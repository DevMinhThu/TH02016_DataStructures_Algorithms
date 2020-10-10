//Ho ten: Vu Minh Thu
//Lop: K63TH
//MaSV: 637865
//De: On tap full Ngan xep

/*Ngan xep ke tiep
#include<stdio.h>
#include<iostream>
#include<fstream>
#define N 32

using namespace std;

//khai bao cau truc gop 2 bien S va T cuar ngan xep
struct Stack
{
    int T;
    int S[N];
};

//khai bao ham cai dat cac phep toan tren ngan xep
void push(Stack &ST,int x);//bo sung phan tu vao ngan xep
int pop(Stack &ST);//loai bo phan tu ra khoi ngan xep
bool isEmpty(Stack ST);//kiem tra rong

//===chuong trinh chinh===
int main()
{
    Stack ST = {-1};

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void push(Stack &ST,int x)
{
    //1.Kiem tra day
    if(ST.T==N-1)
    {
        cout<<"Ngan xep day!";
        return;
    }

    //2.Tang T len 1 va dua x vao ngan xep
    ST.S[++ST.T] = x;
}

int pop(Stack &ST)
{
    //1.Kiem tra rong
    if(ST.T==-1)
    {
        cout<<"Ngan xep rong";
        return -1;
    }

    //2.Tra ve phan tu loai bo va giam T di 1
    return ST.S[ST.T--];
}

bool isEmpty(Stack ST)
{
    return ST.T==-1;
}
*/

//Ngan xep phan tan
#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

//Khai bao nut nho trong ngan xep phan tan
struct node
{
    int infor;
    node *link;
};

//Khai bao ham cai dat cac phep toan tren ngan xep phan tan
void push(node* &T,int x); // bo sung vao ngan xep phan tan
int pop(node* &T);//loai bo phan tu ra khoi ngan xep phan tan
void display(node *T);//duyet cac phan tu trong ngan xep phan tan

//===chuong trinh chinh===
int main()
{
    node *T = NULL;

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void push(node* &T,int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Bo sung nut moi vao ngan xep
    N->link = T;

    //3.Tro T toi nut tren
    T = N;
}

int pop(node* &T)
{
    //1.Kiem tra rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong!";
        return -1;
    }

    //2.Giu lai phan tu loai bo
    int tg = T->infor;

    //3.Luu lai dia chi phan tu loai bo
    node *P = T;

    //4.Cho T tro toi nut duoi no
    T = T->link;

    //5.Huy nut va tra ve phan tu loai bo
    delete P;
    return tg;
}

void display(node *T)
{
    //1.Kiem tra rong
    if(T==NULL)
    {
        cout<<"Ngan xep rong!";
        return;
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
