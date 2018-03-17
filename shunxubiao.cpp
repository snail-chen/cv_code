#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 100
#define DataType int
DataType data[MAXSIZE];
int length;
typedef struct node//定义顺序表类型 
{
	DataType data[MAXSIZE];
	int length;
 } SeqList,*PSeqList;
PSeqList init_Seq(void)//初始化 
 {
 	PSeqList palist;
    palist=(PSeqList)malloc(sizeof(SeqList));
    if(palist)
    	palist->length=0;
    return(palist);
 }
 int Insert_Seqt(PSeqList palist,int i,DataType x)//插入
 {
 	int j;
	if(!palist)
	{
		printf("表不存在");
		return(-2);
	}
	if(palist->length>=MAXSIZE)
	{
		printf("表溢出");
 	    return(-1);
	}
    if(i<1||i>palist->length+1)
	{
		printf("插入位置不合法");
		return(0);
	}
	for(j=palist->length-1;j>=i-1;j--)
		palist->data[j+1]=palist->data[j];
	palist->data[i-1]=x;
	palist->length++;
	return (1);
 } 
 int deleteV_seq( PSeqList palist , int x)//删除 
 {
	int i=1,j;
	if (!palist)
	{
		printf("表不存在");
		return(-1);
	}
	while(palist->data[i]!=x)
	{
		i++;
	}
	if(i<1||i>palist->length)
	{
		printf("删除位置不合法");
		return(0);
	}
	for(j=1;j<palist->length;j++)
		palist->data[j-1]=palist->data[j];
	palist->length--;
	return(1);
}
 int main()//主函数
 {
 	int x,i,y;
 	i=1;
 	PSeqList palist;
 	palist=init_Seq();
 	printf("请输入一组数\n");
	 scanf("%d",&x);
	 Insert_Seqt(palist,i,x);
	while(x)
		{
			i++;
			scanf("%d",&x);
			Insert_Seqt(palist,i,x);	
		}
 	printf("请输入x\n");
 	scanf("%d",&x);
    y=deleteV_seq(palist,x);
    if(y==1)
    	printf("删除成功");
    else
    	printf("删除失败");
 	 return 0;
 }
