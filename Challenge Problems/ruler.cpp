#include <iostream>
#include <string>

using namespace std;

int n, visited[10] = {0}, chosen[10], temp;
string seq[10];
int minimum = 10000;

string merge(string a, string b) {
    string ret = "";
    int bStart = 0;
    int bIndex = 0;
    for (int i = 0; i<a.length(); i++) {
        ret += a[i];
        if (a[i] == b[bIndex]) {
            bIndex++;
            bStart = bIndex;
        }
        else if (a[i] != b[bIndex] && a[i] == b[0]) {
            bIndex=1;
            bStart = bIndex;
        }
        else if (a[i] != b[bIndex]) {
            bIndex=0;
            bStart=0;
        }
    }
    for (int i = bStart; i<b.length(); i++) {
        ret += b[i];
    }
    
    return ret;
}

int merger() {
    string ret = merge(seq[chosen[0]], seq[chosen[1]]);
    for (int i = 2; i < n; i++){
        ret = merge(ret, seq[chosen[i]]);
    }
    return ret.length();
}

void solve(int x) {
    if (x == n) {
        temp = merger();
        if (temp < minimum) {
            minimum = temp;
        }
        return;
    }
    
    for (chosen[x] = 0; chosen[x]<n; chosen[x]++) {
        if (visited[chosen[x]] == 0) {
            visited[chosen[x]] = 1;
            solve(x+1);
            visited[chosen[x]] = 0;
        }
    }
    
}

int main() {
    cin >> n;
    
    for (int i = 0; i<n; i++) {
        cin >> seq[i];
    }
    
    solve(0);
    cout << minimum;
}