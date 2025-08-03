```cpp
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, n1, m, t;
int cust[20];
vector<pair<set<int>, int>> csa;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int caseNo = 0;

  
  while (cin >> n >> n1 && (n||n1)) {
    int ans = 0;
    int locationBits = 0;
    caseNo++;
    for (int i=0; i<n; i++)
      cin >> cust[i];

    cin >> m;

    for (int i=0; i<m; i++) {
      cin >> t;
      set<int> s;
      int temp;
      while (t--) {
	cin >> temp;
	s.insert(temp);
      }

      cin >> temp;
      csa.push_back(make_pair(s, temp));
    }

    // algorithm to solve the problem
    for (int i=0; i<(1<<n); i++) {
      int coverage = 0;
      int setbits = 0;

      for (int j=0; j<n; j++)
	if (i & (1<<j))
	  setbits++;

      if (setbits != n1)
	continue;

      for (int j=0; j<n; j++) {
	if (i & (1<<j)) {

	  coverage += cust[j];
	}
      }

      // inclusion-exclusion principle
      for (const auto& p: csa) {
	int numTowers = 0;

	for (int j: p.first) {
	  if (i & (1<<(j-1)))
	    numTowers++;
	}

	if (numTowers > 1)
	  coverage -= (numTowers - 1)*p.second;
      }

      if (coverage > ans) {
	ans = coverage;
	locationBits = i;
      }
    }

    cout << "Case Number  " << caseNo << endl;
    cout << "Number of Customers: " << ans << endl;
    cout << "Locations recommended:";

    for (int j=0; j<n; j++)
      if (locationBits & (1<<j))
	cout << " " << (j+1);
    cout << endl;

    cout << endl;

    csa.clear();
  }
}
```
