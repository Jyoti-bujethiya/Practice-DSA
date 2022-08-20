class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
         int max_reach = startFuel;   // max_reach stores the max distance we can reach with the fuel we have with us

    priority_queue<int> pq;  // stores the refuling capacity of every station we have encountered so far but have not used

    int cnt = 0;   // storres the number of stops we made at fuel stations for refuling
 
    int idx = 0;  // index of next station

    while(max_reach < target){
        
        // since max_reach < target, we need to refuel at some station
        // this step will store all the gas stations fuels which are withing range of max_reach
        // store all the stations we reached while moving towards destination
        while(idx < stations.size() && stations[idx][0] <= max_reach){
            pq.push(stations[idx][1]);
            idx++;
        }

        // max_reach < target and there is no station we can refuel at. hence we cannot reach
        if(pq.empty()){
            return -1;
        }

        // we can refuel
        max_reach += pq.top();
        pq.pop();
        cnt++;

    }

    return cnt;
    }
};