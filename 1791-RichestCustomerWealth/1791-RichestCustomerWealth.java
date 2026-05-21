// Last updated: 5/20/2026, 11:36:09 PM


import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int maximumWealth(int[][] accounts) {
        List<Integer> wealth = new ArrayList<>();
        for (int[] account : accounts) {
            int sum = 0;
            for (int i : account) {
                sum += i;
            }
            wealth.add(sum);
        }
        return Collections.max(wealth);
    }
}