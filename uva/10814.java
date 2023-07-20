import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt(); 
		while (N-- > 0) {
		BigInteger p = scanner.nextBigInteger(); 
		String ch = scanner.next();
		BigInteger q = scanner.nextBigInteger(); 
		BigInteger gcd_pq = p.gcd(q); 
		System.out.println(p.divide(gcd_pq) + " / " + q.divide(gcd_pq)); 
	}
	}
}