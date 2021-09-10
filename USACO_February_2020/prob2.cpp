#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int n, a, b;
pair<int, int> seg[100100];
vector<pair<int, int>> allSegs;

void 

int main() {

    ifstream cin("help.in");
    ofstream cout("help.out");

    cin >> n;
    for (int i = 0; i < n; i++) {
    	cin >> a >> b;
    	seg[i] = (make_pair(a, b));
    	allSegs.push_back(make_pair(a,b));
    }
    sort(seg, seg+n);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < allSegs.size(); j++) {
    		if (seg[j].first < seg[i].second && seg[j].second > seg[i].second) {
    			allSegs.push_back(make_pair(seg[i].first, seg[j].second));
    		}
    	}
    }

    cout << allSegs.size() + n << endl;
    
}