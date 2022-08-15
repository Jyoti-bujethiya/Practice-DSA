
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            string str = "";
            str += s[i];
            int sum1 = mp.at(s[i]);
            
            int x = i;
            
            while(i > 0 && mp.at(s[i-1]) < mp.at(s[i])) {
                str += s[i-1];
                
                sum1 -= mp.at(s[i-1]);
                
                i--;
            }
            
            
            sum += sum1;
        }
        
        return sum;
    }
};