# ANMLEE: A Nifty ML EE (pronounced a·nom·a·ly)

> !!THIS IS A WORK IN PROGRESS!!

This repo demonstrates how a trained ML model could run inside an Ethereum 2 EE.

## Prerequisits

Install LLVM

```bash
brew install llvm
echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' >> ~/.bash_profile
```

Install the WebAssembly Binary Toolkit

```bash
brew install wabt
```

Install NinJa

```bash
brew install ninja
```

Install Wasmer: The Universal WebAssembly Runtime

```bash
curl https://get.wasmer.io -sSfL | sh
```

## Build 

Native:

```bash
make build-native
```

Wasm
```bash
make build-wasm
```

## Run

Native
```bash
./build/random-forest
```

Wasm
```bash
wasmer run build/random-forest.wasm 
```

## Output

Currently there is a single random forest classifier model that is trained to determine which of the following types of iris flowers:

- setosa
- versicolor
- virginica

 based on the following design variables:

- sepal length (cm)	
- sepal width (cm)	
- petal length (cm)	
- petal width (cm)


```bash
$ wasmer run build/random-forest.wasm 
Probabilities: 1.000000 0.000000 0.000000 
Model Predicts: setosa
```