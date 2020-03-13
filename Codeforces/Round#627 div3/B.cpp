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
int a[5050];
map<int,int>mp;
int num=0,s1=0,s2=0;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        mp.clear();num=s1=s2=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(!mp[a[i]]) mp[a[i]]=i;
            else{
                if(!num){
                    s1=mp[a[i]];s2=i;num=a[i];
                }
                else if(s2-s1==1){
                    if(num==a[i]) s2=i;
                    else{num=a[i];s1=mp[a[i]];s2=i;}
                }
            }
        }
        if(!num||abs(s2-s1)==1) printf("NO\n");
        else printf("YES\n");
    }
}
