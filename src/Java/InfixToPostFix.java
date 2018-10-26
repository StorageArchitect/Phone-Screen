package PhoneScreen;


import java.util.Stack;


public class InfixToPostFix {

  static int getPrecedence(char checkChar) {
            if(checkChar=='+'||checkChar=='-')
                return 1;
            if(checkChar=='*'||checkChar=='/')
                return 2;
            if(checkChar=='('||checkChar==')')
                return 0;
            return -1;
  }


  public static void main(String[] args) {
            Stack<Character> stack=new Stack();
            String result="";
            String inputStr= "(a + b) * (c + d)/ 2";
            char[] inputCharArray=inputStr.toCharArray();

            for(int i= 0 ;i < inputCharArray.length; i++) {
                char checkChar = inputCharArray[i];
                if( checkChar!= '+' && checkChar!= '-' &&
                        checkChar != '/' && checkChar != '*' &&
                        checkChar != '(' && checkChar != ')' ) {
                    result += checkChar;
                } else {
                    if( checkChar!= '(' && checkChar!= ')') {
                        if(stack.isEmpty()) {
                            stack.push(checkChar);
                        } else {
                            while(getPrecedence(stack.peek()) >= getPrecedence(checkChar))   {
                                result= result + stack.pop();
                                if(stack.isEmpty())
                                    break;
                            }
                            stack.push(checkChar);
                        }
                    } else {
                        if(checkChar=='(') {
                            stack.push(checkChar);
                        } else {
                            while(stack.peek()!='(') {
                                result= result + stack.pop();
                            }
                            stack.pop();
                        }
                    }
                }
            }
            while(!stack.isEmpty())
                result= result + stack.pop();

            System.out.print(result);
        }
}

