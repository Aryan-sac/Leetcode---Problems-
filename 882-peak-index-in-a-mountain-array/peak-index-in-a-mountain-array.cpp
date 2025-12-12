class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 1, end = arr.size()-2;         // ignoring first and last element in 'arr' {on including that Mountain will Not form}
        while(st <= end){
            int mid = st + (end-st)/2;

            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid] > arr[mid+1])
                end = mid-1;
            else
                st = mid+1;
        }
        return -1;
    }
};