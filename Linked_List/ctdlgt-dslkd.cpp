//Ho ten: Vu Minh Thu
//Lop: K63TH
//MaSV: 637865
//De: Cai dat cau truc DSLKD

#include<iostream>
#include<stdio.h>

using namespace std;

//Khai bao cau truc nut nho trong DSLKD
struct node
{
    int infor;
    node *link;
};

//Khai bao ham cai dat cac phep toan tren DSLKD
void SLPostInsert(node* &F, node *M, int x); // Bổ sung vào sau nút M
void SLPreInsert(node* &F, node *M, int x); // Bổ sung vào trước M
void SLEndInsert(node *F, int x); // Bổ sung vào cuối danh sách
void SLTopInsert(node *F, int x); // Bổ sung vào đầu danh sách
int SLDelete(node* &F, node *M); // Xóa nút M
void SLDisplay(node *F); // Duyệt DSLKD

//===chuong trinh chinh===
int main()
{
    //Cai dat cau truc luu tru cua DSLKD
    node *F=NULL;

    SLPostInsert(F,F,3);
    SLPostInsert(F,F,5);
    SLPostInsert(F,F,9);

    node *M = F; // gan M la gia tri 3

    //Bo sung sau nut M ==> 3 - 999 - 9 - 5
    SLPostInsert(F,M,999);
    cout<<"Bo sung 999 sau nut M la: \n";
    SLDisplay(F);

    //Bo sung truoc nut M ==> 666 - 3 - 999 - 9 - 5
    SLPreInsert(F,M,666);
    cout<<"\n\nBo sung 666 vao truoc nut M la: \n";
    SLDisplay(F);

    //Bo sung cuoi ==> 666 - 3 - 999 - 9 - 5 - 100
    SLEndInsert(F,100);
    cout<<"\n\nBo sung 100 vao cuoi danh sach: \n";
    SLDisplay(F);

    //Bo sung dau ==> 666 - 3 - 999 - 9 - 5 - 100
    SLTopInsert(F,888);
    cout<<"\n\nBo sung 888 vao dau danh sach: \n";
    SLDisplay(F);

    //Xóa nút M ==> 666 - 999 - 9 - 5 - 100
    SLDelete(F,M);
    cout<<"\n\nDanh sach sau khi xoa nut M: \n";
    SLDisplay(F);

    cout<<endl;
    return 0;
}

//===dinh nghia ham===
void SLPostInsert(node* &F, node *M, int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao sau nut M
    if(F==NULL) F=N;
    else
    {
        N->link = M->link;
        M->link = N;
    }
}

void SLPreInsert(node* &F, node *M, int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao truoc nut M
    if(F==NULL) F=N;
    else
        if(F==M)// TH: F trung voi M
        {
            N->link = M; // Noi N voi M
            F=N; // F trỏ lên N, F luôn là phần tử đầu tiên
        }
        else
        {
            node *P = F;
            while(P->link != M)
            {
                P=P->link; // lấy link của nút trỏ tới M
            }
            P->link = N; // trỏ link vừa lấy được vào N
            N->link = M; // N trỏ vào M
        }
}

void SLEndInsert(node *F, int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao nut cuoi danh sach
    if(F==NULL) F=N;
    else
    {
        node *P = F;
        while(P->link)
        {
            P=P->link; // lấy link nút cuối cùng
        }
        P->link = N; // Nối nút cuối với nút N
    }
}

void SLTopInsert(node *F, int x)
{
    //1.Tao nut moi
    node *N = new node;
    N->infor = x;
    N->link = NULL;

    //2.Noi nut moi vao dau danh sach
    if(F==NULL) F=N;
    else
    {
        N->link = F; // Nối N với nút đầu
        F = N; // Trỏ F lên nút đầu
    }
}

int SLDelete(node* &F, node *M)
{
    int tg = M->infor;

    //1.Truong hop rong
    if(F==NULL)
    {
        cout<<"DSLKD rong!";
        return -1;
    }

    //2.Ngat ket noi voi nut M
    if(M==F) F=F->link; // Cho F trỏ tới nút sau nó
    else
    {
        // Tìm link của nút trước M, để nối với nút sau M
        node *P = F;
        while(P->link != M) P=P->link;

        // Nối nút trước M với nút sau M
        P->link = M->link;
    }

    //3. Huy nut va tra ve nut M
    delete M;
    return tg;
}

void SLDisplay(node *F)
{
    //1.Kiem tra rong
    if(F==NULL)
    {
        cout<<"DSLKD rong";
    }
    else
    {
        node *P = F;
        while(P)
        {
            cout<<P->infor<<"  ";
            P=P->link;
        }
    }
}


