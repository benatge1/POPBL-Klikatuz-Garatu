#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <windows.h>

int DistritosMaxeados2 = 0;
int DistritosMaxeados3 = 0;
int DistritosMaxeados4 = 0;
double click = 0;
double hobekuntza = 1;

void JokoarenHasiera(int upgrade0, int upgrade1, int upgrade2);
void BigarrenDistrito(int upgrade0, int upgrade1, int upgrade2, double klk, double hbk);
void HirugarrenDistrito(int upgrade0, int upgrade1, int upgrade2, double klk, double hbk);
void LaugarrenDistrito(int upgrade0, int upgrade1, int upgrade2, double klk, double hbk);
void Distrito1Maxeado(double klk, double hbk, int MXD2, int MXD3);
void Distrito2Maxeado(double klk, double hbk, int MXD3, int MXD4);
void Distrito3Maxeado(double klk, double hbk, int MXD2, int MXD4);
void Distrito4Maxeado(double klk, double hbk);

void BotoiakHasi(void) {
    int ebentu = 0;
    int menu = 0;
    int upgrade0 = 0;
    int upgrade1 = 11;
    int upgrade2 = 11;
    int azkena = 0;
    POSIZIOA pos;
    pos = saguarenPosizioa();

    irudiaKargatu(".\\img\\1.bmp");
    azkena = ".\\img\\1.bmp";
    trantxizioa();

    printf("HASI DA\n");
    printf("__X:%d -- Y:%d__\n", pos.x, pos.y);

    while (!menu) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        printf("__X:%d -- Y:%d__\n", pos.x, pos.y);

        //Sarreraren Posizioak
        if ((pos.x > 236) && (pos.x < 360 + 44) && (pos.y > 108) && (pos.y < 130 + 31)) {
            irudiaKendu(azkena);
            irudiaKargatu(".\\img\\2.bmp");
            trantxizioa();
            irudiakMarraztu();
        }
        else if ((pos.x > 247) && (pos.x < 351 + 40) && (pos.y > 178) && (pos.y < 218 + 10)) {
            irudiaKendu(".\\img\\1.bmp");
            irudiaKargatu(".\\img\\3.bmp");
            trantxizioa();
            irudiakMarraztu();
        }
        else if ((pos.x > 247) && (pos.x < 351 + 40) && (pos.y > 245) && (pos.y < 283 + 10)) {
            irudiaKendu(".\\img\\1.bmp");
            irudiaKargatu(".\\img\\4.bmp");
            trantxizioa();
            irudiakMarraztu();
        }
        else if ((pos.x > 247) && (pos.x < 351 + 40) && (pos.y > 310) && (pos.y < 320 + 38)) {
            irudiaKendu(".\\img\\1.bmp");
            irudiaKargatu(".\\img\\5.bmp");
            irudiakMarraztu();
            trantxizioa();
        }

        if (ebentu == SAGU_BOTOIA_EZKERRA) {

            if ((pos.x > 236) && (pos.x < 360 + 44) && (pos.y > 108) && (pos.y < 130 + 31)) {
                irudiaKendu(azkena);
                JokoarenHasiera(upgrade0, upgrade1, upgrade2, click, hobekuntza);
                menu = 1;
            }
            if ((pos.x > 247) && (pos.x < 351 + 40) && (pos.y > 178) && (pos.y < 218 + 10)) {
                irudiaKendu(".\\img\\1.bmp");
                KredituakJarri();
                menu = 1;
            }
            if ((pos.x > 247) && (pos.x < 351 + 40) && (pos.y > 245) && (pos.y < 283 + 10)) {
                irudiaKendu(".\\img\\1.bmp");
                ArgibideaJarri();
                menu = 1;
            }
            if ((pos.x > 247) && (pos.x < 351 + 40) && (pos.y > 310) && (pos.y < 320 + 38)) {
                irudiaKendu(".\\img\\1.bmp");
                InstrukzioakJarri();
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

void JokoarenHasiera(int upgrade0, int upgrade1, int upgrade2) {
    char str[128];
    char ztr1[128], ztr2[128], ztr3[128], ztr4[128];
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;
    float prezioa = 10;
    double click = 0;
    double hobekuntza = 1;

    int mejoras0 = upgrade0, mejoras1 = upgrade1, mejoras2 = upgrade2;

    irudiaKargatu(".\\img\\Casas_pobres_solo.bmp");
    azkena = ".\\img\\Casas_pobres_solo.bmp";

    sprintf(str, "%5.lf $", click);
    sprintf(ztr1, "Etxea pobreak, nibel: %d", mejoras0);
    sprintf(ztr2, "Eskola, nibel: 0", mejoras1);
    sprintf(ztr3, "Etxe hobetuak, nibel: 0", mejoras2);
    sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
    textuaIdatzi(300, 50, str);
    pantailaBerriztu();
    pantailaGarbitu();
    trantxizioa();
    textuaIdatzi(300, 50, str);
    //nibelak
    textuaIdatzi_v2(20, 100, ztr1);
    textuaIdatzi_v2(20, 120, ztr2);
    textuaIdatzi_v2(20, 140, ztr3);
    textuaIdatzi_v2(20, 160, ztr4);
    textuaIdatzi_v2(20, 425, "Etxe pobreak hobetu");
    textuaIdatzi_v2(230, 425, "Eskola BLOKEATUTA");
    textuaIdatzi_v2(444, 425, "Auzoa BLOKEATUTA");
    pantailaBerriztu();


    while (!pantaila) {

        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        printf("%f", click);

        while (mejoras0 <= 10 && mejoras1 > 10 && mejoras2 > 10) {
            ebentu = ebentuaJasoGertatuBada();
            pos = saguarenPosizioa();

            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                if ((pos.x > 18) && (pos.x < 199) && (pos.y > 419) && (pos.y < 450) && (click - prezioa > 0)) {
                    mejoras0++;
                    click = click - prezioa;
                    hobekuntza = hobekuntza + 0.5;
                    prezioa = prezioa * 1.15;
                    printf("%d\n", mejoras0);
                    if (mejoras0 == 10) {
                        mejoras1 = 0;
                    }
                }
                if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                    click = click + hobekuntza;
                    printf("%5.f\n", click);
                    sprintf(str, "%5.lf $", click);
                    sprintf(ztr1, "Etxea pobreak, nibel: %d", mejoras0);
                    sprintf(ztr2, "Eskola, nibel: 0", mejoras1);
                    sprintf(ztr3, "Etxe hobetuak, nibel: 0", mejoras2);
                    sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                    textuaIdatzi(300, 50, str);
                    pantailaBerriztu();
                    pantailaGarbitu();
                    trantxizioa();
                    textuaIdatzi(300, 50, str);
                    //nibelak
                    textuaIdatzi_v2(20, 100, ztr1);
                    textuaIdatzi_v2(20, 120, ztr2);
                    textuaIdatzi_v2(20, 140, ztr3);
                    textuaIdatzi_v2(20, 160, ztr4);
                    textuaIdatzi_v2(20, 425, "Etxe pobreak hobetu");
                    textuaIdatzi_v2(230, 425, "Eskola BLOKEATUTA");
                    textuaIdatzi_v2(444, 425, "Auzoa BLOKEATUTA");
                    pantailaBerriztu();
                }
            }
        }
        while (mejoras0 >= 10 && mejoras1 <= 10 && mejoras2 > 10) {
            ebentu = ebentuaJasoGertatuBada();
            pos = saguarenPosizioa();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                if ((pos.x > 222) && (pos.x < 403) && (pos.y > 419) && (pos.y < 450) && (click - prezioa > 0)) {
                    mejoras1++;
                    click = click - prezioa;
                    hobekuntza = hobekuntza + 1;
                    prezioa = prezioa * 1.15;
                    irudiaKendu(azkena);
                    irudiaKargatu(".\\img\\Eskolarekin.bmp");
                    azkena = ".\\img\\Eskolarekin.bmp";
                    trantxizioa();
                    printf("%d\n", mejoras1);
                    if (mejoras1 == 10) {
                        mejoras2 = 0;
                    }
                }
                if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                    click = click + hobekuntza;
                    printf("%f\n", click);
                    sprintf(str, "%5.lf $", click);
                    sprintf(ztr1, "Etxea pobreak, nibel: 10", mejoras0);
                    sprintf(ztr2, "Eskola, nibel: %d", mejoras1);
                    sprintf(ztr3, "Etxe hobetuak, nibel: 0", mejoras2);
                    sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                    textuaIdatzi(300, 50, str);
                    pantailaBerriztu();
                    pantailaGarbitu();
                    trantxizioa();
                    textuaIdatzi(300, 50, str);
                    //nibelak
                    textuaIdatzi_v2(20, 100, ztr1);
                    textuaIdatzi_v2(20, 120, ztr2);
                    textuaIdatzi_v2(20, 140, ztr3);
                    textuaIdatzi_v2(20, 160, ztr4);
                    textuaIdatzi_v2(30, 415, "Etxe pobreak MAX");
                    textuaIdatzi_v2(230, 415, "Eskola hobetu");
                    textuaIdatzi_v2(444, 415, "Auzoa BLOKEATUTA");
                    pantailaBerriztu();
                }
            }
        }
        while (mejoras0 >= 10 && mejoras1 >= 10 && mejoras2 <= 10) {
            ebentu = ebentuaJasoGertatuBada();
            pos = saguarenPosizioa();
            if (ebentu == SAGU_BOTOIA_EZKERRA) {
                if ((pos.x > 425) && (pos.x < 605) && (pos.y > 419) && (pos.y < 450) && (click - prezioa > 0)) {
                    mejoras2++;
                    click = click - prezioa;
                    hobekuntza = hobekuntza + 2.5;
                    prezioa = prezioa * 1.15;
                    irudiaKendu(azkena);
                    irudiaKargatu(".\\img\\Etxe_Hobetuak.bmp");
                    azkena = ".\\img\\Etxe_Hobetuak.bmp";
                    trantxizioa();
                    printf("%d\n", mejoras2);
                    if (mejoras2 == 10) {
                        mejoras0 = 10;
                        mejoras1 = 10;
                        mejoras2 = 9;
                        irudiaKendu(azkena);
                        Distrito1Maxeado(click, hobekuntza, 0, 0);
                        pantaila = 1;
                    }
                }
                else if ((mejoras2 >= 9) && (pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79)) {
                    printf("KLIKATZEN DU");
                    irudiaKendu(azkena);
                    BigarrenDistrito(0, 11, 11, click, hobekuntza);
                    pantaila = 1;

                    sprintf(str, "%5.lf $", click);
                    sprintf(ztr1, "Polizia koartela, nibel: 0", mejoras0);
                    sprintf(ztr2, "Etxe modernoa, nibel: 0", mejoras1);
                    sprintf(ztr3, "Estazioa, nibel: 0", mejoras2);
                    sprintf(ztr4, "Hobekuntza prezioa: %5.f", prezioa);
                    textuaIdatzi(300, 50, str);
                    pantailaBerriztu();
                    pantailaGarbitu();
                    trantxizioa();
                    textuaIdatzi(300, 50, str);
                    //nibelak
                    textuaIdatzi_v2(20, 100, ztr1);
                    textuaIdatzi_v2(20, 120, ztr2);
                    textuaIdatzi_v2(20, 140, ztr3);
                    textuaIdatzi_v2(20, 160, ztr4);
                    pantailaBerriztu();
                }
                else if ((mejoras2 >= 9) && (pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79)) {
                    irudiaKendu(azkena);
                    HirugarrenDistrito(0, 11, 11, click, hobekuntza);
                    pantaila = 1;

                    sprintf(str, "%5.lf $", click);
                    sprintf(ztr1, "Etxea pobreak, nibel: 10", mejoras0);
                    sprintf(ztr2, "Eskola, nibel: 10", mejoras1);
                    sprintf(ztr3, "Etxe hobetuak, nibel: 10", mejoras2);
                    sprintf(ztr4, "Hobekuntza prezioa: %5.f", prezioa);
                    textuaIdatzi(300, 50, str);
                    pantailaBerriztu();
                    pantailaGarbitu();
                    trantxizioa();
                    textuaIdatzi(300, 50, str);
                    //nibelak
                    textuaIdatzi_v2(20, 100, ztr1);
                    textuaIdatzi_v2(20, 120, ztr2);
                    textuaIdatzi_v2(20, 140, ztr3);
                }
                if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT) && mejoras2 < 8); {
                    click = click + hobekuntza;
                    printf("%f\n", click);
                    sprintf(str, "%5.lf $", click);
                    sprintf(ztr1, "Etxea pobreak, nibel: 10", mejoras0);
                    sprintf(ztr2, "Eskola, nibel: 10", mejoras1);
                    sprintf(ztr3, "Etxe hobetuak, nibel: %d", mejoras2);
                    sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                    textuaIdatzi(300, 50, str);
                    pantailaBerriztu();
                    pantailaGarbitu();
                    trantxizioa();
                    textuaIdatzi(300, 50, str);
                    //nibelak
                    textuaIdatzi_v2(20, 100, ztr1);
                    textuaIdatzi_v2(20, 120, ztr2);
                    textuaIdatzi_v2(20, 140, ztr3);
                    textuaIdatzi_v2(20, 160, ztr4);
                    textuaIdatzi_v2(35, 415, "Etxe pobreak MAX");
                    textuaIdatzi_v2(255, 415, "Eskola MAX");
                    textuaIdatzi_v2(455, 415, "Auzoa hobetu");
                    pantailaBerriztu();
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

void BigarrenDistrito(int upgrade0, int upgrade1, int upgrade2, double klk, double hbk) {
    POSIZIOA pos;
    char str[128], ztr1[128], ztr2[128], ztr3[128], ztr4[128];
    int ebentu = 0, pantaila = 0;
    int azkena = 0;
    float prezioa = 1200;
    float click = klk;
    float hobekuntza = hbk;
    int DistritosMaxeados2 = 0;

    int mejoras0 = upgrade0, mejoras1 = upgrade1, mejoras2 = upgrade2;

    irudiaKargatu(".\\img\\Distrito2_Nada.bmp");
    azkena = ".\\img\\Distrito2_Nada.bmp";
    trantxizioa();

    sprintf(str, "%5.lf $", click);
    sprintf(ztr1, "Polizia koartela, nibel: %d", mejoras0);
    sprintf(ztr2, "Etxe modernoa, nibel: 0", mejoras1);
    sprintf(ztr3, "Estazioa, nibel: 0", mejoras2);
    sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
    textuaIdatzi(300, 50, str);
    pantailaBerriztu();
    pantailaGarbitu();
    trantxizioa();
    textuaIdatzi(300, 50, str);
    //nibelak
    textuaIdatzi_v2(20, 100, ztr1);
    textuaIdatzi_v2(20, 120, ztr2);
    textuaIdatzi_v2(20, 140, ztr3);
    textuaIdatzi_v2(20, 160, ztr4);
    textuaIdatzi_v2(20, 415, "Koartela hobetu");
    textuaIdatzi_v2(195, 415, "Etxea BLOKEATUTA");
    textuaIdatzi_v2(360, 415, "Estazioa BLOKEATUTA");
    pantailaBerriztu();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            while (mejoras0 <= 10 && mejoras1 > 10 && mejoras2 > 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 17) && (pos.x < 171) && (pos.y > 412) && (pos.y < 447) && (click - prezioa > 0)) {
                        mejoras0++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 7;
                        prezioa = prezioa * 1.15;
                        printf("%d\n", mejoras0);

                        if (mejoras0 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito2_Cuartel.bmp");
                            azkena = ".\\img\\Distrito2_Cuartel.bmp";
                            trantxizioa();
                        }

                        if (mejoras0 == 10) {
                            mejoras1 = 0;
                        }
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Polizia koartela, nibel: %d", mejoras0);
                        sprintf(ztr2, "Etxe modernoa, nibel: 0", mejoras1);
                        sprintf(ztr3, "Estazioa, nibel: 0", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(50, 420, "Koartela hobetu");
                        textuaIdatzi_v2(200, 420, "Etxea BLOKEATUTA");
                        textuaIdatzi_v2(360, 420, "Estazioa BLOKEATUTA");
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 <= 10 && mejoras2 > 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 192) && (pos.x < 345) && (pos.y > 412) && (pos.y < 447) && (click - prezioa > 0)) {
                        mejoras1++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 17;
                        prezioa = prezioa * 1.15;
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
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Polizia koartela, nibel: 10", mejoras0);
                        sprintf(ztr2, "Etxe modernoa, nibel: %d", mejoras1);
                        sprintf(ztr3, "Estazioa, nibel: 0", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(30, 410, "Koartela MAX");
                        textuaIdatzi_v2(205, 410, "Etxea hobetu");
                        textuaIdatzi_v2(370, 410, "Estazioa BLOKEATUTA");
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 >= 10 && mejoras2 <= 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 366) && (pos.x < 519) && (pos.y > 412) && (pos.y < 447) && (click - prezioa > 0)) {
                        mejoras2++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 25;
                        prezioa = prezioa * 1.07;
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
                            Distrito2Maxeado(click, hobekuntza, 0, 0);
                        }
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Polizia koartela, nibel: 10", mejoras0);
                        sprintf(ztr2, "Etxe modernoa, nibel: 10", mejoras1);
                        sprintf(ztr3, "Estazioa, nibel: %d", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(20, 415, "Koartela MAX");
                        textuaIdatzi_v2(200, 415, "Etxea MAX");
                        textuaIdatzi_v2(370, 415, "Estazioa hobetu");
                        pantailaBerriztu();
                    }
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

void HirugarrenDistrito(int upgrade0, int upgrade1, int upgrade2, double klk, double hbk) {
    POSIZIOA pos;
    char str[128], ztr1[128], ztr2[128], ztr3[128], ztr4[128];
    int ebentu = 0, pantaila = 0;
    int azkena = 0;
    float prezioa = 1200;
    float click = klk;
    float hobekuntza = hbk;
    int DistritosMaxeados3 = 0;

    int mejoras0 = upgrade0, mejoras1 = upgrade1, mejoras2 = upgrade2;

    irudiaKargatu(".\\img\\Distrito3_nada.bmp");
    azkena = ".\\img\\Distrito3_nada.bmp";

    sprintf(str, "%5.lf $", click);
    sprintf(ztr1, "Ospitala, nibel: %d", mejoras0);
    sprintf(ztr2, "Taberna, nibel: 0", mejoras1);
    sprintf(ztr3, "Denda, nibel: 0", mejoras2);
    sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
    textuaIdatzi(300, 50, str);
    pantailaBerriztu();
    pantailaGarbitu();
    trantxizioa();
    textuaIdatzi(300, 50, str);
    //nibelak
    textuaIdatzi_v2(20, 100, ztr1);
    textuaIdatzi_v2(20, 120, ztr2);
    textuaIdatzi_v2(20, 140, ztr3);
    textuaIdatzi_v2(20, 160, ztr4);
    textuaIdatzi_v2(25, 435, "Ospitala hobetu");
    textuaIdatzi_v2(230, 435, "Taberna BLOKEATUTA");
    textuaIdatzi_v2(455, 435, "Denda BLOKEATUTA");
    pantailaBerriztu();


    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();

        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            while (mejoras0 <= 10 && mejoras1 > 10 && mejoras2 > 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 20) && (pos.x < 189) && (pos.y > 427) && (pos.y < 463) && (click - prezioa > 0)) {
                        mejoras0++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 7;
                        prezioa = prezioa * 1.15;
                        printf("%d\n", mejoras0);
                        if (mejoras0 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito3_hospital.bmp");
                            azkena = ".\\img\\Distrito3_hospital.bmp";
                            trantxizioa();
                        }
                        if (mejoras0 == 10) {
                            mejoras1 = 0;
                        }
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Ospitala, nibel: %d", mejoras0);
                        sprintf(ztr2, "Taberna, nibel: 0", mejoras1);
                        sprintf(ztr3, "Denda, nibel: 0", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(25, 435, "Ospitala hobetu");
                        textuaIdatzi_v2(230, 435, "Taberna BLOKEATUTA");
                        textuaIdatzi_v2(455, 435, "Denda BLOKEATUTA");
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 <= 10 && mejoras2 > 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 225) && (pos.x < 406) && (pos.y > 427) && (pos.y < 463) && (click - prezioa > 0)) {
                        mejoras1++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 17;
                        prezioa = prezioa * 1.15;
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
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Ospitala, nibel: 10", mejoras0);
                        sprintf(ztr2, "Taberna, nibel: %d", mejoras1);
                        sprintf(ztr3, "Denda, nibel: 0", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(25, 435, "Ospitala MAX");
                        textuaIdatzi_v2(230, 435, "Taberna hobetu");
                        textuaIdatzi_v2(455, 435, "Denda BLOKEATUTA");
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 >= 10 && mejoras2 <= 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 442) && (pos.x < 627) && (pos.y > 427) && (pos.y < 463) && (click - prezioa > 0)) {
                        mejoras2++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 25;
                        prezioa = prezioa * 1.07;
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
                            Distrito3Maxeado(click, hobekuntza, 0, 0);
                        }
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Ospitala, nibel: 10", mejoras0);
                        sprintf(ztr2, "Taberna, nibel: 10", mejoras1);
                        sprintf(ztr3, "Denda, nibel: %d", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(25, 435, "Ospitala MAX");
                        textuaIdatzi_v2(230, 435, "Taberna MAX");
                        textuaIdatzi_v2(455, 435, "Denda hobetu");
                        pantailaBerriztu();
                    }
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

void LaugarrenDistrito(int upgrade0, int upgrade1, int upgrade2, double klk, double hbk) {
    POSIZIOA pos;
    char str[128], ztr1[128], ztr2[128], ztr3[128], ztr4[128];
    int ebentu = 0, pantaila = 0;
    int azkena = 0;
    float prezioa = 6000;
    float click = klk;
    float hobekuntza = hbk;
    int DistritosMaxeados4 = 0;

    int mejoras0 = upgrade0, mejoras1 = upgrade1, mejoras2 = upgrade2;
    int zero = upgrade0, hamaika = upgrade1, hamaika1 = upgrade2;

    irudiaKargatu(".\\img\\Distrito4_nada.bmp");
    azkena = ".\\img\\Distrito4_nada.bmp";
    trantxizioa();


    printf("%f\n", click);
    sprintf(str, "%5.lf $", click);
    sprintf(ztr1, "Futbol zelaia, nibel: %d", mejoras0);
    sprintf(ztr2, "Kasinoa, nibel: 0", mejoras1);
    sprintf(ztr3, "Hotel, nibel: 0", mejoras2);
    sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
    textuaIdatzi(300, 50, str);
    pantailaBerriztu();
    pantailaGarbitu();
    trantxizioa();
    textuaIdatzi(300, 50, str);
    //nibelak
    textuaIdatzi_v2(20, 100, ztr1);
    textuaIdatzi_v2(20, 120, ztr2);
    textuaIdatzi_v2(20, 140, ztr3);
    textuaIdatzi_v2(20, 160, ztr4);
    textuaIdatzi_v2(20, 425, "Futbol zelaia hobetu");
    textuaIdatzi_v2(220, 425, "Kasinoa BLOKEATUTA");
    textuaIdatzi_v2(444, 425, "Hotela BLOKEATUTA");
    pantailaBerriztu();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            while (mejoras0 <= 10 && mejoras1 > 10 && mejoras2 > 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                printf("__X:%d -- Y:%d__\n", pos.x, pos.y);
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 18) && (pos.x < 199) && (pos.y > 419) && (pos.y < 450) && (click - prezioa > 0)) {
                        mejoras0++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 50;
                        prezioa = prezioa * 1.2;
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

                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Futbol zelaia, nibel: %d", mejoras0);
                        sprintf(ztr2, "Kasinoa, nibel: 0", mejoras1);
                        sprintf(ztr3, "Hotel, nibel: 0", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(20, 425, "Futbol zelaia hobetu");
                        textuaIdatzi_v2(220, 425, "Kasinoa BLOKEATUTA");
                        textuaIdatzi_v2(444, 425, "Hotela BLOKEATUTA");
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 <= 10 && mejoras2 > 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 222) && (pos.x < 403) && (pos.y > 419) && (pos.y < 450) && (click - prezioa > 0)) {
                        mejoras1++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 120;
                        prezioa = prezioa * 1.24;
                        printf("%d\n", mejoras1);
                        if (mejoras1 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito4_Casino.bmp");
                            azkena = ".\\img\\Distrito4_Casino.bmp";
                            trantxizioa();
                        }
                        if (mejoras1 == 10) {
                            mejoras2 = 0;

                        }
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Futbol zelaia, nibel: 10", mejoras0);
                        sprintf(ztr2, "Kasinoa, nibel: %d", mejoras1);
                        sprintf(ztr3, "Hotel, nibel: 0", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(20, 425, "Futbol zelaia MAX");
                        textuaIdatzi_v2(220, 425, "Kasinoa hobetu");
                        textuaIdatzi_v2(444, 425, "Hotela BLOKEATUTA");
                        pantailaBerriztu();
                    }
                }
            }
            while (mejoras0 >= 10 && mejoras1 >= 10 && mejoras2 <= 10) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if (ebentu == SAGU_BOTOIA_EZKERRA) {
                    if ((pos.x > 425) && (pos.x < 605) && (pos.y > 419) && (pos.y < 450) && (click - prezioa > 0)) {
                        mejoras2++;
                        click = click - prezioa;
                        hobekuntza = hobekuntza + 250;
                        prezioa = prezioa * 1.3;
                        printf("%d\n", mejoras2);
                        if (mejoras2 == 1) {
                            irudiaKendu(azkena);
                            irudiaKargatu(".\\img\\Distrito4_Hotel.bmp");
                            azkena = ".\\img\\Distrito4_Hotel.bmp";
                            trantxizioa();
                        }
                        else if (mejoras2 == 10) {
                            mejoras0 = 10;
                            mejoras1 = 10;
                            mejoras2 = 9;
                            DistritosMaxeados4++;
                            Distrito4Maxeado(click, hobekuntza);
                        }
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Futbol zelaia, nibel: 10", mejoras0);
                        sprintf(ztr2, "Kasinoa, nibel: 10", mejoras1);
                        sprintf(ztr3, "Hotel, nibel: %d", mejoras2);
                        sprintf(ztr4, "Hobekuntza prezioa: %5.f $", prezioa);
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(20, 160, ztr4);
                        textuaIdatzi_v2(20, 425, "Futbol zelaia MAX");
                        textuaIdatzi_v2(220, 425, "Kasinoa MAX");
                        textuaIdatzi_v2(444, 425, "Hotela hobetu");
                        pantailaBerriztu();
                    }
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

void Distrito1Maxeado(double klk, double hbk, int MXD2, int MXD3) {
    char str[128];
    char ztr1[128], ztr2[128], ztr3[128];
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0, sinmas = 0;
    float click = klk;
    float hobekuntza = hbk;
    int DistritosMaxeados2 = MXD2;
    int DistritosMaxeados3 = MXD3;

    irudiaKargatu(".\\img\\Etxe_Hobetuak.bmp");
    azkena = ".\\img\\Etxe_Hobetuak.bmp";
    trantxizioa();

    printf("%f\n", click);
    sprintf(str, "%5.lf $", click);
    sprintf(ztr1, "Etxea pobreak, nibel: 10");
    sprintf(ztr2, "Eskola, nibel: 10");
    sprintf(ztr3, "Etxe hobetuak, nibel : 10");
    textuaIdatzi(300, 50, str);
    pantailaBerriztu();
    pantailaGarbitu();
    trantxizioa();
    textuaIdatzi(300, 50, str);
    //nibelak
    textuaIdatzi_v2(20, 100, ztr1);
    textuaIdatzi_v2(20, 120, ztr2);
    textuaIdatzi_v2(20, 140, ztr3);
    textuaIdatzi_v2(35, 415, "Etxe pobreak MAX");
    textuaIdatzi_v2(255, 415, "Eskola MAX");
    textuaIdatzi_v2(455, 415, "Auzoa MAX");
    pantailaBerriztu();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        if (DistritosMaxeados2 >= 1 && DistritosMaxeados3 >= 1)
        {
            while (!sinmas) {

                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if (ebentu == SAGU_BOTOIA_EZKERRA)
                {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79))
                    {
                        irudiaKendu(azkena);
                        Distrito2Maxeado(click, hobekuntza, 1, 1);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79))
                    {
                        irudiaKendu(azkena);
                        Distrito3Maxeado(click, hobekuntza, 1, 1);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT));
                    {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Etxea pobreak, nibel: 10");
                        sprintf(ztr2, "Eskola, nibel: 10");
                        sprintf(ztr3, "Etxe hobetuak, nibel : 10");
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(35, 415, "Etxe pobreak MAX");
                        textuaIdatzi_v2(255, 415, "Eskola MAX");
                        textuaIdatzi_v2(455, 415, "Auzoa MAX");
                        pantailaBerriztu();
                    }
                }
            }
        }
        else if (DistritosMaxeados2 == 0 && DistritosMaxeados3 >= 1)
        {
            while (!sinmas)
            {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                if ((ebentu == SAGU_BOTOIA_EZKERRA))
                {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79))
                    {
                        irudiaKendu(azkena);
                        BigarrenDistrito(0, 11, 11, click, hobekuntza);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79))
                    {
                        irudiaKendu(azkena);
                        Distrito3Maxeado(click, hobekuntza, 1, 0);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT));
                    {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Etxea pobreak, nibel: 10");
                        sprintf(ztr2, "Eskola, nibel: 10");
                        sprintf(ztr3, "Etxe hobetuak, nibel : 10");
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(35, 415, "Etxe pobreak MAX");
                        textuaIdatzi_v2(255, 415, "Eskola MAX");
                        textuaIdatzi_v2(455, 415, "Auzoa MAX");
                        pantailaBerriztu();
                    }
                }
            }
        }
        else if (DistritosMaxeados2 >= 1 && DistritosMaxeados3 == 0) {
            while (!sinmas) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();

                if ((ebentu == SAGU_BOTOIA_EZKERRA)) {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79)) {
                        irudiaKendu(azkena);
                        Distrito2Maxeado(click, hobekuntza, 0, 0);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79)) {
                        irudiaKendu(azkena);
                        HirugarrenDistrito(0, 11, 11, click, hobekuntza);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)); {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Etxea pobreak, nibel: 10");
                        sprintf(ztr2, "Eskola, nibel: 10");
                        sprintf(ztr3, "Etxe hobetuak, nibel : 10");
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(30, 420, "Etxe pobreak MAX");
                        textuaIdatzi_v2(230, 420, "Eskola MAX");
                        textuaIdatzi_v2(454, 420, "Auzoa MAX");
                        pantailaBerriztu();

                    }
                }
            }
        }
        else if (DistritosMaxeados2 == 0 && DistritosMaxeados3 == 0) {
            while (!sinmas) {
                ebentu = ebentuaJasoGertatuBada();
                pos = saguarenPosizioa();
                printf("__X:%d -- Y:%d__\n", pos.x, pos.y);

                if ((ebentu == SAGU_BOTOIA_EZKERRA)) {
                    if ((pos.x > 33) && (pos.x < 173) && (pos.y > 14) && (pos.y < 79)) {
                        irudiaKendu(azkena);
                        BigarrenDistrito(0, 11, 11, click, hobekuntza);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x > 470) && (pos.x < 612) && (pos.y > 14) && (pos.y < 79)) {
                        irudiaKendu(azkena);
                        HirugarrenDistrito(0, 11, 11, click, hobekuntza);
                        sinmas = 1;
                        pantaila = 1;
                    }
                    if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT)) {
                        click = click + hobekuntza;
                        printf("%f\n", click);
                        sprintf(str, "%5.lf $", click);
                        sprintf(ztr1, "Etxea pobreak, nibel: 10");
                        sprintf(ztr2, "Eskola, nibel: 10");
                        sprintf(ztr3, "Etxe hobetuak, nibel : 10");
                        textuaIdatzi(300, 50, str);
                        pantailaBerriztu();
                        pantailaGarbitu();
                        trantxizioa();
                        textuaIdatzi(300, 50, str);
                        //nibelak
                        textuaIdatzi_v2(20, 100, ztr1);
                        textuaIdatzi_v2(20, 120, ztr2);
                        textuaIdatzi_v2(20, 140, ztr3);
                        textuaIdatzi_v2(30, 420, "Etxe pobreak MAX");
                        textuaIdatzi_v2(230, 420, "Eskola MAX");
                        textuaIdatzi_v2(454, 420, "Auzoa MAX");
                        pantailaBerriztu();
                    }
                }
            }
        }
    }
}

