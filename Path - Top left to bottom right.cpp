#include<bits/stdc++.h>

using namespace std;

int totalPath(int n,int m,vector<vector<int>>&mat,vector<vector<int>>&pathMat)

{
   pathMat[0][0]=mat[0][0];
  for(int col=1;col<m;col++)
  {
      if(mat[0][col]==1)
      {
          pathMat[0][col]=pathMat[0][col-1];
      }
  }

  for(int row=1;row<n;row++)
  {
      if(mat[row][0]==1)
      {
          pathMat[row][0]=pathMat[row-1][0];
      }
  }

  for(int i=1;i<n;i++)
  {
      for(int j=1;j<m;j++)
      {
          if(mat[i][j]==1)
          {
              pathMat[i][j]=pathMat[i-1][j]+pathMat[i][j-1];
          }
      }
  }
  return pathMat[n-1][m-1];
}

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
    vector<vector<int>>pathMat(n,vector<int>(m,0));

    cout<< totalPath(n,m,mat,pathMat);

}

/*
4 5
1 1 1 1 0
0 1 0 1 1
1 1 0 1 0
1 1 1 1 1


if 1 path is available
if 0 path is zero

path 1

- - 1 1 0
0 - 0 1 1
1 - 0 1 0
1 - - - -

path 2

- - - - 0
0 1 0 - 1
1 1 0 - 0
1 1 1 - -


*/
