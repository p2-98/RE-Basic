#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int man_hinh_chinh();

int nhap_ma_pin()   {
	char ma_pin[50], c ; 
	int i = 0 , n = 0 ;
	printf(" ma_pin :");
    
	do {
		c = getch() ;
		if( c != '\r')  {
			printf("*");
			ma_pin[i] = c ;
			i++;
			}
		}
	while(c != '\r' );
	FILE *fp ;
    fp = fopen("PassWord.txt", "w");
         for ( n = 0 ; n < 6 ; n++)  {                                
                   fprintf (fp, "%c",ma_pin[n]);
                }
    fclose(fp);
	if(i < 6 || i > 6 ) {
	printf("nhap sai ma pin vui long nhap lai\n");
	}
	else  {
    	printf("\n");
    	man_hinh_chinh();
    	}
getch(); 

}
