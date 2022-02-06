#include"AVLTree.h"
#include<cstdio>
#include<cstdlib>
#include<malloc.h>
#include <memory>
#include<cstring>
AVLTree::AVLTree()
{
	T=NULL;
}
int AVLTree::Max(int a,int b)
{
	return(a>b)?a:b;
}
int AVLTree::height(Position p)
{
	if(p==NULL)
		return -1;
	else
		return p->height;
}
//�������D 
Position AVLTree::LL_Rotation(Position k2)
{
	Position k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	k2->height=Max(height(k2->left),height(k2->right))+1;
	k1->height=Max(height(k1->left),k2->height)+1;
	return k1;
}
//�������D 
Position AVLTree::RR_Rotation(Position k2)
{
	Position k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	k2->height=Max(height(k2->left),height(k2->right))+1;
	k1->height=Max(height(k1->right),k2->height)+1;
	return k1;
}
//�������D 
Position AVLTree::LR_Rotation(Position k2)
{
	k2->left=RR_Rotation(k2->left);
	return LL_Rotation(k2);
}
//�������D 
Position AVLTree::RL_Rotation(Position k2)
{
	k2->right=LL_Rotation(k2->right);
	return RR_Rotation(k2);
}
//��С������ӡ 
void AVLTree::PrintWithLDR(Tree t)
{
		if(t!=NULL)
	{
		PrintWithLDR(t->left);
		printf("%20d:%d-%d-%d-%d-%d from %c to %c cost %d$\n",t->id,t->year,t->mon,t->date,t->hour,t->min,t->source,t->destination,t->price);
		printf("          ------------------------------------------------------------\n");
		PrintWithLDR(t->right);
	}
}
//�Ĵ�С��ӡ 
void AVLTree::PrintWithRDL(Tree t)
{
		if(t!=NULL)
	{
		PrintWithRDL(t->right);
		printf("%20d:%d-%d-%d-%d-%d from %c to %c cost %d$\n",t->id,t->year,t->mon,t->date,t->hour,t->min,t->source,t->destination,t->price);
		printf("          ------------------------------------------------------------\n");
		PrintWithRDL(t->left);
	}	
}
//���� 
Tree AVLTree::Insert(Tree t,int id,int year,int mon,int date,int hour,int min,char source,char destination,int price)
{
	if(t==NULL)
	{
		t=(Tree)malloc(sizeof(struct TreeNode));
		t->id=id;
		t->year=year;
		t->mon=mon;
		t->date=date;
		t->hour=hour;
		t->min=min;
		t->source=source;
		t->destination=destination;
		t->price=price;
		t->left=NULL;
		t->right=NULL;
		t->height=0;
		printf("��Ӻ�����Ϣ���£�%d:%d-%d-%d-%d-%d from %c to %c cost %d$\n",t->id,t->year,t->mon,t->date,t->hour,t->min,t->source,t->destination,t->price);
	}
	else if(price<t->price)
	{
		t->left=Insert(t->left,id,year,mon,date,hour,min,source,destination,price);
		if(height(t->left)-height(t->right)==2)
		{
			if(price<t->left->price)
				t=LL_Rotation(t);
			else
				t=LR_Rotation(t);
		} 
	}
	else if(price>=t->price)
	{
		t->right=Insert(t->right,id,year,mon,date,hour,min,source,destination,price);
		if(height(t->right)-height(t->left)==2)
		{
			if(price>=t->right->price)
				t=RR_Rotation(t);
			else
				t=RL_Rotation(t);
		}
	}
	t->height=Max(height(t->left),height(t->right));
	return t;
}
void AVLTree::is_Found()
{
	isFound=0;
}
//ݔ����ʼ�غ�Ŀ�ĵز��Һ��� 
void AVLTree::FindAirlineWithSourceAndDestination(Tree t,Tree p,char source,char destination)
{
	if(t!=NULL)
	{
		if((source==t->source)&&(destination==t->destination))
		{
			printf("%20d:%d-%d-%d-%d-%d from %c to %c cost %d\n",t->id,t->year,t->mon,t->date,t->hour,t->min,t->source,t->destination,t->price);
			printf("          ------------------------------------------------------------\n");
			isFound=1;
		}			
		FindAirlineWithSourceAndDestination(t->left,p,source,destination);
		FindAirlineWithSourceAndDestination(t->right,p,source,destination);
		if(t==p&&isFound==0)
			printf("No find!!");	
	}
}
//ݔ�뺽�����ڲ��Һ��� 
void AVLTree::FindAirLineWithDate(Tree t,Tree p,int year,int mon,int date)
{
	if(t!=NULL)
	{
		if(year==t->year&&mon==t->mon&&date==t->date)
		{
			printf("%20d:%d-%d-%d-%d-%d from %c to %c cost %d$\n",t->id,t->year,t->mon,t->date,t->hour,t->min,t->source,t->destination,t->price);
			printf("          ------------------------------------------------------------\n");
			isFound=1;
		}
		FindAirLineWithDate(t->left,p,year,mon,date);
		FindAirLineWithDate(t->right,p,year,mon,date);
		if(t==p&&isFound==0)
			printf("No find!");
	} 
}
void AVLTree::ReturnPriceToDeleteFunction(Tree t,int did,int *price)
{
	if(t!=NULL)
	{
		if(did==t->id)
		{
			*price=t->price;
			return;
		}
		ReturnPriceToDeleteFunction(t->left,did,price);
		ReturnPriceToDeleteFunction(t->right,did,price);
	}
}
//����߅�Ĺ��c 
Tree AVLTree::AvlTreeMinimum(Tree t)
{
	if(t==NULL)
		return NULL;
	while(t->left!=NULL)
		t=t->left;
	return t;
}
//����߅�Ĺ��c 
Tree AVLTree::AvlTreeMaximum(Tree t)
{
	if(t==NULL)
		return NULL;
	while(t->right!=NULL)
		t=t->right;
	return t;
}
//�h�����c 
Tree AVLTree::deleteAirLine(Tree t,int id,int price)
{
	//�����ջ��ߛ]��Ҫ�h���Ĺ��c������NULL 
	if(t==NULL)
		return NULL;
	//���h���Ĺ��c��Tree�����Ә��� 
	if(price<t->price)
	{
		t->left=deleteAirLine(t->left,id,price);
		//�h�����c�ᣬ��Treeʧȥƽ�⣬�t�M���������{��		
		if(height(t->right)-height(t->left)==2)
		{
			Position r=t->right;
			if(height(r->left)>height(r->right))
				t=RL_Rotation(t);
			else
				t=RR_Rotation(t);
		}
	}
	//�r������ྎ̖����ͬ���t�Ǵ��h���Ĺ��c
	/*���Д��Ƿ���ͬ�����Д��Ƿ�>=�����ڲ������O���ɂ���ͬ�ăr��
	���������Ȳ�������Ә��У�������Ƿ��Д�>=���Ҳ������h���Ĺ��c*/ 
	else if((price==t->price)&&(id=t->id))
	{
		//Tree�������Ә䶼�ǿ� 
		if((t->left)&&(t->right))
		{
			// ���tree�����Ә�����Ә�ߣ�
            // �t(01)�ҳ�tree�����Ә��е�����c
            //   (02)��ԓ����c��ֵ�xֵ�otree��
            //   (03)�h��ԓ����c��
            // �@������"tree�����Ә�������c"��"tree"������
            // �����@�N��ʽ�ĺ�̎�ǣ��h��"tree�����Ә�������c"֮�ᣬAVL����Ȼ��ƽ��ġ�
			if(height(t->left)>height(t->right))
			{
				Position max=AvlTreeMaximum(t->left);
				t->price=max->price;
				t->id=max->id;
				t->left=deleteAirLine(t->left,id,max->price);
			}
			// ���tree�����Ә䲻�����Ә��(��������ȣ������Ә�����Ә��1)
            // �t(01)�ҳ�tree�����Ә��е���С���c
            //   (02)��ԓ��С���c��ֵ�xֵ�otree��
            //   (03)�h��ԓ��С���c��
            // �@������"tree�����Ә�����С���c"��"tree"������
            // �����@�N��ʽ�ĺ�̎�ǣ��h��"tree�����Ә�����С���c"֮�ᣬAVL����Ȼ��ƽ��ġ�
			else
			{
				Position min=AvlTreeMinimum(t->right);
				t->price=min->price;
				t->id=min->id;
				t->right=deleteAirLine(t->right,id,min->price);
			}
		}
		//Tree�����Ә�����Ә��]���Ә� 
		else
		{
			Position tmp=t;
			t=t->left?t->left:t->right;
			free(tmp); 
		}
		return t;
	}
	//���h���Ĺ��c��Tree�����Ә��� 
	else if(price>=t->price)
	{
		t->right=deleteAirLine(t->right,id,price);
		if(height(t->left)-height(t->right)==2)
		{
			Position l;
			if(height(l->right)>height(l->left))
				t=LR_Rotation(t);
			else
				t=LL_Rotation(t); 
		}
	}		
	t->height=Max(height(t->left),height(t->right))+1; 	
}
//�h���� 
Tree AVLTree::FreeTree(Tree t)
{
	if(t!=NULL)
	{
		FreeTree(t->left);
		FreeTree(t->right);
		free(t);
	}
	return NULL;
} 
