#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

vector<pair <int,int>> visited[1010];
int n, m;
int a, b, c, d;
vector<pair <int,pair <int,int>>> adj[1010];
queue<pair <int,pair <int,int>>> bfsqueue;

bool sortbysec(const pair <int,pair <int,int>> &a, 
              const pair <int,pair <int,int>> &b) 
{ 
    if (a.second.first > b.second.first) return true;
    else if (a.second.first < b.second.first) return false;
    else if (a.second.second < b.second.second) return true;
    else if (a.second.second > b.second.second) return false;
    else return (a.first > b.first); 
}

void addEdge(int u, int v, int cost, int flow) { 
    adj[u].push_back(make_pair(v, make_pair(flow, cost))); 
    adj[v].push_back(make_pair(u, make_pair(flow, cost))); 
} 

void bfs(int a, int cost, int flow) {
    for (int i = 0; i < visited[a].size(); i++) {
        if (cost == visited[a][i].second && flow <= visited[a][i].first) return;
        if (cost >= visited[a][i].second && flow == visited[a][i].first) return;
    }
    visited[a].push_back(make_pair(flow, cost));
    if (a == n) return;
    else {
        for (int i = 0; i <adj[a].size(); i++) {
            bfs(adj[a][i].first, cost + adj[a][i].second.second, min(flow, adj[a][i].second.first));
        }
    }
}

int main() {
    
    ifstream cin("pump.in");
    ofstream cout("pump.out");
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        addEdge(a, b, c, d);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), sortbysec);
    }

    bfsqueue.push(make_pair(1,make_pair(0,100000000)));
    bool move;
    while (!bfsqueue.empty()) {
        move = true;
        int a = bfsqueue.front().first;
        int cost = bfsqueue.front().second.first;
        int flow = bfsqueue.front().second.second;
        bfsqueue.pop();
        for (int i = 0; i < visited[a].size(); i++) {
            if (cost == visited[a][i].second && flow <= visited[a][i].first) move = false;
            if (cost >= visited[a][i].second && flow == visited[a][i].first) move = false;
        }
        if (move) {
            visited[a].push_back(make_pair(flow, cost));
            if (a != n) {
                for (int i = 0; i <adj[a].size(); i++) {
                    bfsqueue.push(make_pair(adj[a][i].first, make_pair(cost + adj[a][i].second.second, min(flow, adj[a][i].second.first))));
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < visited[n].size(); i++) {
        answer = max(answer, 1000000 * visited[n][i].first / visited[n][i].second);
    }

    cout << answer << endl;
}