void Distrito2Maxeado(double klk, double hbk, int MXD3, int MXD4) {
    char str[128], ztr1[128], ztr2[128], ztr3[128];
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;
    int DistritosMaxeados3 = MXD3;
    int DistritosMaxeados4 = MXD4;
    float click = klk;
    float hobekuntza = hbk;

    irudiaKargatu(".\\img\\Distrito2_Estacion.bmp");
    azkena = ".\\img\\Distrito2_Estacion.bmp";
    trantxizioa();

    printf("%f\n", click);
    sprintf(str, "%5.lf $", click);
    sprintf(ztr1, "Polizia koartela, nibel: 10");
    sprintf(ztr2, "Etxe modernoa, nibel: 10");
    sprintf(ztr3, "Estazioa, nibel: 10");
    textuaIdatzi(300, 50, str);
    pantailaBerriztu();
    pantailaGarbitu();
    trantxizioa();
    textuaIdatzi(300, 50, str);
    //nibelak
    textuaIdatzi_v2(20, 100, ztr1);
    textuaIdatzi_v2(20, 120, ztr2);
    textuaIdatzi_v2(20, 140, ztr3);
    textuaIdatzi_v2(20, 415, "Koartela MAX");
    textuaIdatzi_v2(200, 415, "Etxea MAX");
    textuaIdatzi_v2(370, 415, "Estazioa MAX");
    pantailaBerriztu();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        if (ebentu == SAGU_BOTOIA_EZKERRA)
        {
            if ((pos.x > 535) && (pos.x < 619) && (pos.y > 31) && (pos.y < 134) && DistritosMaxeados4 >= 1)
            {

                irudiaKendu(azkena);
                Distrito4Maxeado(click, hobekuntza);
                pantaila = 1;
            }
            if ((pos.x > 536) && (pos.x < 619) && (pos.y > 349) && (pos.y < 453))
            {
                irudiaKendu(azkena);
                Distrito1Maxeado(click, hobekuntza, 1, 0);
                pantaila = 1;
            }
            if ((pos.x > 535) && (pos.x < 619) && (pos.y > 31) && (pos.y < 134) && DistritosMaxeados4 < 1 && DistritosMaxeados3 >= 1) {
                irudiaKendu(azkena);
                LaugarrenDistrito(0, 11, 11, click, hobekuntza);
                pantaila = 1;
            }
            if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT))
            {
                click = click + hobekuntza;;
                printf("%f\n", click);
                sprintf(str, "%5.lf $", click);
                sprintf(ztr1, "Polizia koartela, nibel: 10");
                sprintf(ztr2, "Etxe modernoa, nibel: 10");
                sprintf(ztr3, "Estazioa, nibel: 10");
                textuaIdatzi(300, 50, str);
                pantailaBerriztu();
                pantailaGarbitu();
                trantxizioa();
                textuaIdatzi(300, 50, str);
                //nibelak
                textuaIdatzi_v2(20, 100, ztr1);
                textuaIdatzi_v2(20, 120, ztr2);
                textuaIdatzi_v2(20, 140, ztr3);
                textuaIdatzi_v2(20, 415, "Koartela MAX");
                textuaIdatzi_v2(200, 415, "Etxea MAX");
                textuaIdatzi_v2(370, 415, "Estazioa MAX");
                pantailaBerriztu();
            }
        }
    }

}

