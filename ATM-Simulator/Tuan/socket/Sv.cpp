#include <winsock2.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#pragma comment (lib, "Ws2_32.lib")

DWORD WINAPI multi_client(LPVOID lpParam)
{
  printf("Hello client\r\n");
  SOCKET recvSocket = (SOCKET)lpParam;
  char buffer[1024];
  char sendData[100];
  
  int iRet;
   while(TRUE)
   {
   	iRet = recv(recvSocket,buffer,sizeof(buffer),0);
   	   printf("%s\n", buffer);
		if(strstr(buffer,"exit")  )
     	  {
			printf("Disconnected\n");
			strcpy(sendData,"Disconnected\n");
            Sleep(10);
            send(recvSocket,sendData,sizeof(sendData),0);
            closesocket(recvSocket);
		    ExitThread(0);
		  }
		else
		  {
		    strcpy(sendData,"Continue sending data\n");
            Sleep(10);
            send(recvSocket,sendData,sizeof(sendData),0);
		  }
		    strcpy(sendData,"");
            strcpy(buffer,"");  
   }
}

int  main()
{
		SOCKET sock;
	DWORD thread;
	
   WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) 
	{
        wprintf(L"WSAStartup failed with error: %ld\n", iResult);
        return 1;
	}	
	// Create a socket
	struct	sockaddr_in svrAddr;
	 sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf ("Can't create a socket! Quitting" ) ;
		WSACleanup();
		return 1;
	}
    
	svrAddr.sin_family = AF_INET;
	svrAddr.sin_port = htons(8080);
	svrAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	
	if( bind(sock,(SOCKADDR *)&svrAddr,sizeof(svrAddr)) == SOCKET_ERROR)
	 {
        wprintf(L"bind failed with error: %ld\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return 1;
	 } 
    if(listen(sock,10) == SOCKET_ERROR) 
	{
        wprintf(L"listen failed with error: %ld\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return 1;
    }
    
	SOCKET newSocket;
	struct sockaddr_in newAddr;
	int addr_size = sizeof(newAddr);
		
while(TRUE)
   {
    newSocket = accept(sock,(SOCKADDR*)&newAddr,&addr_size);
	 if( newSocket ==INVALID_SOCKET )
	 {
	 	wprintf(L"accept failed with error: %ld\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return 1;
	 }
	 else
      printf("Client connected from: %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port)); 
	  		
      CreateThread(NULL, 0,multi_client,(LPVOID)newSocket, 0, &thread);
   }
closesocket(sock);	
WSACleanup();	
return 0;
}

