//program to store graph as adjacency list.
//http://iamsoftwareengineer.blogspot.com/2012/06/c-graph-implementation-with-adjacency.html
//https://www.geeksforgeeks.org/graph-and-its-representations/
#include<stdio.h>
#include<stdlib.h>

//create vertex
struct vertex{
	int vertexkey;
	struct edge* edgeptr;
};
 struct vertex* graph[10];
int vertexCount=0;
//create edge
struct edge{
	int vertexname;
	struct edge* edgenext;
};

//insert new vertex
//the vertices should be from 0 to 9 and in ascending order i.e 0,1,2,3 
//sequences like 0,2 or 0,4 or 2,3 or 4,5 will give error
//because the adjacency list(is an array of pointers which store address of every struct vertex created) 
//is using vertexcount from 0 and incrementing by 1.
void newvertex(int a){
		struct vertex* new=(struct vertex*)malloc(sizeof(struct vertex));
		graph[vertexCount]=new;
		new->vertexkey=a;
		new->edgeptr=NULL;
		vertexCount++;
	}

//inserting edge
//two vertexkey are passed as arguments
//the vertexkey should have been already created or else error
//this does not check for muntiple edges with same vertexname in the list
void insertedge(int vertex_a,int vertex_b){
	struct edge* new=(struct edge*)malloc(sizeof(struct edge));
		new->vertexname=vertex_b;
		new->edgenext=NULL;
	if(graph[vertex_a]->edgeptr!=NULL)
	{
		struct edge* point=graph[vertex_a]->edgeptr;
		while(point->edgenext!=NULL)
			point=point->edgenext;
		point->edgenext=new;		
	}
	else if(graph[vertex_a]->edgeptr==NULL)
		graph[vertex_a]->edgeptr=new;

	struct edge* new2=(struct edge*)malloc(sizeof(struct edge));
	new2->vertexname=vertex_a;
	new2->edgenext=NULL;
	if(graph[vertex_b]->edgeptr!=NULL)
	{
		struct edge* point2=graph[vertex_b]->edgeptr;
		while(point2->edgenext!=NULL)
			point2=point2->edgenext;
		point2->edgenext=new2;
	}
	else if(graph[vertex_b]->edgeptr==NULL){
		graph[vertex_b]->edgeptr=new2;
	}
}

void printgraph()
{
	for(int i=0;i<vertexCount;i++)
	{
		if(graph[i]->edgeptr!=NULL){

			struct edge* check=graph[i]->edgeptr;
			printf("Vertice %d neigbour is %d\n",i,check->vertexname );
			while(check->edgenext!=NULL){
				check=check->edgenext;
				printf("Vertice %d neigbour is %d\n",i,check->vertexname );
				
			}
		}
		else return;
	}
}
int main()
{
	newvertex(0);
	newvertex(1);
	newvertex(2);
	newvertex(3);
	newvertex(4);
	newvertex(5);
	newvertex(6);
	newvertex(7);
	newvertex(8);
	newvertex(9);
	
	insertedge(0,1);
	insertedge(0,2);
	insertedge(0,3);
	insertedge(0,4);
	insertedge(0,5);
	insertedge(0,6);
	insertedge(0,7);
	insertedge(0,8);
	insertedge(0,9);
	insertedge(9,1);
	printgraph();


}