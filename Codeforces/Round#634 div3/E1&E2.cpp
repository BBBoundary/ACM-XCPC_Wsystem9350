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
int a[200010];
int sum[200010][205];

void init(){
    for(int i=0;i<205;i++) sum[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<205;j++) sum[i][j]=sum[i-1][j];
        sum[i][a[i]]++;
    }
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<int>pos[205];
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pos[a[i]].pb(i);
        }
        init();
        int ans=1;
        for(int i=1;i<=200;i++){
            int len=(int)pos[i].size();
            for(int j=len/2;j>=1;j--){
                int l=pos[i][j-1];
                int r=pos[i][len-j]-1;
                int cnt=2*j;
                int maxn=0;
                for(int k=1;k<=200;k++){
                    maxn=max(maxn,sum[r][k]-sum[l][k]);
                }
                ans=max(ans,maxn+cnt);
            }
        }
        printf("%d\n",ans);
    }
}
