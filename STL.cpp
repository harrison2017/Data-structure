//���顢 ���������� ���С� ջ������ 
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include <vector>  //�������� 
#include <queue>   // ����
#include <stack>   //ջ 

using namespace std;
using std::setw;  //��ʾ�ո� 

void show(int arr[], int num){
	//��ʾ���� 
	cout << "Element" << setw( 13 ) << "Value" << endl;           
	for ( int j = 0; j < num; j++ ){
		cout << setw( 7 )<< j << setw( 13 ) << arr[ j ] << endl;
	}	
}

void show(vector<int>arr, int num){  //�������� 
	//��ʾ���� 
	cout << "Element" << setw( 13 ) << "Value" << endl;           
	for ( int j = 0; j < num; j++ ){
		cout << setw( 7 )<< j << setw( 13 ) << arr[ j ] << endl;
	}	
}


void shuzu_1(int num){
	//�������鶨�� 
	int arr[num];   
   	for ( int i = 0; i < num; i++ ){
    	arr[ i ] = i + 100; 
   	}
	show(arr, num);
}

void shuzu_2(int num){
	//vector  ��������
	 vector<int>arr;
	 
	for(int i=0; i<num; i++) { // push_back(elem)���������������� 
        arr.push_back(i);  	 
    }
	
	if (!arr.empty()){  		  //�жϷǿ� 
		for(int i=0; i<2; i++){   //ȥ����������������� 
        	arr.pop_back();
    	}
	}
	
	arr.insert(arr.begin() + 5, 666); //����Ԫ��,��֧������ 
	arr.erase (arr.begin() + 6); 	  //ɾ��Ԫ��,��֧������ 
	
    int len = arr.size();
    show(arr, len);
    
    cout<<"��Ԫ�أ� " << arr.front() <<"  βԪ�أ� "<< arr.back() << endl; //��Ԫ�ء�βԪ�� 
    
    //arr.begin()  arr.end()  Ϊȡarr����Ԫ�ء�βԪ�ص�ַ����itָ�������ַ
	vector<int>::iterator it =  arr.begin();
	for(int j=0; j<len; j++)
		cout<< *(it + j) <<endl;
		
}

void shuzu_3(int num){
	queue<int> arr;     	//����,�Ƚ��ȳ� 
	for(int i=0; i<num; i++){
	    arr.push(i);	
	}


	int len = arr.size();   //size()���гߴ��С 
    cout << "������Ԫ��: " << arr.front() <<endl;
    cout << "����βԪ��: " << arr.back() <<endl;
    
    while (!arr.empty()){  		  //�жϷǿ� 
		for(int i=0; i<len; i++){    
			int t = arr.front();
			cout << t <<endl;
        	arr.pop();			 //ȥ����Ԫ��	  
    	}
	}

} 

void shuzu_4(int num){
	//ջ(stack)     �Ƚ���� 
	stack<int> arr;
	for(int i=0; i<num; i++){
	    arr.push(i);	
	}
	
	if (!arr.empty()){  		  // empty() �жϷǿ� 
		for(int i=0; i<2; i++){    
        	arr.pop();			  // pop() ȥջ��Ԫ�� (�����ջԪ��) 
    	}
	}
	
	int len = arr.size();   	 // size()��С
	
	cout <<  "ջ��Ԫ��: " << arr.top() << endl;
	
	while (!arr.empty()){  		  //�жϷǿ� 
		for(int i=0; i<len; i++){    
			int t = arr.top();
			cout << t <<endl;
        	arr.pop();			 //ȥ����Ԫ��	  
    	}
	}
	
} 


void lianbiao(int num){ //��̬���� 
	struct node{
		int data;	//���� 
		node* next;	//��һ�ڵ��ַ 
	};
	
	node *head = new node; //����ͷ�ڵ� 
	head->next = NULL;       //ͷ�ڵ�����ָ����   �ṹ��ָ������ ��->��ȡ 
	
	node *pre = head;				//��¼preΪhead 
	//���
	for(int i=0; i<num; i++){
		node *p = new node;	//�½��ڵ� 
		p->data = i;		//��������� 
		p->next = NULL;		//�½ڵ��ָ������ΪNULL 
		
		pre->next = p;  	//��ǰ�����ڵ���Ϊ��Ǯ�½��ڵ�ĵ�ַ
		pre = p;			//��pre��Ϊp,��Ϊ�¸��ڵ��ǰ���ڵ� 
		
	} //����head ͷ�ڵ�ָ��  ����ʹ��pre 
	
	//���� ����Ԫ�� 
	node *pret = head; 
	node *t = head->next; //�ӵ�һ���ڵ㿪ʼ�������� 
	while(t != NULL){
		
	 	//����Ԫ�� 
	 	if(t->data == 8){
			node *temp = new node; //�½��ڵ� 
			temp->data = 666;
			
			temp->next = t->next; //�½ڵ�ָ��ԭ�ڵ����λ�ýڵ� 
			t->next = temp;		  //ǰλ�ýڵ�ָ���½ڵ� 
		}
 	
	 	//ɾ��Ԫ��
	 	if(t->data == 10){
	 		pret->next = t->next;
	 		delete(t);
	 		
	 		t =pret->next;
	 	} 
	 	
	 	cout<< t->data <<endl; 	//��ӡ���� 
	 	t = t->next;   			//���� 
	 	pret = pret->next; 
 	} 
		 
}

//void lianbiao_2(int num){//��̬���� 
//	struct node{
//		int data;
//		int next;
//	}node[size];
//} 

int main ()
{	
	int num = 15;
	 
//	shuzu_1(num); 
	shuzu_2(num);
//	shuzu_3(num);
//	shuzu_4(num); 
//	lianbiao(num);
//	lianbiao_2(num);
	
	return 0;
}
