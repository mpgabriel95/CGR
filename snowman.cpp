// gcc snowman.cpp -lglut -lGL -lGLU -o  snowman && ./snowman
#include <cstdlib>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

#define NUM_PARTICLES 3000
#define GRAVITY 0.0003


float angle = 0.0;
GLUquadric* qobj;


static void display()
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   gluLookAt(0.0, 6.5, 4.0,
             0.0, 0.0, 1.0,
             0.0, 0.0, 1.0);

   angle += 0.05;

   glRotated(angle, 0, 0, 1);
   glColor3f(1.0, 1.0, 1.0);

	



	//Esfera inferior
   glPushMatrix();
      glTranslatef(0.0, 0.0, 0.75);
      glutSolidSphere(0.75, 20, 20);
   glPopMatrix();
   
   //Esfera do meio
   glPushMatrix();
      glTranslatef(0.0, 0.0, 2.05);
      glutSolidSphere(0.55, 20, 20);
   glPopMatrix();
   
   //Esfera superior
   glPushMatrix();
      glTranslatef(0.0, 0.0, 2.85);
      glutSolidSphere(0.30, 20, 20);
   glPopMatrix();
   
   glColor3f(0, 0, 0);
   
   //Olhos
   glPushMatrix();
      glTranslatef(0.15, -0.25, 2.85);
      glutSolidSphere(0.05, 20, 20);
   glPopMatrix();
   
   glPushMatrix();
      glTranslatef(-0.15, -0.25, 2.85);
      glutSolidSphere(0.05, 20, 20);
   glPopMatrix();
   
   glColor3f(0.5, 0.2, 0);
   
   //Nariz
   glPushMatrix();
      glTranslatef(0.0, 0.0, 2.78);
      glRotatef(90,1,0,0);
      glutSolidCone(0.08, 0.7, 10, 10);
   glPopMatrix();
   
   

   glFlush();
   glutSwapBuffers();
}

int main (int argc, char **argv)
{
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
		
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize(800,600);
    glutCreateWindow("Boneco de Neve");

    glutDisplayFunc(display);
    glutIdleFunc( display );

    glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, 800, 600);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat aspect = (GLfloat) 800 / 600;
    gluPerspective(45, aspect, 2.0f, 15.0f);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel( GL_SMOOTH );
    glClearDepth( 1.0f );
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LEQUAL );
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
    glClearColor(0.0, 0.0, 0.0, 1.0);

    GLfloat mat_shininess[] =  { 50.0 };
    GLfloat mat_specular[] =   { 0.75, 0.75, 0.75, 0.75 };

    GLfloat light_ambient[] =  {  0.0,  0.0,  1.0, 1.0 };
    GLfloat light_diffuse[] =  {  1.0,  1.0,  1.0, 1.0 };
    GLfloat light_specular[] = {  1.0,  1.0,  1.0, 1.0 };
    GLfloat light_position[] = {  10.0,  2.0,  10.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glutMainLoop();

    return 0;
}
