#include <iostream>
#include <vector>
using namespace std;
int findLength(vector<int>& A, vector<int>& B) {
    int lena = A.size();
    int lenb = B.size();
    vector<vector<int> > dp(lena+1,vector<int>(lenb+1));
    for(int i = 0;i<lena+1;++i) dp[i][0] = 0;
    for(int j = 0;j<lenb+1;++j) dp[0][j] = 0;
    for(int i = 1;i<lena+1;++i){
        for(int j = 1;j<lenb+1;++j){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = 0;
        }
    }
    int res = INT_MIN;
    for(int i = 0;i<lena+1;++i){
        for(int j = 0;j<lenb+1;++j){
            if(dp[i][j]>=res)
                res = dp[i][j];
        }
    }
    return res;
}
int main() {
    int n;
    while(cin>>n){
        vector<int> A(n);
        vector<int> B(n);
        for(int i = 0;i<n;++i){
            cin>>A[i];
        }
        for(int i = 0;i<n;++i){
            cin>>B[i];
        }
        int res = findLength(A,B);
        cout<<res<<endl;
    }
    return 0;
}