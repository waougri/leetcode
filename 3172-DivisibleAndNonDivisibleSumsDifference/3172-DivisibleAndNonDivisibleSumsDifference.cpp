// Last updated: 5/20/2026, 11:35:49 PM
class Solution {
public:
  int differenceOfSums(int n, int m) {

    int n1{}, n2{};

    for (int i = 1; i <= n; ++i) {

      if (i % m == 0) {
        n1 += i;
      } else {
        n2 += i;
      }
    }
    return n2 - n1;
  }
};
