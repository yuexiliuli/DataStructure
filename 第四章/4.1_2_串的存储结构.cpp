#include <iostream>
using namespace std;

#define MAXLEN 255
//静态数组
typedef struct 
{
    char ch[MAXLEN];
    int length;
}SString;



//动态数组
typedef struct{
    char * ch;
    int length;
    /*
    HString S;
    S.ch = (char *)malloc(MAXLEN * sizeof(cha));
    S.length = 0;
    */
}HString;

//链式存储
typedef struct StringNode{
    char ch[1];//char ch[4] 每个节点存多个
    struct StringNode *next;
}StringNode,*String;

