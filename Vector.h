#include <stdio.h>
#include <math.h>
#define var float

//x and y : float values used as coordinates of a vector
typedef struct vector { 
    var x; var y;
} Vector;

//x and y : float values used as coordinates of a vector
//return value:  a new vector with (x,y) coordinates
Vector V_new(var x, var y); 

//v : a vector with x and y coordinates
//label : a string that will be printed as a label
//return value : none
//post condition : prints the coordinates of v-vector on the terminal 
                // with possibly an identifying label
void V_show(Vector v, char *label); 

//P and A : two vectors
//precondition : vectors should have valid values
//return value : float distance between P and A vectors
var V_PtPtDistance(Vector P, Vector A); 

//P : is a vector 
//A and B : two vectors joined with a line, forming a line segment
//precondition : vectors should have valid values
//return value : shortest distance between point P and the [AB] line segment
var V_PtSegmentDistance(Vector P, Vector A, Vector B); 