// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  static bool comp(pair<int,int> a, pair<int,int> b)
     {
       return a.first > b.first;
     }
    int maxCoins(int a[], int b[], int T, int N) {
        // code here
        vector <pair<int,int>> v;
       for (int i=0; i<N; i++)
       {
           v.push_back({b[i],a[i]});
       }
       sort (v.begin(), v.end(), comp);
       int ans=0;
       for(int i=0;i<N;i++)
       {
           if(T==0)
           break;
           else
           {
               if(v[i].second<=T)
               {
                   ans=ans+v[i].first*v[i].second;
                   T=T-v[i].second;
                   
               }
               else
               {
                   ans=ans+v[i].first*T;
                   break;
                   
               }    
           }
       }
       return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends