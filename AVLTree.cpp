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
//左左旋轉 
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
//右右旋轉 
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
//左右旋轉 
Position AVLTree::LR_Rotation(Position k2)
{
	k2->left=RR_Rotation(k2->left);
	return LL_Rotation(k2);
}
//右左旋轉 
Position AVLTree::RL_Rotation(Position k2)
{
	k2->right=LL_Rotation(k2->right);
	return RR_Rotation(k2);
}
//從小到大列印 
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
//從大到小列印 
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
//插入 
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
		printf("添加航班信息如下：%d:%d-%d-%d-%d-%d from %c to %c cost %d$\n",t->id,t->year,t->mon,t->date,t->hour,t->min,t->source,t->destination,t->price);
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
//輸入起始地和目的地查找航班 
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
//輸入航班日期查找航班 
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
//最左邊的節點 
Tree AVLTree::AvlTreeMinimum(Tree t)
{
	if(t==NULL)
		return NULL;
	while(t->left!=NULL)
		t=t->left;
	return t;
}
//最右邊的節點 
Tree AVLTree::AvlTreeMaximum(Tree t)
{
	if(t==NULL)
		return NULL;
	while(t->right!=NULL)
		t=t->right;
	return t;
}
//刪除節點 
Tree AVLTree::deleteAirLine(Tree t,int id,int price)
{
	//根爲空或者沒有要刪除的節點，返回NULL 
	if(t==NULL)
		return NULL;
	//待刪除的節點在Tree的左子樹中 
	if(price<t->price)
	{
		t->left=deleteAirLine(t->left,id,price);
		//刪除節點後，若Tree失去平衡，則進行相應的調節		
		if(height(t->right)-height(t->left)==2)
		{
			Position r=t->right;
			if(height(r->left)>height(r->right))
				t=RL_Rotation(t);
			else
				t=RR_Rotation(t);
		}
	}
	//價格跟航班編號都相同，則是待刪除的節點
	/*先判斷是否相同，再判斷是否>=是因爲在插入是設定兩個相同的價格，
	後插入的在先插入的右子樹中，如果先是否判斷>=會找不到待刪除的節點*/ 
	else if((price==t->price)&&(id=t->id))
	{
		//Tree的左右子樹都非空 
		if((t->left)&&(t->right))
		{
			// 如果tree的左子樹比右子樹高；
            // 則(01)找出tree的左子樹中的最大節點
            //   (02)將該最大節點的值賦值給tree。
            //   (03)刪除該最大節點。
            // 這類似於用"tree的左子樹中最大節點"做"tree"的替身；
            // 採用這種方式的好處是：刪除"tree的左子樹中最大節點"之後，AVL樹仍然是平衡的。
			if(height(t->left)>height(t->right))
			{
				Position max=AvlTreeMaximum(t->left);
				t->price=max->price;
				t->id=max->id;
				t->left=deleteAirLine(t->left,id,max->price);
			}
			// 如果tree的左子樹不比右子樹高(即它們相等，或右子樹比左子樹高1)
            // 則(01)找出tree的右子樹中的最小節點
            //   (02)將該最小節點的值賦值給tree。
            //   (03)刪除該最小節點。
            // 這類似於用"tree的右子樹中最小節點"做"tree"的替身；
            // 採用這種方式的好處是：刪除"tree的右子樹中最小節點"之後，AVL樹仍然是平衡的。
			else
			{
				Position min=AvlTreeMinimum(t->right);
				t->price=min->price;
				t->id=min->id;
				t->right=deleteAirLine(t->right,id,min->price);
			}
		}
		//Tree有左子樹或右子樹或沒有子樹 
		else
		{
			Position tmp=t;
			t=t->left?t->left:t->right;
			free(tmp); 
		}
		return t;
	}
	//待刪除的節點在Tree的右子樹中 
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
//刪除樹 
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
