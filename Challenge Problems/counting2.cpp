#include <cstdio>
#include <iostream>
#include <utility>

using namespace std;

long n;
long numPhones;
long charge;
float time;
pair <float,float> phones[100100];
long a;
long b;
float timeLeft[100100];
int indexLeast;
int nextLeast;

void findTimeLeft() {
    long min = 100000;
    for (int i = 0; i<numPhones; i++) {
        timeLeft[i] = phones[i].second/phones[i].first;
        if (timeLeft[i] < min) {
            min = timeLeft[i];
            indexLeast = i;
        }
    }
    
    long min = 100000;
    for (int i = 0; i<numPhones; i++) {
        if (i != indexLeast) {
            if (timeLeft[i] < min) {
                min = timeLeft[i];
                nextLeast = i;
            }
        }
    }
    
}


int main () {
    
    cin >> n;
    
    for (int i = 0; i<n; i++) {
        cin >> numPhones >> charge;
        
        for (int j = 0; j<numPhones; j++) {
            cin >> a >> b;
            phones[j] = make_pair(a,b);
        }
        
        bool answerFound = false;
        float timeUsed;
        
        while (!answerFound) {
            findTimeLeft();
            timeUsed = 
            
            
        }
        
    }
}
