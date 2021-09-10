#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

long long n, maxColor, color[200100];
vector<long long> adj[200100];
vector<long long> twoAdj[200100];
bool visited[200100];


int main() {
    
    ifstream cin("planting.in");
    ofstream cout("planting.out");

    cin >> n;
    for (long long i = 0; i < n-1; i++) {
        long long a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < adj[i].size(); j++) {
            if(!visited[adj[i][j]]) {
                twoAdj[i].push_back(adj[i][j]);
                visited[adj[i][j]] = true;
            }
            for (long long k = 0; k < adj[adj[i][j]].size(); k++) {
                if (!visited[adj[adj[i][j]][k]] && i != adj[adj[i][j]][k]) { // if not connected already and not itself
                    twoAdj[i].push_back(adj[adj[i][j]][k]);
                }
            }
        }
        
        for (long long j = 0; j < adj[i].size(); j++) {
            visited[adj[i][j]] = false;
            for (long long k = 0; k < adj[adj[i][j]].size(); k++) {
                visited[adj[adj[i][j]][k]] = false;
            }
        }
    }
    
//    for (long long i = 0; i < n; i++) {
//        cout << i << ": ";
//        for (long long j = 0; j < twoAdj[i].size(); j++) {
//            cout << twoAdj[i][j] << " ";
//        }
//        cout << endl;
//    }

    
    for (long long i = 0; i < n; i++) {
        long long a = 1;
        for (long long j = 0; j < twoAdj[i].size(); j++) {
            visited[color[twoAdj[i][j]]] = true;
        }
        
        while (true) {
            if (!visited[a]) break;
            else a++;
        }
        color[i] = a;
        maxColor = max(maxColor, a);
        
        for (long long j = 0; j < twoAdj[i].size(); j++) {
            visited[color[twoAdj[i][j]]] = false;
        }
    }
    
    cout << maxColor << endl;
    
}