// Last updated: 5/20/2026, 11:36:25 PM

class Solution {
public:
  void backtrack(std::set<string> &sequences, string path,
                 std::vector<bool> &used, const std::string_view tiles) {
    if (not path.empty())
      sequences.insert(path);

    for (int i = 0; i < tiles.size(); ++i) {
      if (used[i] or (i > 0 && tiles[i] == tiles[i - 1]) and not used[i - 1]) {
        continue;
      }

      used[i] = true;
      backtrack(sequences, path + tiles[i], used, tiles);
      used[i] = false;
    }
  }

  int numTilePossibilities(string tiles) {    if (tiles.size() == 1)
      return 1;

    std::sort(tiles.begin(), tiles.end());
    std::set<string> sequences{};
    vector<bool> used(tiles.size(), false);
    backtrack(sequences, "", used, tiles);
    return sequences.size();
  }
};
