/*
 *    Data Structures in C
 *    
 *    Author: Afaan Bilal
 *    URL: https://afaan.ml
 *    
 *    STACK
 *        ARRAY Implementation
 *    
 *    (c) 2016 Afaan Bilal
 *    Released under the MIT License
 *     
 */

#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int data)
{
    if (top + 1 == SIZE)
    { 
        printf("\nStack is full!\n");
        return;
    }
    
    stack[++top] = data;
    printf("\nData pushed onto stack!\n");
}

int pop()
{
    if (top < 0)
    { 
        printf("\nStack is empty!\n");
        return -1;
    }
    
    return stack[top--];
}

void printstack()
{
    int i = 0;
    
    if (top == -1)
    {
        printf("\nStack is empty!\n");
        return;
    }
    
    printf("\n");
    while (i <= top)
    {
        printf("%d -> ", stack[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    int data, ch;
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
                printf("POPd data: %d", pop());
                break;
                
            default:
                printf("Invalid choice");
                break;      
        }
        
        printf("\nMENU\nPRINT STACK -> 0\nPUSH        -> 1\nPOP         -> 2\nEXIT        -> 3\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
                
    } while (ch != 3);
    
    return 0;    
}
