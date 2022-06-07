#include <iostream>
using namespace std;

int countzeros(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 10 != 0)
    {
        return 0;
    }
    int count = 1 + countzeros(n / 10);
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << countzeros(n) << endl;
}