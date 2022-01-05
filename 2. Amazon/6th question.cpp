
Language --> C++

Time --> O(N) , as we will visit element at most twice because of deque
Space --> (N) , for deque

class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k){   
        vector<int> ans;
        deque<int> dq;
        int i = 0;
        while(i < n){
            while(!dq.empty() and dq.front() == i-k) dq.pop_front();
            
            while(!dq.empty() and arr[dq.back()] < arr[i]) dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1) ans.push_back(arr[dq.front()]);
            
            i++;
        }
        return ans;
    }
};