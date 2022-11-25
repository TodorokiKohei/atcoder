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
    vector<int> ng(3);
    rep(i,3) cin >> ng[i];
    sort(all(ng));
    rep(i,3){
        if (ng[i] == n) {
            cout << "NO" << endl;
            return 0;
        }
    }

    int cnt = 0;
    while(cnt < 100){
        cnt++;
        bool ok = true;
        rep(i,3){
            if (n-3 == ng[i]) ok = false;
        }

        if (ok){
            n -= 3;
            continue;
        }

        ok = true;  
        rep(i,3){
            if (n-2 == ng[i]) ok = false;
        }

        if (ok){
            n -= 2;
            continue;
        }

        ok = true;
        rep(i,3){
            if (n-1 == ng[i]) ok = false;
        }

        if (ok){
            n -= 1;
            continue;
        }

        cout << "NO" << endl;
        return 0;
    }

    if (n <= 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
} 