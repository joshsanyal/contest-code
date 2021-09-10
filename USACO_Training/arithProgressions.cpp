#include <cstdio>
#include <iostream>

#include <vector>

using namespace std;

#define pb push_back

const int MAXN = 101000;

int N, Nt;

int names[MAXN * 2];

int sa[MAXN * 2], isa[MAXN * 2];

vector<int> ctsarr[MAXN * 2];
int rnk[MAXN * 2][2], nrnk[MAXN * 2];

void ctsort(int rn, int mxr) {
    for(int i = 0;i < Nt;i++) ctsarr[rnk[sa[i]][rn]].pb(sa[i]);
    int ctr = 0;
    for(int i = 0;i <= mxr;i++) {
        for(int j = 0;j < ctsarr[i].size();j++) sa[ctr++] = ctsarr[i][j];
        ctsarr[i].assign(0, 0);
    }
}


bool srnk(int a, int b) {
    for(int i = 0;i < 2;i++) if(rnk[a][i] != rnk[b][i]) return false;
    return true;
}

void gsa() {
    for(int i = 0;i < Nt;i++) {
        sa[i] = i;
        rnk[i][0] = names[i];
        rnk[sa[i]][1] = 0;
    }
    for(int i = 1;i >= 0;i--) ctsort(i, 200);
    int ctr = 1;
    for(int po2 = 1;po2 <= Nt;po2 <<= 1) {
        nrnk[sa[0]] = ctr = 1;
        for(int i = 1;i < Nt;i++) nrnk[sa[i]] = srnk(sa[i], sa[i - 1]) ? ctr : ++ctr;
        for(int i = 0;i < Nt;i++) rnk[sa[i]][0] = nrnk[sa[i]];
        for(int i = 0;i < Nt;i++) rnk[i][1] = i + po2 < Nt ? rnk[po2 + i][0] : 0;
        for(int i = 1;i >= 0;i--) ctsort(i, ctr);
    }
    for(int i = 0;i < Nt;i++) isa[sa[i]] = i;
}


void printsfx(int * n) {
    while(*n > 0) {
        cout << static_cast<char> (*(n++));
    }
    cout << endl;
}

int lcp[MAXN * 2];
void glcp() {
    int prev = 0;
    for(int i = 0;i < Nt;i++) {
        if(isa[i] == Nt-1) {
            lcp[isa[i]] = prev = 0;
            continue;
        }
        while(i + prev < Nt and sa[isa[i] + 1] + i < Nt and names[i + prev] == names[sa[isa[i] + 1] + prev]) prev++;
        lcp[isa[i]] = prev;
        if(prev > 0) prev--;
    }
}

int main() {
    cin >> N;
    
    string inp;
    Nt = 0;
    for(int i = 0;i < N;i++) {
        cin >> inp;
        for(int j = 0;j < inp.size();j++) {
            names[Nt++] = static_cast<int> (inp[j]);
        }
        names[Nt++] = 96;
    }
    names[--Nt] = '\0';
    
    gsa();
    
    for(int i = 0;i < Nt;i++) {cout << sa[i] << " " << lcp[i] << " ", printsfx(names + sa[i]);}
}