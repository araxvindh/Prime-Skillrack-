#include<bits/stdc++.h>
using namespace std;

bool canPlace(int n,int row,vector<vector<int>> &board, vector<bool>&sw ,vector<bool>&nw,vector<bool>&rowArr)
{
    if(row==n)
    {
        return true;
    }
    if(rowArr[row])
    {
       canPlace(n,row+1,board,sw,nw,rowArr);
    }
    else
    {
        for(int col=0;col<n;col++)
        {
            if(!sw[col-row+n-1] && !nw[col+row])
            {
                board[row][col]=1;
                sw[col-row+n-1]=true;
                nw[col+row]=true;
                rowArr[row]=true;

                if(canPlace(n,row+1,board,sw,nw,rowArr))
                {
                    return true;
                }
                else
                {
                    board[row][col]=0;
                    sw[col-row+n-1]=false;
                    nw[col+row]=false;
                    rowArr[row]=false;
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
    vector<bool>swArr(2*n+1);
    vector<bool>nwArr(2*n+1);
    vector<bool>arr(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>> board[i][j];
            if(board[i][j]==1)
                {
                    swArr[j-i+n-1]=true;
                    nwArr[i+j]=true;
                    arr[i]=true;
                }
        }
    }

    if(canPlace(n,0,board,swArr,nwArr,arr))
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
placing the bishops in the given chessboard
it can move diagonally

input:
4
1 0 0 0
0 0 0 0
0 0 0 1
0 1 0 0

output:
1 0 0 0
1 0 0 0
0 0 0 1
0 1 0 1

if multiple arr id possible then the starting from the top row and consider the possiblity once the lefft most col is fillied


NorthWest diagonal (row+col)

south west diagonal(col-row-n+1)

total no each diagonal will be 2n+1

*/
