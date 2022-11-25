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
    vector<int> t(n), x(n), y(n);
    rep(i,n) cin >> t[i] >> x[i] >> y[i];
    int preX = 0, preY = 0, preT= 0;
    rep(i,n){
        int diffX, diffY, diffT;
        diffX = abs(x[i] - preX);
        diffY = abs(y[i] - preY);
        diffT = abs(t[i] - preT);
        if (diffT < (diffX + diffY)){
            cout << "No" << endl;
            return 0;
        }
        if (((diffX + diffY) % 2) != (diffT % 2)){
            cout << "No" << endl;
            return 0;
        }
        preX = x[i];
        preY = y[i];
        preT = t[i];
    }
    cout << "Yes" << endl;
    return 0;
}