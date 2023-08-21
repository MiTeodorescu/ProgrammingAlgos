#include <stdio.h>
#include <stdlib.h>

static int noCallsFunc=0;
struct BTree {
  struct BTree * LeftChild;
  struct BTree * RightChild;
  int Data;
};


struct BTree* NewNode(int recvData)
{
    struct BTree* Node
        = (struct BTree*)malloc(sizeof(struct BTree));
    Node->Data = recvData;
    Node->LeftChild = NULL;
    Node->RightChild = NULL;

    return (Node);
}
void releaseMemBTree(struct BTree * Node)
{
  if(Node==NULL)
    return;
  if(Node->LeftChild)
    releaseMemBTree(Node->LeftChild);
  if(Node->RightChild)
    releaseMemBTree(Node->RightChild);
  free(Node);
  return;

}
void InOrderTraverse(struct BTree * Node)
{
  noCallsFunc++;
  if(Node==NULL)
    return;
  if(Node->LeftChild)
    InOrderTraverse(Node->LeftChild);
  printf("%d\n",Node->Data);
  if(Node->RightChild)
    InOrderTraverse(Node->RightChild);
  return;
}


int main()
{
    getchar();
    struct BTree* Root = NewNode(0);
    int i,j;
    int noLvls=9;
    int noNodes=1;
    struct BTree *ArrayCurrentNodes[2][1024]={0};
    struct BTree *TmpNode;
    ArrayCurrentNodes[0][0]=Root;
    for(i=0;i<10;i++)
    {
	for(j=0;j<(1<<i);j++)
	{


		ArrayCurrentNodes[i%2][j]->LeftChild=NewNode(3*j+5*i+noNodes);
		ArrayCurrentNodes[i%2][j]->RightChild=NewNode(7*j+11*i+noNodes+1);
		ArrayCurrentNodes[(i+1)%2][2*j]=ArrayCurrentNodes[i%2][j]->LeftChild;
		ArrayCurrentNodes[(i+1)%2][2*j+1]=ArrayCurrentNodes[i%2][j]->RightChild;
		noNodes = noNodes + 2;
                /*printf("Value of i is %d value of j is %d\n",i,j);*/
                		


	}
    }

    printf("Inorder traversal of binary tree with %d nodes is \n", noNodes);
    InOrderTraverse(Root);

    printf("no of func calls %d\n",noCallsFunc);
    getchar();
    releaseMemBTree(Root);
    getchar();
    return 0;
}
