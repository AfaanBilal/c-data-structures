/*
 *    Data Structures in C
 *    
 *    Author: Afaan Bilal
 *    URL: https://afaan.ml
 *    
 *    STACK
 *        LINKED LIST Implementation
 *    
 *    (c) 2016 Afaan Bilal
 *    Released under the MIT License
 *     
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *root, *current;

void push(int data)
{
    if (root == NULL)
    {
        root = malloc( sizeof(Node) );
        root->data = data;
        root->next = NULL;
        current = root;
    }
    else
    {
        Node* newNode = malloc( sizeof(Node) );
        newNode->data = data;
        newNode->next = NULL;
        current->next = newNode;
        current = newNode;
    }
    
    printf("\nData pushed onto stack!\n");
}

int pop()
{
    Node* itr = root;
    int data = current->data;
    
    if (root == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    
    if (current == root)
    {
        free(current);
        current = NULL;
        root = NULL;
    }
    else
    {   
        while (itr->next->next != NULL)
        {
            itr = itr->next;
        }
        
        current = itr;
        
        free(current->next);
        current->next = NULL;
    }
    
    return data;
}

void printstack()
{
    Node* itr = root;
    
    if (root == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    
    printf("\n");
    while (itr != NULL)
    {
        printf("%d -> ", itr->data);
        itr = itr->next;
    }
    printf("\n");    
}

int main()
{
    int data, ch;
    root = NULL;
    current = NULL;

    printf("MENU\nPRINT STACK -> 0\nPUSH        -> 1\nPOP         -> 2\nEXIT        -> 3\n");
    printf("\nEnter choice: ");
    scanf("%d", &ch);
    
    do
    {
        switch (ch)
        {
            case 0:
                printstack();
                break;
                
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            
            case 2:
                printf("\nPOPd data: %d\n", pop());
                break;
                
            default:
                printf("Invalid choice");
                break;      
        }
        
        printf("---------------------------------------------------");
        printf("\nMENU\nPRINT STACK -> 0\nPUSH        -> 1\nPOP         -> 2\nEXIT        -> 3\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
                
    } while (ch != 3);
    
    return 0;    
}
