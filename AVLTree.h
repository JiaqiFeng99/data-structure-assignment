#ifndef _AVLTREE_H_
#define _AVLTREE_H_
static int isFound=0;
typedef struct TreeNode
{
	int id;
	int year;
	int mon;
	int date;
	int hour;
	int min;
	char source;
	char destination;
	int price;
	struct TreeNode *left;
	struct TreeNode *right;
	int height;
}*Tree,*Position;
class AVLTree
{
	private:
		int Max(int,int);
		int height(Position);
		Position LL_Rotation(Position);
		Position RR_Rotation(Position);
		Position LR_Rotation(Position);
		Position RL_Rotation(Position);
	public:
		Tree T;
		AVLTree();
		void PrintWithLDR(Tree);//由小到大遍歷
		void PrintWithRDL(Tree);//由大到小遍歷
		Tree Insert(Tree,int,int,int,int,int,int,char,char,int);
		void is_Found();
		void FindAirlineWithSourceAndDestination(Tree,Tree,char,char);
		void FindAirLineWithDate(Tree,Tree,int,int,int);
		void ReturnPriceToDeleteFunction(Tree,int,int *);
		Tree AvlTreeMinimum(Tree);
		Tree AvlTreeMaximum(Tree);
		Tree deleteAirLine(Tree,int,int);
		Tree FreeTree(Tree);
};
#endif
