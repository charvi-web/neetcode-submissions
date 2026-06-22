class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int earning = 0;
        int spending = 0;
        for (int i = 0; i < gas.size(); i++) {
            earning += gas[i];
            spending += cost[i];
        }
        if (earning < spending) return -1;
        int result = 0;
        int s = 0;
        for (int i = 0; i < gas.size(); i++) {
            s += (gas[i] - cost[i]);
            if (s < 0) {
                s = 0;
                result = i + 1;
            }
        }
        return result;
    }
};
