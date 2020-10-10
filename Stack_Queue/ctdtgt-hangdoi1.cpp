// Ho ten:
// MaSv:
// Lop:
// De:

#include<iostream>
#include<stdio.h>

using namespace std;

//khai bao hang
#define N 32

//khai bao kieu struc
struct Queue
{
    int F,R;
    int Q[N];
};

//khai bao cac phep toan cua hang doi
// &CQ chuyền tham chiếu vì khi thêm phần tử sẽ thay đổi CQ
void CQInsert(Queue &CQ, int x);
int CQDelete(Queue &CQ);

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc cua hang doi
    Queue CQ = {-1,-1};

    cout<<endl;
    return 0;
}

//===dinh nghia ham===
void CQInsert(Queue &CQ, int x)
{
    //1. kiem tra rong
    if((CQ.F==0 && CQ.R==N-1) || CQ.R+1==CQ.F)
    {
        cout<<"Hang doi day!";
        return;
    }
    //2. thay đổi chỉ số có 3 trường hợp
    if(CQ.R==-1) // Th: phần tử hàng đợi rỗng
    {
        CQ.F=CQ.R=0
    }
    else if(CQ.R==N-1) // Th: phần tử quay vòng
    {
        CQ.R == 0;
    }
    else // Th: phần tử nằm ở giữa
    {
        CQ.R++;
    }
    //3. Thêm x vào hàng đợi
    CQ.Q[CQ.R] = x;
}

int CQDelete(Queue &CQ)
{
    //1. kiểm tra rỗng
    if(CQ.F==-1)
    {
        cout<<"Hang doi rong!";
    }

    //2. lưu lại phần tử loại bỏ
    int y;
    y = CQ.Q[CQ.F];

    //3. thay đổi chỉ số
    if(CQ.F == CQ.R) // TH: Chỉ còn 1 phần tử
    {
        CQ.F=CQ.R=-1;
    }
    else if (CQ.F == N-1) // TH: quay vòng
    {
        CQ.F = 0;
    }
    else
    {
        CQ.F++;
    }
    return y;
}
