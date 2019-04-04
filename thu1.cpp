#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
long guitien,sodu=1000,sotien;
long mk,ruttien,mkm,a,k;
char giaodich='1',hoadon,luachon;
int b=0,c=0,sai=0;
int mkt=1610, mkc=1710,mkq=2010;
void  Tuan()
{
	printf("******** XIN CHAO KHACH HANG DO ANH TUAN DEN VOI ATM NGAN HANG VIETTIN BANK ******\n\n");
	while(mk!=mkt)
	{
	printf("\tXin moi nhap mat khau the cua quy khach:\n\n");
	scanf("%ld",&mk);
		if(mk!=mkt)
		{ printf("\tQuy khach nhap sai mat khau\n\n");
		  printf("\tVui long nhap mat khau chinh xac\n\n");
		  sai=sai+1;
		  if(sai>2)
		  {
		  	printf("\tQuy khach nhap sai mat khau qua 3 lan, vui long thao tac lai dich vu\n");
		  	exit(0);
		  }
		}
	}
	do
    {
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
	        printf("\t=== 5: ket thuc dich vu,    ===\n\tmoi quy khach nhan hoa don  ===\n\t===============================\n");
	        scanf("\t\t%d",&luachon);
	        switch (luachon)
	        {
			case 1: printf("\tSo du trong the cua quy khach la %ld USD\n\n",sodu);
			        break;
			case 2: printf("\tRut tien, nhap so tien quy khach can rut\n\n");
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
			        break;	
					}
					break;
			case 3:
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
			    break;	 	
				}
				break;
			case 4:
				printf("\tVui long nhap lai mat khau cua quy khach\n\n");
				scanf("%ld",&mk);
				if(mk==mkt)
				{
				printf("\tNhap mat khau moi cho the\n\n");
				scanf("%ld",&mkm);
				printf("\tXac nhan lai mat khau\n\n");
				scanf("%ld",&a);
				  if (a==mkm)
					printf("\tQuy khach da doi mat khau thanh cong\n\n");	
				  else if(a!=mkm)  
					printf("\tXac nhan mat khau khong dung\n\n");	break;
					}		
				else
				printf("\tNhap sai mat khau\n");
				break;
				case 5:	
				printf("\t***Cam on quy khach da su dung dich vu ATM***\n \n");
			
				break;
			default: 
			    printf("\tLua chon khong hop le\n\n");
			}
			printf("\tQuy khach co muon thuc hien giao dich khac?\n\n");
			printf("1-Co\n\n");
			printf("2-Khong\n\n");
			fflush stdin;
			scanf("%c",&giaodich);
			if(giaodich=='2')
			k=1;
			}
			while(!k);
			printf("\t***Cam on quy khach da su dung dich vu***\n\n");
			printf("\t   Hoa don cua quy khach la:\n\n");
}
void  Cuong()
{
	printf("******** XIN CHAO KHACH HANG NGUYEN HUU CUONG DEN VOI ATM NGAN HANG VIETTIN BANK ******\n\n");
	while(mk!=mkc)
	{
	printf("\tXin moi nhap mat khau the cua quy khach:\n\n");
	scanf("%ld",&mk);
		if(mk!=mkc)
		{ printf("\tQuy khach nhap sai mat khau\n\n");
		  printf("\tVui long nhap mat khau chinh xac\n\n");
		  sai=sai+1;
		  if(sai>2)
		  {
		  	printf("\tQuy khach nhap sai mat khau qua 3 lan, vui long thao tac lai dich vu\n");
		  	exit(0);
		  }
		}
	}
	do
    {
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
	        printf("\t=== 5: ket thuc dich vu,    ===\n\tmoi quy khach nhan hoa don  ===\n\t===============================\n");
	        scanf("\t\t%d",&luachon);
	        switch (luachon)
	        {
			case 1: printf("\tSo du trong the cua quy khach la %ld USD\n\n",sodu);
			        break;
			case 2: printf("\tRut tien, nhap so tien quy khach can rut\n\n");
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
			        break;	
					}
					break;
			case 3:
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
			    break;	 	
				}
				break;
			case 4:
				printf("\tVui long nhap lai mat khau cua quy khach\n\n");
				scanf("%ld",&mk);
				if(mk==mkc)
				{
				printf("\tNhap mat khau moi cho the\n\n");
				scanf("%ld",&mkm);
				printf("\tXac nhan lai mat khau\n\n");
				scanf("%ld",&a);
				  if (a==mkm)
					printf("\tQuy khach da doi mat khau thanh cong\n\n");	
				  else if(a!=mkm)  
					printf("\tXac nhan mat khau khong dung\n\n");	break;
					}		
				else
				printf("\tNhap sai mat khau\n");
				break;
				case 5:	
				printf("\t***Cam on quy khach da su dung dich vu ATM***\n \n");
			
				break;
			default: 
			    printf("\tLua chon khong hop le\n\n");
			}
			printf("\tQuy khach co muon thuc hien giao dich khac?\n\n");
			printf("1-Co\n\n");
			printf("2-Khong\n\n");
			fflush stdin;
			scanf("%c",&giaodich);
			if(giaodich=='2')
			k=1;
			}
			while(!k);
			printf("\t***Cam on quy khach da su dung dich vu***\n\n");
			printf("\t   Hoa don cua quy khach la:\n\n");
}
void  Quy()
{
	printf("******** XIN CHAO KHACH HANG PHAM PHU QUY DEN VOI ATM NGAN HANG VIETTIN BANK ******\n\n");
	while(mk!=mkq)
	{
	printf("\tXin moi nhap mat khau the cua quy khach:\n\n");
	scanf("%ld",&mk);
		if(mk!=mkq)
		{ printf("\tQuy khach nhap sai mat khau\n\n");
		  printf("\tVui long nhap mat khau chinh xac\n\n");
		  sai=sai+1;
		  if(sai>2)
		  {
		  	printf("\tQuy khach nhap sai mat khau qua 3 lan, vui long thao tac lai dich vu\n");
		  	exit(0);
		  }
		}
	}
	do
    {
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
	        printf("\t=== 5: ket thuc dich vu,    ===\n\tmoi quy khach nhan hoa don  ===\n\t===============================\n");
	        scanf("\t\t%d",&luachon);
	        switch (luachon)
	        {
			case 1: printf("\tSo du trong the cua quy khach la %ld USD\n\n",sodu);
			        break;
			case 2: printf("\tRut tien, nhap so tien quy khach can rut\n\n");
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
			        break;	
					}
					break;
			case 3:
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
			    break;	 	
				}
				break;
			case 4:
				printf("\tVui long nhap lai mat khau cua quy khach\n\n");
				scanf("%ld",&mk);
				if(mk==mkq)
				{
				printf("\tNhap mat khau moi cho the\n\n");
				scanf("%ld",&mkm);
				printf("\tXac nhan lai mat khau\n\n");
				scanf("%ld",&a);
				  if (a==mkm)
					printf("\tQuy khach da doi mat khau thanh cong\n\n");	
				  else if(a!=mkm)  
					printf("\tXac nhan mat khau khong dung\n\n");	break;
					}		
				else
				printf("\tNhap sai mat khau\n");
				break;
				case 5:	
				printf("\t***Cam on quy khach da su dung dich vu ATM***\n \n");
			
				break;
			default: 
			    printf("\tLua chon khong hop le\n\n");
			}
			printf("\tQuy khach co muon thuc hien giao dich khac?\n\n");
			printf("1-Co\n\n");
			printf("2-Khong\n\n");
			fflush stdin;
			scanf("%c",&giaodich);
			if(giaodich=='2')
			k=1;
			}
			while(!k);
			printf("\t***Cam on quy khach da su dung dich vu***\n\n");
			printf("\t   Hoa don cua quy khach la:\n\n");
}
int main()
 {
 int tuan=123456, cuong=123465, quy=123654;
 int mathe;
 	printf("Nhap ma the cua quy khach\n");
 	scanf("%d",&mathe);
 	if(mathe==tuan)
  {	
    Tuan();
    FILE *ghi;
	ghi=fopen("thongtinkhachhang.txt","w"); 
	fprintf(ghi,"Ma the cua quy khach la %d, ",mathe);
    fprintf(ghi,"Quy khach da rut %ld USD, ",sotien);
    fprintf(ghi,"Quy khach da gui thanh cong %ld USD, ",guitien);
    fprintf(ghi,"So du trong tai khoan cua quy khach la %ld USD, ",sodu);
    fclose(ghi);
    
    FILE *doc;
    char thongtin[1000];
    doc=fopen("thongtinkhachhang.txt","r");
    while(fgets(thongtin,1000,doc)!=NULL);
    printf("%s",thongtin);
    fclose(doc);
    }
   
    if(mathe==cuong)
    {
 Cuong();
 FILE *ghi;
	ghi=fopen("thongtinkhachhang.txt","w"); 
	fprintf(ghi,"Ma the cua quy khach la %d, ",mathe);
    fprintf(ghi," Quy khach da rut %ld USD, ",sotien);
    fprintf(ghi," Quy khach da gui thanh cong %ld USD, ",guitien);
    fprintf(ghi,"So du trong tai khoan cua quy khach la %ld USD, ",sodu);
    fclose(ghi);
    
    FILE *doc;
    char thongtin[1000];
    doc=fopen("thongtinkhachhang.txt","r");
    while(fgets(thongtin,1000,doc)!=NULL);
    printf("%s",thongtin);
    fclose(doc);
    }
 
    if(mathe==quy)
    {
    Quy();
    FILE *ghi;
	ghi=fopen("thongtinkhachhang.txt","w"); 
	fprintf(ghi,"Ma the cua quy khach la %d,",mathe);
    fprintf(ghi," Quy khach da rut %ld USD,",sotien);
    fprintf(ghi," Quy khach da gui thanh cong %ld USD,",guitien);
    fprintf(ghi,"So du trong tai khoan cua quy khach la %ld USD,",sodu);
    fclose(ghi);
    
    FILE *doc;
    char thongtin[1000];
    doc=fopen("thongtinkhachhang.txt","r");
    while(fgets(thongtin,1000,doc)!=NULL);
    printf("%s",thongtin);
    fclose(doc);
    }
   
 return 0;
}	
	
