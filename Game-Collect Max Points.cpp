#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;

    vector<vector<int>>mat(r,vector<int>(c));
    vector<vector<int>>dp(r,vector<int>(c,0));

    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
    {
        cin>>mat[i][j];
    }

    dp[0][0]=mat[0][0];
    for(int col=1;col<c;col++)
    {
        dp[0][col]=mat[0][col]+dp[0][col-1];
    }

    for(int row=1;row<r;row++)
    {
        dp[row][0]=mat[row][0]+dp[row-1][0];
    }

    for(int row=1;row<r;row++)
    {
        for(int col=1;col<c;col++)
        {
            dp[row][col]=max(dp[row-1][col]+mat[row][col],dp[row][col-1]+mat[row][col]);
        }
    }
    cout<<dp[r-1][c-1];

}


/*
input:
4 5
4 2 9 6 1
7 9 6 5 4
5 7 3 8 8
7 4 9 9 4

Output:
53

Explanation:
4->7->9->7->4->9->9->4
total(53)

input:
3 3
48 64 47
63 33 14
44 82 52

output:
289


logic:
code:
*/
