#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sumVal=arr[0];
    int maxii=arr[0];
    for(int i=1;i<n;i++)
    {
        sumVal=max(sumVal+arr[i],arr[i]);

        if(maxii < sumVal)
        {
            maxii=sumVal;
        }
    }
    cout<< maxii;
}

/*
5
3 2 -2 5 -4

output 8


logic https://youtu.be/YxiRc60kghI
code https://youtu.be/FWTqoQO1YFA
*/
