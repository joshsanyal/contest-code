// This is a C++ program to find all possible arrangements of
// cubes that lead to an inputed arrangement of cubes after ROFE.

#include <iostream>

using namespace std;

int length, stackHeights[1000];

int main() {
    
    cout << "# of stacks: ";
    cin >> length;
    
    cout << "Height of stacks: ";
    for (int i = 0; i < length; i++) {
        cin >> stackHeights[i];
    }
    
    sort(stackHeights, stackHeights + length);
    
    for (int i = 0; i < length; i++) {
        if (i == 0 || stackHeights[i] != stackHeights[i-1]) {
            if (stackHeights[i] >= length - 1) {
                for (int j = 0; j <= stackHeights[i]; j++) {
                    if (j != i && j <= length) {
                        cout << stackHeights[j] + 1 << " ";
                    }
                    else if (j != i){
                        cout << 1 << " ";
                    }
                }
            cout << endl;
            }
        }
    }
}