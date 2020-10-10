//Ho ten:
//Lop:
//MaSV:
//De: Tim kiem nhi phan

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

//Khai bao gop 2 bien F va R
struct Queue
{
    node *F,*R;
};

//Khai bao ham cai dat cac phep toan tren hang doi phan tan
void QInsert(Queue &FR,int x);
int QDelete(Queue &FR);
int isEmpty(Queue FR);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru hang doi phan tan
    Queue FR={NULL,NULL};

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

    //2.bo sung vao sau R
    if(FR.R==NULL) FR.F=FR.R=N;
    else
    {
        FR.R->link = N;
        FR.R = N;
    }
}

int QDelete(Queue &FR)
{
    //1.kiem tra rong
    if(FR.F==NULL)
    {
        cout<<"Hang doi phan tan rong!";
        return -1;
    }

    //2.luu lai phan tu loai bo
    int tg = FR.F->infor;

    //3.giu lai dia chi nut dau
    node *P = FR.F;

    //4.thay doi F
    if(FR.F==FR.R)//TH: chi co 1 nut
        FR.F=FR.R=NULL;
    else
    {
        //tro F toi nut ke tiep
        FR.F=FR.F->link;
    }

    //5.Huy nut va tra ve phan tu loai bo
    delete P;
    return tg;
}

int isEmpty(Queue FR)
{
    return FR.F==NULL;
}










