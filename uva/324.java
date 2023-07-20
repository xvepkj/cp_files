import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{        
		Scanner scanner = new Scanner(System.in);
        BigInteger[] fact=new BigInteger[367];
        int[] freq=new int[15];
        fact[1]=BigInteger.ONE;
        for(int i=2;i<=366;i++)
            fact[i]=fact[i-1].multiply(BigInteger.valueOf(i));
        while(scanner.hasNext()){
             Arrays.fill(freq, 0);
            int n=scanner.nextInt();
            if(n==0)break;
            String s=fact[n].toString();
            for(int i=0;i<s.length();i++)
                freq[s.charAt(i)-'0']++;
            System.out.printf("%d! --\n",n);
            for(int i=0;i<10;i++){
                System.out.printf("    (%d)     %d",i,freq[i]);
                if(i==4)System.out.println();
            }
            System.out.println();
        }
    }
}