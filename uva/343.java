import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		Scanner scanner = new Scanner(System.in);
		while(scanner.hasNext()){
			String a=scanner.next();
			String b=scanner.next();
			Boolean found=false;
			BigInteger x,y;
			for(int i=1;i<=36 && !found;i++){
					try{x=new BigInteger(a,i);}
					catch(Exception e){continue;}
				for(int j=1;j<=36 && !found;j++){
					try{y=new BigInteger(b,j);}
					catch(Exception e){continue;}
					if(x.compareTo(y)==0){
						found=true;
						System.out.println(a + " (base " + i + ") = " + b + " (base " + j + ")");
					}
				}
			}
			if(!found)System.out.println(a + " is not equal to " + b + " in any base 2..36");
		}
	}
}