#ifndef __GD_H_INCLUDED__
#define __GD_H_INCLUDED__ 
#include <functional>

void solve(std::function<void(const double*, double&, double*)> fg,
		   int n,
		   double* x0,
		   double* x,
		   bool& success,
		   int maxiter = 100,
		   double tol = 1e-3,
		   bool verbose = false);

#endif 