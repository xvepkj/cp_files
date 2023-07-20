import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
			BigInteger x=scanner.nextBigInteger();
			if(x.compareTo(BigInteger.ZERO)==0)
				break;
			if((x.mod(BigInteger.valueOf(17))).compareTo(BigInteger.ZERO)==0)
				System.out.println(1);
			else 
				System.out.println(0);
		}
	}
}