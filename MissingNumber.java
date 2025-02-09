import java.util.*;
public class MissingNumber {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n+1];
        for(int i=0;i<n-1;i++){
            int num=sc.nextInt();
            arr[num]=1;
        }
        int res=0;
        for(int i=1;i<n+1;i++){
            if(arr[i]==0){
                res=i;
                break;
            }
        }
        System.out.println(res);
    }
}
