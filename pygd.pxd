from libcpp cimport bool

cdef extern from "gradient_descent.h": 
	void solve(void (*fg)(const double* x, double& f, double* g), 
		int n, 
		double* x0, 
		double* x, 
		bool& success, 
		int maxiter, 
		double tol, 
		bool verbose);