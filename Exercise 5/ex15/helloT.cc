// hello world with OpenMP
// author:  Holger Arndt
// version: 20.11.2020
// program for sheet 5, exercise 14

#include <iostream>

using namespace std;

int main()
{
#pragma omp parallel
  cout << "Hello Participants of the Modern Programming Exercises!\n";
}
