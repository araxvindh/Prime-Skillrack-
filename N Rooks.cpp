#include<bits/stdc++.h>
using namespace std;

bool canPlace(int n,int row,vector<vector<int>> &board, vector<bool>&rr ,vector<bool>&rc)
{
    if(row==n)
    {
        return true;
    }
    if(rr[row])
    {
       canPlace(n,row+1,board,rr,rc);
    }
    else
    {
        for(int col=0;col<n;col++)
        {
            if(!rc[col] && !rr[row])
            {
                board[row][col]=1;
                rr[row]=true;
                rc[col]=true;

                if(canPlace(n,row+1,board,rr,rc))
                {
                    return true;
                }
                else
                {
                    board[row][col]=0;
                    rr[row]=true;
                    rc[col]=true;
                }
            }
        }return false;
    }

}




int main()
{
    int n;
    cin>>n;
    vector<vector<int>>board(n,vector<int>(n));
    vector<bool>rooksRow(n);
    vector<bool>rooksCol(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>> board[i][j];
            if(board[i][j]==1)
                {
                    rooksRow[i]=true;
                    rooksCol[j]=true;
                }
        }
    }

    if(canPlace(n,0,board,rooksRow,rooksCol))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";

            }
            cout<<" "<<endl;
        }
    }
    else
    {
        cout<< "NOTPossible";
    }

}
/*
placing the Rooks in the given chessboard
it can move row or col

input:
4
1 0 0 0
0 0 0 0
0 0 0 1
0 1 0 0

output:
1 0 0 0
0 0 1 0
0 0 0 1
0 1 0 0

if multiple arr id possible then the starting from the top row and consider the possiblity once the lefft most col is fillied

logic and logic  : https://youtu.be/uDvsL9twFWU


*/

