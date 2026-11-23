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

void merge(int tomb1[], int tomb2[], int n1, int n2)
{
    int i1 = 0;
    int i2 = 0;

    int tomb3[N];
    int i3 = 0;

    while(i1 < n1 && i2 < n2)
    {
        if(tomb1[i1] < tomb2[i2])
        {
            tomb3[i3] = tomb1[i1];
            i1++;
        }
        else
        {
            tomb3[i3] = tomb2[i2];
            i2++;
        }
        i3++;
    }
    while(i1 < n1)
    {
        tomb3[i3] = tomb1[i1];
        i1++;
        i3++;
    }
    while(i2 < n2)
    {
        tomb3[i3] = tomb2[i2];
        i2++;
        i3++;
    }
    kiir(tomb3, i3);
}

int main()
{
    int n = 10;
    int tomb1[N];
    int tomb2[N];
    srand(time(0));
    feltolt(tomb1, n);
    feltolt(tomb2, n);
    quickSort(tomb1, 0, n - 1);
    kiir(tomb1, n);
    quickSort(tomb2, 0, n - 1);
    kiir(tomb2, n);
    merge(tomb1, tomb2, n, n);

    return 0;
}
