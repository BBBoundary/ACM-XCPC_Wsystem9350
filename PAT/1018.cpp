#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int cmax,n,sp,m;
int dis[505],brin[505];
int graph[505][505];
vector<vector<int>>pre(505);
vector<int>path,tmppath;
int minneed=INF,minback=INF;

void init(){
    for(int i=0;i<505;i++) mem(graph[i],INF);
    mem(dis,INF);dis[0]=0;
}

void dijk(){
    int vis[505];mem(vis,0);
    for(int t=0;t<=n;t++){
        int minn=INF,idx=0;
        for(int i=0;i<=n;i++){
            if(!vis[i]&&dis[i]<minn){idx=i;minn=dis[i];}
        }
        vis[idx]=1;
        if(minn==INF) return;
        for(int i=0;i<=n;i++){
            if(vis[i]||graph[idx][i]==INF) continue;
            if(dis[idx]+graph[idx][i]<dis[i]){
                dis[i]=dis[idx]+graph[idx][i];
                pre[i].clear();
                pre[i].push_back(idx);
            }
            else if(dis[idx]+graph[idx][i]==dis[i]){
                pre[i].push_back(idx);
            }
        }
    }
}

void dfs(int sp){
    printf("dfs:%d\n",sp);
    tmppath.push_back(sp);
    if(sp==0){
        int need=0,back=0;
        for(int i=tmppath.size()-1;i>=0;i--){
            int id=tmppath[i];
            if(brin[id]>0) back+=brin[id];
            else{
                if(back>=-1*brin[id]) back-=-1*brin[id];
                else{
                    need+=-1*brin[id]-back;
                    back=0;
                }
            }
        }
        if(need<minneed){
            minneed=need;minback=back;
            path=tmppath;
        }
        else if(need==minneed&&back<minback){
            minback=back;
            path=tmppath;
        }
    }
    else{
        for(int i=0;i<pre[sp].size();i++){
            dfs(pre[sp][i]);
            tmppath.pop_back();
        }
    }
}

int main(){
    scanf("%d%d%d%d",&cmax,&n,&sp,&m);
    for(int i=1;i<=n;i++){scanf("%d",&brin[i]);brin[i]=brin[i]-cmax/2;}
    init();
    int a,b,c;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        graph[a][b]=graph[b][a]=min(graph[a][b],c);
    }
    dijk();
    dfs(sp);
    printf("%d 0",minneed);
    for(int i=path.size()-2;i>=0;i--) printf("->%d",path[i]);
    printf(" %d",minback);
}
