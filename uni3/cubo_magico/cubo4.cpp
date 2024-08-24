#include <GL/glut.h>
#include <vector>
#include <iostream>

// Ângulo de rotação para o cubo
static float angleX = 0.0f;
static float angleY = 0.0f;

int Front = 0, Back, Left, Right, Up, Down;

void rotate(char face, int state){
    if(face == 'l'){
        glPushMatrix(); // Salva a matriz de transformação atual
        glTranslatef(-1.5f, 0.0f, 0.0f); // Translada o cubo à esquerda
        glPopMatrix(); // Restaura a matriz de transformação
    }
}

class cubo{
    public:
        float x, y, z;

        cubo(float dx,float dy,float dz): x(dx), y(dy), z(dz) {
            drawCube(x, y, z);

            return;
        }
    private:
        

        void drawCube(float dx, float dy, float dz) {
            
            glLineWidth(5.0f); // Define a largura da linha
            // Face Frente
            glBegin(GL_QUADS);
                if(dz == -2.0)
                {
                    glColor3f(0.0f, 0.0f, 1.0f); // Azul
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
            glEnd();

            // Face Traseira
            glBegin(GL_QUADS);
                if(dz == 2.0)
                {
                    glColor3f(0.0, 1.0, 0.0); // Verde
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
            glEnd();

            // Face Esquerda
            glBegin(GL_QUADS);
                if(dx == 2.0)
                {
                    glColor3f(1.0, 0.5f, 0.0); // Laranja
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
            glEnd();

            // Face Direita
            glBegin(GL_QUADS);
                if(dx == -2.0)
                {
                    glColor3f(1.0, 0.0, 0.0); // Vermelho
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
            glEnd();

            // Face Superior
            glBegin(GL_QUADS);
                if(dy == -2.0)
                {
                    glColor3f(1.0, 1.0, 0.0); // Amarelo
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx,  1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
            glEnd();

            // Face Inferior
            glBegin(GL_QUADS);
                if(dy == 2.0)
                {
                    glColor3f(1.0, 1.0, 1.0); // Branco
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy, -1.0-(GLfloat)dz);
                glVertex3f( 1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
                glVertex3f(-1.0-(GLfloat)dx, -1.0-(GLfloat)dy,  1.0-(GLfloat)dz);
            glEnd();                 
        }
};


class face{
    public:
        cubo cubos[9];

        face() {
            create_face(int i); // 0 -> face esquerda; 1-> face central; 2 -> face direita;
        }
    private:
    cubo cubinho1(0.0,0.0,0.0);
    cubo cubinho2(0.0,0.0,2.0);
    cubo cubinho3(0.0,0.0,-2.0);
    cubo cubinho4(0,2.0,0);
    cubo cubinho5(0,-2.0,0);
    cubo cubinho6(0,2.0,2.0);
    cubo cubinho7(0,2.0,-2.0);
    cubo cubinho8(0,-2.0,2.0);
    cubo cubinho9(0,-2.0,-2.0);

        void create_face(int i){
            if(i==1){
                for(int i=0; i < 9; i++){
                    cubos[i] = cubo()
                }
            }
        }

        void rotate(){
            return;
        }
};

class CuboMagico{
    public:
        face faces[3];

        CuboMagico() {
            create_cube();
        }
    private:

        void create_cube(){
            return;
        }
};

//Função teclado rotação
void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'f':   /*  s key rotates at shoulder  */
            Front = (Front + 1) % 360;
            glutPostRedisplay();
            break;
        case 'F':
            Front = (Front - 5) % 360;
            glutPostRedisplay();
            break;
        case 'b':  /*  e key rotates at elbow  */
            Back = (Back + 5) % 360;
            glutPostRedisplay();
            break;
        case 'B':  /*  e key rotates at elbow  */
            Back = (Back + 5) % 360;
            glutPostRedisplay();
            break;
        case 'u':
            Up = (Up - 5) % 360;
            glutPostRedisplay();
            break;
        case 'U':
            Up = (Up - 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':
            Down = (Down - 5) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            Down = (Down - 5) % 360;
            glutPostRedisplay();
            break;
        case 'l':
            Left = (Left - 5) % 360;
            rotate('l', 0);
            glutPostRedisplay();
            break;
        case 'L':
            Left = (Left - 5) % 360;
            glutPostRedisplay();
            break;
        case 'r':
            Right = (Right - 5) % 360;
            glutPostRedisplay();
            break;
        case 'R':
            Right = (Right - 5) % 360;
            glutPostRedisplay();
            break;
        default:
        break;
   }
}

// Função de exibição
void display() {

    /*
    GL_COLOR_BUFFER_BIT: Limpa o buffer de cor é onde as cores 
    dos pixels da tela são armazenadas.

    GL_DEPTH_BUFFER_BIT: Limpa o buffer de profundidade (depth buffer). 
    */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Reseta todas as transformações do frame anterior
    glLoadIdentity();

    // Posiciona a câmera
    gluLookAt(0.0, 0.0, 20.0,  // Posição da câmera
              0.0, 0.0, 0.0,  // Para onde a câmera está olhando
              0.0, 1.0, 0.0); // Qual é a direção "cima" da câmera

    // Rotaciona o cubo
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    
    //face central
    

    glPushMatrix(); // Salva a matriz de transformação atual
    glRotatef ((GLfloat) Front, 1.0, 0.0, 0.0); // Translada o cubo à esquerda
    
    glPopMatrix(); // Restaura a matriz de transformação

    //superior
    cubo cubinho10(2.0,0.0,0.0);
    cubo cubinho11(2.0,0.0,2.0);
    cubo cubinho12(2.0,0.0,-2.0);
    cubo cubinho13(2.0,2.0,0.0);
    cubo cubinho14(2.0,-2.0,0);
    cubo cubinho15(2.0,2.0,2.0);
    cubo cubinho16(2.0,2.0,-2.0);
    cubo cubinho17(2.0,-2.0,2.0);
    cubo cubinho18(2.0,-2.0,-2.0);
    
    //inferior
    cubo cubinho19(-2.0,0.0,0.0);
    cubo cubinho20(-2.0,0.0,2.0);
    cubo cubinho21(-2.0,0.0,-2.0);
    cubo cubinho22(-2.0,2.0,0.0);
    cubo cubinho23(-2.0,-2.0,0.0);
    cubo cubinho24(-2.0,2.0,2.0);
    cubo cubinho25(-2.0,2.0,-2.0);
    cubo cubinho26(-2.0,-2.0,2.0);
    cubo cubinho27(-2.0,-2.0,-2.0);
    
    glutSwapBuffers();
}

// Função de atualização
void update(int value) {
    angleX += 0.2f;
    angleY += 0.1f;

    if (angleX > 360) angleX -= 360;
    if (angleY > 360) angleY -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);  // Atualiza a cada 16 ms (~60 FPS)
}

// Função de inicialização
void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2, 0.2, 0.2, 1.0); // Cor de fundo preta
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}


// Função principal
// argumentos para iniciar glut
int main(int argc, char **argv) {
    glutInit(&argc, argv); //Inicia a janela
    /*
    GLUT_DOUBLE: Habilita o uso de duplo buffering. Em duplo buffering, 
    há dois buffers de imagem: um buffer de frente (front buffer), 
    que é exibido na tela, e um buffer de fundo (back buffer), 
    onde o desenho atual ocorre. Quando o desenho no buffer de
    fundo é concluído, ele é trocado com o buffer de frente.

    GLUT_RGB: Especifica o sistema de cor que será usado pela janela.

    GLUT_DEPTH: Habilita o z-buffer
    */
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //Especifica o tamanho da janela
    glutInitWindowSize(800, 600);
    //especifica a posição da tela na qual a janela será exibida
    glutInitWindowPosition(100, 100);
    //cria a janela com o nome
    glutCreateWindow("Cubo Magico com OpenGL");
    
    init();

    //desenha a tela pela primeira vez a partir da função display
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);
    glutKeyboardFunc(keyboard);

    //loop que mantém o programa executando
    glutMainLoop();
    return 0;
}