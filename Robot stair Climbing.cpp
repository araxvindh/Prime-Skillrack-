#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,l;
    cin>>n>>l;
    vector<int>climb(n);
    for(int i=0;i<l;i++)
    {
        cin>>climb[i];
    }
    vector<int>ways(n+1);
    ways[0]=1;
    for(int index=1;index<=n;index++)
    {
        for(int c=0;c<l;c++)
        {

            if(index >=climb[c])
            {
                ways[index]+=ways[index-climb[c]];
            }
        }
    }
    cout<<ways[n];
}
/*
6 2
1 5
output
3
no of ways
1 1 1 1 1 1
1 5
5 1

5 2
2 3

output
2

no of ways
2 3
3 2

logic:
code:


*/
