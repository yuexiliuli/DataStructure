#include <iostream>
using namespace std;

#define MaxSize 100
#define ElemType int

//线索二叉树节点
typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag; //tag=0：指针指向孩子，tag=1：指针是“线索”
}ThreadNode,*ThreadTree;

//二叉树的链式存储
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//辅助全局变量，用于查找节点p的前驱
// BiTNode *p;  //p指向目标节点
// BiTNode *pre = NULL;  //指向当前访问节点的前驱
// BiTNode *final=NULL;  //用于记录最终结果


//全局变量 pre ,指向当前访问节点的前驱，指向当前访问节点的前驱
ThreadNode *pre = NULL;  

//线索二叉树访问节点
void visit(ThreadNode *q){
    if(q->lchild==NULL){ //左子树为空，建立前驱线索
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL && pre->rchild==NULL){
        pre->rchild = q; //建立前驱节点的后继线索
        pre->rtag = 1;
    }
    pre = q;
}

//先序遍历二叉树，一边遍历一边线索化
void PreThread(ThreadTree T){
    if(T!=NULL){
        visit(T);               //访问根节点
        if(T->ltag==0)  //lchild不是前驱线索          
            PreThread(T->lchild);    //递归遍历左子树  
        PreThread(T->rchild);    //递归遍历右子树
    }
}

//中序遍历二叉树，一边遍历一边线索化
void InThread(ThreadTree T){
    if(T!=NULL){
        InThread(T->lchild);    //递归遍历左子树  
        visit(T);               //访问根节点
        InThread(T->rchild);    //递归遍历右子树
    }
}

//后序遍历二叉树，一边遍历一边线索化
void PostThread(ThreadTree T){
    if(T!=NULL){
        PostThread(T->lchild);    //递归遍历左子树  
        PostThread(T->rchild);    //递归遍历右子树
        visit(T);               //访问根节点       
    }
}

///////////////////////////////

//先序线索化二叉树T
void CreatePreThread(ThreadTree T){
    pre=NULL;         //初始
    if(T!=NULL){      //非空二叉树才能线索化
        PreThread(T);  //中序线索化二叉树
        if(pre->rchild ==NULL){
            pre->rtag = 1;  //处理遍历的最后一个节点
        }
    }
}

//中序线索化二叉树T
void CreateInThread(ThreadTree T){
    pre=NULL;         //初始
    if(T!=NULL){      //非空二叉树才能线索化
        InThread(T);  //中序线索化二叉树
        if(pre->rchild ==NULL){
            pre->rtag = 1;  //处理遍历的最后一个节点
        }
    }
}

//后序线索化二叉树T
void CreatePostThread(ThreadTree T){
    pre=NULL;         //初始
    if(T!=NULL){      //非空二叉树才能线索化
        PostThread(T);  //中序线索化二叉树
        if(pre->rchild ==NULL){
            pre->rtag = 1;  //处理遍历的最后一个节点
        }
    }
}







