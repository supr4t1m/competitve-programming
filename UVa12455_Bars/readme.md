```C++
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int b[20];

bool dfs(int depth, int p, int n, int curr_sum) {

  if (curr_sum == n)
    return true;

  bool ans = false;

  // explore all the bars from index i to p-1
  for (int i=depth+1; i<=p; i++)
    ans = ans || dfs(i, p, n, curr_sum + b[i-1]);

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
#endif

  int t, n, p;

  cin >> t;

  while (t--) {
    cin >> n >> p;

    for (int i=0; i<p; i++) {
      cin >> b[i];
    }

    cout << (dfs(0, p, n, 0)?"YES":"NO") << endl;
  }
}
```
