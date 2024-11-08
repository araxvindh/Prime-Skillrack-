#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>> arr[i];
    }

    int cnt=0;
    for(int ctr=1;ctr<(1<<n);ctr++)
    {
        int sum=0;
        for(int bin=0;bin<n;bin++)
        {
            if((ctr&(1<<bin))!=0)
            {
              sum+=arr[bin];
            }
        }
        if(sum==0)
        {
            cnt++;
        }
    }
    cout<<cnt;
}
/*
input:
5
10 -5 5 -15 20

output:
3


input:
7
10 -5 5 -15 20 5 10

*/
