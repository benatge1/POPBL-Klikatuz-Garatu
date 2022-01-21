#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <windows.h>

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."

#define JOKOA_SOUND ".\\sound\\FondoMusica.wav"

#define SOINU_KOP 7
char* soundFiles[] = { ".\\sound\\128GBVHR_01.wav", ".\\sound\\128NIGHT_01.wav", ".\\sound\\132TRANCE_02.wav",
                        ".\\sound\\BugleCall.wav",  ".\\sound\\terminator.wav", ".\\sound\\ilventodoro.wav", ".\\sound\\FondoMusica.wav" };

#define IRUDI_KOP 10
char* imageFiles[] = {  ".\\img\\Sarrera.bmp", ".\\img\\Kredituak.bmp" };

typedef struct S_GURE_GAUZAK
{
  int idSounds[SOINU_KOP];
  int idIrudi[IRUDI_KOP];

}GURE_GAUZAK;

GURE_GAUZAK gureGauzak;

int DistritosMaxeados2 = 0;
int DistritosMaxeados3 = 0;
int DistritosMaxeados4 = 0;
double click = 0;

int hasieratu(void);
void sarreraMezuaIdatzi(void);
void trantxizioa(void);
void KredituakJarri(void);
void ArgibideaJarri(void);
void BotoiakHasi(void);
void JokoarenHasiera(int upgrade0, int upgrade1, int upgrade2);
void BigarrenDistrito(int upgrade0, int upgrade1, int upgrade2);
void HirugarrenDistrito(int upgrade0, int upgrade1, int upgrade2);
void LaugarrenDistrito(int upgrade0, int upgrade1, int upgrade2);
void Distrito1Maxeado(void);
void Distrito2Maxeado(void);
void Distrito3Maxeado(void);
void Distrito4Maxeado(void);
void KlikContador(void);

int main(int argc, char * str[]) 
{
    hasieratu();
    sarreraMezuaIdatzi();
    BotoiakHasi();
    audioTerminate();
    sgItxi();
    pantailaBerriztu();
    pantailaGarbitu();

}


void BotoiakHasi(void) {

    int ebentu = 0;
    int menu = 0;
    int upgrade0 = 0;
    int upgrade1 = 11;
    int upgrade2 = 11;
    int azkena = 0;
    POSIZIOA pos;
    pos = saguarenPosizioa();

    irudiaKargatu(".\\img\\Sarrera.bmp");
    azkena = ".\\img\\Sarrera.bmp";
    trantxizioa();

    printf("HASI DA\n");
    printf("__X:%d -- Y:%d__\n", pos.x, pos.y);

    while (!menu)
    {
            ebentu = ebentuaJasoGertatuBada();
            pos = saguarenPosizioa();
            printf("__X:%d -- Y:%d__\n", pos.x, pos.y);

            if (ebentu == SAGU_BOTOIA_EZKERRA) {

                if ((pos.x > 235) && (pos.x < 340 + 40) && (pos.y > 200) && (pos.y < 200 + 40)) {
                    irudiaKendu(azkena);
                    JokoarenHasiera(upgrade0, upgrade1, upgrade2);
                    KlikContador();
                    menu = 1;
                }

                if ((pos.x > 257) && (pos.x < 320 + 40) && (pos.y > 260) && (pos.y < 245 + 40)) {

                    
                    irudiaKendu(".\\img\\Sarrera.bmp");
                    KredituakJarri();
                    menu = 1;
                }

                if ((pos.x > 262) && (pos.x < 313 + 40) && (pos.y > 308) && (pos.y < 300 + 40)) {

                    irudiaKendu(".\\img\\Sarrera.bmp");
                    ArgibideaJarri();
                    menu = 1;
                }             
            }
            if (ebentu == TECLA_ESCAPE) { 
                sgItxi(); 
            }
            else if (ebentu == TECLA_SPACE) {
                toggleMusic();
            }
            if (ebentu == TECLA_RETURN) {
                trantxizioa();
                irudiakMarraztu();
                printf("EZ DA KARGATZEN");
                                
            }
    }
}

