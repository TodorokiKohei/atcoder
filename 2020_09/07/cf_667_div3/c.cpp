#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;

        int diff = y - x;
        int p;
        for(int i = n-1; i > 0; i--){
            if (diff % i == 0){
                p = diff / i;
                break;
            }
        }

        int r = x % p;
        if (r == 0) r += p;
        VI a;
        for(int i = 0; i < 55; i++){
            a.push_back(r + p * i);
        }
        
        int left, right = 0;
        while(a[right] != y) right++;

        left = max(0, right - n + 1);
        right += n - (right - left + 1);
        while(left <= right){
            printf("%d%c", a[left], left == right ? '\n' : ' ');
            left++;
        }
    }
    return 0;
}