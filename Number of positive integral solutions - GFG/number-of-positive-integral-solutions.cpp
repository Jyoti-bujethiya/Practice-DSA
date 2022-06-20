// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
   long long ncr(long long n, long long r){
       long long C[r + 1] = {0};
       C[0] = 1;
       for (long long i = 1; i <= n; i++) 
           for (long long j = min(i, r); j > 0; j--)
               C[j] = C[j] + C[j - 1];
       return C[r];
    }

    long posIntSol(string s)
    {
        bool found = false;
        long long ans = 0, plus = 1, n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '+'){
                plus++;
            }
            if(s[i] == '='){
                found = true;
            }
            else if(found){
                ans = ans*10 + (s[i] -'0'); 
            }
        }
        ans -= plus;
        if(ans < 0) return 0;
        return ncr(ans + plus - 1, plus - 1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends