class Solution {
    private int find(int ldr[],int node){
        if(ldr[node]!=node){
   ldr[node] = find(ldr,ldr[node]);
}
        
        return ldr[node];
    }
    private void join(int ldr[],int lt,int rt){
        ldr[find(ldr,rt)]=ldr[find(ldr,lt)];
        
    } 
    public int findCircleNum(int[][] G) {
        int N=G.length;
        int ldr[]=new int[N+1];
        for(int c=1;c<=N;c++) ldr[c]=c;
        for(int city=0;city<N;city++){
            for(int oc=0;oc<N;oc++){
                if(city==oc) continue;
                if(G[city][oc]==1){
                    join(ldr,city+1,oc+1);
                }
            }
        }
        Set<Integer> st=new HashSet<>();
        for(int i=1;i<=N;i++){
st.add(find(ldr,i));
        }
        return st.size();
            }
            
}
