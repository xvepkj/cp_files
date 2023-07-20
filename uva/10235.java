import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext()) { 
			int N = scanner.nextInt(); 
			BigInteger BN = BigInteger.valueOf(N); 
			String R = new StringBuffer(BN.toString()).reverse().toString(); 
			int RN = Integer.parseInt(R);
			BigInteger BRN = BigInteger.valueOf(RN); 
			System.out.printf("%d is ", N);
			if (!BN.isProbablePrime(10)) 
				System.out.println("not prime."); 
			else if (N != RN && BRN.isProbablePrime(10)) 
				System.out.println("emirp."); 
			else System.out.println("prime."); 
		}
	}
}