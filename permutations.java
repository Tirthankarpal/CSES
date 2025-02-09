import java.util.*;
public class permutations {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        StringBuffer output = new StringBuffer();
        if(n==1) System.out.println(1);
        else if(n<4) System.out.println("NO SOLUTION");
        else{
            int odd=1;
            int even=0;
            for(int i=0;i<n;i++){
                if(odd>=n){
                    output.append(n-even).append(" ");
                    even+=2;
                }
                else{
                    output.append(n-odd).append(" ");
                    odd+=2;
                }
            }
            System.out.println(output.toString());
        }
    }
}
