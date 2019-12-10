INCLUDES = -I.
CFLAGS = -O3 -fPIC
OUT_DIR = ./../build

generate-pkl:
	mkdir -p $(OUT_DIR)
	./python/model.py train

generate-c: generate-pkl
	rm -f /tmp/temp.c c/iris-model.c 
	cat $(OUT_DIR)/iris-model.pkl | m2cgen --language c | tail -n +2 > /tmp/temp.c

build-native: generate-c
	cat c/main.c /tmp/temp.c > c/iris-model.c 
	gcc $(CFLAGS) -DNATIVE c/iris-model.c -o $(OUT_DIR)/iris-model

build-wasm: generate-c
	cat c/main.c /tmp/temp.c | cpp -P > c/iris-model.c 
	clang -v $(CFLAGS) -flto -nostartfiles -Wl,--allow-undefined-file=c/anomlee.syms -Wl,--no-entry -Wl,--export-dynamic -Wl,--lto-O3 --no-standard-libraries --target=wasm32-unknown-unkown -o $(OUT_DIR)/iris-model.wasm c/iris-model.c

iris: build-wasm build-native

benchmark: 
	@echo "########## Python Benchmark: ###########"
	@./python/model.py inference
	@echo "########## eWasm Benchmark: ###########"
	@cd ../runtime && cargo test --release -- --nocapture
	@echo "########## C Benchmark: ##########"
	@$(OUT_DIR)/iris-model