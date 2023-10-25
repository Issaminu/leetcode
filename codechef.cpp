#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int testNum = 0; testNum < T; testNum++) {
    int N, K;
    cin >> N >> K;
    vector<int> nums(N);
    int total = 0;
    for (int i = 0; i < N; i++) {
      cin >> nums[i];
      total += nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());
    int kidWeight = 0;
    for (int i = N - 1; i >= N - K; i--) {
      kidWeight += nums[i];
    }
    cout << kidWeight;
    int chefWeight = total - kidWeight;

    cout << chefWeight - kidWeight << endl;
  }
}
