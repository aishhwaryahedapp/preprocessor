#include<stdio.h>
#include<string.h>

void file_inclusion(FILE *src,FILE *dst)
{
	char m[100],s[100]="#include",t[200],path[100];
	char *p; 
	int len,i=0,j=0,ch;
	FILE *fp;
	len=strlen(s);

	while(fgets(m,100,src))
	{
		if(strstr(m,s))
		{
			p=strstr(m,s);
			p=p+len;

			while(*p==' '||*p=='\t')
				p++;

			if(*p=='<')
			{
				p++;
				i=0;
				while(*p!='>')
					t[i++]=*p++;
				t[i]='\0';
				if(*p!='>')
				{
					printf("INVALID HEADER\n");
					return;
				}

				strcpy(path,"/usr/include/");
				strcat(path,t);

				fp=fopen(path,"r");
				{
					if(fp==0)
					{
						printf("FILE IS NOT PRESENT\n");
						return;
					}
				}

				while((ch=fgetc(fp))!=-1)
					fputc(ch,dst);
				fclose(fp);
			}
			else if(*p=='"')
			{
				p++;
				j=0;

				while(*p!='"')
					t[j++]=*p++;
				t[j]='\0';

				if(*p!='"')
				{
					printf("INVALID HEADER\n");
					return;
				}

				fp=fopen(t,"r");
				{
					if(fp==0)
					{
						printf("FILE IS NOT AVAILABLE\n");
						return;
					}
					while((ch=fgetc(fp))!=-1)
						fputc(ch,dst);
					fclose(fp);
				}
			}
		}

		else
		{
			fputs(m,dst);
		}
	}
}

