INCLUDES = -I.
CFLAGS = -O2 -fPIC
OUT_DIR = ./build

generate-pkl:
	mkdir -p $(OUT_DIR)
	./python/RandomForrestClassifier.py

generate-c: generate-pkl
	cat $(OUT_DIR)/random-forest.pkl | m2cgen --language c > c/random-forest.c

build-native: generate-c
	gcc $(CFLAGS) -c $(INCLUDES) c/random-forest.c -o $(OUT_DIR)/random-forest.o
	gcc $(CFLAGS) $(INCLUDES) $(OUT_DIR)/random-forest.o c/main.c -o $(OUT_DIR)/main

build-wasi-libc:
	rm -rf wasi-libc
	git clone https://github.com/CraneStation/wasi-libc.git
	cd wasi-libc \
	&& make install INSTALL_DIR=/tmp/wasi-libc

build-wasi-sdk:
	rm -rf wasi-sdk
	mkdir -p /usr/local/Cellar/llvm/9.0.0_1/lib/clang/9.0.0/lib/wasi
	git clone --recursive --branch wasi-sdk-8 git@github.com:CraneStation/wasi-sdk.git
	cd wasi-sdk \
	&& make \
	&& cp wasi-sdk/build/compiler-rt/lib/wasi/libclang_rt.builtins-wasm32.a /usr/local/Cellar/llvm/9.0.0_1/lib/clang/9.0.0/lib/wasi/

build-wasm: generate-c
	#clang $(CFLAGS) --target=wasm32-unknown-wasi --sysroot /tmp/wasi-libc -nostartfiles -Wl,--shared -Wl,--import-memory -Wl,--no-entry -Wl,--export-all -o $(OUT_DIR)/random-forest.wasm c/random-forest.c
	#clang -v $(CFLAGS) --target=wasm32-unknown-wasi --sysroot /tmp/wasi-libc $(OUT_DIR)/random-forest.wasm -o $(OUT_DIR)/main.wasm c/main.c
	# Modules without a main are not spec'd out as part of wasi. see: https://github.com/CraneStation/wasi-sdk/issues/62
	cat c/main.c >> c/random-forest.c
	clang -v $(CFLAGS) --target=wasm32-unknown-wasi --sysroot /tmp/wasi-libc -o $(OUT_DIR)/random-forest.wasm c/random-forest.c


clean:
	rm -rf build