void KlikContador(void) {
    char str[128];
    int ebentu = 0;
    POSIZIOA pos;
    pos = saguarenPosizioa();


    while (click != 100) {

        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        printf("Sartzen da\n");

        if (ebentu == SAGU_BOTOIA_EZKERRA) 
        {
            if (click != 100 && (pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) 
            {
                click++;
                printf("%f\n", click);
                sprintf(str, "%lf", click);
                textuaIdatzi(350, 50, str);
                pantailaBerriztu();
            }
        }
    }
}

void trantxizioa(void) {

    pantailaGarbitu();
    irudiakMarraztu();
    pantailaBerriztu();
}

void sarreraMezuaIdatzi(void)
{
    pantailaGarbitu();
    textuaIdatzi(225, 200, ONGI_ETORRI_MEZUA);
    pantailaBerriztu();
}

void JokoarenHasiera(int upgrade0, int upgrade1, int upgrade2) {

    char str[128];
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;

    int mejoras0 = upgrade0, mejoras1 = upgrade1, mejoras2 = upgrade2;
    int zero = upgrade0, hamaika = upgrade1, hamaika1 = upgrade2;

    if (mejoras2 <= 11) {
        irudiaKargatu(".\\img\\Casas_pobres_solo.bmp");
        azkena = ".\\img\\Casas_pobres_solo.bmp";
        trantxizioa();
    }
    else {
        irudiaKargatu(".\\img\\Etxe_Hobetuak.bmp");
        azkena = ".\\img\\Etxe_Hobetuak.bmp";
        trantxizioa();
    }

    while (!pantaila) {

        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        printf("%f", click);


            while (mejoras0 <= 10 && mejoras1 > 10 && mejoras2 > 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 18) && (pos.x < 199) && (pos.y > 419) && (pos.y < 450))
                    {
                        mejoras0++;
                        click = click - 10;
                        printf("%d\n", mejoras0);
                        if (mejoras0 == 10)
                        {
                            mejoras1 = 0;

                        }
                    }
                    printf("SI REGISTRA\n");
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT))
                    {
                        click++;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf", click);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 <= 10 && mejoras2 > 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 222) && (pos.x < 403) && (pos.y > 419) && (pos.y < 450))
                    {
                        mejoras1++;
                        click = click - 20;
                        printf("%d\n", mejoras1);
                        if (mejoras1 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Eskolarekin.bmp");
                            azkena = ".\\img\\Eskolarekin.bmp";
                            trantxizioa();
                        }
                        if (mejoras1 == 10)
                        {
                            mejoras2 = 0;

                        }
                        
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT))
                    {
                        click++;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf", click);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 >= 10 && mejoras2 <= 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 425) && (pos.x < 605) && (pos.y > 419) && (pos.y < 450))
                    {
                        mejoras2++;
                        click = click - 30;
                        printf("%d\n", mejoras2);
                        if (mejoras2 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Etxe_Hobetuak.bmp");
                            azkena = ".\\img\\Etxe_Hobetuak.bmp";
                            trantxizioa();
                        }
                        else if (mejoras2 == 10)
                        {
                            mejoras0 = 10;
                            mejoras1 = 10;
                            mejoras2 = 9;
                        }
                    }
                    else if ((mejoras2 >= 9) && (pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79)) {

                        printf("KLIKATZEN DU");
                        irudiaKendu(azkena);
                        BigarrenDistrito(0, 11, 11);
                        pantaila = 1;
                    }
                    else if ((mejoras2 >= 9) && (pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79)) {

                        irudiaKendu(azkena);
                        HirugarrenDistrito(0, 11, 11);
                        pantaila = 1;
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT) && mejoras2 < 8);
                    {
                        click++;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf", click);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras2 >= 12 && mejoras0 == 10 && mejoras1 == 10)
            {

                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        Distrito2Maxeado();
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79))
                    {
                        irudiaKendu(azkena);
                        HirugarrenDistrito(0, 11, 11);
                        pantaila = 1;
                    }
                }   
            }
            while (mejoras1 >= 12 && mejoras0 == 10 && mejoras2 == 10)
            {

                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        BigarrenDistrito(0, 11, 11);
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        Distrito3Maxeado();
                        pantaila = 1;
                    }
                }

                if (ebentu == TECLA_m) {
                    irudiaKendu(azkena);
                    BotoiakHasi();
                    pantaila = 1;
                }
            }
         }   
    
}

