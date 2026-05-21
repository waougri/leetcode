// Last updated: 5/20/2026, 11:36:33 PM
import java.util.*;

class Solution {
    public static int numJewelsInStones(String jewels, String stones) {
        char[] jac = jewels.toCharArray();
         char[] sac = stones.toCharArray();
         int sum = 0;
        if(1 <= jac.length && sac.length <= 50){
            

            List<Character> jc = new ArrayList<Character>();
            List<Character> sc = new ArrayList<>();

            for (int i = 0; i < sac.length; i++) {
                sc.add(sac[i]);
            }

            for (int i = 0; i < jac.length; i++) {
                jc.add(jac[i]);
            }

           for (int index = 0; index < jac.length; index++) {
                int occurences = Collections.frequency(sc, jac[index]);
                sum += occurences;
           }
           
           
        }
        return sum;
   }



   public static void main(String[] args) {
    String jewels = "aA";
    String stones = "aAAbbbb";

    numJewelsInStones(jewels, stones);
   }
}