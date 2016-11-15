import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 *
 * @author xergioalex
 */
public class Sort {
    public static int size = 1000000;

    /**
     * Program for Selection Sort in Java
     *
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        int[] numbers = new int[size];

        System.out.println("Size of array: " + size);

        readNumbersFromFile(numbers);

        // Get init time
        long timeStart, timeEnd;
        timeStart = System.currentTimeMillis();

        // Sort
        selectionSort(numbers);

        // Get final time
        timeEnd = System.currentTimeMillis();
        System.out.println("The task has taken "+ (( timeEnd - timeStart ) / 1000.0) +" seconds");
//        printArray(numbers);
    }

    public static void selectionSort(int[] numbers) {
        for (int i = 0; i < numbers.length - 1; i++) {
            int minInd = i;
            for(int j = i + 1; j < numbers.length; j++) {
                if(numbers[j] < numbers[minInd]) {
                    minInd = j;
                }
            }
            int tempVal = numbers[minInd];
            numbers[minInd] = numbers[i];
            numbers[i] = tempVal;
        }
    }



    public static void readNumbersFromFile(int[] numbers) throws IOException {
        BufferedReader reader = null;

        try {
            String sCurrentLine;

            reader = new BufferedReader(new FileReader("../numbers/numbers"+size+".txt"));

            while ((sCurrentLine = reader.readLine()) != null) {
                StringTokenizer token = new StringTokenizer(sCurrentLine);
                int i = 0;
                while (token.hasMoreTokens()) {
                    numbers[i] = Integer.valueOf(token.nextToken());
                    i++;
                }
            }

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (reader != null) { reader.close(); }
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

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
