#include <math.h>
#include <stdio.h>
#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "gfx.h"

typedef struct {
   long double complex m_ll;
   long double complex m_ur;
   long double complex j_ll;
   long double complex j_ur;
   long double complex j_seed;
} coords;

void disp_menu();

void draw_sets(int,  coords);
