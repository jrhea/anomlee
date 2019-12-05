# ANMLEE: A Nascent ML EE (pronounced a·nom·a·ly)

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

## Build 

```bash
make anmlee
```

## Run

```bash
./build/anmlee 
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
$ ./build/anmlee 

Probabilities: 
1.0000 .0000 .0000 

Model Predicts: 
setosa
```