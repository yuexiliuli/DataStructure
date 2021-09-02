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

/*
解：
∵我们要在【中序线索二叉树】中找【中序后继】
∴分情况讨论：建立与未建立线索
    ①当ltag==1，则 next = p->lchild
    ②当ltag==0，
        ∵我们要寻找中序后继，则必有左节点【左-中-右】
        ∴p必有左孩子
        ∵中序遍历--左-根-右
                   （左-根-右）-根-右
                   （（左-根-右）-根-右）-根-右
        ∴可以从上一步看出，访问【中序前驱】，
          相当于访问左子树的右孩子的右孩子的右....
        ∴弄一个寻找左子树的函数（Nextnode），
          一个寻找右孩子的函数（Lastnode）
∴利用Firstnode找第一个节点
  Nextnode找下一个节点，一直循环，直到结束
*/

//找到以P为根的子树中，最后一个被中序遍历的节点
ThreadNode *Lastnode(ThreadNode *p){
    //循环找到最右下节点（不一定是叶结点）
    while(p->rtag == 0) p = p->rchild;
    return p;
}

//在中序线索二叉树中找到节点P的前驱节点
ThreadNode *Prenode(ThreadNode *p){
    //右子树中最右下节点
    if(p->ltag==0)return Lastnode(p->lchild);
    else return p->lchild;  //ltag==1直接返回后继线索
}

//对中序线索二叉树进行逆向中序遍历（利用线索实现的非递归算法）
void Inorder(ThreadNode *T){
    //Firstnode找第一个节点
    //Nextnode找下一个节点，一直循环，直到结束
    for(ThreadNode *p = Lastnode(T);p!=NULL;p=Prenode(p)){
        //visit(p);
    }
}






