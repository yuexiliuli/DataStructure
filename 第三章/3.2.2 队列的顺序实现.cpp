#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int
typedef struct 
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

// 初始化
bool InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0; 
}

// 入队
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear + 1)%MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%MaxSize;
    return true;
}

// 出队（队头）
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear == Q.front) // 判断队空
        return false; // 队空则报错
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize; // 队头指针后移
    return true;
}

// 获取队头元素的值
bool GetHead(SqQueue &Q,ElemType &x){
    if(Q.rear == Q.front) // 判断队空
        return false; // 队空则报错
    x = Q.data[Q.front];
    return true;
}


int main()
{
    cout << "Hello, world!" << endl;
    system("pause");
    
    return 0;
}