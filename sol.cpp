#include <bits/stdc++.h>

using namespace std;

int main() {                            
  ios::sync_with_stdio(false);
  cin.tie(0);          
  int tt;
  cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			// create counter to check if a range can be created (b >= a + 2)
			int cnt = 0;
			// create a temporary variable to traverse the list
			int tmp = i;
			// create a saved variable to store the initial element of the range
			int saved = i;
			for (int j = i + 1; j < n; j++) {
				// traverse the list by checking if it's in non-decreasing order but with
				// a minimal difference of 1
				if (a[j] - a[tmp] == 1) {
					// increment the temporary variable to get the indices that will be skipped
					tmp++;
					// increment the counter to check if it's valid to be a range
					cnt++;
				} else {
					// otherwise, break the loop completely
					break;
				}
			}    
			if (cnt >= 2) {
				// if it's valid to be a range then store the tmp - 1 value to i to skip the elements
				// we subtract 1 from tmp so that the last element of the range won't get skipped
				i = tmp - 1;
				// print the starting element with the saved index together with "..."
				cout << a[saved] << "...";
			} else {
				// otherwise, print the element itself
				cout << a[i] << (i < n - 1 ? ',' : ' ');
			}
		}
		cout << '\n';
	}
  return 0;
}      
