#include <iostream>
#include <math.h>
#include <float.h>

using namespace std;

#define PI 3.14159265

double length(double, double, double, double);
void ellipse(double, double, double, double &, double &);
double circumference(double, double, int);

int main()
{
    double a, b;
    double desiredAccuracy;
    double calculatedAccuracy;
    int n;
    int maxN = pow(2, 24);
    int nPower = 1;

    cout << "Please enter a:" << endl;
    cin >> a;
    cout << "Please enter b:" << endl;
    cin >> b;
    cout << "Please enter desired accuracy:" << endl;
    cin >> desiredAccuracy;

    do
    {
        n = pow(2, nPower);
        nPower++;
        double cir = circumference(a, b, n);
        double cirHalf = circumference(a, b, n / 2);
        calculatedAccuracy = (cir - cirHalf) / cir;
        cout << "circumference:" << cir << "   "
             << "n:" << n << endl;
    } while (calculatedAccuracy > desiredAccuracy || n == maxN);
    return 0;
}

double length(double x1, double y1, double x2, double y2)
{
    double dist = 0;
    dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}

void ellipse(double a, double b, double t, double &x, double &y)
{
    x = a * cos(t);
    y = b * sin(t);
};

double circumference(double a, double b, int n)
{
    double chunk = 2.0 * PI / n * 1.0;
    double len = 0;
    for (int i = 0; i < n; i++)
    {
        double x1, y1, x2, y2;
        double t = chunk * i;
        ellipse(a, b, t, x1, y1);
        t = chunk * (i + 1);
        ellipse(a, b, t, x2, y2);
        len = len + length(x1, y1, x2, y2);
    }

    return len;
}