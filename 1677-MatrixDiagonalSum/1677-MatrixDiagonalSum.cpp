// Last updated: 5/20/2026, 11:36:08 PM

class Solution {

public:
  using matrix2D = vector<vector<int>>;

  int sumOfDiagonalsOdd(const matrix2D &mat) {
    int ant_diag_sum{};
    int diag_sum{};

    const int center_idx = static_cast<size_t>(std::floor(mat.size() / 2.0));
    for (ptrdiff_t row = 0; row < mat.size(); ++row) {
      ant_diag_sum += mat[row][(mat.size() - 1) - row];
      diag_sum += mat[row][row];
    }

    ant_diag_sum -= mat[center_idx][center_idx];

    return diag_sum + ant_diag_sum;
  }

  int sumOfDiagonals(const matrix2D &mat) {
    int diag_sum{};

    int ant_diag_sum{};
    for (ptrdiff_t row = 0; row < mat.size(); ++row) {
      diag_sum += mat[row][row];
      ant_diag_sum += mat[row][(mat.size() - 1) - row];
    }

    return diag_sum + ant_diag_sum;
  }

  int diagonalSum(vector<vector<int>> &mat) {
    if (mat.size() == 1 && mat[0].size() == 1)
      return mat[0][0];

    return mat.size() % 2 == 0 ? (sumOfDiagonals(mat)) : sumOfDiagonalsOdd(mat);
  }
};
