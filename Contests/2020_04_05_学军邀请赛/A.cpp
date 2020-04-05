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

void solve2(){
    printf("5\n");
    printf("1 1\n1 2\n1 3\n2 3\n2 2\n2 1\n");
}

void solve3(){
    printf("11\n");
    printf("2 1\n1 1\n1 2\n2 3\n3 2\n3 1\n2 2\n1 3\n1 4\n2 4\n3 4\n3 3\n");
}

void solve0(){
    printf("%d\n",n*(n+1)-1);
    printf("2 1\n1 1\n");
    int now=2;
    while(now!=n){
        printf("1 %d\n2 %d\n",now,now+1);
        int i=3,j=now;
        for(;i<=n&&j>=1;i++,j--) {printf("%d %d\n",i,j);}
        i--;j++;
        if(j==1) printf("%d %d\n",--i,1);
        else printf("%d %d\n",i,--j);
        i--;j++;
        for(;i>=1;i--,j++) printf("%d %d\n",i,j);
        now+=2;
    }
    printf("1 %d\n1 %d\n",now,now+1);
    now=2;
    while(now!=n){
        printf("%d %d\n",now,n+1);
        int i=now+1,j=n;
        for(;i!=n+1&&j!=0;i++,j--) {printf("%d %d\n",i,j);}
        printf("%d %d\n",--i,j);
        i--;j++;
        for(;i>=now;i--,j++) printf("%d %d\n",i,j);
        printf("%d %d\n",now+1,n+1);
        now+=2;
    }
    printf("%d %d\n%d %d\n",n,n+1,n,n);
}

void solve1(){
    printf("%d\n",n*(n+1)-1);
    printf("2 1\n1 1\n");
    int now=2;
    while(now!=n+1){
        printf("1 %d\n2 %d\n",now,now+1);
        int i=3,j=now;
        for(;i<=n&&j>=1;i++,j--) {printf("%d %d\n",i,j);}
        i--;j++;
        if(j==1) printf("%d %d\n",--i,1);
        else printf("%d %d\n",i,--j);
        i--;j++;
        for(;i>=1;i--,j++) printf("%d %d\n",i,j);
        now+=2;
    }
    printf("1 %d\n2 %d\n",n+1,n+1);
    now=3;
    while(now!=n){
        printf("%d %d\n",now,n+1);
        int i=now+1,j=n;
        for(;i!=n+1&&j!=0;i++,j--) {printf("%d %d\n",i,j);}
        printf("%d %d\n",--i,j);
        i--;j++;
        for(;i>=now;i--,j++) printf("%d %d\n",i,j);
        printf("%d %d\n",now+1,n+1);
        now+=2;
    }
    printf("%d %d\n%d %d\n",n,n+1,n,n);
}

int main(){
    scanf("%d",&n);
    if(n==2) solve2();
    else if(n==3) solve3();
    else{
        if(n%2==0)solve0();
        else solve1();
    }
}
