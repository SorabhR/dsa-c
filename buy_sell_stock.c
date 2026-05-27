int maxProfit(int* prices, int pricesSize, int fee) {

    int hold[pricesSize];
    int cash[pricesSize];

    hold[0] = -prices[0];
    cash[0] = 0;

    for(int i = 1; i < pricesSize; i++) {

        hold[i] = fmax(
            hold[i-1],
            cash[i-1] - prices[i]
        );

        cash[i] = fmax(
            cash[i-1],
            hold[i-1] + prices[i] - fee
        );
    }

    return cash[pricesSize - 1];
}