//数组、 向量容器、 队列、 栈、链表 
#include <iostream>
#include <iomanip>
#include <cstdlib>

#include <vector>  //向量容器 
#include <queue>   // 队列
#include <stack>   //栈 

using namespace std;
using std::setw;  //显示空格 

void show(int arr[], int num){
	//显示数组 
	cout << "Element" << setw( 13 ) << "Value" << endl;           
	for ( int j = 0; j < num; j++ ){
		cout << setw( 7 )<< j << setw( 13 ) << arr[ j ] << endl;
	}	
}

void show(vector<int>arr, int num){  //函数重载 
	//显示数组 
	cout << "Element" << setw( 13 ) << "Value" << endl;           
	for ( int j = 0; j < num; j++ ){
		cout << setw( 7 )<< j << setw( 13 ) << arr[ j ] << endl;
	}	
}


void shuzu_1(int num){
	//常规数组定义 
	int arr[num];   
   	for ( int i = 0; i < num; i++ ){
    	arr[ i ] = i + 100; 
   	}
	show(arr, num);
}

void shuzu_2(int num){
	//vector  向量容器
	 vector<int>arr;
	 
	for(int i=0; i<num; i++) { // push_back(elem)在数组最后添加数据 
        arr.push_back(i);  	 
    }
	
	if (!arr.empty()){  		  //判断非空 
		for(int i=0; i<2; i++){   //去掉数组最后两个数据 
        	arr.pop_back();
    	}
	}
	
	arr.insert(arr.begin() + 5, 666); //插入元素,不支持索引 
	arr.erase (arr.begin() + 6); 	  //删除元素,不支持索引 
	
    int len = arr.size();
    show(arr, len);
    
    cout<<"首元素： " << arr.front() <<"  尾元素： "<< arr.back() << endl; //首元素、尾元素 
    
    //arr.begin()  arr.end()  为取arr的首元素、尾元素地址，而it指向这个地址
	vector<int>::iterator it =  arr.begin();
	for(int j=0; j<len; j++)
		cout<< *(it + j) <<endl;
		
}

void shuzu_3(int num){
	queue<int> arr;     	//队列,先进先出 
	for(int i=0; i<num; i++){
	    arr.push(i);	
	}


	int len = arr.size();   //size()队列尺寸大小 
    cout << "队列首元素: " << arr.front() <<endl;
    cout << "队列尾元素: " << arr.back() <<endl;
    
    while (!arr.empty()){  		  //判断非空 
		for(int i=0; i<len; i++){    
			int t = arr.front();
			cout << t <<endl;
        	arr.pop();			 //去掉首元素	  
    	}
	}

} 

void shuzu_4(int num){
	//栈(stack)     先进后出 
	stack<int> arr;
	for(int i=0; i<num; i++){
	    arr.push(i);	
	}
	
	if (!arr.empty()){  		  // empty() 判断非空 
		for(int i=0; i<2; i++){    
        	arr.pop();			  // pop() 去栈顶元素 (最后入栈元素) 
    	}
	}
	
	int len = arr.size();   	 // size()大小
	
	cout <<  "栈顶元素: " << arr.top() << endl;
	
	while (!arr.empty()){  		  //判断非空 
		for(int i=0; i<len; i++){    
			int t = arr.top();
			cout << t <<endl;
        	arr.pop();			 //去掉首元素	  
    	}
	}
	
} 


void lianbiao(int num){ //动态链表 
	struct node{
		int data;	//数据 
		node* next;	//下一节点地址 
	};
	
	node *head = new node; //创建头节点 
	head->next = NULL;       //头节点无需指针域   结构体指针类型 用->读取 
	
	node *pre = head;				//记录pre为head 
	//填充
	for(int i=0; i<num; i++){
		node *p = new node;	//新建节点 
		p->data = i;		//数据域填充 
		p->next = NULL;		//新节点的指针域设为NULL 
		
		pre->next = p;  	//将前驱动节点设为但钱新建节点的地址
		pre = p;			//把pre设为p,作为下个节点的前驱节点 
		
	} //返回head 头节点指针  不能使用pre 
	
	//遍历 插入元素 
	node *pret = head; 
	node *t = head->next; //从第一个节点开始有数据域 
	while(t != NULL){
		
	 	//插入元素 
	 	if(t->data == 8){
			node *temp = new node; //新建节点 
			temp->data = 666;
			
			temp->next = t->next; //新节点指向原节点插入位置节点 
			t->next = temp;		  //前位置节点指向新节点 
		}
 	
	 	//删除元素
	 	if(t->data == 10){
	 		pret->next = t->next;
	 		delete(t);
	 		
	 		t =pret->next;
	 	} 
	 	
	 	cout<< t->data <<endl; 	//打印数据 
	 	t = t->next;   			//遍历 
	 	pret = pret->next; 
 	} 
		 
}

//void lianbiao_2(int num){//静态链表 
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
