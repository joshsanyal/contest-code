#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


typedef pair<int, pair<int, int>> pi; 
int n, p;
int a, b, c, d;
pair<pair<int, int>, pair<int,int>> spring[100100]; // left, right

priority_queue<pi, vector<pi>, greater<pi> > pq; 

int main() {
    
    ifstream cin("boards.in");
    ofstream cout("boards.out");

	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		cin >> a >> b >> c >> d;
		spring[i] = make_pair(make_pair(a,b), make_pair(c,d));
	}
	sort(spring, spring+p);

	pq.push(make_pair(0,make_pair(n,n)));
	while (!pq.empty()) {
		pair<int, pair<int, int>> top = pq.top();
		pq.pop();
		if (top.second.first == 0 && top.second.second == 0) {
			cout << top.first << endl;
			break;
		}
		pq.push(make_pair(top.first + top.second.first + top.second.second, make_pair(0,0)));
		for (int i = 0; i < p; i++) {
			if (spring[i].first.first >= n - top.second.first && spring[i].first.second >= n - top.second.second) {
				pq.push(make_pair(top.first + spring[i].first.first - (n - top.second.first) + spring[i].first.second - (n - top.second.second), make_pair(n - spring[i].second.first, n - spring[i].second.second)));
			}
		}
	}

}