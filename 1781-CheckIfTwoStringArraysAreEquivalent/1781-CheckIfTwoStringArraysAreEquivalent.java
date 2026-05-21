// Last updated: 5/20/2026, 11:36:07 PM
class Solution {
    public static boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String concatWord1= " ";
        String concatWord2= " ";
         

        for (int i = 0; i < word1.length; i++) {
            concatWord1 += word1[i];
            System.out.println(concatWord1);
            
        }

        for (int i = 0; i < word2.length; i++) {
            concatWord2 += word2[i];
            System.out.println(concatWord2);
            
        }

        


        // char[] concatChar1 = concatWord1.toCharArray();
        // char[] concatChar2 = concatWord2.toCharArray();

        // for (int i = 0; i < concatChar1.length; i++) {
        //     for (int j = 0; j < concatChar2.length; j++) {
        //         if (concatChar1[i] == concatChar2[j]) {
        //             areStringsEqual = true;
        //         }
               

        //     }
        // }

        return concatWord1.equals(concatWord2);
    }

    public static void main(String[] args) {
        String[] word1 = {"ab", "c"};
        String[] word2 = {"a", "bc"};
        System.out.println(arrayStringsAreEqual(word1, word2));
        
    }
}