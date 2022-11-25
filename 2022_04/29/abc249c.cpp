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
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    int ans = 0;
    rep(i, 1<<n){
        vector<bool> use(n, false);
        rep(j, n) if ((i>>j)&1) use[j] = true;

        vector<int> cnt(26, 0);
        rep(j, n){
            if (!use[j]) continue;;
            rep(si, s[j].size()) cnt[s[j][si]-'a']++;
        }
        int tmpAns = 0;
        rep(j, 26) if (cnt[j] == k) tmpAns++;
        chmax(ans, tmpAns);
    }
    cout << ans << endl;
    return 0;
}