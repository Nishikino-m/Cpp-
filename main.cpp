
#include<bits/stdc++.h>
#include<windows.h>
#include"pigpig.h"
#include"classp.h" 
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
void Outpig();
void Getpig();
void start_byfile();
void save_file();
void save_sell(int t,double x);
void save_buy(int t,int x);
void search_file();
void search_buy();
double submoney(int name,double weight);
int opt,numm;
int change(string a){
	int len=a.size();
//	int ss=1;
	int ans=0;
	for(int i=len-1;i>=0;i--){
		if(a[i]>'9'||a[i]<'0'){
			return 404;
		}
		ans*=10;
		ans+=a[i]-'0';
	}
	return ans;
}
void startsearch(){
	searching();
	string option;
	cin>>option;
		opt=change(option);
	while(1){
		switch(opt){
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
				search_file();	
				search_buy();
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
//				cout<<"		请键入您的选择：";
				cout<<"		ERROR! 此选项不存在\n";
//				cin>>option;
//				opt=change(option);
				break;
			}
		}
	cout<<"		请键入您的选择(查询)：";
	cin>>option;
	opt=change(option);
	}
}

void startgame(){
	openning();
	string option;
	cin>>option;
	opt=change(option);
	while(1){
		switch(opt){
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
				save_file();
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
//				cout<<"		请键入您的选择：";
//				cin>>option;
//					opt=change(option);
				break;
			}
		}
		if(opt!=1){
			system("cls"); 
			openning();//包含请输入选择了 
			cin>>option;
			opt=change(option);
		}
	
	}
}

int main(){
	menu();
	string option;
	cin>>option;
	opt=change(option);
	while(1){
	//	cout<<"opt="<<opt;
		switch(opt){
			case 1:{
			system("cls");//清屏 此处应是一个游戏的函数 
			newgames();
			startgame();
			break;} 
			case 2: {
				start_byfile();
				startgame();
				break;
			}
			case 3: {
				system("cls");
				Help();
				break;
			}
			case 4:{
				exit(0);
			}
			default:{
//				cout<<"		请键入您的选择：";
//				cin>>option;
//				opt=change(option);
				break;
			}
		}
	cout<<"		请键入您的选择：";
	cin>>option;
	opt=change(option);
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
			ph[i].addpig(p);
			sp=1; 
			cout<<"分配到空猪圈："<<i<<endl;
			break;
		}	
	}
	if(sp==0){//分配到非空猪圈 
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
		if(flag==1)	cout<<"被分配到黑猪圈："<<index<<endl;
		else cout<<"被分配到猪圈："<<index<<endl;
		if(index>99) {
		cout<<"ERROR! 猪圈满了" ;
		//Sleep(10000);
		return;} 
		ph[index].addpig(p);
		
		
	}
}
void update(){
	Time_l++; 
	if(Time_l==90){
		Outpig();//出栏 
		Getpig();//进猪 
		Time_l=0;
	} 
	//此处应随机生成一个体重 每日更新 
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
	ofstream file;
	file.open("Record.txt",ios::trunc);
	file.close();
	file.open("RRRRecord.txt",ios::trunc);
	file.close();
	ofstream per;
	per.open("Player.txt",ios::trunc);
	per.close();
	ofstream saved;
	saved.open("Gamedata.txt",ios::trunc);
	saved.close();
	srand((unsigned)time(NULL));
	pigcnt=rand()%200+1;
	int num=pigcnt;
	Pig*p;
	while(num--){
		p=new Pig;
		p->name=rand()%3+1;
		p->weight=rand()%61+40;//随机初始化20-50公斤  
		p->fed_time=0;
		newpig(p);
		
	} 
	//Sleep(10000); 
	//此处随机生成n只猪猪 种类 体重 饲养时间为0 
};
void search_pighouse(){
	string num;
	cout<<"			请输入要查询的猪圈编号：";
	cin>>num;
	numm=change(num);
	while(1){
		if(numm>=0&&numm<100){
			ph[numm].printmessage();
			break;
		}
		cout<<"\n			请输入要查询的猪圈编号：";
	cin>>num;
	numm=change(num);
		
	}
	
	
}
void search_pighouse_pig(){
	string num1,num2;
	cout<<"			请输入要查询的猪圈编号：";
	cin>>num1;
	int num11=change(num1);
	while(1){
		if(num11>=0&&num11<100&&ph[num11].Getpig_num()>0)	break;//合法非空猪圈号 
		else cout<<"			此猪圈为空或不存在，请重新输入：";
		cin>>num1;
		num11=change(num1);
	}
	cout<<"			此猪圈共有"<<ph[num11].Getpig_num()<<"头猪,请输入要查询的猪猪编号：";
	cin>>num2;
	int num22=change(num2);
	while(1){
		if(num22<(ph[num11].Getpig_num())&&num22>=0)
			break;
		else{
			cout<<"			此猪不存在，请重新输入：";
		cin>>num2;
		num22=change(num2);
		}
	}
	ph[num11].searchpig(num22);
}
void search_message(){
	string num;
	numm=change(num);
	while(1){
		cout<<"			请输入要查询的猪圈编号：";
		cin>>num;
	numm=change(num);
		if(numm>=100) cout<<"			ERROR!猪圈编号需要小于100\n";
		else {
			ph[numm].search();
			break;
		}
	}
	
}
void search_all(){
	string num;
	while(1){
		cout<<"			请输入要查询的猪圈编号：";
		cin>>num;
		numm=change(num);
		if(numm>=100) cout<<"			ERROR!猪圈编号需要小于100\n";
		else {
			ph[numm].print_all();
			break;
		}
	}
}

