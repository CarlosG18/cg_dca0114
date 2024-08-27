#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Ângulo de rotação para o cubo
static float angleX = 0.0f;
static float angleY = 0.0f;

int Front, Back, Left, Right, Central, Central1;
int* g_value = nullptr;
GLuint Textura;

bool rot_right = false,  rot_left = false, rot_central1 = false;

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
            
            // Desenhando a face Frontal
            glBegin(GL_QUADS);

                if(this->z == -2.0)
                {
                    glColor4f(0.0f, 0.0f, 1.0f, 0.5f); // Azul
                }
                else
                {
                    glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // preto
                }
                
               glTexCoord2f(0.0, 0.0); glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
               glTexCoord2f(1.0, 0.0); glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
               glTexCoord2f(1.0, 1.0); glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
               glTexCoord2f(0.0, 1.0); glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);

            glEnd();

            // Desenhando a borda
            glBegin(GL_LINE_LOOP);
                glColor4f(0.0, 0.0, 0.0, 0.5); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            // Desenhando a face Traseira
            glBegin(GL_QUADS);
                if(this->z == 2.0)
                {
                    glColor4f(0.0, 1.0, 0.0, 0.5); // Verde
                }
                else
                {
                    glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // preto
                }
                glTexCoord2f(0.0, 0.0); glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 0.0); glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 1.0); glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(0.0, 1.0); glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor4f(0.0, 0.0, 0.0, 0.5); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            // Desenhando a face Esquerda
            glBegin(GL_QUADS);
                if(this->x == 2.0)
                {
                    glColor4f(1.0f, 0.5f, 0.0f, 0.5f); // Laranja
                }
                else
                {
                    glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // preto
                }
                glTexCoord2f(0.0, 0.0); glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 0.0); glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 1.0); glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glTexCoord2f(0.0, 1.0); glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor4f(0.0, 0.0, 0.0, 0.5); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            // Desenhando a face Direita
            glBegin(GL_QUADS);
                if(this->x == -2.0)
                {
                    glColor4f(1.0, 0.0, 0.0, 0.5); // Vermelho
                }
                else
                {
                    glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // preto
                }
                glTexCoord2f(0.0, 0.0); glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 0.0); glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 1.0); glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glTexCoord2f(0.0, 1.0); glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor4f(0.0, 0.0, 0.0, 0.5); // Preto para a borda
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
            glEnd();

            // desenhando a Face Superior
            glBegin(GL_QUADS);
                if(this->y == -2.0)
                {
                    glColor4f(1.0, 1.0, 0.0, 0.5); // Amarelo
                }
                else
                {
                    glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // preto
                }
                glTexCoord2f(0.0, 0.0); glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 0.0); glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 1.0); glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glTexCoord2f(0.0, 1.0); glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor4f(0.0, 0.0, 0.0, 0.5); // Preto para a borda
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glVertex3f( 1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glVertex3f(-1.0-(GLfloat)this->x,  1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            // Desenhando a Face Inferior
                glBegin(GL_QUADS);
                if(this->y == 2.0)
                {
                    glColor4f(1.0, 1.0, 1.0, 0.5); // Branco
                }
                else
                {
                    glColor4f(0.0f, 0.0f, 0.0f, 0.5f); // preto
                }
                glTexCoord2f(0.0, 0.0); glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 0.0); glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y, -1.0-(GLfloat)this->z);
                glTexCoord2f(1.0, 1.0); glVertex3f( 1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
                glTexCoord2f(0.0, 1.0); glVertex3f(-1.0-(GLfloat)this->x, -1.0-(GLfloat)this->y,  1.0-(GLfloat)this->z);
            glEnd();

            glBegin(GL_LINE_LOOP);
                glColor4f(0.0, 0.0, 0.0, 0.5); // Preto para a borda
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
        cubo *front, *back, *left, *right, *central1, *central;

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

        void face(char type){
            if(type=='l'){
                for(int i=0; i < 3; i++){
                    for(int j=0; j <=2; j++){
                        if(i == 0){
                            this->front[j].drawCube();
                        }else if(i == 1){
                            this->central[j].drawCube();
                        }else{
                            this->back[j].drawCube();
                        }
                    }
                }
            }else if (type=='s'){
                for(int i=0; i < 3; i++){
                    for(int j=3; j <= 5 ; j++){
                        if(i == 0){
                            this->front[j].drawCube();
                        }else if(i == 1){
                            this->central[j].drawCube();
                        }else{
                            this->back[j].drawCube();
                        }
                    }
                }
            }else if (type=='r'){
                for(int i=0; i < 3; i++){
                    for(int j=6; j <= 8; j++){
                        if(i == 0){
                            this->front[j].drawCube();
                        }else if(i == 1){
                            this->central[j].drawCube();
                        }else{
                            this->back[j].drawCube();
                        }
                    }
                }
            }else if (type=='b'){
                for(int i=0; i < 9; i++){
                    this->back[i].drawCube();
                }
            }else if (type=='f'){
                for(int i=0; i < 9; i++){
                    this->front[i].drawCube();
                }
            }else if (type=='c'){
                for(int i=0; i < 9; i++){
                    this->central[i].drawCube();
                }
            }
        }

        void atualiza_face(){
            cubo matriz_aux[3][3];
            for(int i=0; i < 3; i++){
                for(int j=0; j < 3; j++){
                    matriz_aux[i][j] = this->matriz[i][j][0];
                }
            }

            // atualizando a face front
            for(int i=0; i < 3; i++){
                for(int j=0; j < 3; j++){
                    this->matriz[i][j][0] = matriz_aux[2-j][i];
                }
            }

            //atualizando a face 
            
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

            //definindo a face back
            for(int i=0; i < this->nx; i++){
                for(int j=0; j < this->ny; j++){
                    this->back[i*3+j] = this->matriz[i][j][2];
                }
            }
        }
};

