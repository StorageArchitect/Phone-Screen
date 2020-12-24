package Misc;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

//Refrence https://efficientcodeblog.wordpress.com/2017/12/13/bidirectional-search-two-end-bfs/
//inspired by https://www.programcreek.com/2012/12/leetcode-word-ladder/
public class WordLadderTwoEndBFS {

    public static int ladderLengthLarge(String beginWord, String endWord,  Set <String> dict ) {
        //-- create a large number of data structures hence Large foot print
        int distance = 0;
        if (!dict.contains(endWord)) {
            return distance;
        }
        Set <String> sourceQueue = new HashSet();
        Set <String> targetQueue = new HashSet();
        Set visited = new HashSet();

        sourceQueue.add(beginWord);
        targetQueue.add(endWord);

        for (int len = 2; !sourceQueue.isEmpty(); len++) {

            Set transformedWordList = new HashSet();

            for (String w : sourceQueue) {

                for (int j = 0; j < w.length(); j++) {

                    char[] ch = w.toCharArray();

                    for (char c = 'a'; c <= 'z'; c++) {

                        // continue when you get the parent word back
                        if (c == w.charAt(j)) continue;
                        ch[j] = c;
                        String transformedWord = String.valueOf(ch);

                        if (targetQueue.contains(transformedWord)) {
                            return len; // meet from two ends; so return
                        }

                        if (dict.contains(transformedWord) && visited.add(transformedWord)) {
                            transformedWordList.add(transformedWord);
                        }
                    }
                }
            }

            // always traverse the smaller one
            // BASICALLY IN EVERY ITERATION WE ARE TRYING
            // TO ALTERNATE BETWEEN SOURCE QUEUE & TARGET QUEUE
            sourceQueue = (transformedWordList.size() < targetQueue.size())
                    ? transformedWordList
                    : targetQueue;

            targetQueue = (sourceQueue == transformedWordList)
                    ? targetQueue
                    : transformedWordList;

        }

        return distance;

    }

    public static int ladderLengthSmall(String beginWord, String endWord,  Set <String> dict ) {
        //-- create a minimal number of data structures hence small foot print
        if (!dict.contains(endWord)) {
            return 0;
        }

        int pathLength = 2;

        Set <String> startQ = new HashSet();
        Set <String> endQ = new HashSet();

        startQ.add(beginWord);
        endQ.add(endWord);
        dict.remove(beginWord);
        dict.remove(endWord);

        while(!startQ.isEmpty()){
            //-- swap the two queues to balance
            if(startQ.size() > endQ.size()){
                Set tempQ = startQ;
                startQ = endQ;
                endQ = tempQ;
            }
            Set nextQ = new HashSet();
            for(String cur : startQ){
                char[] strArray = cur.toCharArray();
                for(int i = 0; i < strArray.length;i++){
                    char old = strArray[i];
                    for(char c = 'a';c <= 'z';c++){
                        strArray[i] = c;
                        String str = String.valueOf(strArray);
                        if(endQ.contains(str)){
                            return pathLength;
                        }
                        if(dict.contains(str)){
                            nextQ.add(str);
                            dict.remove(str);
                        }
                    }
                    strArray[i] = old;
                }
            }
            startQ = nextQ;
            pathLength++;
        }
        return 0;
    }



    public static void main(String[] args) {

        List<String> list = Arrays.asList(new String[] {"hot","dot","dog","lot","log","cog"} );
        Set <String> dict = new HashSet<>();
        String beginWord = "hit";
        String endWord = "cog";
        dict.addAll(list);
        System.out.println("The minimum distance between the two words using Large Foot Print is " +
                ladderLengthLarge(beginWord, endWord, dict ));

        System.out.println("The minimum distance between the two words using Small Foot Print is " +
                    ladderLengthSmall(beginWord, endWord, dict));
    }

}
