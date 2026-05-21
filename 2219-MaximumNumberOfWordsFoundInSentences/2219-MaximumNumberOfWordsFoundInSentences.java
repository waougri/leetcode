// Last updated: 5/20/2026, 11:35:54 PM
import java.util.*;

class Solution {
    public static int mostWordsFound(String[] sentences) {
        List<Integer> list = new ArrayList();
        if(1<=sentences.length && sentences.length <= 100){
            for(int i = 0; i < sentences.length; i++){
                int wordCount = 0;
                String[] words = sentences[i].split("\\s+");
                for(String word : words){
                    wordCount++;
                }
                
                list.add(wordCount);
            }
            System.out.println(list);
        
        }
        return Collections.max(list);
       }
}