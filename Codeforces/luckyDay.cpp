#include <iostream>
#include <algorithm>


using namespace std;

int s1, e1, s2, e2;
long long d1, d2, ans;

int overlap(int w, int x, int y, int z) {
    if (min(x,z) - max(w,y) + 1 > 0) return min(x,z) - max(w,y) + 1;
    else return 0;
}

int main() {
    
    cin >> s1 >> e1 >> d1 >> s2 >> e2 >> d2;
    ans = overlap(s1,e1,s2,e2);
    
    for (int i = 0; i < 11000000; i++) {
        if (s1 < s2) {
            int diff = d1 * ((s2-s1)/d1);
            s1 += diff;
            e1 += diff;
            if (overlap(s1,e1,s2,e2) > ans) {
                ans = overlap(s1,e1,s2,e2);
            }
            s1 += d1;
            e1 += d1;
            if (overlap(s1,e1,s2,e2) > ans) {
                ans = overlap(s1,e1,s2,e2);
            }
        }
        else {
            int diff = d2 * ((s1-s2)/d2);
            s2 += diff;
            e2 += diff;
            if (overlap(s1,e1,s2,e2) > ans) {
                ans = overlap(s1,e1,s2,e2);
            }
            s2 += d2;
            e2 += d2;
            if (overlap(s1,e1,s2,e2) > ans) {
                ans = overlap(s1,e1,s2,e2);
            }
        }
    }
    
    cout << ans << endl;
}