class Solution {
public:
const int d[5]={0,1,0,-1,0};
    bool dfs(int r,int c,int row,int col,vector<vector<char>>& board,string word,int idx){
        if(idx==word.length()) return true;
        char bkup=board[row][col];
        board[row][col]='.';
        for(int i=0;i<4;i++){
            int ar=row+d[i],ac=col+d[i+1];
            if(ar>=0 && ar<r && ac>=0 && ac<c && board[ar][ac]==word[idx]){
                bool found=dfs(r,c,ar,ac,board,word,idx+1);
                if(found) return true;
            }
        }
        board[row][col]=bkup;
return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                if(board[row][col]==word[0]){
                    bool found=dfs(r,c,row,col,board,word,1);
                    if(found) return true;
                }
            }
        }
        return false;
    }
};
