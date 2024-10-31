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
    int sumVal=arr[0];
    int mini = (arr[0]<=0)?arr[0]:0 ;

    for(int i=1;i<n;i++)
    {
        sumVal+=arr[i];

        if(sumVal>0)
        {
            sumVal=0;
        }
        if(sumVal < mini)
        {
            mini=sumVal;

        }
    }
    cout<< mini;

}
/*
6
-5 -2 9 -1 -8 -2

the elements in a sub array must be continuous . the sub array having min sum is -1 -8 -2
*/
