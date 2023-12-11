/*
Ups and Downs

Problem code: ANUUND
link:http://www.codechef.com/COOK46/problems/ANUUND
*/

/*
Idea: Partition array into its smallest n/2 elements and largest n/2 elements
x = int[n]
l = int[n/2], h = int[n/2]
now we construct by placing elements in l and h one by one

Suppose we have solution = [s[0], s[1], ..., s[n-1]]
If s[i] has i even, then s[i-1] and s[i+1] must both be greater than s[i] because s[i] comes
from l and s[i-1] and s[i+1] comes from h and for any element l[i] in l, all elements h[j] in h are larger

In practice:

Use quickselect, we try to locate the element that has n/2 elements before it O(n)
Then, generate two array, one L and one H. Then, we reconstruct the solution
*/

/*
Concepts to learn: median of medians
*/

#include <iostream>
#include <random>
#include <cmath>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    sol();
	}
	return 0;
}

void swap(int* a, int idx1, int idx2) {
    int temp = a[idx1];
    a[idx1] = a[idx2];
    a[idx2] = temp;
}

int partition(int* a, int n, int l, int r) {

    int length = r - l + 1;
    if (length == 1) {
        return 0;
    }

    int partitionIdx = l + (rand() % length);
    swap(a, partitionIdx, r);
    int pivotElement = a[r];
    
    for (int i = l; i <= r; i ++) {
        for (int j = i + 1; j <= r; j ++) {
            if (j == r) {
                swap(a, r, i);
                return i;
            }
            if (a[j] < pivotElement) {
                swap(a, i, j);
                i ++;
            }
        }
    }    
    return r;
}

int select(int* a, int n, int k, int l, int r) {
    
    int partitionIdx = partition(a, n, l, r);
    if (partitionIdx == k) {
        return a[partitionIdx];
    } else if (partitionIdx > k) {
        return select(a, n, k, l, partitionIdx - 1);
    } else {
        return select(a, n, k - partitionIdx - 1, partitionIdx + 1, r);
    }
    
}

void sol() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int k;
    if (n % 2 == 1) {
        k = floor(n / 2);
    } else {
        k = floor(n / 2) - 1;
    }

    int partitionValue = select(a, n, k, 0, n - 1);
    
    for (int i = 0; i < n; i ++) {
        int indexBase = floor(i/ 2);
        if (i % 2 == 0) {
            cout << a[indexBase] << " ";
        } else {
            cout << a[indexBase + 1 + k] << " ";
        }
    }

    cout << endl;
}

