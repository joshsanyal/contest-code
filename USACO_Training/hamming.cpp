/*
 ID: josh.sa1
 TASK: hamming
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int n, b, d;
bool num[500] = {false};

void removeNums(int n, int depth, int maxDepth, int bits) {
    if (depth > maxDepth - 1) return;
    num[n] = true;
    for (int i = 0; i < bits; i++) {
        if (n % (int) pow(2,i+1) >= pow(2,i)) removeNums(n - pow(2,i), depth+1, maxDepth, bits); 
        else removeNums(n + pow(2,i), depth+1, maxDepth, bits);
    }
}

int main() {
    
   ofstream cout ("hamming.out");
   ifstream cin ("hamming.in");
    
    cin >> n >> b >> d;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        while (ans < pow(2,b) && num[ans] == true) {
            ans++;
        }
        cout << ans;
        if (i % 10 == 0 || i == n) cout << endl;
        else cout << " ";
        removeNums(ans, 0, d, b);
    }


}
