#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
long a, answer = 0;
long long nums[10100];


int main() {
    
    
    ifstream cin("lemonade.in");
    ofstream cout("lemonade.out");
    
    
    cin >> a;
    
    for (int i = 0; i < a; i++) {
        cin >> nums[i];
    }
    
    sort(nums, nums+a, greater<int>());
    
    for (int i = 0; i < a; i++) {
        if (nums[i] >= i) {
            answer++;
        }
    }
    
    cout << answer << endl;
    
}