#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rdchar(char *file) //ͳ���ַ��� 
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
		while (!feof(fp))  //feof()��������ļ�������������0��������0δ����
		{
			buf=fgetc(fp); //fgetc()��ȡһ���ֽڣ�������һ���ֽ�
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
	printf("�ַ���:%d ",chsum);
	return 0;
}

int rdword(char *file)//ͳ�Ƶ��ʵĸ���
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
		while(!feof(fp))  //feof()��������ļ�������������0��������0δ����
		{
			buf=fgetc(fp);  //fgetc()��ȡһ���ֽڣ�������һ���ֽ�
			if(buf==' ' || buf==',')
			{
				wdsum++;
			}
		}
	}
	fclose(fp); 
	printf("������:%d ",wdsum);
	return 0;
}


int main(int argc, char* argv[])      //�жϿ��Ʋ���       
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
