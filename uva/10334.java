import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{

        BigInteger[] f=new BigInteger[1005];
        f[0]=BigInteger.valueOf(1);
        f[1]=BigInteger.valueOf(2);
        for(int i=2;i<=1000;i++){
            f[i]=f[i-1].add(f[i-2]);
        }
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
            int x=scanner.nextInt();
            System.out.println(f[x]);
        }
	}
}