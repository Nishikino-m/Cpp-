#include<bits/stdc++.h>
#include"Pig.h" 
using namespace std;
#define ll long long
ll Time=0;
 
void menu(){
	cout<<"\n\n\n\n\n		==============================================================\n\n";
	cout<<"					养猪模拟系统                        \n\n\n";
	cout<<"					1.开始游戏\n\n";
	cout<<"					2.帮助\n\n";
	cout<<"					3.退出\n\n";
	cout<<"		==============================================================\n\n";
	cout<<"		请键入您的选择：";

}
void openning(){
	system("cls");
	cout<<"\n\n\n\n\n		==============================================================\n\n";
	cout<<"					您的养猪场                        \n\n";
	cout<<"			1.查询信息\n";
	cout<<"			2.重新游戏\n";
	cout<<"			3.保存游戏\n";
	cout<<"			4.下一天			5.下个月\n"; 
	cout<<"			6.退出游戏\n";
	cout<<'\n';
	//cout<<"               当前金币数："<<<"    总猪数："<<allpig<<"   饲养时间:";if(month>0)cout<<month<<"个月";if(day>=0)cout<<day<<"天";
	cout<<"		==============================================================\n\n";
	cout<<"		请键入您的选择：";
}
void startsearch(){
	system("cls");
	cout<<"\n\n\n\n\n		==============================================================\n\n";
	cout<<"				查询			\n\n";
	cout<<"			1.查询当前某一猪圈的猪的数量和种类\n";
	cout<<"			2.查询当前某一猪圈某头猪的状态信息\n";
	cout<<"			3.统计当前猪场每个品种猪的数量和体重、饲养时间分布情况\n";
	cout<<"			4.查询近5年猪的销售记录和猪崽儿的购入记录\n";
	cout<<"			5.打印当前养猪场所有猪的所有信息\n";
	cout<<"			6.返回\n\n";
	cout<<"		==============================================================\n\n";
	cout<<"		请键入您的选择：";
}
void startgame(){
	openning();
	int option;
	cin>>option;
	while(1){
		switch(option){
			case 1:{//查询 
			system("cls");//清屏 
			startsearch();
			break;} 
			case 2: {
			//清空猪圈，所有数据清零 
				break;
			}
			case 3:{
				//保存文件 
				break;
			}
			case 4:{//下一天 
				Time++; 	
				break;
			}
			case 5:{
				Time+=30;//假设一个月均为30天 
				break;
			}
			case 6:{
				exit(0);
			}
			default:{
				cout<<"		请键入您的选择：";
				cin>>option;
				break;
			}
		}

	cin>>option;
	
	}
}
