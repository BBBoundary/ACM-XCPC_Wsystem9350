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
int a[105];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int minn=INF;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            minn=min(minn,a[i]);
        }
        for(int i=1;i<=n;i++) a[i]-=minn;
        int flag=1;
        for(int i=1;i<n;i++){
            if(abs(a[i]-a[i+1])%2==1){flag=0;break;}
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}
