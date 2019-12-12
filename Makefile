SHELL := /bin/sh

OUT_DIR = ./build
IRIS_DIR = ./iris-model
DIGIT_DIR = ./digit-model

all: iris digit anomlee

anomlee:
	cd runtime && cargo build --release --no-default-features 
	cp ./runtime/target/release/anomlee build/

iris:
	cd $(IRIS_DIR) && make $@

digit:
	cd $(DIGIT_DIR) && make $@

benchmark:
	cd $(IRIS_DIR) && make $@
#	cd $(DIGIT_DIR) && make $@

clean:
	cd runtime && cargo clean
	rm -rf build