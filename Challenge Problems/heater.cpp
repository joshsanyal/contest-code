#include <iostream>
#include <algorithm>

using namespace std;

int length, stackHeights[1000];


int main() {
        
    cin >> length;
    
    for (int i = 0; i < length; i++) {
        cin >> stackHeights[i];
    }
    
    sort(stackHeights, stackHeights + length);
    
    cout << stackHeights[0];
    
}