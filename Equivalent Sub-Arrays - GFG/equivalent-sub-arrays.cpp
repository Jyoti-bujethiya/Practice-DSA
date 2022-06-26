// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        //check number of distinct elements in arr[]
      int dist_elem=0;
      unordered_map<int,int>check;
      for(int i=0;i<n;i++){
          check[arr[i]]++;
      }
      dist_elem=check.size();
      check.clear();
      //now find the number of subarrays which has distinct elem same as
      //dist_elem
      int count=0;
     int i=0,j=0;
     int ans=0;
     while(j<n){
     if(check[arr[j]]==0)count++;
     check[arr[j]]++;
     //now if we encounter count==dist_elem
     while(count==dist_elem){
         ans+=n-j;//it includes current subarray + remaining elements 
         //subarrays in right side
        check[arr[i]]--;
        if(check[arr[i]]==0)count--;
        i++;
     }
     j++;
     }
    return ans;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends