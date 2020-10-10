//Ho ten: Vu Minh Thu
//Lop: K63TH
//MaSV: 637865
//De: On tap full Hang doi

/*
//Hang doi ke tiep
#include<stdio.h>
#include<iostream>
#include<fstream>

//Khai bao hang
#define N 50

using namespace std;

//Khai bao cau truc hang doi
struct Queue
{
    int F,R;
    int Q[N];
};

//Khai bao ham cai dat cac phep toan tren hang doi ke tiep
void CQInsert(Queue &FR,int x);
int CQDelete(Queue &FR);
bool CQIsEmpty(Queue FR);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc hang doi ke tiep
    Queue FR = {-1,-1};

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void CQInsert(Queue &FR,int x)
{
    //1.Kiem tra hang doi day
    if(FR.F==0 && FR.R==N-1 || FR.R+1==FR.F)
    {
        cout<<"Hang doi day!";
        return;
    }

    //2.Thay doi chi so R
    if(FR.R==-1) FR.F=FR.R=0;
    else if(FR.R==N-1) FR.R=0;
    else FR.R++;

    //3.Them x vao hang doi
    FR.Q[FR.R]=x;
}

int CQDelete(Queue &FR)
{
    //1.Kiem tra hang doi rong
    if(FR.F==-1)
    {
        cout<<"Hang doi rong!";
        return -1;
    }

    //2.Giu lai phan tu loai bo
    int tg = FR.Q[FR.F];

    //3.Thay doi chi so F
    if(FR.F==FR.R) FR.F=FR.R=-1; // Truong hop hang doi chi con 1 phan tu
    else if(FR.F==N-1) FR.F=0; // Truong hop quay vong
    else FR.F++;

    //4.Xoa phan tu ra khoi ngan xep
    return tg;
}

bool CQIsEmpty(Queue FR)
{
    return FR.F == -1;
}
*/


//Hang doi phan tan
#include<stdio.h>
#include<iostream>
#include<fstream>

using namespace std;

//Khai bao nut nho trong hang doi phan tan
struct node
{
    int infor;
    node *link;
};

//Khai bao gop 2 bien F va R
struct Queue
{
    node *F,*R;
};

//Khai bao ham cai dat cac phep toan tren hang doi phan tan
void QInsert(Queue &FR,int x); //bo sung phan tu vao hang doi phan tan
int QDelete(Queue &FR); //xoa phan tu khi hang doi phan tan
int QEmpty(Queue FR);//kiem tra hang doi rong

//===chuong trinh chinh===
int main()
{
    Queue FR = {NULL,NULL};

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void QInsert(Queue &FR,int x)
{
    //1.tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.bo sung phan tu vao hang doi
    if(FR.R==NULL) FR.F=FR.R=N; // hang doi rong
    else FR.R->link = N; //bo sung vao dau R

    //3.cho R tro toi nut moi
    FR.R = N;
}

int QDelete(Queue &FR)
{
    //1.kiem tra rong
    if(FR.F==NULL)
    {
        cout<<"Hang doi phan tan rong!";
        return -1;
    }

    //2.luu lai phan tu loai bo va dia chi cua no
    int tg = FR.F->infor;
    node *P = FR.F->link;

    //3.thay doi F
    if(FR.F==FR.R) FR.F=FR.R=NULL; //hang doi co 1 phan tu
    else FR.F = FR.F->link; // tro F cho toi nut sau no

    //4.huy va tra ve nut
    delete P;
    return tg;
}

int QEmpty(Queue FR)
{
    return FR.R==NULL;
}


