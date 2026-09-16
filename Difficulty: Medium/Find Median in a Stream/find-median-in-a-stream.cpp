class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int>left;
        priority_queue<int, vector<int>, greater<int>>right;
        vector<double>ans;
        left.push(arr[0]);
        ans.push_back(arr[0]);
        for(int i=1; i<arr.size(); i++){
                
            if(arr[i] > left.top())
                right.push(arr[i]);
            
            else
                left.push(arr[i]);
            
            // Adjusting the left(max) and right(min)  heap;
            
            if(left.size() > right.size()+1){
                right.push(left.top());
                left.pop();
            }
            if(right.size() > left.size())
            {
                left.push(right.top());
                right.pop();
            }
            
            // insering elements in answer array
            
            if(left.size() == right.size())
                ans.push_back((double)(left.top()+right.top())/2);
            else
                ans.push_back(left.top());
        }
        return ans;
    }
};
