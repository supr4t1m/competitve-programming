```C++
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

char grid[100][100];

//          S SE  E  NE   N  NW   W  SW
int dr[] = {1, 1, 0, -1, -1, -1,  0,  1};
int dc[] = {0, 1, 1,  1,  0, -1, -1, -1};

int R, C, k;

int floodfill(int r, int c, char c1, char c2) {
  if (r < 0 || r >= R || c < 0 || c >= C) {
    return 0;
  }

  if (grid[r][c] != c1)
    return 0;

  grid[r][c] = c2;
  int ans = 1;

  for (int d=0; d<8; d++) {
    ans += floodfill(r+dr[d], c+dc[d], c1, c2);
  }

  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  
  int t;
  int r, c;

  char local_grid[100][100];
  
  string s;

  bool first = true;

  cin >> t;

  getline(cin, s);
  getline(cin, s);

  while (t-- > 0) {
    R = 0;
    C = 0;

    if (!first) cout << endl;
    if (first) first = false;
    
    while (getline(cin, s) && !s.empty()) {

      if (s[0] == 'W' || s[0] == 'L') {
	C = s.length();

	for (int i=0; i<C; i++) {
	  local_grid[R][i] = s[i];
	}
	R++;
      } else {
		
	r = atoi(&s[0]);
	c = atoi(&s[2]);
	r--; c--;

	// initialize or restore the global copy
	// after it has been modified

	for (int i=0; i<R; i++)
	  for (int j=0; j<C; j++)
	    grid[i][j] = local_grid[i][j];
	
	cout << floodfill(r, c, 'W', '.') << endl;
      }
    }
  }
  
  return 0;
}
```
