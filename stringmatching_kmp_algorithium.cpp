#include <bits/stdc++.h>
using namespace std;

void update_lps(int lps[], string p)
{
    int j = 0;
    int i;
    lps[0] = 0;
    for (i = 1; i < p.size(); i++)
    {
        if (p[i] == p[j])
        {
            lps[i] = j + 1;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
                i--;
            }
            else
            {
                lps[i] = 0;
            }
        }
    }
}
void check(string p, string t, int lps[])
{
 int l=p.size();
  int j = 0;
   int i;
    for (i = 0; i < t.size() && j <= p.size(); i++)
    {
        if (t[i] == p[j])
        {
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
                i--;
            }
        }
        if(j==l)
        {
            cout<<i+1-l<<" ";
        }
    }
}
int main()
{
    string p;
    string t;
    cin>>p;
    cin>>t;
    int lps[p.size()];
    update_lps(lps, p);
    check(p, t, lps);
}
