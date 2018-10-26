package PhoneScreen;

import java.util.Stack;

/*******
 * given an input string write a function to determine if the input string contains matching parantheses
 *
 */
public class MatchingParantheses {

    static char[][] pattern = { {'[',']'}, {'(', ')'}, {'<','>'}, {'{','}'}};

    static boolean isOpenTerm(char c){
        switch(c){
            case '[':
            case '{':
            case '<':
            case '(':
               return true;
            default:
                return false;
        }

    }

    static boolean isCloseTerm(char c){
        switch(c){
            case ']':
            case '}':
            case '>':
            case ')':
                return true;
            default:
                return false;
        }
    }

    static boolean isMatched(char open, char close){
        for(int row= 0; row < 4; row++){
            if(pattern[row][0] == open){
                return pattern[row][1] == close ? true: false;
            }
        }
        return false;
    }

    static void isBalanced(String s) {
        char[] cArray = s.toCharArray();
        Stack<Character> myStack = new Stack<Character>();
    //--  break up the string into array of char
    //-- for each element check if it belongs to a list of items in th pattern
    //-- if it is open term push it into stack
    //-- if it is a close term pop the entry from the stack and see if they balance
    //--- at the end if there are remaining entries in a stack then it is unbalanced
        for(int i = 0; i < s.length(); i++){
            if(isOpenTerm(cArray[i]) == true){
                myStack.push(cArray[i]);
            } else if(isCloseTerm(cArray[i]) == true){
                if(myStack.isEmpty()){
                    System.out.println("The string " + s + " is not balanced");
                    return ;
                }
                if(isMatched(myStack.pop(), cArray[i]) == false){
                    System.out.println("The string " + s + " is not balanced");
                    return;
                }
            }
        }

        if(myStack.isEmpty()){
            System.out.println("The string " + s + "is balanced" );
        } else {
            System.out.println("The string " + s + " is not balanced");
        }
    }

    public static void main(String[] args) {
        String s1 = "()";
        String s2 = "})([unbalanced)";
        String s3 = "([balanced<is>])";
        String s4 = "({am it <balancded[or]not>pls})";
        System.out.println("Validate strings to see if parentheses are balanced " );
        isBalanced(s1);
        isBalanced(s2);
        isBalanced(s3);
        isBalanced(s4);
    }
}
