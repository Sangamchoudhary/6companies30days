

Language --> C++;

Time --> O(1)
Space --> O(1)


Ques --> Find total number of Squares in a N*N chessboard

class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        return (long long)(n * (n+1) * (2*n+1)) / 6;
    }
};