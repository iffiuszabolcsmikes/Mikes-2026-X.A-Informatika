#include <iostream>

using namespace std;

const int STRING_SIZE = 1000;

int stringLength_index(char strng[])
{
    int i = 0;
    while(strng[i] != 0) i++;
    return i;
}

void toUpperCase_index(char strng[])
{
    int i = 0;
    while(strng[i] != 0)
    {
        if(strng[i] >= 'a' && strng[i] <= 'z')
            strng[i] -= 'a' - 'A';
        i++;
    }
}

void toLowerCase_index(char strng[])
{
    int i = 0;
    while(strng[i] != 0)
    {
        if(strng[i] >= 'A' && strng[i] <= 'Z')
            strng[i] += 'a' - 'A';
        i++;
    }
}

void stringCopy_index(char dst[], char src[])
{
    int i = 0, j = 0;
    while (src[i] != 0)
    {
        dst[i] = src[i];
        i++;
        j++;
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
    return 0;
}
