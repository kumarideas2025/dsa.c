
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int stacktop(struct stack *sp)
{
    return sp->arr[sp->top];
}
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("stack overflow!cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack under flow! cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
    int precedence(char ch)
    {
        if (ch == '*' || ch == '/')
            return 3;
        else if (ch == '+' || ch == '-')
            return 2;
        else
            return 0;
    }
    int isOperator(char ch)
    {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return 1;
        else
            return 0;
    }

    char* intopo(char* infix)
    {
        struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
        sp->size = 10;
        sp->top = -1;
        sp->arr = (char *)malloc(sp->size * sizeof(char));
        char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
        int i = 0; // Track infix traversal
        int j = 0; // Track postfix addition
        while (infix[i] != '\0')
        {
            if (!isOperator(infix[i]))
            {
                postfix[j] = infix[i];
                j++;
                i++;
            }
            else
            {
                if (precedence(infix[i]) > precedence(stacktop(sp)))
                {
                    push(sp, infix[i]);
                    i++;
                }
                else
                {
                    postfix[j] = pop(sp);
                    j++;
                }
            }
        }
        while (!isempty(sp))
        {
            postfix[j] = pop(sp);
            j++;
        }
        postfix[j] = '\0';
        free(sp->arr);
        free(sp);
        return postfix;
    }


int main()
{
    char *infix = "x-y/z-k*d";

    char *postfix = intopo(infix);
    printf("Postfix is: %s\n", postfix);

    free(postfix);

    return 0;
}
