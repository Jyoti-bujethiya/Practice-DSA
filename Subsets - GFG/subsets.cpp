// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void sol(vector<vector<int> >&v,vector<int>& vec,vector<int>& A ,int i)
    {
        if(i==A.size())
        {
            v.push_back(vec);
            return;
        }
        sol(v,vec,A,i+1);
        vec.push_back(A[i]);
        
        
        sol(v,vec,A,i+1);
        vec.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int> >v;
        vector<int>vec;
        sol(v,vec,A,0);
        sort(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends