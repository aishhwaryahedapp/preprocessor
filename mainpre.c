#include<stdio.h>

void comment_remove(FILE *,FILE *); 
void file_inclusion(FILE *,FILE *); 
void macro_substitution(FILE *,FILE *); 

int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("USAGE:./a.out fname\n");
		return 1;
	}

	FILE *src=fopen(argv[1],"r");
	FILE *temp=fopen("temp.txt","w");

	if(src==0)
	{
		printf("FILE IS NOT PRESENT\n");
		return 1;
	}

	//comment_remove(src,temp);
	file_inclusion(src,temp);
	fclose(src);
	fclose(temp);


	temp=fopen("temp.txt","r");
	FILE *temp1=fopen("temp1.txt","w");
	if(temp==0)
	{
		printf("FILE IS NOT AVAIALBLE\n");
		return 1;
	}
	comment_remove(temp,temp1);
	//file_inclusion(temp,dst);
	fclose(temp);
	fclose(temp1);

	temp1=fopen("temp1.txt","r");
	if(temp1==0)
	{
		printf("FILE IS NOT AVAIALBLE\n");
		return 1;
	}
	FILE *dst=fopen("output.i","w");
	macro_substitution(temp1,dst);
	fclose(temp1);
	fclose(dst);

	return 0;
}

