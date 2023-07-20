import java.lang.*;
import java.util.*;
import java.math.*;
public class Main{
	public static void main(String[] args) 
	{
		// Scanner scanner = new Scanner(System.in);
		BigInteger[] fib = new BigInteger[500];
        fib[0] = BigInteger.ONE;
        fib[1] = new BigInteger("2");
        for (int i = 2; i < 500; i++)
            fib[i] = fib[i - 1].add(fib[i - 2]);
        Scanner scan = new Scanner(System.in);
        StringBuilder builder = new StringBuilder();
        while (true) {
            String num1 = scan.next(), num2 = scan.next();
            BigInteger int1 = BigInteger.ZERO, int2 = BigInteger.ZERO;
            int i = 0, l = num1.length();
            while (i < l) {
                if (num1.charAt(l - i - 1) == '1')
                    int1 = int1.add(fib[i]);
                i++;
            }
            i = 0;
            l = num2.length();
            while (i < l) {
                if (num2.charAt(l - i - 1) == '1')
                    int2 = int2.add(fib[i]);
                i++;
            }
            int1 = int1.add(int2);
            String result = "";
            if (int1.compareTo(BigInteger.ZERO) == 0) {
                result = "0";
            }
            i = 0;
            for (int j = 499; j >= 0; j--) {
                if (int1.compareTo(fib[j]) >= 0) {
                    result = result + "1";
                    i = 1;
                    int1 = int1.subtract(fib[j]);
                } else if (i == 1)
                    result = result + "0";
            }
            builder.append(result);
            builder.append("\n");
            if (scan.hasNext()) {
                builder.append("\n");
            } else
                break;
        }
        System.out.print(builder.toString());
	}
}