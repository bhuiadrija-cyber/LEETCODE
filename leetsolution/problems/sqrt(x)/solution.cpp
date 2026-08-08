class Solution {
public:
    int mySqrt(int x) {
        long long lo=0,hi=x;
        long long mid;
        while (lo<=hi){
            mid=lo+(hi-lo)/2;
            if (mid*mid==x) return mid;
            if (mid*mid<x) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};