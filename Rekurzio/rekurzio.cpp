#include <iostream>

using namespace std;

//1+2+3+...+n
int osszeg(int n)
{
    int ossz = 0;
    while(n != 0)
    {
        ossz = ossz + n;
        n--;
    }
    return ossz;
}
//rekurziv
int osszeg_r(int n)
{
    if(n == 0)
        return 0;
    return n + osszeg_r(n - 1);
}

//iterativ
//1*2*3*...*n
int faktorialis(int n)
{
    int szorzat = 1;
    while(n != 0)
    {
        szorzat = szorzat * n;
        n--;
    }
    return szorzat;
}

//rekurziv
int faktorialis_r(int n)
{
    if(n == 0)
        return 1;
    return n * faktorialis_r(n - 1);
}
//1 1 2 3 5 8 13 21 34 55 89 ...
int fibonacci(int n)
{
    int fib0 = 0;
    int fib1 = 1;
    int aktualis = 0;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    while(n > 1)
    {
        aktualis = fib0 + fib1;
        fib0 = fib1;
        fib1 = aktualis;
        n--;
    }
    return aktualis;
}

int fibonacci_r(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibonacci_r(n - 1) + fibonacci_r(n - 2);
}

int main()
{
    cout << "osszeg   " << osszeg(10) << endl;
    cout << "osszeg_r " << osszeg_r(10) << endl;
    cout << "faktorialis   " << faktorialis(5) << endl;
    cout << "faktorialis_r " << faktorialis_r(5) << endl;
    cout << "fibonacci   " << fibonacci(12) << endl;
    cout << "fibonacci_r " << fibonacci_r(12) << endl;
    return 0;
}
