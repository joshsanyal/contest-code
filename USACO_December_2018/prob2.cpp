#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

struct Cow {
    int priority;
    int arrival;
    int duration;
    bool gone = false;
};

bool compareTwoCows(const Cow& a, const Cow& b)
{
    return (a.arrival < b.arrival || (a.arrival == b.arrival && a.priority > b.priority));
}

int n, maxWait = 0;
Cow cows[101000];

int binarySearch(int a, int low, int high) {
    while (high - low > 1) {
        if (cows[(low+high)/2].arrival < a) low = (low+high)/2;
        else high = (low+high)/2;
    }
    return low;
}


int main() {
    
   ifstream cin("convention2.in");
   ofstream cout("convention2.out");
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cows[i].priority = i+1;
        cin >> cows[i].arrival;
        cin >> cows[i].duration;
    }
    
    sort(cows, cows+n, compareTwoCows);
    
    bool allAte = false;
    int curTime = cows[0].arrival, curLow = 0, curHigh = n-1, curCow;
    
    
    for (int c = 0; c < n; c++) {
        int b = binarySearch(curTime, curLow, curHigh);
        curLow = b;
        int maxPriority = 200000;
        for (int i = 0; i <= b; i++) {
            if (!cows[i].gone && cows[i].priority < maxPriority) {
                maxPriority = cows[i].priority;
                curCow = i;
            }
        }
        if (maxPriority == 200000) {
            curCow = b + 1;
            curTime = cows[curCow].arrival;
        }
        if (curTime - cows[curCow].arrival > maxWait) maxWait = curTime - cows[curCow].arrival;
        cows[curCow].gone = true;
        curTime += cows[curCow].duration;
        
    }
    

    cout << maxWait << endl;
    
}