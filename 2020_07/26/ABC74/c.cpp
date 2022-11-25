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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    set<int> s1, s2;

    for(int i = 0; i <= f; i++){
        for(int j = 0; j <= f; j++){
            int x = (100*a)*i + (100*b)*j;
            if (x != 0 && x <= f) s1.insert(x);
        }
    }

    for(int i = 0; i <= f; i++){
        for(int j = 0; j <= f; j++){
            int x = c*i + d*j;
            if (x <= f) s2.insert(x);
        }
    }

    double maxN = -1;
    int ans1 = 0, ans2 = 0;
    for(int w: s1){
        for(int s: s2){
            if (w+s <= f && s <= (w/100)*e){
                double n = ((double)100*s) / (w+s);
                if (chmax(maxN, n)){
                    ans1 = w + s;
                    ans2 = s;
                }
            }
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
