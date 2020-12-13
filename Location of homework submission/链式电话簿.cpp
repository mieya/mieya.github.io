#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char DataType;
typedef struct abc{    //通讯录结点类型 
        char name[20]; //联系人姓名 
        char number[12]; //联系人电话号码 
}Data; //定义结构变量 

typedef struct Node{ //线性表的单链表存储结构 
	Data data;      		//结点数据域 
    struct  Node *next;   //结点指针域 
}LNode,*LinkList;   //LinkList等价于struct Node * 
 
void create_peo(LinkList &L,int n);  //创建单链表 
int insert_peo(LinkList &L,int i,LinkList &s);  //插入个人信息 
bool delete_peo(LNode *L,int pos);  //删除个人信息 
void print_peo(LinkList &L);   //打印 
void exit_system();  //退出程序

int main()
{
	int choice;
	int n,i,j;
	LinkList p=NULL;
	LinkList L,s,e;
	while(1)
	{
		printf("     通讯录管理系统  \n");
  		printf("===================\n");
  		printf("    1.通讯链表的建立\n");
  		printf("    2.通讯者结点的插入\n");
  		printf("    3.通讯者结点的删除\n");
  		printf("    4.通讯录链表的输出\n");
  		printf("    0.退出管理系统\n");
                                printf(" 董飞333333333333");
  		printf("==========================\n");
  		printf("    请  选 择 0-4： ");
	    scanf("%d",&choice);
	    switch(choice) 
	    {
		case 1:
			printf("输入你想创建的数据组数：");
			scanf("%d",&n); 
		    create_peo(L,n);
		    break;
		case 2:
			printf("请输入需要插入的位置：");
            scanf("%d",&i); 
		    insert_peo(L,i,s); 
		    break;
		case 3:
    		printf("输入你想删除的位置："); 
    		scanf("%d",&i);
    		int d;
			d=delete_peo(L,i);
			if(d==0)
        	printf("您输入的元素位置超出了界限！\n\n");
        	else
        	printf("已经成功删除了该元素！\n\n"); 
			break;
		case 4:
			print_peo(L);
			break;
		case 0:
			exit_system();
			break;	
		default:printf("输入有误，请重新输入：\n");
		    break;	
	    }
    }
	return 0;
} 

void create_peo(LinkList &L,int n)
{
	//逆位序输入 n个元素的值，建立带表头结点的单链线性表L 
	LinkList p;
	int i;
	L=(LinkList)malloc(sizeof(LNode));
	if(NULL==L)
	{
		printf("分配内存失败，程序终止！\n");
		exit(-1);
	}
	
	L->next=NULL;  //先建立一个带头结点的单链表 
	for(i=n;i>0;--i)
	{
		p=(LinkList)malloc(sizeof(LNode));  //生成新结点 
		printf("请输入联系人姓名：");
		scanf("%s",p->data.name);
		printf("请输入联系人电话号码：");
		scanf("%s",p->data.number);  //输入元素值 
		p->next=L->next;
		L->next=p;  //插入到表头 
	}
} //create_L 

int insert_peo(LinkList &L,int i,LinkList &s)
{  //在带头结点的单链线性表 L中第i个位置之前插入元素 e 
	LinkList p=L;
    int j=0;
    while(p&&j<i-1)
    {
    	p=p->next;
    	++j;
	} //寻找第 i-1个结点 
    if(!p||j>i-1)
	{
        printf("插入位置不合法!");
        exit (1);
    }
    else
	{
        s=(LinkList)malloc(sizeof(LNode));  //生成新结点 
        printf("请输入需要插入的联系人姓名：");
        scanf("%s",s->data.name);
        printf("请输入需要插入的联系人电话：");
        scanf("%s",s->data.number);
        s->next=p->next;  //插入 L中 
        p->next=s;
        printf("您已添加成功!\n");
    }
    return 1;
}

bool delete_peo(LNode *L,int pos){//删除第i个结点
    int i = 1;
	LNode *p,*q;
    p = L;
    
    if(L->next==NULL) /*L为空表，无结点可删除*/
    {
        printf("空表无法进行删除!\n");
        
    }
    while(p->next!=NULL&&i<pos)
    {
        p = p->next;
        i++;
    }
    if(p->next==NULL)
        /*若没有第i个结点，则删除操作失败*/
    {
        printf("结点%d不存在\n",pos);
        return false;
    }
    else
    {
        q = p->next;
        p->next = p->next->next;
        free(q);
        return true;
    }
}

void exit_system()
{
    printf("退出中.....\n");
    system("pause");
    exit(0);
}

void print_peo(LinkList &L)
{//打印
    LinkList p;
    p=L;
    printf("姓名\t电话\n\n");
    while(p->next!=NULL){
        p=p->next;
        printf("%s\t%s\n",p->data.name,p->data.number);
    }
}

