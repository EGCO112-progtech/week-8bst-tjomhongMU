// An integer binary search tree

struct TreeNode
{                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );

/*
void insertNode_R(TreeNodePtr * t,int value){
  if(t==NULL){
   t=new TreeNode;
	 if(t){
		t->leftPtr=NULL;
		t->rightPtr=NULL;
		t->data=value;
   }
  }
  else{
     if(t->data>=value) //left
        
     else //right
      
   }
}
*/

void	insertNode (BST *b, int value)
{
	TreeNodePtr	t;
	TreeNodePtr	new_node;
	int	inserted = 0;
	
	t = b->root;
	new_node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
	if (new_node == 0)
		return;
	new_node->leftPtr = 0;
	new_node->rightPtr = 0;
	new_node->data = value;
	if (!b->root)
		b->root = new_node;
	else
	{
		while (!inserted)
		{
				if (value <= t->data)
				{
					if (t->leftPtr == 0)
					{
						t->leftPtr = new_node;
						inserted = 1;
					}
					t = t->leftPtr;
				}
				else if (value > t->data)
				{
					if (t->rightPtr == 0)
					{
						t->rightPtr = new_node;
						inserted = 1;
					}
					t = t->rightPtr;
				}
		}
		b->size++;
	}

}

void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end 

void	preOrder(TreeNodePtr treePtr)
{
	if (treePtr == 0)
		return;
	printf("%3d", treePtr->data);
	preOrder(treePtr->leftPtr);
	preOrder(treePtr->rightPtr);
}

void	postOrder(TreeNodePtr treePtr)
{
	if (treePtr == 0)
		return;
	postOrder(treePtr->leftPtr);
	postOrder(treePtr->rightPtr);
	printf("%3d", treePtr->data);
}

void	tree(TreeNodePtr treePtr, int n)
{
	int	i;

	n++;
	i = 0;
	if (treePtr == NULL)
		return;
	tree(treePtr->rightPtr, n);
	while (i < n - 1)
	{
		printf("   ");
		i++;
	}
	printf("%3d\n", treePtr->data);
	tree(treePtr->leftPtr, n);
}
