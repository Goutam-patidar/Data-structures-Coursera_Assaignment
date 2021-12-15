#include <bits/stdc++.h>

using namespace std;
int main()
{
   unsigned  int l,l1,i,j;
    l=l1=i=j=0;
   string v,v1;
    cin >> v;
    cin >> v1;
    l = v.size();
    l1 = v1.size();
    if(l==0 ||l1==0)
    {
        return (0);
    }
    if(l>l1)
    {
        return(0);
    }
    else{
     for (i = 0; i <= l1 - l; i++)
    {
        for (j = 0; j < l; j++)
        {
            if (v1[i + j] != v[j])
            {
                break;
            }
        }
        if (j == l)
        {
            cout << i << " ";
        }
    }
    }

    return 0;
}
