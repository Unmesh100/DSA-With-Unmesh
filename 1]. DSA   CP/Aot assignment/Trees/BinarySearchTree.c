
#include <stdio.h>
#include<stdlib.h>
//Defining The Binary Search Tree using structure
struct BST{
    int data;
    struct BST* left;
    struct BST* right;
};
//Keep track of the total no of nodes in the BST
int size=0;
//Creating a node
struct BST* create(int data){
    struct BST* node=(struct BST*)malloc(sizeof(struct BST));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
}
//We use it to insert node in the BST
struct BST* insert(struct BST* root,int data){
    
    struct BST* node=create(data);
    if(root==NULL){
         size++;
        return node;
        
    }
    
    
    if(root->data>data){
        root->left=insert(root->left,data);
       //printf("%d",left->data);
        
    }
    else{
        root->right=insert(root->right,data);
    }
   
    return root;
    
}
//Preorder transversal
void preorder(struct BST* root){
    if(root==NULL)return;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}
//Inorder transversal
void inorder(struct BST* root){
    if(root==NULL)return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
//Postorder transversal
void postorder(struct BST* root){
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}
//Find the element in  the Binary Search Tree
void find(struct BST* root ,int value){
    if(root==NULL){
        printf("The value %d does not exits in the tree",value);
        return;
    }
    if(value>root->data){
        find(root->right,value);
    }
    else if(value<root->data){
        find(root->left,value);
    }
    else{
        printf("The element exist in the BST");
    }
}
//Finding the smallest element in a BST
void smallest(struct BST* root){
    
    if(root->left!=NULL)
    smallest(root->left);
    else
    printf("The smallest element is %d",root->data);
   
    
}
//Count the total no of nodes in the Binary Search Tree
void countNodes(struct BST* root){
    printf("The total no of nodes in the Binary Search Tree is %d",size);
}
int main() {
    printf("Press 1 to insert element in the BST\nPress 2 to do inorder transversal\nPress 3 to do preorder transversal\nPress 4 to do postorder transversal,Press 5 to find an element in the BST\nPress 6 to find the smallest element in the Tree\n Press 7 to get the total no of nodes in the Binary Search Tree\nPress any other key to exit the program->\n");
    struct BST* root=NULL;
    while(1){
        int a;
        scanf("%d",&a);
        if(a==1){
            printf("Enter the data to be inserted in the BST->");
            int data;
            scanf("%d",&data);
            root=insert(root,data);
        }
        else if(a==2){
            inorder(root);
        }
        else if(a==3){
            preorder(root);
        }
        else if(a==4){
            postorder(root);
        }
        else if(a==5){
            printf("Please input the data that you want to find in the Tree");
            int data;
            scanf("%d",&data);
            find(root,data);
        }
        else if(a==6){
            smallest(root);
        }
        else if(a==7){
            countNodes(root);
        }
        else{
            exit(0);
        }
    }

    return 0;
}