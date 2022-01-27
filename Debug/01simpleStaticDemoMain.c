#include "graphics.h"
#include "ebentoak.h"
#include "soinua.h"
#include "text.h"
#include "imagen.h"
#include <stdio.h>
#include <windows.h>

#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."

#define JOKOA_SOUND ".\\sound\\FondoMusica.wav"

int main(int argc, char* str[]) {
    hasieratu();
    BotoiakHasi();
    audioTerminate();
    sgItxi();
    pantailaBerriztu();
    pantailaGarbitu();
}