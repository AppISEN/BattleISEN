
/****************************************************************
/***/
/***/
/** SOLUTION BY MaxHeap*/
/***/
/***/
/********************************************************************/
/*******
 * Read input from System.in
 * Use: System.out.println to ouput your result to STDOUT.
 * Use: System.err.println to ouput debugging information to STDERR.
 * ***/
import java.util.*;

public class main {
    static int[] cal1, prix1, cal2, prix2;
    static int n, m, cap;
    static Integer[][] dp;
    static int compute(int index, int capacity) {
        if(index > n + m - 1) {
            return 0;
        }
        if(dp[index][capacity] != null) {
            return dp[index][capacity];
        }
        int best = 0;
        if(index < n) {
            best = Math.max(best, compute(index + 1, capacity));
            if(capacity - prix1[index] >= 0) {
                best = Math.max(best, compute(index + 1, capacity - prix1[index]) + cal1[index]);
            }
        }else {
            best = Math.max(best, compute(index + 1, capacity));
            int curIndex = index - n;
            for(int i = 1; i <= Math.min(prix2[curIndex], capacity); ++i) {
                best = Math.max(best, compute(index + 1, capacity - i) + i * cal2[curIndex]);
            }
        }
        return dp[index][capacity] = best;
    }
    
    public static void main( String[] argv ) throws Exception {
		Scanner in = new Scanner(System.in);
		n = in.nextInt();
		m = in.nextInt();
		cap = in.nextInt();
		cal1 = new int[n];
		prix1 = new int[n];
		cal2 = new int[m];
		prix2 = new int[m];
		dp = new Integer[n + m + 1][cap + 1];
		
		for(int i = 0; i < n; ++i) {
		    cal1[i] = in.nextInt();
		    prix1[i] = in.nextInt();
		}
		for(int i = 0; i < m; ++i) {
		    cal2[i] = in.nextInt();
		    prix2[i] = in.nextInt();
		}
        System.out.println(compute(0, cap));
	}
}

