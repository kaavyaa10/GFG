//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine().trim());

        Solution solution = new Solution();
        while (t-- > 0) {
            String input = reader.readLine().trim();
            String[] parts = input.split("\\s+");
            int[] arr = Arrays.stream(parts).mapToInt(Integer::parseInt).toArray();

            System.out.println(solution.findMissing(arr));

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


// User function Template for Java

class Solution {
    public int findMissing(int[] arr) {
        // code here
         int n = arr.length;
        int d = arr[1]-arr[0];
        if((2*arr[0]+(n-1)*d)!=(arr[0]+arr[n-1]))
        {
            d=(arr[n-1]-arr[0])/n;
        }
        // common difference

       

int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int expected = arr[0] + mid * d;

            if (arr[mid] == expected) {
                // No mismatch yet, go right
                low = mid + 1;
            } else {
                // Found mismatch, go left to find first occurrence
                high = mid - 1;
            }
        }

        // Either missing element at position `low`, or array is complete
        return arr[0] + low * d;
        
    }
}
