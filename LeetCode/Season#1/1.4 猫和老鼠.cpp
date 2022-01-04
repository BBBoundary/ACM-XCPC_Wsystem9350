class Solution {
public:
    int n;
    int memo[55][55][110];
    int dfs(int CatPos,int MousePos,vector<vector<int>>& graph,int turn){
        if(memo[CatPos][MousePos][turn]!=-1)
            return memo[CatPos][MousePos][turn];
        if(turn>=2*n)
            return memo[CatPos][MousePos][turn]=0;
        if(MousePos==0)
            return memo[CatPos][MousePos][turn]=1;
        if(CatPos==MousePos)
            return memo[CatPos][MousePos][turn]=2;
        if(turn%2==0){
            //printf("%d:%d %d %d\n",turn,CatPos,MousePos,memo[2][1][0]);
            int ans=2;
            for(int tmpMove:graph[MousePos]){
                int tmpans=dfs(CatPos,tmpMove,graph,turn+1);
                if(tmpans==1){
                    return memo[CatPos][MousePos][turn]=1;
                }
                else if(tmpans==0) ans=0;
            }
            return memo[CatPos][MousePos][turn]=ans;
        }else{
            //printf("%d:%d %d %d\n",turn,CatPos,MousePos,memo[2][1][0]);
            int ans=1;
            for(int tmpMove:graph[CatPos]){
                if(tmpMove==0) continue;
                int tmpans=dfs(tmpMove,MousePos,graph,turn+1);
                if(tmpans==2)
                    return memo[CatPos][MousePos][turn]=2;
                else if(tmpans==0) ans=0;
            }
            return memo[CatPos][MousePos][turn]=ans;
        }
    }
    int catMouseGame(vector<vector<int>>& graph) {
        n=graph.size();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                memset(memo[i][j],-1,sizeof(memo[i][j]));
        return dfs(2,1,graph,0);
    }
};
