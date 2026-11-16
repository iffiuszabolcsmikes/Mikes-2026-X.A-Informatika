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

int max(int a, int b)
{
    if(a > b) return a;
    else return b;
}

int legnagyobbSzamjegy1(int szam)
{
    if(szam < 10) return szam;
    return max(szam % 10, legnagyobbSzamjegy1(szam / 10));
}

int legnagyobbSzamjegy2(int szam)
{
    if(szam < 10)
        return szam;
    int ertek = legnagyobbSzamjegy2(szam / 10);
    if(szam % 10 > ertek)
        return szam % 10;
    else
        return ertek;
}

int legnagyobbSzamjegy3(int szam, int maxSzamjegy = 0)
{
    if(szam == 0)
        return maxSzamjegy;
    if(szam % 10 > maxSzamjegy)
        return legnagyobbSzamjegy3(szam / 10, szam % 10);
    else
        return legnagyobbSzamjegy3(szam / 10, maxSzamjegy);
}
/*
legnagyobbSzamjegy3(2842371, 0)->8
legnagyobbSzamjegy3(284237, 1)->8
legnagyobbSzamjegy3(28423, 7)->8
legnagyobbSzamjegy3(2842, 7)->8
legnagyobbSzamjegy3(284, 7)->8
legnagyobbSzamjegy3(28, 7)->8
legnagyobbSzamjegy3(2, 8)->8
legnagyobbSzamjegy3(0, 8)->8
*/

int gyorsHatvany(int a, int k)
{
    int eredmeny = 1;
    while(k > 0)
    {
        if(k % 2 == 0) //paros
        {
            a = a * a;
            k = k / 2;
        }
        else //paratlan
        {
            eredmeny = eredmeny * a;
            k--;
        }
    }
    return eredmeny;
}

int gyorsHatvany_r(int a, int k)
{
    if(k == 0)
        return 1;
    if(k % 2 == 0) //paros
        return gyorsHatvany_r(a * a, k / 2);
    else //paratlan
        return a * gyorsHatvany_r(a, k - 1);
}

int lnko(int a, int b)
{
    while(b != 0)
    {
        int r = a % b; //maradek
        a = b;
        b = r;
    }
    return a;
}

int lnko(int a, int b)
{
    while(b != 0)
    {
        int m = a % b;
        a = b;
        b = m;
    }
    return a;
}

int lnko_r(int a, int b)
{
    if(b == 0) return a;
    return lnko_r(b, a % b);
}

void kiir_r(int n)
{
    if(n == 0) return;
    cout << n;
    kiir_r(n - 1);
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

    cout << "legnagyobb Szamjegy " << legnagyobbSzamjegy1(2842371) << endl;
    cout << "legnagyobb Szamjegy " << legnagyobbSzamjegy2(2842371) << endl;
    cout << "legnagyobb Szamjegy " << legnagyobbSzamjegy3(2842371) << endl;

    cout << "lnko " << lnko(50, 75) << endl;
    cout << "lnko_r " << lnko_r(50, 75) << endl;

    return 0;
}
