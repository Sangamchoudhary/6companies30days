
Language --> C++

------------------------------ 2 Approches -----------------------------

------------------------------------------------------------------------
1. With Deque

Time --> O(N) , as we will visit element at most 2 time (because of deque)
Space --> O(K)

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k){
        vector<int> ans;
        deque<int> dq;
        int i=0;
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
------------------------------------------------------------------------



------------------------------------------------------------------------
2. with max heap

Time --> O(NlogN) , in worst case 
Space --> O(N)

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k){
        vector<int> ans;
        priority_queue<pii> pq;
        int i=0,j=0;
        
        while(j < n){
            if(j-i+1 < k){
                pq.push({arr[j],j});
                j++;
            }else{
                pq.push({arr[j],j});
                int t = pq.top().first;
                ans.push_back(t);
                while(!pq.empty()){
                    if(pq.top().second <= i){
                        pq.pop();
                    }else{
                        break;
                    }
                }
                i++,j++;
            }
        }
        return ans;
    }
};
---------------------------------------------------------------------------