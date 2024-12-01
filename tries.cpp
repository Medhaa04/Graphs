#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
// #define haha int main()
using namespace std;

class node{
    public:
    char ch;
    unordered_map<char,node*>h;
    bool isWordEnd;
    node(char c){
        ch=c;
        isWordEnd=false;
    }


};

class tries{
    public:
    node* root;
    tries(){
        root=new node('\0');
    }
    void addWord(char* word){
        node* temp=root;
        for(int i=0;i<word[i]!='\0';++i){
            char ch=word[i];
            if(temp->h.count(ch)==0){
                temp->h[ch]=new node(ch);
            }
            temp=temp->h[ch];

        }
        temp->isWordEnd=true;
    }

    bool searchWord(char* word){
        node* temp=root;
        for(int i=0;i<word[i]!='\0';++i){
            char ch=word[i];
            if(temp->h.count(ch)==0){
                return false;
                temp=temp->h[ch];
            }
            else{
                temp=temp->h[ch];
            }
        }
        return temp->isWordEnd;
    }

    void PrintAllWordsHelper(node* root,string &x){
        if(root->isWordEnd)  cout<<x<<endl;

        for(auto p:root ->h){
            x.push_back(p.first);
            PrintAllWordsHelper(p.second,x);
            x.pop_back();

        }

    }
    void PrintAllWords(char* word){
        node* temp=root;
        for(int i=0;i<word[i]!='\0';++i){
            char ch=word[i];
            if(temp->h.count(ch)==0){
                return ;
            }
            else{
                temp=temp->h[ch];
            }
        }
        string x(word);
        PrintAllWordsHelper(temp,x);
    }
};

int main(){
    tries t;
    t.addWord("Hello");
    t.addWord("Hell");
    t.addWord("He");
    t.addWord("Hero");
    t.addWord("Max");

    // while(1){
    //     char word[100];
    //     cin>>word;                                            //for adding and searching
    //     if(!t.searchWord(word) ) cout<<"Word nhi hai";
    //     else cout<<"Word hai";
    // }
    t.PrintAllWords("He");
}