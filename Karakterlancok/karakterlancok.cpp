#include <iostream>

using namespace std;

const int STRING_SIZE = 1000;

int stringLength_index(char s[])
{
    int i = 0;
    while(s[i] != 0) i++;
    return i;
}

void toUpperCase_index(char s[])
{
    int i = 0;
    while(s[i] != 0)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 'a' - 'A';
        i++;
    }
}

void toLowerCase_index(char s[])
{
    int i = 0;
    while(s[i] != 0)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a' - 'A';
        i++;
    }
}

void stringCopy_index(char dst[], char src[])
{
    int i = 0;
    while (src[i] != 0)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
}

void strConcatenate_index(char dst[], char src[])
{
    int i = 0;
    while(dst[i] != 0) i++;
    int j = 0;
    while(src[j] != 0)
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = 0;
}

int stringCompare_index(char st[], char nd[])
{
    int i = 0;
    while (st[i] != 0 && st[i] == nd[i])
    {
        i++;
    }
    return st[i] - nd[i];
}

void kiir(char s[])
{
    for(char *p = s; *p; p++)
        cout << *p;
    cout << endl;
}

int stringLength(char s[])
{
    char *p = s;
    while(*p) p++;
    return p - s;
}

char* findChar(char s[], char x)
{
    for(char *p = s; *p; p++)
        if(*p == x) return p;
    return 0;
}

void replaceCharChar(char s[], char mit, char mire)
{
    for(char *p = s; *p; p++)
        if(*p == mit) *p = mire;
}

void toLowerCase(char s[])
{
    char *p = s;
    while(*p)
    {
        if(*p >= 'A' && *p <= 'Z')
            *p += 'a' - 'A';
        p++;
    }
}

void toUpperCase(char s[])
{
    char *p = s;
    while(*p != 0)
    {
        if(*p >= 'a' && *p <= 'z')
            *p -= 'a' - 'A';
        p++;
    }
}

void stringConcatenate(char dst[], char src[])
{
    char *p = dst;
    while(*p) p++;
    char *q = src;
    while(*q)
    {
        *p = *q;
        p++;
        q++;
    }
    *p = 0;
}

void stringCopy(char dst[], char src[])
{
    char *p = dst;
    char *q = src;
    while(*q)
    {
        *p = *q;
        p++;
        q++;
    }
    *p = 0;
}

char *findString(char s[],char mit[])
{
    if(*mit == 0)
        return s;
    for(char *p = s; *p; p++)
    {
        char *m = mit;
        char *q = p;
        while(*m && *q && *m == *q)
        {
            m++;
            q++;
        }
        if(*m == 0)
            return p;
    }
    return 0;
}

void replaceCharString(char s[], char mit, char mire[])
{
    char temp[STRING_SIZE];
    char *t = temp;
    for(char *p = s; *p; p++)
    {
        if(*p == mit)
        {
            for(char *q = mire; *q; q++, t++)
                *t = *q;
        }
        else
        {
            *t = *p;
            t++;
        }
    }
    *t = 0;
    stringCopy(s, temp);
}

void replaceStringString(char s[], char mit[], char mire[])
{
    if(*mit == 0)
        return;
    char temp[STRING_SIZE];
    char *t = temp;
    char *p = s;
    int h = stringLength(mit);
    char *found = findString(s, mit);
    while(found)
    {
        while(p < found)
        {
            *t = *p;
            p++;
            t++;
        }
        for(char *q = mire; *q; q++, t++)
            *t = *q;
        p += h;
        found = findString(p, mit);
    }
    while(*p)
    {
        *t = *p;
        p++;
        t++;
    }
    *t = 0;
    stringCopy(s, temp);
}

void trim(char s[] ){
    //megkeressuk a veget
    char *q = s + stringLength(s) - 1;
    while(q >= s && *q == ' '){
        q--;
    }
    *(q + 1) = 0;
    //megkeressuk az elejet
    char *p = s;
    while(*p && *p == ' '){
        p++;
    }
    stringCopy(s, p);
}

void slice(char s[], int i, int j)
{
    int k = 0;
    char tp[100];
    for(int a = i; a <= j; a++)
    {
        tp[k] = s[a];
        k++;
    }
    tp[k] = 0;
    stringCopy(s, tp);
}

void padStart(char s[], int n, char c)
{
    char tmp[100];
    int i = 0;
    while(i < n - stringLength_index(s))
    {
        tmp[i] = c;
        i++;
    }
    stringConcatenate(tmp, s);
    stringCopy(s, tmp);
}

void padEnd(char s[], int n, char c)
{
    int i = stringLength(s);
    while(i < n)
    {
        s[i] = c;
        i++;
    }
    s[i] = 0;
}

int main()
{
    char s[STRING_SIZE] = "OK szia";
    cout << stringLength(s) << endl;
    toUpperCase(s);
    cout << s << endl;
    toLowerCase(s);
    cout << s << endl;
    stringConcatenate(s, "mia");
    cout << s << endl;
    kiir(s);
    cout << stringLength(s) << endl;
    cout << findChar(s, 'a') << endl;
    char vers[STRING_SIZE] = R"(Endre esete
    Endre egyszer elment lesre,
    Erdeje mellett ment, mert kereste,
    Merre lehet egy medve teste?
    Melyet letepert fegyvere, kedden este.)";
    toLowerCase(vers);
    replaceCharChar(vers, 'e', '3');
    kiir(vers);
    cout << findString("aaababc" , "aab") << endl;
    stringCopy(s, "alma, alma, piros alma odafenn a fan");
    replaceStringString(s, "alma", "korte");
    kiir(s);

    stringCopy(s, "    turos puszika    ");
    trim(s);
    cout << s << endl;

    stringCopy(s, "abc def");
    slice(s, 3, 5);
    cout << s << endl;
    stringCopy(s, "abc");
    padStart(s,10,'x');
    cout << s << endl;
    padEnd(s,15,'@');
    cout << s << endl;

    return 0;
}
