#include<iostream>
using namespace std;

typedef struct BiTNode{                 //�����������
char data;
struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

void CreatTree(BiTree &T)             //������������
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
//���������������
void PreTree(BiTree T)
{
    if(T!=NULL)
    {
        cout<<T->data;
        PreTree(T->lchild);
        PreTree(T->rchild);
    }

}
//���������������
void MidTree(BiTree T)
{
    if(T)
    {
        MidTree(T->lchild);
        cout<<T->data;
        MidTree(T->rchild);
    }
}
//���������������
void LastTree(BiTree T)
{
    if(T){
        LastTree(T->lchild);
    LastTree(T->rchild);
    cout<<T->data;
    }
}
//ͳ�Ʋ�����������ĵĽ�����
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
//�����������Ҷ�ӽ��ĸ���
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
   cout<<"�ü�����������һ���ӷ���:\n";
   CreatTree(T);
   cout<<"��ѡ�����²�������ţ���ִ�����²�����"<<endl
       <<"1.�������������"<<endl
       <<"2.���������������"<<endl
       <<"3.���������������"<<endl
       <<"4.ͳ�Ʋ�����������ĵĽ�����"<<endl
       <<"5.�����������Ҷ�ӽ��ĸ���"<<endl
       <<"6.����"<<endl;
        int a;
        cout<<"��ѡ��Ĳ����ǣ�"<<endl;
        cin>>a;
        while(a>=1&&a<=5)
        {
           switch(a)
           {
               case 1:PreTree(T);cout<<endl;break;
               case 2:MidTree(T);cout<<endl;break;
               case 3:LastTree(T);cout<<endl;break;
               case 4:cout<<"�������Ľڵ������"<<NodeCount(T)<<endl;break;
               case 5:cout<<"������Ҷ�ӽ��ĸ�����"<<LeafCount(T)<<endl;break;
           }
           cout<<"�����ѡ��"<<endl;
           cin>>a;
       }
       cout<<"���������"<<endl;
       return 0;
}

