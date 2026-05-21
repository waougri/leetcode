// Last updated: 5/20/2026, 11:37:53 PM
var longestCommonPrefix = function (strs) {
  if (strs.length === 1) return strs[0];

  const result = [];

  let i = 0;
  while (i > -1) {
    for (let j = 1; j < strs.length; j++) {
      if (strs[j][i] === undefined || strs[j - 1][i] !== strs[j][i]) {
        i = -1;
        break;
      }
    }

    if (i >= 0) {
      result.push(strs[0][i]);

      i++;
    }
  }

  return result.join("");
};