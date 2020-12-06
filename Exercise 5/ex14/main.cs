// author:  Holger Arndt
// version: 19.11.2020
// main program in C# (mono)
// needed for sheet 5, exercise 14

using System;

class MainProgram
{
  static void Main()
  {
    double x;
    
    Console.Write("x = ");
    x = Double.Parse(Console.ReadLine());
    Console.WriteLine("f(x) = " + Functions.f(x));
    Console.WriteLine("g(x) = " + Functions.g(x));
  }
}
  
