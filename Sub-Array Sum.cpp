#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {

        cin>>arr[i];
    }

    int left=0;

    int right=0;

    int currSum=arr[0];
    while(right<n &&left<n)
    {
        if(currSum==k)
        {
            cout<<"Yes";
            break;
        }
        else if(currSum>k)
        {
            currSum-=arr[left++];

        }
        else
        {
            currSum+=arr[++right];
        }
    }
}

/*

5
5 10 50 20 25
45

Yes


*/
