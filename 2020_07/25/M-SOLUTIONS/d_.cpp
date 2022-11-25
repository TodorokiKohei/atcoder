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
    vector<int> a;
    a.push_back(300);
    rep(i,n) {
        int ai;
        cin >> ai;
        a.push_back(ai);
    }
    a.push_back(-1);

    int soko = 1, top = 0;
    ll mon = 1000;
    while(true){
        bool ok = false;
        for(int j = top+1; j <= n; j++){
            if (a[j-1] >= a[j] && a[j] < a[j+1] && !ok){
                ok = true;
                soko = j;
            }
            else if(a[j-1] < a[j] && a[j] >= a[j+1] && ok){
                top = j;
                break;
            }
        }
        if (!ok) break;
        for(int i = soko; i < top; i++){
            ll kabu = mon / a[i];
            mon %= a[i];
            mon += kabu * a[i+1];
        }
    }
    cout << mon << endl;
}