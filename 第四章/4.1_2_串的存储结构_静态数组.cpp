#include <iostream>
using namespace std;

#define MAXLEN 255
//静态数组
typedef struct 
{
    char ch[MAXLEN];
    int length;
}SString;

//求子串，用Sub返回S的第pos个字符起，长度为len的字串
bool SubString(SString &Sub,SString S,int pos,int len){
    //子串范围越界
    if(pos+len-1>S.length){
        
    }
}