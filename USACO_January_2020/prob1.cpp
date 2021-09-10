#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int n, m, c;
int a, b;
int money[2010];
vector<int> adj[2010];
long dp[1010][1010];
bool dpPos[1010][1010];

long long nCr(int n, int r) 
{ 
	long long ret = 1;
	if (r >= n/2) {
		r = n-r;
	}
	for (int i = n; i >= n-r; i++) {
		ret *= i;
	}
	ret /= fact(r);
} 
  
// Returns factorial of n 
long long fact(int n) 
{ 
    long long res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

int main() {
    long long ans = 0;
	for (int i = 0; i <= 30; i++) {
			ans += nCr(30,i);
			cout << i << " " << NCR(30,i) << endl;
	}
	cout << ans << endl;
}