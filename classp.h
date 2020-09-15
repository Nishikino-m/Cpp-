#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
struct Pig{
	bool ill;
	int name;//����:  1-����  2-С����  3-�󻨰���
	double weight;//���� ��λ:�� 
	int value;//��۵��ۣ�����-15 С����-7 �󻨰���-6 
	double price;//���ܼ� 
	int fed_time;//����ʱ�� 
	int id;//������Ȧ��ı�� 
	Pig* next;//ͬһ����Ȧ����һͷ�� 
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
		int isIll;//��Ȧ���Ƿ��������� 
		int isBlack;//�Ƿ����Ȧ 
		int pig_num;//��Ȧ���������
		int ill_num;//�������� 
		Pig *head;//ָ���һֻ����׵�ַ 
		/*  1.(*p).��Ա��
       		2.p  ->��Ա��
    		�����ַ��ʵķ�ʽ�ǵȼ۵ġ�
		*/ 
	public:
		Pighouse();//Ĭ�Ϲ��캯��
		int Getpig_num();//�����Ȧ������ 
		bool GetisBlack();//�Ƿ����Ȧ 
		void printmessage();//�����Ȧ��Ϣ��������ࣦ����
		void addpig(Pig* p);//���һֻ��
		double sellpig(ofstream&file);//������������ͬʱ���㱾����������� ,�������¼ 
		void Setids();//ÿ��������������ı�� 
		int search(int i);//��������Ϊi��������� 
		void search1();//ͳ�ƺ���������������ء�����ʱ��ֲ����
		void search2();//ͳ��С��������������ء�����ʱ��ֲ����
		void search3();//ͳ�ƴ󻨰�������������ء�����ʱ��ֲ����
		void searchpig(int x);//��ѯ���Ϊx������ 
		void search();//ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����
		void clear();//��յ�ǰ��Ȧ 
		void pupdate(); //����������Ϣ 
		void print_all();//��ӡ��������������Ϣ 
		void save(ofstream&savefile);  
		int Simulated_fever(int pnt);//ģ������ 
		void SetisIll();
		int GetisIll();
		int Getill_num();
		~Pighouse();//��������  
};
Pighouse::Pighouse(){//Ĭ�Ϲ��캯��
	head=NULL;
	isBlack=0;
	pig_num=0;
	ill_num=0;
} 
int Pighouse::Getpig_num(){//�����Ȧ������ 
	return pig_num;
}
bool Pighouse::GetisBlack(){//�Ƿ����Ȧ 
	return isBlack;
}
void Pighouse::addpig(Pig* p){//���һֻ��
	pig_num++;
	p->next=NULL;//����β�巨��p��Ϊ���Ľ����Ҫָ��NULL
	p->id=(pig_num-1);//��Ŵ�0��ʼ 
	if(head==NULL){//����Ȧ 
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
double Pighouse::sellpig(ofstream&ffile){//������������ ͬʱ���㱾����������� 
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
		if(p1->fed_time>360||p1->weight>150){//�ɳ��� 
			if(pig_num==1){
			file<<"�����۳�һֻ";
			if(p1->name==1){
				file<<"����,";
				p1->price=15*(p1->weight);	
			} 
			else if(p1->name==2){
				file<<"С����,";
				p1->price=7*(p1->weight);
			} 
			else{
				file<<"�󻨰���,";
				p1->price=6*(p1->weight);
			} 
			file<<"���۶�"<<(p1->price)<<"\n";
			pricecnt+=(p1->price);	
			isBlack=0;
			head=NULL;
			delete p1;
			pig_num--;
			break;
			}
			pig_num--;
			p2->next=p1->next; 
			file<<"�����۳�һֻ";
			if(p1->name==1){
				file<<"����,";
				p1->price=15*(p1->weight);	
			} 
			else if(p1->name==2){
				file<<"С����,";
				p1->price=7*(p1->weight);
			} 
			else{
				file<<"�󻨰���,";
				p1->price=6*(p1->weight);
			} 
			file<<"���۶�"<<(p1->price)<<"\n";
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
void Pighouse::Setids(){//ÿ��������������ı�� 
	if(head==NULL) return;
	int temp=0;//id
	Pig *p=head;
	while(p){
		p->id=temp;
		temp++;
		p=p->next;
	}
	
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
	cout<<"					��ѯ���\n";
	cout<<"		==============================================================\n\n";
	cout<<"		�����Ȧ����"<<c<<"ֻ�󻨰���\n\n";
	cout<<"		����ʱ��:\n\n		---3��������---3��6����---6��9����---9���µ�һ��---����һ��---\n" ;
	cout<<"		      "<<ft_1<<"		  "<<ft_2<<"	     "<<ft_3<<"		  "<<ft_4<<"	      "<<ft_5<<endl;
	cout<<"		����:\n\n		-----50������-----50��100��-----100��150��-----����150��-----\n" ;
	cout<<"		\t "<<w_1<<"          "<<w_2<<"      \t    "<<w_3<<"\t          "<<w_4<<endl<<endl; 
	}

}
void Pighouse::searchpig(int x){//��ѯ���Ϊx������ 

	Pig *p1=head;
	int i=0;
	for(;p1!=NULL&&i<x;p1=p1->next,i++){
	
	}

	cout<<"			����Ϊ";
	if(p1->name==1) cout<<"����,";
	else if(p1->name==2) cout<<"С����,";
	else cout<<"�󻨰���,";
	cout<<"Ŀǰ������"<<p1->fed_time<<"��,������"<<p1->weight<<"��"<<endl; 

}
void Pighouse::printmessage(){//�����Ȧ��Ϣ��������ࣦ����
	if(Getpig_num()==0){
			printf("			�����Ȧ�ǿ���Ȧ");
			return;
	}
	cout<<"			�����Ȧ��"<<Getpig_num()<<"ֻ����\n"; 
	int c1=0,c2=0,c3=0;
	Pig*p1=head;
	for(;p1!=NULL;p1=p1->next){
		if(p1->name==1) c1++;
		if(p1->name==2) c2++;
		if(p1->name==3) c3++;
	}
	if(c1!=0){
		printf("			�����Ȧ�� %d ͷ����\n",c1);
		return;
	}
	if(c2||c3){
		printf("			�����Ȧ�� %d ͷС����, %d ͷ�󻨰���\n",c2,c3);
		return;
	}
	return; 
}

void Pighouse::search(){//ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����
	if(isBlack) search1();
	else {
		search2();
		search3();
	}
}
void Pighouse::clear(){//��յ�ǰ��Ȧ 
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

void Pighouse::pupdate(){//����������Ϣ 
	srand((unsigned)time(NULL));//������� 
	Pig*p=head;
	while(p){
		p->weight+=(double)(rand()%12)*1/10.0;//����� 
		p->fed_time++;
		p=p->next;
	}
} 
void Pighouse::print_all(){//��ӡ��ǰ��Ȧ��������������Ϣ 
	Pig *p1=head;
	while(p1){
		cout<<"			����:"<<p1->id<<",Ʒ��Ϊ";
		if(p1->name==1) cout<<"����,";
		else if(p1->name==2) cout<<"С����,";
		else cout<<"�󻨰���,";
		cout<<"Ŀǰ������"<<p1->fed_time<<"��,������"<<p1->weight<<"��"<<endl; 
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
		maybe=(rand()%20);//����� 
		if(maybe<=ppnt&&p->ill==0){
		//	cout<<"����������\n";
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

Pighouse::~Pighouse(){//��������
	clear();
}
