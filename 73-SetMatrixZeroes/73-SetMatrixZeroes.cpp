// Last updated: 5/20/2026, 11:37:38 PM
class Solution {
public:
  using mat = vector<vector<int>>;
  void setWholeColumnTo0(mat &matrix, int col) {
    for (auto &r : matrix) {
      r[col] = 0;
    }
  }
  void setWholeRowTo0(mat &matrix, int row) {
    std::fill(matrix[row].begin(), matrix[row].end(), 0);
  }
  void setZeroes(vector<vector<int>> &matrix) {
    std::unordered_set<int> zeroRows;
    std::unordered_set<int> zeroCols;

    for (int row = 0; row < matrix.size(); ++row) {
      for (int col = 0; col < matrix[row].size(); ++col) {
        if (matrix[row][col] == 0) {
          zeroRows.insert(row);
          zeroCols.insert(col);
        }
      }
    }

    for (int row : zeroRows) {
      setWholeRowTo0(matrix, row);
    }

    for (int col : zeroCols) {
      setWholeColumnTo0(matrix, col);
    }
  }
};
