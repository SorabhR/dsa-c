#include "stdint.h"

int uniquePaths(int m, int n) {
    if(m==1 || n==1)
        return 1;
    
    uint32_t grid[m][n];
    memset(grid,0,sizeof(grid));

    for(int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0){
                grid[i][j] = 1;
            }else{
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
    }
    return grid[m-1][n-1];
}