#include <iostream>
#include <gmpxx.h>
#include "tools/exceptions.h"
#include "operations.h"

using namespace std;

int main()
{
    mpz_class p, a, b;
    mpz_class result;
    cout << "a^x = b (mod p)" << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter p: ";
    cin >> p;
    try
    {
        result = discrete_log(a, b, p);
        if (result == -1)
        {
            cout << "No solution exists" << endl;
            return 0;
        }
        cout << "x = " << result << endl;
    }
    catch (const ValTooLong& err)
    {
        cout << err.what() << endl;
    }
    return 0;
}
