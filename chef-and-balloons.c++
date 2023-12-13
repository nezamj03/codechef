/*
Chef and Balloons
Rating: 1399

Problem code: CHBLLNS
link:https://www.codechef.com/problems/CHBLLNS
*/

/*
Today a plane was hijacked by a maniac. All the passengers of the flight 
are taken as hostage. Chef is also one of them.
He invited one of the passengers to play a game with him. If he loses 
the game, he will release all the passengers, otherwise he will kill 
all of them. A high risk affair it is.
Chef volunteered for this tough task. He was blindfolded by Hijacker.
Hijacker brought a big black bag from his pockets. The contents of the bag is 
not visible. He tells Chef that the bag contains R red, G green and B blue colored balloons.
Hijacker now asked Chef to take out some balloons from the box such that there 
are at least K balloons of the same color and hand him over. If the taken out
balloons does not contain at least K balloons of the same color, then the hijacker
will shoot everybody. Chef is very scared and wants to leave this game as soon as
possible, so he will draw the minimum number of balloons so as to save the passengers. 
Can you please help scared Chef to find out the minimum number of balloons he should take out.

Idea : This is a simle "pigeonhole principle". We can use a small examle of K = 2.
In this case, worst case scenario has us choose one R, one G, and one B, then no matter
what our next draw is, we will have two of the same type.

This becomes slightly more complex when R ≠ G ≠ B. In the case where K < G, B, R, then it
simplifies to the same problem. If K > than one of (or multiple) of G, B, R, then our
process slighly differs. Consider K = 10, but we only have 6 red balloons. We can use the 
pigeonhole on our minimum -> 3 * 6 = 18. Now, we know after 18 draws, the "worst case" is 
we have 6 of each type. Then, we need K = 4 with "infinite" G and B.
*/

#include <iostream>
using namespace std;
#include <limits.h>

int main() {
	
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
}

void sol() {
    int r, g, b, k;
    cin >> r >> g >> b;
    cin >> k;

    long res = 0;
    int remainingColors = 3;
    int remainingBalloons[] = {r, g, b};

    while (k > 0) {
        if (k == 1) {
            cout << res + 1;
            return;
        }

        long remove = min(getRemovingFactor(remainingBalloons, 3, &remainingColors), k - 1);
        k -= remove;
        for (int i = 0; i < 3; i ++) {
            remainingBalloons[i] -= remove;
        }
        res += remainingColors * remove;
    }
}

int getRemovingFactor(int* a, int n, int* remainingColors) {
    *remainingColors = 0;
    int min = INT_MAX;
    for (int i = 0; i < n; i ++) {
        if (a[i] > 0) {
            *remainingColors += 1;
            if (a[i] < min) {
                min = a[i];
            }
        }
    }
    return min;
}