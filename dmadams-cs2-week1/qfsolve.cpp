/**
 * @brief Solves the given quadratic equation.
 *
 * This function, given real coefficients A, B, C to the equation
 * A*x*x + B*x + C = 0, returns the real part of a solution to the
 * equation thus defined. Where two real solutions exist, the one
 * closer to positive infinity is chosen.
 *
 * @param a the quadratic coefficient.
 * @param b the linear coefficient.
 * @param c the constant coefficient.
 *
 * @return the real part of a solution to the defined quadratic equation,
 *         as described.
 */

#include <cmath>
#include <iostream>
using namespace std;

double qfsolve(double a, double b, double c)
{
    if (a == 0.0)
    {
        return -c / b;
    }
    double x1 = (-b + sqrt(b * b - (4 * a * c)))/(2 * a);
    double x2 = (-b - sqrt(b * b - (4 * a * c)))/(2 * a);
    if (x1 > x2)
    {
        return x1;
    }
    return x2;
}

int main(int argc, char ** argv)
{
    double a = qfsolve(0, 1, -1);
    cout << "is: " << a << endl;
    cout << "should be: 1" << endl;
    double b = qfsolve(1, 4, -32);
    cout << "is: " << b << endl;
    cout << "should be: 4" << endl;
    double c = qfsolve(12, 5, -2);
    cout << "is: " << c << endl;
    cout << "should be: .25" << endl;
    double d = qfsolve(3, -3, -90);
    cout << "is: " << d << endl;
    cout << "should be: 6" << endl;
    double e = qfsolve(5, -50, 120);
    cout << "is: " << e << endl;
    cout << "should be: 6" << endl;
    double f = qfsolve(6, -11, 4);
    cout << "is: " << f << endl;
    cout << "should be: 1.3333" << endl;
}
