#include <iostream>
using namespace std;

#define MAXLEN 255
//��̬����
typedef struct 
{
    char ch[MAXLEN];
    int length;
}SString;

//���Ӵ�����Sub����S�ĵ�pos���ַ��𣬳���Ϊlen���ִ�
bool SubString(SString &Sub,SString S,int pos,int len){
    //�Ӵ���ΧԽ��
    if(pos+len-1>S.length){
        
    }
}