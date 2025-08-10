```Cpp
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>

int perm[8];
int m[8][8];

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t, n;

  cin >> t;

  while (t-- > 0) {
    cin >> n;

    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
	cin >> m[i][j];

    for (int i=0; i<n; i++)
      perm[i] = i;

    int ans = 64001;

    do {
      int total = 0;

      for (int i=0; i<n; i++)
	      total += m[i][perm[i]];

/* the final result doesn't depend on Alice's play at all.
 * Since Bob will determine the column number. If both the
 * players play optimally, the final result will be the
 * minimum the permutation sum, since Bob knows Alice
 * eventually has to choose a row.
 */
      ans = min(ans, total);
    } while (next_permutation(perm, perm+n));

    cout << ans << endl;
  }
  
  return 0;
}
```
