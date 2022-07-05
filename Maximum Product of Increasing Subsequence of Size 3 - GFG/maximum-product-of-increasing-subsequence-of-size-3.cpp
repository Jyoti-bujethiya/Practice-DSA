// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 



 // } Driver Code Ends


class Solution{
  public:
    vector<int> maxProductSubsequence(int *arr , int n) 
    { 
        // Complete the function
        vector<int> ans({-1}) ;
        if(n < 3)
            return ans ;
        
        long long p = -1 ;
        multiset<int> sl ;
        
        vector<int> me(n) ;
        me[n-1]=arr[n-1] ;
        for(int i=n-2 ; i>=0 ; i--)
            me[i] = max(me[i+1],arr[i]) ;
        
        for(int i=1 ;i<n-1 ; i++){
            sl.insert(arr[i-1]) ;
            
            auto litr = sl.lower_bound(arr[i]) ;
            if(litr == sl.begin())
                continue ;
            litr = prev(litr) ;
                
            if(me[i+1] > arr[i] && p < 1LL*(*litr) * (arr[i]) * (me[i+1]) ){
                ans = vector<int>({*litr, arr[i], me[i+1]}) ;
                p = 1LL* (*litr) * (arr[i]) * (me[i+1]) ;
            }
            
        }
        return ans ;
    } 

};

// { Driver Code Starts.
// Driver Program 
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; ++i)
	        cin>>arr[i];
	    
	    vector<int> res;
	    Solution obj;
	    res = obj.maxProductSubsequence(arr, num);
	    
	    if(res[0] == -1)
	        cout<<"Not Present\n";
	    else{
    	    for(int i = 0; i<3; ++i)
    	        cout<<res[i]<<" ";
    	    cout<<"\n";
	    }
	    
	}
} 
  // } Driver Code Ends