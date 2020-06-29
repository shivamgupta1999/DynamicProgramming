class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int range=startFuel;
        int stops = 0;
        stations.push_back(vector({target,0}));
        
        int i=0;
        
        while (i<stations.size()) {
            int tar = stations[i][0];
            int fuelplus = stations[i][1];
            if (range<tar) {
                while (!pq.empty()) {
                    range = range + pq.top();
                    pq.pop();
                    stops++;
                    if (range>=tar) break;
                }
                if (range<tar)
                    return -1;
            }
            pq.push(fuelplus);
            i++;
        }
        
        return stops;
    }
};