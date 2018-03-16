# Passing python callback functions to a c/c++ api with cython.

Given a c++ implementation of the basic gradient descent method for minimizing functions. The objective function is passed as a callback. We now want to utilize this function from python, which includes calling a python function from c++.

### Files

| Plugin | README |
| ------ | ------ |
| gradient_descent.cpp | c++ api that we want to wrap.|
| main.cpp | sample use of the c++ api. |
| pygd.pyx/.pxd | cython api wrapper.  |
| main.py | sample use of the python wrapper |
| setup.py | install script |

install via:
``` sh
$ python setup.py build_ext
$ python setup.py install
```

see the main.py file for useage.