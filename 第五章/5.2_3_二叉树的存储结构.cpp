#include <iostream>
using namespace std;

#define MaxSize 100
#define ElemType int

// 顺序存储结构
struct TreeNode
{
    ElemType value;  //节点中的数据元素
    bool isEmpty;  //节点是否为空
};

/*初始化
TreeNode t[MaxSize];
for(int i=0;i<MaxSize;i++){
    t[i].isEmpty = true;
}
*/

//三叉链表（查找父节点方便）
/*
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
    struct BiTNode *parent;
}BiTNode,*BiTree;
*/

//二叉树的链式存储
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//链式队列节点
typedef struct LinkNode{
    BiTNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front,*rear;
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
void EnQueue(LinkQueue &Q,BiTNode *x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; //新节点插入到rear之后
    Q.rear = s; //修改表尾指针
}

//队头元素出队（带头节点）
bool DeQueue(LinkQueue &Q,BiTNode *x){
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

void visit(BiTree T){
    cout<<T->data<<endl;
}

//先序遍历
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T); //访问根节点
        PreOrder(T->lchild);  //递归遍历左子树
        PreOrder(T->rchild);  //递归遍历右子树
    }
}

//先序遍历
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);  //递归遍历左子树
        visit(T);            //访问根节点
        InOrder(T->rchild);  //递归遍历右子树
    }
}

//先序遍历
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);  //递归遍历左子树
        PostOrder(T->rchild);  //递归遍历右子树
        visit(T);  //访问根节点
    }
}

//层序遍历
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);  //初始化辅助队列
    BiTree p;
    EnQueue(Q,T);  //将根节点入队
    while(!IsEmpty(Q)){  //队列不为空则循环
        DeQueue(Q,p);    //队头节点出队
        visit(p);        //访问出队节点
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);  //左孩子入队
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);  //右孩子入队
    }
}

int main(){
    //定义一棵空树
    BiTree root = NULL;
    //插入根节点
    root = (BiTree)malloc(sizeof(BiTree));
    root->data=1;
    root->lchild = NULL;
    root->rchild = NULL;
    //插入新节点
    BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
    p->data=2;
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; //作为根节点的左孩子
}



