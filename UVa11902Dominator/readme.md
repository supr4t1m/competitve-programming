```C++
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define UNVISITED -1
#define VISITED 1

int n;
vector<int> dfs_num;
vector<int> new_dfs_num;
int adjMatrix[100][100];
char dominator[100][100];


void dfs(int u, int d) {
  dfs_num[u] = VISITED;
  if (u != d) {
    if (d != -1) dominator[d][u] = 'N';

    for (int v=0; v<n; v++) {
      if (v != d &&
	  adjMatrix[u][v] == 1 &&
	  dfs_num[v] != VISITED) {
	dfs(v, d);
      }
    }
  }
}

void print_linesep() {
  int num_cols = 2*n+1;
  for (int i=0; i<num_cols; i++)
    if (i==0 || i==num_cols-1)
      cout << "+";
    else
      cout << "-";
  cout <<endl;
}

void formatted_output() {
  
  for (int i=0; i<n; i++) {
    print_linesep();
    cout << "|";
    for (int j=0; j<n; j++)
      cout << dominator[i][j] << "|";
    cout << endl;
  }
  print_linesep();
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  
  int t;
  dfs_num = vector<int>(100, UNVISITED);
  new_dfs_num = vector<int>(100, UNVISITED);

  cin >> t;

  for (int k=0; k<t; k++) {
    cin >> n;


    for (int i=0; i<n; i++) {
      memset(dominator[i], 'N', n*sizeof(int));
    }
    
    for (int i=0; i<n; i++) 
      for (int j=0; j<n; j++)
	cin >> adjMatrix[i][j];

    // mark the nodes which are reachable as Y initially. 
    dfs(0, -1);

    for (int j=0; j<n; j++) {
      if (dfs_num[j] == VISITED)
	// if a node can be visited, it can be dominated by
	// all previous nodes
	for (int i=0; i<=n; i++)
	  dominator[i][j] = 'Y';
    }

    // for each node find if it is the dominator
    // of any node below it through dfs
    for (int i=0; i<n; i++) {
      fill(dfs_num.begin(), dfs_num.end(), UNVISITED);   
      dfs(0, i);
    }

    // print the dominator matrix
    // based on the formatting
    cout << "Case " << k+1 << ":" << endl;
    formatted_output();
    
  }
  
  return 0;
}
```
