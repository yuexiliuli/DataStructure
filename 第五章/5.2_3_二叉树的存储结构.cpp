#include <iostream>
using namespace std;

#define MaxSize 100
#define ElemType int

// ˳��洢�ṹ
struct TreeNode
{
    ElemType value;  //�ڵ��е�����Ԫ��
    bool isEmpty;  //�ڵ��Ƿ�Ϊ��
};

/*��ʼ��
TreeNode t[MaxSize];
for(int i=0;i<MaxSize;i++){
    t[i].isEmpty = true;
}
*/

//�����������Ҹ��ڵ㷽�㣩
/*
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
    struct BiTNode *parent;
}BiTNode,*BiTree;
*/

//����������ʽ�洢
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//��ʽ���нڵ�
typedef struct LinkNode{
    BiTNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct {
    LinkNode *front,*rear;
}LinkQueue;

//��ʼ�����У���ͷ�ڵ㣩
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

//�ж϶����Ƿ�Ϊ�գ���ͷ�ڵ㣩
bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    else 
        return false;
}

//��Ԫ����ӣ���ͷ�ڵ㣩
void EnQueue(LinkQueue &Q,BiTNode *x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; //�½ڵ���뵽rear֮��
    Q.rear = s; //�޸ı�βָ��
}

//��ͷԪ�س��ӣ���ͷ�ڵ㣩
bool DeQueue(LinkQueue &Q,BiTNode *x){
    if(Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next; //�޸�ͷ��㷵�ص�nextָ��
    if(Q.rear == p)          //�˴������һ���ڵ����
        Q.rear = Q.front;    //�޸�rearָ��
    free(p);
    return true;
}

void visit(BiTree T){
    cout<<T->data<<endl;
}

//�������
void PreOrder(BiTree T){
    if(T!=NULL){
        visit(T); //���ʸ��ڵ�
        PreOrder(T->lchild);  //�ݹ����������
        PreOrder(T->rchild);  //�ݹ����������
    }
}

//�������
void InOrder(BiTree T){
    if(T!=NULL){
        InOrder(T->lchild);  //�ݹ����������
        visit(T);            //���ʸ��ڵ�
        InOrder(T->rchild);  //�ݹ����������
    }
}

//�������
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);  //�ݹ����������
        PostOrder(T->rchild);  //�ݹ����������
        visit(T);  //���ʸ��ڵ�
    }
}

//�������
void LevelOrder(BiTree T){
    LinkQueue Q;
    InitQueue(Q);  //��ʼ����������
    BiTree p;
    EnQueue(Q,T);  //�����ڵ����
    while(!IsEmpty(Q)){  //���в�Ϊ����ѭ��
        DeQueue(Q,p);    //��ͷ�ڵ����
        visit(p);        //���ʳ��ӽڵ�
        if(p->lchild!=NULL)
            EnQueue(Q,p->lchild);  //�������
        if(p->rchild!=NULL)
            EnQueue(Q,p->rchild);  //�Һ������
    }
}

int main(){
    //����һ�ÿ���
    BiTree root = NULL;
    //������ڵ�
    root = (BiTree)malloc(sizeof(BiTree));
    root->data=1;
    root->lchild = NULL;
    root->rchild = NULL;
    //�����½ڵ�
    BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
    p->data=2;
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; //��Ϊ���ڵ������
}



