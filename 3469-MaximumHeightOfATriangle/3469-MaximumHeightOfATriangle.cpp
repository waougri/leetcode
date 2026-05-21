// Last updated: 5/20/2026, 11:35:48 PM
class Solution {
public:
    int construct_max_triangle(int red, int blue, bool red_start) {
        int height = 0;
        int level = 1;
        
        while (true) {
            if (red_start) {
                red -= level;
                if (red < 0) break;
            } else {
                blue -= level;
                if (blue < 0) break;
            }
            ++height;
            ++level;
            red_start = !red_start; // Switch turn
        }
        
        return height;
    }

    int maxHeightOfTriangle(int red, int blue) {
        if (red == 0 && blue == 0) return 0;
        
        int max_height = 0;
        // Check starting with red and starting with blue
        max_height = std::max(max_height, construct_max_triangle(red, blue, true));
        max_height = std::max(max_height, construct_max_triangle(red, blue, false));
        
        return max_height;
    }
};
