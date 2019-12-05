INCLUDES = -I.
CFLAGS = -O2 -fPIC
OUT_DIR = ./build

.PHONY: runtime

build-wasi-libc:
	#rm -rf wasi-libc
	#git clone https://github.com/CraneStation/wasi-libc.git
	cd wasi-libc \
	&& make install INSTALL_DIR=/tmp/wasi-libc

build-wasi-sdk:
	#rm -rf wasi-sdk
	#mkdir -p /usr/local/Cellar/llvm/9.0.0_1/lib/clang/9.0.0/lib/wasi
	#git clone --recursive --branch wasi-sdk-8 git@github.com:CraneStation/wasi-sdk.git
	cd wasi-sdk \
	&& make \
	&& cp wasi-sdk/build/compiler-rt/lib/wasi/libclang_rt.builtins-wasm32.a /usr/local/Cellar/llvm/9.0.0_1/lib/clang/9.0.0/lib/wasi/

generate-pkl:
	mkdir -p $(OUT_DIR)
	./python/RandomForrestClassifier.py

generate-c: generate-pkl
	cat $(OUT_DIR)/random-forest.pkl | m2cgen --language c | tail -n +2 > c/random-forest.c
	cat c/main.c >> c/random-forest.c

build-native: generate-c
	gcc $(CFLAGS) --no-standard-libraries $(INCLUDES) c/random-forest.c -o $(OUT_DIR)/random-forest

build-wasm: generate-c
	mkdir -p $(OUT_DIR)
	clang -v $(CFLAGS) -O3 -flto -nostartfiles -Wl,--allow-undefined-file=c/anmlee.syms -Wl,--no-entry -Wl,--export-dynamic -Wl,--lto-O3 --no-standard-libraries --target=wasm32-unknown-unkown -o $(OUT_DIR)/random-forest.wasm c/random-forest.c

runtime: build-wasm
	cd runtime && cargo build --no-default-features 

clean:
	cd runtime && cargo clean
	rm -rf build