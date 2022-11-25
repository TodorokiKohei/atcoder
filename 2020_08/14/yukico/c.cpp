#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

struct UnionFind{
    vector<int> d;
    UnionFind(int n = 0): d(n, -1){}
    int find(int x){
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y){
        x = find(x); y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x){return -d[find(x)];}
};

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    rep(i,n) cin >> x[i];

    UnionFind uf(n);
    vector<int> y(n);
    rep(i,n){
        int l = lower_bound(all(x), x[i]+a) - x.begin();
        int r = (upper_bound(all(x), x[i]+b) - x.begin()) - 1;
        if (l > r) continue;
        uf.unite(i, l);
        y[l]++;
        y[r]--;
    }

    rep(i,n-1) y[i+1] = y[i+1] + y[i];
    rep(i,n-1) if (y[i] > 0) uf.unite(i, i+1);

    rep(i,n){
        cout << uf.size(i) << endl;
    }
    return 0;
}