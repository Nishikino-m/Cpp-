#include<bits/stdc++.h>
using namespace std;
struct Pig{
	int name;//����:  1-����  2-С����  3-�󻨰���
	double weight;//���� ��λ:�� 
	int value;//��۵��ۣ�����-15 С����-7 �󻨰���-6 
	double price;//���ܼ� 
	int fed_time;//����ʱ�� 
	int id;//������Ȧ��ı�� 
	Pig* next;//ͬһ����Ȧ����һͷ�� 
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
	int pig_num;//��Ȧ���������
	Pig *head;
	bool isBlack;
public:
	Pighouse();//Ĭ�Ϲ��캯��
//	void Setpig(int a,double b);//�����ʼ��Ȧ��Ϣ 
	int Getpig_num();
	int GetisBlack();
	void printmessage();//�����Ȧ��Ϣ��������ࣦ����
	void Setids();//ÿ��������������ı�� 
	void buypig(Pig* p);//���һֻ��
	double sellpig(ofstream&file);//������������ͬʱ���㱾����������� ,�������¼ 
	int search(int i);//��������Ϊi��������� 
	void search1();//ͳ�ƺ���������������ء�����ʱ��ֲ����
	void search2();//ͳ��С��������������ء�����ʱ��ֲ����
	void search3();//ͳ�ƴ󻨰�������������ء�����ʱ��ֲ����
	void searchpig(int x);
	void search();//ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����
	void clear();//��յ�ǰ��Ȧ 
	void pupdate(); //����������Ϣ 
	void print_all();//��ӡ��������������Ϣ 
	void save(ofstream&savefile);               
};

