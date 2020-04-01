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
typedef unsigned long long llu;
typedef pair<int,int> pii;

int n,k;
char s[200010];
int f[200010],FIND[200010],fin[200010];
int sum[200010],cnt[200010][30];

void init(){
    for(int i=1;i<=n;i++) for(int j=0;j<30;j++) cnt[i][j]=0;
    for(int i=1;i<=n;i++) {f[i]=i;sum[i]=0;}
}

int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        init();
        for(int i=1,j=n;i<=j;i++,j--) f[j]=i;
        for(int i=1;i<=k;i++){
            for(int j=i+k;j<=n;j+=k){
                int a=find(j),b=find(i);
                f[a]=b;
            }
        }
        for(int i=1;i<=n;i++) FIND[i]=find(i);
        int tot=0;
        for(int i=1;i<=n;i++){
            if(FIND[i]==i){
                fin[i]=++tot;
            }
        }
        for(int i=1;i<=n;i++){
            sum[fin[FIND[i]]]++;
            cnt[fin[FIND[i]]][s[i]-'a']++;
        }
        int ans=0;
        for(int i=1;i<=tot;i++){
            int maxn=-1;
            for(int j=0;j<26;j++) maxn=max(maxn,cnt[i][j]);
            ans+=sum[i]-maxn;
            //            printf("%d %d\n",i,ans);
        }
        printf("%d\n",ans);
    }
}
