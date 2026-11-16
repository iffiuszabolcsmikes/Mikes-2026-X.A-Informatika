#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#define N 20

using namespace std;

void feltolt(int tomb[], int n)
{
    for(int i = 0; i < n; i++)
        tomb[i] = rand() % 100;
}

void kiir(int tomb[], int n)
{
    for(int i = 0; i < n; i++)
        cout << setw(2) << i <<".|";
    cout << endl;

    for(int i = 0; i < n; i++)
        cout << setw(2) << tomb[i] << " |";
    cout << endl;
}

void csere(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int particio(int tomb[], int also, int felso)
{
    int pivot = tomb[also]; //lehet barmelyik
    while(true)
    {
        while(tomb[also] < pivot)
            also++;
        while(tomb[felso] > pivot)
            felso--;
        if(also >= felso)
            return felso;

        csere(tomb[also], tomb[felso]);
        also++;
        felso--;
    }
}

void quickSort(int tomb[], int also, int felso)
{
    if(also >= felso) return;
    int index = particio(tomb, also, felso);
    quickSort(tomb, also, index);
    quickSort(tomb, index + 1, felso);
}

int main()
{
    int n = N;
    int tomb[N];
    srand(time(0));
    feltolt(tomb, n);
    cout << "random:" << endl;
    kiir(tomb, n);
    cout << "quick sort:" << endl;
    quickSort(tomb, 0, n - 1);
    kiir(tomb, n);
    return 0;
}
