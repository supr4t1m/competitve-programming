```C++
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int row[8], n, a, b, linenumber;

bool place(int r, int c) {

  for (int prev=0; prev<c; prev++)
    if (row[prev] == r || abs(r-row[prev]) == abs(c-prev))
      return false;
  
  return true;
}

void backtrack(int c) {
  if (c == 8 && row[b] == a) {
    linenumber++;
    cout << setw(2) << linenumber << "     ";
    for (int r: row) {
      cout << " " << r+1;
    }
    cout << endl;
  }

  for (int r=0; r<8; r++) {
    if (place(r, c)) {
      row[c] = r;
      backtrack(c+1);
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cin >> n;
  bool first = true;

  while (n-- > 0) {
    if (!first) cout << endl;
    if (first) first = false;
    cin >> a >> b;
    a--; b--;
    linenumber = 0;
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl;
    cout << endl;
    
    backtrack(0);
  }

  return 0;
}
```
