int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    //run through grid get all fresh oranges 
    //get all stale orange and add then to queue
    //whenever you add fresh to queue increment counter and check at end

    int count = 0;
    int fresh_fruit = 0;
    int rotten_count = 0;
    int nCols = gridColSize[0];

    int head,tail = 0;
    int rotten_queue[gridSize*nCols][2];
    memset(rotten_queue,0,sizeof(rotten_queue));

    bool visited[gridSize][nCols];
    memset(visited,0,sizeof(visited));

    for(int i = 0;i<gridSize;i++){
        for(int j = 0;j<nCols;j++){
            if(grid[i][j] == 2){
                rotten_queue[tail][0] = i;
                rotten_queue[tail++][1] = j;
                visited[i][j] = 1;
            }
            else if(grid[i][j] == 1){
                fresh_fruit++;
            }
            else{
                visited[i][j] = 1;
            }
        }
    }

    if(fresh_fruit == 0)
        return 0;
    
    int size = 0;
    int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    int cp[2] = {0};

    while(head<tail){
        size = tail - head;
        for(int i = 0;i<size;i++){
            memcpy(cp,rotten_queue[head++],sizeof(cp));
            for(int j = 0;j<4;j++){
                int r = cp[0] + dir[j][0];
                int c = cp[1] + dir[j][1];

                if(r>=0 && r<gridSize && c>=0 && c<nCols && !visited[r][c] && grid[r][c] == 1){
                    visited[r][c] = 1;
                    rotten_queue[tail][0] = r;
                    rotten_queue[tail++][1] = c;
                    rotten_count++;
                }
            }
        }
        count++;
    }
    
    if(fresh_fruit == rotten_count)
        return count-1;
    else
        return -1;
}