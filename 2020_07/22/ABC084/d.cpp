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

int x[100005];
int sums[100005];

const int MAX = 100000;

bool is2017(int i){
    return (x[i] == 2 && x[(i+2)/2] == 2);
}

int main(){
    for(int i = 1; i <= MAX; i++){
        for(int j = i; j <= MAX; j+=i){
            x[j]++;
        }
    }

    for(int i = 3; i <= MAX; i+=2){
        if (is2017(i)) sums[i] = sums[i-2] + 1;
        else sums[i] = sums[i-2];
    }

    int q;
    cin >> q;
    rep(i, q){
        int l, r;
        cin >> l >> r;
        ll ans = sums[r] - sums[l-2];
        cout << ans << endl;
    }
}