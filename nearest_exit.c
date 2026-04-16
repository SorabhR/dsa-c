int isExit(int nRows, int nCols, int* entrance,int* current_point){
    if((current_point[0] == 0 || current_point[1] == 0 || current_point[0] == nRows-1 || current_point[1] == nCols - 1) && !(current_point[0] == entrance[0] && current_point[1] == entrance[1])){
        return 1;
    }
    return 0;
}

int nearestExit(char** maze, int mazeSize, int* mazeColSize, int* entrance, int entranceSize) {
    int nCols = mazeColSize[0];

    int queue[mazeSize*nCols][2];
    bool visited[mazeSize][nCols];
    memset(visited, 0, sizeof(visited));

    int head = 0;
    int tail = 0;
    int count = 0;

    memcpy(queue[tail++], entrance, 2 * sizeof(int));
    visited[entrance[0]][entrance[1]] = 1;
    int current_point[2] = {0};
    int size = 0;

    while(head < tail){
        size = tail - head;
        for(int i = 0;i < size;i++){
            memcpy(current_point, queue[head++], 2 * sizeof(int));
            if(isExit(mazeSize,nCols,entrance,current_point)){
                return count;
            }
            if(current_point[0] > 0 && !visited[current_point[0]-1][current_point[1]] && maze[current_point[0]-1][current_point[1]] == '.'){
                queue[tail][0] = current_point[0]-1;
                queue[tail][1] = current_point[1];
                visited[queue[tail][0]][queue[tail][1]] = 1;
                tail++;
            }
            if(current_point[0] < (mazeSize-1) && !visited[current_point[0]+1][current_point[1]] &&  maze[current_point[0]+1][current_point[1]] == '.'){
                queue[tail][0] = current_point[0]+1;
                queue[tail][1] = current_point[1];
                visited[queue[tail][0]][queue[tail][1]] = 1;
                tail++;
            }
            if(current_point[1] > 0 && !visited[current_point[0]][current_point[1] - 1] && maze[current_point[0]][current_point[1]-1] == '.'){
                queue[tail][0] = current_point[0];
                queue[tail][1] = current_point[1] - 1;
                visited[queue[tail][0]][queue[tail][1]] = 1;
                tail++;
            }
            if(current_point[1] < (nCols-1) && !visited[current_point[0]][current_point[1] + 1] && maze[current_point[0]][current_point[1]+1] == '.'){
                queue[tail][0] = current_point[0];
                queue[tail][1] = current_point[1] + 1;
                visited[queue[tail][0]][queue[tail][1]] = 1;
                tail++;
            }
        }
        count++;
    }
    return -1;
}