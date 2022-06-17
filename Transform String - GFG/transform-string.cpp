// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        int size1=A.size(),size2=B.size();
       if(size1!=size2) return -1;
       vector<int>arr(256,0);
       for(int i=0;i<size1;i++)
       {
           arr[A[i]]++;
           arr[B[i]]--;
       }
       for(int i=0;i<256;i++)
       {
           if(arr[i]!=0)
           {
               return -1;
           }
       }
       int j=size2-1,c=0;
       for(int i=size1-1;i>=0;i--)
       {
           if(A[i]==B[j])
           {
               j--;
           }
           else
           {
               c++;
           }
       }
       return c;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends