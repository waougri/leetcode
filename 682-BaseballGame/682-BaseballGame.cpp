// Last updated: 5/20/2026, 11:36:37 PM
class Solution {
public:
    constexpr bool is_number(const std::string& s) {
        if (s.empty()) {
            return false;
        }

        std::string::const_iterator start = s.begin();
        if (*start == '-') {

            ++start;
        }

        return start != s.end() && std::all_of(start, s.end(), ::isdigit);
    }

    int calPoints(vector<string>& operations) {
        std::vector<int> record{};
        for (const auto& s : operations) {
            if (is_number(s)) {

                record.push_back(std::stoi(s));

            }

            else if (s == "D") {

                record.push_back(record.at(record.size() - 1) * 2);

            }

            else if (s == "C") {

                record.pop_back();

            }

            else if (s == "+") {

                record.push_back(record.at(record.size() - 2) +
                                 record.at(record.size() - 1));
            }
        }

        int sum{};

        if (record.empty())
            sum = 0;
        else {
            for (const int& i : record)
                sum += i;
        }

        return sum;
    }
};
