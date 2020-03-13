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

char s[200010];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        int len=(int)strlen(s+1);
        int maxn=-1,prepos=0;
        for(int i=1;i<=len;i++){
            if(s[i]=='R'){
                maxn=max(maxn,i-prepos);
                prepos=i;
            }
        }
        maxn=max(maxn,len+1-prepos);
        printf("%d\n",maxn);
    }
}
