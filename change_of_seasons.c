#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <iostream>
using namespace std;
 
GLuint makeaTree;
 
void createMenu(void);
void menu(int value);
void makeCylinder(float height, float base);
void makeTree_sum(float height, float base);
void makeTree_wint(float height, float base);
void makeTree_spr(float height, float base);
void makeTree_aut(float height, float base);
void makeTree_fruit(float height, float base);
void init(void);
void display();
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);
void drawstring(float x,float y,float z,char *string);
 
int main(int argc, char **argv);
 
int season,val,win;
float x,y,z;
int flag=0;
 
void createMenu(void)
{
              season = glutCreateMenu(menu);
              glutAddMenuEntry("SUMMER - \"S\"", 1);
              glutAddMenuEntry("WINTER   - \"W\"", 2);
              glutAddMenuEntry("SPRING   - \"G\"", 3);
              glutAddMenuEntry("AUTUMN - \"A\"", 4);
              glutAddMenuEntry("Quit - \"Q\"", 5);
              glutAttachMenu(GLUT_RIGHT_BUTTON);
}
 
void menu(int val)
{
              switch (val)
              {
                           case 1:
                                         glClearColor(1.0,1.0/3,0.1,0.5);
                                         glTranslatef(0.0,-4.0,0.0);
                                         makeTree_sum(4,0.2);
                                         glutPostRedisplay();                  
                                         glClearColor(0.8,0.5,0.5,0.5);
                                         glutPostRedisplay();
                                         break;
                           case 2:
                                         glClearColor(0.8,1.0/2,0.5,0.5);                        
                                         glTranslatef(0.0,-4.0,0.0);                     
                                         makeTree_wint(4,0.2);
                                         glutPostRedisplay();                                   
                                         break;
                           case 3:
                                         glutPostRedisplay();
                                         glClearColor(0.6,0.0,0.6,0.5);
                                         glTranslatef(0.0,-4.0,0.0);                                  
                                         makeTree_spr(4,0.2);
                                         glTranslatef(0.0,-4.0,0.0);
                                         makeTree_fruit(4,0.2);                                        
                                         break;
                           case 4:
                                         glClearColor(1.0,0.0,0.5,0.5);              
                                         glTranslatef(0.0,-4.0,0.0);                     
                                         makeTree_aut(4,0.2);
                                         glutPostRedisplay();    
                                         break;
                           case 5:
                                         exit(0);
              }
}
void frontscreen(void)
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glColor3f(1.0,0.0,1.0);
drawstring(-5,20.05,0.0,"HKBK COLLEGE OF ENGINEERING ");
glColor3f(1.0,1.0,1.0);
drawstring(-10,19.05,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
glColor3f(0.0,1.0,1.0);
drawstring(-12.5,17.05,0.0,"COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT(15CSL68)");
drawstring(-6.5,16.05,0.0,"For the academic year 2019-2020");
glColor3f(1.0,1.0,1.0);
drawstring(-5,14.75,0.0,"  SEASON CHANGE  ");
glColor3f(1.0,1.0,1.0);
drawstring(-3,12.05,0.0,"BY:");
glColor3f(1.0,0.0,1.0);
drawstring(-6.95,11.75,0.0,"UNDER THE GUIDANCE OF :");
glColor3f(0.0,1.0,0.0);
drawstring(-7.95,10.05,0.0,  "PAKKRUDDIN.B   Assistant Professor");
//drawstring(-7.95,9.05,0.0,  "SWATHI PRIYA   Assistant Professor");
 glColor3f(1.0,1.0,0.0);
drawstring(14.95,6.05,0.0,"DONE BY:");
glColor3f(1.0,1.0,1.0);
drawstring(10.5,4.15,0.0,"MD IMRAN\tS\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(1HK16CS076)");
drawstring(10.5,3.05,0.0,"MOHAMMED SYED SAQUIB \tC\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(1HK16CS092)");
 drawstring(10.5,3.05,0.0,"MD WASIM ANWAR \tC\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t(1HK16CS077)");
 
//drawstring(63,34,0.0,"GUIDE NAME SECOND");
//glColor3f(1.0,1.0,1.0);
// drawstring(-14.95,-13.0");
glFlush();
glutSwapBuffers();
}
void drawstring(float x,float y,float z,char *string)
{
  char *c;
glRasterPos3i(x,y,z);
for(c=string;*c!='\0';c++)
{
  glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
}
}
 
