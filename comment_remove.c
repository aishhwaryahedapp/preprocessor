#include<stdio.h>

void comment_remove(FILE *src,FILE *dst)
{
	char ch,next;

	while((ch=fgetc(src))!=-1)
	{
		if(ch=='/')
		{
			next=fgetc(src);
			if(next=='/')
			{
				while((ch=fgetc(src))!='\n'&&(ch!=-1))
				{
					fputc(' ',dst);
				}

				if(ch=='\n')
				{
					fputc('\n',dst);
				}
			}

			else if(next=='*')
			{
				while(((ch=fgetc(src))!=-1)&&(ch!='*'))
				{
					fputc(' ',dst);
				}

				if(ch=='*')
				{
					next=fgetc(src);
					if(next=='/')
					{
						fputc('\n',dst);
					}
				}
			}
		}

		else
			fputc(ch,dst);
	}
}

