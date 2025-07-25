```C++
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

#define VISITED 1
#define UNVISITED -1

vector<int> dfs_num(100, UNVISITED);
vector<int> new_dfs_num(100, UNVISITED);

int adjMat[100][100];
char dominator[100][100];

int n, t;

void dfs(int u, int d, vector<int>& local_dfs_num) {
  if (u != d) {
    local_dfs_num[u] = VISITED;

    for (int v=0; v<n; v++) {
      if (v != d &&
	  adjMat[u][v] == 1 &&
	  local_dfs_num[v] != VISITED) {
	dfs(v, d, local_dfs_num);
      }
    }
  }
}

void print_linesep() {
  int row_num = 2*n + 1;

  for (int i=0; i<row_num; i++) {
    if (i==0 || i==row_num-1)
      cout << "+";
    else
      cout << "-";
  }
  cout << endl;
}

void print_dominator() {

  for (int i=0; i<n; i++) {
    print_linesep();

    cout << "|";
    for (int j=0; j<n; j++) {
      cout << dominator[i][j] << "|";
    }
    cout << endl;
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  
  cin >> t;

  for (int k=1; k<=t; k++) {
    cin >> n;

    for (int i=0; i<n; i++) {
      fill(dfs_num.begin(), dfs_num.end(), UNVISITED);
    }

    for (int i=0; i<n; i++) {
      memset(dominator[i], 'N', n*sizeof(char));
    }

    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
	cin >> adjMat[i][j];

    // mark the nodes which are reachable from initial
    // vertex 0. 
    dfs(0, -1, dfs_num);


    // temporarily disable the outgoing edges from ith
    // node and find the reachability again. 
    for (int i=0; i<n; i++) {
      fill(new_dfs_num.begin(), new_dfs_num.end(), UNVISITED);

      dfs(0, i, new_dfs_num);

      for (int j=0; j<n; j++)
	if (dfs_num[j] == VISITED &&
	    new_dfs_num[j] != VISITED)
	  dominator[i][j] = 'Y';
    }

    cout << "Case " << k << ":" << endl;
    print_dominator();
    print_linesep();
  }
  
  return 0;
}
```
