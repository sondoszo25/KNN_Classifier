# hm4
in this homework we have server which gets from user port by the command line, and client which recive 
ip address and port from user using the command line.(we can have multi clients).
first we write make and then
to run server : ./server.out port   
to run client : ./client.out ip port    

the client run until it recive 8 from the user(commandline)
each time the client prints this menu and the user has to choose option(number from 1-5).
Welcome to the KNN Classifier Server. Please choose an option:
1. upload an unclassified csv data file
2. algorithm settings
3. classify data
4. display results
5. download results
8. exit

the server checks if the input is valid.if the input(choice) is invalid, the client asks the user to try again,
else,  executes the command with index choise.

in case the k is bigger than the file size the server send to client inavlid input.
in case ip address or port  the client prints invalid and close.
in case port not vaild the server print invaild and close.
in first command if the first file is invalid we continue to get the input for the second file but we don't replace them
with the old files.(if one of the files is invalid we dont replace the old files).
in 5th command we take the path of folder which the user wants to save the result file in, and we create
file results.txt and write the results into it.
vectors with differnt length we calculate the distance accroding to shortest.
we accept scientific notaion numbers.
in case there are extra spaces in the input, the program print invalid input.    
port>=0 port<=65535     
ip address allowed is  w.x.y.z // 0<=w,x,y,z<=255