void BigarrenDistrito(int upgrade0, int upgrade1, int upgrade2) {
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;

    int mejoras0 = upgrade0, mejoras1 = upgrade1, mejoras2 = upgrade2;
    int zero = upgrade0, hamaika = upgrade1, hamaika1 = upgrade2;
    if (mejoras2 <= 11) {
        irudiaKargatu(".\\img\\Distrito2_Nada.bmp");
        azkena = ".\\img\\Distrito2_Nada.bmp";
        trantxizioa();
    }
    else {
        irudiaKargatu(".\\img\\Distrito2_Estacion.bmp");
        azkena = ".\\img\\Distrito2_Estacion.bmp";
        trantxizioa();
    }

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        


        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            while (mejoras0 <= 10 && mejoras1 > 10 && mejoras2 > 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 17) && (pos.x < 171) && (pos.y > 412) && (pos.y < 447))
                    {
                        mejoras0++;
                        printf("%d\n", mejoras0);

                        if (mejoras0 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito2_Cuartel.bmp");
                            azkena = ".\\img\\Distrito2_Cuartel.bmp";
                            trantxizioa();
                        }

                        if (mejoras0 == 10)
                        {
                            mejoras1 = 0;                            
                        }
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 <= 10 && mejoras2 > 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 192) && (pos.x < 345) && (pos.y > 412) && (pos.y < 447))
                    {
                        mejoras1++;
                        printf("%d\n", mejoras1);

                        if (mejoras1 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito2_Casa.bmp");
                            azkena = ".\\img\\Distrito2_Casa.bmp";
                            trantxizioa();
                        }
                        if (mejoras1 == 10)
                        {
                            mejoras2 = 0;                           
                        }
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 >= 10 && mejoras2 <= 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 366) && (pos.x < 519) && (pos.y > 412) && (pos.y < 447))
                    {
                        mejoras2++;
                        printf("%d\n", mejoras2);
                        if (mejoras2 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito2_Estacion.bmp");
                            azkena = ".\\img\\Distrito2_Estacion.bmp";
                            trantxizioa();
                        }
                        if (mejoras2 == 10)
                        {
                            mejoras0 = 10;
                            mejoras1 = 10;
                            mejoras2 = 9;
                            DistritosMaxeados2++;
                            irudiaKendu(azkena);
                            Distrito2Maxeado();
                        }
                    }
                    if ((mejoras2 >= 9) && (pos.x > 536) && (pos.x < 619) && (pos.y > 349) && (pos.y < 453)) {

                        irudiaKendu(azkena);
                        Distrito1Maxeado();
                        pantaila = 1;
                    }
                }
            }
        }
        while (mejoras2 >= 12 && mejoras0 == 10 && mejoras1 == 10)
        {
            
            ebentu = ebentuaJasoGertatuBada();
            pos = saguarenPosizioa();
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                if ((pos.x > 536) && (pos.x < 619) && (pos.y > 349) && (pos.y < 453))
                {
                    irudiaKendu(azkena);
                    JokoarenHasiera(10, 10, 12);
                    pantaila = 1;
                }
            }

        }
        if (ebentu == TECLA_m) {
            irudiaKendu(azkena);
            BotoiakHasi();
            pantaila = 1;
        }
    }

}

