#include <stdlib.h>
#include <GL/glut.h>
static GLenum spinMode = GL_TRUE;
static GLenum singleStep = GL_FALSE;

static float HourOfDay = 0.0;
static float DayOfYear = 0.0;

static float AnimateIncrement = 2.0;

void Haxxan()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0.1,0.3,0.9);
	glVertex2f(-0.9,0.5);
	glVertex2f(-0.9,0.0);

	glVertex2f(-0.9,0.25);
	glVertex2f(-0.7,0.25);
	glEnd();
	glFlush();
}



static void Animate(void)
{
	// Clear the redering window
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (spinMode) {
		// Update the animation state
		HourOfDay += AnimateIncrement;
		DayOfYear += AnimateIncrement/40.0;

		HourOfDay = HourOfDay - ((int)(HourOfDay/28))*24;
		DayOfYear = DayOfYear - ((int)(DayOfYear/365))*365;
	}

	// Clear the current matrix (Modelview)
	glLoadIdentity();

	// Back off eight units to be able to view from the origin.
	glTranslatef ( 0.0, 0.0, -8.0 );

	// Rotate the plane of the elliptic
	// (rotate the model's plane about the x axis by fifteen degrees)
	glRotatef( 15.0, 1.0, 0.0, 0.0 );

	// Draw the sun    -- as a yellow, wireframe sphere
	glColor3f( 1.0, 1.0, 0.0 );
	glutWireSphere( 1.0, 32, 32 );

	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	//star 1
	glVertex2f(0.4,2.5);
	glVertex2f(0.6,2.6);

	glVertex2f(0.6,2.5);
	glVertex2f(0.4,2.6);
	// star 2
	glVertex2f(0.8,1.5);
	glVertex2f(1.1,1.7);

	glVertex2f(1.1,1.5);
	glVertex2f(0.8,1.7);
	// star 3
	glVertex2f(0.8,3.5);
	glVertex2f(1.1,3.7);

	glVertex2f(1.1,3.5);
	glVertex2f(0.8,3.7);

	//star 4
	glVertex2f(2.2,1.5);
	glVertex2f(2.4,1.7);

	glVertex2f(2.4,1.5);
	glVertex2f(2.2,1.7);

	//star 5
	glVertex2f(-2.2,3.5);
	glVertex2f(-2.4,3.7);

	glVertex2f(-2.4,3.5);
	glVertex2f(-2.2,3.7);

	//star 6
	glVertex2f(-0.4,2.5);
	glVertex2f(-0.6,2.6);

	glVertex2f(-0.6,2.5);
	glVertex2f(-0.4,2.6);

	//star 7
	glVertex2f(-3.4,2.5); 
	glVertex2f(-3.6,2.6);

	glVertex2f(-3.6,2.5);
	glVertex2f(-3.4,2.6);

	//star 8
	glVertex2f(-4.4,2.5);
	glVertex2f(-4.6,2.6);

	glVertex2f(-4.6,2.5);
	glVertex2f(-4.4,2.6);

	//star 9
	glVertex2f(-4.2,3.5);
	glVertex2f(-4.4,3.7);

	glVertex2f(-4.4,3.5);
	glVertex2f(-4.2,3.7);
	glEnd();
	// Now Draw Stars
	glColor3f(0.0,0.0,1.0);
	//glutWireSphere( 0.3, 18, 9 );
	//glLineStipple(0.1,0.1);
	glVertex2f(0.9,0.3);
	glVertex2f(0.6,0.3);

	//end stars
	// Draw the Earth
	// First position it around the sun
	//     Use DayOfYear to determine its position
	glRotatef( 360.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
	glTranslatef( 4.0, 0.0, 0.0 );
	glPushMatrix();                        // Save matrix state
	// Second, rotate the earth on its axis.
	//     Use HourOfDay to determine its rotation.
	glRotatef( 360.0*HourOfDay/24.0, 0.0, 1.0, 0.0 );
	// Third, draw the earth as a wireframe sphere.
	glColor3f( 0.0, 0.0, 1.0 );
	//iglutWireSphere( 0.4, 64, 64);
	glutSolidSphere(0.4,32,32);
	glPopMatrix();                     // Restore matrix state

	// Draw the moon.
	// Use DayOfYear to control its rotation around the earth
//	glRotatef( 360.0*12.0*DayOfYear/365.0, 0.0, 1.0, 0.0 );
	glRotatef( 360.0*60.0*DayOfYear/1000.0, 0.0, 1.0, 0.0 );
	glTranslatef( 0.7, 0.0, 0.0 );
	glColor3f( 0.3, 0.7, 0.3 );
	glutWireSphere( 0.1, 32, 32 );


	// Flush the pipeline, and swap the buffers
	glFlush();
	glutSwapBuffers();

	if ( singleStep ) {
		spinMode = GL_FALSE;
	}

	glutPostRedisplay();       // Request a re-draw for animation purposes

}


// Initialize OpenGL's rendering modes
void OpenGLInit(void)
{
	//  glClear(GL_COLOR_BUFFER_BIT);
	//glBegin(GL_LINES);
	//glColor3f(0.1,0.3,0.9);
	//glVertex2f(-0.9,0.5);
	//glVertex2f(-0.9,0.0);
	//  glutDisplayFunc(Haxxan);
	glShadeModel( GL_FLAT );
	glClearColor( 0.0, 0.0, 0.0, 0.0 ); 
	glClearDepth( 1.0 );
	glEnable( GL_DEPTH_TEST );
}

// ResizeWindow is called when the window is resized
static void ResizeWindow(int w, int h)
{
	float aspectRatio;
	h = (h == 0) ? 1 : h;
	w = (w == 0) ? 1 : w;
	glViewport( 0, 0, w, h );   // View port uses whole window
	aspectRatio = (float)w/(float)h;

	// Set up the projection view matrix (not very well!)
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 60.0, aspectRatio, 1.0, 30.0 );

	// Select the Modelview matrix
	glMatrixMode( GL_MODELVIEW );
}
int main( int argc, char** argv )
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowPosition( 0, 0 );
	glutInitWindowSize( 600, 360 );
	glutCreateWindow( "Solar System Demo" );
	OpenGLInit();
	glutReshapeFunc( ResizeWindow );
	glutDisplayFunc( Animate );
	glutMainLoop(  );
	return(0);
}


