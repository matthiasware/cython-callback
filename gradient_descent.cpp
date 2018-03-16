#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include "gradient_descent.h"

void solve(std::function<void(const double*, double&, double*)> fg,
		   int n, /* num variables */
		   double* x0, /* start value */
		   double* x, /* solution */
		   bool& success, /* was the solving process successful? */
		   int maxiter, /* = 100, max number of iterations */
		   double tol, /* = 1e-3, tolerance*/
		   bool verbose) /* = false, verbose console output */
{
	double f;
	std::vector<double> g(n);
	for(int i=0; i<n; i++) x[i] = x0[i];
	fg(x, f, &g[0]);
	int k=0;
	success = false;
	while(true)
	{
		if (verbose)
		{
			std::cout << "k: " << k << std::endl;
			std::cout << "x: ";
			for(int i=0; i<n; i++) std::cout << x[i] << " ";
			std::cout <<  std::endl;
			std::cout << "f: " << f << std::endl;
			std::cout << "g: [";
			for(int i=0; i<n; i++) std::cout << g[i] << " ";
			std::cout << "]" <<  std::endl;
		}
		if(k > maxiter) break;
		double norm = 0;
		for(int i=0; i<n; i++) norm += g[i] * g[i];
		norm = std::sqrt(norm);
		if(norm < tol)
		{
			success = true;
			break;
		}
		for(int i=0; i<n; i++) x[i] = x[i] - 0.4 * g[i];
		fg(x, f, &g[0]);
		k++;
	}
}