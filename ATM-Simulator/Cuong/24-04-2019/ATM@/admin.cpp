#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include<process.h>

typedef struct products{
    char Id[50], name[50] , adress[50];
    int phone,cmnd,stk; 
} AD;

void themtk(AD prd[], int *n);

void capnhat(AD prt[] , int n );

void del_ID(AD prt[] , int n );

void search(AD prd[], int n);

void search_ID(AD prd[], int n);

void search_name(AD prd[], int n, char name[]);

int main() {
    products prd[100];
    int n;
    
    char id[50];
    int key;
    do {
        system("cls");
        printf("******************************************\n");
        printf("**              ADMIN                   **\n");
        printf("**      1. Them tai khonan              **\n");
        printf("**      2. Cap nhat tai khoan           **\n");
        printf("**      3. Xoa tai khoan                **\n");
        printf("**      4. Tim tai khoan                **\n");
        printf("**      5. Thoat                        **\n");
        printf("******************************************\n");
        printf("**       Nhap lua chon cua ban          **\n");      
        scanf("%d", &key);
        switch(key){
            case 1: {
                printf("1: Them tai khoan\n");
              themtk(prd, &n);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            }
            case 2: {
                printf("2: CAP NHAT TAI KHOAN\n");
                printf("--------------\n");
               capnhat( prd , n );
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            }
            case 3: {
            	printf("3: XOA TAI KHOAN");
            del_ID(prd, n);
            	printf("\nBam phim bat ky de tiep tuc!");
                getch();
            	break;
            }
            case 4: {
                printf("Tim tai khoan\n");
             search(prd, n);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            }
            case 5: return 0;
            default : printf(" NHAP LAI LUA CHON !"); break;
        }
    }
    while (key != 5);
return 0;
}

void themtk(AD prd[], int *n){
	 printf("So tai khoan muon them: ");
    scanf("%d", n);
	FILE *fp;
	fp= fopen("admin.txt", "w");
	if( fp == NULL)  {
		printf("error cannot open file\n");
		exit(1);
	}
    int i;
    printf("\n");
    for (i = 0; i < (*n); i++){
    	 fflush(stdin);
    	printf("\tNhap ten nguoi dung %d: ", i+1);
		gets(prd[i].name);
        printf("\tID : ", i+1);
        gets(prd[i].Id);
         printf("\tDia chi : ", i+1);
        gets(prd[i].adress);
        printf("\tSo tk %d : ", i+1);
        scanf("%d", &prd[i].stk);
        printf("\tSo dien thoai %d : ", i+1);
        scanf("%d", &prd[i].phone);
        printf("\tSo cmnd %d : ", i+1);
        scanf("%d", &prd[i].cmnd);
        fflush(stdin);
    }
    fwrite(prd,sizeof(struct products) , 100 , fp);
	fclose(fp);
} 

void capnhat(AD prd[] , int n )  {
	FILE *fp , *fp1;
	fp= fopen("admin.txt", "r");
	if( fp == NULL)  {
		printf("error cannot open file\n");
		exit(1);
	}
	fread(prd,sizeof(struct products) , 100 , fp);
	char ID[50];
	int i = 0 , tmp;
	printf("\nNap ID TK muon chinh sua : ");
	fflush(stdin);
	gets(ID);
	for( i ; i < n; i++)   {
        if(strcmp( ID, prd[i].Id) == 0)   {
        	i = tmp;
        	printf("\n NAME = %s",prd[i].name);
		printf("\nID = %s",prd[i].Id);
		printf("\nADRESS = %s",prd[i].adress);
		printf("\nPHONE = %d",prd[i].phone);
		printf("\nCMND = %d",prd[i].cmnd);
		printf("\nSO TK = %d",prd[i].stk);
            break;
        }
    }
    fclose(fp);
    fp= fopen("admin.txt", "r");
	if( fp == NULL)  {
		printf("error cannot open file\n");
		exit(1);
	}
    printf("\n\tNHAP NOI DUNG SUA\n");
            printf("\nTen nguoi dung: ");
			gets(prd[tmp].name);
            printf("\nDia chi: ");
            fflush(stdin);
            gets(prd[tmp].adress);
            printf("\nID: ");
            gets( prd[tmp].Id);
            printf("\nSo tai khoan : ");
            scanf("%d",&prd[tmp].stk);
            printf("\nSo dien thoai: ");
            scanf("%d", &prd[tmp].phone);
            printf("\nSo cmnd: ");
            scanf("%d", &prd[tmp].cmnd);
            fflush(stdin);
    fwrite(prd,sizeof(struct products) , 100 , fp1);
	fclose(fp1);	  
}

