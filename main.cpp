#include <iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cctype>
#include<conio.h>
#include<malloc.h>
#include"AVLTree.h" 
#include"io.h"
#include"interface.h"
#include"graph.h"
#include<windows.h>
int main()
{
	MessageBox(0,"hi!!!!!!!!!\n!!!!!!!!!!!\n!!!!!!!!!!!\n!!!!!!!!!!!\n!!!!!!!!!!!\n!!!!!!!!!!!\n","AirLineSystem",0);
	AVLTree t;
	char main,choice,choice1,color;
	int id=1,year,mon,date,hour,min,price,did,gid,gid2;
	char source,destination,buffer;
	resetGraph();
	resetVisit();
	system("color 01");
	printf("                    Welcome to the AirLine Booking system!\n");
	printf("                        Press any key to the main menu!\n");
	color=getch();
	while(main!='E')
	{
		system("cls");
		system("color 07");
  		main_menu();
    	main = toupper(getch());//��С���D����
    	fflush(stdin);//���ݔ�뾏�n�^���_������ݔ��Ĕ�������Ӱ� 
    	switch(main)
    	{
    		//�������x�񺽿չ�˾ 
    		case 'A':
    			{
    				while(choice!='E')
    				{
	    				system("cls");
	    				airLine_menu();
	    				choice=toupper(getch());
	    				switch(choice)
	    				{
	    					case 'A':
	    						{
	    							printf("           ݔ�뺽���r�g��Ϣ(��ʽ��2016-5-20-23-55)\n");
	    							scanf("%d-%d-%d-%d-%d",&year,&mon,&date,&hour,&min);
	    							while(!isValidDate(year,mon,date,hour,min))
									{
										printf("wrong input!please try again!\n");
										scanf("%d-%d-%d-%d-%d",&year,&mon,&date,&hour,&min);
									} 
	    							printf("           ݔ�뺽��Ʊ�r��\n");
	    							scanf("%d",&price);
	    							buffer=getchar();
	    							printf("           ����ݔ�뺽����ʼ���c��\n");
	    							//gets(source);
	    							cin>>source;	    							
	    							while(!isalpha(source))
	    							{
	    								printf("wrong input!please try again!\n");
	    								cin>>source;
	    							}
	    							gid=searchGraphID(source);
	    							cout<<"gid="<<gid<<endl;
	    							printf("           ����ݔ�뺽�ཱུ����c��\n");
	    							cin>>destination;	    							
	    							while(!isalpha(destination))
	    							{
	    								printf("wrong input!please try again!\n");
	    								cin>>destination;
	    							}
	    							gid2=searchGraphID(destination);
	    							cout<<"gid="<<gid2<<endl; 
	    							setGraph(gid,gid2);
	    							t.T=t.Insert(t.T,id,year,mon,date,hour,min,source,destination,price);
	    							++id;
	    							back(); 
	    							break;
	    						}
	    					case 'B':
	    						{
	    							printf("           ݔ�����h���ĺ����id��\n");
	    							scanf("%d",&did);
	    							t.ReturnPriceToDeleteFunction(t.T,did,&price);
	    							t.T=t.deleteAirLine(t.T,did,price);
	    							printf("           �фh����");
	    							back();
	    							break;
	    						}
	    					case 'E':
	    						{
	    							break;
	    						}
	    					default :
	    						{
	    							wrong_input();
	    							break;
	    						}
	    				}
    				}
    				//back();
    				choice='\0';
	    			break;
    			}
    		//�������x���Ñ� 
    		case 'B':
				{
					while(choice1!='E')
					{
						system("cls");
						user_menu();
						choice1=toupper(getch());
						switch(choice1)
						{
							//�@ʾ���к��ࣨ�r��͵��ߣ�
							 case 'A':
							 	{	
							 		t.PrintWithLDR(t.T);
							 		back();
									break;
							 	}
							//�@ʾ���к��ࣨ�r��ߵ��ͣ�
							 case 'B':
							 	{
							 		t.PrintWithRDL(t.T);
							 		back();
									break;
							 	}
							//�����ڲ��Һ���  
							case 'C':
								{
									printf("           ݔ�����ь�֮��������(��ʽ��2016-5-20)\n");
									scanf("%d-%d-%d",&year,&mon,&date); 
									t.FindAirLineWithDate(t.T,t.T,year,mon,date);
									t.is_Found();
									back();
									break;	
								}
							//�����c���ҕr�g 
							case 'D':
								{
									printf("           Ӣ��ݔ�����ь�֮������ʼ���c��\n");
									cin>>source;
									gid=searchGraphID(source);
	    							printf("           Ӣ��ݔ�����ь�֮���ཱུ����c��\n");
	    							cin>>destination;
	    							gid2=searchGraphID(destination);
	    							t.FindAirlineWithSourceAndDestination(t.T,t.T,source,destination);
	    							t.is_Found();
	    							cout<<"           �������_��Ŀ�ĵص�·����\n";
									findWay(gid,gid2);
									back();
									break;
								}
							case 'E':
								{
									break;
								}
						}
					}
					//break;
					choice1='\0';
					break;
				} 
			//�˳�ϵ�y 
			case 'E': 
				{
					t.T=t.FreeTree(t.T);
					//back();
					break;
				} 
			default : 
				{
					wrong_input();
					break;
				}
    	}
	}
	system("pause");
	return 0; 
}


