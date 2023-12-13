/*
Help Voldemort 
Rating: 1302

Problem code: HELPVOLD
https://www.codechef.com/problems/HELPVOLD
*/

/*
The story of Harry Potter begins when Lord Voldemort arrives at his 
house at Privet Drive. Harry's house has N rooms placed in one line. 
Each room has its own energy level and no two rooms have exactly same
energy. Lord Voldemort arrives at the room which has lowest energy 
while Harry is at the room having highest energy.

Lord Voldemort has to reach Harry's room. Voldemort can travel from a room 
having energy X to any other room having energy Y such that |X-Y| is minimum
and that room hasn't been visited before. The energy required for moving 
from room having energy X to room having energy Y is X*Y.

Idea: It seems like Voldemort's actions are deterministic because Voldemort will 
strictly go up to the next highest energy level. The most simple way to do this
is to sort the list and continue accordingly with O(NlogN). I can't see a better way 
to consistently go to the next biggest room. A potential alternate solution is 
using a heap and popping elements sequentially, but beceause we will need to pop
all elements, it also becomes O(N + NLogN).
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;
    long e[n];
    for (int i = 0; i < n; i ++) {
        cin >> e[i];
    }

    sort(e, e + n);

    long res = 0;
    int i = 1;
    while (i < n) {
        res += e[i] * e[i - 1];
        i += 1;
    }

    cout << res << endl;
    return 0;
}
