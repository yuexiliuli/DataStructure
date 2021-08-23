#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int

typedef struct{
    char data[MaxSize];
    int top;
}SqStack;
//初始化栈
void InitStack(SqStack &S);
//判断是否为空
bool StackEmpty(SqStack S);
//新元素入栈
bool Push(SqStack &S,char x);
//栈顶元素出栈，用x返回
bool Pop(SqStack &S,char &x);

//括号匹配
bool bracketCheck(char str[],int length){
    SqStack S;
    InitStack(S);
    for(int i=0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            Push(S,str[i]); //扫描到左括号，入栈
        }
        else{
            if(StackEmpty(S))//扫描到右括号，且栈空
                return false; //匹配失败

            char topElem;
            Pop(S,topElem);//栈顶元素出栈
            if(str[i]==')' && topElem!='(')
                return false;
            if(str[i]==']' && topElem!='[')
                return false;
            if(str[i]=='}' && topElem!='{')
                return false;
        }
    }
    return StackEmpty(S);
}