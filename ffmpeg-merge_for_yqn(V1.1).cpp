#include<Windows.h>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include <time.h>
using namespace std;
char address[500]="C:\\bilibili\\22310856-ӣǧ��";
char x1[]="ffmpeg -i ";
char x2[]=" -c copy -bsf:v h264_mp4toannexb -f mpegts ";
char x3[]=" -c copy -bsf:a aac_adtstoasc -movflags +faststart ";
char x4[]="\"concat:";
char x5[3000];
char x[5000];
char ts[100][10];
char mp4[100][10];
char temp[100]="flv";
char output[100];//����ļ�����������׺�� 
/*char input[100][10];//�������е��ز��ļ�������׺�� 
char inputx[3000];//��������һά�洢 */
int n;
void init_mpeg(); 
void init_ts();
void init_mp4();
//void init_input();

void format();
int main()
{
	//printf("ʹ����֪��\n\t1.�ز��ļ��뱣����ͬһ�ļ����£����Ʊ����01.xxx,02.xxx,....����\n\t2.Ŀ¼����ΪӢ�����Ʊ�����ܳ��ֵ�bug\n\t3.��������ļ����ᱣ�����ز��ļ����ڵ�Ŀ¼\n");
	//printf("ע������˵����������\n\t1.��һ��ƴ�ӷ�ʽ��Ҫ��Ƶ�ߴ�һ��\n\t2.���ͬ����Ƶ�ϲ�����ܻ����޷�Ԥ��Ľ����\n\t3.������\n\n");
	printf("��N����Ƶ��Ҫ���ϲ���\nN=");
	scanf("%d",&n); 
//	sprintf(address,"F:\\1111111");
	printf("\n"); 
	format();
	printf("\n�زĺϲ���ɣ������Զ��ر�");
	for(int i=0;i<6;++i)
	{
		printf(".");
		Sleep(500);
	}
	return 0;
}
void init_ts()
{
	for(int i=0;i<100;++i)
	{
		ts[i][0]='\\';
		ts[i][1]=(i/10)+'0';
		ts[i][2]=(i%10)+'0';
		ts[i][3]='.';
		ts[i][4]='t';
		ts[i][5]='s';
	}
	return;
}
void init_mp4()
{
	for(int i=0;i<100;++i)
	{
		mp4[i][0]=(i/10)+'0';
		mp4[i][1]=(i%10)+'0';
		mp4[i][2]='.';
		mp4[i][3]=temp[0];
		mp4[i][4]=temp[1];
		mp4[i][5]=temp[2];
	}
	return;
}
void format()
{
		printf("��ʼ���С�����\n"); 
		init_ts();
		init_mp4();
		printf("��ʼ��������\n");
		for(int i=1;i<=n;++i)
		{
			printf("\n���������%d���ز�",i);
			Sleep(500);
			printf(".");
			Sleep(500);
			printf(".\n");
			sprintf(x,"%s%s\\%s%s%s%s",x1,address,mp4[i],x2,address,ts[i]);
			puts(x);
			system(x);
			printf("\n��%d���زĴ���ɹ�\n",i);
		}
		printf("\nȫ���زĴ������\n");
		
		time_t t = time(0);
		strftime( output, sizeof(output), "%Y.%m.%d",localtime(&t) );
		//printf("\n����ļ�����Ϊ(������׺��):");
		//scanf("%s",output);
		int p=0,j;//now position
		for(int i=1;i<=n;++i)
		{
			
			for(j=0;j<strlen(address);++j)
			{
				x5[p+j]=address[j];
			}
			x5[p+j]=ts[i][0];
			x5[p+j+1]=ts[i][1];
			x5[p+j+2]=ts[i][2];
			x5[p+j+3]=ts[i][3];
			x5[p+j+4]=ts[i][4];
			x5[p+j+5]=ts[i][5];
			if(i!=n) x5[p+j+6]='|';
			p+=(7+strlen(address));
		}
		x5[p+j-strlen(address)-1]='\"';
		sprintf(x,"%s%s%s%s%s\\%s.flv",x1,x4,x5,x3,address,output);
		system(x);
	return;
}
