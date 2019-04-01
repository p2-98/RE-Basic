#include<stdlib.h>
#include<stdio.h>
#include<conio.h>

int man_hinh_chinh();

int thong_tin_tai_khoan()  {
	int z;
	int sotaikhoan , socmnd ,sodienthoai;
	char tennguoidung , diachi;
	printf("\t so tai khoan : ");
	FILE *fp1 , *fp2 , *fp3 , *fp4 , *fp5;
	fp1 = fopen("sotaikhoan.txt","a");  {
	fscanf( fp1 , "%d" ,&sotaikhoan);
	printf("%d",sotaikhoan);
	fclose(fp1);
	  }
	printf("\n");
	printf("\t ten nguoi dung : ");  {
	fp2 = fopen("tennguoidung.txt","a");
	fscanf( fp2 , "%c" , &tennguoidung);
	printf("%s",tennguoidung);
	fclose(fp2);
	   }
	printf("\n");
	printf("\t so chung minh nhan dan : "); 
	fp3 = fopen("socmnd.txt","a");  {
	fscanf( fp3 , "%d" , &socmnd);
	printf("%d",socmnd);
	fclose(fp3);
	  }
	printf("\n");
	printf("\t so dien thoai : ");
	fp4 = fopen("sodienthoai.txt","a");  {
	fscanf( fp4 , "%d" , &sodienthoai);
	printf("%d",socmnd);
	fclose(fp4);
	  }
	printf("\n");
	printf("\t dia chi : ");
	fp5 = fopen("diachi.txt","a");  {
	fscanf( fp5 , "%c" , &diachi);
	printf("%s", diachi);
	fclose(fp5);
	  }
	printf("\n");
	 printf("\t\t BAN MUON GIAO DICH NUA KHONG ? \n ");
    printf("                       1-Co\n");
    printf("                       2_Khong\n");
   	z = getch() ;
    	if( z == 49 ) {	
    	  man_hinh_chinh();  
    	  }
    	  else printf(" xin chao va hen gap lai\n");
return 0;
}
	
	
	
