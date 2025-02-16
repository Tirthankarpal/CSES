import java.util.*;
public class MissingCoinSum {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=sc.nextInt();
        }
        Arrays.sort(arr);
        long res=1;
        for(int i=0;i<n;i++){
            if(res>=arr[i]){
                res+=arr[i];
            }
            else{
                break;
            }
        }
        System.out.println(res);
    }
}
