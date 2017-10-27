#include <iostream>
#include <vector>
#include <string>
#include <queue>
/*
 * leetcode 2017.10.27
 * Surrounded Regions
 * BFS
 * */
using namespace std;

void solve(vector<vector<char>>& board) {
    int m = board.size();
    if(m == 0) return;
    int n = board[0].size();
    if(n == 0) return;
    queue<int> xindex,yindex;
    for(int i = 0;i<m;++i){
        if(board[i][n-1] == 'O'){
            xindex.push(i);
            yindex.push(n-1);
        }
        if(board[i][0] == 'O'){
            xindex.push(i);
            yindex.push(0);
        }
    }
    for(int j = 1;j<n-1;++j){
        if(board[0][j] == 'O'){
            xindex.push(0);
            yindex.push(j);
        }
        if(board[m-1][j] == 'O'){
            xindex.push(m-1);
            yindex.push(j);
        }
    }
    while(!xindex.empty()){
        int x = xindex.front();
        int y = yindex.front();
        xindex.pop();
        yindex.pop();
        board[x][y] = 'Y';
        if(x>0 && board[x-1][y] == 'O'){
            xindex.push(x-1);
            yindex.push(y);
        }
        if(x<m-1 && board[x+1][y] == 'O'){
            xindex.push(x+1);
            yindex.push(y);
        }
        if(y>0 && board[x][y-1] == 'O'){
            xindex.push(x);
            yindex.push(y-1);
        }
        if(y<n-1 && board[x][y+1] == 'O'){
            xindex.push(x);
            yindex.push(y+1);
        }
    }
    for(int i = 0;i<m;++i){
        for(int j = 0;j<n;++j){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
    for(int i = 0;i<m;++i){
        for(int j = 0;j<n;++j){
            if(board[i][j] == 'Y')
                board[i][j] = 'O';
        }
    }
}

int main() {
    int m,n;
    while(cin>>m>>n){
        vector<vector<char> >temp(m,vector<char>(n));
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                cin>>temp[i][j];
            }
        }
        solve(temp);
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                cout<<temp[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}