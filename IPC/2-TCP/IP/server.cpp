// tcp_server.cpp
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>

void handle_client(int client_socket) {
    char buffer[1024] = {0};
    while (true) {
        // Simulate temperature reading
        int temperature = std::rand() % 40; // Random temperature between 0 and 39
        std::string temp_str = "Temperature: " + std::to_string(temperature) + "C\n";
        
        // Send the temperature data
        send(client_socket, temp_str.c_str(), temp_str.length(), 0);
        std::cout << "Sent to client: " << temp_str;

        // Delay to simulate periodic sensor reading
        sleep(1);
    }

    // Close the client socket
    close(client_socket);
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Seed for random number generation
    std::srand(std::time(0));

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind the socket to the network address and port
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    std::cout << "Waiting for connections..." << std::endl;

    std::vector<std::thread> client_threads;

    // Accept multiple incoming connections
    while (true) {
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        std::cout << "New connection established" << std::endl;

        // Handle each client in a new thread
        client_threads.emplace_back(handle_client, new_socket);
    }

    // Join all threads before exiting (this part is never reached in this example)
    for (auto& thread : client_threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    // Close the server socket
    close(server_fd);
    return 0;
}

/*TCP
                +-----------------+                            +-----------------+
                |     Client      |                            |     Server      |
                +-----------------+                            +-----------------+
                |                 |                            |                 |
                |    socket()     |                            |    socket()     |
                |        |        |                            |        |        |
                |        v        |                            |        v        |
                |    connect()    |                            |    bind()       |
                |        |        |                            |        |        |
                |        v        |                            |        v        |
                | send()/recv()   |                            |    listen()     |
                |        |        |                            |        |        |
                |        v        |                            |        v        |
                |    close()      |                            |    accept()     |
                |                 |                            |        |        |
                +-----------------+                            |        v        |
                                                              | send()/recv()   |
                                                              |        |        |
                                                              |        v        |
                                                              |    close()      |
                                                              |                 |
                                                              +-----------------+

*/
/*UDP
                +-----------------+                            +-----------------+
                |     Client      |                            |     Server      |
                +-----------------+                            +-----------------+
                |                 |                            |                 |
                |    socket()     |                            |    socket()     |
                |        |        |                            |        |        |
                |        v        |                            |        v        |
                |    sendto()     |                            |    bind()       |
                |        |        |                            |        |        |
                |        v        |                            |        v        |
                |    recvfrom()   |                            |    recvfrom()   |
                |        |        |                            |        |        |
                |        v        |                            |        v        |
                |    close()      |                            |    sendto()     |
                |                 |                            |        |        |
                +-----------------+                            |        v        |
                                                              |    close()      |
                                                              |                 |
                                                              +-----------------+



*/