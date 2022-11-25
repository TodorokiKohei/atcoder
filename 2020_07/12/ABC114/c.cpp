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

bool f(int x){
    vector<int> a(10);
    while(x){
        a[x % 10]++;
        x /= 10;
    }
    for(int i = 3; i <= 7; i+=2){
        if(a[i] == 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    queue<ll> q;
    q.push(0);
    ll num = 0, ans = 0;
    while(true){
        num = q.front(); q.pop();
        for(int i = 3; i <= 7; i+=2){
            ll next = num * 10 + i;
            if (next > n){
                cout << ans << endl;
                return 0;
            }
            if (f(next)) ans++;
            q.push(next);
        }
    }
}