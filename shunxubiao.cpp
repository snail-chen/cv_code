#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100
#define DataType int
DataType data[MAXSIZE];
int length;
typedef struct node//����˳������� 
{
	DataType data[MAXSIZE];
	int length;
 } SeqList,*PSeqList;
PSeqList init_Seq(void)//��ʼ�� 
 {
 	PSeqList palist;
    palist=(PSeqList)malloc(sizeof(SeqList));
    if(palist)
    	palist->length=0;
    return(palist);
 }
 int Insert_Seqt(PSeqList palist,int i,DataType x)//����
 {
 	int j;
	if(!palist)
	{
		printf("������");
		return(-2);
	}
	if(palist->length>=MAXSIZE)
	{
		printf("�����");
 	    return(-1);
	}
    if(i<1||i>palist->length+1)
	{
		printf("����λ�ò��Ϸ�");
		return(0);
	}
	for(j=palist->length-1;j>=i-1;j--)
		palist->data[j+1]=palist->data[j];
	palist->data[i-1]=x;
	palist->length++;
	return (1);
 } 
 int deleteV_seq( PSeqList palist , int x)//ɾ�� 
 {
	int i=1,j;
	if (!palist)
	{
		printf("������");
		return(-1);
	}
	while(palist->data[i]!=x)
	{
		i++;
	}
	if(i<1||i>palist->length)
	{
		printf("ɾ��λ�ò��Ϸ�");
		return(0);
	}
	for(j=1;j<palist->length;j++)
		palist->data[j-1]=palist->data[j];
	palist->length--;
	return(1);
}
 int main()//������
 {
 	int x,i,y;
 	i=1;
 	PSeqList palist;
 	palist=init_Seq();
 	printf("������һ����\n");
	 scanf("%d",&x);
	 Insert_Seqt(palist,i,x);
	while(x)
		{
			i++;
			scanf("%d",&x);
			Insert_Seqt(palist,i,x);	
		}
 	printf("������x\n");
 	scanf("%d",&x);
    y=deleteV_seq(palist,x);
    if(y==1)
    	printf("ɾ���ɹ�");
    else
    	printf("ɾ��ʧ��");
 	 return 0;
 }
