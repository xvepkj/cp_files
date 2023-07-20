import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		int c=scanner.nextInt();
		while(c-->0){
			BigInteger x=BigInteger.valueOf(scanner.nextInt());
			BigInteger y=BigInteger.valueOf(scanner.nextInt());
			BigInteger n=BigInteger.valueOf(scanner.nextInt());
			System.out.println(x.modPow(y,n));
		}
	}
}