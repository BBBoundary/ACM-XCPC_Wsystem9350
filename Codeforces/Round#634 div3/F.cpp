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
//typedef pair<int,int> pii;

#define rep(i,n) for(int i=0;i<n;i++)
#define pr pair<int,int>

const int N=2e6+5;
char ch;
int ans_a,ans_b,idx,n,m;
int vis[N],b[N],a[N],dfn[N],inque[N];
vector<int> c[N];
//b数组表示连出，c表示连入

void fill_(int p) {
    if(vis[p]) return ;
    vis[p]=1;
    fill_(b[p]);
    for(int v:c[p]) fill_(v);
}

void bfs(int p,int mx) {
    queue<pr> que;
    que.push(pr(0,p));
    inque[p]=1;
    vector<int> ans(mx);
    while(!que.empty()) {
        pr t=que.front();que.pop();
        int u=t.second,cnt=t.first;
        if(!a[u]) ans[cnt%mx]=1;
        for(int v:c[u]) {
            if(!inque[v]) que.push(pr(cnt+1,v));
            inque[v]=1;
        }
    }
    ans_a+=mx;
    rep(i,mx) if(ans[i]) ans_b++;
}

void dfs(int p) {
    if(dfn[p]) {
        bfs(p,idx+1-dfn[p]);
        return ;
    }
    dfn[p]=++idx,dfs(b[p]);
}


void solve() {
    cin>>n>>m;
    idx=ans_a=ans_b=0;
    rep(i,n*m) vis[i]=dfn[i]=inque[i]=0,c[i].clear();
    rep(i,n) rep(j,m) {
        int p=i*m+j;
        cin>>ch;
        a[p]=ch-'0';
    }
    rep(i,n) rep(j,m) {
        int p=i*m+j;
        cin>>ch;
        switch(ch) {
            case 'L':b[p]=p-1;c[p-1].push_back(p);break;
            case 'R':b[p]=p+1;c[p+1].push_back(p);break;
            case 'U':b[p]=p-m;c[p-m].push_back(p);break;
            case 'D':b[p]=p+m;c[p+m].push_back(p);
        }
    }
    rep(i,n) rep(j,m) {
        int p=i*m+j;
        if(!vis[p]) dfs(p);
        fill_(p);
    }
    cout<<ans_a<<' '<<ans_b<<'\n';
}

int main() {
    int T;cin>>T;
    while(T--) solve();
}


