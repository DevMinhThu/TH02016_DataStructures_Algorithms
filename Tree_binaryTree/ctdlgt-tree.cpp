#include<iostream>
#include<stdio.h>

using namespace std;

//khai cau cau truc node cua tree
struct node
{
    char infor;
    node *left;
    node *right;
};

//khai bao ham cac phep toan duyet cay
void preOrder(node *T); //duyet truoc
void inOrder(node *T); //duyet giua
void postOrder(node *T); //duyet sau

//===chuong trinh chinh===
int main()
{
    node *T,*N;

    //tao nut 1
    T = new node;
    T->infor = '/';
    T->left = T->right = NULL;

    //tao nut 2
    N = new node;
    N->infor = 'a';
    N->left = N->right = NULL;
    T->left = N;

    //tao nut 3
    N = new node;
    N->infor = '-';
    N->left = N->right = NULL;
    T->right = N;

    //tao nut 4
    N = new node;
    N->infor = 'b';
    N->left = N->right = NULL;
    T->right->left = N;

    //tao nut 5
    N = new node;
    N->infor = 'c';
    N->left = N->right = NULL;
    T->right->right = N;

    cout<<"Duyet sau: ";
    postOrder(T);
    cout<<"\nDuyet giua: ";
    inOrder(T);
    cout<<"\nDuyet truoc: ";
    preOrder(T);

    cout<<endl;
    return 0;
}

//===dinh nghia ham===
void preOrder(node *T)
{
    if(T==NULL) return;
    else
    {
        cout<<T->infor<<" ";
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
        cout<<T->infor<<" ";
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
        cout<<T->infor<<" ";
    }
}
