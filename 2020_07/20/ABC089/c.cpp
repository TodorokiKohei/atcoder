#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    map<char, ll> m;
    rep(i,n){
        m[s[i][0]]++;
    }
    vector<char> c = {'M', 'A', 'R', 'C', 'H'};
    ll ans = 0;
    for(int i = 0; i < c.size(); i++){
        for(int j = i+1; j < c.size(); j++){
            for(int k = j+1; k < c.size(); k++){
                ans += m[c[i]] * m[c[j]] * m[c[k]];
            }
        }
    }
    cout << ans << endl;
}