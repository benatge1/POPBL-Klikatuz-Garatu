#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <windows.h>

#define SOINU_KOP 1
char* soundFiles[] = { ".\\sound\\FondoMusica.wav" };
#define IRUDI_KOP 10
char* imageFiles[] = { ".\\img\\1.bmp", ".\\img\\Kredituak.bmp" };

typedef struct S_GURE_GAUZAK {
    int idSounds[SOINU_KOP];
    int idIrudi[IRUDI_KOP];
}GURE_GAUZAK;

GURE_GAUZAK gureGauzak;

int hasieratu(void);
void trantxizioa(void);
void KredituakJarri(void);
void ArgibideaJarri(void);
void InstrukzioakJarri(void);
void PantallaFinal(void);

int hasieratu(void) {
    int i;
    char str[128];

    if (sgHasieratu() == -1)
    {
        fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
        return 0;
    }
    audioInit();
    for (i = 0; i < SOINU_KOP; i++)
    {
        if ((gureGauzak.idSounds[i] = loadSound(soundFiles[i])) == -1)
        {
            fprintf(stderr, "Unable to load sound %s\n", SDL_GetError());
            return 0;
        }
    }
    if (!loadTheMusic(".\\sound\\MusicaFondo1.mp3"))
    {
        fprintf(stderr, "Unable to load music %s\n", SDL_GetError());
        return 0;
    }
    textuaGaitu();
    pantailaGarbitu();

    return 0;
}

void trantxizioa(void) {
    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
}

void KredituakJarri(void) {

    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;;

    irudiaKargatu(".\\img\\Kredituak.bmp");
    trantxizioa();

    while (!pantaila) {

        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            if ((pos.x > 9) && (pos.x < 129) && (pos.y > 23) && (pos.y < 29 + 20)) {
                irudiaKendu(".\\img\\Kredituak.bmp");
                irudiaKargatu(".\\img\\1.bmp");
                trantxizioa();
                BotoiakHasi();
            }
        }
    }
}

void ArgibideaJarri(void) {
    POSIZIOA pos;
    int pantaila = 0;
    int ebentu = 0;

    irudiaKargatu(".\\img\\Argibideak.bmp");
    trantxizioa();

    while (!pantaila) {

        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            if ((pos.x > 9) && (pos.x < 129) && (pos.y > 23) && (pos.y < 29 + 20)) {

                irudiaKendu(".\\img\\Argibideak.bmp");
                irudiaKargatu(".\\img\\1.bmp");
                trantxizioa();
                BotoiakHasi();
            }
        }
    }
}

void InstrukzioakJarri(void) {
    POSIZIOA pos;
    int pantaila = 0;
    int ebentu = 0;

    irudiaKargatu(".\\img\\Nola_jolastu.bmp");
    trantxizioa();

    while (!pantaila) {

        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            if ((pos.x > 6) && (pos.x < 114) && (pos.y > 28) && (pos.y < 45 + 20)) {
                irudiaKendu(".\\img\\Nola_jolastu.bmp");
                irudiaKargatu(".\\img\\1.bmp");
                trantxizioa();
                BotoiakHasi();
            }
        }
    }
}

void PantallaFinal(void) {

    POSIZIOA pos;
    int pantaila = 0;
    int ebentu = 0;

    irudiaKargatu(".\img\Pantalla_Final.bmp");
    trantxizioa();

    while (!pantaila) {

        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        if (ebentu == TECLA_ESCAPE)
        {
            sgItxi();
        }
    }
}