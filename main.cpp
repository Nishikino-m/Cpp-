#include<bits/stdc++.h>
#include<windows.h>
#include"pigpig.h"
#include"classp.h" 
using namespace std;
double money;//��ǰ�Ƹ� 
int pigcnt;//������ 
Pighouse ph[105];
int Time;//��Ϸʱ�� ��λ:�� 
int Time_l;//��¼���γ����м�ļ��ʱ�� ==90ʱ��������0 
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
void search_file();
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
			case 2:{//��ѯ��ǰĳһ��Ȧ���������������
				search_pighouse();
				break;
			} 
			case 3: {//��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ��
				search_pighouse_pig();
				break;
			}
			case 4:{//ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ������
				search_message();
				break;
			}
			case 5:{//��ѯ��5��������ۼ�¼�����̶��Ĺ����¼(�ļ�)
				search_file();	
				break;
			}
			case 6:{	//��ӡ��ǰ�����������������Ϣ
				search_all();
				break;
			}
			case 7:{//���� 
				startgame();
			}
			default:{
				cout<<"		���������ѡ��";
				cin>>option;
				break;
			}
		}
	cout<<"		���������ѡ��";
	cin>>option;
	}
}

void startgame(){
	openning();
	int option;
	cin>>option;
	while(1){
		switch(option){
			case 1:{//��ѯ 
				system("cls");//���� 
				startsearch();//�����ѯ
				break;
			} 
			case 2: {	//�����Ȧ��������������
				regame();
				break;
			}
			case 3:{	//�����ļ� 
				save_file();
				break;
			}
			case 4:{//��һ�� 
				Time++; 	
				update();//������Ȧ��Ϣ 
				break;
			}
			case 5:{
				Time+=30;//����һ���¾�Ϊ30�� 
				update_m();//������Ȧ��Ϣ 
				break;
			}
			case 6:{
				exit(0);
			}
			default:{
				cout<<"		���������ѡ��";
				cin>>option;
				break;
			}
		}
		if(option!=1){
			system("cls"); 
			openning();
			cin>>option;
		}
	
	}
}

int main(){
	menu();
	int option;
	cin>>option;
	while(1){
		switch(option){
			case 1:{
			system("cls");//���� �˴�Ӧ��һ����Ϸ�ĺ��� 
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
				cout<<"		���������ѡ��";
				cin>>option;
				break;
			}
		}

	cin>>option;
	
	}
}
void print_Time(int x){//��ӡʱ�� 
	int y=0,m=0,d=0;	
	y=x/360;//��
	x%=360;
	m=x/30;
	x%=30;
	d=x; 
	printf("���Ѿ�����%2d��%2d��%2d��\n",y,m,d);
} 
void newpig(Pig *p){//Ϊ���������Ȧ
	int flag=0,sp=0;//sp:�Ƿ���䵽����Ȧ 
  	if(p->name==1)//����ֻ�ܷ��䵽����Ȧ/����Ȧ 
		flag=1;
	for(int i=0;i<100;i++){
		if(ph[i].Getpig_num()==0){
			ph[i].addpig(p);
			sp=1; 
			cout<<"���䵽����Ȧ��"<<i<<endl;
			break;
		}	
	}
	if(sp==0){//���䵽�ǿ���Ȧ 
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
		if(flag==1)	cout<<"�����䵽����Ȧ��"<<index<<endl;
		else cout<<"�����䵽��Ȧ��"<<index<<endl;
		if(index>99) {
		cout<<"ERROR! ��Ȧ����" ;
		Sleep(10000);
		return;} 
		ph[index].addpig(p);
	}

}
void update(){
	Time_l++; 
	if(Time_l==90){
		Outpig();//���� 
		Getpig();//���� 
		Time_l=0;
	} 
	//�˴�Ӧ�������һ������ ÿ�ո��� 
	 for(int i=0;i<100;i++){
		ph[i].pupdate();
	}
	 
}
void update_m(){
	for(int i=0;i<30;i++){
		update();
	}
}
void newgames(){//��ʼ�� 
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
		p->weight=rand()%61+40;//�����ʼ��20-50����  
		p->fed_time=0;
		newpig(p);
		
	} 

	//�˴��������nֻ���� ���� ���� ����ʱ��Ϊ0 
};
void search_pighouse(){
	int num;
	cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
	cin>>num;
	ph[num].printmessage();
}
void search_pighouse_pig(){
	int num1,num2;
	cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
	cin>>num1;
	while(1){
		if(num1>=0&&num1<100&&ph[num1].Getpig_num()>0)	break;//�Ϸ��ǿ���Ȧ�� 
		else cout<<"			����ȦΪ�գ����������룺";
		cin>>num1;
	}
	cout<<"			����Ȧ����"<<ph[num1].Getpig_num()<<"ͷ��,������Ҫ��ѯ�������ţ�";
	cin>>num2;
	while(1){
		if(num2<(ph[num1].Getpig_num())&&num2>=0)
			break;
		else{
			cout<<"			�������ڣ����������룺";
		cin>>num2;
		}
	}
	ph[num1].searchpig(num2);
}
void search_message(){
	int num;
	while(1){
		cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
		cin>>num;
	
		if(num>=100) cout<<"ERROR!��Ȧ�����ҪС��100\n";
		else {
			ph[num].search();
			break;
		}
	}
	
}
void search_all(){
	int num;
	while(1){
		cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
		cin>>num;
		if(num>=100) cout<<"ERROR!��Ȧ�����ҪС��100\n";
		else {
			ph[num].print_all();
			break;
		}
	}
}

