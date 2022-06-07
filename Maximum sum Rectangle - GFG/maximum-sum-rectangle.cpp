// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
         int ans = 0;
        int ans1 = -1000;
        for(int i = 0 ; i < R ; i ++){
            for(int j = 0 ;  j < C ; j ++){
                ans1 = max(ans1,M[i][j]);
            }
        }
        for(int i = 0 ; i < C ; i ++){
            vector< int > dp(R,0);
            for(int j = i ; j < C ; j++){
                for(int k = 0 ; k < R; k ++){
                    dp[k] += M[k][j];
                }
                int res = 0;
                for(int k = 0 ; k < R ; k ++){
                    res += dp[k];
                    if(res < 0) res  = 0;
                    ans = max(ans,res);
                }
            }
        }
        if(ans == 0) return ans1;
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends