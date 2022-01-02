
Language --> c++

Time -> O(1)
Space --> O(1)

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        if(N == 1) return 1;
        int pos = M % N;
        return (sum + K - 1) == N ? (sum + K - 1) : (sum + K - 1) % N;
    }
};