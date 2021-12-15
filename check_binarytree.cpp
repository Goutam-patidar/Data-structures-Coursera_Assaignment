#include <bits/stdc++.h>

using namespace std;
struct input
{
    int info;
    int indexl;
    int indexr;
};
struct node
{
    long long int data;
    node *l;
    node *r;
};

struct node *createtree(struct input a[], int i)
{
    struct node *newnode;
    newnode = new struct node;
    if (i == -1)
    {
        return (0);
    }
    newnode->data = a[i].info;
    newnode->l = createtree(a, a[i].indexl);
    newnode->r = createtree(a, a[i].indexr);
    return (newnode);
}

int checkuntil(struct node *root, int min, int max)
{
    if (root == 0)
    {
        return (1);
    }
    if (root->data > max || root->data < min)
    {
        return (0);
    }
    return (
        checkuntil(root->l, min, root->data - 1) &&  //*
        checkuntil(root->r, root->data + 1, max));
}
bool checkbt(struct node *root)
{
    return (checkuntil(root, INT_MIN, INT_MAX));
}

int main()
{
    int n = 0, i = 0;
    cin >> n;
    if (n == 0)
    {
        cout << "CORRECT" << endl;
        return (0);
    }
    struct input a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i].info;
        cin >> a[i].indexl;
        cin >> a[i].indexr;
    }
    struct node *root;
    root = createtree(a, 0);
    bool b = checkbt(root);
    if (b)
    {
        cout << "CORRECT" << endl;
    }
    else
    {
        cout << "INCORRECT" << endl;
    }
}
