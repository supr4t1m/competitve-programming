```C++
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int a[21], b[21], c[21];
int position[9];

int satisfy(int i) {
  if (c[i] > 0) {
    return (abs(position[a[i]]-position[b[i]]) <= c[i]);
  } else {
    return (abs(position[a[i]]-position[b[i]]) >= -c[i]);
  }
}

int dfs(int depth, int n, int m) {
  if (depth == n) { // if we have explored all the positions
    // either count the node or don't
    for (int i=0; i<m; i++) {
      if (!satisfy(i)) {
	return 0;
      }
    }

    return 1;
  }

  int ans = 0;

  // count the number of valid child nodes under it
  for (int i=0; i<n; i++) {
    if (!position[i]) { // if ith position isn't explored yet
      position[i] = depth + 1;
      ans += dfs(depth+1, n, m);
      position[i] = 0; // leave it open for subsequent exploration
    }
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n, m;
  
  while (cin >> n >> m && (n || m)) {

    for (int i=0; i<m; i++) {
      cin >> a[i] >> b[i] >> c[i];
    }
    cout << dfs(0, n, m) << endl;
  }

  return 0;
}
```
