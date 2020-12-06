// computing π by integration, OpenMP version
// author:  Holger Arndt
// version: 20.11.2020
// program for sheet 5, exercise 15

#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;
using namespace std::chrono;

double f(double x)
{ return 4 / (1 + x * x); }

int main()
{
  cout << "n = ";
  int n;
  cin >> n;

  auto startTime{high_resolution_clock::now()};
  double sum;
  double h{1.0 / n};
  sum = f(0) + f(1);
#pragma omp parallel for reduction(+:sum)
  for (int i = 1; i < n; ++i)
    sum += 2 * f(i * h);
  sum *= h / 2;
  auto endTime{high_resolution_clock::now()};
  auto usedTime{duration_cast<duration<double>>(endTime - startTime)};

  cout << "result: " << setprecision(15) << sum << endl;;
  cout << "time for computation: " << usedTime.count() << " s" << endl;
}
