#include <windows.h>
#include  <stdlib.h>
#include <stdio.h>
#include <winsock.h>
#pragma comment(lib, "Ws2_32.lib")
 
// our thread for recving commands
DWORD WINAPI multi_client(LPVOID lpParam)   {
  printf("hello client\r\n");
   
  // set our socket to the socket passed in as a parameter   
  SOCKET current_client = (SOCKET)lpParam; 
   
  // buffer to hold our recived data
  char buf[100];
  // buffer to hold our sent data
  char sendData[100];
  // for error checking 
  int res;
   
  // our recv loop
  while(TRUE) 
  {
     res = recv(current_client,buf,sizeof(buf),0); // recv cmds 
     printf("mess from client: %s\n",buf);
     if( strstr(buf , "hello")){
       strcpy(sendData,"hello, client\n");
       Sleep(10);
       send(current_client,sendData,sizeof(sendData),0); 
     }                              
     else if(strstr(buf,"bye"))   
     { // dissconnected this user
     printf("bye client\n");
       strcpy(sendData,"bye client\n");
       Sleep(10);
       send(current_client,sendData,sizeof(sendData),0);
  
      // close the socket associted with this client and end this thread
       closesocket(current_client);
       ExitThread(0);
     }
     else
     {
       strcpy(sendData,"hello client\n");
       Sleep(10);
       send(current_client,sendData,sizeof(sendData),0);
     }
     // clear buffers
       strcpy(sendData,"");
       strcpy(buf,"");
  } 
}   
 
int main()
{
 printf("    WELLCOME TO SERVER\r\n");
     SOCKET sock;
  
    // for our thread
    DWORD thread;
	 
   // Initialize Winsock.
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        wprintf(L"WSAStartup failed with error: %ld\n", iResult);
        return 1;
    }
 struct sockaddr_in server;
 
  // create our socket
 sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); 
 if(sock == INVALID_SOCKET)
 {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        WSACleanup();
        return 1;  
 }
 
  // IP address, and port for the socket that is being bound 
 server.sin_family=AF_INET; 
 server.sin_addr.s_addr=inet_addr("127.0.0.1"); 
 server.sin_port=htons(8080); // listen on telnet port 23
  
  // bind our socket to a port(port 8080) 
 if( bind(sock,(SOCKADDR *)&server,sizeof(server)) == SOCKET_ERROR) {
        wprintf(L"bind failed with error: %ld\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return 1;
    }
   
 // listen for a connection  
 if(listen(sock,5) == SOCKET_ERROR) {
        wprintf(L"listen failed with error: %ld\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
        return 1;
    }
 SOCKET client;
 struct sockaddr_in client_info;
 int fromlen = sizeof(client_info);
 while(TRUE)
 { 
  // accept connections
  client = accept(sock, (struct sockaddr*) &client_info,&fromlen);
  if (client == INVALID_SOCKET) 	{
        wprintf(L"accept failed with error: %ld\n", WSAGetLastError());
        closesocket(sock);
        WSACleanup();
                 return 1;
  } else
   printf("Client connected from: %s:%d\n", inet_ntoa(client_info.sin_addr), ntohs(client_info.sin_port)); 
   
  // create our recv_cmds thread and parse client socket as a parameter
  CreateThread(NULL, 0,multi_client,(LPVOID)client, 0, &thread);  
 }
  
 // shutdown winsock
 closesocket(sock); 
 WSACleanup(); 
  
 // exit
 return 0;
}


