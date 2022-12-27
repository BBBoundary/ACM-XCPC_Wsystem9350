class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        /*
         贪心法，将所有线段按照右端点从小到大排序
         最优解情况下，(从左到右处理)每一步都取当前右端点最小的线段，则剩余可放的空间会更大、有机会能放下更多的线段。
         */
        if(intervals.empty()) return 0;
        int n=intervals.size();
        /*注意stl:sort的用法！一行搞定*/
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b){return a[1]<b[1];});
        int ans=0;
        int pree=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<pree) ans++;
            else pree=intervals[i][1];
        }
        return ans;
    }
};
