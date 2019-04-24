#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int man_hinh_chinh();

int chuyen_khoan()   {
	int n = 0 , tien , c;
	printf("\n");	
	int a,b ,z;
	FILE *f1 , *f2;
	f1 = fopen("money.txt" , "r");
    while (!feof (f1))
     {
     fscanf (f1, "%d", &c);
     printf ("%d\n", c);
     tien = c;
    }
    fclose(f1);
	printf(" so tk muon chuyen : ");
	scanf("%d",&a);
	printf(" so tien muon chuyen : ");
	scanf("%d",&b);
	if( b % 10000 == 0  )   {
		printf(" chuyen tien thanh cong \n");
		tien = tien - b;
	f2 = fopen("money.txt" , "w+");
    fprintf(f2 , "%d" , tien);
    fclose(f1);
	FILE *fp;
    fp = fopen("history.txt" , "w");
    fprintf(fp , "Tai khoan duoc chuyen la : %d", a);
    fprintf(fp , "So tien duoc chuyen la : %d", b);
    fclose(fp);
	printf(" ban co muon giao dich nua ko? \n ");
    printf("                       1-Co\n");
    printf("                       2_Khong\n");
    z = getch() ;
    	if( z == 49 )  {	
    	man_hinh_chinh();
    	
    }
        else printf(" xin chao va hen gap lai\n");
	}
	else if( b % 10000 != 0) {
	 printf("\t\t chuyen tien that bai \n");
	printf("\t\t so tien chuyen phai chia het cho 10000 \n");
	printf("\tban co muon giao dich nua ko? \n ");
    printf("\t                       1-Co\n");
    printf("\t                       2_Khong\n");
   	z = getch() ;
    	if( z == 49 )  {	
    	man_hinh_chinh();	
    }
        else printf(" xin chao va hen gap lai\n");
    }
    
return 0;
}
	
