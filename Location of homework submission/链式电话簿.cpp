#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char DataType;
typedef struct abc{    //ͨѶ¼������� 
        char name[20]; //��ϵ������ 
        char number[12]; //��ϵ�˵绰���� 
}Data; //����ṹ���� 

typedef struct Node{ //���Ա�ĵ�����洢�ṹ 
	Data data;      		//��������� 
    struct  Node *next;   //���ָ���� 
}LNode,*LinkList;   //LinkList�ȼ���struct Node * 
 
void create_peo(LinkList &L,int n);  //���������� 
int insert_peo(LinkList &L,int i,LinkList &s);  //���������Ϣ 
bool delete_peo(LNode *L,int pos);  //ɾ��������Ϣ 
void print_peo(LinkList &L);   //��ӡ 
void exit_system();  //�˳�����

int main()
{
	int choice;
	int n,i,j;
	LinkList p=NULL;
	LinkList L,s,e;
	while(1)
	{
		printf("     ͨѶ¼����ϵͳ  \n");
  		printf("===================\n");
  		printf("    1.ͨѶ����Ľ���\n");
  		printf("    2.ͨѶ�߽��Ĳ���\n");
  		printf("    3.ͨѶ�߽���ɾ��\n");
  		printf("    4.ͨѶ¼��������\n");
  		printf("    0.�˳�����ϵͳ\n");
                                printf(" ����333333333333");
  		printf("==========================\n");
  		printf("    ��  ѡ �� 0-4�� ");
	    scanf("%d",&choice);
	    switch(choice) 
	    {
		case 1:
			printf("�������봴��������������");
			scanf("%d",&n); 
		    create_peo(L,n);
		    break;
		case 2:
			printf("��������Ҫ�����λ�ã�");
            scanf("%d",&i); 
		    insert_peo(L,i,s); 
		    break;
		case 3:
    		printf("��������ɾ����λ�ã�"); 
    		scanf("%d",&i);
    		int d;
			d=delete_peo(L,i);
			if(d==0)
        	printf("�������Ԫ��λ�ó����˽��ޣ�\n\n");
        	else
        	printf("�Ѿ��ɹ�ɾ���˸�Ԫ�أ�\n\n"); 
			break;
		case 4:
			print_peo(L);
			break;
		case 0:
			exit_system();
			break;	
		default:printf("�����������������룺\n");
		    break;	
	    }
    }
	return 0;
} 

void create_peo(LinkList &L,int n)
{
	//��λ������ n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L 
	LinkList p;
	int i;
	L=(LinkList)malloc(sizeof(LNode));
	if(NULL==L)
	{
		printf("�����ڴ�ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	
	L->next=NULL;  //�Ƚ���һ����ͷ���ĵ����� 
	for(i=n;i>0;--i)
	{
		p=(LinkList)malloc(sizeof(LNode));  //�����½�� 
		printf("��������ϵ��������");
		scanf("%s",p->data.name);
		printf("��������ϵ�˵绰���룺");
		scanf("%s",p->data.number);  //����Ԫ��ֵ 
		p->next=L->next;
		L->next=p;  //���뵽��ͷ 
	}
} //create_L 

int insert_peo(LinkList &L,int i,LinkList &s)
{  //�ڴ�ͷ���ĵ������Ա� L�е�i��λ��֮ǰ����Ԫ�� e 
	LinkList p=L;
    int j=0;
    while(p&&j<i-1)
    {
    	p=p->next;
    	++j;
	} //Ѱ�ҵ� i-1����� 
    if(!p||j>i-1)
	{
        printf("����λ�ò��Ϸ�!");
        exit (1);
    }
    else
	{
        s=(LinkList)malloc(sizeof(LNode));  //�����½�� 
        printf("��������Ҫ�������ϵ��������");
        scanf("%s",s->data.name);
        printf("��������Ҫ�������ϵ�˵绰��");
        scanf("%s",s->data.number);
        s->next=p->next;  //���� L�� 
        p->next=s;
        printf("������ӳɹ�!\n");
    }
    return 1;
}

bool delete_peo(LNode *L,int pos){//ɾ����i�����
    int i = 1;
	LNode *p,*q;
    p = L;
    
    if(L->next==NULL) /*LΪ�ձ��޽���ɾ��*/
    {
        printf("�ձ��޷�����ɾ��!\n");
        
    }
    while(p->next!=NULL&&i<pos)
    {
        p = p->next;
        i++;
    }
    if(p->next==NULL)
        /*��û�е�i����㣬��ɾ������ʧ��*/
    {
        printf("���%d������\n",pos);
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
    printf("�˳���.....\n");
    system("pause");
    exit(0);
}

void print_peo(LinkList &L)
{//��ӡ
    LinkList p;
    p=L;
    printf("����\t�绰\n\n");
    while(p->next!=NULL){
        p=p->next;
        printf("%s\t%s\n",p->data.name,p->data.number);
    }
}

