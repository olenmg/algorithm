/**
    CCW algorithm
    @CCW.cpp
    @author olenmg

    [BOJ] #11758
*/
#include <iostream>
using namespace std;

int CCW(int x1, int y1, int x2, int y2) {
	int cross_dot = x1 * y2 - x2 * y1;
	if(cross_dot > 0) return 1;
	else if(cross_dot < 0) return -1;
	else return 0;
}
int main(void) {
	int x[3], y[3];
	for(int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];
	cout << CCW(x[1] - x[0], y[1] - y[0], x[2] - x[1], y[2] - y[1]);
}
