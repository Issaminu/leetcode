#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
#define OVL(x, s)                                                              \
  for (auto y : x)                                                             \
    cout << y << s;                                                            \
  cout << "\n";
void dbg_out() { cout << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cout << ' ' << H;
  dbg_out(T...);
}
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#define endl "\n"
#define pb push_back
#define F first
#define S second
#define ll long long
#define mod 1000000007
#define all(v) v.begin(), v.end()
#define int long long
void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

void solve() {
  string pin;
  cin >> pin;
  int pointer = 1;
  int answer = 0;
  for (char digit : pin) {
    int val = digit - '0';
    if (val == 0) {
      val = 10;
    }
    if (pointer == 0) {
      pointer = 10;
    }
    answer += abs(pointer - val) + 1;
    pointer = val;
  }
  cout << answer << endl;
}