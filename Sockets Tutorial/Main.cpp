#include <iostream>
#include <winsock2.h> //windows socket lib

/**
 *
 * NOTE
 * Compile with linker flag: -lws2_32
 */

int main()
{
    // OS is windows, first initialize the socket library
    WSADATA wsaData;                                   // Struct that holds winsock implementation info
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData); // Startup the socket with version 2.2
    if (result != 0)
    {
        std::cerr << "WSAStartup Failed: " << result << std::endl;
        return 1;
    }

    // Create a TCP (Stream) IPv4 socket
    SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (listenSock == INVALID_SOCKET)
    {
        std::cerr << "socket() failed, error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    std::cout << "Socket created (SOCKET = " << listenSock << ")" << std::endl;

    // Initializing the IPV4 socket address struct
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    int PORT = 54000;
    address.sin_port = htons(PORT);

    // Binding the socket to the ip/port
    if (bind(listenSock, (sockaddr *)&address, sizeof(address)) == SOCKET_ERROR)
    {
        std::cerr << "bind() failed, error: " << WSAGetLastError() << std::endl;
        closesocket(listenSock);
        WSACleanup();
        return 1;
    }

    std::cout << "socket bound to port " << PORT << std::endl;

    // Listening for connections on specific socket
    if (listen(listenSock, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "listen() failed, error: " << WSAGetLastError() << std::endl;
        closesocket(listenSock);
        WSACleanup();
        return 1;
    }

    std::cout << "Server is listening on PORT: " << PORT << std::endl;

    // Define the client address;
    sockaddr_in clientAddress;
    int clientSize = sizeof(clientAddress);

    while (true)
    {
        // Accept a connection which returns a socket to communicate with the client
        SOCKET clientSocket = accept(listenSock, (sockaddr *)&clientAddress, &clientSize);

        if (clientSocket == INVALID_SOCKET)
        {
            std::cerr << "accept() failed, error: " << WSAGetLastError() << std::endl;
            closesocket(listenSock);
            WSACleanup();
            return 1;
        }

        // Actual receiving and sending with the socket

        char buffer[4096]; // Data from client is stored here

        // Receive data from the client
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == SOCKET_ERROR)
        {
            std::cerr << "recv() failed, error: " << WSAGetLastError() << std::endl;
        }
        else if (bytesReceived == 0)
        {
            std::cout << "Client disconnected" << std::endl;
        }
        else
        {
            buffer[bytesReceived] = '\0';
            std::cout << "This is what the client sent:\n"
                      << buffer << std::endl;
            // Echo/Send it back to the client
            int bytesSent = send(clientSocket, buffer, sizeof(buffer), 0);
            if (bytesSent == 0)
            {
                std::cerr << "send() failed, error: " << WSAGetLastError() << std::endl;
            }
            else
            {
                std::cout << "sent " << bytesSent << " bytes back" << std::endl;
            }
        }
        closesocket(clientSocket);
    }

    closesocket(listenSock);
    result = WSACleanup(); // Close the socket
    if (result != 0)
    {
        std::cerr << "WSACleanup failed: " << result << std::endl;
        return 1;
    }
    return 0;
}