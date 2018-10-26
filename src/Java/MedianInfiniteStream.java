package PhoneScreen;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

//inspired by ttps://research.neustar.biz/2013/09/16/sketch-of-the-day-frugal-streaming/
public class MedianInfiniteStream {

    Integer median_est = 0;
    public Integer median(InputStream in) {

        try
        {
            String line;
            BufferedReader bufferedReader = new BufferedReader( new InputStreamReader( in ) );
            while( (line = bufferedReader.readLine()) != null )
            {
                if(Integer.valueOf(line) > median_est){
                    median_est +=1;
                } else if(Integer.valueOf(line) < median_est){
                    median_est -=1;
                }
            }
        }
        catch( IOException e )
        {
            System.err.println( "Error: " + e );
        }

        return median_est;
    }

     public Integer getMedianEstimate(){
        return median_est;
    }

}

