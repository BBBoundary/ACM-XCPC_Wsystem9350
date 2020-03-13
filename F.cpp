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

int n;
int a[200010];
vector<int>e[200010];
int fir[200010],ans[200010];

int dfs(int now,int past){
    int tmpsum=0;
    for(auto i=0;i<e[now].size();i++){
        if(e[now][i]==past) continue;
        fir[e[now][i]]=dfs(e[now][i],now);
        tmpsum+=max(fir[e[now][i]],0);
    }
    return tmpsum+a[now];
}

void dp(int now,int past){
    ans[now]=max(ans[past],0)+fir[now];
    for(auto i=0;i<e[now].size();i++){
        if(e[now][i]==past) continue;
        ans[now]-=max(fir[e[now][i]],0);
        dp(e[now][i],now);
        ans[now]+=max(fir[e[now][i]],0);
    }
}

int main(){
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=a[i]?1:-1;
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        e[u].pb(v);
        e[v].pb(u);
    }
    fir[1]=dfs(1,0);
    dp(1,0);
    for(int i=1;i<=n;i++) {printf("%d",ans[i]);if(i!=n) printf(" ");}
}
