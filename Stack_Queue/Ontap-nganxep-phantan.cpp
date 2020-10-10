//Ho ten:
//Lop:
//MaSV:
//De:

#include<iostream>
#include<stdio.h>
#include<fstream>

using namespace std;

//Khai bao nut nho
struct node
{
    int infor;
    node *link;
};

//Khai bao ham cai dat cac phep toan tren ngan xep phan tan
void push(node* &T,int x);
int pop(node* &T);
void display(node *T);
int isEmpty(node *T);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru ngan xep phan tan
    node *T = NULL;

    push(T,3);
    push(T,1);
    push(T,6);

    cout<<"Cac phan tu trong ngan xep la: ";
    display(T);

    printf("\n\nPhan tu loai bo la: %d",pop(T));
    cout<<"\n\nDay sau khi loai bo phan tu dinh la: ";
    display(T);

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void push(node* &T,int x)
{
    //1.tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.bo sung phan tu vao ngan xep
    if(T==NULL) T=N;//TH: truong hop ngan xep rong
    else
    {
        //noi nut moi vao nut sau no
        N->link = T;
        //tro T toi nut moi
        T=N;
    }
}

int pop(node* &T)
{
    //1.kiem tra truong hop rong
    if(T==NULL)
    {
        cout<<"rong!";
        return -1;
    }

    //luu lai phan tu dinh loai bo
    int tg = T->infor;

    //luu lai dia chi nut dinh
    node *P = T;

    //truong hop ngan xep co 1 phan tu
    if(T->link==NULL) T=NULL;
    else
    {
        T = T->link;
    }

    //huy nut va tra ve phan tu dinh loai bo
    delete P;
    return tg;
}

void display(node *T)
{
    if(T==NULL)
    {
        cout<<"Ngan xep rong!";
        return;
    }
    node *P = T;
    while(P)
    {
        cout<<P->infor<<"  ";
        //de P tro toi nut tiep theo
        P=P->link;
    }
}

int isEmpty(node *T)
{
    return T==NULL;
}









