#include <bits/stdc++.h>
#include <stack>

using namespace std;

int main()
{
    stack<unsigned int> s;
    stack< unsigned int> l;
    unsigned int a = 0;
    int i,n = 0,max;
    char b[5];
    cin >> a;
    for (i = 0; i <a; i++)
    {
        cin >> b;
        if (b[1] == 'u')
        {
            cin >> n;
            s.push(n);
            if (i == 0)
            {
                l.push(n);
            }
            else
            {
                if (l.top() > s.top())
                {
                    l.push(l.top());
                }
                else
                {
                    l.push(n);
                }
            }
        }
        if (b[1] =='o')
        {
            s.pop();
            l.pop();
        }
        if (b[1] == 'a')
        {
            max=l.top();
            cout<<max<<"\n";
        }
    }
}
