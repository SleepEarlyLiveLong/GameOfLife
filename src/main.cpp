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
	int map[MAXROW][MAXLIS] = {DEAD},newmap[MAXROW][MAXLIS] = {DEAD};		//定义2个同维数组并初始化为全0数组	
	cout<<"_________________________________________"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|         欢迎来到“生命游戏”！         |"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|  请选择初始化模式：                    |"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|     1.自动模式A     2.自动模式B        |"<<endl;
	cout<<"|                                        |"<<endl;
	cout<<"|     3.随机模式      4.手动模式         |"<<endl;
	cout<<"|________________________________________|"<<endl;
	cin>>choice;
	switch(choice)
	{
	case 1:Init1(map);break;               //二维数组作为函数参数被调用时，参数是二维数组的起始位指针，也就是数组名
	case 2:Init2(map);break;
	case 3:Init3(map);break;
	case 4:Init4(map);break;
	default:
		{
			cout<<"默认为随机初始化模式."<<endl;
			Init3(map);
			break;
		}
	}            
	cout<<endl<<"父代细胞生存图："<<endl;
	ShowMap(map);
	while(CHOICE)
	{
		NextG(map,newmap);
		CopyClc(map,newmap);
		cout<<endl<<"子"<<n++<<"代细胞生存图："<<endl;
		ShowMap(map);
		cout<<"\n继续请按除0以外的任意数字键."<<endl;
		cin>>CHOICE;
	}
	cout<<"您已退出游戏."<<endl;
	return 0;
}