double sellcount(){//���㱾�غ�����������   
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
	//	cout<<"����Ȧ�۳�"<<cot<<"ֻ����\n";
	}
	
//	file<<"����һ���۳�"<<qqq<<"ֻ����\n";
	file.close();
	pigcnt-=qqq; 
//	Sleep(1005);
	return m;
}
void regame(){//���¿�ʼ��Ϸ 
	for(int i=0;i<100;i++){
			ph[i].clear();
	}
	newgames();//��Ϸ��ʼ�� 
}
void print_imformation(){//��ӡ�����Ϣ 
	cout<<"			��ǰ�������"<<money<<"	��������"<<pigcnt<<"	����ʱ��: ";
	print_Time(Time);
}
void start_byfile(){
	ifstream getim;//��ȡ�����Ϣ 
	getim.open("Player.txt");
	if(!getim){
		cout<<"			ERROR:��ȡ����ʧ�ܣ�\n";
		exit(0);
	}
	getim>>pigcnt>>money>>Time>>Time_l; 
	cout<<"			��ȡ�����Ϣ�ɹ���\n";
	getim.close();
	
	ifstream read;
	read.open("Gamedata.txt");
	if(!read){
		cout<<"			ERROR:��ȡ����ʧ�ܣ�\n";
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
	cout<<"			��ȡ��Ȧ���ݳɹ���"<<endl;
	Sleep(200); 
}
void save_file(){
	ofstream saved;
	saved.open("Player.txt");
	saved<<pigcnt<<"	"<<money<<"	"<<Time<<"	"<<Time_l; 
	cout<<"			���������Ϣ�ɹ���"<<endl;
	saved.close();
	ofstream saveg;
	saveg.open("Gamedata.txt");
//	cout<<"���ļ��ɹ�\n";Sleep(500);
	for(int i=0;i<100;i++){
		ph[i].save(saveg);
	}
	cout<<"			����������Ϣ�ɹ���"<<endl;	
	//Sleep(105);
	saveg.close();
}
void Outpig(){
	double sale_v=sellcount(); 
//	cout<<"�����۳�"<<sale_v<<"Ԫ"<<endl; 
	money+=sale_v;
//	Sleep(1000);
	save_sell(Time,sale_v);//�����ܳ��ۼ�¼//ʱ�䡢 ������ 
}
void Getpig(){
	srand((unsigned)time(NULL));
	int num=rand()%200+1;
///	cout<<"������"<<num<<"ֻ��\n";
	
	pigcnt+=num;
	Pig*p;
	while(num--){
		p=new Pig;
		p->name=rand()%3+1;
		p->weight=rand()%100+40;//�����ʼ��20-50����  
		p->fed_time=-1;
		p->countp(); 
		newpig(p);
		
	}
//	 Sleep(1000);
}
void save_sell(int t,double x){
	ofstream file;
	file.open("Record.txt",ios::app);
	file<<t<<"	"<<x<<"	"<<endl; 
	file.close();
} 
void search_file(){
	ifstream pre_file;//Դ�ļ� 
	pre_file.open("Record.txt");
	if(!pre_file){
		cout<<"			�򿪳�Ȧ��Ϣ�ļ�ʧ��\n";
		exit(0);
	} 
	int tmp=1;
	double coin=0;
	int temp=17;
	pre_file>>tmp;
	while(1){
		pre_file>>coin;
		if(tmp>(Time-1800))
			cout<<"			����ʱ��: "<<tmp<<"�죬������۶�"<<coin<<"Ԫ\n";
			temp=tmp;
	
		pre_file>>tmp;//	cout<<"Temp="<<temp<<"	Tmp="<<temp<<endl;
		if(temp==tmp) break;
	}	
	pre_file.close(); 
}
