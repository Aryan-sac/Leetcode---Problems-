class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int>max;
        priority_queue<int, vector<int>, greater<int>>min;
        
        vector<double>ans;
        for(int i=0; i<arr.size(); i++){
            if(max.empty())
            {
                max.push(arr[i]);
                ans.push_back(arr[i]);
                continue;
            }
                
            if(arr[i] > max.top())
                min.push(arr[i]);
            else
                max.push(arr[i]);
                
            // Adjust the element in correct HEap
            if(max.size() > min.size()+1){
                min.push(max.top());
                max.pop();
            }
            if(min.size() > max.size())
            {
                max.push(min.top());
                min.pop();
            }
            
            // Store answer
            if(max.size() == min.size())
                ans.push_back((double)(max.top()+min.top())/2);
            else
                ans.push_back(max.top());
        }
        
        return ans;
    }
};
