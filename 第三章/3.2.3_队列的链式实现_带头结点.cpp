#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int

typedef struct LinkNode{ //链式队列结点
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{ //链式队列
    LinkNode *front,*rear; //队列的队头和队尾，如果需要时常计算，可以弄length一类的变量
}LinkQueue;

//初始化队列（带头节点）
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//判断队列是否为空（带头节点）
bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    else 
        return false;
}

//新元素入队（带头节点）
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; //新节点插入到rear之后
    Q.rear = s; //修改表尾指针
}

//队头元素出队（带头节点）
bool DeQueue(LinkQueue &Q,ElemType &x){
    if(Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next; //修改头结点返回的next指针
    if(Q.rear == p)          //此次是最后一个节点出队
        Q.rear = Q.front;    //修改rear指针
    free(p);
    return true;
}

