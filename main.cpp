#include<bits/stdc++.h>
#include<windows.h>
#include"pigpig.h"
#include"classp.h" 
using namespace std;
/*test Git*/
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
void update_fever();
void update_m();
void regame();
void print_imformation();
void search_pighouse();
void search_pighouse_pig();
void search_message();
void search_all();
void print_All(); 
double sellcount();
void Outpig();
void Getpig();
void start_byfile();
void save_file();
void save_sell(int t,double x);
void save_buy(int t,int x);
void search_file();
void search_buy();
void Simulated();//ģ������ 
double submoney(int name,double weight);
int opt,numm;
int change(string a){//�ַ���ת���� 
	int len=a.size();
	int ans=0;
	for(int i=len-1;i>=0;i--){
		if(a[i]>'9'||a[i]<'0'){
			return 404;
		}
		ans*=10;
		ans+=a[i]-'0';
	}
	return ans;
}
void mainmenu(){
	menu();
	string option;
	cin>>option;
	opt=change(option);
	while(1){
	//	cout<<"opt="<<opt;
		switch(opt){
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
//				cout<<"		���������ѡ��";
//				cin>>option;
//				opt=change(option);
				break;
			}
		}
	if(opt!=3)	cout<<"		���������ѡ��";
	cin>>option;
	opt=change(option);
	}
}
void startsearch(){
	searching();
	string option;
	cin>>option;
		opt=change(option);
	while(1){
		switch(opt){
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
				search_buy();
				break;
			}
			case 6:{	//��ӡ��ǰ�����������������Ϣ
				search_all();
				break;
			}
			case 7:{//��ӡ������Ȧ����Ϣ 
				print_All();
				break;
			} 
			case 8:{//���� 
				startgame();
			}
			default:{
//				cout<<"		���������ѡ��";
				cout<<"		ERROR! ��ѡ�����\n";
//				cin>>option;
//				opt=change(option);
				break;
			}
		}
	cout<<"		���������ѡ��(��ѯ)[����8���ع��ܲ˵�]��";
	cin>>option;
	opt=change(option);
	}
}

