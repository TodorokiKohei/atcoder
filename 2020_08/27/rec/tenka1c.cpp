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
    ll N;
    cin >> N;
    for(int n = 1; n <= 3500; n++){
        for(int w = 1; w <= 3500; w++){
            if ((4*n*w - N*(n+w)) <= 0) continue;
            if ((N * n * w) % (4*n*w - N*(n+w)) == 0){
                int h = (N * n * w) / (4*n*w - N*(n+w));
                printf("%d %d %d\n", h, n, w);
                return 0;
            }
        }
    }
    return 0;
}