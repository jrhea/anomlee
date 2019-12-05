## ANOMLEE: A Neat-O Machine Learning Execution Environment

:muscle: by Quilt's [ewasm-rt](https://github.com/quilt/ewasm-rt)

This repo demonstrates how a trained ML model could run inside an Ethereum 2 EE.  

### Random Forest Classifier

Currently there is a single random forest classifier model that is trained to determine which of the following types of iris flowers:

- setosa
- versicolor
- virginica

 based on the following design variables:

- sepal length (cm)	
- sepal width (cm)	
- petal length (cm)	
- petal width (cm)

**Benchmarks:**
- **Python:** 103307 microseconds
- **eWasm:** 551.849 microseconds
- **C:** 1 microsecond

**Binary size:**
- 826 bytes

### Prerequisits

Install LLVM

```bash
brew install llvm
echo 'export PATH="/usr/local/opt/llvm/bin:$PATH"' >> ~/.bash_profile
```

Install the WebAssembly Binary Toolkit

```bash
brew install wabt
```

### Build 

```bash
make build
```

### Run Native

```bash
$ ./build/random-forest

Execution time: 0 microseconds


Probabilities: 
1.000000 0.000000 0.000000 

Model Predicts: 
setosa    

```

### Run eWASM

```bash
$ ./build/anomlee

Probabilities: 
1.0000 .0000 .0000 

Model Predicts: 
setosa    
```

### Run Benchmark

```bash
$ make benchmark
########## Python Benchmark: ###########

Execution time: 103307 microseconds.


 0    setosa
Name: species, dtype: category
Categories (3, object): [setosa, versicolor, virginica] 

########## eWasm Benchmark: ###########
    Finished release [optimized] target(s) in 0.03s
     Running target/release/deps/anomlee-0de6000a8c14c88e

running 1 test

Execution Time: 551.849µs

test tests::test ... ok

test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out

########## C Benchmark: ##########

Execution time: 1 microseconds


Probabilities: 
1.000000 0.000000 0.000000 

Model Predicts: 
setosa    

```

