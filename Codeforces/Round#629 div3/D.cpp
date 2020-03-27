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

int n,cnt;
int num[200010],ans[200010];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cnt=1;
        scanf("%d",&n);
        int flag=0,pos=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
            if(i!=1&&num[i]!=num[i-1]) flag=1;
            if(!pos&&num[i]==num[i-1]) pos=i;
        }
        //        printf("pos=%d\n",pos);
        if(!flag){
            printf("1\n");
            for(int i=1;i<=n;i++) {printf("1");if(i!=n) printf(" ");}printf("\n");
            continue;
        }
        if(n%2==0){
            printf("2\n");
            for(int i=0;i<n;i++){printf("%d",i%2+1);if(i!=n) printf(" ");}printf("\n");
            continue;
        }
        if(num[1]==num[n]){
            printf("2\n");
            for(int i=0;i<n;i++){printf("%d",i%2+1);if(i!=n) printf(" ");}printf("\n");
            continue;
        }
        if(!pos){
            printf("3\n");
            for(int i=0;i<n-1;i++){printf("%d",i%2+1);printf(" ");}
            printf("3\n");
        }
        else{
            printf("2\n");
            int tmp=2;
            for(int i=0;i<n;i++){
                if(i!=pos-1){tmp=3-tmp;printf("%d",tmp);}
                else{ printf("%d",tmp);}
                if(i!=n-1) printf(" "); else printf("\n");
            }
        }
    }
}
