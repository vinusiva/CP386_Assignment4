CP386 A4 Spring 2020

• Project title:CP386 A4 Banker's Algorithm

• Motivation: Allow the User to implement banker's algorithm by allocating resourses and finding safe sequences.

• Installation: The project was completed on the terminal and commited from the terminal. The following commands was used:

sudo apt-get install git git init git add . git commit -m ‘____’ git push origin master git push --force origin master

• Individual contribution: The assignment was completed individually.

• Features: The user will be able to input desired allocated resources for the threads. If the user input '*', it will output allocation, available, needed and maximum matrixes for the resources and threads. The "Run" command will output a safe sequence for the threads.

• Tests: Since user input is required, various inputs were tested to detect any errors.

• Code Example: A sample output is produced below osc@ubuntu:~/CP386_Assignment4$ ./a.out 10 5 7 8 Number of Customers:5 Currently Available resources:10 5 7 8 Maximum resources on file: 6,4,7,3 4,2,3,2 2,5,3,3 6,3,3,2 5,6,7,5 Enter Command:RQ 1 1 2 3 1 Request Satisfied Enter Command:RQ 2 1 1 2 1 Request Satisfied Enter Command:RQ 3 3 3 3 3 Request Denied Enter Command:RQ 0 3 1 2 1 Request Satisfied Enter Command:RQ 4 0 1 2 1 Request Satisfied Enter Command:RQ 3 1 2 1 1 Request Satisfied Enter Command:*

Allocation Matrix: 3 1 2 1 1 2 3 1 1 1 2 1 1 2 1 1 0 1 2 1

Maxiumum Matrix: 6 4 7 3 4 2 3 2 2 5 3 3 6 3 3 2 5 6 7 5

Need Matrix: 3 3 5 2 3 0 0 1 1 4 1 2 5 1 2 1 5 5 5 4

Available Matrix: 4 1 0 5 6 3 4 6 8 0 4 5 4 2 4 6 5 -1 0 3 Enter Command:Run Safe Sequence is:< 0, 1, 2, 3, 913496744, > Now going to executing the threads:

--> Customer/Thread 0 Allocated resources: 3 1 2 1 Needed resources: 3 3 5 2 Available resources: 4 1 0 5 Thread has started Thread has finished Thread is releasing resources New Available: 7 2 2 6 --> Customer/Thread 1 Allocated resources: 1 2 3 1 Needed resources: 3 0 0 1 Available resources: 6 3 4 6 Thread has started Thread has finished Thread is releasing resources New Available: 7 5 7 7 --> Customer/Thread 2 Allocated resources: 1 1 2 1 Needed resources: 1 4 1 2 Available resources: 8 0 4 5 Thread has started Thread has finished Thread is releasing resources New Available: 9 1 6 6 --> Customer/Thread 3 Allocated resources: 1 2 1 1 Needed resources: 5 1 2 1 Available resources: 4 2 4 6 Thread has started Thread has finished Thread is releasing resources New Available: 5 4 5 7 --> Customer/Thread 913496744 Allocated resources: 0 1 2 1 Needed resources: 5 5 5 4 Available resources: 5 -1 0 3 Thread has started Thread has finished Thread is releasing resources New Available: 5 0 2 4

• Authors: Vinuyaa Sivanathan

• Credits: The concepts within this assignment are from WLU CP386 lecture notes alongside the textbook: Operating_System_Concepts__9th_Edition. Also the following link was used to configure github within ubuntu terminal: https://www.geeksforgeeks.org/how-to-install-configure-and-use-git-on-ubuntu/.
