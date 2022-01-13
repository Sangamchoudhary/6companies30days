
Time --> O(N) , as we are visit 1 element max of 2 times (2nd time because of stack)
Space --> O(N) , stack space

class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n){
        vector<int> ans;
        stack<int> st;
        st.push(0);
        ans.push_back(1);
        for(int i=1;i<n;i++){
            while(!st.empty() and price[st.top()] <= price[i])
                st.pop();
                
            int days = st.empty() ? i+1 : i-st.top();
            ans.push_back(days);
            st.push(i);
        }
        return ans;
    }
};