void startgame(){
	openning();
	string option;
	cin>>option;
	opt=change(option);
	while(1){
		switch(opt){
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
			case 7:{
				system("cls"); 
				Simulated_Help();
				Simulated();
				break;
			}
			case 8:{
				system("cls"); 
				mainmenu();
				break;
			} 
			default:{
//				cout<<"		���������ѡ��";
//				cin>>option;
//					opt=change(option);
				break;
			}
		}
		if(opt==7){
			cout<<"		����������Ϸ��...\n";
			Sleep(100);
			newgames();
			startgame();
		}
		if(opt!=1){
			system("cls"); 
			openning();//����������ѡ���� 
			cin>>option;
			opt=change(option);
		}
	
	}
}
int main(){

	mainmenu();
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
		//	cout<<"���䵽����Ȧ��"<<i<<endl;
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
	//	if(flag==1)	cout<<"�����䵽����Ȧ��"<<index<<endl;
	//	else cout<<"�����䵽��Ȧ��"<<index<<endl;
		if(index>99) {
		cout<<"ERROR! ��Ȧ����" ;
		//Sleep(10000);
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
	file.open("Buy_Record.txt",ios::trunc);
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
	//Sleep(10000); 
	//�˴��������nֻ���� ���� ���� ����ʱ��Ϊ0 
};
void search_pighouse(){
	string num;
	cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
	cin>>num;
	numm=change(num);
	while(1){
		if(numm>=0&&numm<100){
			ph[numm].printmessage();
			break;
		}
		cout<<"\n			������Ҫ��ѯ����Ȧ��ţ�";
	cin>>num;
	numm=change(num);
		
	}
	
	
}
void search_pighouse_pig(){
	string num1,num2;
	cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
	cin>>num1;
	int num11=change(num1);
	while(1){
		if(num11>=0&&num11<100&&ph[num11].Getpig_num()>0)	break;//�Ϸ��ǿ���Ȧ�� 
		else cout<<"			����ȦΪ�ջ򲻴��ڣ����������룺";
		cin>>num1;
		num11=change(num1);
	}
	cout<<"			����Ȧ����"<<ph[num11].Getpig_num()<<"ͷ��,������Ҫ��ѯ�������ţ�";
	cin>>num2;
	int num22=change(num2);
	while(1){
		if(num22<(ph[num11].Getpig_num())&&num22>=0)
			break;
		else{
			cout<<"			�������ڣ����������룺";
		cin>>num2;
		num22=change(num2);
		}
	}
	ph[num11].searchpig(num22);
}
void search_message(){
	string num;
	numm=change(num);
	while(1){
		cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
		cin>>num;
	numm=change(num);
		if(numm>=100) cout<<"			ERROR!��Ȧ�����ҪС��100\n";
		else {
			ph[numm].search();
			break;
		}
	}
	
}
void search_all(){
	string num;
	while(1){
		cout<<"			������Ҫ��ѯ����Ȧ��ţ�";
		cin>>num;
		numm=change(num);
		if(numm>=100) cout<<"			ERROR!��Ȧ�����ҪС��100\n";
		else {
			ph[numm].print_all();
			break;
		}
	}
}
void print_All(){
	for(int i=0;i<100;i++){
		cout<<"\n\n		=========================��Ȧ���:"<<i<<"=========================\n\n\n"; 
		if(ph[i].Getpig_num())
			ph[i].print_all();
		else {
			cout<<"			��һ������Ȧ\n";
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
	//Sleep(1005);
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
	ofstream saved;
	saved.open("BBBBuy_Record.txt");
	srand((unsigned)time(NULL));
	int num=rand()%50+1;
	int precnt=pigcnt;
	pigcnt+=num;
	
	int prenum=num;
	Pig*p;
	double pric=0.0;
	saved<<"����ʱ��:"<<Time<<"		����Ԥ�ƹ���"<<num<<"ͷ\n"; 
	while(num){
		p=new Pig;
		p->name=rand()%3+1;
		p->weight=rand()%100+40;//�����ʼ��20-50����  
		p->fed_time=-1;
		p->countp(); 
		pric=submoney(p->name,p->weight);
		saved<<"�������ࣺ"<<p->name<<"\n����Ϊ��"<<p->weight<<"\n";
		if(money-pric<=0){
			delete p;
		//	cout<<"num="<<num<<endl;
		//	Sleep(1000);
		
			pigcnt-=num;
			saved<<"�����ʽ��㣬����ʵ�ʹ���"<<prenum-num<<"ͷ\n"; 
			saved.close();
		//	cout<<"�������������ı�:"<<(precnt-pigcnt)<<"ͷ\n";
			Sleep(200);
			save_buy(Time,(prenum-num));
			return;
		}
		money-=pric;
		newpig(p);
		num--;
	}
	saved.close();
//	cout<<"�������������ı�:"<<(precnt-pigcnt)<<"ͷ\n";
//	Sleep(200);
	save_buy(Time,prenum);
	 
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
	if(tmp==1){
		cout<<"		��δ������Ȧ����ѡ������\n";
		return;
	}
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
void save_buy(int t ,int x){
	ofstream file;
	file.open("Buy_Record.txt",ios::app);
	file<<t<<"	"<<x<<"	"<<endl; 
	file.close();
} 

void search_buy(){
	ifstream pre_file;//Դ�ļ� 
	pre_file.open("Buy_Record.txt");
	if(!pre_file){
		cout<<"			�򿪹�����Ϣ�ļ�ʧ��\n";
		exit(0);
	} 
	int tmp=1;
	int buynum=0;
	int temp=17;
	pre_file>>tmp;
	if(tmp==1){
		cout<<"		��δ�����������̣���ѡ������\n";
		return;
	}
	while(1){
		pre_file>>buynum;
		if(tmp>(Time-1800))
			cout<<"			����ʱ��: "<<tmp<<"�죬��������"<<buynum<<"ֻ\n";
			temp=tmp;
	
		pre_file>>tmp;//	cout<<"Temp="<<temp<<"	Tmp="<<temp<<endl;
		if(temp==tmp) break;
	}	
	pre_file.close(); 
	
}
double submoney(int name,double weight){
	double pri=0.0;
	if(name==1){
		pri=500;
	}
	else if(name==2){
		pri=100;
	}
	else if(name==3){
		pri=50;
	}
	return pri;

}
void Simulated(){
	srand((unsigned)time(NULL));
	int illnum=rand()%100;//���һ��������Ȧ 
	//������������Ȧ�ǿյģ�ֱ�����¿�ʼ���� 
	if(ph[illnum].Getpig_num()==0){
		cout<<"Another \n";
		Simulated();
		return;
	} 
	int day=0,illpig=1;
	int newill=0;
	ph[illnum].SetisIll();//����Ȧ�л�����(ͷ 
	int flag1=0;//����һ�� ����������Ȧ���� ������1 ����ѭ�� 
	do{
		//cout<<"DO\n";
		flag1=0;
		for(int i=0;i<100;i++){
			newill=0;
			if(ph[i].GetisIll()){
				if(ph[i].Getill_num()!=ph[i].Getpig_num()){
					newill+=ph[i].Simulated_fever(50);
					flag1=1;
				}
				
				if(i-1>=0){
					if(ph[i-1].Getill_num()!=ph[i-1].Getpig_num()) flag1=1;
					newill+=ph[i-1].Simulated_fever(15);
					
				}
				if(i+1<100){
					if(ph[i+1].Getill_num()!=ph[i+1].Getpig_num()) flag1=1;
					newill+=ph[i+1].Simulated_fever(15);
				
				
				}
			}	illpig+=newill;
		//	if(newill>0)
		//	cout<<"��Ȧ���"<<i<<"������������"<<newill<<"ͷ\n";
		}
		day++;	
		Time++;
		cout<<"day= "<<day<<"  ���������� "<<illpig<<"ͷ\n";
		//Sleep(500);
	}while(flag1);
	cout<<"\n\n\n\n\n		==============================================================\n\n";
	cout<<"					�������\n\n";
	cout<<"		����"<<day<<"�죬��������"<<illpig<<"ֻ������\n		ʣ��"<<(pigcnt-illpig)<<"ֻ������Ϊû��������Ȧ�л�������Ҵ�\n"; 
	getchar();
	if(getchar()){
	system("cls");
	}
}
