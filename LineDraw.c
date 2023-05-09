// <------------------------------>
// <------Line-Draw-Project------->
// <-------Sabina-Abdyeva--------->
// <------------------------------>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include "LineStrip.h" 

int window_width, window_height;

int px = 100; int py = 100;

Vector P; Vector A, B, C;   // vector A for red cross; B and C for [BC] line-segment

static void _drawRedCross(int x, int y, int size)
{
    A = V_new(x,y);   //red cross value
	// Let the current color be red
	glColor3ub(255,0,0);

	// Horizontal line
	glBegin(GL_LINE_STRIP);
	glVertex2i( x-size, y);
	glVertex2i( x+size, y);
	glEnd();

	// Vertical line
	glBegin(GL_LINE_STRIP);
	glVertex2i( x, y-size);
	glVertex2i( x, y+size);
	glEnd();
}

static void _display_CB()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0, window_width, window_height, 0, -1, 1);

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(0,0,0);

    glBegin(GL_LINE_STRIP);
    glVertex2i(px + 100, py);  B = V_new(px + 100,py);
    glVertex2i(100,300); C = V_new(100, 300);
    glEnd();

    _drawRedCross(200,200,10);

    glFlush();
    glutPostRedisplay();
    glutSwapBuffers();
}

static void _reshape_CB(int width, int height)
{
    printf("Window resized.\nWidth = %d, Height = %d\n",width,height);
    window_width = width;
    window_height = height;
    glViewport(0, 0, window_width, window_height);
}

static void _mouse_CB(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN)
    {
        switch(button)
        {
        case GLUT_LEFT_BUTTON: P = V_new(x,y);  // vector holding the click-point value
            printf("Shortest distance from the red cross = %.2f\n", V_PtPtDistance(P,A));
            break;
        case GLUT_RIGHT_BUTTON: P = V_new(x,y);  // vector holding the click-point value
            printf("Shortest distance from the line segment = %.2f\n", V_PtSegmentDistance(P,B,C)); 
            break;
        case GLUT_MIDDLE_BUTTON: printf("Middle button pressed.\n"); break;
        }
    }
    glutPostRedisplay();
}

static void _mouse_move_CB(int x, int y)
{
    printf("Mouse position : (%d,%d)\n", x, y);
}

static void _keyboard_CB(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 : exit(0); break;      // Escape to exit the program
    case 13 : printf("Enter pressed.\n"); break;
    case 8  : printf("Backspace pressed.\n"); break;
    case 32 : printf("Space pressed.\n"); break;
    
    default: break; 
    }
    glutPostRedisplay();
}

static void _special_CB(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT :     // moves current vector by 5px to the left
		px -= 5; break;
	case GLUT_KEY_RIGHT:    // moves current vector by 5px to the right
		px += 5; break;
 	case GLUT_KEY_UP   :    // moves current vector by 5px up
 		py -= 5; break;
 	case GLUT_KEY_DOWN :    // // moves current vector by 5px down
	 	py += 5; break;      

 	case GLUT_KEY_F1 : printf("F1 key.\n"); break;
    default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) 
{

    if(argc != 3) 
    {
        printf("\n Usage : %s <width> <height>\n", argv[0]);
        return 1;
    }
    else 
    {
        printf(                            // Entrance Menu
        " <--------------Welcome-!------------>\n"
        " <--Here you can find:             --> \n"
        " <--distance to the red cross :    --> \n"
        " <--             mouse left-click  --> \n"
        " <--distance to the line-segment : --> \n"
        " <--             mouse right-click --> \n"
        " <--Press Escape to exit           --> \n"
        " <--------------Thank you!-----------> \n");

        window_width = atoi(argv[1]);
        window_height = atoi(argv[2]);

        int windowPosX = 100, windowPosY = 100;

        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );        
        glutInitWindowSize(window_width, window_height);
        glutInitWindowPosition(windowPosX, windowPosY);
        glutCreateWindow("LineDraw");

        glViewport(0, 0, window_width, window_height);
        glClearColor(255,255,255,0);

        glutDisplayFunc(_display_CB);
        glutReshapeFunc(_reshape_CB);
        glutMouseFunc(_mouse_CB);
        glutMotionFunc(_mouse_move_CB);
        glutKeyboardFunc(_keyboard_CB);
        glutSpecialFunc(_special_CB);

        glutMainLoop();
    }
}
