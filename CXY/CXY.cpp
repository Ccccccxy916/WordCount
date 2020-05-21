#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rdchar(char *file) //统计字符数 
{ 	
	char buf;
	int chsum=0;
	FILE* fp;
	if((fp=fopen(file,"r")) == NULL)
	{
		printf(" No file content \n");
	}
    else
	{
		while (!feof(fp))  //feof()检测流上文件结束符；返回0结束；非0未结束
		{
			buf=fgetc(fp); //fgetc()读取一个字节，光标后移一个字节
			if((buf >='a' && buf <='z')||(buf >='A' && buf <='Z'))
			{
				chsum++;
			}
			else if(buf==' ' || buf=='\n' || buf=='\t')
			{
				chsum++;
			}
			
		}
	}
	fclose(fp);
	printf("字符数:%d ",chsum);
	return 0;
}

int rdword(char *file)//统计单词的个数
{   
	char buf;
	int wdsum=0;
	FILE* fp;
	if((fp=fopen(file,"r")) == NULL)
	{
		printf(" No file content \n");
	}
    else
	{
		while(!feof(fp))  //feof()检测流上文件结束符；返回0结束；非0未结束
		{
			buf=fgetc(fp);  //fgetc()读取一个字节，光标后移一个字节
			if(buf==' ' || buf==',')
			{
				wdsum++;
			}
		}
	}
	fclose(fp); 
	printf("单词数:%d ",wdsum);
	return 0;
}


int main(int argc, char* argv[])      //判断控制参数       
{
	if(strcmp(argv[1],"-w")==0) 
	{
		rdword(argv[2]);   
	}
	else if(strcmp(argv[1],"-c")==0) 
	{
		rdchar(argv[2]);  
	}
	else
	{
		printf("Input error");
	}
	return 0;
}
