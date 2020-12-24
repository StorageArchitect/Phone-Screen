package Misc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

// Find top k (or most frequent) numbers in a stream
// The answer does not have to be entirely accurate
// reservoir sampling is to pick k elements from a stream with equal probability
public class TopValuesInDataStream {
     //-- a count min sketch is a bloom filter
    //-- you compute the  hash of the incoming value and detect duplicates
    //-- have k counters and eject values that are stale

    private int count = 0;
    private int majority = Integer.MIN_VALUE;
    public Integer Top(InputStream in) {

        try
        {
            String line;
            BufferedReader bufferedReader = new BufferedReader( new InputStreamReader( in ) );
            while( (line = bufferedReader.readLine()) != null )
            {
                if( count == 0){
                    majority = Integer.valueOf(line);
                }
                //-- the count will be incremented
                if(Integer.valueOf(line) == majority){
                    count +=1;
                } else {
                    count -=1;
                }
            }
        }
        catch( IOException e )
        {
            System.err.println( "Error: " + e );
        }

        return count > 0 ? majority : Integer.MIN_VALUE;
    }


}
