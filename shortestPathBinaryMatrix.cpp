class Solution {
public:

    vector<pair<int,int>>getAdj(int row ,int col ,vector<vector<int>>& grid)
    {
        vector<int>row1={-1,1,0,0,-1,1,-1,1};
        vector<int>col1={0,0,1,-1,-1,1,1,-1};
        vector<pair<int,int>>ans;
        for(int i=0;i<8;i++)
        {
            int newRow =row+row1[i];
            int newCol=col+col1[i];

            if(newRow>=0 && newCol>=0 && newRow<grid.size() && newCol<grid[0].size())
            {
                ans.push_back({newRow,newCol});
            }
        }
        return ans;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m =grid[0].size();
        
        if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        vector<vector<int>>vis(n,vector<int>(m,0));

        int dis=1;

        queue<pair<int,int>>q;
        vis[0][0]=1;
        q.push({0,0});

        while(!q.empty())
        {
            int size =q.size();
            for(int i=0;i<size;i++)
            {
                auto top = q.front();
                q.pop();
                int row =top.first;
                int col =top.second;
                if(row==n-1 && col==m-1) return dis;
                vector<pair<int,int>>adj = getAdj(row,col,grid);
                for(auto it : adj)
                {
                    int row2=it.first;
                    int col2=it.second;

                    if(vis[row2][col2]==0 && grid[row2][col2]==0)
                    {
                        vis[row2][col2]=1;
                        q.push({row2,col2});
                    }
                }
            }
            dis+=1;
        }
        return -1;
    }
};
