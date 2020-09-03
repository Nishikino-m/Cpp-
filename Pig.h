#include<bits/stdc++.h>
using namespace std;
struct Pig{
	int name;//种类:  1-黑猪  2-小花猪  3-大花白猪
	double weight;//体重 单位:斤 
	int value;//猪价单价：黑猪-15 小花猪-7 大花白猪-6 
	double price;//猪总价 
	int fed_time=400;//饲养时间 
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
	double sellpig();//卖掉能卖的猪同时计算本次卖猪的收入 
	int search(int i);//计算种类为i的猪的数量 
	void search1();//统计黑猪猪的数量和体重、饲养时间分布情况
	void search2();//统计小花猪的数量和体重、饲养时间分布情况
	void search3();//统计大花白猪的数量和体重、饲养时间分布情况
	void search();//统计当前猪场每个品种猪的数量和体重、饲养时间分布情况
}ph[105];

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
double Pighouse::sellpig(){//卖掉能卖的猪 同时计算本次卖猪的收入 
	Pig *p1=head;
	Pig *p2=head;//pre
	double pricecnt=0;
	for(;p1!=NULL;p1=p1->next,p2=p1){
		if(p1->fed_time>360||p1->weight>150){//可以售出 
			pig_num--;
			p2->next=p1->next;
		//	cout<<"(p1->price)"<<(p1->price); 
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
	if(GetisBlack())
		search1();
	else{
		search2();
		search3();
	}
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
int main(){
	Pig pp(1,2.3);
	pp.countp();
//	cout<<pp.name<<" "<<pp.price<<endl;
	newpig(&pp);
//	ph[0].printmessage();
	ph[0].search();
	//cout<<"0号猪圈卖出金额："<<ph[0].sellpig()<<endl;
	
	Pig ppp(2,5.3);
	ppp.countp();
//	cout<<ppp.name<<" "<<ppp.price<<endl;
	newpig(&ppp);
//	ph[1].printmessage();

	ph[1].search();
//	cout<<"1号猪圈卖出金额："<<ph[1].sellpig();
} 
