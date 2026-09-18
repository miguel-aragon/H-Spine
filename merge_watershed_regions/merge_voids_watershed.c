/*

   NAME: 
       MERGE_VOIDS

   DESCRIPTION:
       Merge voids in scale space. This is the first step in the void hierarchy.

   COMPILE AS:


   HISTORY:
       2008-12-08 Ported from IDL code.

   Written by: Miguel Angel Aragon Calvo. 
	       miguel@pha.jhu.edu
               miguel@astro.rug.nl

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../lib/header_struct.h"
#include "../lib/io_files.h"
#include "inc/water_hierarchy.h"

int main(int argc, char **argv)
{
  //--- Data arrays
  int    *Water1      =NULL;
  int    *Water2      =NULL;
  int    *Water12     =NULL;
  //--- Headers
  struct Header Header_Wat1;
  struct Header Header_Wat2;
  struct Header Header_Wat12;

  //====================================
  //--- Read watershed from files
  //====================================
  Water1 = Read_DataCube_int(argv[1], &Header_Wat1);
  Water2 = Read_DataCube_int(argv[2], &Header_Wat2);

  //====================================
  //--- Merge scales
  //====================================
  printf(">>> Mixing regions 1 and 2 \n"); fflush(stdout);
  //Water12 = merge_regions_int(Water1, Water2, Header_Wat1.sizeX*Header_Wat1.sizeY*Header_Wat1.sizeZ);
  Water12 = merge_regions_grid_int(Water1, Water2, Header_Wat1.sizeX*Header_Wat1.sizeY*Header_Wat1.sizeZ,Header_Wat1.sizeX,Header_Wat1.sizeY,Header_Wat1.sizeZ);

  //====================================
  //--- Fix indexes of regions after merging
  //====================================
  //printf(">>> Fixing ID's of regions \n"); fflush(stdout);
  //fix_watershed_IDs(Water12,Header_Wat1.sizeX*Header_Wat1.sizeY*Header_Wat1.sizeZ);

  //====================================
  //--- Write merged watershed to file
  //====================================
  Write_DataCube_int(argv[3], &Header_Wat1, Water12);

  //--- Free memory
  free(Water1);
  free(Water2);
  free(Water12);

  printf("\n\n>>> Clean exit from program!\n"); fflush(stdout);

  exit(0);

}
