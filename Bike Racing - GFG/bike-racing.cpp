// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long TrackSpeed(long A[], long H[], long N, int L, long hour)
    {
        long long ans = 0;
        for (int i = 0; i < N; i++)
        {
            if (H[i] + hour * A[i] >= L)
                ans += (H[i] + hour * A[i]);
        }
        return ans;
    }
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long long l = 1, r = INT_MAX;
        long long mid, trackspeed;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            trackspeed = TrackSpeed(A, H, N, L, mid);
            if (trackspeed > M)
                r = mid - 1;
            else if (trackspeed < M)
                l = mid + 1;
        }
        trackspeed = TrackSpeed(A, H, N, L, mid);
        if (trackspeed >= M)
            return mid;
        return mid + 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends