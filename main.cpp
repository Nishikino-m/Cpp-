#include<bits/stdc++.h>
#include"pigpig.h" 
using namespace std;
double money;//��ǰ�Ƹ� 
int pigcnt;//������ 
Pighouse ph[105];
ll Time;//��Ϸʱ�� ��λ:�� 
void startgame();
void newgames(){
	money=0;
	Time=0; 
	//�˴��������nֻ���� ���� ���� ����ʱ��Ϊ0 
};
void clearpig(){
	for(int i=0;i<100;i++){
			ph[i].clear();
	}
	newgames();//��Ϸ��ʼ�� 
}
void print_imformation(){
	cout<<"			��ǰ�������"<<money<<"	��������"<<pigcnt<<"	����ʱ��: "<<Time<<endl;
}
double sellcount(){//���㱾�غ����������� 
	int m;
	for(int i=0;i<100;i++){
		m+=ph[i].sellpig();
	} 
	return m;
}
void newpig(Pig *p){//Ϊ���������Ȧ
	int flag=0,sp=0;//sp:�Ƿ���䵽����Ȧ 
  	if(p->name==1)//����ֻ�ܷ��䵽����Ȧ/����Ȧ 
		flag=1;
	for(int i=0;i<100;i++){
		if(ph[i].Getpig_num()==0){
			ph[i].buypig(p);
			sp=1; 
			//cout<<"���������Ȧ��"<<i<<endl;
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
		//cout<<"��������Ȧ��"<<index<<endl;
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
			case 2:{//��ѯ��ǰĳһ��Ȧ���������������
				break;
			} 
			case 3: {//��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ��
				break;
			}
			case 4:{//ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ������
				break;
			}
			case 5:{//��ѯ��5��������ۼ�¼�����̶��Ĺ����¼	
				break;
			}
			case 6:{	//��ӡ��ǰ�����������������Ϣ
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
				clearpig();
				break;
			}
			case 3:{	//�����ļ� 
				break;
			}
			case 4:{//��һ�� 
				Time++; 	
				break;
			}
			case 5:{
				Time+=30;//����һ���¾�Ϊ30�� 
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
				cout<<"\n\n\n\n\n		=========================����===========================\n\n";
				cout<<"		���������ѡ��";
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
