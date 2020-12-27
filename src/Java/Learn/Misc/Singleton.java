package Misc;

public class Singleton {
    private static volatile Singleton instance;

    private void Singleton() {};

    public static  Singleton getInstance() {

        if(instance == null){
            synchronized (Singleton.class) {
                if(instance == null){
                    return new Singleton();
                }
            }
        }
        return instance;
    }

    public static int getSingletonVal() {

        return 99134232;
    }

    public static void main(String[] args) {
        Singleton s = new Singleton();

        System.out.println("Get a singleton instance ");
        s = getInstance();
        System.out.println("This instance has value " + s.getSingletonVal() );
    }
}