void HirugarrenDistrito(int upgrade0, int upgrade1, int upgrade2) {
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;

    int mejoras0 = upgrade0, mejoras1 = upgrade1, mejoras2 = upgrade2;
    int zero = upgrade0, hamaika = upgrade1, hamaika1 = upgrade2;

    if (mejoras2 <= 11) {
        irudiaKargatu(".\\img\\Distrito3_nada.bmp");
        azkena = ".\\img\\Distrito3_nada.bmp";
        trantxizioa();
    }
    else {
        irudiaKargatu(".\\img\\Distrito3_final.bmp");
        azkena = ".\\img\\Distrito3_final.bmp";
        trantxizioa();
    }

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            while (mejoras0 <= 10 && mejoras1 > 10 && mejoras2 > 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 20) && (pos.x < 189) && (pos.y > 427) && (pos.y < 463))
                    {
                        mejoras0++;
                        printf("%d\n", mejoras0);

                        if (mejoras0 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito3_hospital.bmp");
                            azkena = ".\\img\\Distrito3_hospital.bmp";
                            trantxizioa();
                        }

                        if (mejoras0 == 10)
                        {
                            mejoras1 = 0;
                        }
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 <= 10 && mejoras2 > 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 225) && (pos.x < 406) && (pos.y > 427) && (pos.y < 463))
                    {
                        mejoras1++;
                        printf("%d\n", mejoras1);

                        if (mejoras1 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito3_caseta.bmp");
                            azkena = ".\\img\\Distrito3_caseta.bmp";
                            trantxizioa();
                        }
                        if (mejoras1 == 10)
                        {
                            mejoras2 = 0;
                        }
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 >= 10 && mejoras2 <= 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 442) && (pos.x < 627) && (pos.y > 427) && (pos.y < 463))
                    {
                        mejoras2++;
                        printf("%d\n", mejoras2);
                        if (mejoras2 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito3_final.bmp");
                            azkena = ".\\img\\Distrito3_final.bmp";
                            trantxizioa();
                        }
                        if (mejoras2 == 10)
                        {
                            mejoras0 = 10;
                            mejoras1 = 10;
                            mejoras2 = 9;
                            DistritosMaxeados3++;
                            irudiaKendu(azkena);
                            Distrito3Maxeado();
                        }
                    }
                    if ((mejoras2 >= 9) && (pos.x > 2) && (pos.x < 65) && (pos.y > 317) && (pos.y < 403)) {

                        irudiaKendu(azkena);
                        Distrito1Maxeado();
                        pantaila = 1;
                    }
                }
            }
        }
        while (mejoras2 >= 12 && mejoras0 == 10 && mejoras1 == 10)
        {

            ebentu = ebentuaJasoGertatuBada();
            pos = saguarenPosizioa();
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                if ((pos.x > 2) && (pos.x < 65) && (pos.y > 317) && (pos.y < 403))
                {
                    printf("KLIKATZEN DU");
                    irudiaKendu(azkena);
                    Distrito1Maxeado();
                    pantaila = 1;
                }
            }

        }
        if (ebentu == TECLA_m) {
            irudiaKendu(azkena);
            BotoiakHasi();
            pantaila = 1;
        }
    }
}

