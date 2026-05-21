// Last updated: 5/20/2026, 11:36:39 PM
enum Moves {

        kUp = 'U',
        kDown = 'D',
        kLeft = 'L',
        kRight = 'R'

    };

class Solution {
public:
    

    using coords_t = std::pair<int, int>;
    coords_t addCoords(const coords_t& lhs, const coords_t& rhs) {
        return {lhs.first + rhs.first, lhs.second + rhs.second};
    }
    bool judgeCircle(string moves) {
        static const std::unordered_map<Moves, coords_t> mvs{{kUp, {0, 1}},
                                                             {kDown, {0, -1}},
                                                             {kLeft, {-1, 0}},
                                                             {kRight, {1, 0}}};

        static const coords_t origin{0, 0};

        coords_t current_coords = origin;

        for (const auto move : moves) {
            current_coords =
                addCoords(current_coords, mvs.at(static_cast<Moves>(move)));
        }

        return current_coords == origin;
    }
};