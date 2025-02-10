import java.util.*;
public class PalindromeReorder {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        HashMap<Character,Integer> map=new HashMap<>();
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            if(map.containsKey(ch))map.put(ch,map.get(ch)+1);
            else map.put(ch,1);
        }
        StringBuilder sb=new StringBuilder();
        StringBuilder mid=new StringBuilder();
        for(char ch:map.keySet()){
            int num = map.get(ch);
            int f = num / 2;
            int mod = num % 2;
            for (int l = 0; l < f; l++) {
                sb.append(ch);
            }
            if (mod == 1) {
                mid.append(ch);
                if(mid.length()>1){
                    System.out.println("NO SOLUTION");
                    return;
                }
            }
        }
        System.out.println(sb.toString()+mid.toString()+sb.reverse().toString());
    }
}
