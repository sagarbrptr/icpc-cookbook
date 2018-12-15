// matrix chain multiplication
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n 
int MatrixChainOrder(int p[], int n) 
{ /* For simplicity of the program, one extra row and one 
	extra column are allocated in m[][]. 0th row and 0th 
	column of m[][] are not used */
	int m[n][n]; 
	int i, j, k, L, q; 
/* m[i,j] = Minimum number of scalar multiplications needed 
	to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where 
	dimension of A[i] is p[i-1] x p[i] */
// cost is zero when multiplying one matrix. 
	for (i=1; i<n; i++) 
		m[i][i] = 0; 
// L is chain length. 
	for (L=2; L<n; L++) 
	{ 
		for (i=1; i<n-L+1; i++) { 
			j = i+L-1; 
			m[i][j] = INT_MAX; 
			for (k=i; k<=j-1; k++) {
				// q = cost/scalar multiplications 
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
				if (q < m[i][j]) 
					m[i][j] = q; } 
		} 
	} 

   return m[1][n-1]; 
} 
// bell no
//Let S(n, k) be total number of partitions of n elements into k sets. The value of n’th Bell Number is sum of S(n, k) for k = 1 to n.
int bellNumber(int n) 
{ 
   int bell[n+1][n+1]; 
   bell[0][0] = 1; 
   for (int i=1; i<=n; i++) 
   { 
      // Explicitly fill for j = 0 
      bell[i][0] = bell[i-1][i-1]; 
  
      // Fill for remaining values of j 
      for (int j=1; j<=i; j++) 
         bell[i][j] = bell[i-1][j-1] + bell[i][j-1]; 
   } 
   return bell[n][0]; 
} 
// subset sum
isSubsetSum(set, n, sum) = isSubsetSum(set, n-1, sum) || 
                           isSubsetSum(set, n-1, sum-set[n-1])
Base Cases:
isSubsetSum(set, n, sum) = false, if sum > 0 and n == 0
isSubsetSum(set, n, sum) = true, if sum == 0 
//rod cutting
Let cutRod(n) be the required (best possible price) value for a rod of length n. cutRod(n) can be written as following.

cutRod(n) = max(price[i] + cutRod(n-i-1)) for all i in {0, 1 .. n-1}
//LCS 
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + lcs(X, Y, m-1, n-1); 
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 
//
The longest common suffix has following optimal substructure property
   LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 if X[m-1] = Y[n-1]
                        0  Otherwise (if X[m-1] != Y[n-1])

The maximum length Longest Common Suffix is the longest common substring.
   LCSubStr(X, Y, m, n)  = Max(LCSuff(X, Y, i, j)) where 1 <= i <= m
                                                     and 1 <= j <= n
//Kadane
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far
//0-1 knapsack
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Base Case 
   if (n == 0 || W == 0) 
       return 0; 
  
   // If weight of the nth item is more than Knapsack capacity W, then 
   // this item cannot be included in the optimal solution 
   if (wt[n-1] > W) 
       return knapSack(W, wt, val, n-1); 
  
   // Return the maximum of two cases:  
   // (1) nth item included  
   // (2) not included 
   else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), 
                    knapSack(W, wt, val, n-1) 
                  ); 
}
//Egg-Droping
 k ==> Number of floors
  n ==> Number of Eggs
  eggDrop(n, k) ==> Minimum number of trials needed to find the critical
                    floor in worst case.
  eggDrop(n, k) = 1 + min{max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)): 
                 x in {1, 2, ..., k}}
//Partition Problem
Let isSubsetSum(arr, n, sum/2) be the function that returns true if 
there is a subset of arr[0..n-1] with sum equal to sum/2

The isSubsetSum problem can be divided into two subproblems
 a) isSubsetSum() without considering last element 
    (reducing n to n-1)
 b) isSubsetSum considering the last element 
    (reducing sum/2 by arr[n-1] and n to n-1)
If any of the above the above subproblems return true, then return true. 
isSubsetSum (arr, n, sum/2) = isSubsetSum (arr, n-1, sum/2) ||
                              isSubsetSum (arr, n-1, sum/2 - arr[n-1])
//Longest Palindromic Subsequence
// Every single character is a palindrome of length 1
L(i, i) = 1 for all indexes i in given sequence

// IF first and last characters are not same
If (X[i] != X[j])  L(i, j) =  max{L(i + 1, j),L(i, j - 1)} 

// If there are only 2 characters and both are same
Else if (j == i + 1) L(i, j) = 2  

// If there are more than two characters, and first and last 
// characters are same
Else L(i, j) =  L(i + 1, j - 1) + 2 
//Coin Change
To count the total number of solutions, we can divide all set solutions into two sets.
1) Solutions that do not contain mth coin (or Sm).
2) Solutions that contain at least one Sm.
Let count(S[], m, n) be the function to count the number of solutions, then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).
//LOngest repeating Subsequence
int findLongestRepeatingSubSeq(string X, int m, int n) 
{ 
    if(dp[m][n]!=-1) 
    return dp[m][n]; 
      
    // return if we have reached the end of either string 
    if (m == 0 || n == 0) 
        return dp[m][n] = 0; 
  
    // if characters at index m and n matches  
    // and index is different 
    if (X[m - 1] == X[n - 1] && m != n) 
        return dp[m][n] = findLongestRepeatingSubSeq(X,  
                            m - 1, n - 1) + 1; 
  
    // else if characters at index m and n don't match 
    return dp[m][n] = max (findLongestRepeatingSubSeq(X, m, n - 1),  
                           findLongestRepeatingSubSeq(X, m - 1, n)); 
} 
// job-scheduling
1) First sort jobs according to finish time.
2) Now apply following recursive process. 
   // Here arr[] is array of n jobs
   findMaximumProfit(arr[], n)
   {
     a) if (n == 1) return arr[0];
     b) Return the maximum of following two profits.
         (i) Maximum profit by excluding current job, i.e., 
             findMaximumProfit(arr, n-1)
         (ii) Maximum profit by including the current job            
   }
//L[0] = {job[0]}
L[i] = {MaxSum(L[j])} + job[i] where j < i and job[j].finish <= job[i].start
     = job[i], if there is no such j

