```C++
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

int n, l;
int a[52];

int dp[52][52];

int cut(int left, int right) {
  /* base case:
   * if right = left + 1, i.e. if the cuts are
   * adjacent, return A[right]
   */
  if (right == left + 1)
    return 0;

  if (dp[left][right] != -1)
    return dp[left][right];

  /* explore the complete search space
   */
  int ans = INT_MAX;

  for (int i=left+1; i<right; i++) {
    ans = min(ans, cut(left, i) + cut(i, right) + a[right]-a[left]);
  }

  return dp[left][right] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  
  while (cin >> l && l && cin >> n) {
    for (int i=1; i<=n; i++)
      cin >> a[i];
    a[0] = 0; a[n+1] = l;

    for (int i=0; i<=51; i++)
      memset(dp[i], -1, 52*sizeof(int));

    cout << "The minimum cutting is " << cut(0, n+1) << "." << endl;
  }
  
  return 0;
}
```
