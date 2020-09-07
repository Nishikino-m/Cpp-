#include<bits/stdc++.h>
using namespace std;
struct Pig{
	int name;//种类:  1-黑猪  2-小花猪  3-大花白猪
	double weight;//体重 单位:斤 
	int value;//猪价单价：黑猪-15 小花猪-7 大花白猪-6 
	double price;//猪总价 
	int fed_time;//饲养时间 
	int id;//猪在猪圈里的编号 
	Pig* next;//同一个猪圈的下一头猪 
	Pig (){
	};
	Pig (int a,double w) : name(a) , weight(w){
		if(name==1) value=15;
		else if(name==2) value=7;
		else value=6;
		
		return;
	}
	void countp(){
		price=weight*value;
	}
	void growth(){
		
	}
};
//
class Pighouse{
private:
	int pig_num;//猪圈中猪的数量
	Pig *head;
	bool isBlack;
public:
	Pighouse();//默认构造函数
//	void Setpig(int a,double b);//输入初始猪圈信息 
	int Getpig_num();
	int GetisBlack();
	void printmessage();//输出猪圈信息：猪的种类＆数量
	void Setids();//每次卖出后，重置猪的编号 
	void buypig(Pig* p);//买进一只猪
	double sellpig(ofstream&file);//卖掉能卖的猪同时计算本次卖猪的收入 ,并保存记录 
	int search(int i);//计算种类为i的猪的数量 
	void search1();//统计黑猪猪的数量和体重、饲养时间分布情况
	void search2();//统计小花猪的数量和体重、饲养时间分布情况
	void search3();//统计大花白猪的数量和体重、饲养时间分布情况
	void searchpig(int x);
	void search();//统计当前猪场每个品种猪的数量和体重、饲养时间分布情况
	void clear();//清空当前猪圈 
	void pupdate(); //更新猪猪信息 
	void print_all();//打印所有猪猪所有信息 
	void save(ofstream&savefile);               
};

