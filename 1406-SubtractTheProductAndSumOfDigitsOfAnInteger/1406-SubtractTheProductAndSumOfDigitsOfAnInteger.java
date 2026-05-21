// Last updated: 5/20/2026, 11:36:22 PM
class Solution {
    public static int subtractProductAndSum(int n) {
        int sumOfDigits = 0;
        int productOfDigits = 1;

        String str = Integer.toString(n);
        System.out.println(str);
        char[] charring = str.toCharArray();
        System.out.println(charring);
        
        for (int i = 0; i < charring.length; i++) {
            
            sumOfDigits += Character.getNumericValue(charring[i]);
            productOfDigits *= Character.getNumericValue(charring[i]);
        }

        System.out.println(sumOfDigits);
        System.out.println(productOfDigits);

        return productOfDigits - sumOfDigits;
    }
    public static void main(String[] args) {
        subtractProductAndSum(234);
    }
}