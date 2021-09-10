#include <iostream>

using namespace std;

int main() {
    int t, n, lis[110], a, ans[110], sum;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        sum = 0;
        for (int j = 1; j <= n; j++) {
            cin >> a;
            lis[a] = j;
        }
        for (int j = 1; j < n; j++) {
        	int pos = lis[j];
        	for (int k = 1; k < j; k++) {
        		int start = k;
        		int end = ans[k] + start - 1;
        		if (start <= pos && end >= pos) {
        			pos = start + end - pos;
        		}
        	}
        	ans[j] = pos - j + 1;
        	sum += ans[j];
		}	
		cout << "Case #" << i+1 << ": " << sum << endl;
    }

}