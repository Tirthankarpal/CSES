import java.util.*;
public class Repetition {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s1=sc.next();
        int res=0;
        int count=1;
        for(int i=0;i<s1.length()-1;i++){
            if(s1.charAt(i)==s1.charAt(i+1)){
                count++;
            }
            else{
                res=Math.max(res,count);
                count=1;
            }
        }
        res=Math.max(res,count);
        System.out.println(res);
    }
}
