const int maxn=100000+5;
int n,m;
int num[maxn];
struct node{
    int sub,lsub,rsub;
    int l,r;
//    int lazy;
}SegTree[maxn*2];

void PushUp(int rt,int ln,int rn){
    SegTree[rt].l=SegTree[rt<<1].l;
    SegTree[rt].r=SegTree[rt<<1|1].r;

    SegTree[rt].sub=max(SegTree[rt<<1].sub,SegTree[rt<<1|1].sub);
    if(SegTree[rt<<1|1].l>SegTree[rt<<1].r)
        SegTree[rt].sub=max(SegTree[rt].sub,SegTree[rt<<1].rsub+SegTree[rt<<1|1].lsub);
    
    SegTree[rt].lsub=SegTree[rt<<1].lsub;
    if(SegTree[rt<<1].lsub==ln&&SegTree[rt<<1|1].l>SegTree[rt<<1].r)
        SegTree[rt].lsub+=+SegTree[rt<<1|1].lsub;
    SegTree[rt].rsub=SegTree[rt<<1|1].rsub;
    if(SegTree[rt<<1|1].rsub==rn&&SegTree[rt<<1|1].l>SegTree[rt<<1].r)
        SegTree[rt].rsub+=SegTree[rt<<1].rsub;
    
//    printf("rt=%d sub=%d lsub=%d rsub=%d\n",rt,SegTree[rt].sub,SegTree[rt].lsub,SegTree[rt].rsub);
}

void build(int l,int r,int rt){     //建树
//    SegTree[rt].lazy=0;
    if(l==r){
//        SegTree[rt].val=1;          //叶节点赋值
        SegTree[rt].l=SegTree[rt].r=num[l];
        SegTree[rt].sub=SegTree[rt].lsub=SegTree[rt].rsub=1;
//        printf("l=%d SegTree[rt].l=%d\n",l,num[l]);
        return;
    }
    int m=(l+r)>>1;
    build(l,m,rt<<1);               //建左子树
    build(m+1,r,rt<<1|1);           //建右子树
    PushUp(rt,m-l+1,r-m);        //回溯
}

void PushDown(int rt,int ln,int rn){        //lazy更新
    SegTree[rt<<1].lazy=SegTree[rt].lazy;   //若为覆盖则为=，若为累加则为+=
    SegTree[rt<<1|1].lazy=SegTree[rt].lazy;
    SegTree[rt<<1].val=SegTree[rt].lazy*ln; //若为覆盖则为=，若为累加则为+=
    SegTree[rt<<1|1].val=SegTree[rt].lazy*rn;

    SegTree[rt].lazy=0;                     //结束使命，清除lazy
}

void SingleUpdate(int L,int C,int l,int r,int rt){     //单点更新，区别于区间更新的地方在于：单点更新是类似于dfs一搜到底然后再进行回溯，而区间更新是边精确范围边将符合条件的区间更新（必要时做lazy标记），直至要求的区间均被更新
    if(l==r){
        SegTree[rt].l=SegTree[rt].r=C;
//        printf("l=%d SegTree[rt].l=%d",l,SegTree[rt].l);
        return;
    }
    int m=(l+r)>>1;
    if(L<=m) SingleUpdate(L,C,l,m,rt<<1);
    else if(L>m) SingleUpdate(L,C,m+1,r,rt<<1|1);
    PushUp(rt,m-l+1,r-m);
}

void Update(int L,int R,int C,int l,int r,int rt){      //区间更新
    if(L<=l&&R>=r){
        SegTree[rt].lazy=C;                 //若为覆盖则为=，若为累加则为+=
        SegTree[rt].val=(r-l+1)*C;          //若为覆盖则为=，若为累加则为+=
        return;
    }
    int m=(l+r)>>1;
    if(SegTree[rt].lazy) PushDown(rt,m-l+1,r-m);    //若到达这一步说明肯定还要继续向下，即若该rt有lazy标记则要将之前欠下的补回来（每次更新至其两个子树）
    if(L>m) Update(L,R,C,m+1,r,rt<<1|1);        //注意L、R 和l、m、r的位置关系
    else if(R<=m) Update(L,R,C,l,m,rt<<1);
    else{
        Update(L,R,C,l,m,rt<<1);
        Update(L,R,C,m+1,r,rt<<1|1);
    }
    SegTree[rt].val=SegTree[rt<<1].val+SegTree[rt<<1|1].val;    //回溯
}

int Query(int L,int R,int l,int r,int rt){
    if(L<=l&&R>=r){
        return SegTree[rt].sub;
    }
    else if(L>r||R<l)
        return 0;
    int m=(l+r)>>1;
    int ans=0;
    if(L<=m) ans=max(ans,Query(L,R,l,m,rt<<1));
    if(R>m) ans=max(ans,Query(L,R,m+1,r,rt<<1|1));
    if(L<=m&&R>m&&SegTree[rt<<1].r<SegTree[rt<<1|1].l){
        ans=max(ans,min(SegTree[rt<<1].rsub,m-L+1)+min(SegTree[rt<<1|1].lsub,R-m));
//        printf("%d %d %d %d\n",temp,min(SegTree[rt<<1].rsub,m-L+1),min(SegTree[rt<<1|1].lsub,R-m),min(SegTree[rt<<1].rsub,m-L+1)+min(SegTree[rt<<1|1].lsub,R-m));
    }
//    if(L<=l&&R>=r) printf("rt=%d sub=%d lsub=%d rsub=%d\n",rt,SegTree[rt].sub,SegTree[rt].lsub,SegTree[rt].rsub);
    return ans;
}