CuboMagico cubomag(3,3,3);

void rotate_horario(int){
    (*g_value)++;
    if (((*g_value) % 90) == 1 && (*g_value) != 1){
        //cubomag.atualiza_face();
    }else {
        glutPostRedisplay();
        glutTimerFunc(10, rotate_horario, 0);
    }
}

void rotate_anti_horario(int){
    
}



//Função teclado rotação
void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 'f':
            g_value = &Front;
            rot_right = false, rot_left = false, rot_central1 = false;
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
            rot_right = false, rot_left = false, rot_central1 = false;
            glutTimerFunc(10, rotate_horario, 0);
            glutPostRedisplay();
            break;
        case 'B':  /*  e key rotates at elbow  */
            g_value = &Back;
            glutTimerFunc(10, rotate_anti_horario, 0);
            glutPostRedisplay();
            break;
        case 'l':
            g_value = &Left;
            rot_left = true;
            glutTimerFunc(10, rotate_horario, 0);
            glutPostRedisplay();
            break;
        case 'L':
            g_value = &Left;
            glutTimerFunc(10, rotate_anti_horario, 0);
            glutPostRedisplay();
            break;
        case 'r':
            g_value = &Right;
            rot_right = true;
            glutTimerFunc(10, rotate_horario, 0);
            glutPostRedisplay();
            break;
        case 'R':
            g_value = &Right;
            cubomag.atualiza_face();
            glutTimerFunc(10, rotate_anti_horario, 0);
            glutPostRedisplay();
            break;
        case 'c':
            g_value = &Central;
            rot_right = false, rot_left = false, rot_central1 = false;
            glutTimerFunc(10, rotate_horario, 0);
            glutPostRedisplay();
            break;
        case 'C':
            g_value = &Central;
            glutTimerFunc(10, rotate_anti_horario, 0);
            glutPostRedisplay();
            break;
        case 's':
            g_value = &Central1;
            rot_central1 = true;
            glutTimerFunc(10, rotate_horario, 0);
            glutPostRedisplay();
            break;
        case 'S':
            g_value = &Central1;
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

    //habilitando textura
    glEnable(GL_TEXTURE_2D);
    
    if(rot_right || rot_left || rot_central1){
        glPushMatrix(); // Salva a matriz de transformação atual
        glRotatef ((GLfloat) Right, 1.0, 0.0, 0.0);
        cubomag.face('r');
        glPopMatrix(); // Restaura a matriz de transformação

        glPushMatrix(); // Salva a matriz de transformação atual
        glRotatef ((GLfloat) Left, 1.0, 0.0, 0.0);
        cubomag.face('l');
        glPopMatrix(); // Restaura a matriz de transformação

        glPushMatrix(); // Salva a matriz de transformação atual
        glRotatef ((GLfloat) Central1, 1.0, 0.0, 0.0); 
        cubomag.face('s');
        glPopMatrix(); // Restaura a matriz de transformação
        
    }else{
            // rotação da face frontal
        glPushMatrix(); // Salva a matriz de transformação atual
        glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glRotatef ((GLfloat) Front, 0.0, 0.0, 1.0);
        cubomag.face('f');
        glPopMatrix(); // Restaura a matriz de transformação
 
        // rotação da face central
        glPushMatrix(); // Salva a matriz de transformação atual
        glRotatef ((GLfloat) Central, 0.0, 0.0, 1.0); 
        cubomag.face('c');
        glPopMatrix(); // Restaura a matriz de transformação
        
        // rotação da face traseira
        glPushMatrix(); // Salva a matriz de transformação atual
        glRotatef ((GLfloat) Back, 0.0, 0.0, 1.0);
        cubomag.face('b');
        glPopMatrix(); // Restaura a matriz de transformação
    }
    
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
    glEnable(GL_BLEND); // Habilita o blend
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.2, 0.2, 0.2, 1.0); // Cor de fundo preta
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    
    // Configurações de Textura
    unsigned char *data;
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    data = stbi_load("metalico_textura.jpg", &width, &height, &nrChannels, 4);

    glGenTextures(1, &Textura);
    glBindTexture(GL_TEXTURE_2D, Textura);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
                    GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
                    GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 50, 
                    50 , 0, GL_RGBA, GL_UNSIGNED_BYTE, 
                    data);
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
    glDisable(GL_TEXTURE_2D);
    glDeleteTextures(1, &Textura);
    return 0;
}