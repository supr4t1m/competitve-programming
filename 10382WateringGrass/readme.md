```C++
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

const double EPS = 1e-9;

struct sprinkler {
  int c, r;
  double x_l, x_r;
};

struct sprinkler sp[10010];

int n, l, w;


int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  while (cin >> n >> l >> w) {
    for (int i=0; i<n; i++) {
      cin >> sp[i].c >> sp[i].r;

      if (2*sp[i].r >= w) {
	double dx = sqrt((double)sp[i].r*sp[i].r - (w/2.0)*(w/2.0));
	sp[i].x_l = sp[i].c-dx;
	sp[i].x_r = sp[i].c+dx;
      } else { // it doesn't completely cover any grass strip
	// making the range span 0
	sp[i].x_l = sp[i].c;
	sp[i].x_r = sp[i].c;
      }
    }

    bool possible = true;
    double covered = 0.0;
    int ans = 0;

    sort(sp, sp+n, [](struct sprinkler sp1, struct sprinkler sp2) -> bool {
      if (fabs(sp1.x_l - sp2.x_l) > EPS)
	return sp1.x_l < sp2.x_l;
      else
	return sp1.x_r > sp2.x_r;
    });

    for (int i=0; (i<n) && possible; i++) {
      if (covered > l) break;
      if (sp[i].x_r < covered + EPS) continue;
      if (sp[i].x_l < covered + EPS) {

	double max_x_r = -1.0;
	int max_idx=i;

	for (int j=i; (j<n) && (sp[j].x_l<covered+EPS); j++)
	  if (sp[j].x_r > max_x_r+EPS) {
	    max_x_r = sp[j].x_r;
	    max_idx = j;
	  }

	ans++;
	covered = max_x_r;
	i = max_idx;
      } else {
	possible = false;
      }
    }

    if (!possible || (covered<l))
      cout << -1 << endl;
    else
      cout << ans << endl;
  }

  return 0;
}
```
