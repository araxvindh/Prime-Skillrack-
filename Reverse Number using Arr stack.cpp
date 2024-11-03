#include<bits/stdc++.h>

using namespace std;

vector<int>st(1000);
int top=-1;
int  peek()
{
     return st[top];
}

void push(int val)
{
    st[++top]=val;
}
int  pop()
{
    return st[top--];
}
int isEmpty()
{
     return (top==-1)?1:0;

}
int main()
{
    int n;
    cin>>n;
    int curVal;
    vector<int>arr(n);

    for(int i=1;i<=n;i++)
    {
        cin>> curVal;
        push(curVal);
    }

    while(!isEmpty())
    {
        cout << pop();

    }
}

/*
5
10 20 30 40 50
*/