Pighouse::Pighouse(){// Ĭ�Ϲ��캯��
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
void Pighouse::printmessage(){//�����Ȧ��Ϣ��������ࣦ����
	int c1=0,c2=0,c3=0;
	Pig*p1=head;
	for(;p1!=NULL;p1=p1->next){
		if(p1->name==1) c1++;
		if(p1->name==2) c2++;
		if(p1->name==3) c3++;
	}
	if(c1!=0){
		cout<<"�����Ȧ��"<<c1<<"ͷ����\n";
		return;
	}
	if(c2||c3){
		cout<<"�����Ȧ��"<<c2<<"ͷС�����Լ�"<<c3<<"ͷ�󻨰���\n" ;
	}
	else{
		cout<<"����һ������Ȧ��\n";
	}
}
void Pighouse::Setids(){//ÿ��������������ı�� 
	Pig *p1=head;
	int id=0;
	for(;p1!=NULL;p1=p1->next){
		p1->id=id;
		id++;	
	}
	if(id==0) isBlack=0;//û���� 
}
void Pighouse::buypig(Pig *p){//���һֻ��
	pig_num++;
	p->next=NULL;
	if(head==NULL){//��һͷ�� 
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
double Pighouse::sellpig(ofstream&file){//������������ ͬʱ���㱾����������� 
	Pig *p1=head;
	Pig *p2=head;//pre
	double pricecnt=0;
	for(;p1!=NULL;p1=p1->next,p2=p1){
		if(p1->fed_time>360||p1->weight>150){//�����۳� 
			pig_num--;
			p2->next=p1->next;
		//	cout<<"(p1->price)"<<(p1->price); 
			file<<"�۳�һֻ";
			if(p1->name==1) file<<"����,";
			else if(p1->name==2) file<<"С����,";
			else file<<"�󻨰���,";
			file<<",�ۼ�Ϊ"<<(p1->price)<<"\n";
			pricecnt+=(p1->price);	
		}
	}
	Setids();
	return pricecnt;
}
int Pighouse::search(int i){//��������Ϊi��������� 
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
	int ft_1=0,ft_2=0,ft_3=0,ft_4=0,ft_5=0;//����ʱ�� ����������--����������--�����Ÿ���--�Ÿ��µ�һ��--����һ�� 
	int w_1=0,w_2=0,w_3=0,w_4=0;//����	 50������--50��100��--100��150��--����150�� 
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
	cout<<"					��ѯ���\n";
	cout<<"		==============================================================\n\n";
	cout<<"		�����Ȧ����"<<c<<"ֻ����\n\n";
	cout<<"		����ʱ��:\n\n		---3��������---3��6����---6��9����---9���µ�һ��---����һ��---\n" ;
	cout<<"		      "<<ft_1<<"		  "<<ft_2<<"	     "<<ft_3<<"		  "<<ft_4<<"	      "<<ft_5<<endl;
	cout<<"		����:\n\n		-----50������-----50��100��-----100��150��-----����150��-----\n" ;
	cout<<"		\t "<<w_1<<"          "<<w_2<<"      \t    "<<w_3<<"\t          "<<w_4<<endl<<endl; 
	
} 
void Pighouse::search2(){
	int c=0;
	Pig*p1=head;
	int ft_1=0,ft_2=0,ft_3=0,ft_4=0,ft_5=0;//����ʱ�� ����������--����������--�����Ÿ���--�Ÿ��µ�һ��--����һ�� 
	int w_1=0,w_2=0,w_3=0,w_4=0;//����	 50������--50��100��--100��150��--����150�� 
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
	cout<<"					��ѯ���\n";
	cout<<"		==============================================================\n\n";
	cout<<"		�����Ȧ����"<<c<<"ֻС����\n\n";
	cout<<"		����ʱ��:\n\n		---3��������---3��6����---6��9����---9���µ�һ��---����һ��---\n" ;
	cout<<"		      "<<ft_1<<"		  "<<ft_2<<"	     "<<ft_3<<"		  "<<ft_4<<"	      "<<ft_5<<endl;
	cout<<"		����:\n\n		-----50������-----50��100��-----100��150��-----����150��-----\n" ;
	cout<<"		\t "<<w_1<<"          "<<w_2<<"      \t    "<<w_3<<"\t          "<<w_4<<endl<<endl; 
	}

}
void Pighouse::search3(){
	int c=0;
	Pig*p1=head;
	int ft_1=0,ft_2=0,ft_3=0,ft_4=0,ft_5=0;//����ʱ�� ����������--����������--�����Ÿ���--�Ÿ��µ�һ��--����һ�� 
	int w_1=0,w_2=0,w_3=0,w_4=0;//����	 50������--50��100��--100��150��--����150�� 
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
	cout<<"					��ѯ���\n";
	cout<<"		==============================================================\n\n";
	cout<<"		�����Ȧ����"<<c<<"ֻ�󻨰���\n\n";
	cout<<"		����ʱ��:\n\n		---3��������---3��6����---6��9����---9���µ�һ��---����һ��---\n" ;
	cout<<"		      "<<ft_1<<"		  "<<ft_2<<"	     "<<ft_3<<"		  "<<ft_4<<"	      "<<ft_5<<endl;
	cout<<"		����:\n\n		-----50������-----50��100��-----100��150��-----����150��-----\n" ;
	cout<<"		\t "<<w_1<<"          "<<w_2<<"      \t    "<<w_3<<"\t          "<<w_4<<endl<<endl; 
	}

}
void Pighouse::search(){//ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����
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
	cout<<"			����Ϊ";
	if(p1->name==1) cout<<"����,";
	else if(p1->name==2) cout<<"С����,";
	else cout<<"�󻨰���,";
	cout<<"Ŀǰ������"<<p1->fed_time<<"��,������"<<p1->weight<<"��"<<endl; 
} 
void Pighouse::print_all(){
	Pig *p1=head;
	for(;p1!=NULL;p1=p1->next){
		cout<<"			����:"<<p1->id<<",Ʒ��Ϊ";
		if(p1->name==1) cout<<"����,";
		else if(p1->name==2) cout<<"С����,";
		else cout<<"�󻨰���,";
		cout<<"Ŀǰ������"<<p1->fed_time<<"��,������"<<p1->weight<<"��"<<endl; 
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