void LaugarrenDistrito(int upgrade0, int upgrade1, int upgrade2) {
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;

    int mejoras0 = upgrade0, mejoras1 = upgrade1, mejoras2 = upgrade2;
    int zero = upgrade0, hamaika = upgrade1, hamaika1 = upgrade2;

    irudiaKargatu(".\\img\\Distrito4_nada.bmp");
    azkena = ".\\img\\Distrito4_nada.bmp";
    trantxizioa();

    while (!pantaila) {

        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();


        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            while (mejoras0 <= 10 && mejoras1 > 10 && mejoras2 > 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                printf("__X:%d -- Y:%d__\n", pos.x, pos.y);
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 18) && (pos.x < 199) && (pos.y > 419) && (pos.y < 450))
                    {
                        mejoras0++;
                        printf("%d\n", mejoras0);
                        if (mejoras0 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito4_Futbol.bmp");
                            azkena = ".\\img\\Distrito4_Futbol.bmp";
                            trantxizioa();
                        }
                        if (mejoras0 == 10)
                        {
                            mejoras1 = 0;

                        }
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 <= 10 && mejoras2 > 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 222) && (pos.x < 403) && (pos.y > 419) && (pos.y < 450))
                    {
                        mejoras1++;
                        printf("%d\n", mejoras1);
                        if (mejoras1 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito4_Casino.bmp");
                            azkena = ".\\img\\Distrito4_Casino.bmp";
                            trantxizioa();
                        }
                        if (mejoras1 == 10)
                        {
                            mejoras2 = 0;

                        }
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 >= 10 && mejoras2 <= 10)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 425) && (pos.x < 605) && (pos.y > 419) && (pos.y < 450))
                    {
                        mejoras2++;
                        printf("%d\n", mejoras2);
                        if (mejoras2 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito4_Hotel.bmp");
                            azkena = ".\\img\\Distrito4_Hotel.bmp";
                            trantxizioa();
                        }
                        else if (mejoras2 == 10)
                        {
                            mejoras0 = 10;
                            mejoras1 = 10;
                            mejoras2 = 9;
                            DistritosMaxeados4++;
                        }
                    }
                    else if ((mejoras2 >= 9) && (pos.x > 5) && (pos.x < 144) && (pos.y > 343) && (pos.y < 390)) {

                        printf("KLIKATZEN DU");
                        irudiaKendu(azkena);
                        Distrito2Maxeado();
                        pantaila = 1;
                    }
                    else if ((mejoras2 >= 9) && (pos.x > 488) && (pos.x < 627) && (pos.y > 343) && (pos.y < 390)) {

                        irudiaKendu(azkena);
                        Distrito3Maxeado();
                        pantaila = 1;
                    }

                }
            }
        }
        while (mejoras2 >= 12 && mejoras0 == 10 && mejoras1 == 10)
        {

            ebentu = ebentuaJasoGertatuBada();
            pos = saguarenPosizioa();
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                if ((pos.x > 5) && (pos.x < 144) && (pos.y > 343) && (pos.y < 390))
                {

                    irudiaKendu(azkena);
                    Distrito2Maxeado();
                    pantaila = 1;
                }
                if ((pos.x > 488) && (pos.x < 627) && (pos.y > 343) && (pos.y < 390))
                {
                    irudiaKendu(azkena);
                    Distrito3Maxeado();
                    pantaila = 1;
                }
            }
        }
        while (mejoras1 >= 12 && mejoras0 == 10 && mejoras2 == 10)
        {

            ebentu = ebentuaJasoGertatuBada();
            pos = saguarenPosizioa();
            if (ebentu == SAGU_BOTOIA_EZKERRA)
            {
                if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79))
                {

                    irudiaKendu(azkena);
                    Distrito2Maxeado();
                    pantaila = 1;
                }
                if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79))
                {

                    irudiaKendu(azkena);
                    Distrito3Maxeado();
                    pantaila = 1;
                }
            }
        }
        if (ebentu == TECLA_m) {
            irudiaKendu(azkena);
            BotoiakHasi();
            pantaila = 1;
        }
    }
}

void Distrito1Maxeado(void) {
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0, sinmas = 0;

    irudiaKargatu(".\\img\\Etxe_Hobetuak.bmp");
    azkena = ".\\img\\Etxe_Hobetuak.bmp";
    trantxizioa();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        printf("__%d---%d__\n", DistritosMaxeados2, DistritosMaxeados3);
        
        if (DistritosMaxeados2 >= 1 && DistritosMaxeados3 >= 1)
        {
            while (!sinmas) {

                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                printf("Heltzen da BIAK MAX\n");

                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        Distrito2Maxeado();
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        Distrito3Maxeado();
                        sinmas = 1;
                        pantaila = 1;
                    }

                }
            }
        }
        else if (DistritosMaxeados2 == 0 && DistritosMaxeados3 >= 1) {
            while (!sinmas) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                printf("Heltzen da HIRU MAX\n");
                if ((ebentu == SAGU_BOTOIA_EZKERRA))
                {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        BigarrenDistrito(0, 11, 11);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        Distrito3Maxeado();
                        sinmas = 1;
                        pantaila = 1;
                    }
                }
            }
        }
        else if (DistritosMaxeados2 >= 1 && DistritosMaxeados3 == 0) {
            while (!sinmas) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                printf("Heltzen da BI MAX\n");
                if ((ebentu == SAGU_BOTOIA_EZKERRA))
                {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        Distrito2Maxeado();
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79))
                    {

                        irudiaKendu(azkena);
                        HirugarrenDistrito(0, 11, 11);
                        sinmas = 1;
                        pantaila = 1;
                    }
                }
            }
        }
    }
}

