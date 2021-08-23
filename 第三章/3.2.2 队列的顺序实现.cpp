#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int
typedef struct 
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

// ��ʼ��
bool InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0; 
}

// ���
bool EnQueue(SqQueue &Q,ElemType x){
    if((Q.rear + 1)%MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1)%MaxSize;
    return true;
}

// ���ӣ���ͷ��
bool DeQueue(SqQueue &Q,ElemType &x){
    if(Q.rear == Q.front) // �ж϶ӿ�
        return false; // �ӿ��򱨴�
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize; // ��ͷָ�����
    return true;
}

// ��ȡ��ͷԪ�ص�ֵ
bool GetHead(SqQueue &Q,ElemType &x){
    if(Q.rear == Q.front) // �ж϶ӿ�
        return false; // �ӿ��򱨴�
    x = Q.data[Q.front];
    return true;
}


int main()
{
    cout << "Hello, world!" << endl;
    system("pause");
    
    return 0;
}