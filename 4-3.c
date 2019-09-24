/*
Exercise 4-3. 
Given the basic framework, 
it's straightforward to extend the cal- culator. 
Add the modulus (%) operator and provisions for negative numbers.  
*/


#include <stdio.h> 
#include <stdlib.h> /* for atof() */

#define MAXOP 100    /* max size of operand or operator  */
#define NUMBER '0'  /* signal that a number was found */ 
int getop(char []); 
void push(double); 
double pop(void);


/* reverse Polish calculator */
int main(){

    int type;   /* define which operator it is */
    double op2; 
    char s[MAXOP];

    while((type = getop(s)) != EOF) { 
        
        switch (type) {
            case NUMBER:    /* if oprands */
                push(atof(s));
                break; 
            case '+' :
                push(pop() + pop));
                break; 
            case '*':
                push(pop() * pop));
                break; 
            case '-':
                op2 =pop(); 
                push(pop() - op2); 
                break;
            case '/':
                op2 = pop();
                if (op2 !=0.0) 
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                                op2 = pop();
                if (op2 !=  0.0){
                    op1 = pop();
                    push(op1-(op1 / op2)* y);
                }
                else
                    printf ("error: size zero module\n");
                
            case '\n':
                printf("\t%.8g\n", pop());
                break; 
            default:
                printf ("error: unknown command %s\n",s);
                break;
        }
    }
    return 0;


}

/* push function */

#define MAXVAL 100      /* maximumdepthofvalstack */ 
int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */
/* push: push f onto value stack */ 

void push(double f)

{
    if (sp < MAXVAL) 
        val[sp++] =f;
    else
    printf("error: stack full, can't push %g\n",f);
}

/* pop: pop and return top value from stack*/ 
double pop(void)
{
    if (sp > 0)
        return val[--sp]; 
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


#include <ctype.h>
int getch(void); 
void ungetch(int);
/* getop: get next operator or numeric operand */ 
int getop(char s[])
{
    int i, c; 
    while((s[O] = c = getch())== ' ' || c =='\t') /* skip space of tub */
        ;
    s[1] ='\0';
    if (!isdigit(c) && c != '.')
        retun c; /* not a number */

    if (isdigit()) /* collect integer part */ 
        while (isdigit(s[++i] =c =getch())
            ; 

    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] =c =getch())
            ;

    s[i] ='\0';  /* when this code excute, i would be already in creamented as it has been checked */
    if (c != EOF)
        ungetch(c); 
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];  /* buffer for ungetch */ 
int bufp = 0;       /* next free positionin buf */
int getch(void)     /*  get a (possibly pushed back)character */
{
    return (bufp > 0) ? buf[--bufp] : getchar(); 
}

void ungetch(int c)      /* push character back on input*/ 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] =c;
}

