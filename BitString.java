import java.util.*;
public class BitString {
    public static int num(long n){
        if(n==0)return 1;
        return (2*num(n-1))%1000000007;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextInt();
        System.out.println(num(n));
    }
}
