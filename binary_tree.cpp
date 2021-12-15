#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    struct node* l;
    struct node* r;
}node;
struct node* createtree()
{
struct node* newnode;
 newnode=new  struct node;
 int n;
cin>>n;
if(n==-1)
{
    return(0);
}
newnode->info=n;
//cout<<"now enter value of left sub tree";
newnode->l=createtree();
//cout<<"now enter value of right sub tree";
newnode->r=createtree();

return(newnode);
}
int main()

{
    struct node *root;
    root=createtree();
}