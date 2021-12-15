#include <iostream>

using namespace std;
int main()
{
    long long int a, n, i;

    cin >> a;
    for (i = 1; i <= a; i++)
    {long long int sum = 0, rem;
        cin >> n;
        if (n > 2)
        {
            if(n%4==0)
            {
                cout << "YES";
            }
            else
            {
                cout << "NO";
            }
        }
        else
        {
            cout << "NO";
        }
    }
}
