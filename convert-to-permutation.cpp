/*
Convert to Permutation
Rating: 1197

Problem code: PERMUTATION
link: https://www.codechef.com/problems/PERMUTATION
*/

/*
Given array A of size N, you may change A[i] to be A[i] + 1, where
this action has a cost of 1. Find the minimum number of operations 
required to convert the array A into a permutation of N. If it is 
not possible, return -1. 

Idea: Sort the array, and for each element, add enough to get it to its required position
in the permuted array of N. The complexity would be O(NlogN). This would give the 
correct solution. 

For any algorithm to go from A -> [1, ..., N] the same number of steps will
be used, so any solution is an optimal solution. Let me explain with a small 
example. Suppose we build the permutation constructively. When finding ai that 
could map to 1, we have {ai | ai <= 1}. Suppose this is {a1, a2, a3}. For any given
choice to map to 1, each of the other two are mapped to other solutions, giving +1
for each. Consequently, any choice will give the same solution.

By this, we do not necessarily need to sort the array, we must just check whether it is 
possible, then sum the hamming distances. How can we check if it is possible?

For every element i in [1, 2, ..., N], we need to be sure that there are at least i elements <= A[i].
We could do this one by one, but this gives O(N^2). The best approach is to just sort the arrays.
*/

#include <iostream>
#include <algorithm>
using namespace std;

void sol() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    sort(a, a + n);
    int solution = 0;
    for (int i = 0; i < n; i ++ ) {
        if(a[i] <= i + 1) {
            solution += i + 1 - a[i];
        }
        else {
            cout << -1 << endl;
            return;
        }
    }

    cout << solution << endl;

}

int main() {
	
	int t;
    cin >> t;

    while (t--) {
        sol();
    }
}
