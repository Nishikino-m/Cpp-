#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct Pig{
	bool ill;
	int name;//种类:  1-黑猪  2-小花猪  3-大花白猪
	double weight;//体重 单位:斤 
	int value;//猪价单价：黑猪-15 小花猪-7 大花白猪-6 
	double price;//猪总价 
	int fed_time;//饲养时间 
	int id;//猪在猪圈里的编号 
	Pig* next;//同一个猪圈的下一头猪 
	void countp(){
		if(name==1) value=15;
		else if(name==2) value=7;
		else value=6;
	//	cout<<weight<<" * "<<value<<endl;
		price=weight*value;
	}
}; 
class Pighouse{
	private:
		int isIll;//猪圈中是否有猪猪患病 
		int isBlack;//是否黑猪圈 
		int pig_num;//猪圈中猪的数量
		int ill_num;//病猪数量 
		Pig *head;//指向第一只猪的首地址 
		/*  1.(*p).成员名
       		2.p  ->成员名
    		这两种访问的方式是等价的。
		*/ 
	public:
		Pighouse();//默认构造函数
		int Getpig_num();//获得猪圈猪数量 
		bool GetisBlack();//是否黑猪圈 
		void printmessage();//输出猪圈信息：猪的种类＆数量
		void addpig(Pig* p);//添加一只猪
		double sellpig(ofstream&file);//卖掉能卖的猪同时计算本次卖猪的收入 ,并保存记录 
		void Setids();//每次卖出后，重置猪的编号 
		int search(int i);//计算种类为i的猪的数量 
		void search1();//统计黑猪猪的数量和体重、饲养时间分布情况
		void search2();//统计小花猪的数量和体重、饲养时间分布情况
		void search3();//统计大花白猪的数量和体重、饲养时间分布情况
		void searchpig(int x);//查询编号为x的猪猪 
		void search();//统计当前猪场每个品种猪的数量和体重、饲养时间分布情况
		void clear();//清空当前猪圈 
		void pupdate(); //更新猪猪信息 
		void print_all();//打印所有猪猪所有信息 
		void save(ofstream&savefile);  
		int Simulated_fever(int pnt);//模拟猪瘟 
		void SetisIll();
		int GetisIll();
		int Getill_num();
		~Pighouse();//析构函数  
};
Pighouse::Pighouse(){//默认构造函数
	head=NULL;
	isBlack=0;
	pig_num=0;
	ill_num=0;
} 
int Pighouse::Getpig_num(){//获得猪圈猪数量 
	return pig_num;
}
bool Pighouse::GetisBlack(){//是否黑猪圈 
	return isBlack;
}
void Pighouse::addpig(Pig* p){//添加一只猪
	pig_num++;
	p->next=NULL;//采用尾插法，p作为最后的结点需要指向NULL
	p->id=(pig_num-1);//编号从0开始 
	if(head==NULL){//空猪圈 
		head=p;
		if(p->name==1) isBlack=1;
		return;
	}
	Pig *p1=head;
	while(p1->next){
		p1=p1->next;
	} 
	p1->next=p;
}
double Pighouse::sellpig(ofstream&ffile){//卖掉能卖的猪 同时计算本次卖猪的收入 
	ofstream file;
	file.open("RRRRecord.txt",ios::app);
	if (pig_num==0) {
		return 0;
	}
	int flag=0;
	Pig *p1=head;
	Pig *p2=head;//pre
	double pricecnt=0;
	for(;p1!=NULL;){
		if(p1->fed_time>360||p1->weight>150){//可出售 
			if(pig_num==1){
			file<<"本次售出一只";
			if(p1->name==1){
				file<<"黑猪,";
				p1->price=15*(p1->weight);	
			} 
			else if(p1->name==2){
				file<<"小花猪,";
				p1->price=7*(p1->weight);
			} 
			else{
				file<<"大花白猪,";
				p1->price=6*(p1->weight);
			} 
			file<<"销售额"<<(p1->price)<<"\n";
			pricecnt+=(p1->price);	
			isBlack=0;
			head=NULL;
			delete p1;
			pig_num--;
			break;
			}
			pig_num--;
			p2->next=p1->next; 
			file<<"本次售出一只";
			if(p1->name==1){
				file<<"黑猪,";
				p1->price=15*(p1->weight);	
			} 
			else if(p1->name==2){
				file<<"小花猪,";
				p1->price=7*(p1->weight);
			} 
			else{
				file<<"大花白猪,";
				p1->price=6*(p1->weight);
			} 
			file<<"销售额"<<(p1->price)<<"\n";
			pricecnt+=(p1->price);	
			delete p1;
			p1=p2->next;
		}
		else{
			if(flag==0){
				flag=1;
				head=p1;
			}
			p2=p1;
			p1=p1->next;
		}
	}
	Setids();
	file.close();
	return pricecnt;
}
void Pighouse::Setids(){//每次卖出后，重置猪的编号 
	if(head==NULL) return;
	int temp=0;//id
	Pig *p=head;
	while(p){
		p->id=temp;
		temp++;
		p=p->next;
	}
	
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
	while(p1){
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
		p1=p1->next;
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
void Pighouse::searchpig(int x){//查询编号为x的猪猪 

	Pig *p1=head;
	int i=0;
	for(;p1!=NULL&&i<x;p1=p1->next,i++){
	
	}

	cout<<"			此猪为";
	if(p1->name==1) cout<<"黑猪,";
	else if(p1->name==2) cout<<"小花猪,";
	else cout<<"大花白猪,";
	cout<<"目前饲养了"<<p1->fed_time<<"天,体重是"<<p1->weight<<"斤"<<endl; 

}
void Pighouse::printmessage(){//输出猪圈信息：猪的种类＆数量
	if(Getpig_num()==0){
			printf("			这个猪圈是空猪圈");
			return;
	}
	cout<<"			这个猪圈有"<<Getpig_num()<<"只猪猪\n"; 
	int c1=0,c2=0,c3=0;
	Pig*p1=head;
	for(;p1!=NULL;p1=p1->next){
		if(p1->name==1) c1++;
		if(p1->name==2) c2++;
		if(p1->name==3) c3++;
	}
	if(c1!=0){
		printf("			这个猪圈有 %d 头黑猪\n",c1);
		return;
	}
	if(c2||c3){
		printf("			这个猪圈有 %d 头小花猪, %d 头大花白猪\n",c2,c3);
		return;
	}
	return; 
}

void Pighouse::search(){//统计当前猪场每个品种猪的数量和体重、饲养时间分布情况
	if(isBlack) search1();
	else {
		search2();
		search3();
	}
}
void Pighouse::clear(){//清空当前猪圈 
	pig_num=0;
	isBlack=0;
	isIll=0;
	if(head==NULL){
		return;
	}
	else{
		Pig*p=head;
		Pig*p1=p;
		head=NULL;
		while(p){
			p1=p;
			p=p->next;
			delete p1;
		}
	}
}

void Pighouse::pupdate(){//更新猪猪信息 
	srand((unsigned)time(NULL));//随机种子 
	Pig*p=head;
	while(p){
		p->weight+=(double)(rand()%12)*1/10.0;//随机数 
		p->fed_time++;
		p=p->next;
	}
} 
void Pighouse::print_all(){//打印当前猪圈所有猪猪所有信息 
	Pig *p1=head;
	while(p1){
		cout<<"			猪编号:"<<p1->id<<",品种为";
		if(p1->name==1) cout<<"黑猪,";
		else if(p1->name==2) cout<<"小花猪,";
		else cout<<"大花白猪,";
		cout<<"目前饲养了"<<p1->fed_time<<"天,体重是"<<p1->weight<<"斤"<<endl; 
		p1=p1->next;
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
	return;
}
int Pighouse::Simulated_fever(int pnt){
	int illpig=0;
	int maybe;
	Pig*p=head;
	int ppnt;
	if(pnt==15) ppnt=3;
	else ppnt=10;
	while(p){
		maybe=(rand()%20);//随机数 
		if(maybe<=ppnt&&p->ill==0){
		//	cout<<"有新猪猪患病\n";
			p->ill=1;
			isIll=1;
			ill_num++;
			illpig++;	
		}
		p=p->next;
	}
	return illpig;
}
void Pighouse::SetisIll(){
	head->ill=1;
	isIll=1;
	ill_num=1;
}
int Pighouse::GetisIll(){
	return isIll;
}
int Pighouse::Getill_num(){
	return ill_num;
}

Pighouse::~Pighouse(){//析构函数
	clear();
}
