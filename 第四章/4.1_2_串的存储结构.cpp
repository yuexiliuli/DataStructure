#include <iostream>
using namespace std;

#define MAXLEN 255
//��̬����
typedef struct 
{
    char ch[MAXLEN];
    int length;
}SString;



//��̬����
typedef struct{
    char * ch;
    int length;
    /*
    HString S;
    S.ch = (char *)malloc(MAXLEN * sizeof(cha));
    S.length = 0;
    */
}HString;

//��ʽ�洢
typedef struct StringNode{
    char ch[1];//char ch[4] ÿ���ڵ����
    struct StringNode *next;
}StringNode,*String;

