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
using namespace std;
typedef long long ll;

int n,h,l,r;
ll a[2020];
ll f[2020][2020];

ll judge(ll x){
    x=(x+h)%h;
    if(x>=l&&x<=r) return 1;
    return 0;
}

int main(){
    scanf("%d%d%d%d",&n,&h,&l,&r);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<h;j++) f[i][j]=-INF;
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<h;j++){
            f[i][(j+a[i])%h]=max(f[i-1][j]+judge(j+a[i]),f[i][(j+a[i])%h]);
        }
        for(int j=0;j<h;j++){
            f[i][(j+a[i]-1+h)%h]=max(f[i-1][j]+judge(j+a[i]-1),f[i][(j+a[i]-1+h)%h]);
        }
    }
    ll ans=0;
    for(int i=0;i<h;i++) ans=max(ans,f[n][i]);
    printf("%lld\n",ans);
}
