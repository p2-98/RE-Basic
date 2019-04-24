#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
long sodu=1000,k;
int sodu1();
int ruttien();
int guitien();
int doimatkhau();
int ketthuc();
char ht[30];
	 int mt;
struct thongtin
	 {
	 char hoten[30];
	 int mathe , madinhdanh ;
	 };
typedef thongtin tt;
int sodu1()
{
	
	printf("\tSo du trong the cua quy khach la %ld USD\n\n",sodu);
	FILE *file1;
	file1=fopen("thongtinkh","a");
	fprintf(file1,"So du trong the cua quy khach la %d USD", sodu);
	fprintf(file1, "\n");
	fclose(file1);
	return 0;
}
int ruttien()
{
	int sotien;
        printf("\tRut tien, nhap so tien quy khach can rut\n\n");
			        scanf("\t\t\t%ld",&sotien);
			        printf("\n");
			        if(sotien>sodu )
			        {
			        	printf("\tSo du khong du cho giao dich nay\n\n");
					}
			        else if(sotien%50!=0||sotien==0)
			        {
			        printf("\tSo tien rut phai la boi so cua 50 USD\n\n");
			        printf("\tMoi quy khach giao dich lai\n");
			        }
			        else
			        {
			        	printf("\tQuy khach da rut thanh cong %ld USD\n\n", sotien);
			        	sodu = sodu - sotien;
			        
			        	printf("\tVui long nhan tien o duoi khay cua cay atm\n\n");	
						FILE *file2;
						file2=fopen("thongtinkh","a");
						fprintf(file2,"Quy khach da rut %d USD", sotien);
						fprintf(file2,"\n");
						fprintf(file2,"So du hien tai la %ld USD", sodu);
						fprintf(file2, "\n");
						fclose(file2);	
					}  
}  
int guitien()
{
	        long guitien;
	          printf("\tDich vu gui ten vao tai khoan\n\n");
				printf("\tQuy khach vui long nhap so tien can gui\n\n");
				scanf("%ld",&guitien);
				if(guitien<50)
				{ 
				printf("\tSo tien gui vao co gia tri it nhat la 50 USD\n\n");
				}
				else if(guitien % 50 !=0)
				{
					printf("\tSo tien gui phai la boi so cua 50 USD\n \n");
				}
				else 
			    {
			    	printf("\tGui tien thanh cong\n\n");
			    	sodu = sodu + guitien;
			    	printf("\tSo du trong tai khoan cua quy khach la %ld\n\n", sodu);
			    }
			FILE *file3;
			file3=fopen("thongtinkh","a");
			fprintf(file3,"Quy khach da gui thanh cong %ld USD vao tai khoan", guitien);
			fprintf(file3,"\n");
			fprintf(file3,"So du cua quy khach la %ld", sodu);
			fprintf(file3, "\n");	
			fclose(file3);
}
int doimatkhau()
{
	long mk,a,mkm;
	printf("\tVui long nhap lai mat khau cua quy khach\n\n");
				scanf("%ld",&mk);
				if(mk==1234)
				{
				printf("\tNhap mat khau moi cho the\n\n");
				scanf("%ld",&mkm);
				printf("\tXac nhan lai mat khau\n\n");
				scanf("%ld",&a);
				  if (a==mkm)
					printf("\tQuy khach da doi mat khau thanh cong\n\n");	
				  else if(a!=mkm)  
					printf("\tXac nhan mat khau khong dung\n\n");	
				}		
				else
				printf("\tNhap sai mat khau\n");
 } 
 void nhap(tt &t){
    printf("\nNhap ten: "); fflush(stdin); gets(t.hoten);
    printf("\nNhap ma the: "); scanf("%d", &t.mathe);
    t.madinhdanh  = rand() % 20;;
}
 
