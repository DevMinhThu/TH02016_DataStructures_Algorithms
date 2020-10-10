//Ho ten:
//MaSV:
//Lop:
//De: Cai dat cau truc DSLKK co phan tu la so nguyen

#include<stdio.h>
#include<iostream>

using namespace std;

//Khai báo cấu trúc nút nhớ trong DSLKK
struct node
{
    int infor;
    node *left,*right;
};

//Khai báo cấu trúc gộp 2 biến L và R
struct Dlist
{
    node *L,*R;
};

//Khai báo hàm cài đặt các phép toán
void DLPreInsert(Dlist &LR,node *M,int x); // Bổ sung phần tử x vào trước nút M
node* DLPostInsert(Dlist &LR,node *M,int x); // Bổ sung phần tử x vào sau phần tử M
void DLDelete(Dlist &LR,node *M); // Xóa nút M ra khỏi DSLKK
void DLDisplay(Dlist LR, bool leftToRight=1); // Duyệt DSLKK theo 2 chiều
node* DLSearchX(Dlist LR,int x); // Tìm phần tử có dữ liệu là X và trả về địa chỉ của chúng
void DLTopInsert(Dlist &LR, int x); // Bo sung vao dau DSLKK

//===Chương trình chính===
int main()
{
    //Cài đặt cấu trúc của DSLKK
    Dlist LR = {NULL,NULL}; // Ban đầu DSLKK chưa có phần tử nên 2 con trỏ L và R = NULL

    cout<<endl;
    return 0;
}
//===Định nghĩa hàm===
void DLPreInsert(Dlist &LR,node *M,int x)
{
    //1.Tạo nút mới
    node *N = new node;
    N->infor = x;
    N->right = N->left = NULL;

    //2.Nối nút mới vào trước nút M
    if(LR.L==NULL) LR.L=LR.R=N; // TH1: DSLKK rỗng
    else
        if(M==LR.L) // TH2: M trùng với nút L
        {
            N->right = M;
            M->left = N;
            LR.L = N;
        }
        else // TH3: Còn lại M nằm ở giữa
        {
            M->left->right = N; // "Phải của phần tử" nằm bên trái M --> N (giữ lại nút phía trước k mất)
            N->left = M->left; // gán Left(M) cho left(N) : vì M đã có liên kết với nút trước nó rồi.
            N->right = M;
            M->left = N;
        }
}

node* DLPostInsert(Dlist &LR,node *M,int x)
{
    //1.Tạo nút mới
    node *N = new node;
    N->infor = x;
    N->right = N->left = NULL;

    //2.Nối nút mới vào sau nút M
    if(LR.L==NULL) LR.L=LR.R=N; // TH1: DSLKK rỗng
    else
        if(M==LR.R) // TH2: M trùng với nút R
        {
            M->right = N; // nối M với N
            N->left = M; // nối N lại với M
            LR.R = N; // trỏ R về phần tử cuối trong DS
        }
        else
        {
            N->right = M->right; //giữ lại nút phía sau k mất
            M->right->left = N;
            M->right = N;
            N->left = M;
        }
    return N;
}

void DLDelete(Dlist &LR,node *M)
{
    //1.Kiểm tra rỗng
    if(LR.L==NULL)
    {
        cout<<"DSLKK rỗnSg!";
    }

    //2.Thay đổi liên kết
    if(LR.L==LR.R) LR.L=LR.R=NULL; //TH1: chỉ còn 1 nút
    else
        if(M==LR.L) //TH2: M trùng với nút cực trái
        {
            LR.L = LR.L->right; // cho L nhảy tới nút sau nó
            LR.L->left = NULL;
        }
        else
            if(M==LR.R) //TH3: M trùng với nút cực phải
            {
                LR.R = LR.R->left;
                LR.R->right = NULL;
            }
            else //TH4: còn lại, M nằm ở giữa
            {
                M->left->right = M->right; // nối con trỏ phải của nút bên trái M ---> cho thằng bên phải M
                M->right->left = M->left; // nối con trỏ trái của nút bên phải M ---> cho thằng bên trái M
            }
    //3. Hủy nút M
    delete M;
}

void DLDisplay(Dlist LR, bool leftToRight)
{
    node *P = leftToRight?LR.L:LR.R; // gán con trỏ P vào toán tử 3 ngôi lựa chọn chiều đi là trái hay phải

    while(P)
    {
        cout<<P->infor<<"  ";
        P=leftToRight?P->right:P->left; // nếu LR.L trước thì phải đi theo P->right, tương tự với LR.R
    }
}

node* DLSearchX(Dlist LR,int x)
{
    //1.Tìm nút có chưa dữ liệu là x
    node *P = LR.L;
    while(P)
        if(P->infor==x) return P; //nếu tìm thấy trả về P
        else P=P->right; //còn không thì tìm tiếp các nút tiếp

    //2.Không tìm thấy
    return NULL;
}

void DLTopInsert(Dlist &LR, int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->right = N->left = NULL;

    //2.Bo sung nut moi vao dau DSLKK
    if(LR.L==NULL) LR.L=LR.R=N;
    else
    {
        N->right = LR.L;
        LR.L->left = N;
        LR.R = N;
    }
}







/*
//Ho ten:
//Lop:
//MaSV:
//De:

#include<stdio.h>
#include<iostream>

using namespace std;

//Khai bao nut nho trong DSLKK
struct node
{
    int infor;
    node *left, *right;
};

//Khai bao gop 2 bien L  va R
struct DList
{
    node *L, *R;
};

//Khai bao ham cai dat cac phep toan tren dslkk
void DLPostInsert(DList &LR, node *M,int x);
void DLPreInsert(DList &LR, node *M, int x);
void DLDelete(DList &LR,node *M);
void DLDisplay(DList LR, bool leftToRight=1);

//===chuong trinh chinh===
int main()
{
    DList LR = {NULL,NULL};

    cout<<endl;
    return 0;
}
//===dinh nghia ham===
void DLPostInsert(DList &LR, node *M,int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->left = N->right = NULL;

    //2.Bo sung nut moi
    if(LR.L==NULL)
        LR.R=LR.L=N;
    else
        if(M==LR.R)
        {
            M->right = N;
            N->left = M;
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

void DLPreInsert(DList &LR, node *M, int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->right = N->left = NULL;

    //2.Bo sung phan tu vao truoc
    if(LR.L==NULL)
        LR.R=LR.L=N;
    else
        if(M==LR.L)
        {
            N->right = M;
            M->left = N;
            LR.L = N;
        }
        else
        {
            M->left->right = N;
            N->left = M->left;
            N->right = M;
            M->left = N;
        }
}

void DLDelete(DList &LR,node *M)
{
    //1.Kiem tra rong
    if(LR.R==NULL)
    {
        cout<<"Rong!";
        return;
    }

    //2.Thay doi lien ket
    if(LR.R==LR.L)
        LR.R=LR.L=NULL;
    else
        if(M==LR.L)
        {
            LR.L=LR.L->right;
            LR.L->left = NULL;
        }
        else
            if(M==LR.R)
            {
                LR.R=LR.R->left;
                LR.R->right = NULL;
            }
            else
            {
                M->left->right = M->right;
                M->right->left = M->left;
            }

    //3.Huy nut
    delete M;
}

void DLDisplay(DList LR, bool leftToRight)
{
    node *P=leftToRight?LR.L:LR.R;

    while(P)
    {
        cout<<P->infor<<"  ";
        P=leftToRight?P->right:P->left;
    }
}
*/
