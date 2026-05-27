int numTilings(int n) {
    long long combo[n > 2 ? (n+1):3];
    combo[0] = 1;
    combo[1] = 1;
    combo[2] = 2;

    for(int i = 3;i<=n;i++){
        combo[i] = 2*combo[i-1] + combo[i-3];
        combo[i] = combo[i] % (long long)(pow(10,9) + 7);
    }

    return combo[n];
}