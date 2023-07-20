import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		int t=scanner.nextInt();
		while(t-->0){
			String a=new StringBuffer(scanner.next()).reverse().toString();
			String b=new StringBuffer(scanner.next()).reverse().toString();
		  	BigInteger x=new BigInteger(a);
		  	BigInteger y=new BigInteger(b);
		  	y=y.add(x);
		  	String c= new StringBuffer(y.toString()).reverse().toString(); 
		  	BigInteger z=new BigInteger(c);
		  	System.out.println(z);
		}
	}
}