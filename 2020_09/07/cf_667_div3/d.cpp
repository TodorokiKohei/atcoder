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


int ff(string &ls, int i){
    int score = 0;
    if (ls[i] == '9'){
        ls[i] = '0';
        score += 9 + ff(ls, i+1);
    }else{
        ls[i] += 1;
        score = -1;
    }
    return score;
}

int f(string &ls, int i){
    int score = ls[i] - '0';
    ls[i] = '0';
    score += ff(ls, i+1);
    return score;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll l; 
        int s;
        cin >> l >> s;
        string ls = to_string(l);
        reverse(all(ls));
        ls += '0';
        int sum = 0;
        rep(i,ls.size()) sum += ls[i] - '0';
        rep(i, ls.size()){
            if (sum <= s) break;
            if (ls[i] == '0') continue;
            int score = f(ls, i);
            sum -= score;
        }
        reverse(all(ls));
        ll r = stoll(ls);
        ll ans = r - l;
        cout << ans << endl;
    }
    
    return 0;
}