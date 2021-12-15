
#include <iostream>
#include <string.h>


using namespace std;

struct stakearray
{
    int top;
    int capacity;
    int *a;
};
int m=0;
struct stakearray* createstake(int cap)
{
    struct stakearray *stake;
    stake=new (struct stakearray);
    stake->top = -1;
    stake->capacity = cap;
    stake->a=new int[stake->capacity];
    memset(stake->a, 0, stake->capacity);
    return (stake);
}
void push(struct stakearray *stake, int x)
{
    if (stake->top == stake->capacity - 1)
    {
        return ;
    }
    else
    {
        stake->top++;
        stake->a[stake->top] = x;


        if(stake->a[stake->top]>m)
        {
            m=stake->a[stake->top];
        }
    }
}
int large(struct stakearray *stake)
{
    int z=stake->top;

    if (stake->top == -1)
    {
        return 'n' ;
    }
    else
    {
        int u = 0;

        while( stake->top>-1)
        {

            if (stake->a[stake ->top]>u )
            {
                u = stake->a[stake->top];

            }
            stake->top--;
        }

        stake->top=z;
        return(u);
    }
}

int pop(struct stakearray *stake)
{
    int item=0;
    if (stake->top == -1)
    {
        return 'n';
    }

    else

    {
         item = stake->a[stake->top];
        stake->top--;
        if(item== m)
        {
            m= large(stake);
        }
        return (item);
    }
}

int max()
{
    return(m);
}
int main()
{

    unsigned int a, s=0, x,i,y;
    // cout << "loop";
    cin >>a;
    struct stakearray *stake;
    stake = createstake( 400000);
    char tem[10];
    for (i = 0; i < a; i++)
    {
        //   cout << "enter subject eg- pop,push,max...";
        cin >> tem;
        if (tem[1] == 'o')
        {
            s = pop(stake);
            //cout<< s;
        }
        else if (tem[1] == 'u')
        {
            //     cout << "enter value";
            cin >> x;
            push(stake,x);
        }
        else if (tem[1] = 'a')
        {

            y= max();
            cout<<y<<endl;;
        }

    }

}
