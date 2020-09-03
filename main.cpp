#include<bits/stdc++.h>
#include"pigpig.h" 
using namespace std;
double money;//当前财富 
int pigcnt;//总猪猪 
Pighouse ph[105];
ll Time;//游戏时间 单位:天 
void startgame();
void newgames(){
	money=0;
	Time=0; 
	//此处随机生成n只猪猪 种类 体重 饲养时间为0 
};
void clearpig(){
	for(int i=0;i<100;i++){
			ph[i].clear();
	}
	newgames();//游戏初始化 
}
void print_imformation(){
	cout<<"			当前金币数："<<money<<"	总猪数："<<pigcnt<<"	饲养时间: "<<Time<<endl;
}
double sellcount(){//计算本回合卖猪总收入 
	int m;
	for(int i=0;i<100;i++){
		m+=ph[i].sellpig();
	} 
	return m;
}
void newpig(Pig *p){//为新猪分配猪圈
	int flag=0,sp=0;//sp:是否分配到空猪圈 
  	if(p->name==1)//黑猪只能分配到黑猪圈/空猪圈 
		flag=1;
	for(int i=0;i<100;i++){
		if(ph[i].Getpig_num()==0){
			ph[i].buypig(p);
			sp=1; 
			//cout<<"被分配空猪圈："<<i<<endl;
			break;
		}	
	}
	if(sp==0){
		int min_num=20;
		int index=101;
		for(int i=0;i<100;i++){
			if(ph[i].GetisBlack()==flag){
				if(min_num > ph[i].Getpig_num()){
					min_num=ph[i].Getpig_num();
					index=i;
				}
			}
		}
		//cout<<"被分配猪圈："<<index<<endl;
		ph[index].buypig(p);
	}

}
void startsearch(){
	searching();
	int option;
	cin>>option;
	while(1){
		switch(option){
			case 1:{
				print_imformation();
				break;
			} 
			case 2:{//查询当前某一猪圈的猪的数量和种类
				break;
			} 
			case 3: {//查询当前某一猪圈某头猪的状态信息；
				break;
			}
			case 4:{//统计当前猪场每个品种猪的数量和体重、饲养时间分布情况；
				break;
			}
			case 5:{//查询近5年猪的销售记录和猪崽儿的购入记录	
				break;
			}
			case 6:{	//打印当前养猪场所有猪的所有信息
				break;
			}
			case 7:{//返回 
				startgame();
			}
			default:{
				cout<<"		请键入您的选择：";
				cin>>option;
				break;
			}
		}
	cout<<"		请键入您的选择：";
	cin>>option;
	}
}
void startgame(){
	openning();
	int option;
	cin>>option;
	while(1){
		switch(option){
			case 1:{//查询 
				system("cls");//清屏 
				startsearch();//进入查询
				break;
			} 
			case 2: {	//清空猪圈，所有数据清零
				clearpig();
				break;
			}
			case 3:{	//保存文件 
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
		if(option!=1){
			system("cls"); 
			openning();
		}
		else cout<<"		请键入您的选择：";
	cin>>option;
	}
}
int main(){
	menu();
	int option;
	cin>>option;
	while(1){

		switch(option){
			case 1:{
			system("cls");//清屏 此处应是一个游戏的函数 
			newgames();
			startgame();
			break;} 
			case 2: {
				system("cls");
				cout<<"\n\n\n\n\n		=========================帮助===========================\n\n";
				cout<<"		请键入您的选择：";
				break;
			}
			case 3:{
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
