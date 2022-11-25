#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }


const int MAX = 1e5+5;

int main(){
    int n, c;
    cin >> n >> c;
    vector<vector<P>> tv(c);
    rep(i,n){
        P tm;
        int ch;
        cin >> tm.first >> tm.second >> ch;
        ch--;
        tv[ch].push_back(tm);
    }

    rep(i, c){
        sort(all(tv[i]));
        vector<P> tv_con;
        rep(j, tv[i].size()){
            P tm = tv[i][j];
            if (j == 0){
                tv_con.push_back(tm);
            }else{
                if (tv_con.back().second == tm.first) tv_con.back().second = tm.second;
                else tv_con.push_back(tm);
            }
        }
        tv[i] = tv_con;
    }

    vector<int> sum(MAX);
    rep(i, c){
        rep(j, tv[i].size()){
            P tm = tv[i][j];
            sum[tm.first-1]++;
            sum[tm.second]--;
        }
    }

    int ans = 0;
    rep(i, MAX-1) sum[i+1] += sum[i];
    rep(i, MAX) ans = max(ans, sum[i]);
    cout << ans << endl;
    return 0;
}