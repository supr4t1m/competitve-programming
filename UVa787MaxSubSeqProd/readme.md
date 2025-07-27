```Java

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    
    public static final String INPUT = "input.txt";
    public static final String OUTPUT = "output.txt";
    public static final int nums[] = new int[100];
    // used to store cumulative product
    public static final BigInteger A[] = new BigInteger[100];
    // used to keep track of the next zero index for index i
    public static final int zero_idx[] = new int[100]; 
    public static int n;
    
    
    private static void ioRedirect() {
        FileInputStream input = null;
        PrintStream output = null;
        
        try {
            input = new FileInputStream(INPUT);
            output = new PrintStream(new FileOutputStream(OUTPUT));
            
            System.setIn(input);
            System.setOut(output);
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    
    public static void main(String[] args) {
        
//         uncomment while debugging
//        ioRedirect();
        
        BigInteger ans;
        
        Scanner sc = new Scanner(System.in);
        
        while(sc.hasNext()) {
            int num = 0;
            n = 0;
            ans = BigInteger.valueOf(Long.MIN_VALUE*Long.MAX_VALUE);
            while (num != -999999) {
                num = sc.nextInt();
                
                if (num != -999999)
                    nums[n++] = num;
            }
            
            int idx = n;
            for (int i=n-1; i>=0; i--) {
                zero_idx[i] = idx;
                
                if (nums[i] == 0) {
                    idx = i;
                }
            }
            
            A[0] = BigInteger.valueOf(nums[0]);
                
            for (int i=1; i<n; i++) {
                // if the previous cumulative product was not zero
                // continue multiplying, else restart the product
                // from the current number
                if (A[i-1].compareTo(BigInteger.ZERO) != 0)
                    A[i] = BigInteger.valueOf(nums[i]).multiply(A[i-1]);
                else
                    A[i] = BigInteger.valueOf(nums[i]);
            }
            
            // explore all possible pairs
            for (int j=0; j<n; j++) {
                for (int i=0; i<=j; i++) {
                    BigInteger temp = rsp(i, j);
                    if (temp.compareTo(ans) > 0)
                        ans = temp;
                }
            }
            
            System.out.println(ans);
        }
        
    }
    
    private static BigInteger rsp(int i, int j) {
        if (i == 0) {
            if (zero_idx[0] <= j)
                return BigInteger.ZERO;
            
            if (nums[0] == 0)
                return BigInteger.ZERO;
            
            return A[j];
        }
        
        if (zero_idx[i-1] <= j)
            return BigInteger.ZERO;
        
        if (nums[i-1] == 0)
            return BigInteger.ZERO;
        
        return A[j].divide(A[i-1]);
    }
}
```
