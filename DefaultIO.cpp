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


bool DefaultIO::getflag(){
    return this->stat;
}

SocketIO::SocketIO(int sockk)
{
  this->sock=sockk;
}
DefaultIO::DefaultIO(){
    
}
void SocketIO:: write(std::string s) {
                char buffer[4096];
                int expected_data_len = sizeof(buffer);
                memset(buffer, 0, expected_data_len * (sizeof buffer[0]));
                strcpy(buffer,s.c_str());
               int sent_bytes = send(sock, buffer, expected_data_len, 0);
                if (sent_bytes < 0)
                {
                 this->stat=false;
                 }
           
}

std::string SocketIO::read(){
                char buffer[4096];
                int expected_data_len = sizeof(buffer);
            memset(buffer, 0, expected_data_len * (sizeof buffer[0]));
            int read_bytes = recv(sock, buffer, expected_data_len, 0);
               if (read_bytes == 0)
            {
                stat=false;
            }
            else if (read_bytes < 0)
            {
                stat=false;
                
            }
          return buffer;
            
}