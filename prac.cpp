#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char op){
    if(op=='+'|| op=='-')  return 1;
    if(op=='*'|| op=='/')  return 2;
    return 0;
    
}

string InfixToPostfix(const string &infix){
    string postfix=" ";
    stack<char>operatorStack;

    for(char ch:infix){
        if(isalnum(ch)){
            postfix+=ch;
        }
        else if(ch=='('){
            operatorStack.push(ch);
        }
        else if(ch==')'){
            while(!operatorStack.empty() && operatorStack.top()!='(' ){
                postfix+=operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();

        }
        else{
            while(!operatorStack.empty() && precedence(ch)<precedence(operatorStack.top())){
                postfix+=operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }
    while(!operatorStack.empty() ){
        postfix+=operatorStack.top();
        operatorStack.pop();
    }
    return postfix;
}


