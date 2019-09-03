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

/************************** 自动模式A函数 ******************************/
//像这种涉及数组元素分配的问题，勤画图
void Init1(int p[][MAXLIS])
{
	int i,j;
	for(i = 0;i<MAXROW;i++)      //不论i,j的步长，确保i<MAXROW就可以保证不越界
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

/************************** 自动模式B函数 ******************************/
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

/************************** 随机模式函数 ******************************/
void Init3(int p[][MAXLIS])
{
	srand(time(NULL));          //以时间为种子，每次生成不同的数
	for(int i = 0;i<MAXROW;i++)           
	{
		for(int j = 0;j<MAXLIS;j++)            
		{
			p[i][j] = rand()%2;       //赋[0,1]之间的随机整数
		}
	}
}

/************************** 手动模式函数 ******************************/
void Init4(int p[][MAXLIS])
{
	int x,y;
	while(1)
	{
		cout<<"依次输入活细胞的行、列坐标(1<=x<="<<MAXROW<<" 且 1<=y<="<<MAXLIS<<",若x、y全部为0，则退出):"<<endl;
		cin>>x>>y;
		if(x>=1 && x<=MAXROW && y>=1 && y<=MAXLIS)
		{
			p[x-1][y-1] = ALIVE;
			cout<<"您已赋予细胞["<<x<<','<<y<<"]为“生”."<<endl;	
		}
		else if((x==0) && (y==0))
		{
			cout<<"您已经完成初始化."<<endl;
			break;
		}
		else 
		{
			cout<<"您输入的坐标错误！请重新输入:"<<endl;
			continue;
		}
	}
}

/*************************** 显示死活函数 *******************************/
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

/*************************** 计算下一代函数 *******************************/
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
				judge = -1;                         //每一轮结束judge都要复位
			}
			else if(p[i][j] == DEAD)
			{
				judge = 0;
			}
			for(x = MAX(i-1,0);x<=MIN(i+1,MAXROW-1);x++)     //开始这里的MAXROW和MAXLIS后面忘记-1，逻辑出错找了好久
			{
				for(y = MAX(j-1,0);y<=MIN(j+1,MAXLIS-1);y++)
				{
					if(p[x][y] == ALIVE)
						judge +=1;
				}
			}
			switch(judge)
			{
			case 2:q[i][j] = p[i][j];break;			// 周围有2个活细胞，保持原样
			case 3:q[i][j] = ALIVE;break;			// 周围有3个活细胞，生则继续，死则复活(模拟繁殖)
			default:q[i][j] = DEAD;break;			// 周围有1或4-8个活细胞，死(模拟拥挤而死或孤独而死)
			}
		}
	}
}

/*************************** 拷贝清零函数 *******************************/
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

/************************** 最值函数 **********************************/
//最大值
int MAX(int a,int b)
{
	return (a>=b)?a:b;
}

//最小值
int MIN(int a,int b)
{
	return (a<=b)?a:b;
}