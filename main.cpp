#include<bits/stdc++.h>
#include"pigpig.h" 
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
		}
		else cout<<"		���������ѡ��";
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
			system("cls");//���� �˴�Ӧ��һ����Ϸ�ĺ��� 
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
			ph[i].buypig(p);
			sp=1; 
			cout<<"���䵽����Ȧ��"<<i<<endl;
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
		cout<<"�����䵽��Ȧ��"<<index<<endl;
		ph[index].buypig(p);
	}

}
void update(){
	if(Time_l==90){
	//	Outpig();//���� 
	//	Getpig();//���� 
		Time_l=0;
	} 
	//�˴�Ӧ�������һ������
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
	srand((unsigned)time(NULL));
	pigcnt=rand()%200+1;
	int num=pigcnt;
	Pig*p;
	while(num--){
		p=new Pig;
		p->name=rand()%3+1;
		p->weight=rand()%100+40;//�����ʼ��20-50����  
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
		if(num1>=0&&num1<100&&ph[num1].Getpig_num())	break;//�Ϸ��ǿ���Ȧ�� 
		else cout<<"			����ȦΪ�գ����������룺";
		cin>>num1;
	}
	cout<<"			����Ȧ����"<<ph[num1].Getpig_num()<<"ͷ��,������Ҫ��ѯ�������ţ�";
	cin>>num2;
	while(1){
		if(num2<=(ph[num1].Getpig_num())&&num2>=0)
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
	cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
	cin>>num;
	ph[num].search();
}
void search_all(){
	int num;
	cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
	cin>>num;
	ph[num].print_all();
}
double sellcount(){//���㱾�غ����������� 
	int m;
	for(int i=0;i<100;i++){
		m+=ph[i].sellpig();
	} 
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
