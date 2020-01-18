#ifndef STDFX_H
#define STDFX_H 

#include<GL/glut.h>

#include<stdlib.h>

#define CONTINUE 1
#define QUIT 0
#define RED 2 
#define GREEN 3
#define BLUE 4
#define BLACK 5
#define INC 6
#define DEC 7
#define C1 8
#define C2 9
#define C3 10 
#define GOLD 11
#define ORCHID 12
#define BLACK1 13
#define WHITE 14

#define WIDTH 600
#define HEIGHT 400
#define POSX 100
#define POSY 100


struct bricks
{
	float x,y,w,h;
	bool alive;
};

struct ball
{
	float ballx,bally,ballwh,velx,vely;
	float red;
	float green;
	float blue;
	bool left,right,up,down;
};

struct block
{
	float myx;
	float myy;
	float width;
	float height;
	bool lft;
	bool rgt;
	float red;
	float green;
	float blue;
};

static int bricks_count = 45;

void reshape(void);		//To Modify the co-ordinates of the game objects according to the events
void draw(void);		//To Render the Game objects on the screen
void processmenu(int);		//To process the pause menu
extern void specialUp(int,int,int);	//To check for key press
extern void specialDown(int,int,int);  //To check for key release

extern void keyboard(unsigned char key,int x,int y);
extern void bg1_menu(int opt); // background color RGB Default menu
extern void bg2_menu(int opt); // background color RGB Default menu
extern void bg3_menu(int opt); // background color RGB Default menu
extern void bg4_menu(int opt); // background color RGB Default menu
extern void sp_menu(int opt) ; //for increasing and decreasing speed of both ball and slider need to be increase
extern void main_menu(int opt);
extern void callMenu();
extern void display();
extern void revert(void);

#endif
