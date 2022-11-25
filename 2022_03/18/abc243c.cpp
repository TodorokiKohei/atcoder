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

int main(){
    int n;
    cin >> n;
    VI x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    string s;
    cin >> s;
    map<int, vector<pair<int, char>>> m;
    rep(i,n) m[y[i]].push_back(make_pair(x[i], s[i]));
    for(pair<int, vector<pair<int, char>>> mm: m){
        sort(mm.second.begin(), mm.second.end());
        bool right = false, col = false;
        for(pair<int, char> p : mm.second){
            if (p.second == 'R') right = true;
            if (right && p.second == 'L') col = true;
            if (col){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}