#include<iostream>
#include<vector>
using namespace std;

void goland(vector<vector<int >>& vec, int i, int j, int n, int m, vector<vector<bool>>& visited){
	if (i < 0 || i >= n || j < 0 || j >= m) return;
	visited[i][j] = true;
	if (i - 1 >= 0 && visited[i - 1][j] == false && vec[i - 1][j] == 1)
		goland(vec, i - 1, j, n, m, visited);
	if (i + 1 < n && visited[i + 1][j] == false && vec[i + 1][j] == 1)
		goland(vec, i + 1, j, n, m, visited);
	if (j - 1 >= 0 && visited[i][j - 1] == false && vec[i][j - 1] == 1)
		goland(vec, i, j - 1, n, m, visited);
	if (j + 1 < m && visited[i][j + 1] == false && vec[i][j + 1] == 1)
		goland(vec, i, j + 1, n, m, visited);
}

void cntland(vector<vector<int >>& vec, int i, int j, int n, int m, int& cnt, vector<vector<bool>>& visited){
	if (!visited[i][j]){
		cnt++;
		goland(vec, i, j, n, m, visited);
		return;
	}
}

int main(){
	int n = 0;
	int m = 0;
	while (cin >> n >> m){
		vector<vector<int >> vec(n, vector<int>(m));
		vector<vector<bool >> visited(n, vector<bool>(m));
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin >> vec[i][j];
			}
		}
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				visited[i][j] = false;
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if (vec[i][j] == 0) continue;
				cntland(vec, i, j, n, m, cnt, visited);
			}
		}
		cout << cnt << endl;
	}
	return 0;
}