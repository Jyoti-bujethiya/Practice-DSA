class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.",
                         "....","..",".---","-.-",".-..","--","-.",
                         "---",".--.","--.-",".-.","...","-","..-",
                         "...-",".--","-..-","-.--","--.."};
        unordered_set<string> set;
        
        for(auto &w :words)
        {
            string s= "";
            for(auto &ch:w)
            {
                s+=v[ch - 'a']; 
            }
            set.insert(s);
        }
        return set.size();
    }
};