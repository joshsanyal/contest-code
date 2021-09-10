#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int n, q;
int a, b;
pair<int, int> arr[5050]; // value, index
unsigned long long ans[100010];


long long findSols(int a, int b) {
	int arrayWow[b-a+1];
	for (int i = a-1; i<b; i++) {
		arrayWow[i-a+1] = arr[i].first;
	}
	long long ret;
	for (int i = 0; i < b-a-1; i++) {
		int low = i+1;
		int high = b-a;
		if (arrayWow[i] > 0) high = -99;
		while (low < high) {
			if (arrayWow[i] + arrayWow[low] + arrayWow[high] == 0) {
				int l, h;
				for (l = low; arrayWow[l] == arrayWow[low]; l++) {
					for (h = high; arrayWow[h] == arrayWow[high]; h--) {
						ret++;
					}
				}
				low = l;
				high = h;
			}
			if (arrayWow[i] + arrayWow[low] + arrayWow[high] < 0) low++;
			else if (arrayWow[i] + arrayWow[low] + arrayWow[high] > 0) high--;
		}
	}
	return ret;
}

int main() {
    
    //ifstream cin("threesum.in");
	//ofstream cout("threesum.out");

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[i] = make_pair(a, i);
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		cout << findSols(a,b) << endl;
	}

}

