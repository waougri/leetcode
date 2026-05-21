// Last updated: 5/20/2026, 11:37:55 PM
class Solution {
    public static boolean isPalindrome(int x) {
        return new StringBuilder(String.valueOf(x)).reverse().toString().equals(String.valueOf(x));
    }
}