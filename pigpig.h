#include<bits/stdc++.h>
#include"Pig.h" 
using namespace std;
#define ll long long
ll Time=0;
 
void menu(){
	cout<<"\n\n\n\n\n		==============================================================\n\n";
	cout<<"					����ģ��ϵͳ                        \n\n\n";
	cout<<"					1.��ʼ��Ϸ\n\n";
	cout<<"					2.����\n\n";
	cout<<"					3.�˳�\n\n";
	cout<<"		==============================================================\n\n";
	cout<<"		���������ѡ��";

}
void openning(){
	system("cls");
	cout<<"\n\n\n\n\n		==============================================================\n\n";
	cout<<"					��������                        \n\n";
	cout<<"			1.��ѯ��Ϣ\n";
	cout<<"			2.������Ϸ\n";
	cout<<"			3.������Ϸ\n";
	cout<<"			4.��һ��			5.�¸���\n"; 
	cout<<"			6.�˳���Ϸ\n";
	cout<<'\n';
	//cout<<"               ��ǰ�������"<<<"    ��������"<<allpig<<"   ����ʱ��:";if(month>0)cout<<month<<"����";if(day>=0)cout<<day<<"��";
	cout<<"		==============================================================\n\n";
	cout<<"		���������ѡ��";
}
void startsearch(){
	system("cls");
	cout<<"\n\n\n\n\n		==============================================================\n\n";
	cout<<"				��ѯ			\n\n";
	cout<<"			1.��ѯ��ǰĳһ��Ȧ���������������\n";
	cout<<"			2.��ѯ��ǰĳһ��Ȧĳͷ���״̬��Ϣ\n";
	cout<<"			3.ͳ�Ƶ�ǰ��ÿ��Ʒ��������������ء�����ʱ��ֲ����\n";
	cout<<"			4.��ѯ��5��������ۼ�¼�����̶��Ĺ����¼\n";
	cout<<"			5.��ӡ��ǰ�����������������Ϣ\n";
	cout<<"			6.����\n\n";
	cout<<"		==============================================================\n\n";
	cout<<"		���������ѡ��";
}
void startgame(){
	openning();
	int option;
	cin>>option;
	while(1){
		switch(option){
			case 1:{//��ѯ 
			system("cls");//���� 
			startsearch();
			break;} 
			case 2: {
			//�����Ȧ�������������� 
				break;
			}
			case 3:{
				//�����ļ� 
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

	cin>>option;
	
	}
}
