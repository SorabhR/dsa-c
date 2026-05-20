int minCostClimbingStairs(int* cost, int costSize) {
    int total_cost = 0; 
    int cost_sum[costSize];
    memset(cost_sum,0,costSize);
    cost_sum[0] = cost[0];
    cost_sum[1] = cost[1];
    
    for(int i=2;i<costSize;i++){
        total_cost = cost_sum[i-1] > cost_sum[i-2] ? cost_sum[i-2] : cost_sum[i-1];
        cost_sum[i] = total_cost + cost[i];
    }

    total_cost = cost_sum[costSize-1] > cost_sum[costSize-2] ? cost_sum[costSize-2] : cost_sum[costSize-1];
    return total_cost;
}