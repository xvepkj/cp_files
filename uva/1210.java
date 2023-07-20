import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		int primes[]=new int[10000];
		int ans[]=new int[10001];
		int noofprimes=0;
		for(int i=2;i<=10000;i++)
		{	
			BigInteger x = BigInteger.valueOf(i);
			if(x.isProbablePrime(10))
				primes[noofprimes++]=i;
		}
		for(int i=0;i<noofprimes;i++){
			int temp=0;
			for(int j=i;j<noofprimes;j++){
				temp+=primes[j];
				if(temp>10000)break;
				ans[temp]++;
			}
		}
		while (true) { 
		 	int n=scanner.nextInt();
		 	if(n==0)break;
		 	System.out.println(ans[n]);
		}
	}
}