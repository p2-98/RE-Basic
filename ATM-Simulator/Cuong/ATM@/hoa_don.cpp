#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void gotoxy(int x , int y)   {
	static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

int hoa_don( int d , int t )    {
	 
         int i,x,y,sotaikhoan,a,n , c;
         FILE *fp1;
         printf("\t\t\t\t\tHOA DON\n");
         printf("\t\t\t\t  Ngay\t  thang\t  nam");
      
         printf("\n");
         printf("\n");
         printf("\tSO THE : ");
         
         	fp1 = fopen("sotaikhoan.txt","a");  {
	fscanf( fp1 , "%d" ,&sotaikhoan);
	printf("%d",sotaikhoan);
	fclose(fp1);
	}
	    printf("\n");
         printf("\tSO TIEN RUT : ");
         if ( d == 1 ) {
         	a = 500000;
         	printf("500.000"); }
         if ( d == 2) {
         	a = 1000000;
         	printf("1.000.000"); }
        if ( d == 3) {
        	a = 2000000;
         	printf("2.000.000"); }
        if ( d == 4) {
        	a = 3000000;
         	printf("3.000.000"); }
        if ( d == 5) {
        	a = 4000000;
       	printf("4.000.000"); }
        if ( d == 6) {
        	a = 5000000;
         	printf("5.000.000"); }
        if ( d == 7)  {
        	printf("%d",t);
			a = t;  }
          printf("\n");
        
           if ( a <= 1000000)  {
        	 c = 0;
         	  }
            else if ( a > 1000000 || a <= 3000000)  {
        	c = 500 + a / 10000;
         	  }
            else if ( a > 3000000 || a <= 10000000)  {
        	c = 1000 + a / 10000;
         	  }
            else  c = 2000 + a/10000;
         printf("\tLE PHI (gom thue VAT) : %d",c);
          printf("\n");
          
return 0;
}
