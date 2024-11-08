#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& mat, int x1, int y1, int x2, int y2, int n, int m) {

    if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || mat[x1][y1] == 0) {
        return false;
    }


    if (x1 == x2 && y1 == y2) {
        return true;
    }


    mat[x1][y1] = 0;

    vector<int> row = {0, 0, 1, -1};
    vector<int> col = {-1, 1, 0, 0};


    for (int i = 0; i < 4; i++) {
        int newX = x1 + row[i];
        int newY = y1 + col[i];

        if (dfs(mat, newX, newY, x2, y2, n, m)) {
            return true;
        }
    }


    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (dfs(mat, x1, y1, x2, y2, n, m)) {
        cout << "yes";
    } else {
        cout << "No";
    }

    return 0;
}


/*
4 5
1 0 1 1 0
0 1 0 1 1
1 1 0 1 0
1 1 1 1 1
1 1
1 4



*/
