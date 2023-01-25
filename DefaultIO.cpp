#include "DefaultIOo.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <regex.h>
#include <cstring>
#include "Myvector.h"
#include "Data.h"
/******************
 * Function Name: getflag
 * Input: none
 * Output: bool
 * Function Operation: geting flag value
 ******************/
bool DefaultIO::getflag()
{
    return this->stat;
}
/******************
 * Function Name: socketIO ctor
 * Input: int sock
 * Output: socketIO
 * Function Operation: ctor
 ******************/
SocketIO::SocketIO(int sockk)
{
    this->sock = sockk;
}
/******************
 * Function Name: default ctor
 * Input: none
 * Output: DefaultIO
 * Function Operation:
 ******************/
DefaultIO::DefaultIO()
{
}
/******************
 * Function Name: write
 * Input: string
 * Output: void
 * Function Operation: write to the reciver
 ******************/
void SocketIO::write(std::string s)
{
    int expected_data_len = sizeof(buffer);
    memset(buffer, 0, expected_data_len * (sizeof buffer[0]));
    strcpy(buffer, s.c_str());
    int sent_bytes = send(sock, buffer, expected_data_len, 0);
    if (sent_bytes < 0)
    {
        this->stat = false;
    }
}
/******************
 * Function Name: read
 * Input: none
 * Output: string
 * Function Operation: read from sender
 ******************/
std::string SocketIO::read()
{
    int expected_data_len = sizeof(buffer);
    memset(buffer, 0, expected_data_len * (sizeof buffer[0]));
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes == 0)
    {
        stat = false;
    }
    else if (read_bytes < 0)
    {
        stat = false;
    }
    return buffer;
}