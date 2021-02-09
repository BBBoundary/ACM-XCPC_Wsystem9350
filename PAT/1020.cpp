#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n;
int posord[35],inord[35];
int lch[35],rch[35];

void init(){
    for(int i=0;i<35;i++){lch[i]=rch[i]=0;}
}

int build(int l1,int r1,int l2,int r2){
    if(l1>r1) return 0;
    if(l1==r1) return posord[l1];
    int root=posord[r1];
    int p=l1;
    while(inord[p]!=root) p++;
    int cnt=p-l2;
    lch[root]=build(l1,l1+cnt-1,l2,p-1);
    rch[root]=build(l1+cnt,r1-1,p+1,r2);
    return root;
}

void bfs(int root){
    queue<int>que;que.push(root);
    int cnt=0;
    while(!que.empty()){
        int cur=que.front();que.pop();
        if(lch[cur]!=0) que.push(lch[cur]);
        if(rch[cur]!=0) que.push(rch[cur]);
        cnt++;
        printf("%d",cur);if(cnt!=n) printf(" ");
    }
}

int main(){
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&posord[i]);
    for(int i=1;i<=n;i++) scanf("%d",&inord[i]);
    int root=build(1,n,1,n);
    bfs(root);
}
