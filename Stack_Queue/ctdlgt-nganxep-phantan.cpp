#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao nut nho
struct node
{
    int infor;
    node *link;
};

//Khai bao ham cai dat cac phep toan
void push(node* &T,int x);// bo sung x vao ngan xep
int pop(node* &T);// loai bo va tra x ra khoi ngan xep
void display(node *T);// duyet cac phan tu

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru phan tan
    node *T = NULL;

    push(T,2);
    push(T,1);
    push(T,3);
    push(T,9);
    push(T,6);

    cout<<"Cac phan tu day vao ngan xep la: ";
    display(T);

    printf("\n\nPhan tu dinh xoa khoi ngan xep la: %d ",pop(T));

    cout<<"\n\niCac phan tu cua ngan xep sau khi xoa phan tu dinh la: ";
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

    //2.bo sung nut moi vao ngan xep
    N->link = T;

    //3.Tro T len nut moi
    T = N;
}

int pop(node* &T)
{
    //1.Kiem tra ngan xep rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong!";
        return -1;
    }
    //2. Giu lai phan tu dinh loai bo
    int tg = T->infor;
    node *P = T;

    //3.Chuyen con tro xuong nut duoi
    T=T->link;

    //4.Huy nut va tra ve phan tu nut bi huy
    delete P;
    return tg;
}

void display(node *T)
{
    if(T==NULL)
    {
        cout<<"Ngan xep rog!";
    }
    else
    {
        node *P = T;
        while(P)
        {
            cout<<P->infor<<"  ";
            P=P->link;
        }
    }
}
