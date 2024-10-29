#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >>n>>k;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>> arr[i];
    }

    int sum=0;
    int index=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }


    for(int i=1;i<n-k+1;i++)
    {
        cout<<sum<<" ";
        sum=sum-arr[index++];
        sum=sum+arr[index+k-1];
    }
    cout<<sum<<" ";
}
/*
11 4
1 2 3 2 4 5 1 5 8 9 10


Sliding window method (where one element will excluded and other one will get in included
*/
