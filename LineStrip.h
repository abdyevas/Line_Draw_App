#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <gl.h>
#include "Vector.h"
#define LineStrip Stack* 

// In this step we should be able to: add a new vertex; remove the latest vertex;

// Thus, we can use STACK of vectors, as abstract data type.
// As we work only with the last vector (remove last; add after the last) 
// LIFO principle will be the best chose.

// As a concrete data structure it is better to use Simply Linked List
// which enables us to use the next address of a vector,
// and also allows to add as many vertices as needed to the user;
// whereas array requires specific size which is not practical.

//value : the vector with x and y coordinates
//next : pointer to the next linestrip
//prev : pointer to the previous linestrip 

//value: a vector with x and y components
//next: a pointer to the next value of a stack
typedef struct stack 
{
    Vector value;
    struct stack *next;
} Stack;
    
//stack : a main stack holding all vertices
//vector : a vector(Vertex) 
//precondition : vector should have valid coordinates
//return value: none
//post condition : adds a value-vector to the end of a line strip 
LineStrip addVertex(LineStrip stack, Vector value);

//stack : a main stack holding all vertices
//precondition : stack should not be equal to NULL
//return value : none
//post condition : removes the latest vertex 
LineStrip removeVertex(LineStrip stack);

//stack : a main stack holding all vertices
//precondition: stack should not be equal to NULL
//return value: none
//post condition: prints components of each vector 
void Stack_show(LineStrip stack);

//stack : a main stack holding all vertices
//precondition: stack should not be equal to NULL
//return value: none
//post condition: draws line-strips joining two neighboring vertexes
void Strip_draw(LineStrip stack);