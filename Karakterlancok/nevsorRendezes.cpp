#include <iostream>
#include <fstream>

using namespace std;

const int NEV_HOSSZ = 1000;

int beolvas(char nevsor[][NEV_HOSSZ], char fileName[])
{
    ifstream f(fileName);

    int i = 0;
    while(f.getline(nevsor[i], NEV_HOSSZ))
    {
        i++;
    }
    return i;
}

void kiir(char nevsor[][NEV_HOSSZ], int n)
{
    for(int i = 0; i < n ; i++)
    {
        cout << nevsor[i] << endl;
    }
}

int stringCompare(char str1[],char str2[])
{
    int i = 0;
    while(str1[i] != 0 && str1[i] == str2[i])
    {
        i++;
    }
    return str1[i] - str2[i];
}

void stringCopy(char dest[],char src[])
{
    int i = 0;
    while(src[i] != 0)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
}

void csere(char str1[], char str2[])
{
    char tmp[NEV_HOSSZ];
    stringCopy(tmp, str1);
    stringCopy(str1, str2);
    stringCopy(str2, tmp);
}

void buborekRendezes(char nevsor[][NEV_HOSSZ], int n)
{
    for(int j = 0; j < n - 1; j++)
    {
        for(int i = 0; i < n - j - 1; i++)
        {
            if(stringCompare(nevsor[i], nevsor[i + 1]) > 0)
            {
                csere(nevsor[i], nevsor[i + 1]);
            }
        }
    }
}

int main()
{
    char nevsor [100][NEV_HOSSZ];
    int n = beolvas(nevsor, "nevsor.txt");
    kiir(nevsor, n);
    buborekRendezes(nevsor, n);
    cout << endl << "Rendezve:" << endl << endl;
    kiir(nevsor, n);
    return 0;
}
