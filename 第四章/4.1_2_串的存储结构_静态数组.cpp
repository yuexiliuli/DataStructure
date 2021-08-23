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
        return false;
    }
    for(int i=pos;i<pos+len;i++){
        Sub.ch[i-pos+1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}
//�Ƚ��������Ĵ�С,��S>T,����ֵ>0;��S=T,�򷵻�ֵ=0;��S<T,�򷵻�ֵ<0
int StrCompare(SString S,SString T){
    for(int i = 1;i<S.length && i<T.length ;i++){
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    //ɨ����������ַ�����ͬ���򳤶ȳ��Ĵ�����
    return S.length - T.length;
}

//��λ����,������S�д����봮Tֵ��ͬ���Ӵ����򷵻����������е�һ�γ��ֵ�λ��
int Index(SString S, SString T){
    int i=1,n=S.length,m=T.length;
    SString sub;  //�����ݴ洮
    while(i<=n-m+1){
        SubString(sub,S,i,m);
        if(StrCompare(sub,T)!=0)++i;
        else return i; //�����Ӵ��������е�λ��
    }
    return 0;   //S�в�������T��ȵĵ��Ӵ�
}



