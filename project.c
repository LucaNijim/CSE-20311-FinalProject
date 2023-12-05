#include "projfunc.h"

int main() {
   disp_menu();

   int height = 550;
   int width = height*2;
   gfx_open(width, height, "Mandelbrot and Julia Set Rendering");

   int x, y;

   bool cont = true;
   bool reprint = true;

   coords pos = { .m_ll = -2.0-2.0*I, 
                  .m_ur = 2.0+2.0*I,
                  .j_ll = -2.0-2.0*I,
                  .j_ur = 2.0+2.0*I,
                  .j_seed = 0+0*I};

   pos.j_seed = 0+0*I;
 
   char c;

   while (cont) {
      if (reprint) {
         gfx_clear();
         draw_sets(height, pos);
         reprint = false;
      }
      c = gfx_wait();
      switch (c) {
         case 'q': return 0;
         case 'j': ; 
            x = gfx_xpos();
            y = gfx_ypos();
            if (x <= height) {
               pos.j_seed = pos.m_ll + 
                            x*creall(pos.m_ur-pos.m_ll)/height + 
                            (height-y)*cimagl(pos.m_ur-pos.m_ll)*I/height;
               pos.j_ll = -2-2*I;
               pos.j_ur = 2+2*I;
               reprint = true;
            }
            break;
         case 'i': ;
            x = gfx_xpos();
            y = gfx_ypos();
            if (x <= height) {
               long double complex curr_pos = pos.m_ll + 
                            x*creall(pos.m_ur-pos.m_ll)/height + 
                            y*cimagl(pos.m_ur-pos.m_ll)*I/height;
               long double complex newm_ll, newm_ur;
               newm_ll = curr_pos - (pos.m_ur-pos.m_ll)/5;
               newm_ur = curr_pos + (pos.m_ur-pos.m_ll)/5;
               pos.m_ll = newm_ll;
               pos.m_ur = newm_ur;
            } else {
               long double complex curr_pos = pos.j_ll + 
                            (x-height)*creall(pos.j_ur-pos.j_ll)/height + 
                            y*cimagl(pos.j_ur-pos.j_ll)*I/height;
               long double complex newj_ll, newj_ur;
               newj_ll = curr_pos - (pos.j_ur-pos.j_ll)/5;
               newj_ur = curr_pos + (pos.j_ur-pos.j_ll)/5;
               pos.j_ll = newj_ll;
               pos.j_ur = newj_ur;
            }
            reprint=true;
            break;
         case 'o': ;
            x = gfx_xpos();
            y = gfx_ypos();
            if (x <= height) {
               long double complex curr_pos = pos.m_ll + 
                            x*creall(pos.m_ur-pos.m_ll)/height + 
                            y*cimagl(pos.m_ur-pos.m_ll)*I/height;
               long double complex newm_ll, newm_ur;
               newm_ll = curr_pos - (pos.m_ur-pos.m_ll)*5;
               newm_ur = curr_pos + (pos.m_ur-pos.m_ll)*5;
               pos.m_ll = newm_ll;
               pos.m_ur = newm_ur;
            } else {
               long double complex curr_pos = pos.j_ll + 
                            (x-height)*creall(pos.j_ur-pos.j_ll)/height + 
                            y*cimagl(pos.j_ur-pos.j_ll)*I/height;
               long double complex newj_ll, newj_ur;
               newj_ll = curr_pos - (pos.j_ur-pos.j_ll)*5;
               newj_ur = curr_pos + (pos.j_ur-pos.j_ll)*5;
               pos.j_ll = newj_ll;
               pos.j_ur = newj_ur;
            }
            reprint=true;
            break;
         case 'a': ;
            long double l_inc = (creall(pos.m_ur)-creall(pos.m_ll))/10;
            pos.m_ll -= l_inc;
            pos.m_ur -= l_inc;
            reprint=true;
            break;
         case 'd': ;
            long double r_inc = (creall(pos.m_ur)-creall(pos.m_ll))/10;
            pos.m_ll += r_inc;
            pos.m_ur += r_inc;
            reprint = true;
            break;
         case 'w': ;
            long double u_inc = (cimagl(pos.m_ur)-cimagl(pos.m_ll))/10;
            pos.m_ll -= u_inc*I;
            pos.m_ur -= u_inc*I;
            reprint = true;
            break;
         case 's': ;
            long double d_inc = (cimagl(pos.m_ur)-cimagl(pos.m_ll))/10;
            pos.m_ll += d_inc*I;
            pos.m_ur += d_inc*I;
            reprint = true;
            break;
         case 81: ;
            long double lj_inc = (creall(pos.j_ur)-creall(pos.j_ll))/10;
            pos.j_ll -= lj_inc;
            pos.j_ur -= lj_inc;
            reprint=true;
            break;
         case 83: ;
            long double rj_inc = (creall(pos.j_ur)-creall(pos.j_ll))/10;
            pos.j_ll += rj_inc;
            pos.j_ur += rj_inc;
            reprint = true;
            break;
         case 82: ;
            long double uj_inc = (cimagl(pos.j_ur)-cimagl(pos.j_ll))/10;
            pos.j_ll -= uj_inc*I;
            pos.j_ur -= uj_inc*I;
            reprint = true;
            break;
         case 84: ;
            long double dj_inc = (cimagl(pos.j_ur)-cimagl(pos.j_ll))/10;
            pos.m_ll += dj_inc*I;
            pos.m_ur += dj_inc*I;
            reprint = true;
            break;
         case 'r':
            pos.m_ll = -2-2*I;
            pos.m_ur = 2+2*I;
            pos.j_ll = -2-2*I;
            pos.j_ur = 2+2*I;
            pos.j_seed = 0+0*I;
            reprint = true;
            break;
         default: break;
      }
   }

   return 0;
}
