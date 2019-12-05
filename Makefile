INCLUDES = -I.
CFLAGS = -O2 -fPIC
OUT_DIR = ./build

generate-pkl:
	mkdir -p $(OUT_DIR)
	./python/RandomForrestClassifier.py

generate-c: generate-pkl
	cat $(OUT_DIR)/random-forest.pkl | m2cgen --language c | tail -n +2 > c/random-forest.c
	cat c/main.c >> c/random-forest.c

build-native: generate-c
	#gcc $(CFLAGS) --no-standard-libraries $(INCLUDES) c/random-forest.c -o $(OUT_DIR)/random-forest

build-wasm: generate-c
	mkdir -p $(OUT_DIR)
	clang -v $(CFLAGS) -O3 -flto -nostartfiles -Wl,--allow-undefined-file=c/anmlee.syms -Wl,--no-entry -Wl,--export-dynamic -Wl,--lto-O3 --no-standard-libraries --target=wasm32-unknown-unkown -o $(OUT_DIR)/random-forest.wasm c/random-forest.c

build: build-wasm build-native
	cd runtime && cargo build --release --no-default-features 
	cp ./runtime/target/debug/anmlee build/

test: 
	cd runtime && cargo test --release -- --nocapture

clean:
	cd runtime && cargo clean
	rm -rf build