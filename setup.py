from distutils.core import setup, Extension
from Cython.Build import cythonize
import numpy as np
import distutils.sysconfig

compilerFlags = "-std=c++11"

cfg_vars = distutils.sysconfig.get_config_vars()
for key, value in cfg_vars.items():
    if type(value) == str:
        cfg_vars[key] = value.replace("-Wstrict-prototypes", "")


ext = Extension("pygd",
                sources=["pygd.pyx",
                         "gradient_descent.cpp"],
                language="c++",
                extra_compile_args=[compilerFlags],
                include_dirs=['.',
                              np.get_include(),
                              '..']
                )
setup(name="pygd",
      ext_modules=cythonize(ext))
