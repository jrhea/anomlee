INCLUDES = -I.
CFLAGS = -O3 -fPIC
OUT_DIR = ./build

generate-pkl:
	mkdir -p $(OUT_DIR)
	./python/RandomForrestClassifier.py train

generate-c: generate-pkl
	rm -f /tmp/temp.c c/random-forest.c 
	cat $(OUT_DIR)/random-forest.pkl | m2cgen --language c | tail -n +2 > /tmp/temp.c

build-native: generate-c
	cat c/main.c /tmp/temp.c > c/random-forest.c 
	gcc $(CFLAGS) -DNATIVE c/random-forest.c -o $(OUT_DIR)/random-forest

build-wasm: generate-c
	cat c/main.c /tmp/temp.c | cpp -P > c/random-forest.c 
	clang -v $(CFLAGS) -flto -nostartfiles -Wl,--allow-undefined-file=c/anomlee.syms -Wl,--no-entry -Wl,--export-dynamic -Wl,--lto-O3 --no-standard-libraries --target=wasm32-unknown-unkown -o $(OUT_DIR)/random-forest.wasm c/random-forest.c

build: build-wasm build-native
	cd runtime && cargo build --release --no-default-features 
	cp ./runtime/target/release/anomlee build/

benchmark: 
	@echo "########## Python Benchmark: ###########"
	@./python/RandomForrestClassifier.py inference
	@echo "########## eWasm Benchmark: ###########"
	@cd runtime && cargo test --release -- --nocapture
	@echo "########## C Benchmark: ##########"
	@./build/random-forest

clean:
	cd runtime && cargo clean
	rm -rf build