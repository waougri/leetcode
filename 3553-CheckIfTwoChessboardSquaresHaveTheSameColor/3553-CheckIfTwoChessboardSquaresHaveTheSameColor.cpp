// Last updated: 5/20/2026, 11:35:48 PM


enum Colors { kBlack, kWhite };

class Solution {
public:
  Colors getSquareColor(const string &coords) {
    int atoi = coords[0] - 'a' + 1;
 
    // if col is even
    if (atoi % 2 == 0) {
      // if row is even
      if ((coords[1] - '0') % 2 == 0) {
        return kBlack;
      } else {
        return kWhite;
      }
    } else {
      if ((coords[1] % 2) == 0) {
        return kWhite;
      }
      return kBlack;
    }
  }
  bool checkTwoChessboards(string coordinate1, string coordinate2) {
    return getSquareColor(coordinate1) == getSquareColor(coordinate2);
  }
};
