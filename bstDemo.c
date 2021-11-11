#include <stdio.h>
#include <stdlib.h>

struct node
{
	int node_number;
    int node_data;
    struct node *right;
    struct node *left;
};

struct node *CreateBST(struct node *root, int node_data, int node_number)
{
	// If tree is empty, then current node becomes root
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        
		root->left = root->right = NULL;
		
        root->node_data = node_data;
		root->node_number = node_number;
        
		return root;
    }
    else
    {
        if (node_data < root->node_data )
			root->left = CreateBST(root->left, node_data, node_number);
		
        else if(node_data > root->node_data )
            root->right = CreateBST(root->right, node_data, node_number);
        
		else
            printf(" Duplicate Element !! Not Allowed !!!");

        return(root);
    }
}

void Inorder(struct node *root)
{
    if( root != NULL)
    {
		Inorder(root->left);
        printf(" Node%d-%d ", root->node_number, root->node_data);
		Inorder(root->right);
    }
}

void Preorder(struct node *root)
{
    if( root != NULL)
    {
        printf(" Node%d-%d ", root->node_number, root->node_data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

struct node *SearchForNode(struct node *root, int node_data)
{
	if (root == NULL || root->node_data == node_data)
	{
		return root;
	}
		
	if (root->node_data > node_data)
		return SearchForNode(root->left, node_data);
		
    else
		return SearchForNode(root->right, node_data);
}

void Postorder(struct node *root)
{
    if( root != NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        printf(" Node%d-%d ", root->node_number, root->node_data);
    }
}

int main(void)
{
    struct node *root = NULL;
	struct node *SearchNode = NULL;
    int Choice, node_data, nodes_in_tree, node_number;
 
	do
    {
        printf("\n\nBinary Search Tree Operations\n");
		printf("\n0. Exit");
        printf("\n1. Creation of BST");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
		printf("\n5. Search for a node");

        printf("\n\nEnter Choice : ");

        scanf("%d", &Choice);

        switch (Choice)
        {
			case 0:
				printf("Bye!\n");
				break;
			
			case 1:
				root = NULL;
				printf("\n\nHow many nodes in the tree? ");
				scanf("%d",&nodes_in_tree);
            
				for(node_number = 1; node_number <= nodes_in_tree; node_number++)
				{
					printf("\nEnter data for node %d : ", node_number);
					scanf("%d", &node_data);
					root = CreateBST(root, node_data, node_number);
				}
				
				printf("\nBST with %d nodes is ready to use!!\n", nodes_in_tree);
				break;
				
			case 2:
				printf("\nBST Traversal in Inorder\n\n");
				Inorder(root);
				break;
        
			case 3:
				printf("\nBST Traversal in Preorder\n\n");
				Preorder(root);
				break;
        
			case 4:
				printf("\nBST Traversal in Postorder\n\n");
				Postorder(root);
				break;
				
			case 5:
				printf("Enter a data value to search for its node : ");
				scanf("%d", &node_data);
				SearchNode = SearchForNode(root, node_data);
				if (SearchNode ==  NULL)
					printf("Node data %d not found\n\n", node_data);
				else
					printf("Node %d has a value of %d\n", SearchNode->node_number, SearchNode->node_data);
				break;
     
			default:
				printf("\n\nInvalid Option !!! Try Again !! \n\n");
				break;
        }
    } 
	while (Choice);
    
	return 0;
}
