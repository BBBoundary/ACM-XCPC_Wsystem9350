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

int n;
ll a[200010],b[200010];
ll c[200010];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++) c[i]=a[i]-b[i];
    sort(c+1,c+n+1,less<ll>());
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(c[i]<0) continue;
        int pos=(int)(upper_bound(c+1,c+n+1,-c[i])-(c));
        //        printf("%d,pos=%d\n",c[i],pos);
        if(pos<i){
            ans+=i-pos;
        }
    }
    printf("%lld\n",ans);
}
