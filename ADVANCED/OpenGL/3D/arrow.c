#include <GL/glut.h>

int refreshMills = 15;
GLfloat angleCube = 0.0f;

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
	// Compute aspect ratio of the new window
	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);

	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset

	// Set up orthographic projection view [NEW]
	if (width >= height) {
		// aspect >= 1, set the height from -1 to 1, with larger width
//	glOrtho(-3.0 * aspect, 3.0 * aspect, -3.0, 3.0, 0.1, 100);
		glOrtho(-5.0 * aspect, 5.0 * aspect, -5, 5.0, 0.1, 100);
	} else {
		// aspect < 1, set the width to -1 to 1, with larger height
//		glOrtho(-3.0, 3.0, -3.0 / aspect, 3.0 / aspect, 0.1, 100);
		glOrtho(-5.0, 5.0, -5.0 / aspect, 5.0 / aspect, 0.1, 100);
	}
}

void arrow (){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 	// Clear color and depth buffers to preset values
	glMatrixMode(GL_MODELVIEW);    				//specify which matrix is the current matrix GL_MODELVIEW is the  Applies subsequent matrix operations to the modelview matrix stack.
	glPushMatrix();						//glPushMatrix pushes the current matrix stack down by one.
	glLoadIdentity();					//glLoadIdentity replaces the current matrix with the identity matrix.It is semantically equivalent to calling glLoadMatrix with the identity matrix
	glTranslatef(0.0, 0.0, -4.0);				//multiply the current matrix by a translation matrix
	glRotatef(angleCube, 1.0, 0.0, 1.0);			//multiply the current matrix by a rotation matrix	
	glColor3f(1.0,0.0,0.0); // red x			//set the current color
	glBegin(GL_LINES);					//delimit the vertices of a primitive or a group of like primitives. ex 
	glVertex3f(-3.0, 0.0f, 0.0f);				//specify a vertex.	
	glVertex3f(3.0, 0.0f, 0.0f);
	//arrow
	glVertex3f(3.0, 0.0f, 0.0f);
	glVertex3f(2.0, 0.5f, 0.0f);
	glVertex3f(2.0, -0.5f, 0.0f);
	glVertex3f(3.0, 0.0f, 0.0f);
	glEnd();
	glFlush();						// force execution of GL commands in finite time

	glColor3f(0.0,1.0,0.0); // green y
	glBegin(GL_LINES);
	glVertex3f(0.0, -3.0f, 0.0f);
	glVertex3f(0.0, 3.0f, 0.0f);
	// arrow
	glVertex3f(0.0, 3.0f, 0.0f);
	glVertex3f(-0.5,2.0f, 0.0f);
	glVertex3f(0.5, 2.0f, 0.0f);
	glVertex3f(0.0, 3.0f, 0.0f);
	glEnd();
	glFlush();

	glColor3f(0.0,0.0,1.0); // blue z
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0f ,-3.0f );
	glVertex3f(0.0, 0.0f ,3.0f );
	// arrow
	glVertex3f(0.0, 0.0f ,3.0f );
	glVertex3f(0.0, 0.5f ,2.0f );
	glVertex3f(0.0, -0.5f ,2.0f );
	glVertex3f(0.0, 0.0f ,3.0f );
	glEnd();
	glFlush();
	
	glPopMatrix();						//glPopMatrix pops the current matrix stack
	glutSwapBuffers();					//glutSwapBuffers swaps the buffers of the current window if double buffered

	// angleCube -= 0.9f;
	 angleCube -= 2.0f;
}


void timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, timer, -0.4); // next timer call milliseconds later
}

/*
void quit(unsigned char key,int , int y){

	if (key == 27  | key == 81 | key == 113)
		exit(1);
}

void fullscreen(int key , int ,int){

	if (key == GLUT_KEY_F5){
		glutFullScreen();
	}
}
*/
int main(int argc, char** argv)
{

	glutInit(&argc,argv); 				// initialize the glut library
	glutInitDisplayMode(GLUT_DOUBLE);		// initialize the display mode for double window 
	glutInitWindowSize(620,410);
	glutInitWindowPosition(0,0);
	glutCreateWindow("3D_ARROWS");
	glutDisplayFunc(arrow);				
	glutReshapeFunc(reshape);			// The reshape callback is triggered when a window is reshaped
//	glutKeyboardFunc(quit);
//	glutSpecialFunc(fullscreen);
	glutTimerFunc(refreshMills,timer,0);

	glutMainLoop();
	return 0;
}
