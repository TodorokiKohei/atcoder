#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<vector<int>> g;

struct UnionFind{
    vector<int> d;
    UnionFind(int n): d(n, -1){}

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
    bool same(int x, int y){
        return (find(x) == find(y));
    }
    int size(int x){return -d[find(x)];}
};


bool f(int n, int m, int a, int b){
    UnionFind uf(n);
    rep(i,n){
        for(auto v : g[i]){
            if (i == a && v == b) continue;
            if (i == b && v == a) continue;
            uf.unite(i, v);
        }
    }
    return uf.size(a) != n;
}

int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    vector<pair<int, int>> e(m);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        e[i] = (make_pair(a, b));
    }

    int ans = 0;
    rep(i,m){
        int a, b;
        a = e[i].first;
        b = e[i].second;
        if (f(n, m, a, b)) ans++;
    }
    cout << ans << endl;
    return 0;
}