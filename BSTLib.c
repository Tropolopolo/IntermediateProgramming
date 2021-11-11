//Matthew Irvine 1001401200
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BSTLib.h"

struct BSTnode *CreateBST(struct BSTnode **root, char MTName[], char MTZip[], char MTMap[])
{
	//printf("%s\n%s\n%s\n", MTName, MTZip, MTMap);
	// If tree is empty, then current node becomes root
    if (*root == NULL)
    {
        *root = (struct BSTnode *)malloc(sizeof(struct BSTnode));
        
		(*root)->left = (*root)->right = NULL;
		
        strcpy((*root)->MovieTheaterName, MTName);
		strcpy((*root)->MovieTheaterZip, MTZip);
		strcpy((*root)->MovieTheaterMap, MTMap);
        
		return *root;
    }
    else
    {
        if (strcmp(MTZip, (*root)->MovieTheaterZip) <0)
			(*root)->left = CreateBST(&((*root)->left), MTName, MTZip, MTMap);
		
        else if(strcmp(MTZip, (*root)->MovieTheaterZip) >0)
            (*root)->right = CreateBST(&((*root)->right), MTName, MTZip, MTMap);
        
		else
            printf(" Duplicate Element !! Not Allowed !!!");

        return(*root);
    }
}

struct BSTnode *SearchForMovieTheater(struct BSTnode *root, char Zip[])
{
	if (root == NULL || strcmp(root->MovieTheaterZip, Zip) == 0)
	{
		return root;
	}
		
	if (strcmp(root->MovieTheaterZip, Zip) > 0)
		return SearchForMovieTheater(root->left, Zip);
		
    else
		return SearchForMovieTheater(root->right, Zip);
}

void ListZipsInOrder(struct BSTnode *root)
{
    if( root != NULL)
    {
		ListZipsInOrder(root->left);
        printf("%s\n", root->MovieTheaterZip);
		ListZipsInOrder(root->right);
    }
}

void WriteOutNode(struct BSTnode *root, FILE *MyFile)
{
    if( root != NULL)
    {
		WriteOutNode(root->left, MyFile);
		printf(MyFile, "%s|%s|%s", root->MovieTheaterName, root->MovieTheaterZip, root->MovieTheaterMap);
        fprintf(MyFile, "%s|%s|%s", root->MovieTheaterName, root->MovieTheaterZip, root->MovieTheaterMap);
		WriteOutNode(root->right, MyFile);
    }
}
