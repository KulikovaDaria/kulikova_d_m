import java.io.IOException;

public class Main {
    public static void main(String[] args) {
        try{
            if(args.length != 2) {
                throw new IOException("Number of arguments is not 2");
            }
            Integer a = Integer.parseInt(args[0]);
            Integer b = Integer.parseInt(args[1]);
            System.out.println(a + b);
        }
        catch(IOException exp){
            System.out.println(exp.getMessage());
        }
    }
}
