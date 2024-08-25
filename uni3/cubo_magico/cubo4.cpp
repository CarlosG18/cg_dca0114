#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <string>

// Ângulo de rotação para o cubo
static float angleX = 0.0f;
static float angleY = 0.0f;

int Front = 0, Back, Left, Right, Up, Down, Central;
int* g_value = nullptr;


class cubo{
    public:
        float x, y, z;

        cubo() : x(0), y(0), z(0){}

        cubo(float dx,float dy,float dz): x(dx), y(dy), z(dz) {
            drawCube();

            return;
        }

        void drawCube() {
            
            glLineWidth(5.0f); // Define a largura da linha
            // Face Frente
            glBegin(GL_QUADS);
                if(this->z == -2.0)
                {
                    glColor3f(0.0f, 0.0f, 1.0f); // Azul
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            // Face Traseira
            glBegin(GL_QUADS);
                if(this->z == 2.0)
                {
                    glColor3f(0.0, 1.0, 0.0); // Verde
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            // Face Esquerda
            glBegin(GL_QUADS);
                if(this->x == 2.0)
                {
                    glColor3f(1.0, 0.5f, 0.0); // Laranja
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            // Face Direita
            glBegin(GL_QUADS);
                if(this->x == -2.0)
                {
                    glColor3f(1.0, 0.0, 0.0); // Vermelho
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            // Face Superior
            glBegin(GL_QUADS);
                if(this->y == -2.0)
                {
                    glColor3f(1.0, 1.0, 0.0); // Amarelo
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            // Face Inferior
            glBegin(GL_QUADS);
                if(this->y == 2.0)
                {
                    glColor3f(1.0, 1.0, 1.0); // Branco
                }
                else
                {
                    glColor3f(0.0f, 0.0f, 0.0f); // preto
                }
                
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor3f(0.0, 0.0, 0.0); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();                 
        }
    private:
    
};

class CuboMagico{
    public:
        cubo ***matriz;
        int nx, ny, nz;
        cubo *front, *back, *left, *right, *up, *down, *central;

        CuboMagico(int nx, int ny,int nz): nx(nx), ny(ny), nz(nz) {
            create_cube(nx,ny,nz);
            create_faces();
        }

        ~CuboMagico() {
            // Destrói a matriz alocada dinamicamente para evitar vazamentos de memória
            for (int i = 0; i < this->nx; i++) {
                for (int j = 0; j < this->ny; j++) {
                    delete[] matriz[i][j];
                }
                delete[] matriz[i];
            }
            delete[] matriz;
        }

        void show(){
            for (int i = 0; i < this->nx; i++) {
                for (int j = 0; j < this->ny; j++) {
                    for (int k = 0; k < this->nz; k++) {
                        this->matriz[i][j][k].drawCube();
                    }
                }
            }
        }

        void face(char type){
            if(type=='l'){
                for(int i=0; i < 9; i++){
                    this->left[i].drawCube();
                }
            }else if (type=='u'){
                for(int i=0; i < 9; i++){
                    this->up[i].drawCube();
                }
            }else if (type=='r'){
                for(int i=0; i < 9; i++){
                    this->right[i].drawCube();
                }
            }else if (type=='b'){
                for(int i=0; i < 9; i++){
                    this->back[i].drawCube();
                }
            }else if (type=='f'){
                for(int i=0; i < 9; i++){
                    this->front[i].drawCube();
                }
            }else if (type=='d'){
                for(int i=0; i < 9; i++){
                    this->down[i].drawCube();
                }
            }else if (type=='c'){
                for(int i=0; i < 9; i++){
                    this->central[i].drawCube();
                }
            }
        }

    private:

        void create_cube(int nx, int ny, int nz){
            matriz = (cubo ***)new cubo **[nx];
            matriz[0] = (cubo **) new cubo *[nx * ny];
            matriz[0][0] =(cubo *) new cubo [nx * ny * nz];

            for (int i = 1; i < nx; i++)
                matriz[i] = matriz[i - 1] + ny;

            for (int j = 1; j < nx * ny; j++){
                matriz[0][j] = matriz[0][j - 1] + nz;
            }

            float offset = 2.0; // Deslocamento do cubo

            for (int i = 0; i < nx; i++) {
                for (int j = 0; j < ny; j++) {
                    for (int k = 0; k < nz; k++) {
                        float x = (i - 1) * offset;  // Ajusta o eixo x para -2.0, 0.0, 2.0
                        float y = (j - 1) * offset;  // Ajusta o eixo y para -2.0, 0.0, 2.0
                        float z = (k - 1) * offset;  // Ajusta o eixo z para -2.0, 0.0, 2.0

                        // Cria o cubo na posição (x, y, z)
                        matriz[i][j][k] = cubo(x, y, z);
                    }
                }
            }
        }

        void create_faces(){
            this->front = new cubo[this->nx * this->ny];
            this->back = new cubo[this->nx * this->ny];
            this->left = new cubo[this->nx * this->ny];
            this->right = new cubo[this->nx * this->ny];
            this->up = new cubo[this->nx * this->ny];
            this->down = new cubo[this->nx * this->ny];
            this->central = new cubo[this->nx * this->ny];

            //definindo a face front
            for(int i=0; i < this->nx; i++){
                for(int j=0; j < this->ny; j++){
                    this->front[i*3+j] = this->matriz[i][j][0];
                }
            }

            //definindo a face central
            for(int i=0; i < this->nx; i++){
                for(int j=0; j < this->ny; j++){
                    this->central[i*3+j] = this->matriz[i][j][1];
                }
            }

            //definindo a face
            for(int i=0; i < this->nx; i++){
                for(int j=0; j < this->ny; j++){
                    this->back[i*3+j] = this->matriz[i][j][2];
                }
            }
        }
};

CuboMagico cubomag(3,3,3);

/*
void rotate(int value){
    Front++;
    if(Front < 90){
        glutTimerFunc(10, rotate, 0);
    }else{
        //cubomag.atualiza_face();
        Front = 0;
    }
    
}*/


void rotate_horario(int){
    (*g_value)++;
    if (((*g_value) % 90) == 1 && (*g_value) != 1){
        //cubomag.atualiza_face();
    }else {
        glutTimerFunc(10, rotate_horario, 0);
    }
}

void rotate_anti_horario(int){
    (*g_value)--;
    if (((*g_value) % 90) == -1 && (*g_value) != -1) {
        glutTimerFunc(10, rotate_anti_horario, 0);
    } else {
        
        //cubomag.atualiza_face();
    }
}



//Função teclado rotação
void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'f':   /*  s key rotates at shoulder  */
            g_value = &Front;
            glutTimerFunc(10, rotate_horario, 0);
            glutPostRedisplay();
            break;
        case 'F':
            g_value = &Front;
            glutTimerFunc(10, rotate_anti_horario, 0);
            glutPostRedisplay();
            break;
        case 'b':  /*  e key rotates at elbow  */
            g_value = &Back;
            glutTimerFunc(10, rotate_horario, 0);
            glutPostRedisplay();
            break;
        case 'B':  /*  e key rotates at elbow  */
            g_value = &Back;
            glutTimerFunc(10, rotate_anti_horario, 0);
            glutPostRedisplay();
            break;
        case 'u':
            Up = (Up + 1) % 360;
            glutPostRedisplay();
            break;
        case 'U':
            Up = (Up - 1) % 360;
            glutPostRedisplay();
            break;
        case 'd':
            Down = (Down + 1) % 360;
            glutPostRedisplay();
            break;
        case 'D':
            Down = (Down - 1) % 360;
            glutPostRedisplay();
            break;
        case 'l':
            Left = (Left + 1) % 360;
            glutPostRedisplay();
            break;
        case 'L':
            Left = (Left - 1) % 360;
            glutPostRedisplay();
            break;
        case 'r':
            Right = (Right + 1) % 360;
            glutPostRedisplay();
            break;
        case 'R':
            Right = (Right - 1) % 360;
            glutPostRedisplay();
            break;
        case 'c':
            g_value = &Central;
            glutTimerFunc(10, rotate_horario, 0);
            glutPostRedisplay();
            break;
        case 'C':
            g_value = &Central;
            glutTimerFunc(10, rotate_anti_horario, 0);
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
    
    /*
    glPushMatrix(); // Salva a matriz de transformação atual
    glRotatef ((GLfloat) Left, 1.0, 0.0, 0.0); // Translada o cubo à esquerda
    cubomag.face('l');
    glPopMatrix(); // Restaura a matriz de transformação

    glPushMatrix(); // Salva a matriz de transformação atual
    glRotatef ((GLfloat) Up, 0.0, 1.0, 0.0); // Translada o cubo à esquerda
    cubomag.face('u');
    glPopMatrix(); // Restaura a matriz de transformação*/

    glPushMatrix(); // Salva a matriz de transformação atual
    glRotatef ((GLfloat) Front, 0.0, 0.0, 1.0); // Translada o cubo à esquerda
    cubomag.face('f');
    glPopMatrix(); // Restaura a matriz de transformação

    glPushMatrix(); // Salva a matriz de transformação atual
    glRotatef ((GLfloat) Central, 0.0, 0.0, 1.0); // Translada o cubo à esquerda
    cubomag.face('c');
    glPopMatrix(); // Restaura a matriz de transformação

    glPushMatrix(); // Salva a matriz de transformação atual
    glRotatef ((GLfloat) Back, 0.0, 0.0, 1.0); // Translada o cubo à esquerda
    cubomag.face('b');
    glPopMatrix(); // Restaura a matriz de transformação

    //cubomag.show();
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
    glutTimerFunc(10, update, 0);
    glutKeyboardFunc(keyboard);

    //loop que mantém o programa executando
    glutMainLoop();
    return 0;
}