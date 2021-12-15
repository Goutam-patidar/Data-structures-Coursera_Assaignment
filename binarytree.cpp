#include <bits/stdc++.h>


using namespace std;
struct input
{
    int info;
    int indexl;
    int indexr;

} input;
struct node
{
    int data;
    struct node *l;
    struct node *r;
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

void inorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    inorder(root->l);
    cout << root->data << " ";
    inorder(root->r);
    return;
}
void preorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->l);
    preorder(root->r);
    return;
}
void postorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    postorder(root->l);
    postorder(root->r);
    cout << root->data << " ";
    return;
}

int main()
{
    int i, n;
    //enter the size of array to be form==n;
    cin >> n;
    struct input a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i].info;
        cin >> a[i].indexl;
        cin >> a[i].indexr;
    }
    struct node *root;
    root = createtree(a, 0);
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
}
