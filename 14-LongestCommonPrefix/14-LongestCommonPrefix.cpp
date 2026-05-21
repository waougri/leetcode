// Last updated: 5/20/2026, 11:37:51 PM
#include <algorithm>
#include <cstdio>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

using namespace std::string_literals;
using hist_t = std::unordered_map<string, int>;

class Solution {
public:
    int minimal_length(const vector<string>& strs) {

        return std::min_element(
                   strs.begin(), strs.end(),
                   [](const std::string& lhs, const std::string& rhs) {
                       return lhs.length() < rhs.length();
                   })
            ->length();
    }

    void print_hist(const hist_t& h) {
        for (const auto& [k, v] : h) {
            printf("{%s, %i}\n", k.c_str(), v);
        }
    }

    string longestCommonPrefix(vector<string>& strs) {
        hist_t hist{};
        int min_l = minimal_length(strs);
        for (const auto& s : strs) {

            for (int i = 0; i <= min_l; ++i) {
                auto sb = s.substr(0, i);
                if (sb.empty()) {
                    continue;
                }
                ++hist[sb];
            }
        }

        if (hist.size() == 1) {
            return hist.begin()->first;
        }

        using pair_type = decltype(hist)::value_type;
        return std::all_of(std::begin(hist), std::end(hist),
                           [&](typename hist_t::const_reference t) {
                               return t.second < strs.size();
                           })
                   ? ""s
                   : std::max_element(std::begin(hist), std::end(hist),
                                      [](const pair_type& lhs,
                                         const pair_type& rhs) -> bool {
                                          return lhs.second == rhs.second
                                                     ? lhs.first.length() <
                                                           rhs.first.length()
                                                     : lhs.second < rhs.second;
                                      })
                         ->first;
    }
};
