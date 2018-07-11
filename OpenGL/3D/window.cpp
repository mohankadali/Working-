#include <GL/glut.h>
int refreshMills = 15;
GLfloat angleCube = 15.0f;

void cube(){
	glColor3f(1.0,0.0,0.0);
	glutSolidCube(0.5);
}
void arrow (){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(40,1,1,0);
	cube();
	glutSwapBuffers();					//glutSwapBuffers swaps the buffers of the current window if double buffered

	angleCube -= 4.1f;

}
void quit(unsigned char key,int , int y){

	if (key == 27  | key == 81 | key == 113)
		exit(1);
}
void fullscreen(int key , int ,int){

	if (key == GLUT_KEY_F5){
		glutFullScreen();
	}
}
void init(){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35,1.0f,0.1f,1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1,0.1,0.1,1);
}

void timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, timer, 0.1); // next timer call milliseconds later
}


int main(int argc, char** argv)
{

	glutInit(&argc,argv); 				// initialize the glut library
	glutInitDisplayMode(GLUT_DOUBLE);		// initialize the display mode for double window 
	glutInitWindowSize(620,410);
	glutInitWindowPosition(0,0);
	glutCreateWindow("3D_ARROWS");
	glutDisplayFunc(arrow);				
	glutKeyboardFunc(quit);
	glutSpecialFunc(fullscreen);
	glutTimerFunc(refreshMills,timer,5);
	glutMainLoop();
	return 0;
}
