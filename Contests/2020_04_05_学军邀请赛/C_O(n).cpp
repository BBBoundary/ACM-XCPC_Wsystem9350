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

ll n;
ll h[100010];

int lowbit(int x){
    return x&(-x);
}

void init(){
    for(int i=1;i<100010;i++){
        if(i%2==1) h[i]=1;
        else h[i]=lowbit(i);
    }
}

int solve(int x){
    int ans=0;
    for(int i=1;i<=x;i++){
        if(x%i==0) ans+=h[i];
    }
    return ans;
}

int main(){
    scanf("%lld",&n);
    init();
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=solve(i);
    }
    printf("%d\n",ans);
}
