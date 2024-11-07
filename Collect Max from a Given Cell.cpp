#include<bits/stdc++.h>

using namespace std;

int main()
{
    int r,c;
    cin>>r>>c;

    vector<vector<int>>mat(r,vector<int>(c));


    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
    {
        cin>>mat[i][j];
    }
    int x,y;
    cin>>x>>y;
    vector<vector<int>>dp(r,vector<int>(c,0));

    dp[x][y]=mat[x][y];

    for(int row=x+1;row<r;row++)
    {
        dp[row][y]=dp[row-1][y]+mat[row][y];
    }

    for(int col=y+1;col<c;col++)
    {
        dp[x][col]=mat[x][col]+dp[x][col-1];
    }

    for(int row=x+1;row<r;row++)
    {
        for(int col=y+1;col<c;col++)
        {
            dp[row][col]=max(dp[row-1][col],dp[row][col-1])+mat[row][col];
        }
    }
    cout<< dp[r-1][c-1];
}

/*
input:
4 5
4 2 9 6 1
7 9 6 5 4
5 7 3 8 8
7 4 9 9 4
0 1

Output:
44

Explanation:
2->9->7->4->9->9->4

total = 44

input:
3 3
70 76 60
18 64 39
45 28 79
1 1

output:
182

logic:
code:


*/
