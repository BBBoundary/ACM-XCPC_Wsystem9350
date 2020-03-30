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

int n,k;
llu a[200010];
llu cnt[200010],sum[200010],bsum[200010];

int main(){
    scanf("%d%d",&n,&k);
    sum[0]=0;bsum[n+1]=0;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=n;i>=1;i--) bsum[i]=bsum[i+1]+a[i];
    cnt[1]=1;int flag=0;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) cnt[i]=cnt[i-1]+1;
        else cnt[i]=1;
        if(cnt[i]>=k){flag=1;break;}
    }
    if(flag) {printf("0\n");return 0;}
    llu minn=UINT64_MAX;
    for(int i=1;i<=n;i++){
        llu lef=i*a[i]-sum[i]-(i-k),rig=bsum[i]-(n-i+1)*a[i]-(n-i-k+1);
        if(i>=k) minn=min(minn,lef);
        if(n-i+1>=k) minn=min(minn,rig);
        minn=min(minn,lef+rig-k+1);
    }
    printf("%llu\n",minn);
}
