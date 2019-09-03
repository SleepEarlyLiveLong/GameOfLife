//---------Author:Chen Tianyang  -------//
//---------  Data:2016/8/2  ------------//
//------  Contact:tychen@whu.edu.cn  ---//
//------  Content:Life Game  -----------//

/*
mian.cpp
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include"lifegame.h"

using namespace std;

/**************************** main ********************************/
int main()
{
	int CHOICE = 1,n = 0;
	int choice;
	int map[MAXROW][MAXLIS] = {DEAD},newmap[MAXROW][MAXLIS] = {DEAD};		//����2��ͬά���鲢��ʼ��Ϊȫ0����	
	cout<<"_________________________________________"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|         ��ӭ������������Ϸ����         |"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|  ��ѡ���ʼ��ģʽ��                    |"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|     1.�Զ�ģʽA     2.�Զ�ģʽB        |"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|     3.���ģʽ      4.�ֶ�ģʽ         |"<<endl;
	cout<<"|________________________________________|"<<endl;
	cin>>choice;
	switch(choice)
	{
	case 1:Init1(map);break;               //��ά������Ϊ��������������ʱ�������Ƕ�ά�������ʼλָ�룬Ҳ����������
	case 2:Init2(map);break;
	case 3:Init3(map);break;
	case 4:Init4(map);break;
	default:
		{
			cout<<"Ĭ��Ϊ�����ʼ��ģʽ."<<endl;
			Init3(map);
			break;
		}
	}            
	cout<<endl<<"����ϸ������ͼ��"<<endl;
	ShowMap(map);
	while(CHOICE)
	{
		NextG(map,newmap);
		CopyClc(map,newmap);
		cout<<endl<<"��"<<n++<<"��ϸ������ͼ��"<<endl;
		ShowMap(map);
		cout<<"\n�����밴��0������������ּ�."<<endl;
		cin>>CHOICE;
	}
	cout<<"�����˳���Ϸ."<<endl;
	return 0;
}