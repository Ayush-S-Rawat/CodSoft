#include <bits/stdc++.h>

using namespace std;

class Trie {
    public:
        char data;
        Trie* children[26];
        bool isterminal;

        Trie() {
            data = '\0';
            isterminal = false;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
        Trie(char ch) {
            data = ch;
            isterminal = false;
            for(int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
        void insertion(string word) {
            if(word.length() == 0) {
                isterminal = true;
                return ;
            }
            int index = word[0] - 'a';
            Trie* next;
            if(children[index]) {
                next = children[index];
            }
            else {
                next = new Trie(word[0]);
                children[index] = next;
            }
            next->insertion(word.substr(1));
        }
        void traverse(Trie* root, string str = "") {
            if(root->isterminal) {
                cout << str << endl;
            }
            for(int i = 0; i < 26; i++) {
                if(children[i]) {
                    str.push_back(children[i]->data);
                    children[i]->traverse(children[i], str);
                    str.pop_back();
                }
            }
        }
        bool ispresent(string word) {
            if(word.length() == 0) {
                return isterminal;
            }
            int index = word[0] - 'a';
            if(children[index]) {
                return children[index]->ispresent(word.substr(1));
            }
            else {
                return false;
            }
        }
        bool deletion(string word) {
            if(ispresent(word)) {
                deletefromtrie(word);
                return true;
            }
            return false;
        }
        bool deletefromtrie(string word) {
            if(word.length() == 0) {
                isterminal = false;
                for(int i = 0; i < 26; i++) {
                    if(children[i]) {
                        return false;
                    }
                }
                return true;
            }
            int index = word[0] - 'a';
            if(children[index]->deletefromtrie(word.substr(1))){
                Trie* temp = children[index];
                children[index] = NULL;
                delete temp;
                for(int i = 0; i < 26; i++) {
                    if(children[i]) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
};

int main() {
    Trie* root = new Trie();
    root->insertion("ash");
    root->insertion("building");
    root->insertion("plant");
    root->insertion("plants");
    root->insertion("sand");
    root->insertion("build");
    root->insertion("buy");

    root->traverse(root);

    cout << endl;

    cout << "Is word 'ayush' present in the trie: " << root->ispresent("ayush") << endl;
    cout << "Is word 'sand' present in the trie: " << root->ispresent("build") << endl;

    cout << root->deletion("build") << endl;
    cout << root->deletion("sand") << endl;

    root->traverse(root);
    return 0;
}