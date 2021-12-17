//trie cpp implementation in cpp
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#define VOCABSIZE 27

class TrieNode{
public:
    TrieNode(char _value, bool _is_leaf){
        value = _value;
        is_leaf = _is_leaf;
        childrens = new TrieNode*[VOCABSIZE];
        n_childs = 0;
    }   
    void insert(string _value, int _index){
        int index = _value[_index] - 'a';
        if(_index+1 == _value.length()){
            if(childrens[index] == NULL){
                childrens[index] = new TrieNode(_value[_index], true);
                indexes.push_back(index);
            }else{
                childrens[index]->is_leaf = true;
            }
            n_childs++;
        }
        else{
            if(childrens[index] == NULL){
                childrens[index] = new TrieNode(_value[_index], false);
                indexes.push_back(index);
            }
            n_childs++;
            childrens[index]->insert(_value, _index+1);
        }
    }
    TrieNode* getRootOf(string _query, int _index){
        int index = _query[_index] - 'a';
        if(_index == _query.length()-1){
            return childrens[index];
        }else{
            if(childrens[index] == NULL)
                return nullptr;
            return childrens[index]->getRootOf(_query, _index+1);
        }
    }
    int n_childs;
    char value;
    bool is_leaf;
    TrieNode **childrens;
    vector<int> indexes;
};


class Trie{
public:
    Trie(){
        root = new TrieNode('F', false);
    }
    TrieNode *root;
    void insert(string _value){
        root->insert(_value, 0);
    }
    vector<string> getWords(string query){
        TrieNode* query_root = root->getRootOf(query, 0);
        vector<string> result;
        if(query_root == NULL)
            return vector<string>(); //empty results;
        if(query_root->is_leaf){
            result.push_back(query);
            return result;
        }else{
            return _getWords(query_root, query);
        }
    }

    vector<string> _getWords(TrieNode *start, string actualkey){
        vector<string> actual;
        TrieNode *tmpnode;
        for(int i = 0; i < start->indexes.size(); i++){
            tmpnode = start->childrens[start->indexes[i]];
            if(tmpnode->is_leaf){
                actual.push_back(actualkey+tmpnode->value);
            }
            if(tmpnode->childrens > 0){
                vector<string> tmp = _getWords(
                    tmpnode,
                    actualkey + tmpnode->value
                );
                actual.insert(actual.end(), tmp.begin(), tmp.end());
            }
        }
        return actual;
    }
    
private:

};

int main(){
    Trie *trie = new Trie();
    trie->insert("roberto");
    trie->insert("anuel");
    trie->insert("rioberto");
    trie->insert("riob");
    trie->insert("robert");
    vector<string> words = trie->getWords("a");
    for(auto word : words)
        cout << word << endl;
}