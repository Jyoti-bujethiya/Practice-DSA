class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) { 

		if( k<= 1 ) return 0;  // if product is 1 or less then no element can be less, so return 0.

		int size = nums.size();    
		long prod = 1;  // keep track of product
		int ans = 0;  // keep track of final answer
		int left=0, right=0; // intially left and right to be zero, move right pointer to next location till product < k, once prod exceed, divide prod by left value and move left pointer towards right till product once again < k.

		while( right < size )
		{           
			prod *= nums[right];            // keep track of product with each new right .
			while( prod >= k)  // once product exceeds, keep dividing prod by left value and move left pointer towards right till product once again < k.
				prod /= nums[left++];

			ans += right - left + 1;  // final answer is to count of elements in that windows and add it to previously calculated sliding window ans
			//, +1 is to keep individual element as well.
			++right;            // if product < k, move towards right
		}
		return ans;
	}
};