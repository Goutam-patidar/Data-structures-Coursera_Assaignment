#include <bits/stdc++.h>
#include <vector>
using namespace std;
void heap(int a[], int i, int n, vector<int> &v)
{
    //int k=0;
    int m = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    while (l < n && a[l] < a[m])
    {
        m = l;
    }
    while (r < n && a[r] < a[m])
    {
        m = r;
    }
    if (i != m)
    {
        swap(a[i], a[m]);
        v.push_back(i);
        v.push_back(m);

        heap(a, m, n, v);
    }

}
int main()
{
    int n, i;
    int a[100000];
    vector<int> v;
    int flag = 0;
    cin >> n;// no. of element
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /* for(i=0;i<n/2;i++)
    {
        if(a[i]>a[2*i+1] ||a[i]>a[2*i+2])
        {
            flag++;

        }
    }
    if(flag==0)
    {
        cout<<"0"<<" "<<endl;
        return 'n';
    }
    else
    {
        cout<<flag<<endl;
            }

*/
    for (i = (n / 2) - 1; i >= 0; i--)
    {

        heap(a, i, n, v);
    }
    if (v.size() == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << v.size()/2<< endl;  //printing no. of swap perfom during exicution
        for (i = 0; i < v.size(); i++)
        {
            cout << v[i] << " " << v[i + 1]<<endl;// elements which are swap
             i++;
        }
    }
}
