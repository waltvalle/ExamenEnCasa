
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<windows.h>
#include<SDL_mixer.h>
#include <time.h>
using namespace std;
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *black,*background,*character,*pregunta,*menu,*inst,*carro, *crono,*estado,*corazon,*cadena;
SDL_Rect rect_background,rect_character,rect_pregunta,rect_menu,rect_inst,rect_black,rect_carro,rect_crono,rect_estado,rect_corazon,rect_cadena;
boolean tiempo=false;
int vidas=1;
int win=0,perder=0;

int main( int argc, char* args[] )
{
Mix_Music* music;
Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,4096);
music=Mix_LoadMUS("music/Highway To Hell.mp3");
Mix_PlayMusic(music,-1);
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 800/*WIDTH*/, 600/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {

        return 20;
    }

    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //nuestras imagenes
    int w=0,h=0;
    black = IMG_LoadTexture(renderer,"img/black.png");
    SDL_QueryTexture(black, NULL, NULL, &w, &h);
    rect_black.x = 0;
    rect_black.y = 0;
    rect_black.w = 800;
    rect_black.h = 600;

    cadena = IMG_LoadTexture(renderer,"img/caff.png");
    SDL_QueryTexture(cadena, NULL, NULL, &w, &h);
    rect_cadena.x =460;
    rect_cadena.y = 520;
    rect_cadena.w = 300;
    rect_cadena.h = 20;


    inst = IMG_LoadTexture(renderer,"img/instrucciones.png");
    SDL_QueryTexture(inst, NULL, NULL, &w, &h);
    rect_inst.x = 900;
    rect_inst.y = 0;
    rect_inst.w = 800;
    rect_inst.h = 600;

    background = IMG_LoadTexture(renderer,"img/background.png");
    SDL_QueryTexture(inst, NULL, NULL, &w, &h);
    rect_background.x = 900;
    rect_background.y = 0;
    rect_background.w = 800;
    rect_background.h = 600;

    menu = IMG_LoadTexture(renderer,"img/menu.png");
    SDL_QueryTexture(menu, NULL, NULL, &w, &h);
    rect_menu.x = 0;
    rect_menu.y = 0;
    rect_menu.w = 800;
    rect_menu.h = 600;

       corazon = IMG_LoadTexture(renderer,"img/viddsd.png");
    SDL_QueryTexture(menu, NULL, NULL, &w, &h);
    rect_corazon.x = 680;
    rect_corazon.y = 30;
    rect_corazon.w = 100;
    rect_corazon.h = 35;

    carro = IMG_LoadTexture(renderer,"img/carro.png");
    SDL_QueryTexture(menu, NULL, NULL, &w, &h);
    rect_carro.x = 300;
    rect_carro.y = 900;
    rect_carro.w = 180;
    rect_carro.h = 65;


    pregunta = IMG_LoadTexture(renderer,"img/cjh.png");
    SDL_QueryTexture(pregunta, NULL, NULL, &w, &h);
    rect_pregunta.x = 200;
    rect_pregunta.y = 70;
    rect_pregunta.w = 400;
    rect_pregunta.h = 300;

    crono = IMG_LoadTexture(renderer,"img/crono.png");
    SDL_QueryTexture(black, NULL, NULL, &w, &h);
    rect_crono.x = 900;
    rect_crono.y = 0;
    rect_crono.w = 300;
    rect_crono.h = 30;

    estado = IMG_LoadTexture(renderer,"img/es.png");
    SDL_QueryTexture(estado, NULL, NULL, &w, &h);
    rect_estado.x = 0;
    rect_estado.y = 0;
    rect_estado.w = 800;
    rect_estado.h = 600;

