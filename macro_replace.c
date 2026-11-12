#include<stdio.h>
#include<string.h>

void macro_substitution(FILE *src,FILE *dst)
{
        char m[100],s[100]="#define",macroname[100][100],macrobody[100][100],str[100],formal[100][10][10],actual[10][100];
        char *p; 
        int len=strlen(s),i=0,j=0,c=0,k,n;
        FILE *fp;

        while(fgets(m,100,src))
        {
                if(strncmp(m,s,len)==0)
                {
                        p=m;
                        p=p+len;

                        while(*p==' '||*p=='\t')
                                p++;

                        i=0;
                        while(*p!='(' && *p!=' ' && *p!='\t' &&*p!='\n' && *p!='\0')
                                macroname[c][i++]=*p++;
                        macroname[c][i]='\0';

                        if(*p=='(')
                        {
                                p++;
                                i=0;
                                j=0;
                                while(*p!=')' && *p!='\0')
                                {
                                        if(*p==',')
                                        {
                                                formal[c][i][j]='\0';
                                                i++;
                                                j=0;
                                                p++;

                                        }
                                        else
                                                formal[c][i][j++]=*p++;
                                }
formal[c][i][j]='\0';
                                p++;
                        }

                        else
                                        formal[c][0][0]='\0';


                                while((*p==' ')||(*p=='\t'))
                                        p++;

                                j=0;
                                while((*p!='\n')&&(*p!='\0'))
                                        macrobody[c][j++]=*p++;
                                macrobody[c][j]='\0';

                                c++;

                        }
                }

                rewind(src);

                while(fgets(m,100,src))
                {
                        if(strncmp(m,s,len)==0)
                                continue;

                        p=m;
                        while(*p)
                        {
                                if((*p)>='A'&&(*p)<='Z'||(*p)>='a'&&(*p)<='z'||*p=='_')
                                {
                                        i=0;
                                        while((*p)>='A'&&(*p)<='Z'||(*p)>='a'&&(*p)<='z'||(*p)>='0'&&(*p)<='9'||*p=='_')
                                                str[i++]=*p++;
                                        str[i]='\0';

                                        for(k=0;k<c;k++)
                                        {
                                                if(strcmp(str,macroname[k])==0)
                                                        break;
 }

                                        if(k<c)
                                        {
                                                if(formal[k][0][0]=='\0')
                                                {
                                                        fprintf(dst,"%s",macrobody[k]);
                                                }
                                                else
                                                {
                                                        if(*p=='(')
                                                        {
                                                                p++;
                                                                i=0;
                                                                j=0;

                                                                while(*p!=')' && *p!='\0')
                                                                {
                                                                        if(*p==',')
                                                                        {

                                                                                actual[i][j]='\0';
                                                                                i++;
                                                                                j=0;
                                                                                p++;
                                                                        }
                                                                        else
                                                                                actual[i][j++]=*p++;
                                                                }
                                                                actual[i][j]='\0';

                                                                for(n=0;macrobody[k][n];n++)
                                                                {
                                                                        if(macrobody[k][n]==formal[k][0][0])
                                                                                fprintf(dst,"%s",actual[0]);
                                                                        else if(macrobody[k][n]==formal[k][1][0])
                                                                                fprintf(dst,"%s",actual[1]);
                                                                        else
                                                                                fputc(macrobody[k][n],dst);
                                                                }
                                                                if(*p==')')
                                                                        p++;
                                                        }
                                                        //fprintf(dst,"%s",macrobody[k]);
                                                        else
                                                                fprintf(dst,"%s",str);
                                                }
                                        }
                                        else
                                                fprintf(dst,"%s",str);
                                        //fputc(*p++,dst);
                                }
                                else
                                        fputc(*p++,dst);
                        }
                }
}

