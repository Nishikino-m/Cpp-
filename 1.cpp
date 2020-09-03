#include<bits/stdc++.h>
#include"pigpig.h" 
using namespace std;
double money;//当前财富 
int pigcnt;//总猪猪 

int main(){
	menu();
	int option;
	cin>>option;
	while(1){

		switch(option){
			case 1:{
			system("cls");//清屏 此处应是一个游戏的函数 
			startgame();
			break;} 
			case 2: {
				system("cls");
				cout<<"\n\n\n\n\n		=========================帮助===========================\n\n";
				cout<<"		请键入您的选择：";
				break;
			}
			case 3:{
				exit(0);
			}
			default:{
				cout<<"		请键入您的选择：";
				cin>>option;
				break;
			}
		}

	cin>>option;
	
	}
}
