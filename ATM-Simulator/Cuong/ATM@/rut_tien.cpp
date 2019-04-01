#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int man_hinh_chinh();
int thoat();
int hoa_don(int d , int t);

int rut_tien() {
	
	int z,d,t,n,a,y;
    printf("\t\tChon so tien muon rut \n");
    printf("\t 1_500.000     \t\t 2_1.000.000 \n ");
    printf("\t 3_2.000.000   \t\t 4_3.000.000 \n");
    printf("\t 5_4.000.000   \t\t 6_5.000.000 \n ");
    printf("\t 7_nhap so khac\t\t 8_thoat \n");
    z = getch();
    d = z - 48;
    if( d == 1 || d == 2 || d == 3 || d == 4 || d == 5 || d == 6) {
    	printf (" \t vui long cho giao dich \n");
    	printf("nhan tien tai khe\n");
    	printf("\n");
    
    	printf(" ban co muon in hoa don ko? \n");
    	printf("                       1-Co\n");
    	printf("                       2_Khong\n");
    	z = getch() ;
    	if( z == 49 ) {
		printf(" dang in hoa don vui long doi trong giay lat\n");
		hoa_don( d , t);
		}
		else printf(" nhan lai the o khe cam và nho lay tien \n");
		printf("\n");
		
    printf(" ban co muon giao dich nua ko? \n ");
    printf("                       1-Co\n");
    printf("                       2_Khong\n");
    	z = getch() ;
    	if( z == 49 ) {	
    	man_hinh_chinh();
    	
    }
        else printf(" xin chao va hen gap lai\n");
    }
    if( d == 7 ){
    	printf("nhap so tien ban muon rut : ");
    	scanf("%d",&t);
    
    	if( t % 10000 != 0 || t < 10000)   {
    		printf(" nhap lai. so tien phai chia het cho 10000\n");
    		printf("nhap so tien ban muon rut : ");
    	    scanf("%d",&t);
    	}
    	if( t > 20000000) {
    		printf(" so tien lon nhap lai\n");
    	}
    	if( t % 10000 == 0) {
    		printf("  nhan tien tai khe lay tien\n");
    		printf(" ban co muon in hoa don ko? \n");
    	printf("                       1-Co\n");
    	printf("                       2_Khong\n");
    	int w;
		z = getch() ;
	    w = z ;
	printf("\n");
    	if( w == 49 )  {
		printf(" dang in hoa don vui long doi trong giay lat\n");
		 hoa_don( d , t);
		}
		else printf(" nhan lai the o khe cam và nho lay tien \n");
		printf("\n");
			}
    
    		
    		printf(" ban co muon giao dich nua ko? \n ");
    printf("                       1-Co\n");
    printf("                       2_Khong\n");
    int g;
		z = getch() ;
	    g = z ;
	printf("\n");
    	if( g == 49 )  {	
    	man_hinh_chinh();
    	
    }
    
        else thoat();
    }
    else if( d == 8 ) {
    	thoat();
    	}
    		
    return 0;
}
    	
