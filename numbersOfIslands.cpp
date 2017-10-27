#include <iostream>
#include <vector>
/*
 * leetcode 2017.10.27
 * Number of Islands
 * DSF
 * */
using namespace std;

void cntisland(vector<vector<char>>& grid,int i,int j,int m,int n,vector<vector<int>> &visited){
    if(i<0 || i>m-1) return;
    if(j<0 || j>n-1) return;
    if(visited[i][j] == 1 || grid[i][j] != '1') return;
    visited[i][j] = 1;
    cntisland(grid,i-1,j,m,n,visited);
    cntisland(grid,i,j-1,m,n,visited);
    cntisland(grid,i+1,j,m,n,visited);
    cntisland(grid,i,j+1,m,n,visited);
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> >visited(m,vector<int> (n));
    for(int i = 0;i<m;++i)
        for(int j = 0;j<n;++j)
            visited[i][j] = 0;
    int cnt = 0;
    for(int i = 0;i<m;++i){
        for(int j = 0;j<n;++j){
            if(grid[i][j] == '1' && visited[i][j] == 0){
                cntisland(grid,i,j,m,n,visited);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int m,n;
    while(cin>>m>>n) {
        vector<vector<char> > temp(m, vector<char>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> temp[i][j];
            }
        }
        int res = numIslands(temp);
        cout << res << endl;
    }
    return 0;
}