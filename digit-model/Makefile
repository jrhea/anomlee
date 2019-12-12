INCLUDES = -I./cpp/frugally-deep/include -I./cpp/FunctionalPlus/include -I./cpp/eigen -I./cpp/json/include -I ./cpp/CImg-2.8.0 -I /opt/X11/include
CFLAGS = -O3 -fPIC --std=c++14
OUT_DIR = ./../build

cpp/frugally-deep:
	cd cpp \
	&& git clone --branch v0.11.0-p0 https://github.com/Dobiasd/frugally-deep.git \
	&& git clone --branch v0.2.3-p0 https://github.com/Dobiasd/FunctionalPlus.git \
	&& git clone --branch 3.3.7 https://gitlab.com/libeigen/eigen.git \
	&& git clone --branch v3.7.3 https://github.com/nlohmann/json.git \
	&& wget http://cimg.eu/files/CImg_2.8.0.zip \
	&& unzip CImg_2.8.0.zip


generate-json: cpp/frugally-deep
	mkdir -p $(OUT_DIR)
	#./python/digit-model.py train
	python3 cpp/frugally-deep/keras_export/convert_model.py $(OUT_DIR)/digit-model.h5 $(OUT_DIR)/digit-model.json

generate-cpp: generate-json
	

build-native: generate-cpp
	g++ $(CFLAGS) $(INCLUDES) -DNATIVE cpp/main.cpp -L/opt/X11/lib -lX11 -o $(OUT_DIR)/digit-model

build-wasm: generate-cpp
	# clang -v $(CFLAGS) -flto -nostartfiles -Wl,--allow-undefined-file=c/anomlee.syms -Wl,--no-entry -Wl,--export-dynamic -Wl,--lto-O3 --no-standard-libraries --target=wasm32-unknown-unkown -o $(OUT_DIR)/random-forest.wasm c/random-forest.c

digit: build-wasm build-native

benchmark: 

