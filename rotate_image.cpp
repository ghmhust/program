#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = 0;
        if(m>=1) n = matrix[0].size();
        if(m<=1 || n<=1) return;
        for(int j = 0;j<n;++j){
            for(int i = 0;i<m/2;++i){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[m-i-1][j];
                matrix[m-i-1][j] = temp;
            }
        }
        for(int i = 0;i<m;++i){
            for(int j = i;j<n;++j){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return;
    }
int main() {
    cout << "Hello, World!" << std::endl;
    return 0;
}