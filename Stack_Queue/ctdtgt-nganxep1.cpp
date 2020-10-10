// Ho ten:
// MaSV:
// Lop:
// De:
#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao hang
#define N 32 // mảng S có 32 phần tử

//khai bao cau truc gop 2 bien S,T
struct Stack
{
    int T;
    int S[N];
};

//Khai bao ham cai dat cac phep toan
void push(Stack &ST, int x);
int pop(Stack &ST);
bool isEmpty(Stack ST);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru ke tiep cua ngan xep
    Stack ST = {-1}; // -1 vì mảng lưu trữ từ 0, do đó khởi tạo giá trị là -1 thì mảng mới rỗng

    //Khai bao bien
    int n, thuong;

    cout<<"Nhap vao 1 so nguyen duong: ";
    cin>>n;

    //Chuyen sang so nhi phan
    thuong = n;
    while(thuong)
    {
        push(ST,thuong%2);
        thuong/=2;
    }

    //Dua ra
    printf("So nhi phan cua %d la: ",n);
    while(!isEmpty(ST))
    {
        cout<<pop(ST);
    }

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void push(Stack &ST, int x)
{
    //1.Kiem tra ngan xep day
    if(ST.T==N-1)
    {
        cout<<"Ngan xep da day!";
        return;
    }

    //2-3. Tang T len 1 va dua x vao ngan xep
    ST.S[++ST.T] = x; // tiền tố, do đó sẽ thực hiện ++ST.T trước
}

int pop(Stack &ST)
{
    //1. Kiem tra ngan xep rong
    if(ST.T == -1)
    {
        cout<<"Ngan xep da rong!";
        return -1;
    }

    //2-3-4. Tra ve phan tu loai bo va giam T di 1
    return ST.S[ST.T--];
}

bool isEmpty(Stack ST)
{
    return ST.T == -1;
}
