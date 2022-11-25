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
    string s;
    cin >> n >> s;
    VI chW, paW;
    set<int> stW;
    rep(i,n) {
        int wi;
        cin >> wi;
        if (s[i] == '0') {
            chW.push_back(wi);
        }
        else{
            paW.push_back(wi);
        }
        stW.insert(wi);
        if (wi != 1) stW.insert(wi-1);
        if (wi != 1000000000) stW.insert(wi+1);
    }
    sort(chW.begin(), chW.end());
    sort(paW.begin(), paW.end());
    int ans = 0;
    int chStart = 0, paStart = 0;
    for(auto itr = stW.begin(); itr != stW.end(); itr++){
        int wi = *itr;
        for(int i = chStart; i < chW.size(); i++){
            if (chW[i] >= wi) break;
            chStart++;
        }
        for(int i = paStart; i < paW.size(); i++){
            if (paW[i] >= wi) break;
            paStart++;
        }
        int cnt = chStart + (paW.size() - paStart);
        chmax(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}