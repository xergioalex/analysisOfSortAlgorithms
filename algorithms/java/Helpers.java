import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 *
 * @author xergioalex
 */
public class Helpers {
    public static void printArray(int[] numbers) throws IOException {
        for (int i = 0; i < numbers.length; i++) {
            System.out.print(numbers[i]);
            if (i < numbers.length - 1) {
                System.out.print(" ");
            }
        }
        System.out.println("");
    }
}



// public class A {
//    public void unMetodoDeA() {
//        B b = new B();
//        b.unMetodoDeB();
//    }
// }