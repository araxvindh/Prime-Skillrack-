#include<bits/stdc++.h>

using namespace std;
bool isValidSudoku(vector<vector<char>>&board)
{
    vector<int>rflag(9,0);
    vector<int>cflag(9,0);
    vector<int>sflag(9,0);

    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col]!='.'){
                    int digit=(int)board[row][col]-'0';
                    int midx= (row/3)*3+col/3;
                    if((rflag[row]&(1<<digit))&&(cflag[row]&(1<<digit))&&(sflag[midx]&(1<<digit))){
                        return false;
                    }else{
                        rflag[row]|=1<<digit;
                        cflag[col]|=1<<digit;
                        sflag[midx]=1<<digit;
                    }
            }
        }
    }
    return true;
}





int main()
{
    int n=9;

    vector<vector<char>>board(n,vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    cout<< isValidSudoku(board);
}

/*
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9

*/
