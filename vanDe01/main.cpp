#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void NhapMang(int a[], int n);
void XuatMang(int a[], int n);
void PhatSinhMang(int a[], int n);
int GhiMangVaoFileText(char* filename, int a[], int n)
int DocFileTextVaoMang(char* filename, int a[], int &n);

int main()
{
    //Khoi tao va nhap kich thuoc mang
    int n;
    printf("Nhap kich thuoc mang: ");
    scanf("%d", &n);
    //Khoi tao, xuat, nhap mang
    int a[n];
    //NhapMang(a, n);
    PhatSinhMang(a, n);
    XuatMang(a, n);

    return 0;
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

void PhatSinhMang(int a[], int n){
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        a[i] = rand();
}

int GhiMangVaoFileText(char* filename, int a[], int n){
    FILE* f = fopen(filename, "w");
    if(!f)
        return 0;
    for(int i = 0; i < n; i++)
        fprintf(f, "%d\t", a[i]);
    fclose(f);
    return 1;
}


int DocFileTextVaoMang(char* filename, int a[], int &n){
    FILE* f = fopen(filename, "r");
    if(!f)
        return 0;
    int i = 0;
    while(!feof(f)){
        fscanf(f, "%d", &a[i]);
        i++;
    }
    n = i;
}