void del_ID(AD prd[], int n)  {
	int i, check = 0 , tmp;
	char id[50];
	printf("nhap ID tk muon xoa: ");
	gets(id);
	fflush(stdin);
	FILE *fp;
		fp= fopen("admin.txt", "r");
	if( fp == NULL)  {
		printf("error cannot open file\n");
		exit(1);
	}
	fread(prd,sizeof(struct products) , 100 , fp);
    for (i = 0; i < n; i++){
        if (strcmp(id, prd[i].Id) == 0){
        	tmp = i ;
            check = 1;
        printf("\n NAME = %s",prd[i].name);
		printf("\nID = %s",prd[i].Id);
		printf("\nADRESS = %s",prd[i].adress);
		printf("\nPHONE = %d",prd[i].phone);
		printf("\nCMND = %d",prd[i].cmnd);
		printf("\nSO TK = %d",prd[i].stk);
         break;   
        }
        if (check == 0 && i == n - 1)
            printf("Not found product have Id is %s !\n", id);
    }
    for( i = tmp ; i < n ; i++)  {
			prd[i] = prd[i+1];
		    n--;
	}
	fclose(fp);
}

void search_id(AD prd[], int n){
	char id[50];
    gets(id);
    int i, check = 0;
    FILE *fp;
		fp= fopen("admin.txt", "r");
	if( fp == NULL)  {
		printf("error cannot open file\n");
		exit(1);
	}
	fread(prd,sizeof(struct products) , 100 , fp);
    for (i = 0; i < n; i++){
        if (strcmp(id, prd[i].Id) == 0){
            check = 1;
            printf("\n NAME = %s",prd[i].name);
		printf("\nID = %s",prd[i].Id);
		printf("\nADRESS = %s",prd[i].adress);
		printf("\nPHONE = %d",prd[i].phone);
		printf("\nCMND = %d",prd[i].cmnd);
		printf("\nSO TK = %d",prd[i].stk);
            break;
        }
        if (check == 0 && i == n - 1)
            printf("Not found product have Id is %s !\n", id);
    }
    fclose(fp);
}

void search_name(AD prd[], int n, char name[]){
    int i, check = 0;
    FILE *fp;
	fp= fopen("admin.txt", "r");
	if( fp == NULL)  {
		printf("error cannot open file\n");
		exit(1);
	}
	fread(prd,sizeof(struct products) , 100 , fp);
    for (i = 0; i < n; i++){
        if (strcmp(name, prd[i].name) == 0){
            check = 1;
        printf("\n NAME = %s",prd[i].name);
		printf("\nID = %s",prd[i].Id);
		printf("\nADRESS = %s",prd[i].adress);
		printf("\nPHONE = %d",prd[i].phone);
		printf("\nCMND = %d",prd[i].cmnd);
		printf("\nSO TK = %d",prd[i].stk);
            break;
        }
        if (check == 0 && i == n - 1)
            printf("Not found product have name is %s !\n", name);
    
	fclose(fp);
	}
}

void search(AD prd[], int n){
    int select;
    char s[50];
    do{
    	system("cls");
    	printf("*******************************\n");
        printf("**          SEARCH           **\n");
        printf("**      1. Search ID         **\n");
        printf("**      2. Search name       **\n");
        printf("**      3. Eixt              **\n");
        printf("*******************************\n");
        printf("**  Nhap lua chon cua ban    **\n");
        scanf("%d", &select);
        gets(s);
        switch(select){
            case 1: {
                printf("Enter Id want search: ");
                search_id(prd, n);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            }
            case 2: {
                printf("Enter name want search: ");
                char name[50];
                gets(name);
                search_name(prd, n, name);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
				 break;
            }
            case 3: return;
            default : printf("Error select !"); break;
        }
    }while (select != 3);
}




