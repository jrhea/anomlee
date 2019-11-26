#!/usr/bin/env python

from sklearn.datasets import load_iris
from sklearn.ensemble import RandomForestClassifier
import pandas as pd
import numpy as np
import m2cgen as m2c
import pickle

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
filename = './build/random-forest.pkl'
pickle.dump(clf, open(filename, 'wb'))








