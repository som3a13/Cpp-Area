// tcp_client.cpp
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // Create socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error\n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address / Address not supported\n";
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection failed\n";
        return -1;
    }

    std::cout << "Connected to server" << std::endl;

    // Continuous receiving of temperature data
    while (true) {
        std::memset(buffer, 0, sizeof(buffer));
        int valread = read(sock, buffer, 1024);
        if (valread <= 0) {
            std::cout << "Server disconnected or error occurred\n";
            break;
        }
        std::cout << "Received: " << buffer;
    }

    // Close the socket
    close(sock);
    return 0;
}
