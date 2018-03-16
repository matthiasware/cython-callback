cimport cython
import numpy as np
cimport numpy as np
from libcpp.limits cimport numeric_limits
from libcpp cimport bool
np.import_array()

cdef object global_fg
cdef int global_n

ctypedef void (*t_callback_fg) (const double *x,
                                double &f,
                                double *g)

cdef void callback_fg(const double *x, double &f, double *g):
    cdef double[:] x_mv = <double[:global_n]> x
    cdef np.ndarray pyx = np.asarray(x_mv)
    pyf, pyg = (<object>global_fg)(pyx)
    (&f)[0] = <double> pyf
    for i in range(global_n):
        g[i] = <double> pyg[i]


def pysolve(fg, double[:] x0,
            int maxiter=100,
            double tol=1e-4,
            bool verbose=False):
    global global_n
    global global_fg
    global_n = x0.size
    global_fg = fg

    cdef np.ndarray x = np.ones(global_n, dtype=np.double)
    cdef bool success = False
    solve(<t_callback_fg> callback_fg,
          global_n,
          &x0[0],
          <double *> x.data,
          success,
          maxiter,
          tol,
          verbose)
    return x, success