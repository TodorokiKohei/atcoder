#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 30;
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    VP c(n);
    rep(i,n) cin >> c[i].first >> c[i].second;
    sort(all(c));
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                int x1 = (c[j].first - c[i].first);
                int x2 = (c[k].first - c[j].first);
                int y1 = (c[j].second - c[i].second);
                int y2 = (c[k].second - c[j].second);
                if (x1 == 0 && x2 == 0){
                    cout << "Yes" << endl;
                    return 0;
                }else if (x1 == 0 || x2 == 0){
                    continue;
                }else{
                    if (x2 * y1 == x1 * y2){
                        cout <<"Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}