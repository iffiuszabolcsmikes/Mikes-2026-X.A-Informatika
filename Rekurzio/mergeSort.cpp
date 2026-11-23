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

void merge(int tomb[], int bal, int kozepso,  int jobb)
{
    int i = bal;
    int j = kozepso + 1;

    int tmp[N];
    int k = 0;

    while(i <= kozepso && j <= jobb)
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
    while(j <= jobb)
    {
        tmp[k] = tomb[j];
        j++;
        k++;
    }
    k = 0;
    for(int x = bal; x <= jobb; x++)
    {
        tomb[x] = tmp[k];
        k++;
    }
}

void merge2(int tomb[], int bal, int kozepso, int jobb)
{
    int i = bal;
    int j = kozepso + 1;

    int tmp[N];
    int k = 0;

    while(i <= kozepso && j <= jobb)
        if(tomb[i] < tomb[j])
            tmp[k++] = tomb[i++];
        else
            tmp[k++] = tomb[j++];

    while(i <= kozepso)
        tmp[k++] = tomb[i++];

    while(j <= jobb)
        tmp[k++] = tomb[j++];

    k = 0;
    for(int x = bal; x <= jobb; x++)
        tomb[x] = tmp[k++];
}

void mergeSort(int tomb[], int bal, int jobb)
{
    if(bal >= jobb) return;
    int kozepso = (bal + jobb) / 2;
    mergeSort(tomb, bal, kozepso);
    mergeSort(tomb, kozepso + 1, jobb);
    merge(tomb, bal, kozepso, jobb);
}

int main()
{
    int n = 10;
    int tomb[N];
    srand(time(0));
    feltolt(tomb, n);
    kiir(tomb, n);
    mergeSort(tomb, 0, n - 1);
    kiir(tomb, n);
    return 0;
}