//  este while ejecuta constantemente todas las funciones que los eventos realicen
    while(true)
    {

        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
//              este if ejecuta el inicio del juego y todas sus funciones
                if(Event.key.keysym.sym == SDLK_1){
                        //><
                    tiempo=true;
                    rect_menu.x=900;
                    rect_background.x=0;
                    rect_background.y=0;
                    rect_crono.x=30;
                    rect_crono.y=30;
                    rect_inst.x=990;
                    rect_carro.y=500;
                    tiempo=true;
                    pregunta = IMG_LoadTexture(renderer,"img/acertijo.png");
                    corazon = IMG_LoadTexture(renderer,"img/vidas.png");
                    cadena = IMG_LoadTexture(renderer,"img/cadena.png");

                    }
//                  con este if se muestran la instrucciones
                    if(Event.key.keysym.sym == SDLK_2){
                        rect_menu.x=900;
                        rect_inst.x=0;
                        rect_inst.y=0;

                    }
//                  este if se encarga de terminar el juego
                    if(Event.key.keysym.sym == SDLK_3){

                        SDL_Quit();
                     }
//                  esta es la tecla que haa ganar al usuario
                    if(Event.key.keysym.sym == SDLK_a)
                    {

                    rect_carro.x=30;
                    rect_estado.x=0;
                    tiempo=false;
                    win=1;
                    }
//                  esta tecla que haa perder al usuario
                    if(Event.key.keysym.sym == SDLK_b)
                    {
                    rect_carro.x=600;
                    rect_cadena.x=780;
                    rect_estado.x=0;
                    tiempo=false;
                    rect_corazon.x = 900;
                    perder=1;

                    }
//                  esta tecla que haa perder al usuario
                    if(Event.key.keysym.sym == SDLK_c)
                    {
                    rect_carro.x=600;
                    rect_cadena.x=780;
                    rect_estado.x=0;
                    tiempo=false;
                    rect_corazon.x = 900;
                    perder=1;
                    }
//                  esta es la tecla para el reiniciado y
//                  evalua los posibles casos en el conteo e vidas y victorias o perdidas
                    if(Event.key.keysym.sym == SDLK_r)
                    {
                        if(vidas==0&&win==1){

                    tiempo=false;
                    rect_background.x=0;
                    rect_background.y=0;
                    rect_crono.x=30;
                    rect_crono.y=30;
                    rect_carro.x=300;
                    rect_carro.y=500;
                    rect_cadena.x=450;
                    rect_crono.w=500;
                    rect_estado.x=900;
                    rect_menu.x=900;
                    rect_inst.x=900;
                    rect_corazon.x = 750;
                    tiempo=true;
                    pregunta = IMG_LoadTexture(renderer,"img/acertijo.png");
                    vidas++;
                    }

                    if(vidas==1&&win==2){

                    tiempo=false;
                    rect_background.x=0;
                    rect_background.y=0;
                    rect_crono.x=30;
                    rect_crono.y=30;
                    rect_carro.x=300;
                    rect_carro.y=500;
                    rect_cadena.x=450;
                    rect_crono.w=500;
                    rect_estado.x=900;
                    rect_menu.x=900;
                    rect_inst.x=900;
                     rect_corazon.x = 750;
                    tiempo=true;
                     pregunta = IMG_LoadTexture(renderer,"img/acertijo.png");
                     vidas++;
                     }
                    if(vidas==0&&perder==1){

                    tiempo=false;
                    rect_background.x=0;
                    rect_background.y=0;
                    rect_crono.x=30;
                    rect_crono.y=30;
                    rect_carro.x=300;
                    rect_carro.y=500;
                    rect_cadena.x=450;
                    rect_crono.w=500;
                    rect_estado.x=900;
                    rect_menu.x=900;
                    rect_inst.x=900;
                    rect_corazon.x = 750;
                    tiempo=true;
                    pregunta = IMG_LoadTexture(renderer,"img/acertijo.png");
                    vidas++;
                    }

                    if(vidas==1&&perder==2){

                    tiempo=false;
                    rect_background.x=0;
                    rect_background.y=0;
                    rect_crono.x=30;
                    rect_crono.y=30;
                    rect_carro.x=300;
                    rect_carro.y=500;
                    rect_cadena.x=450;
                    rect_crono.w=500;
                    rect_estado.x=900;
                    rect_menu.x=900;
                    rect_inst.x=900;
                    rect_corazon.x = 750;
                    tiempo=true;
                    pregunta = IMG_LoadTexture(renderer,"img/acertijo.png");
                    vidas++;
                    }
                }


            }

}
        //render

        SDL_RenderCopy(renderer, inst, NULL, &rect_inst);
        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, crono, NULL, &rect_crono);
        SDL_RenderCopy(renderer, menu, NULL, &rect_menu);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, cadena, NULL, &rect_cadena);
        SDL_RenderCopy(renderer, carro, NULL, &rect_carro);
        SDL_RenderCopy(renderer, pregunta, NULL, &rect_pregunta);
        SDL_RenderCopy(renderer, estado, NULL, &rect_estado);
        SDL_RenderCopy(renderer, corazon, NULL, &rect_corazon);
        SDL_RenderPresent(renderer);


   //sentencia de tiempo
    if(tiempo==true)
    {
int SEGUNDO, ML;
           for (SEGUNDO=0; SEGUNDO<3; SEGUNDO++)     {
             for (ML=0; ML<18.9; ML++){
system("cls");
}
rect_crono.w--;
if(rect_crono.w<=0){
    tiempo=false;
    estado = IMG_LoadTexture(renderer,"img/perdiste.png");
    rect_corazon.x=900;

        }
    }
}

if(win==1){
SDL_Delay(900);

    estado = IMG_LoadTexture(renderer,"img/ganaste.png");
    rect_corazon.x=900;
win=2;

}
if(perder==1)
{
    SDL_Delay(900);
    estado = IMG_LoadTexture(renderer,"img/perdiste.png");
    rect_corazon.x=900;
    perder=2;
}
}


Mix_FreeMusic(music);
Mix_CloseAudio();
	return 0;
}
