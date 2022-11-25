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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> l_switch(m);
    rep(i,m){
        int k;
        cin >> k;
        rep(j, k){
            int s;
            cin >> s; 
            s--;
            l_switch[i].push_back(s);
        }
    }
    vector<int> p(m);
    rep(i,m) cin >> p[i];

    int ans = 0;
    rep(i, 1<<n){
        int led_on = 0;
        rep(j, m){
            int on = 0;
            for(int s : l_switch[j]){
                if (i>>s&1) on++;
            }
            if (on % 2 == p[j]) led_on++;;
        }
        if (led_on == m) ans++;
    }
    cout << ans << endl;
}