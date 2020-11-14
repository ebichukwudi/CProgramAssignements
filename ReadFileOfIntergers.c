/* Use of FILE I/O
 * Ebi Chukwudi
 * 14/11/2020
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 100

//define the function to read data from the file
void ReadData(FILE *ptr, int data[], int *size)
{
	//in this exercise the first data in the file determines the 
	//maximum data be read from the file
	int maxSize;
	//initialise the maxSize
	fscanf(ptr,"%d",&maxSize);

	//initialise the actual size with 0
	*size = 0;

	//now read all the data from the file
	while((fscanf(ptr,"%d",&data[*size]) == 1) && (*size < maxSize))
	{
		(*size)++;
	}
}

//define the function to calculate the average
double Average(int data[],int size)
{
	int i;
	double avg = 0.0;
	double sum = 0;
	for (i = 0; i < size; i++)
	{
		sum += data[i];
	}

	avg = (sum/size);

	return  avg;
}

//define the function to calculate the max number read
int MaxNumber(int data[],int size)
{
	int i;
	//declare and initialise the maximum numnuber with the first
	//data in the data array. 
	int maxNumber = data[0];

	//go through the data to determine the maximum
	for(i = 1; i < size; i++)
	{
	   if(maxNumber<data[i])
	   {
		maxNumber = data[i];
	   }
	}

	return maxNumber;
}

//define the function to print the data read
void PrintData(int data[],int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		printf("%d\t",data[i]);

		if( (i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
}

int main(int argc, char* args[])
{
	int size = MAX_ARRAY_SIZE;
	FILE *ifp;
	int data[MAX_ARRAY_SIZE] = {0};
	double average = 0.0;
	int max;

	//check if the user supplied the input file as argument 
	//if not return immediately

	if (argc != 2)
	{
		printf("You need to include filename or path to run the code");                return -1;
	}
	else
	{
		ifp = fopen(args[1],"r");
		ReadData(ifp,data,&size);

		PrintData(data,size);

		average = Average(data,size);
		max = MaxNumber(data,size);

		//print the average number
		printf("The average number read from the file is :%lf \n",average);
		//print the maximum number
		printf("The maximum number read from the file is :%d \n",max);
	}

	return 0;
}
    


