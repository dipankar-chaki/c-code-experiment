#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Image
{
	char header[4];
	int width;
	int height;
	char data[10];
};

int ProcessImage(char* filename){

	FILE *fp;
	char ch;
	struct Image img;

	fp = fopen(filename,"r"); 

	if(fp == NULL)
	{
		printf("\nCan't open file or file doesn't exist.");
		exit(0);
	}

	printf("\n\tHeader\twidth\theight\tdata\t\r\n");

	while(fread(&img,sizeof(img),1,fp)>0){
		printf("\n\t%s\t%d\t%d\t%s\r\n",img.header,img.width,img.height,img.data);
	
		int size1 = img.width + img.height;
		char* buff1=(char*)malloc(size1);

		memcpy(buff1,img.data,sizeof(img.data));
		free(buff1);
	
		if (size1/2==0){
			free(buff1);
		}
		else{
			if(size1 == 123456){
				buff1[0]='a';
			}
		}

		int size2 = img.width - img.height+100;
		//printf("Size1:%d",size1);
		char* buff2=(char*)malloc(size2);

		memcpy(buff2,img.data,sizeof(img.data));

		int size3= img.width/img.height;
		//printf("Size2:%d",size3);

		char buff3[10];
		char* buff4 =(char*)malloc(size3);
		memcpy(buff4,img.data,sizeof(img.data));

		char OOBR_stack = buff3[size3+100];
		char OOBR_heap = buff4[100];

		buff3[size3+100]='c';
		buff4[100]='c';

		if(size3>10){
				buff4=0;
		}
		else{
			free(buff4);
		}

		free(buff2);
	}
	fclose(fp);
}

int main(int argc,char **argv)
{
	ProcessImage(argv[1]);
}


// #include <stdio.h>

// int main() {

//     char str1[10];
//     char str2[]="abcdefghijklmn";
//     strcpy(str1,str2);

    
    // int number1, number2, sum;

    // // Ask for input
    // printf("Enter two integers: ");
    // scanf("%d %d", &number1, &number2);

    // // Calculate the sum
    // sum = number1 + number2;

    // // Display the result
    // printf("%d + %d = %d\n", number1, number2, sum);

    // return 0;
//}
