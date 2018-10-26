package PhoneScreen;


//  Write a program to sum a very large file (for example 8G) binary integers.
//  Parsing an integer from the front is awkward if you don't know the length of it.
//  Parsing it backwards is much easier: the first digit you encounter is units,
//  the next one is tens, and so on. So the easiest way to approach the whole thing is to read the file backwards.

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;
import java.util.Random;

class Summer {

    long sum = 0;
    long val = 0;

    public void add(byte b) {
        if (b >= '0' && b <= '9') {
            val = (val * 10) + (b - '0');
        } else {
            sum += val;
            val = 0;
        }
    }

    public long getSum() {
        return sum + val;
    }
}

public class SumIntegersInLargeFile {

    // 4k buffer size.
    static final int SIZE = 4 * 1024;
    static byte[] buffer = new byte[SIZE];

    static long sumMapped(File file) throws IOException {
        Summer sum = new Summer();
        FileInputStream f = new FileInputStream(file);
        final FileChannel ch = f.getChannel();
        long red = 0L;
        do {
            final long read = Math.min(Integer.MAX_VALUE, ch.size() - red);
            final MappedByteBuffer mb = ch.map(FileChannel.MapMode.READ_ONLY, red, read);
            int nGet;
            while (mb.hasRemaining()) {
                nGet = Math.min(mb.remaining(), SIZE);
                mb.get(buffer, 0, nGet);
                for (int i = 0; i < nGet; i++) {
                    sum.add(buffer[i]);
                }
            }
            red += read;
        } while (red < ch.size());
        // Finish off.
        ch.close();
        f.close();
        return sum.getSum();
    }

    public static void genRandoms(File file) throws IOException {
        Random r = new Random();
        FileOutputStream fos = new FileOutputStream(file);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));

        for (int i = 0; i < 100000000; i++){
            bw.write(r.nextInt(1000000000)+"");
            bw.newLine();
        }

        bw.close();



    }

    public static void main(String[] args) {
        File file = new File("digits.txt");
        try{
            genRandoms(file);
            System.out.println("Returned sum of large file is: " + sumMapped(file));
        } catch (IOException ex){
           System.out.println("Could not complete request");
        }



    }
}
