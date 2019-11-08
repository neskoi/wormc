#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void delay(int number_of_seconds) {
    // Converting time into milli_seconds
    int milli_seconds =  number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}

void hidecursor(){
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
}

void textcolor (int color){
    static int __BACKGROUND;

    HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

    GetConsoleScreenBufferInfo(h, &csbiInfo);

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             color + (__BACKGROUND << 4));
}

void geraCampo(int x, int y) {
  hidecursor();
  system("CLS");
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      if (i == 0 || i == y-1 || j == 0 || j == x-1) {
        textcolor(6);
        printf("|");
      }else{
        printf(" ");
      }
    }
    printf("\n");
  }
}

COORD setXY(int wy, int wx) {
  COORD pos = {wy, wx};
  return pos;
}

void movimentar(int wx, int wy, int state){
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  if (state == 1) {
    //Cria minhoca
      SetConsoleCursorPosition(hConsole, setXY(wx,wy));
      textcolor(2);
      printf("o");
  }else{
    //Limpa Rastro da minhoca
    SetConsoleCursorPosition(hConsole, setXY(wx,wy));
    printf(" ");
  }
  if (state == 3) {
    SetConsoleCursorPosition(hConsole, setXY(wx,wy));
    textcolor(4);
    printf("@");
  }
}

void scoreShow(int x, int y,int score){
  //movimentar(x, y+5, 0);
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),setXY(x,y));
  textcolor(6);
  printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n||");
  textcolor(14);
  printf(" +---------+ +-+ +-+ +-+ +-+ ");
  textcolor(6);
  printf("|||||||||||||||||||||||||");
  textcolor(2);
  printf("  The Worm Game      ____      ");
  textcolor(6);
  printf("|||||||||||||||||||||||\n||");
   //|T H E   W O R M   G A M E | ||O||O||O||O||O||O||O||
  textcolor(14);
  printf(" |S C O R E| |%d| |%d| |%d| |%d| ",(score%10000)/1000,(score%1000)/100,(score%100)/10,score%10);
  textcolor(6);
  printf("||O|O||O||O||O||O||O||O|| ");
  textcolor(2);
  printf(" __________________/ ");
  textcolor(4);
  printf(" O ");
  textcolor(2);
  printf("\\___/");
  textcolor(6);
  printf(" ||O||O||O||O||O||O||O||\n||");
  textcolor(14);
  printf(" +-+-+-+-+-+ +-+ +-+ +-+ +-+ ");
  textcolor(6);
  printf("|||||||||||||||||||||||||");
  textcolor(2);
  printf(" <_/_\\__/_\\__/_\\_/_______/   \\ ");
  textcolor(6);
  printf("|||||||||||||||||||||||\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
}

