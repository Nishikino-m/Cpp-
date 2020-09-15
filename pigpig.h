#include<bits/stdc++.h>
//#include"Pig.h" 
using namespace std;
#define ll long long

void menu(){
	cout<<"\n\n\n\n\n		==============================================================\n\n";
	cout<<"					养猪模拟系统                        \n\n\n";
	cout<<"					1.开始游戏\n\n";
	cout<<"					2.继续游戏\n\n";
	cout<<"					3.帮助\n\n";
	cout<<"					4.退出\n\n";
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
	cout<<"			7.模拟猪瘟\n";
	cout<<"			8.返回主菜单\n";
	cout<<'\n';
	cout<<"		==============================================================\n\n";
	cout<<"		请键入您的选择：";
}
void searching(){
	system("cls");
	cout<<"\n\n\n\n\n		=================================================================\n\n";
	cout<<"					查询			\n\n";
	cout<<"			1.查询当前财富（金币数、猪猪数、总饲养时间）\n";
	cout<<"			2.查询当前某一猪圈的猪的数量和种类\n";
	cout<<"			3.查询当前某一猪圈某头猪的状态信息\n";
	cout<<"			4.统计当前某一猪圈所拥有的每个品种猪的数量和体重、饲养时间分布情况\n";
	cout<<"			5.查询近5年猪的销售记录和猪崽儿的购入记录\n";
	cout<<"			6.打印当前某一猪圈所有猪的所有信息\n";
	cout<<"			7.返回\n\n";
	cout<<"		=================================================================\n\n";
	cout<<"		请键入您的选择(查询)：";
}
void Help(){
	cout<<"\n\n\n\n\n		=========================帮助===========================\n\n";
	cout<<"		    这个游戏设定一年只有360天，每三个月（90天）有\n";
	cout<<"		    一批符合要求的猪猪会出栏，同时会有新的猪崽进入\n";
	cout<<"		    出栏要求：饲养超过一年（360天）或体重大于150斤\n";
	cout<<"		    猪猪价格设定：\n";
	cout<<"		        黑猪： 猪仔 500 元/只 | 成猪 15 元/斤 \n";
	cout<<"		      小花猪： 猪仔 100 元/只 | 成猪  7 元/斤 \n";
	cout<<"		    大花白猪： 猪仔 50  元/只 | 成猪  6 元/斤 \n";
	cout<<"\n\n		    按回车键返回主菜单\n";
	getchar();
	if(getchar()){
	system("cls");
	menu();
	}
	
}
void Simulated_Help(){
	system("cls");
	cout<<"\n\n\n\n\n		=======================模拟猪瘟系统=========================\n\n";
	cout<<"		    现在随机使一只猪患病，猪瘟的扩展几率是：\n";
	cout<<"		    同一个猪圈的猪每天被传染几率是50%\n";
	cout<<"		    相邻猪圈的猪每天被传染的几率是15%\n";
	cout<<"		    不相邻的猪圈的猪不传染\n";
	cout<<"		    ===========================================================";
	cout<<"\n\n		    按回车键开始模拟\n";
	getchar();
	if(getchar()){
	system("cls");
	}
} 
