//Ho ten: Vu Minh Thu
//Lop: K63TH
//MaSV: 637865
//De: hang doi phan tan

#include<iostream>
#include<stdio.h>

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

//Khai bao ham cai dat cac phep toan tren hang doi luu tru phan tan
void QInsert(Queue &FR,int x);//Bo sung phan tu x vao hang doi
int QDelete(Queue &FR);//Loai bo phan tu ra khoi hang doi
int isEmpty(Queue FR);//Kiem tra rong

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
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Bo sung vao sau R
    if(FR.R==NULL) FR.F=FR.R=N;
    else
    {
        //Noi nut R voi nut moi
        FR.R->link = N;
        //Tro R toi nut moi
        FR.R = N;
    }
}

int QDelete(Queue &FR)
{
    //1.Kiem tra rong
    if(FR.F==NULL)
    {
        cout<<"Hang doi rong!";
        return -1;
    }

    //2.Luu lai phan tu loai bo
    int tg = FR.F->infor;

    //Luu tru dia chi nut F
    node *P = FR.F;

    //3.Thay doi F
    if(FR.F==FR.R) // TH: co 1 phan tu
        FR.F=FR.R=NULL;
    else
    {
        //4.Tro F toi nut sau no
        FR.F=FR.F->link;
    }

    //5.Huy nut va tra ve
    delete P;
    return tg;
}

int isEmpty(Queue FR)
{
    return FR.R==NULL;
}
