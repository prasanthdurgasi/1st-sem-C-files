"""
10)
import pandas as pd
import numpy as np

data = {
    'name': ['alice', 'bob', 'charlie', None, 'eve'],
    'age': [25, np.nan, 32, 22, np.nan],
    'salary': [23000, 6000, None, 5200, 58000] 
}
df = pd.DataFrame(data)
print("Original DataFrame:")
print(df)
print("\nMissing Data:")
print(df.isnull())
df['name'].fillna('unknown', inplace=True)
mean_age = df['age'].mean()
df['age'].fillna(mean_age, inplace=True)
df['salary'].fillna(method='bfill', inplace=True)
print("\nDataFrame after replacing missing values:")
print(df)

9)
import re

def is_valid_mobile(number):
    pattern = r'^(\+91[\-\s]?)?[6-9]\d{9}$'
    if re.fullmatch(pattern, number):
        return True
    else:
        return False
mobile_number = input("Enter a mobile number: ")
if is_valid_mobile(mobile_number):
    print(" Valid mobile number.")
else:
    print(" Invalid mobile number.")
    

8)
import re

def is_valid_password(password):
    if len(password) < 6 or len(password) > 12:
        return False
    if not re.search(r'[a-z]', password):
        return False
    if not re.search(r'[A-Z]', password):
        return False
    if not re.search(r'[0-9]', password):
        return False
    if not re.search(r'[$#@]', password):
        return False

    return True
user_password = input("Enter your password: ")
if is_valid_password(user_password):
    print(" Password is valid.")
else:
    print(" Password is invalid.")
    
7b)

import pandas as pd
import numpy as np
df_csv=pd.read_csv("d:\data.csv") #need to create a csv file in notepad save the filename as data.csv in d drive
print(df_csv)

import pandas as pd
df_excel=pd.read_excel("d:\student.xlsx")
print(df_excel)

7a)

import pandas as pd
import numpy as np
data={
      'name':['abc','bcd','cde'],
      'rollno':[1,2,3],
      'grade':['a','b','c']}
df=pd.DataFrame(data)
print("dataframe into numpy array")
print(df.to_numpy())
series=[10,20,30,40]
ser=pd.Series(series)
print("Series to numpy array")
print(ser.to_numpy())

6a)
import pandas as pd
data=[10,20,30,40,50]
labels=['a','b','c','d','e']
series=pd.Series(data,index=labels)
print(series)

6b)
import pandas as pd
data_dict={'savitri':25,
           'saru':26,
           'lav':34,
           'subbu':28}
new_series=pd.Series(data_dict)
print(new_series)

6c)
import pandas as pd
data={
      'product':['sansumg','lenovvo','dell','moto'],
      'price':[10000,12000,14000,16000],
      'itemsold':[12,14,16,18]}
df=pd.DataFrame(data)
print("describe")
print(df.describe())
print("head")
print(df.head(2))
print("tail")
print(df.tail(3))
"""
3.a))

import numpy as np
list=[12.3,34.5,67.8]
tuple=23.5,67.9,25.7
a1=np.array(list)
a2=np.array(tuple)
print(type(a1))
print(a1)
print(a2)

o/p=>

D:\python problems>py test.py
<class 'numpy.ndarray'>
[12.3 34.5 67.8]
[23.5 67.9 25.7]



3.b))


import numpy as np
a=np.array([[10,20,30],[40,50,60],[70,80,90]])
print('slicing:')
print(a[:2,1:])
print('indexing:',a[1,2])
bool_array=[True,False,True,True]
print('boolean indexing :',bool_array[2])

o/p=>

D:\python problems>py test.py
slicing:
[[20 30]
 [50 60]]
indexing: 60
boolean indexing : True

3.c))

import numpy as np
a=np.array([10,20,30,40,50,60])
print('minimum:',np.min(a))
print('maximun:',np.max(a))
print('sum:',np.sum(a))
print('cumsum:',np.cumsum(a))


o/p=>

D:\python problems>py test.py
minimum: 10
maximun: 60
sum: 210
cumsum: [ 10  30  60 100 150 210]



4.a))

import numpy as np
a=np.array([[10,20,30],[40,50,60],[70,80,90]])
print('rank:',np.linalg.matrix_rank(a))
print('determinant:',int(np.linalg.det(a)))
print('trace:',np.trace(a))

o/p==>

D:\python problems>py test.py
rank: 2
determinant: 0
trace: 150




4.b))

import numpy as np
a=np.array([[4,-2],[1,1]])
eval,evec=np.linalg.eig(a)
print(eval)

o/p=>


D:\python problems>py test.py
[3. 2.]




4.c))

import numpy as np
m=np.array([[10,20],[30,40]])
a=np.array([10,20])
b=np.array([3,4])
print(np.dot(a,b))
print(np.inner(a,b))
print(np.outer(a,b))
n=3
print(np.linalg.matrix_power(m,n))

o/p=>

D:\python problems>py test.py
110
110
[[30 40]
 [60 80]]
[[ 37000  54000]
 [ 81000 118000]]




 5.a))

 import numpy as np
from PIL import Image

array=np.ones((500,500,3),dtype=np.uint8)*255;
image=Image.fromarray(array)
image.show()

image.save('pavan.png')

o/p=>

white screen



5.b))

import numpy as np
from PIL import Image

array=np.ones((500,500,3),dtype=np.uint8)*255;
image=Image.fromarray(array)
image.show()

image.save('pavan.png')

image1=Image.open('pavan.png')
array1=np.array(image1)
print(array1.shape)

o/p:


D:\python problems>py test.py
(500, 500, 3)





5.c))

import numpy as np
a=np.array([10,20,60,30,40,18,69,30,30])
print(np.sort(a))
print(np.where(a==30))
print(np.count_nonzero(a==30))

o/p=>

D:\python problems>py test.py
[10 18 20 30 30 30 40 60 69]
(array([3, 7, 8]),)
3

