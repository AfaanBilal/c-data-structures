/*
 *    Data Structures in C
 *    
 *    Author: Afaan Bilal
 *    URL: https://afaan.ml
 *    
 *    QUEUE
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

Node *front, *back;

void append(int data)
{    
    if (back == NULL)
    {
        back = malloc( sizeof(Node) );
        back->data = data;
        back->next = NULL;
        front = back;
    }
    else
    {
        Node* newNode = malloc( sizeof(Node) );
        
        newNode->data = data;
        newNode->next = NULL;
        
        back->next = newNode;
        back = newNode;
    }
        
    printf("\nData appended to queue!\n");
}

int rem()
{
    if (front != NULL)
    {
        Node* temp = front;
        int data = front->data;
        
        if (front->next == NULL)
        {
            front = back = NULL;
        }
        else
        {
            front = front->next;
        }
        
        free(temp);
        temp = NULL;
               
        return data;
    }
    else
    {
        printf("\nQueue is empty!\n");
        return -1;
    }
}

void printqueue()
{
    Node* itr = front;
    
    if (front == NULL)
    {
        printf("\nQueue is empty\n");
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
    back = NULL;
    front = NULL;

    printf("MENU\nPRINT QUEUE -> 0\nAPPEND      -> 1\nREMOVE      -> 2\nEXIT        -> 3\n");
    printf("\nEnter choice: ");
    scanf("%d", &ch);
    
    do
    {
        switch (ch)
        {
            case 0:
                printqueue();
                break;
                
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                append(data);
                break;
            
            case 2:
                printf("\nRemoved data: %d\n", rem());
                break;
                
            default:
                printf("Invalid choice");
                break;      
        }
        
        printf("---------------------------------------------------");
        printf("\nMENU\nPRINT QUEUE -> 0\nAPPEND      -> 1\nREMOVE      -> 2\nEXIT        -> 3\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
                
    } while (ch != 3);
    
    return 0;    
}
