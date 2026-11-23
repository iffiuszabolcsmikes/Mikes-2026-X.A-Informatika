#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int N = 20;

void feltolt(int tomb[], int n)
{
    for(int i = 0; i < n; i++)
    {
        tomb[i] = rand() % 100;
    }
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
    cout << "PIVOT: tomb[0] = " << pivot << endl;
    while(true)
    {
        while(tomb[also] < pivot)
            also++;
        while(tomb[felso] > pivot)
            felso--;

        if(also >= felso)
        {
            cout << "also = " << also << " felso = " << felso << endl;
            return felso;
        }

        cout << "csere tomb[" << also << "] = " << tomb[also] << "  tomb[" << felso << "] = " << tomb[felso] << endl;
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
    srand(time(0));

    int tomb[N];
    int n = N;

    feltolt(tomb, n);
    kiir(tomb, n);
    cout << endl << "PARTICIO:" << endl;
    //quickSort(tomb, 0, n - 1);
    int index = particio(tomb, 0, n - 1);
    kiir(tomb, n);
    cout << "FELOSZTAS  [0, " << index << "] [" << index + 1 << ", " << n - 1 << "]" << endl;
}
