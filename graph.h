#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<vector> 
#include<stack>
#define MAXGRAPH 50
bool graph[MAXGRAPH][MAXGRAPH];
bool visit[MAXGRAPH];
stack<int> s;
vector<int> v;
vector<char> v1;
int temp;
int size=0;
//�O��ÿ�����c�Ԡ�δ���L��B 
void resetVisit()
{
	for(int i=0;i<MAXGRAPH;i++)
		visit[i]=false;
} 
void resetGraph()
{
	for(int i=0;i<MAXGRAPH;i++)
	{
		for(int j=0;j<MAXGRAPH;j++)
			graph[i][j]=0;
	}
}
//��Ӣ����ĸ�ĵ�ַ�D�Q�������Ĕ��ִ��a 
int searchGraphID(char site)
{
	int i;
	for(i=0;i<v1.size();i++)
	{
		if(site==v1[i])
		{
			return i;
		}
	}
	v1.push_back(site);
	return i;
}
//ݔ����ʼ���ca,Ŀ�˵��cb,�O��a��b���Bͨ 
void setGraph(int a,int b)
{
	graph[a][b]=1;
} 
//������ʼ�cs1��Ŀ�ĵ�d1������·�� 
void findWay(int s1,int d1)
{	
	visit[s1]=true;
	s.push(s1);
	v.push_back(s1);
	if(s1==d1)
	{
		cout<<"           ";
		for(int i=0;i<v.size();i++)
		{
			cout<<v1[v[i]];
			if(i!=(v.size()-1))
				cout<<"->";
		}
		cout<<endl;
		visit[s1]=false;
		s.pop();
		v.pop_back();
		return;
	}
			
	
	for(int j=0;j<MAXGRAPH;j++)
	{
		if(graph[s1][j]&&!visit[j])
			findWay(j,d1);			
	}	
	visit[s1]=false;
	s.pop();
	v.pop_back();
	return;
}
#endif
