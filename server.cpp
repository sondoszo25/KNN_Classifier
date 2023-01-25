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
#include "DefaultIOo.h"
#include "CLI.h"
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "invalid input run again" << endl;
        return 0;
    }
    int num;
    try
    {
        num = stod(argv[1]);
    }
    catch (exception e)
    {
        cout << "invalid input run again" << endl;
        return 0;
    }
    string moaa;
    vector<double> v222;
    char delim222[1];
    delim222[0] = ',';
    MakeData data99(argv[1], delim222, v222, 0, moaa);
    if (data99.makeInput() == 0)
    {
        cout << "invalid input run again" << endl;
        return 0;
    }
    if (num > 65535 || num < 0)
    {
        cout << "invalid input run again" << endl;
        return 0;
    }
    const int server_port = stod(argv[1]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {

        perror("error creating socket");
        return 0;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
        close(sock);
        return 0;
    }
    if (listen(sock, 5) < 0)
    {
        close(sock);
        perror("error listening to a socket");
    }
    while (1)
    {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        if (client_sock < 0)
        {
            perror("error accepting client");
            close(client_sock);
            continue;
        }
        else
        {

            SocketIO sockio(client_sock);
            Cli cli(&sockio);
            string input;
            int num;
            int pid = fork();
            string inputlist = "Welcome to the KNN Classifier Server. Please choose an option:\n1. upload an unclassified csv data file\n2. algorithm settings\n3. classify data\n4. display results\n5. download results\n8. exit";
            if (pid == 0)
            {
                if (!(sockio.getflag()))
                {
                    close(client_sock);
                    break;
                }
                int num;
                while (1)
                {
                    sockio.write(inputlist);
                    if (!sockio.getflag())
                    {
                        close(client_sock);
                        break;
                    }
                    input = sockio.read();
                    if (!sockio.getflag())
                    {
                        close(client_sock);
                        break;
                    }
                    try
                    {
                        num = stod(input);
                        if (!(0 < num && num < 6))
                        {
                            sockio.write("invalid choice");
                            continue;
                        }
                    }
                    catch (exception e)
                    {
                        sockio.write("invalid choice");
                        continue;
                    }
                   
                        cli.start(num);
                    
                }
                close(client_sock);
                return 0;
            }
        }
    }
    close(sock);
    return 0;
}