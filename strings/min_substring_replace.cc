// Problem is to find the min no of characters to be replaced to satisfy a
// given condition

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n = 0;
  string str;
  cin >> n;
  cin >> str;

  int start = 0, end = 0, min_len = 500001;
  int a[256] = {0};
  // count all genes
  for (int i = 0; i < str.length(); i++)
    a[str[i]]++;
  // find min length gene replacement
  while (end < str.length()) {
    int s_till_i = 0;
    a[str[end]]--;
    if (a['A'] > n/4 || a['T'] > n/4 || a['G'] > n/4 || a['C'] > n/4) {
      end++;
      continue;
    }
    else {
      while (start <= end) {
        if (a[str[start]]+1 > n/4)
          break;
        else {
          a[str[start]]++;
          start++;
        }
      }
      s_till_i = end - start + 1;
    }
    min_len = min(min_len, s_till_i);
    end++;
  }
  cout << min_len << endl;
  return 0;
}
