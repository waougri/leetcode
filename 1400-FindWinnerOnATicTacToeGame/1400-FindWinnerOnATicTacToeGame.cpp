// Last updated: 5/20/2026, 11:36:23 PM
class Solution {
public:
    enum tileState { kA, kB, kNone };

    using moves_t = vector<vector<int>>;
    using table_t = std::array<std::array<tileState, 3>, 3>;
    bool checkRowsForWin(const table_t& table, const tileState& playerSign) {

        for (int i = 0; i < table.size(); ++i) {
            if (std::all_of(table[i].begin(), table[i].end(),
                            [&](tileState i) { return i == playerSign; }))
                return true;
        }
        return false;
    }

    bool checkDiagonalForWin(const table_t& table,
                             const tileState& playerSign) {
        return table[0][0] == table[1][1] && table[1][1] == table[2][2] &&
               table[0][0] == playerSign;
    }

    bool checkAntDiagonalForWin(const table_t& table,
                                const tileState& playerSign) {
        return table[0][2] == table[1][1] && table[1][1] == table[2][0] &&
               table[0][2] == playerSign;
    }

    bool checkVerticalsForWin(const table_t& table,
                              const tileState& playerSign) {
        for (int i = 0; i < 3; ++i) {
            if ((table[0][i] == playerSign && table[0][i] == table[1][i] &&
                 table[1][i] == table[2][i]))
                return true;
        }
        return false;
    }

    bool checkIfGameIsPending(const table_t& table) {
        bool is_pending = true;
        for (const auto& row : table) {
            if (std::any_of(row.begin(), row.end(),
                            [](tileState state) { return state == kNone; }))
                return true;
        }
        return false;
    }

    void populateTableWithMoves(table_t& table, const moves_t& moves) {
        bool a_turn = true;
        for (const vector<int>& v : moves) {
            table[v[0]][v[1]] = a_turn ? kA : kB;
            a_turn = !a_turn;
        }
    }
    string tictactoe(vector<vector<int>>& moves) {
        table_t table{};
        for (std::array<tileState, 3>& arr : table) {
            std::fill(arr.begin(), arr.end(), kNone);
        }
        populateTableWithMoves(table, moves);

        if (checkRowsForWin(table, kA) || checkDiagonalForWin(table, kA) ||
            checkAntDiagonalForWin(table, kA) ||
            checkVerticalsForWin(table, kA))
            return "A";
        else if (checkRowsForWin(table, kB) || checkDiagonalForWin(table, kB) ||
                 checkAntDiagonalForWin(table, kB) ||
                 checkVerticalsForWin(table, kB))
            return "B";

        if (checkIfGameIsPending(table))
            return "Pending";
        return "Draw";
    }
};