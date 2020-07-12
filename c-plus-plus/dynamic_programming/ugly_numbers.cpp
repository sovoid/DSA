#include <stdc++.h>
using namespace std;

void print(const vector<int> &ugly) {
  for (auto el : ugly)
    cout << el << " ";
}

void ugly_numbers(int n) {
  vector<int> ugly;
  ugly.push_back(1);

  int i2, i3, i5;
  i2 = i3 = i5 = 0;

  while (ugly.size() != n) {
    int next_ugly = min(ugly[i2] * 2, min(ugly[i3] * 3, ugly[i5] * 5));

    if (next_ugly == ugly[i2] * 2) {
      i2++;
    }
    if (next_ugly == ugly[i3] * 3) {
      i3++;
    }
    if (next_ugly == ugly[i5] * 5) {
      i5++;
    }

    ugly.push_back(next_ugly);
  }

  print(ugly);
}

int main() {
  int n;
  cout << "Enter n: "
       << "\n";
  cin >> n;
  ugly_numbers(n);
  return 0;
}