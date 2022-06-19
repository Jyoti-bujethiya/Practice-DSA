// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> nearestPerfectSquare(int N) {
        // code here
          vector<int> v;
       int root=round(pow(N,0.5));
       int square=pow(root,2);
       int dif=abs(square-N);
       v.push_back(square);
       v.push_back(dif);
       return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.nearestPerfectSquare(N);
        cout << ans[0] << " " << ans[1] << "\n";
    }
}  // } Driver Code Ends