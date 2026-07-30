class Solution {
    public int orangesRotting(int[][] grid) {
    int r = grid.length;
    int c= grid[0].length;
    int o = 0,days = 0;
    Queue<int[]> q = new LinkedList<>();
    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            if(grid[i][j] == 2){
                q.add(new int[]{i,j,0});
            } 
            if(grid[i][j] != 0){
                o++;
            }
        }
    }
    if(o == 0) return 0;
    int d[] = {0,1,0,-1,0};
    while(!q.isEmpty()){
        int cell[] =q.poll();
        o--;
        int row = cell[0],col = cell[1],dy = cell[2];
        days = dy;
        for(int i  =0;i<4;i++){
            int ar = row+d[i],ac = col + d[i+1];
            if(ar>=0 && ar<r && ac>= 0 && ac<c && grid[ar][ac] == 1){
                q.add(new int[]{ar,ac,dy+1});
                grid[ar][ac]= 2;
            }
        }
    }
    return o == 0 ?days : -1;
    }
}
