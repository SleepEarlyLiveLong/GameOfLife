//---------Author:Chen Tianyang  -------//
//---------  Data:2016/8/2  ------------//
//------  Contact:tychen@whu.edu.cn  ---//
//------  Content:Life Game  -----------//

/*
lifegame.cpp
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"lifegame.h"

using namespace std;

///////////////////////// Function Definitions /////////////////////////

/************************** �Զ�ģʽA���� ******************************/
//�������漰����Ԫ�ط�������⣬�ڻ�ͼ
void Init1(int p[][MAXLIS])
{
	int i,j;
	for(i = 0;i<MAXROW;i++)      //����i,j�Ĳ�����ȷ��i<MAXROW�Ϳ��Ա�֤��Խ��
	{
		for(j = 0;j<MAXLIS/2;j+=2)      
		{
			p[i][j] = ALIVE;
		}
	}
	for(i = 0;i<MAXROW;i+=2)
	{
		for(j = MAXLIS/2;j<MAXLIS;j++)
		{
			p[i][j] = ALIVE;
		}
	}
}

/************************** �Զ�ģʽB���� ******************************/
void Init2(int p[][MAXLIS])
{
	for(int i = 0;i<MAXROW;i+=2)      
	{
		for(int j = 0;j<MAXLIS;j+=2)
		{
			p[i][j] = ALIVE;
		}
	}
	for(int i = 1;i<MAXROW;i+=2)
	{
		for(int j = 1;j<MAXLIS-1;j+=2)
		{
			p[i][j] = ALIVE;
		}
	}
}

/************************** ���ģʽ���� ******************************/
void Init3(int p[][MAXLIS])
{
	srand(time(NULL));          //��ʱ��Ϊ���ӣ�ÿ�����ɲ�ͬ����
	for(int i = 0;i<MAXROW;i++)           
	{
		for(int j = 0;j<MAXLIS;j++)            
		{
			p[i][j] = rand()%2;       //��[0,1]֮����������
		}
	}
}

/************************** �ֶ�ģʽ���� ******************************/
void Init4(int p[][MAXLIS])
{
	int x,y;
	while(1)
	{
		cout<<"���������ϸ�����С�������(1<=x<="<<MAXROW<<" �� 1<=y<="<<MAXLIS<<",��x��yȫ��Ϊ0�����˳�):"<<endl;
		cin>>x>>y;
		if(x>=1 && x<=MAXROW && y>=1 && y<=MAXLIS)
		{
			p[x-1][y-1] = ALIVE;
			cout<<"���Ѹ���ϸ��["<<x<<','<<y<<"]Ϊ������."<<endl;	
		}
		else if((x==0) && (y==0))
		{
			cout<<"���Ѿ���ɳ�ʼ��."<<endl;
			break;
		}
		else 
		{
			cout<<"������������������������:"<<endl;
			continue;
		}
	}
}

/*************************** ��ʾ����� *******************************/
void ShowMap(int p[][MAXLIS])
{
	int i,j;
	for(i = 0;i<MAXROW;i++)
	{
		cout<<endl<<"\t";
		for(j = 0;j<MAXLIS;j++)
		{
			if(p[i][j] == ALIVE)
				cout<<'#'<<" ";
			else
				cout<<'-'<<" ";
		}
	}
}

/*************************** ������һ������ *******************************/
void NextG(int p[][MAXLIS],int q[][MAXLIS])               
{
	int i,j,x,y;
	int judge;
	for(i = 0;i < MAXROW;i++)
	{
		for(j = 0;j < MAXLIS;j++)
		{
			if(p[i][j] == ALIVE)
			{
				judge = -1;                         //ÿһ�ֽ���judge��Ҫ��λ
			}
			else if(p[i][j] == DEAD)
			{
				judge = 0;
			}
			for(x = MAX(i-1,0);x<=MIN(i+1,MAXROW-1);x++)     //��ʼ�����MAXROW��MAXLIS��������-1���߼��������˺þ�
			{
				for(y = MAX(j-1,0);y<=MIN(j+1,MAXLIS-1);y++)
				{
					if(p[x][y] == ALIVE)
						judge +=1;
				}
			}
			switch(judge)
			{
			case 2:q[i][j] = p[i][j];break;			// ��Χ��2����ϸ��������ԭ��
			case 3:q[i][j] = ALIVE;break;			// ��Χ��3����ϸ����������������򸴻�(ģ�ֳⷱ)
			default:q[i][j] = DEAD;break;			// ��Χ��1��4-8����ϸ������(ģ��ӵ��������¶�����)
			}
		}
	}
}

/*************************** �������㺯�� *******************************/
void CopyClc(int p[][MAXLIS],int q[][MAXLIS])
{
	int i,j;
	for(i = 0;i<MAXROW;i++)
	{
		for(j = 0;j<MAXLIS;j++)
		{
			p[i][j] = q[i][j];
			q[i][j] = DEAD;
		}
	}
}

/************************** ��ֵ���� **********************************/
//���ֵ
int MAX(int a,int b)
{
	return (a>=b)?a:b;
}

//��Сֵ
int MIN(int a,int b)
{
	return (a<=b)?a:b;
}