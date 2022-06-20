class Solution {
public:
    vector<vector<int>> answer;
    
    void backtrack(vector<int>& nums, int n, vector<int>& temp){
        if(n==nums.size()){
            answer.push_back(temp);
            return;
        }
        backtrack(nums,n+1,temp);
        temp.push_back(nums[n]);
        backtrack(nums,n+1,temp);
		temp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums,0,temp);
        return answer;
    }
};