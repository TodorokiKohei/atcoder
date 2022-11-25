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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> lr;
    lr.push_back(make_pair(-1, -1));
    int l = 0;
    int sum = 0, ans = 0;
    bool ok = false;
    rep(i,n){
        if (s[i] == '1' && ok){
            lr.push_back(make_pair(l, i-1));
            ok = false;
            sum++;
        }
        if (s[i] == '0'){
            if (!ok) l = i;
            ok = true;
            ans = max(ans, sum);
            sum = 0;
        }
    }
    if (s[n-1] == '0') lr.push_back(make_pair(l, n-1));
    lr.push_back(make_pair(n, n));

    if (lr.size()-2 <= k){
        cout << n << endl;
        return 0;
    }

    for(int i = 0; i < lr.size()-1; i++){
        int oneSum = 0;
        int cnt = k;
        int j;
        for(j = i+1; j < lr.size()-1; j++){
            if (cnt == 0) break;
            oneSum += lr[j].second - lr[j-1].second;
            cnt--;
        }
        oneSum += lr[j].first - lr[j-1].second - 1;
        ans = max(ans, oneSum);
    }
    cout << ans << endl;
}