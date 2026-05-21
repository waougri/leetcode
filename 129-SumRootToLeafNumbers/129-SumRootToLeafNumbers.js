// Last updated: 5/20/2026, 11:37:30 PM
/**
 * @param {TreeNode} root
 * @return {number}
 */
var sumNumbers = function (root) {
  return sum(root, 0);
};

const sum = (n, s) => {
  if (n === null || n === undefined) return 0;
  if (!n.right && !n.left) return s * 10 + n.val;
  return sum(n.left, s * 10 + n.val) + sum(n.right, s * 10 + n.val);
};