int wormDie(int score, int causa){
  int sayBye = 100;
  system("CLS");
  textcolor(6);

  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" |||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("| ");
  textcolor(4);
  printf("Y O U' R E    D E A D");
  textcolor(14);
  printf(" |");
  textcolor(6);
  printf(" |||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" |||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||                                                                                             ");
  textcolor(2);
  printf("____");
  textcolor(6);
  printf("    ||||\n");
  delay(sayBye);
  printf("||||    ");
  textcolor(2);
  printf("________________________________________________________________________________________/ X  \\");
  textcolor(6);
  printf("   ||||\n");
  delay(sayBye);
  printf("||||  ");
  textcolor(2);
  printf("<_/_\\_/_\\_/_\\_/_\\/_\\_/_\\/_\\/_\\_/_\\/_\\/_\\_/_\\/_\\/_\\_/_\\/_\\/_\\_/_\\/_\\/_\\_/_\\/_\\_/_\\_/_\\_/_\\______/");
  textcolor(6);
  printf("   ||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" |||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||");
  textcolor(14);
  printf(" | ");
  textcolor(4);
  printf("F I N A L   S C O R E");
  textcolor(14);
  printf(" | ");
  textcolor(6);
  printf("|||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" |||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+ +-+ +-+ +-+");
  textcolor(6);
  printf(" ||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||||||||||||||||||||||||");
  textcolor(14);
  printf(" |%d| |%d| |%d| |%d| ",(score%10000)/1000,(score%1000)/100,(score%100)/10,score%10);
  textcolor(6);
  printf("||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+ +-+ +-+ +-+");
  textcolor(6);
  printf(" ||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
    printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  if (causa == 0) {
    printf("||||||||||||||||||||||||| ");
    textcolor(14);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    textcolor(6);
    printf(" |||||||||||||||||||||||||\n");
    delay(sayBye);
    printf("||||||||||||||||||||||||| ");
    textcolor(14);
    printf("| Pobre minhoquinha confundiou o rabo com uma frutinha. |");
    textcolor(6);
    printf(" |||||||||||||||||||||||||\n");
    printf("||||||||||||||||||||||||| ");
    textcolor(14);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    textcolor(6);
    printf(" |||||||||||||||||||||||||\n");
  }else{
    printf("|||||||||||| ");
    textcolor(14);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    textcolor(6);
    printf(" ||||||||||||\n");
    delay(sayBye);
    printf("|||||||||||| ");
    textcolor(14);
    printf("| Por nao obedecer os limites de velocidade a minhoca se espatifou contra parede. |");
    textcolor(6);
    printf(" ||||||||||||\n");
    delay(sayBye);
    printf("|||||||||||| ");
    textcolor(14);
    printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
    textcolor(6);
    printf(" ||||||||||||\n");
  }
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  getch();
  return 0;
}

void menu(){
  int sayBye = 80;
  system("CLS");
  textcolor(6);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" |||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||| ");
  textcolor(14);
  printf("|             Deseja iniciar um novo jogo?              |");
  textcolor(6);
  printf(" |||||||||||||||||||||||||\n");
  printf("||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" |||||||||||||||||||||||||\n");
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" ||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" ||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("||||||||||||||||||||||||||||||||||");
  textcolor(14);
  printf(" | ");
  textcolor(2);
  printf("S I M ( S )");
  textcolor(14);
  printf(" | ");
  textcolor(6);
  printf("|||||||");
  textcolor(14);
  printf(" | ");
  textcolor(4);
  printf("N A O ( N )");
  textcolor(14);
  printf(" | ");
  textcolor(6);
  printf("||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" ||||||| ");
  textcolor(14);
  printf("+-+-+-+-+-+-+-+");
  textcolor(6);
  printf(" ||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);

  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);
  printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  delay(sayBye);


}

int main() {
    srand(time(NULL));

  int x = 110,
      y = 20,
      fruitX = 70,
      fruitY = 15,
      speed = 100,
      direction = 0,
      score = 0,
      size = 0,
      alive = 0;

  int wormBody[100][3];
  size_t wormSize = sizeof(wormBody) / sizeof(int);
  char mov = '/', menuSelection = '0';



  while (alive == 0) {
      menu();
      menuSelection = getch();
      if (menuSelection == 's' || menuSelection == 'S') {
        alive = 1;
        score = 0;
        size = 0;
          //Zerando Vetor
        for (int ll = 0; ll <(wormSize/3); ll++) {
          wormBody [ll][0] = 0;
          wormBody [ll][1] = 0;
          wormBody [ll][2] = 0;
        }
        wormBody [0][0] = x/2; //x bola inicial
        wormBody [0][1] = y/2; //y bola inicial
        wormBody [0][2] = 1;   //estado bola inicial
        geraCampo(x,y);
        scoreShow(0,y,score);
        movimentar(fruitX,fruitY,3);


        while (alive == 1) {
        //Define Velocidade de Movimento baseado na pontuacao
        delay((speed-((score/5)*2)));

        //Recebe input de teclado
        if (kbhit()) {
          mov = getch();
        }

        //Analise teclas pressionadas
        switch (mov) {
          case 'w':
            if (direction == 0 || direction == 1 || direction == 3) {
              //define posicao do rabo da minhoca
              for (int i = (wormSize/3)-1; i > 0; i--) {
                wormBody [i][0] = wormBody [i-1][0]; //x
                wormBody [i][1] = wormBody [i-1][1]; //y
              }
              //limita minhoca com as barreiras
              if (wormBody [0][1] > 1) {
                wormBody [0][1]--;
              //analisa e posiciona frutas
                if (wormBody [0][0] == fruitX && wormBody [0][1] == fruitY) {
                  score += 5;
                  //Limita o tamanho da minhoca
                  if (size < (wormSize/3)-2){
                    size++;
                  }
                  //define posicao randomica da fruta
                  fruitX = rand()%x-1;
                  fruitY = rand()%y-1;
                  //Caso qualquer coord seja 0(barreiras), ela se reposiciona pra um local fixo.
                  if (fruitX < 1 || fruitY < 1) {
                      fruitX = 35;
                      fruitY = 15;
                  }
                  //Sempre que come a fruta, ela adiciona colisao e visibilidade a um elemento novo caso o size permita.
                  wormBody[size][2] = 1;
                  scoreShow(0,y,score);
                }
                //Posiciona fruta no local definido anteriormente
                movimentar(fruitX, fruitY,3);
                //analisa pra ver se a minhoca n acertou a minhoca
                for (int j = 0; j <= size+1; j++) {
                  if (wormBody[0][0] == wormBody[j+1][0] && wormBody[0][1] == wormBody[j+1][1] && wormBody[j+1][2] == 1) {
                    alive = wormDie(score,1);
                    break;
                  }else{
                    //Caso a minhoca n tenha se acertado ela pode se mover
                    movimentar(wormBody[j][0],wormBody[j][1], wormBody [j][2]);
                  }
                }
             }else{
              //Perde caso encoste em qualquer barreira
              alive = wormDie(score,0);
            }
            //Flag de direcao, auxilia para que nao possa dar "marcha re".
            direction = 0;
          }else{
            //Devolve a minhoca pra direcao certa caso ela tente andar na oposta.
            mov = 's';
          }
          break;

          case 's':
          if (direction == 1 || direction == 2 || direction == 3) {
            //define posicao do rabo da minhoca
            for (int i = (wormSize/3)-1; i > 0; i--) {
              wormBody [i][0] = wormBody [i-1][0]; //x
              wormBody [i][1] = wormBody [i-1][1]; //y
            }
            //limita minhoca com as barreiras
            if (wormBody [0][1] < y-2) {
              wormBody [0][1]++;
            //analisa e posiciona frutas
              if (wormBody [0][0] == fruitX && wormBody [0][1] == fruitY) {
                score += 5;
                //Limita o tamanho da minhoca
                if (size < (wormSize/3)-2){
                  size++;
                }
                //define posicao randomica da fruta
                fruitX = rand()%x-1;
                fruitY = rand()%y-1;
                //Caso qualquer coord seja 0(barreiras), ela se reposiciona pra um local fixo.
                if (fruitX < 1 || fruitY < 1) {
                    fruitX = 35;
                    fruitY = 15;
                }
                //Sempre que come a fruta, ela adiciona colisao e visibilidade a um elemento novo caso o size permita.
                wormBody[size][2] = 1;
                scoreShow(0,y,score);
              }
              //Posiciona fruta no local definido anteriormente
              movimentar(fruitX, fruitY,3);
              //analisa pra ver se a minhoca n acertou a minhoca
              for (int j = 0; j <= size+1; j++) {
                if (wormBody[0][0] == wormBody[j+1][0] && wormBody[0][1] == wormBody[j+1][1] && wormBody[j+1][2] == 1) {
                  alive = wormDie(score,1);
                }else{
                  //Caso a minhoca n tenha se acertado ela pode se mover
                  movimentar(wormBody[j][0],wormBody[j][1], wormBody [j][2]);
                }
              }
           }else{
            //Perde caso encoste em qualquer barreira
            alive = wormDie(score,0);
          }
          //Flag de direcao, auxilia para que nao possa dar "marcha re".
          direction = 2;
        }else{
          //Devolve a minhoca pra direcao certa caso ela tente andar na oposta.
              mov = 'w';
            }

          break;

          case 'a':
            if (direction == 0 || direction == 1 || direction == 2) {
              //define posicao do rabo da minhoca
              for (int i = (wormSize/3)-1; i > 0; i--) {
                wormBody [i][0] = wormBody [i-1][0]; //x
                wormBody [i][1] = wormBody [i-1][1]; //y
              }
              //limita minhoca com as barreiras
              if (wormBody [0][0] > 1) {
                wormBody [0][0]--;
              //analisa e posiciona frutas
                if (wormBody [0][0] == fruitX && wormBody [0][1] == fruitY) {
                  score += 5;
                  //Limita o tamanho da minhoca
                  if (size < (wormSize/3)-2){
                    size++;
                  }
                  //define posicao randomica da fruta
                  fruitX = rand()%x-1;
                  fruitY = rand()%y-1;
                  //Caso qualquer coord seja 0(barreiras), ela se reposiciona pra um local fixo.
                  if (fruitX < 1 || fruitY < 1) {
                      fruitX = 35;
                      fruitY = 15;
                  }
                  //Sempre que come a fruta, ela adiciona colisao e visibilidade a um elemento novo caso o size permita.
                  wormBody[size][2] = 1;
                  scoreShow(0,y,score);
                }
                //Posiciona fruta no local definido anteriormente
                movimentar(fruitX, fruitY,3);
                //analisa pra ver se a minhoca n acertou a minhoca
                for (int j = 0; j <= size+1; j++) {
                  if (wormBody[0][0] == wormBody[j+1][0] && wormBody[0][1] == wormBody[j+1][1] && wormBody[j+1][2] == 1) {
                    alive = wormDie(score,1);
                  }else{
                    //Caso a minhoca n tenha se acertado ela pode se mover
                    movimentar(wormBody[j][0],wormBody[j][1], wormBody [j][2]);
                  }
                }
             }else{
              //Perde caso encoste em qualquer barreira
              alive = wormDie(score,0);
            }
            //Flag de direcao, auxilia para que nao possa dar "marcha re".
            direction = 1;
            }else{
            //Devolve a minhoca pra direcao certa caso ela tente andar na oposta.
            mov = 'd';
            }
          break;

          case 'd':
          if (direction == 0 || direction == 2 || direction == 3) {
            //define posicao do rabo da minhoca
            for (int i = (wormSize/3)-1; i > 0; i--) {
              wormBody [i][0] = wormBody [i-1][0]; //x
              wormBody [i][1] = wormBody [i-1][1]; //y
            }
            //limita minhoca com as barreiras
            if (wormBody [0][0] < x-2) {
              wormBody [0][0]++;
            //analisa e posiciona frutas
              if (wormBody [0][0] == fruitX && wormBody [0][1] == fruitY) {
                score += 5;
                //Limita o tamanho da minhoca
                if (size < (wormSize/3)-2){
                  size++;
                }
                //define posicao randomica da fruta
                fruitX = rand()%x-1;
                fruitY = rand()%y-1;
                //Caso qualquer coord seja 0(barreiras), ela se reposiciona pra um local fixo.
                if (fruitX < 1 || fruitY < 1) {
                    fruitX = 35;
                    fruitY = 15;
                }
                //Sempre que come a fruta, ela adiciona colisao e visibilidade a um elemento novo caso o size permita.
                wormBody[size][2] = 1;
                scoreShow(0,y,score);
              }
              //Posiciona fruta no local definido anteriormente
              movimentar(fruitX, fruitY,3);
              //analisa pra ver se a minhoca n acertou a minhoca
              for (int j = 0; j <= size+1; j++) {
                if (wormBody[0][0] == wormBody[j+1][0] && wormBody[0][1] == wormBody[j+1][1] && wormBody[j+1][2] == 1) {
                  alive = wormDie(score,1);
                }else{
                  //Caso a minhoca n tenha se acertado ela pode se mover
                  movimentar(wormBody[j][0],wormBody[j][1], wormBody [j][2]);
                }
              }
           }else{
            //Perde caso encoste em qualquer barreira
            alive = wormDie(score,0);
          }
          //Flag de direcao, auxilia para que nao possa dar "marcha re".
          direction = 3;
          }else{
          //Devolve a minhoca pra direcao certa caso ela tente andar na oposta.
          mov = 'a';
        }
          break;

          default:
            switch (direction) {
              case 0:
                mov = 'w';
              break;
              case 1:
                mov = 'a';
              break;
              case 2:
                mov = 's';
              break;
              case 3:
                mov = 'd';
              break;
            }
          break;
        }
      }
      }else if (menuSelection == 'n' || menuSelection == 'N') {
      break;
    }
  }
  return 0;
}
