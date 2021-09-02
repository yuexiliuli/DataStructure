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
∵我们要在【先序线索二叉树】中找【先序后继】
∴分情况讨论：建立与未建立线索
    ①当rtag==1，则 next = p->rchild
    ②当rtag==0，
        ∵我们要寻找先序后继，则必有右节点【根-左-右】
        ∴p必有右孩子
        ∵先序遍历--根-左-右
        ∴分情况讨论：有无左孩子
            ①有左孩子：则先序后继为左孩子
                   根-左-右
                   根-（根-左-右）-右
                   根-（根-（根-左-右）-右）-右
            ②无左孩子：则先序后继为右孩子
                   根-右
                   根-（根-左-右）
                   根-（根-（根-左-右）-右）

        ∴可以从上一步看出，访问【先序后继】，
          相当于访问左右孩子....
*/






