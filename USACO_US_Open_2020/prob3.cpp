#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<long long, long long> pi; 

int a;
long long m;
priority_queue<pi, vector<pi>, greater<pi> > pq;
long long ans = 0;
int primes[10000];

void primeSieve(int n) { 
    bool prime[10100]; 
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == false) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = true; 
        } 
    } 

    int counter = 0;
    for (int p=2; p<=n; p++) 
       if (!prime[p]) {
       		primes[counter] = p;
       		counter++;
       }
}

int main() {
    //ifstream cin("exercise.in");
    //ofstream cout("exercise.out");
    
    cin >> a >> m;
    primeSieve(a);
    
    for (int i = 1; i <= a; i++) {
		pq.push(make_pair(i, i));
    }
   
    while (!pq.empty()) {
    	pair<int, int> top = pq.top(); 
    	while (!pq.empty() && pq.top().first == top.first) {
    		pq.pop();
    	}
		ans = (ans + top.first) % m;
		cout << top.first << " " << top.second << endl;
		for (int p = 0; primes[p] + top.second <= a && primes[p] != 0; p++) {
			if (top.first % primes[p] != 0) pq.push(make_pair((top.first * primes[p]), primes[p] + top.second));
		}
    }

    cout << ans << endl;
    
    
}