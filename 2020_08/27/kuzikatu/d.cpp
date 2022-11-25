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
    vector<int> d(MAX);
    for(int i = 1; i < MAX; i++){
        for(int j = i;  j < MAX; j += i){
            d[j]++;
        }
    }
    vector<int> sum(MAX+1);
    for(int i = 2; i < MAX; i++){
        if (d[i] == 2 && i % 2 == 1 && d[(i+1)/2] == 2) sum[i] = sum[i-1] + 1;
        else sum[i] = sum[i-1];
    }

    int q;
    cin >> q;
    vector<int> ans;
    rep(i,q){
        int l, r;
        cin >> l >> r;
        ans.push_back(sum[r]-sum[l-1]);
    }
    rep(i,q) cout << ans[i] << endl;
    return 0;
}