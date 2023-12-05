#include "projfunc.h"

void disp_menu() {
   printf("     ******************\n");
   printf("—————*FRACTAL EXPLORER*—————\n");
   printf("     ******************\n\n");
   printf("This fractal explorer will display two fractals:\nthe Mandelbrot set on the left pane\nand a Julia set on the right pane\n\n");
   printf("     ******************\n");
   printf("—————*    CONTROLS    *—————\n");
   printf("     ******************\n\n");
   printf("To use this application, there are a few controls:\n\tMove your mouse over a point on the Mandelbrot set \n\tand press 'j' to view the corresponding Julia set.\n\tPoints near the edge of the Mandelbrot set will\n\tproduce the most interesting Julia sets.\n\n");
   printf("\tMove your mouse over a point on either set\n\tand press 'i' to zoom in, or 'o' to zoom out.\n\n");
   printf("\tUse WASD and the arrow keys to pan over \n\tthe Mandelbrot and Julia sets, respectively.\n\n");
   printf("\tPress 'r' to reset to the initial view.\n\n");
   printf("\tPress 'q' to exit the program.\n\n");

   printf("Press ENTER to continue.");
   char c;
   scanf("%c", &c);
   printf("\n");
}

void draw_sets(int height, coords pos) {

   int mand_colors[height][height][3];
   int jul_colors[height][height][3];

   for (int i = 0; i < height; i++) { // i is the real coordinate
      for (int j = 0; j < height; j++) { // and j is the complex coordinate
         long double complex mb_curr_point = pos.m_ll+
                                 + i*creall(pos.m_ur-pos.m_ll)/height 
                                 + j*cimagl(pos.m_ur-pos.m_ll)/height*I;
         long double complex c_1 = 0+0*I;
         long double complex c_2 = pos.j_ll+
                                 + i*creall(pos.j_ur-pos.j_ll)/height 
                                 + j*cimagl(pos.j_ur-pos.j_ll)/height*I;

         int k = 0;
         int l = 0;
         do {
            c_1 = c_1*c_1+mb_curr_point;
            k++;
         } while ((cabs(c_1) <= 2)&&(k < 255)); 
         mand_colors[i][j][0] = k;
         mand_colors[i][j][1] = k;
         mand_colors[i][j][2] = k;
         gfx_color(mand_colors[i][j][0],mand_colors[i][j][1],mand_colors[i][j][2]);
         gfx_point(i, j);

         do {
            c_2 = c_2*c_2+pos.j_seed;
            l++;
         } while ((cabs(c_2) < 2)&&(l < 255)); 
         jul_colors[i][j][0] = l;
         jul_colors[i][j][1] = l;
         jul_colors[i][j][2] = l;
         gfx_color(jul_colors[i][j][0],jul_colors[i][j][1],jul_colors[i][j][2]);
         gfx_point(i+height, j);
      }
   }
} 
