#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include "gradient_descent.h"

// f(x,y) = x^2 + y^2
// g(x,y) = [2x, 2y]
void qp2d(const double* x, double& f, double* g)
{
	f = 0;
	for(int i=0; i<2; i++)
	{
		f += x[i] * x[i];
		g[i] = 2 * x[i];
	}
}

int main()
{
	int n = 2;
	std::vector<double> x0 = {8, 4};
	std::vector<double> x(n);
	bool success;
	solve(&qp2d, n, &x0[0], &x[0], success);
	std::cout << "Success:  " << std::boolalpha << success << std::endl;
	std::cout << "Solution: [";
	for(int i=0; i<n; i++) std::cout << x[i] << " ";
	std::cout << "]" <<  std::endl;

}