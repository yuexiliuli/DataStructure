#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int

typedef struct{
    char data[MaxSize];
    int top;
}SqStack;
//��ʼ��ջ
void InitStack(SqStack &S);
//�ж��Ƿ�Ϊ��
bool StackEmpty(SqStack S);
//��Ԫ����ջ
bool Push(SqStack &S,char x);
//ջ��Ԫ�س�ջ����x����
bool Pop(SqStack &S,char &x);

//����ƥ��
bool bracketCheck(char str[],int length){
    SqStack S;
    InitStack(S);
    for(int i=0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            Push(S,str[i]); //ɨ�赽�����ţ���ջ
        }
        else{
            if(StackEmpty(S))//ɨ�赽�����ţ���ջ��
                return false; //ƥ��ʧ��

            char topElem;
            Pop(S,topElem);//ջ��Ԫ�س�ջ
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