void Distrito3Maxeado(double klk, double hbk, int MXD2, int MXD4) {
    char str[128], ztr1[128], ztr2[128], ztr3[128];
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;
    float click = klk;
    float hobekuntza = hbk;
    int DistritosMaxeados2 = MXD2;
    int DistritosMaxeados4 = MXD4;

    irudiaKargatu(".\\img\\Distrito3_final.bmp");
    azkena = ".\\img\\Distrito3_final.bmp";
    trantxizioa();

    sprintf(str, "%5.lf $", click);
    sprintf(ztr1, "Ospitala, nibel: 10");
    sprintf(ztr2, "Taberna, nibel: 10");
    sprintf(ztr3, "Denda, nibel: 10");
    textuaIdatzi(300, 50, str);
    pantailaBerriztu();
    pantailaGarbitu();
    trantxizioa();
    textuaIdatzi(300, 50, str);
    //nibelak
    textuaIdatzi_v2(20, 100, ztr1);
    textuaIdatzi_v2(20, 120, ztr2);
    textuaIdatzi_v2(20, 140, ztr3);
    textuaIdatzi_v2(25, 435, "Ospitala MAX");
    textuaIdatzi_v2(230, 435, "Taberna MAX");
    textuaIdatzi_v2(455, 435, "Denda MAX");
    pantailaBerriztu();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            if ((pos.x > 2) && (pos.x < 65) && (pos.y > 0) && (pos.y < 81) && DistritosMaxeados4 >= 1)
            {
                irudiaKendu(azkena);
                Distrito4Maxeado(click, hobekuntza);
                pantaila = 1;
            }
            if ((pos.x > 2) && (pos.x < 65) && (pos.y > 317) && (pos.y < 403))
            {
                irudiaKendu(azkena);
                Distrito1Maxeado(click, hobekuntza, 0, 1);
                pantaila = 1;
            }
            if ((pos.x > 2) && (pos.x < 65) && (pos.y > 0) && (pos.y < 81) && DistritosMaxeados4 < 1 && DistritosMaxeados2 >= 1)
            {
                printf("%d", DistritosMaxeados2);
                irudiaKendu(azkena);
                LaugarrenDistrito(0, 11, 11, click, hobekuntza);
                pantaila = 1;
            }
            if ((pos.x < SCREEN_WIDTH) && (pos.y < SCREEN_HEIGHT))
            {
                click = click + hobekuntza;
                sprintf(str, "%5.lf $", click);
                sprintf(ztr1, "Ospitala, nibel: 10");
                sprintf(ztr2, "Taberna, nibel: 10");
                sprintf(ztr3, "Denda, nibel: 10");
                textuaIdatzi(300, 50, str);
                pantailaBerriztu();
                pantailaGarbitu();
                trantxizioa();
                textuaIdatzi(300, 50, str);
                //nibelak
                textuaIdatzi_v2(20, 100, ztr1);
                textuaIdatzi_v2(20, 120, ztr2);
                textuaIdatzi_v2(20, 140, ztr3);
                textuaIdatzi_v2(25, 435, "Ospitala MAX");
                textuaIdatzi_v2(230, 435, "Taberna MAX");
                textuaIdatzi_v2(455, 435, "Denda MAX");
                pantailaBerriztu();
            }
        }
    }
}

