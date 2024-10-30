#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n,m;
    cin>>n>>m;

    vector<vector<int>>mat(n,vector<int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }

    vector<vector<int>>path(n,vector<int>(m,0));

    path[n-1][0]=mat[n-1][0];

    for(int row= n-2; row>=0;row-- )
    {
        if(mat[row][0]==1)
        {
            path[row][0]=path[row+1][0];
        }
    }

    for(int col=1;col<m;col++)
    {
        if(mat[n-1][col]==1)
        {

            path[n-1][col]=path[n-1][col-1];
        }
    }
    for(int i =n-2;i>=0;i--)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                path[i][j]=path[i+1][j]+path[i][j-1];
            }
        }
    }
    if(path[0][m-1] >0)
    {
        cout<<"Yes " << path[0][m-1];
    }
}





/*


it will be similar to the prev code top right to bottom right
*/
