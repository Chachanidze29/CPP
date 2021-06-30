#include <iostream>
#include <time.h>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a, b;
    cout << "Enter 2 integers : " << endl;
    cin >> a >> b;  
    clock_t tstart = clock();
    cout << "GCD is " << gcd(a, b) << endl;
    printf("Time taken %2fs\n", (double)(clock() - tstart) / CLOCKS_PER_SEC);
}