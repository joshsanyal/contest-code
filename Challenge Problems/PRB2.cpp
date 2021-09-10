#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool inside( int n, int d, int x, int y)
{
    if (x+y < d) return false; // (0. d)-(d, 0)
    if (x+y > 2*n-d) return false; // (n,n−d) и (n−d,n)
    if (x-y > d) return false; // (d, 0) (n,n−d)
    if (y-x > d) return false; // 0. d)  (n−d,n)
    return true;
}

int main()
{
  
    

    int a, n, d, m;
    cin>>a;
    
    for(int j=0; j<a; j++) {
        cin>>n>>d;
        cin>>m;
        for(int i=0; i<m; i++)
        {
            int x, y;
            cin>>x>>y;
            if (inside(n, d, x, y)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}