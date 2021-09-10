#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

long long length, speedJohn, speedBessie;
pair<long long, long long> reststop[1000000];
long long tempA, tempB;
long long maxTasty = 0;
long long locationJohn = 0;
long long locationBessie = -1;
long long answer;
long long restStops;


int main() {

    
    ifstream cin("reststops.in");
    ofstream cout("reststops.out");
    
    
    cin >> length >> restStops >> speedJohn >> speedBessie;
    
    for (int i = 0; i < restStops; i++) {
        cin >> tempA >> tempB;
        reststop[i] = make_pair(tempA, tempB);
        
    }
    
    sort(reststop, reststop + restStops);

    while (locationBessie < restStops - 1) {
        maxTasty = 0;
        for (int i = locationBessie + 1; i < restStops; i++) {
            if (reststop[i].second > maxTasty) {
                maxTasty = reststop[i].second;
                locationBessie = i;
            }
        }
        
        answer += maxTasty * ((reststop[locationBessie].first - locationJohn)*(speedJohn-speedBessie));
        
        locationJohn = reststop[locationBessie].first;
    }
    
   cout << answer << endl;
    
}