void makeCylinder(float height, float base)
{
              GLUquadric *obj = gluNewQuadric();
              gluQuadricDrawStyle(obj, GLU_LINE);
              glColor3f(0.64f, 0.16, 0.16f);
              glPushMatrix();
                           glRotatef(-90, 1.0,0.0,0.0);
                           gluCylinder(obj, base,base-(0.2*base), height, 20,20);
              glPopMatrix();
              glutSwapBuffers();
}
 
void makeTree_sum(float height, float base)
{
              float angle;
              makeCylinder(height, base);
              glTranslatef(0.0, height, 0.0);
              height-= height*.2;
              base-= base*0.3;
              for(int a= 0; a<3; a++)
              {
                           angle = rand()%50+20;
                           if(angle >48)
                                         angle = -(rand()%50+20);
                           if (height >1)
                           {
                                         glPushMatrix();
                                                       glRotatef(angle,1,0.0,1);
                                                       makeTree_sum(height,base);
                                         glPopMatrix();
                           }
                           else
                                         glColor3f(0.0,1.0/a,0.0);
                           glutSolidTeapot(0.2);
              }
              glFlush();
}
 
void makeTree_aut(float height, float base)
{
              float angle;
              makeCylinder(height, base);
              glTranslatef(0.0, height, 0.0);
              height-= height*.2;
              base-= base*0.3;
              for(int a= 0; a<3; a++)
              {
                           angle = rand()%50+20;
                           if(angle >48)
                                         angle = -(rand()%50+20);
                           if (height >1)
                           {
                                         glPushMatrix();
                                                       glRotatef(angle,1,0.0,1);
                                                       makeTree_aut(height,base);
                                         glPopMatrix();
                           }
                           else
                                         glColor3f(0.0,1.0/a,0.0);
              }
              glFlush();
}
 
void makeTree_spr(float height, float base)
{
              float angle;
              makeCylinder(height, base);
              glTranslatef(0.0, height, 0.0);
              height-= height*.2;
              base-= base*0.3;
              for(int a= 0; a<3; a++)
              {
                           angle = rand()%50+20;
                           if(angle >48)
                                         angle = -(rand()%50+20);
                           if (height >1)
                           {
                                         glPushMatrix();
                                                       glRotatef(angle,1,0.0,1);
                                                       makeTree_spr(height,base);
                                         glPopMatrix();
                           }
                           else
                                         glColor3f(1.0,1.0/a,0.0);
                           glutSolidTeapot(0.2);
              }
              glFlush();
}
 
void makeTree_wint(float height, float base)
{
              float angle;
              makeCylinder(height, base);
              glTranslatef(0.0, height, 0.0);
              height-= height*.2;
              base-= base*0.3;
              for(int a= 0; a<3; a++)
              {
                           angle = rand()%50+20;
                           if(angle >48)
                                         angle = -(rand()%50+20);
                           if (height >1)
                           {
                                         glPushMatrix();
                                                       glRotatef(angle,1,0.0,1);
                                                       makeTree_wint(height,base);
                                         glPopMatrix();
                           }
                           else
                                         glColor3f(1.0,1.0/a,1.0);
                          
                           glutSolidTeapot(0.2);
              }
              glFlush();
}
 
