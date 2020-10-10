/*
#include<iostream>
#include<stdio.h>

using namespace std;

#define N 32

//khai bao cau truc luu tru ke tiep trong stack
struct Stack
{
    int T;
    int S[N];
};

//Khai bao ham cai dat cac phep toan trong stack
void push(Stack &ST,int x);
int pop(Stack &ST);
bool isEmpty(Stack ST);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru ke tiep cua stack
    Stack ST = {-1};

    //Khai bao bien
    int thuong, n;

    cout<<"Nhap vao gia tri n can chuyen tu he 10 sang 16: ";
    cin>>n;

    //chuyen doi
    thuong=n;
    while(thuong)
    {
        push(ST,thuong%16);
        thuong /= 16;
    }

    printf("He 16 cua %d la: ",n);
    while(!isEmpty(ST))
    {
        int du=pop(ST);
        if(du<10) cout<<du;
        else printf("%c",du+55);
    }

    cout<<endl;
    return 0;
}
//===chuong trinh chinh===
void push(Stack &ST,int x)
{
    //1.Kiem tra ngan xep day
    if(ST.T == N-1) cout<<"Stack da day!";

    //2-3.Tang T len 1 va bo sung x vao stack
    ST.S[++ST.T] = x;
}

int pop(Stack &ST)
{
    //1.kiem tra ngan xep rong
    if(ST.T == -1)
        cout<<"Stack rong!";

    //2-3-4. Tra ve phan tu loai bo va giam T di 1
    return ST.S[ST.T--];
}

bool isEmpty(Stack ST)
{
    return ST.T == -1;
}
*/

/*
//===Hang doi luu tru ke tiep===
#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao hang
#define N 32

//khai bao cau truc hang doi
struct Queue
{
    int F,R;
    int Q[N];
};

//Khai bao hamcai dat cac phep toan
void CQInsert(Queue &CQ,int x);
int CQDelete(Queue &CQ);
bool isEmpty(Queue ST);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc hang doi
    Queue CQ = {-1,-1};


    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void CQInsert(Queue &CQ,int x)
{
    //1.Kiem tra hang doi day
    if(CQ.F==0 && CQ.R==N-1 || CQ.R+1==CQ.F)
        cout<<"Hang doi day!";

    //2.Thay doi chi so
    //Th1: Hang doi chua co phan tu nao
    if(CQ.F==CQ.R==-1)
    {
        CQ.F++;
        CQ.R++;
    }
    else if(CQ.R==N-1) //th2: quay vong
    {
        CQ.R ==0;
    }
    else //th3: O giua
    {
        CQ.R++;
    }

    //3.bo sung x vao hang doi
    CQ.Q[CQ.R] = x;
}

int CQDelete(Queue &CQ)
{
    //1. Kiem tra rong
    if(CQ.F==CQ.R==-1)
    {
        cout<<"Hang doi rong";
        return 1;
    }

    int tg;
    tg = CQ.Q[CQ.F];

    //3. Thay doi chi so
    if(CQ.R==CQ.F)
    {
        CQ.R=CQ.F=-1;
    }
    else if(CQ.F==N-1)
    {
        CQ.F = 0;
    }
    else
    {
        CQ.F++;
    }

    //4. Tra ve phan tu loai bo
    return tg;
}

bool isEmpty(Queue CQ)
{
    return CQ.R==CQ.F==-1;
}
*/




















