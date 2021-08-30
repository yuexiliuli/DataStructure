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
//ʱ�临�Ӷ�O(NM)
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

//����ģʽƥ���㷨
//ʱ�临�Ӷ�O(N-M)
int Index(SString S,SString T){
    int k=1;
    int i=k,j=1;
    while(i<=S.length && j<=T.length){
        if(S.ch[i] == T.ch[j]){
            i++;
            j++; //�����ȽϺ���ַ�
        }else{
            k++; //�����һ���Ӵ�
            i=k;
            j=1;
        }
    }
    if(j>T.length)return k;//���ڴ�1��ʼ������j�����߽缴ƥ��ɹ�
    else return 0;
}

//��ģʽ��T��next����
void get_next(SString T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while (i<T.length)
    {
        if(j==0 || T.ch[i]==T.ch[j]){
            i++;j++;
            //��pi=pj����next[j+1] = next[j]
            next[i] = j;
        }else{
            //������j = next[j]��ѭ������
            j=next[j];
        }
    }
    
}

//KMP�㷨
int Index_KMP(SString S,SString T){
    int i=1,j=1;
    int next[7];
    get_next(T,next); //��next����
    while(i<S.length && j<T.length){
        if(j==0|S.ch[i]==T.ch[j]){
            i++;
            j++;   //�����ȽϺ���ַ�
        }else{
            j = next[j]; //ģʽ�������ƶ�
        }
    }
    if(j<T.length)
        return i-T.length; //ƥ��ɹ�
    else 
        return 0;
}