void Distrito4Maxeado(double klk, double hbk) {
    char str[128];
    POSIZIOA pos;
    int ebentu = 0, pantaila = 0;
    int azkena = 0;
    float click = klk;
    float hobekuntza = hbk;

    irudiaKargatu(".\\img\\ANTEULTIMA.bmp");
    azkena = ".\\img\\ANTEULTIMA.bmp";
    trantxizioa();

    textuaIdatzi_v2(210, 420, "HIRIA IKUSI");
    pantailaBerriztu();

    while (!pantaila) {
        ebentu = ebentuaJasoGertatuBada();
        pos = saguarenPosizioa();
        printf("__X:%d -- Y:%d__\n", pos.x, pos.y);
        if (ebentu == SAGU_BOTOIA_EZKERRA) {
            if ((pos.x > 11) && (pos.x < 153) && (pos.y > 406) && (pos.y < 462)) {
                irudiaKendu(azkena);
                Distrito2Maxeado(click, hobekuntza, 1, 1);
                pantaila = 1;
            }
            if ((pos.x > 497) && (pos.x < 640) && (pos.y > 413) && (pos.y < 470)) {
                irudiaKendu(azkena);
                Distrito3Maxeado(click, hobekuntza, 1, 1);
                pantaila = 1;
            }
            if ((pos.x > 190) && (pos.x < 468) && (pos.y > 404) && (pos.y < 465)) {
                irudiaKendu(azkena);
                PantallaFinal();
                pantaila = 1;
            }
        }
    }
}