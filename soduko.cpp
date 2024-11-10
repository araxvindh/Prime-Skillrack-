#include<bits/stdc++.h>

using namespace std;

class Cell
{
public:
    int row;
    int col;

    Cell(int r,int c): row(r),col(c) {}

};


Cell getUnfilled(vector<vector<char>>&board,int sizeT)
    {
        for(int r=0; r<sizeT; r++)
        {
            for(int c=0; c<sizeT; c++)
            {
                if(board[r][c]=='.')
                {
                    return Cell(r,c);
                }
            }
        }return Cell(-1, -1);

    }

bool solve(vector<vector<char>>&board, vector<int>&rflag,vector<int>&cflag,vector<int>&sflag,int sizeT)
{
    Cell toFill = getUnfilled(board,sizeT);
    if(toFill.row==-1 && toFill.col==-1)
    {
        return true ;
    }
    for(int dig=1; dig<=9; dig++)
    {
        int submix=(toFill.row/3)*3 + toFill.col/3;
        if ((rflag[toFill.row] & (1 << dig)) == 0 &&
                (cflag[toFill.col] & (1 << dig)) == 0 &&
                (sflag[submix] & (1 << dig)) == 0)
        {
            board[toFill.row][toFill.col]=(char)('0'+dig);
            rflag[toFill.row]|=(1<<dig);
            cflag[toFill.col]|=(1<<dig);
            sflag[submix]|=(1<<dig);
            if(solve(board,rflag,cflag,sflag,sizeT))
            {
                return true;
            }
            else
            {
                board[toFill.row][toFill.col]= '.';
                rflag[toFill.row]^=(1<<dig);
                cflag[toFill.col]^=(1<<dig);
                sflag[submix]^=(1<<dig);
            }

        }

    }
    return false;
}

    int main()
    {
        int sizeT=9;
        int r =sizeT,c=sizeT ;
        vector<vector<char>>board(r,vector<char>(r));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>board[i][j];
            }
        }
        vector<int>rflag(r,0);
        vector<int>cflag(c,0);
        vector<int>sflag(sizeT,0);
        for(int row=0; row<r; row++)
        {
            for(int col=0; col<c; col++)
            {
                char ch = board[row][col];
                if(ch!='.')
                {
                    int smidx=(row/3)*3+col/3;
                    int dig =(int)(ch-'0');
                    rflag[row]|=(1<<dig);
                    cflag[col]|=(1<<dig);
                    sflag[smidx]|=(1<<dig);

                }
            }
        }
        solve(board,rflag,cflag,sflag,sizeT);
        for(int i=0;i<r;i++){
            for(int j=0;j<r;j++){
                cout <<board[i][j]<<" ";
            }cout << endl;
        }
    }
