class Solution {
public:
    long long reqTime(vector<int>& piles, int hr){
        long long totalTime=0;
        for(int i=0; i<piles.size(); i++){
            totalTime += ceil((double)piles[i]/(double)hr);
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = INT_MIN, ans;
        for(auto i: piles){
            high = max(high, i);
        }
        int low=1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(reqTime(piles, mid) <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};