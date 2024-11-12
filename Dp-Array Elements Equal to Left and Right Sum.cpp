#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin>>n;
    vector<int>arr(n);
    vector<int>sum(n);


    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sum[0]=arr[0];
    for(int i=1;i<n;i++)
    {

        sum[i]=sum[i-1]+arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int left =abs(sum[i]-arr[i]);
        int right =abs(sum[n-1]-sum[i]);

        if(left==right)
        {
            cout<< arr[i]<<" ";
        }
    }
}
/*
input:
6
7 2 1 -5 5 5

output:
-5 5

*/
