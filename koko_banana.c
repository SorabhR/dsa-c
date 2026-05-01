long long calculate_hours(int* piles, int n, int k) {
    long long total_hrs = 0;
    for (int i = 0; i < n; i++) {
        // Standard integer ceiling: (piles[i] + k - 1) / k
        total_hrs += (1LL * piles[i] + k - 1) / k;
    }
    return total_hrs;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = 0;
    
    // Find the max pile size to set the upper boundary
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > high) high = piles[i];
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // If Koko can finish at speed 'mid'
        if (calculate_hours(piles, pilesSize, mid) <= (long long)h) {
            result = mid;     // This speed works, but maybe a slower one does too?
            high = mid - 1;   // Try slower
        } else {
            low = mid + 1;    // Too slow, must eat faster
        }
    }
    return result;
}