void nhapN(tt a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap KH thu %d:", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}

void xuatFile(tt a[], int n, char fileName[]){
    FILE * fp;
    fp = fopen (fileName,"a");
    for(int i = 0;i < n;i++){
    	fprintf(fp, "Ho ten khach hang: %s",a[i].hoten);
    	fprintf(fp,"\n");
        fprintf(fp, "Ma the khach hang: %d ",a[i].mathe);
        fprintf(fp,"\n");
        fprintf(fp,"Ma dinh danh cua khach hang: %d", a[i].madinhdanh);
        fprintf(fp,"\n");
    }
    fclose (fp);
}
void xoatt()
{ 
char fileName[] = "thongtinhk.txt";
int luachon;
    printf("Quy khach co muon xoa thong tin khach hang?\n");
    printf("1-co  2-khong\n");
    scanf("%d", &luachon);
    if(luachon==1) 
	{
	if (remove("thongtinkh.txt") == 0) ;
      printf("Deleted successfully");
	}   
   else
      printf("Unable to delete the file");
 }     
void anhtuan()
{
	char fileName[] = "thongtinkh.txt";
    int n;
    int key ;
    bool daNhap = false;
	do{
		printf("**    CHUONG TRINH QUAN LY THONG TIN NGAN HANG   **\n");
       	 printf("\nNhap so KH can them vao thong tin ngan hang : "); scanf("%d", &n);
    	}while(n <= 0);
    	tt a[n];
    while(true){
        system("cls");
        printf("******************************************\n");  
        printf("**      1. Nhap khach hang              **\n");
        printf("**      2. Dua thong tin vao file       **\n");
        printf("**      3. Xoa thong tin trong file     **\n");
        printf("**      4. Thoat                        **\n");
        printf("******************************************\n");
        printf("**         Nhap lua chon cua ban        **\n");
        scanf("%d",&key);
        switch(key){
            case 1:
                nhapN(a, n);
                daNhap = true;
                getch();
                break;
		
			 case 2 : 
            if(daNhap){
                    printf("\nBan da nhap DS KH vao file!");
                    xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap DS KH truoc!!!!");
                }
                getch();
                break; 
                case 3: 
                {
                 xoatt();
				}
            case 4:
                exit(0);
                getch();
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
			     }
    }}
 
int ketthuc()
{
	printf("\t***Cam on quy khach da su dung dich vu ATM***\n \n");
			
} 
                        
int main()
{
	printf("\tXIN CHAO QUY KHACH DEN VOI HE THONG ATM CUA NGAN HANG ACB\n\n");	
	int mk,sai;
	sai=0;
	while(1)
	{
		printf("\tXin moi nhap mat khau the cua quy khach:\n\n");
		scanf("%ld",&mk);
		if(mk==1234||mk==1235||mk==1236||mk==1237||mk==1238||mk=1239)
		{ 
			break ;
		    
		}
		else{
			printf("\tQuy khach nhap sai mat khau\n\n");
			  printf("\tVui long nhap mat khau chinh xac\n\n");
			  sai=sai+1;
		}
		if(sai>2)
		  {
		  	printf("\tQuy khach nhap sai mat khau qua 3 lan, vui long thao tac lai dich vu\n");
		  	sai = 0;
		  	exit(0);
		  }
	
	}
	int luachon;
	printf("\t---XIN MOI LUA CHON DICH VU---\n\n");
		    printf("\t===============================\n");
		    printf("\t===\t\t\t    ===\n");
	        printf("\t=== 1: so du trong the      ===\n");
	        printf("\t===\t\t\t    ===\n");
            printf("\t=== 2: dich vu rut tien     ===\n");
            printf("\t===\t\t\t    ===\n");
            printf("\t=== 3: dich vu gui tien     ===\n");
            printf("\t===\t\t\t    ===\n");
	        printf("\t=== 4: doi mat khau the     ===\n");
	        printf("\t===\t\t\t    ===\n");
	        printf("\t=== 5: Thay doi thong tin   ===\n");
	        printf("\t===\t\t\t    ===\n");
	        printf("\t=== 6: ket thuc dich vu,    ===\n\t\t    nhan hoa don  ===\n\t===============================\n");
	        scanf("\t\t%d",&luachon);
	    switch (luachon)
		{
	    case 1: sodu1(); break;
	    case 2: ruttien(); break;
	    case 3: guitien(); break;
	    case 4: doimatkhau(); break;
	    case 5: anhtuan(); break;
	    case 6: ketthuc(); break;
	    default: 
			    printf("\tLua chon khong hop le\n\n");
			}
			char giaodich='1';
			int k;
			printf("\tQuy khach co muon thuc hien giao dich khac?\n\n");
			printf("1-Co\n\n");
			printf("2-Khong\n\n");
			fflush stdin;
			scanf("%c",&giaodich);
			if(giaodich=='2')
			k=1;
			
			while(!k);
			printf("\t***Cam on quy khach da su dung dich vu***\n\n");
			printf("\t   Hoa don cua quy khach la:\n\n");
}
