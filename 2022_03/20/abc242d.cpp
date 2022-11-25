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
    string s;
    int q;
    cin >> s >> q;
    while(q--){
        ll t, k;
        cin >> t >> k;
        k--;
        int si = 0;
        if (t <= 60){
            ll b = 1LL<<t;  // t回繰り返した時の0番目の文字列から出来る文字数
            si = k/b;       // どのkは最初の文字のどの位置から作られた文字か
            k %= b;         // kの開始位置をずらす
        }
        ll r = __builtin_popcountll(k); // 右の回数をカウント(+2)
        ll l = t-r;                     // 左の回数をカウント(+1)
        ll x = l + r * 2 + (s[si]-'A'); // 最初の文字からずらす回数
        char ans = 'A' + (x%3);
        cout << ans << endl;
    }
    return 0;
}