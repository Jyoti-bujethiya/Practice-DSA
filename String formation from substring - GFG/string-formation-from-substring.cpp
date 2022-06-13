// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    bool isPossible(int len, string& s, int n){
        // The repeating string is of size == len
        for(int i = len; i < n; i++){
            if(s[i] != s[i%len])
                return false;
        }
        return true;
    }
    
	int isRepeat(string s)
	{
	    int n = s.size();
	    if(n == 1) return 0;
	    // O(N * Log(N))
	    // Because number of divisors is not large we can consider this as ~ O(N)
	    for(int i = 1; i * i <= n; i++){
	        if(n % i == 0){
	            // O(N)
	            if(isPossible(i, s, n))
	                return 1;
	            if(i != 1 && i*i != n && isPossible(n/i, s, n)){
	                return 1;
	            }
	        }
	    }   
	    return 0;
	}

};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;
        Solution ob;
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends