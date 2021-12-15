#include <bits/stdc++.h>

using namespace std;

unsigned int match(string p, unsigned int i, unsigned int l)
{
    unsigned int j, s = 0;

    for (j = i; j < l; j++)
    {
        s = s + p[j] * pow(10, l - 1 - j);
    }
    return (s);
}
void check(string p, string t,unsigned int k,unsigned int l)
{
    unsigned int j=0, i;

    for (i=k; i<k+l; i++)
    {


        if (t[i] == p[j])
        {
            j++;
        }
        else
        {
            break;
        }
    }
    if (j==l)
    {
        cout << k << " ";
    }
}

int main()
{
    unsigned int l, L, l1, i, a = 0, b = 0;
    string p;
    string t;
    cin >> p;
    cin >> t;

    L = l = p.size();
    l1 = t.size();
    if (l1 > l)
    {
        a = match(p, 0, l);
        for (i = 0; i <=l1 - L; i++)
        {
            int k=i;
            b=0;
            l=L;
            l = l + i;
            b = match(t, i, l);
            if (a == b)
            {
                check(p, t,i, L);
            }
            i=k;
        }
    }

}
