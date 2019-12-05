#!/usr/bin/env python

from sklearn.datasets import load_iris
from sklearn.ensemble import RandomForestClassifier
import pandas as pd
import numpy as np
import m2cgen as m2c
import pickle
import sys
import datetime

num_args = len(sys.argv);

if num_args == 1:
    print("Not enough arguments!");
    exit;

filename = './build/random-forest.pkl'
if sys.argv[1] == "train":
    np.random.seed(0)
    iris = load_iris()
    df = pd.DataFrame(iris.data, columns=iris.feature_names)
    df['species'] = pd.Categorical.from_codes(iris.target, iris.target_names)
    df['is_train'] = np.random.uniform(0, 1, len(df)) <= .80

    # split into train and test dataframes
    train, test = df[df['is_train']==True], df[df['is_train']==False]
    print('Number of observations in the training data:', len(train))
    print('Number of observations in the test data:',len(test))
    # isolate features
    features = df.columns[:4]
    # convert text targets into numbers
    y = pd.factorize(train['species'])[0]
    # create and train model
    clf = RandomForestClassifier(n_jobs=2, random_state=0)
    clf.fit(train[features], y)
    #clf.predict(test[features])

    # generate c model
    #code = m2c.export_to_c(clf)

    # save the model to disk
    pickle.dump(clf, open(filename, 'wb'))
elif sys.argv[1] == "inference":
    np.random.seed(0)
    iris = load_iris()
    df = pd.DataFrame(iris.data, columns=iris.feature_names)
    df['species'] = pd.Categorical.from_codes(iris.target, iris.target_names)
    df['is_train'] = np.random.uniform(0, 1, len(df)) <= .80

    # split into train and test dataframes
    train, test = df[df['is_train']==True], df[df['is_train']==False]

    # isolate features
    features = df.columns[:4]

    clf = pickle.load(open(filename, 'rb'))

    start = datetime.datetime.now()
    result = clf.predict(test[features].head(1))
    end = datetime.datetime.now()
    delta = end - start
    print("\nExecution time: ", delta.microseconds, " microseconds.\n")
    print("\n",df['species'].iloc[result],"\n")
    






