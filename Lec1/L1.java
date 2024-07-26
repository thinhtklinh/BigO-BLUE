import java.util.ArrayList;
import java.util.Arrays;
import java.lang.Character;

public class L1 {
    public static void main(String[] args) {
        // LECTURE 1
        System.out.println("JAVA");

        ArrayList<Integer> arr = new ArrayList<Integer>();
        arr.add(1);
        arr.add(3);
        arr.add(4);

        arr.add(1, 2);

        System.out.println("Size: " + arr.size());

        System.out.println("3rd element: " + arr.get(2));

        arr.set(3, 10);

        arr.remove(arr.size() - 1);
        
        arr.remove(2);

        arr.clear();

        int len = arr.size();
        for (int i = len; i < len + 8; i++) {
            arr.add(0);
        }

        arr.subList(5, 8).clear();

        arr = new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4));

        System.out.println(arr.isEmpty() ? "Empty" : "Not Empty");


        // print the arr
        for (int i = 0; i < arr.size(); i++) {
            System.out.print(arr.get(i) + " ");
        }

        for (int i = arr.size() - 1; i > -1; i--) {
            System.out.print(arr.get(i) + " ");
        }

        String str = "4Hello World";

        if (str.charAt(0) >= '0' && str.charAt(0) <= '9') {
            System.out.println("Digit");
        }

        System.out.println(Character.isLetter(str.charAt(2)) ? "Letter" : "Not Letter");

        String num = "123";
        int nu = Integer.parseInt(num);
        String num2 = Integer.toString(nu);
        System.out.println(num2);
    }
}