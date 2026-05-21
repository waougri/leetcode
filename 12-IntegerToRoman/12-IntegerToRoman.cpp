// Last updated: 5/20/2026, 11:37:52 PM
class Solution {
public:
    const std::map<int, char> intToRomanMap{{1, 'I'},   {5, 'V'},   {10, 'X'},
                                            {50, 'L'},  {100, 'C'}, {500, 'D'},
                                            {1000, 'M'}};

    std::string substractive_form(int num, int power_factor) {
        std::ostringstream oss{};

        int factor = static_cast<int>(std::pow(10, power_factor));

        oss << intToRomanMap.at(1 * factor);
        oss << intToRomanMap.at((num + 1) * factor);

        return oss.str();
    }

    std::string repetitive_form(int num, int power_factor) {
        std::ostringstream oss{};
        int factor = static_cast<int>(std::pow(10, power_factor));
        if (num < 4) {
            for (int i = 0; i < num; ++i) {
                oss << intToRomanMap.at(1 * factor);
            }
        }
        if (num > 5 && num < 9) {
            oss << intToRomanMap.at(5 * factor);

            for (int i = 0; i < num - 5; ++i) {
                oss << intToRomanMap.at(1 * factor);
            }
        }

        return oss.str();
    }

    static std::stack<int> int_to_stack(int num) {
        std::stack<int> vec{};
        while (num > 0) {
            vec.push(num % 10);
            num /= 10;
        }

        return vec;
    }

    string intToRoman(int num) {
        auto st{int_to_stack(num)};
        std::ostringstream oss{};
        int mult_factor = st.size() - 1;

        while (!st.empty()) {
            auto pow = (static_cast<int>(std::pow(10, mult_factor)));
            int digit = st.top();
            st.pop();
            if (intToRomanMap.find(digit * pow) != std::end(intToRomanMap)) {
                oss << intToRomanMap.at(digit * pow);
            } else {
                if (digit == 4 || digit == 9) {
                    oss << substractive_form(digit, mult_factor);
                } else {
                    oss << repetitive_form(digit, mult_factor);
                }
            }
            --mult_factor;
        }

        return oss.str();
    }
};