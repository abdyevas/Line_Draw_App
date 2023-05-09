#include"Vector.h"

Vector V_new(float x, float y) {
    Vector vnew;
    vnew.x = x; vnew.y = y;
    return vnew;
} 

void V_show(Vector v, char *label) {
    printf("%s : (%.2f, %.2f)\n", label, v.x, v.y);
}

float V_PtPtDistance(Vector P, Vector A) {
    float x = P.x - A.x;
    float y = P.y - A.y;
    return sqrt(x*x + y*y);
} 

float V_PtSegmentDistance(Vector P, Vector A, Vector B) {
/*We can find the distances between the beginning points of vectors and 
    use them as triangle sides, and after find the height of a triangle.
    As the height is perpendicular to the base, it will be 
    the shortest distance from a point P to the line segment [AB]*/
    // H = (2/a)sqrt(p(p-a)(p-b)(p-c));

    float base = V_PtPtDistance(A,B); //lenght of a line
    float side1 = V_PtPtDistance(P,A);
    float side2 = V_PtPtDistance(P,B);

    float halfper = (base + side1 + side2) / 2; //half-perimeter

    return ((2/base)*sqrt(halfper*(halfper - base)*(halfper - side1) * (halfper -side2)));    
}
