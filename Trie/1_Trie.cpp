#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct Node{
    Node *links[26];
    bool flag=false;    

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void addChar(char ch){
        Node *newnode = new Node();
        links[ch-'a'] = newnode;
    }

    Node *getNextChar(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    Node *root;
    public : 
        Trie(){
            root=new Node();
        }

        void insert(string s){
            Node *node = root;
            for(int i=0; i<s.size(); i++){
                if(!node->containsKey(s[i])){
                    node->addChar(s[i]);
                }
                node=node->getNextChar(s[i]);
            }
            node->setEnd();
        }

        bool search(string s){
            Node *node = root;
            for(int i=0; i<s.size(); i++){
                if(!node->containsKey(s[i]))
                    return false;
                node=node->getNextChar(s[i]);
            }
            return node->isEnd();
        }

        bool startsWith(string s){
            Node *node = root;
            for(int i=0; i<s.size(); i++){
                if(!node->containsKey(s[i]))
                    return false;
                node=node->getNextChar(s[i]);
            }
            return true;
        }
};

int main()
{
    return 0;
}