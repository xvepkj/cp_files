import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
			String a=scanner.next();
			int b=scanner.nextInt();
			int c=scanner.nextInt();
			BigInteger x = new BigInteger(a,b);
			String ans=x.toString(c).toUpperCase();
			if(ans.length()>7)ans="ERROR";
			int rem=7-ans.length();
			while(rem-->0)System.out.print(" ");
			System.out.println(ans);
		}
	}
}