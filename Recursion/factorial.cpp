#include <iostream>
using namespace std;

int factorial(int m)
{
    if (m == 0)
    {
        return 1;
    }
    else
    {
        int smalloutput = factorial(m - 1);
        return m * smalloutput;
    }
}

int main()
{
    int n;
    cin >> n;
    int result = factorial(n);
    cout << result << endl;
}