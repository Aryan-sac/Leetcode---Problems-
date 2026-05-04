class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int j=0; // tracking 0 to swap
        for(int i=0; i<arr.size(); i++){
            if(arr[i] != 0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
        
    }
};