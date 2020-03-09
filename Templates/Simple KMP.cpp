#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int MAXN=1e5+10;
char T[MAXN],P[MAXN];
int nxt[MAXN];

void init(char* P,int* nxt){
    int lenp=(int)strlen(P);
    nxt[0]=nxt[1]=0;
    for(int i=1;i<lenp;i++){
        int j=nxt[i];
        while(j&&P[i]!=P[j]) j=nxt[j];
        nxt[i+1]=P[i]==P[j]?j+1:0;
    }
}

int find(char* T,char* P,int* nxt){
    int cnt=0;
    int lent=(int)strlen(T);
    int lenp=(int)strlen(P);
    int j=0;
    for(int i=0;i<lent;i++){
        if(j&&T[i]!=P[j]) j=nxt[j];
        if(T[i]==P[j]) j++;
        if(j==lenp) {cnt++;j=nxt[j];}
    }
    return cnt;
}
