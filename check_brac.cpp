#include <bits/stdc++.h>
#include <stack>
#include <map>


using namespace std;
int dic(char a)
{
    map<char, char> m;
    if (a == '}')
    {
        return  ( m[a] = '{');
    }
    if (a == ']')
    {
        return (m[a] = '[');
    }
    if (a == ')')
    {
        return (m[a] = '(');
    }
    return'0';
}

int main()

{
    char a[100000];
    cin >> a;
    int i, l, k, b, c,d;
    b=c=d=0;
    l=strlen(a);
    stack<char> s;
    if (a[0] == ']' || a[0] == '}' || a[0] == ')')
    {
        cout << "1" << endl;
        b=1;
    }
    else
    {
        for (i = 0; i < l; i++)
        {
            if (a[i] == '[' || a[i] == '{' || a[i] == '(')
            {
                s.push(a[i]);
                k = i+1 ;
            }
            else
            {
                if (s.size() == 0 && (a[0] == ']' || a[0] == '}' || a[0] == ')'))
                {
                    cout << i + 1 << "\n";
                    b = 1;
                    break;
                }
                else
                {
                    if(s.empty()==1)
                    {
                        cout<<i+1<<endl;
                        b=1;
                    }

                    else if (dic(a[i]) == s.top())
                    {

                        s.pop();
                    }
                    else
                    {
                        cout << i + 1 << "\n";
                        c = 1;
                        b=1;
                        break;
                    }
                }
            }
        }
    }
    if(s.empty()==1 && b==0)
    {
        cout<< "Success" <<endl;
        d=1;
    }
    if(c==0 &&b==0&&d==0)
    {
        cout<<k<<endl;
    }
}
