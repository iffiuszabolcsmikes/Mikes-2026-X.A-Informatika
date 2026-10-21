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

int main()
{
    cout << "osszeg   " << osszeg(10) << endl;
    cout << "osszeg_r " << osszeg_r(10) << endl;
    return 0;
}
