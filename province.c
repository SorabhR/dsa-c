//isConnected is nxn
//isCOnnectedSize is cities
//isConnectedColSize is number of cols in each row

int dfs(int** isConnected, int* isConnectedColSize,bool* visitable,int city){
    if(visitable[city])
        return 0;
    else{
        visitable[city] = 1;
        for(int i = 0;i<isConnectedColSize[city];i++){
            if(i!=city){
                if(isConnected[city][i] && visitable[i] == 0){
                    dfs(isConnected,isConnectedColSize,visitable,i);
                }
            }
        }
        return 1;
    }
}


int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    bool visitable[isConnectedSize];
    memset(visitable,0,isConnectedSize);

    int count = 0;
    for(int i = 0;i<isConnectedSize;i++)
        count += dfs(isConnected,isConnectedColSize,visitable,i);

    return count;
}