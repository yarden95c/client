//
// Created by yarden95c on 25/12/16.
//

#include <fstream>
#include "Communication.h"

using namespace std;

Communication::Communication() {
}

Communication::~Communication() {
  //  delete (driver);
}

void Communication::startCommunicate() {
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    char data[] = "hello";
    int data_len = sizeof(data);

    int sent_bytes = sendto(sock, data, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }

    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }

    cout << "The server sent: " << buffer << endl;

    close(sock);

}




