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
typedef pair<int,int> pii;

int num[15]={2,3,5,7,11,13,17,19,23,29,31};
int n,a[1010];
int mp[15];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int tot=0;
        fill(mp,mp+15,0);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            for(int j=0;j<11;j++){
                if(a[i]%num[j]==0){
                    if(!mp[j]) mp[j]=++tot;
                    a[i]=mp[j];
                    break;
                }
            }
        }
        printf("%d\n",tot);
        for(int i=1;i<=n;i++) {printf("%d",a[i]);if(i!=n) printf(" ");}printf("\n");
    }
}
