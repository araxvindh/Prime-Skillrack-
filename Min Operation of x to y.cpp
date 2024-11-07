
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    int cnt=0;
    while(y>x)
    {

        if(y%2==1)
        {
            y=y+1;
        }
        else
        {
            y=y/2;
        }
        cnt++;
    }
    cnt=cnt+(x-y);
    cout<<cnt;

}

/*
input:
5 8
output:
2

input:
10 1
output:
9

*/
