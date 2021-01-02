/**
    KMP algorithm
    @KMP-algorithm.cpp
    @author olenmg

    [BOJ] #1786
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string s) {
    int len = s.length();
    int m = 0;
    vector<int> pi(len, 0);
    
    for(int i = 1; i < len; i++) {
        while(m > 0 && s[m] != s[i])
            m = pi[m - 1];
        if(s[m] == s[i])
            pi[i] = ++m;
    }
    return pi;
}
int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    string T, P;
    getline(cin, T);
    getline(cin, P);
    vector<int> pi = getPi(P);
    int t_len = T.length();
    int p_len = P.length();
    int m = 0; 

    vector<int> pos;
    for(int i = 0; i < t_len; i++) {
        while(m > 0 && T[i] != P[m])
            m = pi[m - 1];
        if(T[i] == P[m])
            m++;
        if(m == p_len) {
            pos.push_back(i - p_len + 1);
            m = pi[m - 1];
        }
    }
    cout << (int)pos.size() << "\n";
    for(int i : pos)
        cout << i + 1 << " ";
}