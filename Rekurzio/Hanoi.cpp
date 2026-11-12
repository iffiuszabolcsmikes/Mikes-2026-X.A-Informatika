#include <iostream>

using namespace std;

const int N = 7; //korongok szama

//korongok
int A[N] = {0};
int B[N] = {0};
int C[N] = {0};

int nA = 0, nB = 0, nC = 0; //hany korong van az adott rudon

void feltolt()
{
    nA = N;
    for(int i = 0; i < N; i++)
        A[i] = N - i;
}

void kiirKorong(int n)
{
    for(int j = 0; j < N - n; j++)
        cout << " ";
    for(int j = 0; j < n; j++)
        cout << "=";
    if(n == 0)
        cout << "|";
    else
        cout << n;
    for(int j = 0; j < n; j++)
        cout << "=";
    for(int j = 0; j < N - n; j++)
        cout << " ";
}

void kiirOszlop(char oszlop)
{
    for(int i = 0; i < N; i++)
        cout << "-";
    cout << oszlop;
    for(int i = 0; i < N; i++)
        cout << "-";
}

int lepes = 0;

void kiir()
{
    cout << lepes++ << ". lepes:" << endl;
    for(int i = N - 1; i >= 0; i--)
    {
        kiirKorong(A[i]);
        cout << " ";
        kiirKorong(B[i]);
        cout << " ";
        kiirKorong(C[i]);
        cout << endl;
    }
    kiirOszlop('A');
    cout << " ";
    kiirOszlop('B');
    cout << " ";
    kiirOszlop('C');
    cout << endl;
}

void hanoi(int from[], int to[], int via[], int &f, int &t, int &v, int n)
{
    if(n == 1)
    {
        to[t] = from[f - 1];
        from[f - 1] = 0;
        t++;
        f--;
        kiir();
        return;
    }
    hanoi(from, via, to, f, v, t, n - 1);
    hanoi(from, to, via, f, t, v, 1);
    hanoi(via, to, from, v, t, f, n - 1);
}

int main()
{
    feltolt();
    kiir();
    hanoi(A, C, B, nA, nC, nB, N);
    return 0;
}
