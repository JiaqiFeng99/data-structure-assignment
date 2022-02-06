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
    	main = toupper(getch());//將小寫轉爲大寫
    	fflush(stdin);//清空輸入緩衝區，確保後面輸入的數據不受影響 
    	switch(main)
    	{
    		//主界面選擇航空公司 
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
	    							printf("           輸入航班時間信息(格式：2016-5-20-23-55)\n");
	    							scanf("%d-%d-%d-%d-%d",&year,&mon,&date,&hour,&min);
	    							while(!isValidDate(year,mon,date,hour,min))
									{
										printf("wrong input!please try again!\n");
										scanf("%d-%d-%d-%d-%d",&year,&mon,&date,&hour,&min);
									} 
	    							printf("           輸入航班票價：\n");
	    							scanf("%d",&price);
	    							buffer=getchar();
	    							printf("           中文輸入航班起始地點：\n");
	    							//gets(source);
	    							cin>>source;	    							
	    							while(!isalpha(source))
	    							{
	    								printf("wrong input!please try again!\n");
	    								cin>>source;
	    							}
	    							gid=searchGraphID(source);
	    							cout<<"gid="<<gid<<endl;
	    							printf("           中文輸入航班降落地點：\n");
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
	    							printf("           輸入欲刪除的航班的id：\n");
	    							scanf("%d",&did);
	    							t.ReturnPriceToDeleteFunction(t.T,did,&price);
	    							t.T=t.deleteAirLine(t.T,did,price);
	    							printf("           已刪除！");
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
    		//主界面選擇用戶 
    		case 'B':
				{
					while(choice1!='E')
					{
						system("cls");
						user_menu();
						choice1=toupper(getch());
						switch(choice1)
						{
							//顯示所有航班（價格低到高）
							 case 'A':
							 	{	
							 		t.PrintWithLDR(t.T);
							 		back();
									break;
							 	}
							//顯示所有航班（價格高到低）
							 case 'B':
							 	{
							 		t.PrintWithRDL(t.T);
							 		back();
									break;
							 	}
							//按日期查找航班  
							case 'C':
								{
									printf("           輸入欲搜尋之航班日期(格式：2016-5-20)\n");
									scanf("%d-%d-%d",&year,&mon,&date); 
									t.FindAirLineWithDate(t.T,t.T,year,mon,date);
									t.is_Found();
									back();
									break;	
								}
							//按地點查找時間 
							case 'D':
								{
									printf("           英文輸入欲搜尋之航班起始地點：\n");
									cin>>source;
									gid=searchGraphID(source);
	    							printf("           英文輸入欲搜尋之航班降落地點：\n");
	    							cin>>destination;
	    							gid2=searchGraphID(destination);
	    							t.FindAirlineWithSourceAndDestination(t.T,t.T,source,destination);
	    							t.is_Found();
	    							cout<<"           其它到達此目的地的路徑：\n";
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
			//退出系統 
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


