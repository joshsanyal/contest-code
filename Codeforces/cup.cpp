#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string s;
int ast, start, fin;
double row, col;

int main() {
    
    cin >> s;

    row = ceil(s.length()/20.0);
    col = ceil(s.length()/row);
    
    ast = row*col - s.length();
    
    start = 0;
    cout << row << " " << col << endl;
    
    for (int i = 0; i < row; i++) {
        if (ast > 0) {
            ast--;
            cout << s.substr(start, col - 1) << "*" << endl;
            start += col - 1;
        }
        else {
            cout << s.substr(start, col) << endl;
            start += col;
        }
            
    }
    
}