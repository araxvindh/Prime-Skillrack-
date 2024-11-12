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
    int m =1;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=m)
        {
            m+=arr[i];
        }
        else
        {
            break;
        }
    }
    cout<<m;
}

/*
input:
4
2 4 1 10

output:
8


input:
5
1 4 2 4 3

output:
15


logic : sort the arry
1 2 4 10
let m=1
if( arr[index] <= m)
    m+=arr[index]

dry run
1 poss
now i=2 (which is equal)
m=2
m+=2
2 3 poss
m=4
now i=4 and m=4
m+=4
1 2 3 4 5 6 7 poss
m=8
i =10 which is greater than the value of m
print(8)


*/
