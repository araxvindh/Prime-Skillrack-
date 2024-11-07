#include<bits/stdc++.h>
using namespace std;

int main()

{
    int n,x;
    cin>>n>>x;

    vector<int>arr(n,0);
    int a, b;
    for(int i=0;i<x;i++){
        cin>>a>>b;
        arr[a]--;
        arr[b]++;
    }
    for(int i=0;i<n;i++)
    {

        if(arr[i]==n-1)
        {
            cout<<n-1;

        }

    }


}

/*
5 7
1 3
2 3
3 4
5 3
1 4
5 4
2 4

output:
4


logic :
code:
*/
