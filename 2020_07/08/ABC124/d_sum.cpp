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

    vector<int> nums;
    int cnt = 0;
    int now = 1;
    rep(i,n){
        if (s[i] == '0'+now) cnt++;
        else {
            nums.push_back(cnt);
            now ^= 1;
            cnt = 1;
        }
    }
    nums.push_back(cnt);
    if (nums.size() % 2 == 0) nums.push_back(0);

    vector<int> sums(nums.size()+1);
    rep(i, nums.size()){
        sums[i+1] = sums[i] + nums[i];
    }

    int add = 2 * k + 1;
    int tmp = 0;
    int ans = 0;
    for(int i = 0; i < nums.size(); i+=2){
        int left = i;
        int right = min(i + add, (int)nums.size());
        ans = max(ans, sums[right] - sums[left]);
    }
    cout << ans << endl;
}