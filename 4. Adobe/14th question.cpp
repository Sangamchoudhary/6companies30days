
Time --> O(KlogK)
Space --> O(K)

class Box {
  public:
    int num, numIdx, arrIdx;
    
    Box(int _num, int _numIdx, int _arrIdx) {
        num = _num, numIdx = _numIdx, arrIdx = _arrIdx;
    }
};

struct comp {
	bool operator()(const Box &x, const Box &y) const { 
	    if(x.num == y.num) return x.arrIdx < y.arrIdx;
	    return x.num < y.num;
	}
};

class Solution {
  public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k) {
          set<Box, comp> s;
          for(int i = 0; i < k; i++) {
              Box b(KSortedArray[i][0], 0, i);
              // Element, element index, array index
              s.insert(b);
          }
          pair<int, int> range = {0, 1e5};
          while(1) {
              auto l = *s.begin(), r = *s.rbegin();
              int currD = r.num - l.num, prevD = range.second - range.first;
              if(currD < prevD) range = {l.num, r.num};
              int currIdx = l.numIdx;
              if(currIdx == n - 1) break;
              s.erase(s.begin());
              // Put the new element
              l.numIdx = currIdx + 1;
              l.num = KSortedArray[l.arrIdx][l.numIdx];
              s.insert(l);
          }
          return range;
    }
};