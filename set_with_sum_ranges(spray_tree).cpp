#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

typedef struct node
{
    struct node *left;
    ll data;
    struct node *right;
} node;

node *rightRotate(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

node *splay(node *root, ll data)
{
    if (root == NULL || root->data == data)
        return root;

    if (root->data > data)
    {
        if (root->left == NULL)
            return root;

        if (root->left->data > data)
        {
            root->left->left = splay(root->left->left, data);
            root = rightRotate(root);
        }
        else if (root->left->data < data)
        {
            root->left->right = splay(root->left->right, data);

            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    else // data lies in right subtree
    {
        if (root->right == NULL)
            return root;

        if (root->right->data > data)
        {
            root->right->left = splay(root->right->left, data);

            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        else if (root->right->data < data) // Zag-Zag (Right Right)
        {
            root->right->right = splay(root->right->right, data);
            root = leftRotate(root);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}

int search(node *root, ll data)
{
    root = splay(root, data);
    if(root==0)
        return 0;
    return (root->data == data ? 1 : 0) ;
}

struct node *createtree(struct node *root, ll b)
{
    struct node *newnode;

    newnode = new struct node;
    newnode->data = b;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
    {
        root = newnode;
        return (root);
    }
    splay(root, newnode->data);
    if (root->data == newnode->data)
    {
        return (root);
    }
    if (root->data > newnode->data)
    {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
    else
    {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
    return (newnode);
}

ll rangesum(struct node *root, ll a, ll b, ll s)
{
    if (root == NULL)
    {
        return (s);
    }
    s = rangesum(root->left, a, b, s);
    if (root->data <= b && root->data >= a)
    {
        s = s + root->data;
    }
    s = rangesum(root->right, a, b, s);
    return (s);
}

struct node *deletedata(struct node *root, ll data)
{
    struct node *temp;
    if (!root)
        return NULL;
    root = splay(root, data);
    if (data != root->data)
        return root;
    if (!root->left)
    {
        temp = root;
        root = root->right;
    }
    else
    {
        temp = root;

        root = splay(root->left, data);
        root->right = temp->right;
    }
    free(temp);
    return root;
}

int main()
{
    struct node *root;
    root = NULL;
    ll n, i, x = 0, b, c;
    cin >> n;
    char a;

    for (i = 0; i < n; i++)
    {
        b = c = 0;
        cin >> a;
        if (a == '+')
        {
            cin >> b;
            b = ((b + x) % 1000000001);

            root = createtree(root, b);
        }
        if (a == '-')
        {
            cin >> b;
            b = ((b + x) % 1000000001);
            root = deletedata(root, b);
        }
        if (a == '?')
        {
            cin >> b;
            b = ((b + x) % 1000000001);
            if (search(root, b) == 1)
                cout << "Found" << endl;
            else
            {
                cout << "Not found" << endl;
            }
        }
        if (a == 's')
        {
            ll sum = 0;
            cin >> b >> c;
            b = ((b + x) % 1000000001);
            c = ((c + x) % 1000000001);
            sum = rangesum(root, b, c, 0);
            x = sum;
            cout << sum << endl;
        }
    }
}
