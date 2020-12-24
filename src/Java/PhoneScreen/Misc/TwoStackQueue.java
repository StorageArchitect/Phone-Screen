package Misc;

import java.util.Stack;


//
//    The remove() and poll() methods remove and return the head of the queue.
//    The element() and peek() methods return, but do not remove, the head of the queue.
//

class myQueue<T> {

    private Stack<T> inStack = new Stack<>();
    private Stack<T> outStack = new Stack<>();

    //-- note the constructor does not get called

    boolean add(T element){
         return inStack.add(element);
    }

    T peek(){
        if(outStack.isEmpty() ) {
            while(!inStack.isEmpty()){
                outStack.push(inStack.pop());
            }
        }

        return outStack.peek();
    }

    T poll(){

        if(outStack.isEmpty() ) {
            while(!inStack.isEmpty()){
                outStack.push(inStack.pop());
            }
        }
        return outStack.pop();
    }


}



public class TwoStackQueue {

    public static void main(String[] args) {
        myQueue<Integer> q = new myQueue<>();
        for(int i = 0; i < 20; i++){
            q.add(i);
            System.out.println("head of the queue is " + q.peek());

        }

        System.out.println("retrive all items from the queue ");
        for(int i = 0; i < 20; i++){
            System.out.print( " " + q.poll());

        }
        System.out.println();

    }


}
