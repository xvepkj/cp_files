import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{        
		Scanner scanner = new Scanner(System.in);
        BigInteger[] cat=new BigInteger[301];
        BigInteger x=BigInteger.ONE;
        cat[0]=BigInteger.ONE;
        for(int i=1;i<=300;i++)
                cat[i]=(cat[i-1].multiply(BigInteger.valueOf(2*(2*i-1)))).divide(BigInteger.valueOf(i+1));
        for(int i=1;i<=300;i++){
            x=x.multiply(BigInteger.valueOf(i));
            cat[i]=cat[i].multiply(x);
        }
		while(true){
            int n=scanner.nextInt();
            if(n==0)break;
            System.out.println(cat[n]);
        }
	}
}