// Last updated: 5/20/2026, 11:37:25 PM
import java.util.function.BinaryOperator;

public class Solution {
    // you need to treat n as an unsigned value
    public static int hammingWeight(int n) {
        int counter = 0;
        String a = Integer.toBinaryString(n);
        
        System.out.println(a);

        char[] b = a.toCharArray();

        for (int i = 0; i < b.length; i++) {
            if (b[i] == '1'){
                counter++;
            }
        }


        return counter;
    }
    public static void main(String[] args) {
System.out.println(hammingWeight(93138123)); 
    }
}