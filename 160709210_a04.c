/*Vinuyaa Sivanathan
Cp386*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{

	int alloc[5][5];
	int avaiRes[4];
	int n=5;

	for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
		//printf("%s",argv[j+1]);
		alloc[i][j] = atoi(argv[j+1]);
		avaiRes[j] = atoi(argv[j+1]);}}


	printf("Number of Customers:%d\n",n);
	printf("Currently Available resources:%s %s %s %s\n",argv[1],argv[2],argv[3],argv[4]);
	printf("Maximum resources on file:\n");

	//Read File

	FILE *in = fopen("sample4_in.txt", "r");
	if(!in)
	{
		printf("Child A: Error in opening input file...exiting with error code -1\n");
		return -1;
	}

	struct stat st;
	fstat(fileno(in), &st);
	char* fileContent = (char*)malloc(((int)st.st_size+1)* sizeof(char));
	fileContent[0]='\0';
	while(!feof(in))
	{
		char line[100];
		if(fgets(line,100,in)!=NULL)
		{	printf("%s", line);
			strncat(fileContent,line,strlen(line));
		}
	}
	fclose(in);

	// Maximum Array 
	char* line;
	char* maxArrayLines[n];
	int maxArray[n][4];
	char* token = NULL;
	int r =0 ;

	line = strtok(fileContent,"\n");



	while(line!=NULL)
	{
		maxArrayLines[r] = malloc(sizeof(line)*sizeof(char));
		strcpy(maxArrayLines[r],line);
		line = strtok(NULL,"\n");
		r++;
	}


	for(int k=0; k<n; k++){
		r=0;
		token =  strtok(maxArrayLines[k],",");
		while(token!=NULL)
		{	//printf(" %s ",token);
			maxArray[k][r]=atoi(token);
			token = strtok(NULL,",");
			r++;
		}
	}


	char command[256];
	int i_resource;
	char c_resource;
        printf("\nEnter Command:");
	scanf("%[^\n]", command);
	getchar();


        //Need Matrix
        int needMatrix[n][4];

	while (command != "" ){

	if (command[0]=='R' && command[1]=='Q'){
		c_resource = command[3];
		i_resource = c_resource - '0' ;
		//printf("%d",(command[5] - '0'));
		if (avaiRes[0] >= (command[5] - '0') && avaiRes[1] >= (command[7] - '0') && avaiRes[2] >= (command[9] - '0') && avaiRes[3] >= (command[11] - '0')){
			alloc[i_resource][0] = (command[5]- '0');
			alloc[i_resource][1] = (command[7]- '0');
			alloc[i_resource][2] = (command[9]- '0');
			alloc[i_resource][3] = (command[11]- '0');
			printf("Request Satisfied\n");}
		else {printf("Request Denied\n");}}
	else if (command[0]=='R' && command[1]=='L'){
                c_resource = command[3];
                i_resource = c_resource - '0' ;
                //printf("%d",(command[5] - '0'));
                if (alloc[i_resource][0] >= (command[5] - '0') && alloc[i_resource][1] >= (command[7] - '0') && alloc[i_resource][2] >= (command[9] - '0') && alloc[i_resource][3] >= (command[11] - '0')){
                        alloc[i_resource][0] -= (command[5]- '0');
                        alloc[i_resource][1] -= (command[7]- '0');
                        alloc[i_resource][2] -= (command[9]- '0');
                        alloc[i_resource][3] -= (command[11]- '0');
                        printf("Request Satisfied\n");}
                else {printf("Request Denied\n");}}
	else if(command[0]=='*'){
                printf("\nAllocation Matrix:\n");
		for(int k=0; k<n; k++){
	                for(int j=0; j<n-1; j++){
			printf("%d ", alloc[k][j]);}
			printf("\n");}
		printf("\nMaxiumum Matrix:\n");
                for(int k=0; k<n; k++){
                        for(int j=0; j<n-1; j++){
                        printf("%d ", maxArray[k][j]);}
			printf("\n");}
                printf("\nNeed Matrix:\n");
                //Need Matrix

        	for(int k=0; k<n; k++){
             	for(int j=0; j<n-1; j++){
             		needMatrix[k][j] =  maxArray[k][j]-alloc[k][j];}}

		for(int k=0; k<n; k++){
                        for(int j=0; j<n-1; j++){
                        printf("%d ", needMatrix[k][j]);}
                        printf("\n");}
	   	//Available Matrix

		printf("\nAvailable  Matrix:\n");

		for(int k=0; k<n-1; k++){
             		//avaiMatrix[k][j] = atoi(argv[j+1])- maxArray[k][j];
                        printf("%d ",avaiRes[k]);} printf("\n");

	}
	else if (command[0]=='R' && command[1]=='u') {
                for(int k=0; k<n; k++){
                for(int j=0; j<n-1; j++){
                        needMatrix[k][j] =  maxArray[k][j]-alloc[k][j];}}

		int complete[5];
		int seq[5];
		int s = 0;
		int turn = 0 ;

		for (int i = 0; i < n; i++)
                        complete[i]=0;


		for(int i=0; i<n; i++){
			for (int j = 0; j < n; j++) {
			if (complete[j]==0){
				turn = 0;
				for (int k = 0;  k < n-1;k++){
				if (needMatrix[j][k]>avaiRes[k]) {
					turn=1;
					break;}
				}
			if  (turn==0){
				seq[s]=j;
				s++;
				for (int l = 0; l < n-1; l++){
					avaiRes[l] = avaiRes[l] + alloc[j][l];}
				complete[j]= 1 ;}

				}
			}
		}

		printf("Safe Sequence is:<" );
                for (int l = 0; l < n; l++)
	                printf(" %d ", seq[l]);
		printf(">\nNow going to executing the threads:\n\n" );
		for(int j=0; j<n-1; j++){
			avaiRes[j] = atoi(argv[j+1]);}

		for (int l = 0; l < n; l++){
			printf("\n--> Customer/Thread %d", seq[l]);

			printf("\n\tAllocated resources: ");
			for(int j=0; j<n-1; j++){
                        	printf("%d ", alloc[l][j]);}

                        printf("\n\tNeeded resources: ");
                        for(int j=0; j<n-1; j++){
                                printf("%d ", needMatrix[l][j]);}

			printf("\n\tAvailable resources: ");
                        for(int j=0; j<n-1; j++){
				printf("%d ", avaiRes[j]);}

			printf("\n\tThread has started\n\tThread has finished\n\tThread is releasing resources");
			printf("\n\tNew Available: ");
                        for(int j=0; j<n-1; j++){
				avaiRes[j] +=  alloc[l][j] ;
                                printf("%d ", avaiRes[j]);}

			}
		printf("\n");

	}
        printf("Enter Command:");
        scanf("%[^\n]", command);
        getchar();

}


	return 0;
}



