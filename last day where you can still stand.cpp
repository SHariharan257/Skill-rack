class Solution{
    vector<int> parent,size;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
public:
    int latestDayToCross(int row,int col,vector<vector<int>>&cells){
        int total=row*col;
        int top=total;
        int bottom=total+1;
        parent.resize(total+2);
        size.assign(total+2,1);
        iota(parent.begin(),parent.end(),0);
        vector<vector<int>> grid(row,vector<int>(col,0));
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int day=total-1;day>=0;day--){
            int r=cells[day][0]-1;
            int c=cells[day][1]-1;
            grid[r][c]=1;
            int node=r*col+c;
            if(r==0) unite(node,top);
            if(r==row-1) unite(node,bottom);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<row&&nc>=0&&nc<col&&grid[nr][nc]){
                    unite(node,nr*col+nc);
                }
            }
            if(find(top)==find(bottom)) return day;
        }
        return 0;
    }
};
