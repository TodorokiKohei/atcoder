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
    cin >> s;
    if (sz(s) != 8) {
        cout << "No" << endl;
        return 0;
    }
    if (s[0] < 'A' || s[0] > 'Z' ){
        cout << "No" << endl;
        return 0;
    }

    string num = "";
    for(int i = 1; i < sz(s)-1; i++) {
        num.append({s[i]});
        if ('0' <= s[i] && s[i] <= '9') continue;
        cout << "No" << endl;
        return 0;
    }
    
    if (stoi(num) < 100000 || stoi(num) > 999999) {
        cout << "No" << endl;
        return 0;
    }

    if (s[sz(s)-1] < 'A' || s[sz(s)-1] > 'Z' ){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}