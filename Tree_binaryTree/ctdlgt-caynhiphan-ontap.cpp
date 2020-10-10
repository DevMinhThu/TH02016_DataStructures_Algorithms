//Ho ten: Vu Minh Thu
//Lop: K63TH
//MaSV: 637865
//De: cay nhi phan

#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao cua truc nut cua cay
struct node
{
    char infor;
    node *left,*right;
};

//Khai bao ham cac phep toan duyet cay
void preOrder(node *T);//Duyet truoc
void inOrder(node *T);//duyet giua
void postOrder(node *T);//duyet sau

//===chuong trinh chinh===
int main()
{
    node *T,*N;

    //tao nut 1
    T = new node;
    T->infor = 'A';
    T->right = T->left = NULL;

    //tao nut 2
    N = new node;
    N->infor = 'B';
    N->right = N->left = NULL;
    T->left = N;

    //tao nut 3
    N = new node;
    N->infor = 'C';
    N->right = N->left = NULL;
    T->right = N;

    //tao nut 4
    N = new node;
    N->infor = 'D';
    N->right = N->left = NULL;
    T->left->right = N;

    cout<<"\nDuyet truoc: ";
    preOrder(T);
    cout<<"Duyet sau: ";
    postOrder(T);
    cout<<"\nDuyet giua: ";
    inOrder(T);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void preOrder(node *T)
{
    if(T=NULL) return;
    else
    {
        cout<<T->infor<<"  ";
        preOrder(T->left);
        preOrder(T->right);
    }
}

void inOrder(node *T)
{
    if(T==NULL) return;
    else
    {
        inOrder(T->left);
        cout<<T->infor<<"  ";
        inOrder(T->right);
    }
}

void postOrder(node *T)
{
    if(T==NULL) return;
    else
    {
        postOrder(T->left);
        postOrder(T->right);
        cout<<T->infor<<"  ";
    }
}
