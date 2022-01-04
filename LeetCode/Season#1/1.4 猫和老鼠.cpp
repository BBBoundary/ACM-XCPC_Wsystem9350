class Solution {
public:
    int n;  //总结点数
    int memo[55][55][110];  //记忆DFS，(i,j,k):(猫位置，鼠位置，比赛轮数)
    int dfs(int CatPos,int MousePos,vector<vector<int>>& graph,int turn){
        //猫位置、鼠位置、图、轮数
        if(memo[CatPos][MousePos][turn]!=-1)  //该情况已被遍历，直接返回记忆结果
            return memo[CatPos][MousePos][turn];
        if(turn>=2*n)   //轮数>=2n时必定平局
            return memo[CatPos][MousePos][turn]=0;
        if(MousePos==0) //老鼠赢
            return memo[CatPos][MousePos][turn]=1;
        if(CatPos==MousePos) //猫赢
            return memo[CatPos][MousePos][turn]=2;
        if(turn%2==0){  //比赛还在进行，老鼠的回合
            int ans=2;  //最坏的情况下是猫赢
            for(int tmpMove:graph[MousePos]){
                int tmpans=dfs(CatPos,tmpMove,graph,turn+1);
                if(tmpans==1){ //有可以赢的路，直接退出
                    return memo[CatPos][MousePos][turn]=1;
                }
                else if(tmpans==0) ans=0; //可以优化成平局
            }
            return memo[CatPos][MousePos][turn]=ans;
        }else{          //比赛还在进行，猫的回合
            int ans=1;  //最坏的情况下是老鼠赢
            for(int tmpMove:graph[CatPos]){ 
                if(tmpMove==0) continue; //猫不能进入0点
                int tmpans=dfs(tmpMove,MousePos,graph,turn+1); 
                if(tmpans==2)            //有可以让猫赢的方法，直接退出
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
                //设置初始memo值，-1表示该情况还未被遍历过
        return dfs(2,1,graph,0);
    }
};