void makeTree_fruit(float height, float base)
{
              float angle;
              makeCylinder(height, base);
              glTranslatef(0.0, height, 0.0);
              height-= height*.2;
              base-= base*0.3;
              for(int a= 0; a<3; a++)
              {
                           angle = rand()%50+20;
                           if(angle >48)
                                         angle = -(rand()%50+20);
                           if (height >1)
                           {
                                         glPushMatrix();
                                                       glRotatef(angle,1,0.0,1);
                                                       makeTree_fruit(height,base);
                                         glPopMatrix();
                           }
                           else
                                         glColor3f(0.2/a,0.2,0.0);
                           glutSolidSphere(0.2,10,10);
              }
              glFlush();
}
 
void init(void)
{
              glMatrixMode(GL_PROJECTION);
              glLoadIdentity();
              glPointSize(18.0);
              glClearColor(0.2,0.6,0.5,0.5);
              glShadeModel(GL_SMOOTH);
              glEnable(GL_DEPTH_TEST);
              makeaTree=glGenLists(1);
              glNewList(makeaTree, GL_COMPILE);
              glMatrixMode(GL_MODELVIEW);
              glEndList();
}
 
void mydisplay(void)
{
glClear(GL_COLOR_BUFFER_BIT);
if(flag==0){
glClearColor(0,0,0,0);
   frontscreen();
cout<<flag;
}
if(flag==1){
glClear(GL_COLOR_BUFFER_BIT);
  display();}
}
 
 
 
 
 
void display()
{
              glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
              glPushMatrix();
                           glRotatef(x,1.0,0.0,0.0);                                     
                           glRotatef(y,0.0,1.0,0.0);
                           glRotatef(z,0.0,0.0,1.0);
                           glCallList(makeaTree);
              glPopMatrix();              
              glutSwapBuffers();
              glFlush();
}
 
void keyboard(unsigned char key, int x, int y)
{
             
              if(key=='s')
              {
                           glClearColor(1.0,1.0/3,0.1,0.5);
                           glutPostRedisplay();                  
                           glTranslatef(0.0,-4.0,0.0);
                           makeTree_sum(4,0.2);                          
              }
             
              if(key=='w')
              {                                      
                           glClearColor(0.8,1.0/2,0.5,0.5);
                           glTranslatef(0.0,-4.0,0.0);                     
                           makeTree_wint(4,0.2);
                           glutPostRedisplay();    
              }
             
              if(key=='a')
              {                         
                           glClearColor(0.2,0.2,0.6,0.5);                                         
                           glTranslatef(0.0,-4.0,0.0);                     
                           makeTree_aut(4,0.2);
                           glutPostRedisplay();    
              }
 
              if(key=='g')
              {                                                    
                           glClearColor(1.0,0.0,0.5,0.5);
                           glTranslatef(0.0,-4.0,0.0);                                  
                           makeTree_spr(4,0.2);
                           glTranslatef(0.0,-4.0,0.0);
                           makeTree_fruit(4,0.2);
                           glutPostRedisplay();
              }
if (key=1)
{
 
mydisplay();
}           
 
 
              if(key=='q')
                           exit(0);
 
}
 
 
void reshape(int w, int h)
{
              glViewport (0, 0, (GLsizei) w, (GLsizei) h);
              glMatrixMode(GL_PROJECTION);
              glLoadIdentity();
              gluPerspective(30.0, (GLfloat) w/(GLfloat) h, 0.001, 1000.0);
              glMatrixMode(GL_MODELVIEW);
              glLoadIdentity();
              glTranslatef(0.0,-8.0,-50.0);
}           
 
 
int main(int argc, char **argv)
{
              glutInit(&argc, argv);
              glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
              glutInitWindowSize (2000, 2000);
              glutInitWindowPosition(0,0);
              glutCreateWindow("Tree season");
              glEnable(GL_DEPTH_TEST);
              init();
              createMenu();
              glutReshapeFunc(reshape);
              glutKeyboardFunc(keyboard);
              glutDisplayFunc(display);
              glEnable (GL_NORMALIZE);
              glutMainLoop();
}


