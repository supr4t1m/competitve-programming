/*
 * Summation of Four Primes
 *
 * The main idea behind this solution is "Goldbach's conjecture" 
 * which states that "every even counting number greater than two is equal
 * to the sum of two prime numbers"
 *
 * 1. In the first step we need to make the number even, if the number is
 * even subtract 2 + 2, if odd subtract 2 + 3 (why only 2 & 3, well these
 * are the smallest possible prime numbers).
 *
 * 2. In the next step we need to search through all the prime numbers
 * from 2 to N (after subtracting in previous step) and find a pair 
 * i and N-i which are prime. We can guarantee this thanks to Goldbach's
 * conjecture.
 *
 * 3. Lastly we print the result
 *
 *      {2, 2} | {2, 3}, i, N-i
 */

#include <bits/stdc++.h>

using namespace std;
void solve()
{
    // prime numbers are calculated using sieve of eratosthenes
    // this sieve will be used for all the test cases
    int N = 1e7;
    int *sieve = (int *)malloc(N*sizeof(int));

    fill_n(sieve, N, 1);

    for (int i=2; i*i<=N; i++) {
        if (sieve[i]) {
            for (int j=2; i*j<=N; j++) {
                sieve[i*j] = 0;
            }
        }
    }

    int n;
    while (cin >> n) {
        if (n < 8) {
            cout << "Impossible." << endl;
            continue;
        }

        if (n % 2) {
            n -= 5; 
            cout << "2 3 ";
        } else {
            n -= 4;
            cout << "2 2 ";
        }

        // finding the goldbach's conjecture pair
        int g=2;
        while (g<n) {
            if (sieve[g] && sieve[n-g])
                break;
            g++;
        }
        cout << g << " " << n-g << endl;
    }

    delete sieve;
}

int main()
{
#ifndef ONLINE_JUDGE
// open the file in respective mode and redirect
// stream into respective file
    freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
