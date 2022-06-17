// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        string ans;
       for(int i=0;i<index[0];i++)
       ans+=S[i];
       for(int i=0;i<Q;i++)
       {
           int count=0,k=0;
           int x=(index[i]+sources[i].length());
           for(int j=index[i];j<x;j++)
           {
               if(S[j]==sources[i][k])
               count++;
               k++;
           }
           if(count==sources[i].length())
           ans+=targets[i];
           else
           {
               //cout<<"hi";
               for(int j=index[i];j<x;j++)
               ans+=S[j];
           }
           if(i==Q-1)
           {
               for(int h=index[i]+sources[i].length();h<S.length();h++)
               ans+=S[h];
           }
           else
           {
               //cout<<"ej";
               for(int h=index[i]+sources[i].length();h<index[i+1];h++)
               ans+=S[h];
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
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends