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
        return false;
    }
    for(int i=pos;i<pos+len;i++){
        Sub.ch[i-pos+1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}
//比较两个串的大小,若S>T,返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
int StrCompare(SString S,SString T){
    for(int i = 1;i<S.length && i<T.length ;i++){
        if(S.ch[i]!=T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    //扫描过的所有字符都相同，则长度长的串更大
    return S.length - T.length;
}

//定位操作,若主串S中存在与串T值相同的子串，则返回它在主串中第一次出现的位置
//时间复杂度O(NM)
int Index(SString S, SString T){
    int i=1,n=S.length,m=T.length;
    SString sub;  //用于暂存串
    while(i<=n-m+1){
        SubString(sub,S,i,m);
        if(StrCompare(sub,T)!=0)++i;
        else return i; //返回子串在主串中的位置
    }
    return 0;   //S中不存在与T相等的的子串
}

//朴素模式匹配算法
//时间复杂度O(N-M)
int Index(SString S,SString T){
    int k=1;
    int i=k,j=1;
    while(i<=S.length && j<=T.length){
        if(S.ch[i] == T.ch[j]){
            i++;
            j++; //继续比较后继字符
        }else{
            k++; //检查下一个子串
            i=k;
            j=1;
        }
    }
    if(j>T.length)return k;//由于从1开始，所以j超出边界即匹配成功
    else return 0;
}

//求模式串T的next数组
void get_next(SString T,int next[]){
    int i=1,j=0;
    next[1]=0;
    while (i<T.length)
    {
        if(j==0 || T.ch[i]==T.ch[j]){
            i++;j++;
            //若pi=pj，则next[j+1] = next[j]
            next[i] = j;
        }else{
            //否则令j = next[j]，循环继续
            j=next[j];
        }
    }
    
}

//KMP算法
int Index_KMP(SString S,SString T){
    int i=1,j=1;
    int next[7];
    get_next(T,next); //求next数组
    while(i<S.length && j<T.length){
        if(j==0|S.ch[i]==T.ch[j]){
            i++;
            j++;   //继续比较后继字符
        }else{
            j = next[j]; //模式串向右移动
        }
    }
    if(j<T.length)
        return i-T.length; //匹配成功
    else 
        return 0;
}

