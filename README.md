# KNN Classifier Server
## Overview

This project implements a client-server system for running a K-Nearest Neighbors (KNN) classifier over CSV data.
The server receives a port number as a command-line argument, and the client connects to the server using an IP address and port. Multiple clients can connect simultaneously.

## Build and Run
``` bash
# 1. compile
make

# 2. run the server
./server.out <port>

# 3. run the client
./client.out <ip> <port>
```

# Client Menu
When connected, the client displays the following menu:

```
Welcome to the KNN Classifier Server. Please choose an option:
1. Upload an unclassified CSV data file
2. Algorithm settings (set k and distance metric, default: k=5, metric=AUC)
3. Classify data
4. Display results
5. Download results
8. Exit
```

Each selection is validated and executed by the server. Invalid choices trigger a retry prompt on the client side.

# Key Features

* Multi-client support.

* Input validation and error handling.

* Thread-safe server design.

* Configurable KNN parameters (k and distance metric).

* File upload, classification, and results download over sockets.
