#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>

int man_hinh_chinh();

int dich_vu()   {
	int z,a;
	printf("muon biet them dich vu lien he voi so 0333371717\n");
		printf(" ban co muon giao dich nua ko? \n ");
    printf("                       1_Co\n");
    printf("                       2_Khong\n");
    	z = getch() ;
    	if( z == 49 )  {	
    	man_hinh_chinh();
    	
    }
        else printf(" xin chao va hen gap lai\n");
return 0;
}
