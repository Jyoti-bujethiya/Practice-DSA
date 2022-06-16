class Solution {
public:
    string longestPalindrome(string str) {
          int n = str.size();
        
        int start_idx = 0;
        
        int end_idx = 0;
        
        for(int i = 0; i < n; i++)
        {
            // expand the substring around odd length substring
            
            int left = i;
            
            int right = i;
            
            while(left >= 0 && right < n)
            {
                if(str[left] == str[right])
                {
                    if(right - left + 1 > end_idx - start_idx + 1)
                    {
                        start_idx = left;
                
                        end_idx = right;
                    } 
                    
                    left--;
                    
                    right++;   
                }
                else
                {
                    break;
                }
            }
            
            // expnad the substring around even length substring
            
            left = i;
            
            right = i + 1;
            
            while(left >= 0 && right < n)
            {
                if(str[left] == str[right])
                {
                    if(right - left + 1 > end_idx - start_idx + 1)
                    {
                        start_idx = left;
                
                        end_idx = right;
                    } 
                    
                    left--;
                    
                    right++;   
                }
                else
                {
                    break;
                }
            }
        }
        
        return str.substr(start_idx, end_idx - start_idx + 1);
    }
};