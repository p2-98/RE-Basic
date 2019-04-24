#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int man_hinh_chinh();

int xem_so_du() {
	int z , sotaikhoan , c , tien;
	printf("\tso tai khoan : ");
	FILE *fp1,*f1 ;
	fp1 = fopen("sotaikhoan.txt","a");  {
	fscanf( fp1 , "%d" ,&sotaikhoan);
	printf("%d",sotaikhoan);
	fclose(fp1);
	f1 = fopen("money.txt" , "r");
    while (!feof (f1))
     {
     fscanf (f1, "%d", &c);
     tien = c;
    }
    fclose(f1);
	  }
	printf("\n");
  printf("\tso du cua ban la :%d\n",tien);
  printf("\t\tban co muon giao dich nua ko? \n ");
    printf("                       1-Co\n");
    printf("                       2_Khong\n");
   	z = getch() ;
    	if( z == 49 )  {	
    	  man_hinh_chinh();  
    	  }
    	  else printf(" xin chao va hen gap lai\n");
    return 0;
}
