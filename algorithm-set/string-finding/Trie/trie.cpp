/**
    Trie (Data Structure)
    @trie.cpp
    @author olenmg

    [BOJ] #14425
    p.s. This problem can be solved more easily by using hash table(i.e. map, set ...)
*/
#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    Trie* child[26];
public:
    bool finish;

    Trie() {
        finish = false;
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }

    ~Trie() {
        for(int i = 0; i < 26; i++)
            if(child[i] != NULL)
                delete child[i];
    }

    void insert(char *word) {
        if(*word == '\0') {
            finish = true;
            return;
        }
        int next = *word - 'a';
        if(child[next] == NULL)
            child[next] = new Trie;
        child[next]->insert(word + 1);
    }

    bool find(char *word) {
        if(*word == '\0')
            return finish;
        int next = *word - 'a';
        if(child[next] == NULL)
            return false;
        return child[next]->find(word + 1);
    }
};

int main(void) {
    cin.tie(NULL); ios::sync_with_stdio(false);

    int N, M;
    Trie *t = new Trie;
    cin >> N >> M;
    while(N--) {
        char word[501];
        cin >> word;
        t->insert(word);
    }

    int answer = 0;
    while(M--) {
        char word[501];
        cin >> word;
        if(t->find(word))
            answer++;
    }
    cout << answer;
}