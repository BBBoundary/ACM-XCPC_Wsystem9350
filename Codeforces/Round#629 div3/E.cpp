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
#include<functional>
#define INF 0x3f3f3f3f
#define pb push_back
using namespace std;
typedef long long ll;

int n,m;
vector<int>G[200010];
int bit[30],dep[200010];
int f[200010][30];
int q[200010];

void init(){
    bit[0]=1;
    for(int i=1;i<30;i++) bit[i]=bit[i-1]*2;
}

void Treedfs(int now,int par){
    dep[now]=dep[par]+1;
    f[now][0]=par;
    for(int i=1;i<30;i++) f[now][i]=f[f[now][i-1]][i-1];
    for(auto i=0;i<G[now].size();i++){
        int v=G[now][i];
        if(v==par) continue;
        Treedfs(v,now);
    }
}

int lca(int a,int b){
    if(dep[a]<dep[b]) swap(a,b);
    int dif=dep[a]-dep[b];
    for(int i=29;i>=0;i--){
        if(dif>=bit[i]) {dif-=bit[i];a=f[a][i];}
    }
    for(int i=29;i>=0;i--){
        if(dep[a]>=bit[i]&&f[a][i]!=f[b][i]){
            a=f[a][i];b=f[b][i];
        }
    }
    return f[a][0];
}

int main(){
    init();
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        G[a].pb(b); G[b].pb(a);
    }
    Treedfs(1,0);
    while(m--){
        int num;scanf("%d",&num);
        for(int i=1;i<=num;i++) scanf("%d",&q[i]);
        int las=q[1],maxn=dep[q[1]];
        for(int i=2;i<=num;i++){
            if(dep[q[i]]>maxn){maxn=dep[q[i]];las=q[i];}
        }
        int flag=0;
        for(int i=1;i<=num;i++){
            if(q[i]==las) continue;
            int fa=lca(q[i],las);
            if(abs(dep[fa]-dep[q[i]])>1){
                flag=1;break;
            }
        }
        if(!flag) printf("YES\n");
        else printf("NO\n");
    }
}
