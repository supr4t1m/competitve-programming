```C++
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>

using namespace std;

bitset<15> rw;
bitset<29> ld, rd;

int n;
char board[30][30];
int ans;

void backtrack(int c) {
  if (c == n) { // valid placement of queens
    ans++;
    return;
  }

  for (int r=0; r<n; r++) {
    if (board[r][c] != '*' && !rw[r] && !ld[r+c] && !rd[n-1 + r-c]) {
      rw[r] = true; ld[r+c] = true; rd[n-1 + r-c] = true;
      backtrack(c+1);
      rw[r] = false; ld[r+c] = false; rd[n-1 + r-c] = false;
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int caseNo = 1;
  
  while (cin >> n && n) {
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
	cin >> board[i][j];

    ans = 0;
    rw.reset(); ld.reset(); rd.reset(); // reset the bit sets
    
    backtrack(0);
    cout << "Case " << caseNo << ": " << ans << endl;
    caseNo++;
  }
  
  return 0;
}
```
