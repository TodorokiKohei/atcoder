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

int main(){
    int n, k;
    cin >> n >> k;
    int sum = ((n-2) * (n-1)) / 2;
    if (k > sum){
        cout << -1 << endl;
        return 0;
    }

    vector<P> g;
    for(int i = 1; i < n; i++){
        g.push_back(make_pair(i, n));
    }
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            g.push_back(make_pair(i, j));
        }
    }
    cout << sum-k+(n-1) << endl;
    for(int i = 0; i < sum-k+n-1; i++){
        printf("%d %d\n", g[i].first, g[i].second);
    }
    return 0;
}