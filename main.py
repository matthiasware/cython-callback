import numpy as np
from pygd import pysolve


def fg(x):
    return sum(x**2), 2 * x


x0 = np.array([100, 100], dtype=np.double)

x, success = pysolve(fg, x0)
f, g = fg(x)
print("success:", success)
print("x: ", x)
print("f:", f)
print("g:", g)
