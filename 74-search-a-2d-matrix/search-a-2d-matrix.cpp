class Solution {
public:

    // Search in row if correct Row found
    bool srchInRow(vector<vector<int>>& matrix, int target, int row){
        int st=0, end= matrix[0].size()-1, mid;
        while(st <= end){
            mid = st + (end-st)/2;
            if(matrix[row][mid] == target)
                return true;
            else if (target  < matrix[row][mid])
                end = mid-1;
            else
                st = mid+1;
        }
        return false;
    }    

    // Search a Particular row where target element found
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st=0, end= matrix.size()-1, mid;
        while(st <= end){
            mid = st + (end-st)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[0].size()-1] ){
                if(srchInRow(matrix, target, mid))
                    return true;
                return false;
            }
            else if (target  < matrix[mid][0])
                end = mid-1;
            else
                st = mid+1;
        }
        return false;
    }
};