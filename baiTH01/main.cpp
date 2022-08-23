#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int LinearSearch(int a[], int n, int x);
void NhapMang(int a[], int n);
void XuatMang(int a[], int n);

int main()
{
    //Tao kich thuoc cua mang
    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);
    //Tao, xuat, nhap mang
    int a[n];
    NhapMang(a, n);
    XuatMang(a, n);
    //Tao so can tim
    int x;
    printf("\nNhap so can tim: ");
    scanf("%d", &x);
    //Return co tim thay so can tim ko
    int k = LinearSearch(a, n, x);
    if(k == -1)
        printf("\nKhong tim thay");
    else
        printf("\nVi tri cua %d trong mang la %d", x, k);
    return 0;
}

int LinearSearch(int a[], int n, int x){
    for(int i = 0; i < n; i++)
        if(a[i] == x)
            return i;
    return -1;
}

void NhapMang(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int a[], int n){
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
