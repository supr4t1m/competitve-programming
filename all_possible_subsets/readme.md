__Problem__: Generate all possible subsets of $$\\{ 0, 1, 2, . . . , N-1 \\}$$, for $$N = 20$$

```C++
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

void solve(int n) {
  queue<vector<int>> q; // using a queue to save the state
  // of the outer loop, so that we can use it to determine
  // state of the inner loop

  for (int i=0; i<n; i++) {
    q.push(vector<int>(1, i));
  }

  while (!q.empty()) {
    vector<int> curr = q.front();
    q.pop();

    for (int a: curr) {
      cout << a << " ";
    }
    
    cout << endl;
    
    int m = curr.size();

    for (int i = curr[m-1]+1; i<n; i++) {
      curr.push_back(i);
      q.push(vector<int>(curr)); // using a copy constructor to copy contents
      // instead of copying reference
      // utilizing reuse of the curr vector
      curr.pop_back();
    }
  }
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  #endif
  int n;
  while (cin >> n) {
    solve(n);
    cout << endl;
  }
}
```
