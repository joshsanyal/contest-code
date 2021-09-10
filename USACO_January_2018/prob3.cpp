#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>


using namespace std;


long long n;
pair<long long, long long> manure[1000000];
pair<long long, long long> help[1000000];
long long Distance[1000000];
long long answer = 100000000;
long long teleport;
long long total, a, b;


long long find(int teleport) {
    long long total = 0;
    for (int a = 0; a < n; a++) {
        long long min = Distance[a];
        if (min > abs(manure[a].first) + abs(manure[a].second - teleport)) {
            min = abs(manure[a].first) + abs(manure[a].second - teleport);
        }
        total += min;
    }
    return total;
}


int main() {
    
    
    ifstream cin("teleport.in");
    ofstream cout("teleport.out");
    
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        manure[i] = make_pair(a, b);
        Distance[i] = abs(a-b);
        if (a >= 0 && b >= 0) {
            if (a < b) {
                help[i] = make_pair(0,0);
            }
            else {
                if (2*a >= b) {
                    help[i] = make_pair(b,2*a);
                }
                else {
                    help[i] = make_pair(0,0);
                }
            }
        }
        else if (a <= 0 && b <= 0) {
            if (a > b) {
                help[i] = make_pair(0,0);
            }
            else {
                if (2*a <= b) {
                    help[i] = make_pair(b,2*a);
                }
                else {
                    help[i] = make_pair(0,0);
                }
            }
        }
        else {
            help[i] = make_pair(0,b);
        }
        
    }
    
    for (int i = 0; i < n; i++) {
        if (help[i].first != 0) {
            total = find(help[i].first);
            if (total < answer) {
                answer = total;
            }
        }
        if (help[i].second != 0) {
            total = find(help[i].second);
            if (total < answer) {
                answer = total;
            }
        }
        
    }
                                                  
    cout << answer << endl;
    
}