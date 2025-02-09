import java.util.*;
public class WeirdAlgorithm {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextInt();
        while(n!=1){
            if(n%2==1){
                System.out.print(n+" ");
                n=3*n+1;
            }
            else{
                System.out.print(n+" ");
                n=n/2;
            }
        }
        System.out.print(n+" ");
    }
}
