int* countBits(int n, int* returnSize) {
    int* cB = (int*)calloc((n+1),sizeof(int));
    //memset(cB,0,sizeof(cB));
    
    int offset = 1;
    for(int i = 1;i<=n;i++){
        if(offset*2 == i)
            offset = i;
        cB[i] = 1 + cB[i-offset];
    }

    *returnSize = n+1;
    return cB;
}