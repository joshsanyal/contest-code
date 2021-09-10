#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define pb push_back

const int MN = 1e5 + 100;
template<int MS = MN<<2> struct ST {
    vi v, z;
    int s;
    void addz(int n, int x) {
        v[n]^=x, z[n]^=x;
    }
    void up(int n, int l, int r) {
        v[n] = v[n<<1] ^ v[n<<1|1];
    }
    void down(int n, int l, int r) {
        if(!z[n]) return;
        if(r-l>1)
            addz(n<<1, z[n]), addz(n<<1|1, z[n]);
        z[n] = 0;
    }
    void init(int n, int l, int r) {
        if(r-l>1) {
            int m = l + ((r-l)>>1);
            init(n<<1, l, m), init(n<<1|1, m, r);
            z[n] = 0, up(n, l, r);
        } else
            v[n] = 0;//default to 0
    }
    void init(int S) {
        s = S;
        v.assign(s*4, 0);
        z.assign(s*4, 0);
        init(1, 0, s);
    }
    void upd(int n, int l, int r, int ql, int qr, int x) {
        if(l <= ql&&r <= qr) return addz(n, x);
        int m = l + ((r-l)>>1);
        down(n, l, r);
        if(ql < m) upd(n<<1, l, m, ql, qr, x);
        if(m < qr) upd(n<<1|1, m, r, ql, qr, x);
        up(n, l, r);
    }
    void upd(int ql, int qr, int x) {upd(1, 0, s, ql, qr, x);}
    int qry(int n, int l, int r, int ql, int qr) {
        if(ql <= l&&r <= qr) return v[n];
        down(n, l, r);
        int m = l + ((r-l)>>1);
        int f = 0;
        if(ql < m) x ^= qry(n<<1, l, m, ql, qr);
        if(m < qr) x ^= qry(n<<1|1, m, r, ql, qr);
        return x;
    }
    int qry(int ql, int qr) {return qry(1, 0, s, ql, qr);}
};


vi a[MN];
int s[MN], p[MN], d[MN];
int h[MN], t[MN], q[MN];
int o[MN][2];
struct QR{
    int n, d;
    bool operator < (const QR& o) const {return d < o.d;}
} Q[MN<<1][30];

int dfs(int n = 1, int * c = new int(0)) {
    Q[o[n] = (*c)++][0] = {n, d[n]};
    s[n] = 1;
    for(int x : a[n])
        if(p[n] != x)
            p[x] = n, d[x] = d[n]+1, s[n] += dfs(x), Q[(*c)++][0] = {n, d[n]};
    h[n] = -1;
    for(int x : a[n])
        if(p[n] != x&&s[x]<<1>=s[n])
            h[n] = x;
    return s[n];
}
int e[MN];
ST st[MN];
void dfs2(int n = 1) {
    if(h[n] != -1) {
        if(t[n] == -1) t[n] = n, q[n] = 0;
        t[h[n]] = t[n], q[h[n]] = q[n] + 1;
    }
    for(int x : a[n])
        if(x != p[n])
            dfs2(x);
    if(h[n] == -1)
        if(t[n] != -1)
            st[t[n]].init(q[n]+1);
}
void pcprmq() {
    for(int i = (N<<1)-1;i >= 0;i--)
        for(int j = 0;i + (1<<j+1) < (N<<1)-1;j++)
            q[i][j+1] = min(q[i][j], q[i+(1<<j)][j]);
}
int l2[MN<<1];
void pcpl() {
    for(int i = 0, j = -1;i < MN<<1;i++) {
        if(i>>(j+1)) j++;
        l2[i] = j;
    }
}
int lca(int a, int b) {
    if(a == b) return a;
    if(o[b] < o[a]) swap(a, b);
    int w = l2[o[b]-o[a]];
    return min(q[o[a]][w], q[o[b]-(1<<w)][w]).n;
}
void upd(int n, int x) {
    if(t[n] != -1)
        st[t[n]].upd(q[n], q[n]+1, x);
    else
        e[n] ^= x;
}
int tqry(int n, int t) {
    
}

int main() {
    
    //ifstream cin("cowland.in");
    //ofstream cout("cowland.out");

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    
    for (int i = )
    
    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c;
        if (a == 1) { // set enjoyment of b to c
            
        }
        else { // output enjoyment of path from b to c
            
        }
    }
    
    dfs();
    t[1] = -1;
    dfs2();
    pcpl();
    pcprmq();
}