#include <bits/stdc++.h>

using namespace std;

void kmp_process(string text, int* b, int len) {
  int i = 0, j = -1;
  b[0] = -1;
  while (i < len) {
    while (j >= 0 && text[i] != text[j]) j = b[j];
    i++;
    j++;
    b[i] = j;
  }
}

bool kmp_search(string text, string in, int* b) {
  int l1 = text.length();
  int l2 = in.length(), i = 0, j = 0;

  while (i < l1) {
    while (j >= 0 && text[i] != in[j]) j = b[j];
    i++; j++;
    if (j == l2) {
      return true;
      // j = b[j]; // for next possible match
    }
  }
  return false;
}

int main() {
  string text, in;
  cin >> text;
  cin >> in;
  const int len = text.length();
  int b[len];

  kmp_process(in, b, len);
  if (kmp_search(text, in, b)) {
    cout << "Found";
  } else {
    cout << "Not found";
  }

  return 0;
}
