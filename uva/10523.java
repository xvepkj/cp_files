import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
			int n=scanner.nextInt();
			int a=scanner.nextInt();
		  	BigInteger x=BigInteger.valueOf(a);
		  	BigInteger sum = BigInteger.ZERO;
		  	for(int i=1;i<=n;i++){
		  		BigInteger y=BigInteger.valueOf(i);
		  		sum=sum.add((x.pow(i)).multiply(y));
		  	}
		  	System.out.println(sum);
		}
	}
}