#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
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
    int n, m;
    cin >> n >> m;
    VVI g(n);
    VP e(m);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        e[i].first = a;
        e[i].second = b;
    }
    reverse(all(e));

    UnionFind uf(n);
    VL ans = {n * (n-1LL) / 2};
    rep(i,m){
        int a, b;
        a = e[i].first;
        b = e[i].second;
        if (uf.same(a, b)) {
            ans.push_back(ans.back());
            continue;
        }
        ll szA = uf.size(a);
        ll szB = uf.size(b);
        ans.push_back(ans.back() - (szA * szB));
        uf.unite(a, b);
    }
    ans.pop_back();
    reverse(all(ans));
    rep(i,m) cout << ans[i] << endl;
    return 0;
}