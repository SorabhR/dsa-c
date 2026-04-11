//rooms[row][col]
//roomsize is number of rooms
//*roomColSize is number of keys in every room

void dfs(int** rooms, int* count, int* roomsColSize,bool* visited,int room){
    if(visited[room])
        return;
    visited[room] = 1;
    (*count)++;
    for(int i = 0;i<roomsColSize[room];i++)
        dfs(rooms,count,roomsColSize,visited,rooms[room][i]);
}

bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize) {
    bool visited[roomsSize];
    memset(visited,0,roomsSize);

    int count = 0;

    dfs(rooms,&count,roomsColSize,visited,0);
    if(count == roomsSize)
        return true;
    else
        return false;

}