#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n, m, a, b;
vector<int> admiresList[200100]; //admiresList[i] == list of cows who cow i admires
vector<int> admiredBy[200100]; //admiredBy[i] == list of cows who cow i is admired by
vector<int> colored[200100]; // cows who like color i
int color[200100]; // fav color of cow i
int numDistinct = 1;

int main() {

   // ifstream cin("sort.in");
   // ofstream cout("sort.out");
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
    	cin >> a >> b;
    	admiresList[a].push_back(b);
    	admiredBy[b].push_back(a);
    }

    
    for (int i = 1; i <= n; i++) {
    	if (color[i] == 0) {
    		color[i] = numDistinct++;
    		colored[numDistinct-1].push_back(i);
    	}
    	set<int> admiredColors;
    	for (int j = 0; j < admiresList[i].size(); j++) {
			for (int k = 0; k < admiredBy[admiresList[i][j]].size(); k++) {
				color[admiredBy[admiresList[i][j]][k]] = color[i];
			}
    		if (color[i] != 0) admiredColors.insert(color[admiresList[i][j]]);
    	}
    	for (int x : admiredColors) {
			for (int j = 0; j < colored[x].size(); j++) {
				for (int k = 0; k < admiredBy[colored[x][j]].size(); k++) {
    				color[admiredBy[colored[x][j]][k]] = color[i];
    			}
    		}
    	}
    	cout << color[i] << endl;
    }
    
}