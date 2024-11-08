#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&mat,int row,int col,int R, int C)
{
    if((row<0 || row>=R || col<0 || col>=C) || (mat[row][col]==0))
    {
        return ;
    }

    mat[row][col]=0;
    vector<int>rowR={0,0,1,-1};
    vector<int>colC={-1,1,0,0};
    for(int i=0;i<4;i++)
    {
        int newRow=row+rowR[i];
        int newCol=col+colC[i];

        dfs(mat,newRow,newCol,R,C);
    }


}


int main()
{
     int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int k;
    cin>>k;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==k)
            {
                cnt++;
                dfs(mat,i,j,n,m);
            }
        }
    }
    cout<<cnt;
}
/*
5 5
5 6 0 5 6
1 8 8 0 2
5 5 5 0 6
4 5 5 5 0
8 8 8 8 8
6

Output:
2

4 5
5 0 0 5 6
1 0 8 1 0
0 5 0 0 6
4 5 0 5 2
5
*/
