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
void Init4(int p[][MAXLIS]);			//��ʼ����������ά������Ϊ�����������ݣ�����ʡ������
void ShowMap(int p[][MAXLIS]);			//��ʾϸ������ֲ��ĺ���
void NextG(int p[][MAXLIS],int q[][MAXLIS]);			//������һ��
void CopyClc(int p[][MAXLIS],int q[][MAXLIS]);          //newmap����map,����newmap����
int MAX(int a,int b); 
int MIN(int a,int b); 

#endif