void Distrito2Maxeado(void) {
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;

    irudiaKargatu(".\\img\\Distrito2_Estacion.bmp");
    azkena = ".\\img\\Distrito2_Estacion.bmp";
    trantxizioa();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        if (ebentu == SAGU_BOTOIA_EZKERRA )
        {
            if ((pos.x > 535) && (pos.x < 619) && (pos.y > 31) && (pos.y < 134) && DistritosMaxeados4 >= 1)
            {

                irudiaKendu(azkena);
                Distrito4Maxeado();
                pantaila = 1;
            }
            if ((pos.x > 536) && (pos.x < 619) && (pos.y > 349) && (pos.y < 453))
            {

                irudiaKendu(azkena);
                Distrito1Maxeado();
                pantaila = 1;
            }
            if ((pos.x > 535) && (pos.x < 619) && (pos.y > 31) && (pos.y < 134) && DistritosMaxeados4 < 1 && DistritosMaxeados3 >= 1) {
                irudiaKendu(azkena);
                LaugarrenDistrito(0, 11, 11);
                pantaila = 1;

            }
        }
    }

}

void Distrito3Maxeado(void) {
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;

    irudiaKargatu(".\\img\\Distrito3_final.bmp");
    azkena = ".\\img\\Distrito3_final.bmp";
    trantxizioa();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            if ((pos.x > 2) && (pos.x < 65) && (pos.y > 0) && (pos.y < 81) && DistritosMaxeados4 >= 1)
            {
                irudiaKendu(azkena);
                Distrito4Maxeado();
                pantaila = 1;
            }
            if ((pos.x > 2) && (pos.x < 65) && (pos.y > 317) && (pos.y < 403))
            {
                irudiaKendu(azkena);
                Distrito1Maxeado();
                pantaila = 1;
            }
            if ((pos.x > 2) && (pos.x < 65) && (pos.y > 0) && (pos.y < 81) && DistritosMaxeados4 < 1 && DistritosMaxeados2 >= 1)
            {
                printf("%d", DistritosMaxeados2);
                irudiaKendu(azkena);
                LaugarrenDistrito(0, 11, 11);
                pantaila = 1;
            }
        }
    }
}

void Distrito4Maxeado(void) {
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;

    irudiaKargatu(".\\img\\Distrito4_Hotel.bmp");
    azkena = ".\\img\\Distrito4_Hotel.bmp";
    trantxizioa();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            if ((pos.x > 5) && (pos.x < 144) && (pos.y > 343) && (pos.y < 390))
            {
                irudiaKendu(azkena);
                Distrito2Maxeado();
                pantaila = 1;
            }
            if ((pos.x > 488) && (pos.x < 627) && (pos.y > 343) && (pos.y < 390))
            {
                irudiaKendu(azkena);
                Distrito3Maxeado();
                pantaila = 1;
            }
        }
    }
}

void KredituakJarri(void) {

    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;;
       

    irudiaKargatu(".\\img\\Kredituak.bmp");
    trantxizioa();


    while (!pantaila) {
        
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            if ((pos.x > 9) && (pos.x < 129) && (pos.y > 23) && (pos.y < 29 +20)) {
                
                irudiaKendu(".\\img\\Kredituak.bmp");
                irudiaKargatu(".\\img\\Sarrera.bmp");
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

        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            if ((pos.x > 9) && (pos.x < 129) && (pos.y > 23) && (pos.y < 29 + 20)) {

                irudiaKendu(".\\img\\Argibideak.bmp");
                irudiaKargatu(".\\img\\Sarrera.bmp");
                trantxizioa();
                BotoiakHasi();
            }
        }
    }
}

int hasieratu(void)
{
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