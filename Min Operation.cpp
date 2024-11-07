
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    if(n==1 || n==2)
    {
        cout<<n;
    }
    else
    {


    int cnt=2;
    while(n!=2)
    {
        if(n%2==0)
        {
            n=n/2;
            cnt++;
        }
        else
        {
            n=n-1;
            cnt++;
        }
    }
    cout<<cnt;
    }
}
/*
N=8

0+1 = 1
1+1=2
2*2=4
4*2=8

total operation of 4

input:
43
output:
9


*/
