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

int n;
pair<int,int>p[100010];
int d[100010];
int node=0;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++){
        scanf("%d%d",&p[i].first,&p[i].second);
        d[p[i].first]++;d[p[i].second]++;
        if(d[p[i].first]>=3) node=p[i].first;
        if(d[p[i].second]>=3) node=p[i].second;
    }
    if(!node){
        for(int i=0;i<n-1;i++) printf("%d\n",i);
    }
    else{
        int otn=3,nown=0;
        for(int i=1;i<=n-1;i++){
            if(p[i].first!=node&&p[i].second!=node){
                printf("%d\n",otn++);
            }
            else{
                if(nown<=2) printf("%d\n",nown++);
                else printf("%d\n",otn++);
            }
        }
    }
}
