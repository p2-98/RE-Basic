#include <stdio.h>
#include <winsock2.h>
#define DEFAULT_BUFLEN 512

int main()
{

int iResult;
  WSADATA wsaData;
  iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
  if (iResult != NO_ERROR)
    printf("Client: Error at WSAStartup().\n");
  else
    printf("Client: WSAStartup() is OK.\n");

  SOCKET ConnectSocket;
  ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (ConnectSocket == INVALID_SOCKET)
  {
    printf("Client: Error at socket(): %ld.\n", WSAGetLastError());
    WSACleanup();
    return 0;
  }

  else
    printf("Client: socket() is OK.\n");
  sockaddr_in cliAddr;
  cliAddr.sin_family = AF_INET;
  cliAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  cliAddr.sin_port = htons(8080);
 iResult=connect(ConnectSocket, (SOCKADDR*)&cliAddr, sizeof(cliAddr)) ;
  if(iResult == SOCKET_ERROR)
  {
    wprintf(L"Client: Failed to connect.\n");
      closesocket(ConnectSocket);
    WSACleanup();
    return 0;
  }

  
  while(TRUE) 
   {
    char sendbytes[225];
    int recvbuflen=DEFAULT_BUFLEN ;
    char recvbuf[100 ] = "";

 
    printf("Data sent server: ");
    gets(sendbytes);
    iResult = send( ConnectSocket, sendbytes, (int)strlen(sendbytes), 0 );
    if (iResult == SOCKET_ERROR)
	 {
        wprintf(L"send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
     }
    iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 ) 
		{
            printf("Bytes received server: %s\n",recvbuf);
        }
        else if ( iResult == 0 )
            wprintf(L"Connection closed\n");
        else
            wprintf(L"recv failed with error: %d\n", WSAGetLastError());
    if(strstr(recvbuf,"Disconnected"))   
	{
        iResult = shutdown(ConnectSocket, SD_SEND);
        if (iResult == SOCKET_ERROR) 
		{
        wprintf(L"shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
        }
    }
  }
  
    iResult = closesocket(ConnectSocket);
    if (iResult == SOCKET_ERROR) 
	{
        wprintf(L"close failed with error: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }
    WSACleanup();
    return 0;
}
