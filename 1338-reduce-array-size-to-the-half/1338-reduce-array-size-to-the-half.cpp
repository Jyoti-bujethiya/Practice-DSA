class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map <int,int> mp;
        for(auto i:arr)
            mp[i]++;
        priority_queue <int> pq;
        for(auto i:mp){
            pq.push(i.second);
        }
        int ans=0,tmp=0;
        while(tmp < arr.size()/2 && !pq.empty()){
            tmp += pq.top();
            pq.pop();
            ans ++;
        }
        return ans;
    }
};