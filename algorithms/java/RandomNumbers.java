import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Random;

/**
 * Generate Random Numbers and write in File
 *
 * @author xergioalex
 */
public class RandomNumbers {
    public static double size = 1000000000;

    /**
     *
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        Writer writer = null;
        try {
            File file = new File("../../numbers/numbers.txt");

            // if file doesnt exists, then create it
            if (!file.exists()) {
                file.createNewFile();
            }

            writer = new FileWriter(file.getAbsoluteFile(), true);

            String numbers = "";
            double lenght = size;
            for (double i = lenght; i >= 0; i--) {
                // numbers += i;
                numbers += randInt(10000, 100000);

                numbers += " ";
                // if (i < lenght -1) {
                // }
                if (i % 10 == 0) {
                    writer.write(numbers);
                    numbers = "";
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try{
                if(writer!=null) { writer.close(); }
            } catch(Exception ex) {
    	       System.out.println("Error in closing the BufferedWriter"+ex);
    	    }
    	}
    }

    /**
     * Generate a random number
     *
     * @param min => min value for the random number
     * @param max => max value for the random number
     * @return random number
     */
    public static int randInt(int min, int max) {
        int randomNum = (int) Math.floor(Math.random()*(max-min+1)+min);

        return randomNum;
    }

}
