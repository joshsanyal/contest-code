#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int n, m, a, b, c;
int cow[100100];
vector<int> adj[100100];
vector<int> path[100100];
bool visited[100100] = {false};

void addEdge(int u, int v) 
{ 
    adj[u].push_back(v); 
    adj[v].push_back(u); 
} 

void dfs(vector<int> p) {
    if (visited[p.back()]) {
        return;
    }
    visited[p.back()] = true;
    path[p.back()] = p;
    for (int i = 0; i < adj[p.back()].size(); i++) {
        p.push_back(adj[p.back()][i]);
        dfs(p);
        p.pop_back();
    }
    p.pop_back();
}


int main() {
    
    ifstream cin("milkvisits.in");
    ofstream cout("milkvisits.out");
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cow[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        addEdge(a,b);
    }
    dfs(vector<int>{1});

    bool reverse, stop;

    for (int i = 0; i < m; i++) {
        cin >> b >> a >> c;
        reverse = false;
        stop = false;

        for (int j = path[a].size()-1; j >= 0 && !stop && !reverse; j--) {
            if (cow[path[a][j]] == c) {
                cout << '1';
                stop = true;
            }
            for (int k = 0; k < path[b].size() && !stop; k++) {
                if (path[a][j] == path[b][k]) {
                    reverse = true;
                }
                if (reverse && cow[path[b][k]] == c) {
                    cout << '1';
                    stop = true;
                }
            }
        }

        if (!stop) cout << '0';
    }
    cout << endl;
    
}