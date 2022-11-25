#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 29;
const ll INF = 1LL << 60;

int search(map<int, set<int>> &mp, bool bigger, int target,int start, int l, int mx) {
    if (bigger) {
        // left or up
        int to = start+l;
        // 壁がない
        if (mp.count(target) == 0){
            return min(to, mx);
        }
        auto itr = mp[target].lower_bound(start);
        // スタートより奥に壁がない
        if (itr == mp[target].end()){
            return min(to, mx);
        }
        if (*itr > to){
            // 壁の位置が目的地より奥
            return to;
        } 
        else{
            // 壁の位置が目的地とスタートの間
            return *itr-1;
        } 
    }else{
        // left or up
        int to = start-l;
        // 壁がない
        if (mp.count(target) == 0){
            return max(1, to);
        }
        auto itr = mp[target].lower_bound(start);
        if (itr != mp[target].begin()) itr--;
        if (start < *itr) {
            // 壁の位置がスタートより奥
            return max(1, to);
        }
        if (*itr < to){
            // 壁の位置が目的地より手前
            return to;
        } 
        else{
            // 壁の位置が目的地とスタートの間
            return *itr+1;
        } 
    }
}

int main(){
    int h, w, rs, cs, n;
    cin >> h >> w >> rs >> cs >> n;
    map<int, set<int>> rmp, cmp;
    rep(i,n) {
        int r, c;
        cin >> r >> c;
        rmp[r].insert(c);
        cmp[c].insert(r);
    }
    int q;
    cin >> q;
    rep(i,q) {
        char d;
        int l;
        cin >> d >> l;
        if (d == 'L'){
            cs = search(rmp, false, rs, cs, l, w);
        }
        if (d == 'R'){
            cs = search(rmp, true, rs, cs, l, w);
        }
        if (d == 'U'){
            rs = search(cmp, false, cs, rs, l, h);
        }
        if (d == 'D'){
            rs = search(cmp, true, cs, rs, l, h);
        }
        printf("%d %d\n", rs, cs);
    }
    return 0;
}