int minm(int a,int b,int c){
    int min = 0;
    min = a > b ? b : a;
    min = min > c ? c : min;
    return min;
}

int minDistance(char* word1, char* word2) {
    int m = strlen(word1);
    int n = strlen(word2);

    int grid[m+1][n+1];
    for(int i = 0; i <= m; i++) {
        grid[i][0] = i;
    }

    // first row
    for(int j = 0; j <= n; j++) {
        grid[0][j] = j;
    }

    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=n;j++){
            if(word1[i-1] == word2[j-1]){
                grid[i][j] = grid[i-1][j-1];
            }else{
                grid[i][j] = 1 + min(grid[i-1][j-1],grid[i-1][j],grid[i][j-1]);
            }
        }
    }
    return grid[m][n];
}