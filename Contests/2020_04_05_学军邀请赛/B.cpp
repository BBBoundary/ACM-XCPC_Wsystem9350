#include<cstdio>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<cstring>
#include<cmath>
#include<limits>
#define INF 0x3f3f3f3f
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int,int> pii;

int n;
int a[50010];
vector<int>G[50010];
int dx[50010],dy[50010];

int dfs(int now,int pre,int* d){
    int res=now;
    for(int i=0;i<G[now].size();i++){
        int nxt=G[now][i];
        if(nxt==pre)continue;
        d[nxt]=d[now]+1;
        int tmp=dfs(nxt,now,d);
        if(d[tmp]>d[res]) res=tmp;
    }
    return res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int tx,ty;
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&tx,&ty);
        G[tx].pb(ty);G[ty].pb(tx);
    }
    int x=dfs(1,0,dy);
    int y=dfs(x,0,dx);
    fill(dy,dy+50010,0);dfs(y,0,dy);
    int ans=-1;
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]*max(dx[i],dy[i]));
    }
    printf("%d\n",ans);
}
