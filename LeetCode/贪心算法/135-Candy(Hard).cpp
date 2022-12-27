class Solution {
public:
    int candy(vector<int>& ratings) {
        int i=0,cnt[20010];
        int sum=0;
        /*
         三次遍历
         第一次：先将每一位的基础值置为1
         第二次：从左到右，若当前ratings[i]>ratings[i-1],则cnt[i]=cnt[i-1]+1;
         第三次：从右到左，若当前ratings[i]>ratings[i+1],则cnt[i]=cnt[i+1]+1;
         */
        while(i<ratings.size()) {cnt[i]=1;i++;}
        i=1;
        while(i<ratings.size()){
            if(ratings[i]>ratings[i-1]) cnt[i]=cnt[i-1]+1;
            i++;
        }
        sum=cnt[ratings.size()-1];
        i=ratings.size()-2;
        while(i>=0){
            if(ratings[i]>ratings[i+1]) cnt[i]=max(cnt[i+1]+1,cnt[i]);
            sum+=cnt[i];
            i--;
        }
        return sum;
    }
};