double sellcount(){//计算本回合卖猪总收入   
	double m=0;
	ofstream file;
	file.open("Record.txt",ios::app);
	int qqq=0;
	for(int i=0;i<100;i++){
		int pre=ph[i].Getpig_num();
		double a=ph[i].sellpig(file);
		if(a){
			m+=a;		
		}	
		int now=ph[i].Getpig_num();
		int cot=pre-now;
		qqq+=cot;
		cout<<"本猪圈售出"<<cot<<"只猪猪\n";
	}
	
//	file<<"本次一共售出"<<qqq<<"只猪猪\n";
	file.close();
	pigcnt-=qqq; 
	//Sleep(1005);
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
void start_byfile(){
	ifstream getim;//读取玩家信息 
	getim.open("Player.txt");
	if(!getim){
		cout<<"			ERROR:读取数据失败！\n";
		exit(0);
	}
	getim>>pigcnt>>money>>Time>>Time_l; 
	cout<<"			读取玩家信息成功！\n";
	getim.close();
	
	ifstream read;
	read.open("Gamedata.txt");
	if(!read){
		cout<<"			ERROR:读取数据失败！\n";
			exit(0);
	}
	int pign;
	Pig*p;
	for(int i=0;i<100;i++){
		read>>pign;
		for(int j=0;j<pign;j++){
			p=new Pig;
			read>>p->name;
			if(p->name==0){
				delete p;
				break;
			}
			else read>>p->weight>>p->fed_time;
			p->countp();
			ph[i].addpig(p);
		//cout<<p->name<<" "<<p->weight<<" "<<p->fed_time<<endl;
		}	
	}
	read.close();
	cout<<"			读取猪圈数据成功！"<<endl;
	Sleep(200); 
}
void save_file(){
	ofstream saved;
	saved.open("Player.txt");
	saved<<pigcnt<<"	"<<money<<"	"<<Time<<"	"<<Time_l; 
	cout<<"			保存玩家信息成功！"<<endl;
	saved.close();
	ofstream saveg;
	saveg.open("Gamedata.txt");
//	cout<<"打开文件成功\n";Sleep(500);
	for(int i=0;i<100;i++){
		ph[i].save(saveg);
	}
	cout<<"			保存猪猪信息成功！"<<endl;	
	//Sleep(105);
	saveg.close();
}
void Outpig(){
	double sale_v=sellcount(); 
//	cout<<"本次售出"<<sale_v<<"元"<<endl; 
	money+=sale_v;
//	Sleep(1000);
	save_sell(Time,sale_v);//保存总出售记录//时间、 总收入 
}
void Getpig(){
	srand((unsigned)time(NULL));
	int num=rand()%200+1;
	cout<<"新入栏"<<num<<"只猪\n";
	
	pigcnt+=num;
	int prenum=num;
	Pig*p;
	double pric=0.0;
	while(num--){
		p=new Pig;
		p->name=rand()%3+1;
		p->weight=rand()%100+40;//随机初始化20-50公斤  
		p->fed_time=-1;
		p->countp(); 
		pric=submoney(p->name,p->weight);
		if(money-pric<=0){
			cout<<"num="<<num<<endl;
			Sleep(1000);
			pigcnt-=num;
			save_buy(Time,(prenum-num));
			return;
		}
		money-=pric;
		newpig(p);
		
	}
	save_buy(Time,prenum);
//	 Sleep(1000);
}
void save_sell(int t,double x){
	ofstream file;
	file.open("Record.txt",ios::app);
	file<<t<<"	"<<x<<"	"<<endl; 
	file.close();
} 
void search_file(){
	ifstream pre_file;//源文件 
	pre_file.open("Record.txt");
	if(!pre_file){
		cout<<"			打开出圈信息文件失败\n";
		exit(0);
	} 
	int tmp=1;
	double coin=0;
	int temp=17;
	pre_file>>tmp;
	if(tmp==1){
		cout<<"		尚未经历出圈！请选择其它\n";
		return;
	}
	while(1){
		pre_file>>coin;
		if(tmp>(Time-1800))
			cout<<"			饲养时间: "<<tmp<<"天，获得销售额"<<coin<<"元\n";
			temp=tmp;
	
		pre_file>>tmp;//	cout<<"Temp="<<temp<<"	Tmp="<<temp<<endl;
		if(temp==tmp) break;
	}	
	pre_file.close(); 
}
void save_buy(int t ,int x){
	ofstream file;
	file.open("Buy_Record.txt",ios::app);
	file<<t<<"	"<<x<<"	"<<endl; 
	file.close();
} 

void search_buy(){
	ifstream pre_file;//源文件 
	pre_file.open("Buy_Record.txt");
	if(!pre_file){
		cout<<"			打开购猪信息文件失败\n";
		exit(0);
	} 
	int tmp=1;
	int buynum=0;
	int temp=17;
	pre_file>>tmp;
	if(tmp==1){
		cout<<"		尚未经历购猪崽崽！请选择其它\n";
		return;
	}
	while(1){
		pre_file>>buynum;
		if(tmp>(Time-1800))
			cout<<"			饲养时间: "<<tmp<<"天，购入猪猪"<<buynum<<"只\n";
			temp=tmp;
	
		pre_file>>tmp;//	cout<<"Temp="<<temp<<"	Tmp="<<temp<<endl;
		if(temp==tmp) break;
	}	
	pre_file.close(); 
	
}

double submoney(int name,double weight){
	double pri=0.0;
	if(name==1){
		pri=(10*weight);
	}
	else if(name==2){
		pri=(2*weight);
	}
	else if(name==3){
		pri=(1*weight);
	}
	return pri;

}
