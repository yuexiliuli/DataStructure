#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int

//定义
typedef struct
{
    ElemType data[MaxSize];
    int length;
}SqList;

//在位置 i 插入元素
bool ListInsert(SqList &L,int i,ElemType e){
    if(i<1 || i>L.length+1) //判断 i 的范围
        return false;
    if(L.length>=MaxSize)   //存储空间满
        return false;
    for(int j=L.length;j>=i;j--){//将i及其之后元素后移
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

//删除第 i 个元素
bool ListDelete(SqList &L,int i,ElemType &e){
    if(i<1 || i>L.length) //判断 i 的范围
        return false;
    e = L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

//查找第一个元素值等于e的元素
int LocateElem(SqList L,ElemType e){
    int i;
    for(int i = 0;i<L.length;i++){
        if(L.data[i]==e)
            return i+1;
    }
    return 0;
}