// Last updated: 5/20/2026, 11:35:47 PM
class Solution {
public:
  int get_wrapped_index(const std::string_view s, int i, int k) {
    int len = s.length();
    int wrapped_idx = (i + k) % len;
    if (wrapped_idx < 0)
      wrapped_idx += len;

    return wrapped_idx;
  }

  string getEncryptedString(string s, int k) {
    std::ostringstream oss{};
    for (int i = 0; i < s.length(); ++i) {
      oss << s[get_wrapped_index(s, i, k)];
    }

    return oss.str();
  }
};