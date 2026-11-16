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

void merge(int tomb[], int also, int kozepso, int felso)
{
    int tmp[N];
    int k = 0;
    int i = also;
    int j = kozepso + 1;
    while(i <= kozepso && j <= felso)
    {
        if(tomb[i] < tomb[j])
        {
            tmp[k] = tomb[i];
            i++;
        }
        else
        {
            tmp[k] = tomb[j];
            j++;
        }
        k++;
    }
    while(i <= kozepso)
    {
        tmp[k] = tomb[i];
        i++;
        k++;
    }
    while(j <= felso)
    {
        tmp[k] = tomb[j];
        j++;
        k++;
    }
    k = 0;
    for(int i = also; i <= felso; i++)
    {
        tomb[i] = tmp[k];
        k++;
    }
}

void mergeSort(int tomb[], int also, int felso)
{
    if(also >= felso) return;
    int kozepso = (also + felso) / 2;
    mergeSort(tomb, also, kozepso);
    mergeSort(tomb, kozepso + 1, felso);
    merge(tomb, also, kozepso, felso);
}

int main()
{
    int n = 10;
    int tomb[N];
    srand(time(0));
    feltolt(tomb, n);
    cout << "rand: " << endl;
    kiir(tomb, n);

    cout << "merge sort:" << endl;
    mergeSort(tomb, 0, n - 1);
    kiir(tomb, n);
    return 0;
}
