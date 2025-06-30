```C++
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

void solve(int N) {
  bool exists_solution = false;
  for (int fghij=1234; fghij <= 98765/N; fghij++) {
    int used = (fghij < 10000);
    int temp = fghij;
    while (temp) {
      used = used | (1 << (temp%10));
      temp = temp/10;
    }
    int abcde = fghij*N; 
    temp = abcde;
    while (temp) {
      used = used | (1 << (temp%10));
      temp = temp/10;
    }
    if (used == (1<<10)-1) { // if all 10 bits (digits) are used
      exists_solution = true;
      printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
    } 
  }

  if (!exists_solution) {
    cout << "There are no solutions for " << N << "." << endl;
  }
}

// taking the input
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n;
  bool first=true;
  
  // While N is not 0
  while (cin >> n && n) {
    // print a newline between test cases not after them
    if (!first) cout << endl;
    if (first) first=false;
    solve(n);
  }
}
```
