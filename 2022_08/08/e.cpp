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
    map<int, int> pMax, pCnt;
    vector<vector<pair<int, int>>> a(n);
    rep(i,n){
        int m;
        cin >> m;
        rep(j, m){
            int p, e;
            cin >> p >> e;
            if (chmax(pMax[p], e)){
                pCnt[p] = 1;
            }else if (pMax[p] == e){
                pCnt[p]++;
            }
            a[i].push_back(make_pair(p, e));
        }
    }
    int ans = 0;
    rep(i,n){
        rep(j, sz(a[i])){
            int p = a[i][j].first, e = a[i][j].second;
            if (pMax[p] == e && pCnt[p] == 1){
                ans++;
                break;
            }
        }
    }
    cout << min(ans+1, n) << endl;
    return 0;
}