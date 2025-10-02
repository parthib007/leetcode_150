class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int start = 0, currentTank = 0; // starting sttion and gas balance
        for(int i=0;i<gas.size();i++){
            totalGas += gas[i];
            totalCost += cost[i];
            int gasNet = gas[i] - cost[i];
            currentTank += gasNet;
            // if current Tank becomes negative then update the start and reset the current tank
            if(currentTank < 0){
                start = i+1;
                currentTank = 0;
            }
        }
        // if total cost is more than total gas, then not possible
        return (totalGas >= totalCost) ? start:-1;
    }
};
