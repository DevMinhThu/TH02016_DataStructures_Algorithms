#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

//Khai baocau truc nut nho
struct node
{
    int infor;
    node *left,*right;
};

struct Dlist
{
    node *L,*R;
};

//Khai báo hàm cài đặt các phép toán
void DLPostInsert(Dlist &LR,node *M,int x);
int DLDelete(Dlist &LR,node *M);
void DLDisplay(Dlist LR, bool leftToRight=1);

//===chương trình chính===
int main()
{
    Dlist LR = {NULL,NULL};

    cout<<endl;
    return 0;
}
//===định nghĩa hàm===
void DLPostInsert(Dlist &LR,node *M,int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    //2.Bo sung nut moi
    if(LR.L==NULL) LR.L=LR.R=N; //Hang doi rong
    else
        if(M==LR.R)
        {
            LR.R->right = N;
            N->left = LR.R;
            LR.R = N;
        }
        else
        {
            N->right = M->right;
            M->right->left = N;
            M->right = N;
            N->left = M;
        }
}

int DLDelete(Dlist &LR,node *M)
{
    //1.Kiem tra dslkk rong
    if(LR.L==NULL)
    {
        cout<<"DSLKK rong!";
        return -1;
    }

    //2.Thay doi lien ket
    if(LR.L==LR.R) LR.L=LR.R=NULL;//chi con 1 nut
    else
        if(M==LR.L) // truong hop M trung voi nut L
        {
            //L tro toi nut sau no
            LR.L = LR.L->right;
            LR.L->left = NULL;
        }
        else
            if(M==LR.R) // truong hop M trung voi nut R
            {
                LR.R = LR.R->left;
                LR.R->right = NULL;
            }
            else // truong hop con lai
            {
                M->left->right = M->right;
                M->right->left = M->left;
            }

    //3.Huy nut M
    delete M;
}

void DLDisplay(Dlist LR, bool leftToRight)
{
    node *P = leftToRight?LR.L:LR.R;

    while(P)
    {
        cout<<P->infor<<"  ";
        P = leftToRight?P->right:P->left;
    }
}

