class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0, totalCost=0;
        int n = gas.size();

        int start=0, curr_gas=0;
        for(int i=0; i<n; i++){

            totalGas += gas[i];
            totalCost += cost[i];

            curr_gas += (gas[i] - cost[i]);
            if(curr_gas < 0){
                start = i+1;
                curr_gas = 0;
            }
        }
        
        return (totalGas < totalCost) ? -1 : start;
    }
};