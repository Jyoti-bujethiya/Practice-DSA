class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> mp;
        int l  = nums.size();
        int maxSum=0, currSum=0;
        int i=0,j=0;
        while(j<l)
        {
            if(!mp[nums[j]]) //Current item doesn't exist, we can add it to window.
            {
                currSum+=nums[j];
                mp[nums[j]]++; //Inserting value to map
            }
            else //Current item doesn;t exist, we need to delete the previous elements(from pointer i) till we can add this current element to the window.
            {
                while(i<j and mp[nums[j]])
                {
                    mp[nums[i]]--;  //Removing value from map
                    currSum-=nums[i];
                    i++;
                }
                mp[nums[j]]++;  //Inserting value to map
                currSum+=nums[j];
            }
			//Main condition check (to store the largest sum of any window possible)
            maxSum=currSum>maxSum?currSum:maxSum;
            j++;
        }
        return maxSum; 
    }
};