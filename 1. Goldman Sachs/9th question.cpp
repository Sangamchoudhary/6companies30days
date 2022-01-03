
Language --> c++

Time --> O(N)
Space --> O(N) , in worst case when whole string will be filled with 'D' only

class Solution{   
public:

    string printMinNumberForPattern(string s){
        string ans;
        stack<int> st;
        int num = 1;
        for(auto it:s){
            if(it == 'D'){
                st.push(num);
                num++;
            }else{
                st.push(num);
                num++;
                while(!st.empty()){
                    ans += to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(num);
        while(!st.empty()){
            ans += to_string(st.top());
            st.pop();
        }
        return ans;
    }
};