Pighouse::Pighouse(){// 默认构造函数
	pig_num=0;
	head=NULL;
	isBlack=0;
}
int Pighouse::Getpig_num(){
	return pig_num;
}
int Pighouse::GetisBlack(){
	return isBlack;
}
void Pighouse::printmessage(){//输出猪圈信息：猪的种类＆数量
	int c1=0,c2=0,c3=0;
	Pig*p1=head;
	for(;p1!=NULL;p1=p1->next){
		if(p1->name==1) c1++;
		if(p1->name==2) c2++;
		if(p1->name==3) c3++;
	}
	if(c1!=0){
		cout<<"这个猪圈有"<<c1<<"头黑猪。\n";
		return;
	}
	if(c2||c3){
		cout<<"这个猪圈有"<<c2<<"头小花猪以及"<<c3<<"头大花白猪。\n" ;
	}
	else{
		cout<<"这是一个空猪圈。\n";
	}
}
void Pighouse::Setids(){//每次卖出后，重置猪的编号 
	Pig *p1=head;
	int id=0;
	for(;p1!=NULL;p1=p1->next){
		p1->id=id;
		id++;	
	}
	if(id==0) isBlack=0;//没猪了 
}
void Pighouse::buypig(Pig *p){//买进一只猪
	pig_num++;
	p->next=NULL;
	if(head==NULL){//第一头猪 
		head=p; 
		if(p->name==1) isBlack=1;
		
	}
	else{
		Pig *p1=head;
		while(p1->next){
		p1=p1->next;
		}
		p1->next=p;
	}
	p->id=pig_num;
}
double Pighouse::sellpig(ofstream&file){//卖掉能卖的猪 同时计算本次卖猪的收入 
	Pig *p1=head;
	Pig *p2=head;//pre
	double pricecnt=0;
	for(;p1!=NULL;p1=p1->next,p2=p1){
		if(p1->fed_time>360||p1->weight>150){//可以售出 
			pig_num--;
			p2->next=p1->next;
		//	cout<<"(p1->price)"<<(p1->price); 
			file<<"售出一只";
			if(p1->name==1) file<<"黑猪,";
			else if(p1->name==2) file<<"小花猪,";
			else file<<"大花白猪,";
			file<<",售价为"<<(p1->price)<<"\n";
			pricecnt+=(p1->price);	
		}
	}
	Setids();
	return pricecnt;
}
int Pighouse::search(int i){//计算种类为i的猪的数量 
	int c=0;
	Pig*p1=head;
	for(;p1!=NULL;p1=p1->next){
		if(p1->name==i) c++;
	}
	return c;
}
void Pighouse::search1(){
	int c=0;
	Pig*p1=head;
	int ft_1=0,ft_2=0,ft_3=0,ft_4=0,ft_5=0;//饲养时间 三个月以下--三到六个月--六到九个月--九个月到一年--超过一年 
	int w_1=0,w_2=0,w_3=0,w_4=0;//体重	 50斤以下--50到100斤--100到150斤--超过150斤 
	for(;p1!=NULL;p1=p1->next){
		c++;
		if(p1->fed_time<90)	ft_1++;
		else if(p1->fed_time<180)	ft_2++;
		else if(p1->fed_time<270)	ft_3++;
		else if(p1->fed_time<360)	ft_4++;
		else ft_5 ++; 
		
		if(p1->weight<50) w_1++; 
		else if(p1->weight<100) w_2++; 
		else if(p1->weight<150) w_3++; 
		else w_4++; 
	}
	cout<<"\n\n\n\n\n		==============================================================\n";
	cout<<"					查询结果\n";
	cout<<"		==============================================================\n\n";
	cout<<"		这个猪圈里有"<<c<<"只黑猪。\n\n";
	cout<<"		饲养时间:\n\n		---3个月以下---3到6个月---6到9个月---9个月到一年---超过一年---\n" ;
	cout<<"		      "<<ft_1<<"		  "<<ft_2<<"	     "<<ft_3<<"		  "<<ft_4<<"	      "<<ft_5<<endl;
	cout<<"		体重:\n\n		-----50斤以下-----50到100斤-----100到150斤-----超过150斤-----\n" ;
	cout<<"		\t "<<w_1<<"          "<<w_2<<"      \t    "<<w_3<<"\t          "<<w_4<<endl<<endl; 
	
} 
void Pighouse::search2(){
	int c=0;
	Pig*p1=head;
	int ft_1=0,ft_2=0,ft_3=0,ft_4=0,ft_5=0;//饲养时间 三个月以下--三到六个月--六到九个月--九个月到一年--超过一年 
	int w_1=0,w_2=0,w_3=0,w_4=0;//体重	 50斤以下--50到100斤--100到150斤--超过150斤 
	for(;p1!=NULL;p1=p1->next){
		if(p1->name==2){
			c++;
			if(p1->fed_time<90)	ft_1++;
			else if(p1->fed_time<180)	ft_2++;
			else if(p1->fed_time<270)	ft_3++;
			else if(p1->fed_time<360)	ft_4++;
			else ft_5 ++; 
		
			if(p1->weight<50) w_1++; 
			else if(p1->weight<100) w_2++; 
			else if(p1->weight<150) w_3++; 
			else w_4++; 
		}
	}
	if(c>0){
		cout<<"\n\n\n\n		==============================================================\n";
	cout<<"					查询结果\n";
	cout<<"		==============================================================\n\n";
	cout<<"		这个猪圈里有"<<c<<"只小花猪。\n\n";
	cout<<"		饲养时间:\n\n		---3个月以下---3到6个月---6到9个月---9个月到一年---超过一年---\n" ;
	cout<<"		      "<<ft_1<<"		  "<<ft_2<<"	     "<<ft_3<<"		  "<<ft_4<<"	      "<<ft_5<<endl;
	cout<<"		体重:\n\n		-----50斤以下-----50到100斤-----100到150斤-----超过150斤-----\n" ;
	cout<<"		\t "<<w_1<<"          "<<w_2<<"      \t    "<<w_3<<"\t          "<<w_4<<endl<<endl; 
	}

}
void Pighouse::search3(){
	int c=0;
	Pig*p1=head;
	int ft_1=0,ft_2=0,ft_3=0,ft_4=0,ft_5=0;//饲养时间 三个月以下--三到六个月--六到九个月--九个月到一年--超过一年 
	int w_1=0,w_2=0,w_3=0,w_4=0;//体重	 50斤以下--50到100斤--100到150斤--超过150斤 
	for(;p1!=NULL;p1=p1->next){
		if(p1->name==3){
			c++;
			if(p1->fed_time<90)	ft_1++;
			else if(p1->fed_time<180)	ft_2++;
			else if(p1->fed_time<270)	ft_3++;
			else if(p1->fed_time<360)	ft_4++;
			else ft_5 ++; 
		
			if(p1->weight<50) w_1++; 
			else if(p1->weight<100) w_2++; 
			else if(p1->weight<150) w_3++; 
			else w_4++; 			
		}
	}
	if(c>0){
		cout<<"\n\n\n\n\n		==============================================================\n";
	cout<<"					查询结果\n";
	cout<<"		==============================================================\n\n";
	cout<<"		这个猪圈里有"<<c<<"只大花白猪。\n\n";
	cout<<"		饲养时间:\n\n		---3个月以下---3到6个月---6到9个月---9个月到一年---超过一年---\n" ;
	cout<<"		      "<<ft_1<<"		  "<<ft_2<<"	     "<<ft_3<<"		  "<<ft_4<<"	      "<<ft_5<<endl;
	cout<<"		体重:\n\n		-----50斤以下-----50到100斤-----100到150斤-----超过150斤-----\n" ;
	cout<<"		\t "<<w_1<<"          "<<w_2<<"      \t    "<<w_3<<"\t          "<<w_4<<endl<<endl; 
	}

}
void Pighouse::search(){//统计当前猪场每个品种猪的数量和体重、饲养时间分布情况
	if(GetisBlack()){
		search1();
	}	
	else{
		search2();
		search3();
	}
}
void Pighouse::clear(){
	pig_num=0;
	head=NULL;
	isBlack=0;
} 
void Pighouse::searchpig(int x){
	Pig *p1=head;
	for(int i=0;p1!=NULL&&i<x;p1=p1->next);
	cout<<"			此猪为";
	if(p1->name==1) cout<<"黑猪,";
	else if(p1->name==2) cout<<"小花猪,";
	else cout<<"大花白猪,";
	cout<<"目前饲养了"<<p1->fed_time<<"天,体重是"<<p1->weight<<"斤"<<endl; 
} 
void Pighouse::print_all(){
	Pig *p1=head;
	for(;p1!=NULL;p1=p1->next){
		cout<<"			猪编号:"<<p1->id<<",品种为";
		if(p1->name==1) cout<<"黑猪,";
		else if(p1->name==2) cout<<"小花猪,";
		else cout<<"大花白猪,";
		cout<<"目前饲养了"<<p1->fed_time<<"天,体重是"<<p1->weight<<"斤"<<endl; 
	}
}
void Pighouse::pupdate(){
	srand((unsigned)time(NULL));
	Pig*p=head;
	while(p){
		p->weight+=(double)(rand()%12)*1/10;
		p->fed_time++;
		p=p->next;
	}
}
void Pighouse::save(ofstream&savefile){
	if(head==NULL){
		savefile<<'0'<<endl;
		return;
	}
	else {
		Pig*p=head;
		int i=0;
		savefile<<pig_num<<endl;
	while(p){
		savefile<<p->name<<"   "<<p->weight<<"   "<<p->fed_time<<endl;
		i++;
		p=p->next;
	}
}
}
