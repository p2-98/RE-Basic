#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int man_hinh_chinh();

int xem_so_du() {
	int z , sotaikhoan;
	printf("\tso tai khoan : ");
	FILE *fp1 ;
	fp1 = fopen("sotaikhoan.txt","a");  {
	fscanf( fp1 , "%d" ,&sotaikhoan);
	printf("%d",sotaikhoan);
	fclose(fp1);
	  }
	printf("\n");
  printf("\tso du cua ban la :.....\n");
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
