#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int

typedef struct LinkNode{ //链式队列结点
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{ //链式队列
    LinkNode *front,*rear; //队列的队头和队尾
}LinkQueue;

//初始化队列（不带头节点）
void InitQueue(LinkQueue &Q){
    Q.front = NULL;
    Q.rear = NULL;
}

//判断队列是否为空（不带头结点）
bool IsEmpty(LinkQueue Q){
    if(Q.front == NULL)
        return true;
    else 
        return false;
}

//新元素入队（不带头节点）
void EnQueue(LinkQueue &Q,ElemType x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    //不带头结点的队列，第一个元素入队时需要特别处理
    if(Q.front = NULL){ //在空队列中插入第一个元素
        Q.front = s; //修改队头队尾指针
        Q.rear = s; 
    }else{
        Q.rear->next = s; //新节点插入到rear之后
        Q.rear = s; //修改表尾指针
    }
}

//队头元素出队（不带头节点）
bool Dequeue(LinkQueue &Q,ElemType &x){
    if(Q.front == NULL)
        return false;
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;  //修改front指针
    if(Q.rear == p){    //此次是最后一个节点出队
        Q.front = NULL; //空
        Q.rear = NULL;
    }
    free(p);
    return true;
}