#include <bits/stdc++.h>
#include <map>

using namespace std;
int main()
{
    map<int, string> m;
    int n, i, no;
    n = i = 0;
    string name;
    cin >> n;
    char *x;
    map<int, string>::iterator it;
    char a[10];
    for (i = 0; i < n; i++)
    {

        no = 0;
        cin >> a;
        if (a[0] == 'a')
        {
            cin >> no;
            cin >> name;
            it = m.find(no);
            if (it != m.end())
            {
                it->second = name;
            }
            else
            {
                m.insert(pair<int, string>(no, name));
            }
        }

        if (a[0] == 'd')
        {
            cin >> no;
            m.erase(no);
        }
        if (a[0] == 'f')
        {
            cin >> no;
            //int l=m.size();
            //int o=m.empty();
            if (m.empty() != 0)
            {
                cout << "not found" << endl;
            }
            else
            {
                if (no < 0)
                {
                    cout << "not found" << endl;
                }
                if (no == 0 || no > 0)
                {

                    it = m.find(no);
                    if (it == m.end())
                    {
                        cout << "not found" << endl;
                    }
                    else
                    {
                        cout << m.at(no) << endl;
                    }
                }
            }
        }
    }
}
