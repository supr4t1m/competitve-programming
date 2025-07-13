```C++
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MODULO int(1e6)

int dp[101][101];


int ways(int n, int k) {
  /* There is only one way to have sum of n with 1 element
   * the element 1 itself.
   */
    
  if (k == 1)
    return dp[n][1] = 1;

  
  if (dp[n][k] != -1)
    return dp[n][k];

  int ans = 0;

  /* otherwise we take one number of value i
   * and find out the ways to get sum of (n-i)
   * with one less element than we have currently.
   * we do this for all i from 0 to n.
   */
  for (int i=0; i<=n; i++) {
    ans = ans%MODULO + ways(n-i, k-1)%MODULO;
    ans = ans%MODULO;
  }

  return dp[n][k] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  
  int n, k;
  
  
  while (cin >> n >> k && (n || k)) {
    for (int i=0; i<101; i++)
      memset(dp[i], -1, 101*sizeof(int));
    
    cout << ways(n, k) << endl;
  }
  
  return 0;
}
```
