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

//a*a*a*...*a, k-szor = a^k
int hatvany(int a, int k)
{

    int szorzat = 1;
    while(k != 0)
    {
        szorzat = szorzat * a;
        k--;
    }
    return szorzat;
}

//a*a*a*...*a, k-szor = a^k
int hatvany_r(int a, int k)
{
    if(k == 0)
        return 1;
    return a * hatvany_r(a, k - 1);
}

//1*2 + 2*3 + ... (n-1)*n
int sumProd(int n)
{
    int ossz = 0;
    while(n != 1)
    {
        ossz = ossz + (n - 1) * n;
        n--;
    }
    return ossz;
}

//1*2 + 2*3 + ... (n-1)*n
int sumProd_r(int n)
{
    if(n == 1)
        return 0;
    return (n - 1) * n + sumProd_r(n - 1);
}

int szamjegyOssz(int szam)
{
    int ossz = 0;
    while(szam != 0)
    {
        ossz = ossz + szam % 10;
        szam = szam / 10;
    }
    return ossz;
}

int szamjegyOssz_r(int szam)
{
    if(szam == 0)
        return 0;
    return szam % 10 + szamjegyOssz_r(szam / 10);
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
    cout << "hatvany " << hatvany(2, 10) << endl;
    cout << "hatvany_r " << hatvany_r(2, 10) << endl;
    cout << "sumProd " << sumProd(5) << endl;
    cout << "sumProd_r " << sumProd_r(5) << endl;
    cout << "szamjegyOssz " <<  szamjegyOssz(456) << endl;
    cout << "szamjegyOssz_r " <<  szamjegyOssz_r(456) << endl;

    return 0;
}
