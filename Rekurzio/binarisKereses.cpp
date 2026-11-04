#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

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

void buborekRendezes(int tomb[], int n)
{
    for(int j = 0; j < n - 1; j++)
    {
        for(int i = 0; i < n - j - 1; i++)
        {
            if(tomb[i] > tomb[i + 1])
            {
                csere(tomb[i], tomb[i+1]);
            }
        }
    }
}

int binarisKereses(int tomb[], int also, int felso, int keresettElem)
{
    if(also > felso)
        return -1;

    int kozepso = (also + felso) / 2;

    if(keresettElem == tomb[kozepso])
        return kozepso;
    if(keresettElem < tomb[kozepso])
        return binarisKereses(tomb, also, kozepso - 1, keresettElem);
    else
        return binarisKereses(tomb, kozepso + 1, felso, keresettElem);
}

int main()
{
    srand(time(0));

    int tomb[100];
    int n = 20;

    cout << endl << "buborekos rendezes:" << endl;
    feltolt(tomb, n);
    tomb[n - 1] = 67;
    kiir(tomb, n);
    cout << endl;
    buborekRendezes(tomb, n);
    kiir(tomb, n);

    cout << "BinarisKereses: " << binarisKereses(tomb, 0, n - 1, 677) << endl;
    valami(456);

    return 0;
}
