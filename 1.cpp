#include<bits/stdc++.h>
#include"pigpig.h" 
using namespace std;
double money;//��ǰ�Ƹ� 
int pigcnt;//������ 

int main(){
	menu();
	int option;
	cin>>option;
	while(1){

		switch(option){
			case 1:{
			system("cls");//���� �˴�Ӧ��һ����Ϸ�ĺ��� 
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
