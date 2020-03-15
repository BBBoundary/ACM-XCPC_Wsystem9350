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

ll u,v;

int main(){
    scanf("%lld%lld",&u,&v);
    if(u>v||(u&1)!=(v&1)){printf("-1\n");return 0;}
    if(u==v){
        if(u) printf("1\n");
        printf("%lld\n",u);
        return 0;
    }
    ll x=(v-u)/2;
    if(((u^x)+x)==v){
        printf("2\n%lld %lld\n",(u^x),x);
    }
    else{
        printf("3\n%lld %lld %lld\n",u,x,x);
    }
}
