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

int n, k;
VI a, b;

bool dfs(int i, int x){
    if (i == n) return true;
    if (abs(a[i] - x) <= k){
        if (dfs(i+1, a[i])) return true;
    }
    if (abs(b[i] - x) <= k){
        if (dfs(i+1, b[i])) return true;
    }
    return false;
}

int main(){
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    VVI diff(4, VI(n-1));
    rep(i,n-1){
        diff[0][i] = abs(a[i+1] - a[i]);
        diff[1][i] = abs(b[i+1] - a[i]);
        diff[2][i] = abs(a[i+1] - b[i]);
        diff[3][i] = abs(b[i+1] - b[i]);
    }
    rep(i,n-1){
        int cnt = 0;
        rep(j,4){
            if (diff[j][i] > k) cnt++;
        }
        if (cnt == 4){
            cout << "No" << endl;
            return 0;
        }
    }
    if (dfs(1, a[0])){
        cout << "Yes" << endl;
        return 0;
    }
    if (dfs(1, b[0])){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}