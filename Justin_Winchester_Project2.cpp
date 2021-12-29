/* =================================================================================================================================================================================================================================
Programmer:			Justin Winchester
Instructor:			Dr. Zhao 
Course:				Operating Systems
Project Number & Title:  	2 - Matrix Multiplication (File Name: Justin_Winchester_Project2.cpp)
Institution:			Cameron University 	
Decription: 			This program performs multiplication of two matrices using memory allocation and threads! This program uses a struct to pass data to the threads and has the threads perform the multiplication 
				of each row. The rows and columns are of variable size and have been dynamically allocated using malloc in the C program. This is a typical c program with integer decalartions and for loops! 


================================================================================================================================================================================================================================= */


//Libraries!!!
/* ============================================================================================================================================================================================================================= */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/* ============================================================================================================================================================================================================================== */
//Declare variables/ Struct for matrix values/ Declare Main Thread !
/* =========================================================================================================================================================================================================================== */
int row1, col1, row2, col2;
int **a, **b, **c; 

struct matrix_index
{
	long long  i, j; //Struct Declaration, Long integer have a wider Range!!!!
};

void *matrix_thread( void* param)
{
	struct matrix_index values = *(struct matrix_index *) param;

	long long i = values.i;  //Declare i & j values or element values to store long long integers so can hold larger numeric values 
	long long j = values.j; // Long int 

	c[i][j] = ( a[i][0] * b[0][j]) + (a[i][1] * b[1][j]);
}
/* ============================================================================================================================================================================================================================== */
//Main Function
/* ============================================================================================================================================================================================================================== */

int main(int argc, char *argv[])
{
	int i, j;
	//Get rows and column order of 1st Matrix
	 printf("Please Enter The Number of the ROWS then press enter and Then enter the Number of COLUMNS\n");

	scanf("%d", &row1);	//Get the row order of Matrix from user/keyboard/input device
	scanf("%d", &col1);	///Get the column order of Matrix from user/keyboard/input device

	//Malloc Matrix1 : I found that if i tried to allocate all three matrices together before recieving their iput from keyboard resulted in an error so we will allocate each Matrix individually in MAIN 
	a = (int**)malloc(row1 * sizeof(int *)); //allocate memory for rows (really point pointer to left part of 2dimensional array 
	for(int i =0; i<row1; i++){
		a[i]=(int*) malloc(col1 * sizeof(int *)); //Create rows & columns "2d" Array 
	}
	  //Initialize the elelments in 1st matrix
        for(i = 0; i < row1; i++){     //Loop to get elements for First Matrix ~
         for(j = 0; j <col1; j++)
         {       printf("please enter elements ");

                scanf("%d", &a[i][j]); // Get each individual element from keyboard 
                        }
        }
	printf("\nMatrix Number One\n You Have Entered A:  ");
	printf(" %d", row1,"\t"); 
	printf(" :By:"," "); 
	printf( "%d",col1);
	printf( " Matrix\n");
	printf("\nHere Is Matrix Number One & it'z Elements!!!\n"); 

         for(i = 0; i < row1; i++)     //Loopz to shows user what first matrix looks like
        {
                for(j = 0; j <col1; j++)
                {
                        printf("%d\t", a[i][j]);  //...print first matrix elements 
                }

                printf("\n");

        }

	//Get rows and column order of 2nd Matrix
         printf("Please Enter The Number of the ROWS: then press enter and then Enter the Number of COLUMNS\n");


	scanf("%d", &row2);
        scanf("%d", &col2);
       	
	if(col1!=row2){
                printf("Sorry Can Not Multiply Matrices! For Matrix Multiplication to be Defined Your Column Size of First Matrix Must Equal Your Row Size of Your Second Matrix!!!\nPlease RE-TRY Program!!!");
        	exit(0);
	}


	// Malloc(Memory Allocate)  Matrix2
        b = (int**)malloc(row2 * sizeof(int *));       //Allocate # of Rows for second Matrix
        for(int i =0; i<row2; i++){
                b[i]= (int*)malloc(col2 * sizeof(int *)); //Allocate # of Columns for second Matrix
        }

        //Initialize the elelments in 2nd Matrix
        for(i = 0; i < row2; i++){
         for(j = 0; j <col2; j++)
         {	 printf("please enter elements ");  //Prompt for user(repeats)

                scanf("%d", &b[i][j]);        //Get elements for second matrix 
		
	}	

	}
	printf("\nMatrix Number Two:\n You Have Entered A:  ");
        printf(" %d", row2,"\t");
        printf(" :By:"," ");
        printf( "%d",col2);
        printf( "\nMatrix\n");
        printf("\nHere Is Matrix Number 2 & it'z Elements!!!\n");



	  //Show user what second matrix looks like
	 
	 for(i = 0; i < row2; i++)
        {
                for(j = 0; j <col2; j++)
                {
                        printf("%d\t", b[i][j]);  //.. print elements of second matrix entered in program 
                }

                printf("\n");

        
	}
	
        //Malloc(Memory Allocate) Matrix3
       c =(int**) malloc(row1 * sizeof(int *)); // allocate rows for third matrix must be size of first matrix
        for(int i =0; i<col1; i++){
             c[i]=(int*) malloc(col2 * sizeof(int *)); //Colums for third matrix must size of columns of second matrix
        }


	
	
       
//	printf("Now thread will begin their jobs !! ");
 
for(i = 0; i < row1; i++){
         for(j = 0; j <col2; j++)    //Create loop to create threadz !!! Loops repeats by the order of third/output/resultant Matrix!!!
         {


	struct matrix_index *m;    // Initialze struct 
	m = (struct matrix_index* ) malloc(sizeof(struct matrix_index)); //Allocate memory
	m->i = i;      //Store values .....
	m->j = j;
	 
	pthread_t tid;  //Declare thread id
	pthread_attr_t attr; //Thread attributes
	pthread_attr_init(&attr);//Initilization of thread atts
	pthread_create(&tid, &attr, matrix_thread, m); // Create Thread, pass function to multiply Matrices rows by columns and pass struct values as parameters!
	pthread_join(tid, NULL); // Join Threads Main thread waits for all threads to complete work!!!! 
	}
}

	printf("\nResult of matrix multiplication!:\n" );  // Print third matrix containing results of matrix Multiplication usuing for loops and selection each array element 
	for(i = 0; i < row1; i++)
	{
		for(j = 0; j <col2; j++)
		{
			printf("%d\t", c[i][j]);
		}

		printf("\n");

	}

	return 0; // Program completes!!!! 
}
			
