#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

void drawCube() {
    // Define as coordenadas dos vértices do cubo
    float vertices[][3] = {
        {-0.5, -0.5, -0.5}, // Vértice 0
        {0.5, -0.5, -0.5},  // Vértice 1
        {0.5, 0.5, -0.5},   // Vértice 2
        {-0.5, 0.5, -0.5},  // Vértice 3
        {-0.5, -0.5, 0.5},  // Vértice 4
        {0.5, -0.5, 0.5},   // Vértice 5
        {0.5, 0.5, 0.5},    // Vértice 6
        {-0.5, 0.5, 0.5}    // Vértice 7
    };

    // Define as faces do cubo
    int faces[][4] = {
        {0, 1, 2, 3}, // Face frontal
        {1, 5, 6, 2}, // Face lateral direita
        {5, 4, 7, 6}, // Face traseira
        {4, 0, 3, 7}, // Face lateral esquerda
        {3, 2, 6, 7}, // Face superior
        {0, 4, 5, 1}  // Face inferior
    };

    // Cores para cada face do cubo
    float colors[][3] = {
        {1.0, 0.0, 0.0}, // Vermelho
        {0.0, 1.0, 0.0}, // Verde
        {0.0, 0.0, 1.0}, // Azul
        {1.0, 1.0, 0.0}, // Amarelo
        {1.0, 0.0, 1.0}, // Magenta
        {0.0, 1.0, 1.0}  // Ciano
    };

    // Desenha o cubo
    glBegin(GL_QUADS);
    for (int i = 0; i < 6; i++) {
        glColor3fv (colors[i]);
        for (int j = 0; j < 4; j++) {
            glVertex3fv(vertices[faces[i][j]]);
        }
    }
    glEnd();
}

void init(void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT); //apaga tudo (fica tudo com a cor definida no buffer)
   //glColor3f (0.0, 0.0, 0.0); // difine a cor do "desenho"
   glLoadIdentity ();             /* clear the matrix - forma de garantir que as proximas transformações sejam executadas sem interferencias de transformações anteriores*/ 

   /* viewing transformation  */
   gluLookAt (0.0, 2.0, 5.0,  //posição da camera
              0.0, 0.0, 0.0,  //onde a camera esta apontando
              0.0, 1.0, 0.0); //vetor up da camera

   //glScalef (1.0, 2.0, 1.0);      /* modeling transformation */ 

   //glutWireCube (1.0);
   drawCube();
   glFlush ();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
   glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}

