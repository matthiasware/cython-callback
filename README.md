# Passing python callback functions to a c/c++ api with cython.

### As an example:
Given a c++ implementation of the basic gradient descent method for minimizing functions. The objective function is passed as a callback. We now want to utilize the minimizing function from python, which includes calling a python function from c++.

### Files

| Plugin | README |
| ------ | ------ |
| gradient_descent.cpp | c++ api that we want to wrap.|
| main.cpp | sample usage of the c++ api. |
| pygd.pyx/.pxd | cython api wrapper.  |
| main.py | sample useage of the cython wrapper |
| setup.py | install script |

install via:
``` sh
$ python setup.py build_ext
$ python setup.py install
```