#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define N 10
typedef struct People
{
	char name[20];
	int age;
	struct People *next;
}People;

People *create(int n)
{
	
	People *head,*p1,*p2;
	int i=0;
	for(i=0;i<n;i++)
	{
		if((p2=(People *)malloc(sizeof(People)))==NULL)
		{
			printf("不能分配内存空间");
			exit(0);
		}
		if(i==0){
			head=p2;
			p1=head;
		}
		p1->next=p2;
		printf("输入第%d个人的姓名:",i+1);
		scanf("%s",p2->name);
		printf("输入第%d个人的年龄:",i+1);
		scanf("%d",&p2->age);
		printf("\n");
		p2->next=NULL;
		p1=p2;
			
	}
	return head;
	
}

/**
打印链表
*/
void print(People *p){
	

	People *p1=p;
	while(p1!=NULL){
		printf("名字:%s 年龄:%d",p1->name,p1->age);
		p1=p1->next;
		printf("\n");
	}
	
}
/**
插入链表
*/
void insert(People *p,int num){
	int len=getLen(p);
	int cout=0;
	People *p2;
	People *p1=(People*)malloc(sizeof(People));
	if(p1==NULL){
		exit(0);
	}
	printf("输入姓名:");
	scanf("%s",p1->name);
	printf("输入年龄:");
	scanf("%d",&p1->age);
	People *temp=p;	
	if(num>=len){//在尾部插入		
		printf("尾部插入");
		while(temp!=NULL){
			temp=temp->next;
		}
		temp->next=p1;				
	}else if(num==0){			
		p1->next=temp;
		temp=p1;	
	}else{
		while(temp!=NULL){
			cout++;
			if(cout==num){
				p2=temp->next;
				temp->next=p1;
				p1->next=p2;
				break;
			}
			temp=temp->next;
		}
	}
	p=temp;
}

/**
删除链表
*/
void delete(People *p,int num){
	
	People *temp=p;
	People *p1;
	int len=getLen(p);
	int cout=0;
	if(cout>len){
		printf("长度溢出了");
		exit(0);
	}
	while(temp!=NULL){
		cout++;
		if(cout==num){
			p1=temp->next;
			temp->next=p1->next;
			free(p1);
			p1=NULL;
			break;
		}
		temp=temp->next;
	}
	
}

int getLen(People *p){
	People *p1=p;
	int cout=0;
	while(p1!=NULL){
		cout++;
		p1=p1->next;
	}
	return cout;
}



void main(){
	
	People *p=create(3);
	print(p);
	printf("%d-->\n",getLen(p));
	insert(p,2);
	print(p);
	printf("开始删除-->\n");
	delete(p,2);
	print(p);
	
}

