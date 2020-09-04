#include<bits/stdc++.h>
#include"pigpig.h" 
using namespace std;
double money;//当前财富 
int pigcnt;//总猪猪 
Pighouse ph[105];
int Time;//游戏时间 单位:天 
int Time_l;//记录两次出栏中间的间隔时间 ==90时出栏并置0 
void newpig(Pig *p);
void newgames();
void print_Time(int x);
void startgame();
void update();
void update_m();
void regame();
void print_imformation();
void search_pighouse();
void search_pighouse_pig();
void search_message();
void search_all();
double sellcount();
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
				search_pighouse();
				break;
			} 
			case 3: {//查询当前某一猪圈某头猪的状态信息；
				search_pighouse_pig();
				break;
			}
			case 4:{//统计当前猪场每个品种猪的数量和体重、饲养时间分布情况；
				search_message();
				break;
			}
			case 5:{//查询近5年猪的销售记录和猪崽儿的购入记录(文件)	
				break;
			}
			case 6:{	//打印当前养猪场所有猪的所有信息
				search_all();
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
				regame();
				break;
			}
			case 3:{	//保存文件 
				break;
			}
			case 4:{//下一天 
				Time++; 	
				update();//更新猪圈信息 
				break;
			}
			case 5:{
				Time+=30;//假设一个月均为30天 
				update_m();//更新猪圈信息 
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
				Help();
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
void print_Time(int x){//打印时间 
	int y=0,m=0,d=0;	
	y=x/360;//年
	x%=360;
	m=x/30;
	x%=30;
	d=x; 
	printf("您已经饲养%2d年%2d月%2d天\n",y,m,d);
} 
void newpig(Pig *p){//为新猪分配猪圈
	int flag=0,sp=0;//sp:是否分配到空猪圈 
  	if(p->name==1)//黑猪只能分配到黑猪圈/空猪圈 
		flag=1;
	for(int i=0;i<100;i++){
		if(ph[i].Getpig_num()==0){
			ph[i].buypig(p);
			sp=1; 
			cout<<"分配到空猪圈："<<i<<endl;
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
		cout<<"被分配到猪圈："<<index<<endl;
		ph[index].buypig(p);
	}

}
void update(){
	if(Time_l==90){
	//	Outpig();//出栏 
	//	Getpig();//进猪 
		Time_l=0;
	} 
	//此处应随机生成一个体重
	 for(int i=0;i<100;i++){
		ph[i].pupdate();
	} 
	 
}
void update_m(){
	for(int i=0;i<30;i++){
		update();
	}
}
void newgames(){//初始化 
	money=0;
	Time=0; 
	Time_l=0;
	srand((unsigned)time(NULL));
	pigcnt=rand()%200+1;
	int num=pigcnt;
	Pig*p;
	while(num--){
		p=new Pig;
		p->name=rand()%3+1;
		p->weight=rand()%100+40;//随机初始化20-50公斤  
		p->fed_time=0;
		newpig(p);
	} 
	//此处随机生成n只猪猪 种类 体重 饲养时间为0 
};
void search_pighouse(){
	int num;
	cout<<"			请输入要查询的猪圈编号：";
	cin>>num;
	ph[num].printmessage();
}
void search_pighouse_pig(){
	int num1,num2;
	cout<<"			请输入要查询的猪圈编号：";
	cin>>num1;
	while(1){
		if(num1>=0&&num1<100&&ph[num1].Getpig_num())	break;//合法非空猪圈号 
		else cout<<"			此猪圈为空，请重新输入：";
		cin>>num1;
	}
	cout<<"			此猪圈共有"<<ph[num1].Getpig_num()<<"头猪,请输入要查询的猪猪编号：";
	cin>>num2;
	while(1){
		if(num2<=(ph[num1].Getpig_num())&&num2>=0)
			break;
		else{
			cout<<"			此猪不存在，请重新输入：";
		cin>>num2;
		}
	}
	ph[num1].searchpig(num2);
}
void search_message(){
	int num;
	cout<<"			请输入要查询的猪圈编号：";
	cin>>num;
	ph[num].search();
}
void search_all(){
	int num;
	cout<<"			请输入要查询的猪圈编号：";
	cin>>num;
	ph[num].print_all();
}
double sellcount(){//计算本回合卖猪总收入 
	int m;
	for(int i=0;i<100;i++){
		m+=ph[i].sellpig();
	} 
	return m;
}
void regame(){//重新开始游戏 
	for(int i=0;i<100;i++){
			ph[i].clear();
	}
	newgames();//游戏初始化 
}
void print_imformation(){//打印玩家信息 
	cout<<"			当前金币数："<<money<<"	总猪数："<<pigcnt<<"	饲养时间: ";
	print_Time(Time);
}
