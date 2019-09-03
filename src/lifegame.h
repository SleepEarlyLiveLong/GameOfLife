//---------Author:Chen Tianyang  -------//
//---------  Data:2016/8/2  ------------//
//------  Contact:tychen@whu.edu.cn  ---//
//------  Content:Life Game  -----------//

/*
	lifegame.h
*/

#ifndef __LIFEGAME_H__
#define __LIFEGAME_H__

#define MAXROW 20
#define MAXLIS 20
#define DEAD 0
#define ALIVE 1

void Init1(int p[][MAXLIS]);
void Init2(int p[][MAXLIS]);
void Init3(int p[][MAXLIS]);
void Init4(int p[][MAXLIS]);			//初始化函数，二维数组作为函数参数传递，不可省略列数
void ShowMap(int p[][MAXLIS]);			//显示细胞死活分布的函数
void NextG(int p[][MAXLIS],int q[][MAXLIS]);			//计算下一代
void CopyClc(int p[][MAXLIS],int q[][MAXLIS]);          //newmap拷贝map,并将newmap清零
int MAX(int a,int b); 
int MIN(int a,int b); 

#endif