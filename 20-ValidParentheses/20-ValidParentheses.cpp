// Last updated: 5/20/2026, 11:37:49 PM
const std::unordered_map<char, char> p_map = {{'{', '}'}, {'(', ')'}, {'[', ']'}};

const std::unordered_set<char> openings{'{', '(', '['};
bool is_opening_paren(const char c) {

  return std::find(openings.begin(), openings.end(), c) != openings.end();
}

const std::unordered_set<char> closings{'}', ')', ']'};
bool is_closing_paren(const char c) {

  return std::find(closings.begin(), closings.end(), c) != closings.end();
}
class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 1) {
            return false;
        }
        std::stack<char> stack{};

        for (const auto& c : s) {
            if (is_opening_paren(c)) {
                stack.push(c);
            } else if (is_closing_paren(c)) {
                if (stack.empty()) {
                    return false;
                } else if (c != p_map.at(stack.top())) {
                    return false;
                } else {
                    stack.pop();
                }
            }
        }
        if (!stack.empty())
            return false;
        return true;
    }
};