// Last updated: 5/20/2026, 11:36:19 PM
import java.util.ArrayList;
import java.util.List;
import java.util.*;

class Solution {
    public static double average(int[] salary) {
        double max = 0;
        double min = 0;
        double average = 0;
        List<Integer> salList= new ArrayList<>();

        for (int i = 0; i < salary.length; i++) {
            salList.add(salary[i]);
        }


        salList.remove(Collections.max(salList));
        salList.remove(Collections.min(salList));
        System.out.println(salList);


        for (int i = 0; i < salList.size(); i++) {
            average += salList.get(i);
        }
        average /= salList.size();

        System.out.println(average);

        return average;
    }

    public static void main(String[] args) {
        int[] salary = {48000,59000,99000,13000,78000,45000,31000,17000,39000,37000,93000,77000,33000,28000,4000,54000,67000,6000,1000,11000};
        average(salary);
    }
}