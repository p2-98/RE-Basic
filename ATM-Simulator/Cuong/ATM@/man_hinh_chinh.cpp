#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdlib.h>

int rut_tien();
int chuyen_khoan();
int doi_ma_pin();
int xem_so_du();
int thoat();
int dich_vu();
int thong_tin_tai_khoan();
int hoa_don();

int man_hinh_chinh()   {
	int x ,z;
	printf("\t\t 1_Rut tien    \t\t 2_Chuyen khoan \n");
	printf("\t\t 3_Doi ma pin  \t\t 4_Xem so du \n");
	printf("\t\t 5_Thoat       \t\t 6_Tra cuu dich vu \n");
	printf("\t\t 7_thong tin tai khoan \n");
	printf("\n");
	z = getch();
	x = z - 48 ;
	switch(x) {
		
		case 1 : 
			rut_tien();  
			break;
		case 2 : 
			chuyen_khoan();  
			break;
		case 3 : 
			doi_ma_pin();  
			break;
		case 4 : 
			xem_so_du(); 
			break; 
		case 5 : 
			thoat();  
			break;
		case 6: 
			dich_vu();  
			break;
		case 7:
			thong_tin_tai_khoan();
			break;
	}
		
return 0;
}
	
