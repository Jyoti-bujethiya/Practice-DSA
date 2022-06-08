// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        // Your code here
            priority_queue<int , vector<int>, greater<int>> pq;// min heap priority queue
        for(int i = 0; i <min(n,k+1); i++)
        {
           pq.push(arr[i]);// pushing first k elements in priority queue
       }
       vector<int> ans; 
       for(int i = k + 1; i < n; i++){
           ans.push_back(pq.top());// push the minimum of all k elements in ans
           //then pop the minmimum element and push the ith element
           pq.pop();
           pq.push(arr[i]);
       }
       //push all elements in ans vector till priority queue size is>0;
       while(pq.empty() == false){
           ans.push_back(pq.top());
           pq.pop();
       }
       
       return ans;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends