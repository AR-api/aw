#include<iostream>
using namespace std;

typedef struct BiTNode{                 //定义二叉链表
char data;
struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

void CreatTree(BiTree &T)             //创建二叉链表
{
    char ch;
    cin>>ch;
    if(ch=='#')
        T=NULL;
    else
    {
        T=new BiTNode;
        T->data=ch;
        CreatTree(T->lchild);
        CreatTree(T->rchild);
    }
}
//先序遍历二叉链表
void PreTree(BiTree T)
{
    if(T!=NULL)
    {
        cout<<T->data;
        PreTree(T->lchild);
        PreTree(T->rchild);
    }

}
//中序遍历二叉链表
void MidTree(BiTree T)
{
    if(T)
    {
        MidTree(T->lchild);
        cout<<T->data;
        MidTree(T->rchild);
    }
}
//后序遍历二叉链表
void LastTree(BiTree T)
{
    if(T){
        LastTree(T->lchild);
    LastTree(T->rchild);
    cout<<T->data;
    }
}
//统计并输出二叉树的的结点个数
int NodeCount(BiTree T)
{
    if(T==NULL)
    {
        return 0;
    }
    else{
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
    }
}
//输出二叉树的叶子结点的个数
int LeafCount(BiTree T)
{
    if(T==NULL)
        return 0;
    else
    {
        if (!T->lchild && !T->rchild) return 1;
        return LeafCount(T->lchild)+LeafCount(T->rchild);
    }
}
int main()
{
   BiTree T;
   cout<<"用键盘先序输入一个子符串:\n";
   CreatTree(T);
   cout<<"请选择以下操作的序号，来执行以下操作："<<endl
       <<"1.先序遍历二叉树"<<endl
       <<"2.中序遍历二叉链表"<<endl
       <<"3.后序遍历二叉链表"<<endl
       <<"4.统计并输出二叉树的的结点个数"<<endl
       <<"5.输出二叉树的叶子结点的个数"<<endl
       <<"6.结束"<<endl;
        int a;
        cout<<"你选择的操作是："<<endl;
        cin>>a;
        while(a>=1&&a<=5)
        {
           switch(a)
           {
               case 1:PreTree(T);cout<<endl;break;
               case 2:MidTree(T);cout<<endl;break;
               case 3:LastTree(T);cout<<endl;break;
               case 4:cout<<"二叉树的节点个数："<<NodeCount(T)<<endl;break;
               case 5:cout<<"二叉树叶子结点的个数："<<LeafCount(T)<<endl;break;
           }
           cout<<"请继续选择："<<endl;
           cin>>a;
       }
       cout<<"程序结束。"<<endl;
       return 0;
}

