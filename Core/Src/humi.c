/*********************************************************************
*            (c) 1998 - 2024 SEGGER Microcontroller GmbH             *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter for emWin (Demo version) V6.46.            *
*        Compiled Oct 11 2024, 10:02:08                              *
*                                                                    *
*        (c) 1998 - 2024 SEGGER Microcontroller GmbH                 *
*                                                                    *
*        May not be used in a product                                *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: humi                                                  *
* Dimensions:  40 * 40                                               *
* NumColors:   16bpp: 65536                                          *
* NumBytes:    3220                                                  *
*                                                                    *
**********************************************************************
*/

#include <image.h>


#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmhumi;

static GUI_CONST_STORAGE unsigned short _achumi[] = {
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 
        0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x9DBF, 0xAE1F, 0xAE3F, 0xAE3F, 0xAE1F, 0x9DBF, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x959F, 0xA5FF, 0xAE3F, 0xB65F, 0xAE3F, 0xA5FF, 0x9D9F, 0x957F, 
        0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x9DDF, 0xBE9F, 0xD73F, 0xDF7F, 0xDF7E, 0xDF7F, 0xDF7F, 0xDF9F, 0xDF7F, 0xD73F, 0xB67F, 0x9D9F, 0x957F, 0xAE1F, 0xC6DF, 0xDF5F, 0xDF7F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xC6FF, 
        0xAE1F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x959F, 0xBE9F, 0xDF7F, 0xDF9E, 0xDF7F, 0xDF7F, 0xDF7F, 0xDF7F, 0xDF7F, 0xDF7E, 0xE618, 0xE6FC, 0xDF7E, 0xD75F, 0xCF1F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xCF1E, 0xA5DF, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x9DBF, 0xCF1F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xE639, 0xDF1D, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xB65F, 0x8D3D, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x9DBF, 0xD73F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF9F, 0xB63A, 0xAD54, 0x8D3D, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0xCEFE, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xAE3B, 0xA5DF, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0xB65F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xC6FD, 0xCF3D, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xD73E, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x959F, 0xD75E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9E, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0x8D79, 0x95B9, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7F, 0xB65F, 0x957F, 0x957F,
  0x957F, 0x957F, 0xB65F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9E, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF7E, 0xCF1D, 0x85BA, 0x7D59, 0xC71D, 0xDF7E, 0x8538, 0xC6DD, 0xDF7E, 0xDF9F, 0xDF9F, 
        0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xD73E, 0x957F, 0x957F,
  0x957F, 0x957F, 0xCF1E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF9E, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF7E, 0x8D79, 0xA6DE, 0x9E9D, 0x8D79, 0xD75E, 0x7D59, 0x9DDA, 0xDF7E, 0xDF9F, 0xDF9F, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xA5DF, 0x957F,
  0x957F, 0x959F, 0xD73E, 0xBEBC, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF7F, 0xDF7E, 0xDF7E, 0xD75E, 0xDF7E, 0xDF7E, 0xBE9C, 0x8DFB, 0xA6FE, 0xA6FE, 0x7D79, 0x9579, 0x9E9D, 0x8559, 0xCF3D, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xB65F, 0x957F,
  0x957F, 0x9DDF, 0xC6BC, 0xE651, 0xB595, 0xDF9E, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7F, 0xC6BC, 0x9D98, 0xA554, 0xAD52, 0xB552, 0xAD32, 0xA534, 0x7D38, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6DE, 0x6CB7, 0xAEFE, 0x9E7C, 0xA61A, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7F, 0xBE9E, 0x957F,
  0x957F, 0xA5FF, 0xDF7E, 0xB594, 0xCEFC, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xCF1D, 0x9D56, 0xC591, 0xF690, 0xFE91, 0xFE91, 0xFE90, 0xFE90, 0xB552, 0x9EBD, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0x963C, 0x963C, 0xA6FE, 0x8559, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xC6DF, 0x957F,
  0x957F, 0xA5DF, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xBEBC, 0xAD32, 0xF691, 0xFE90, 0xDE11, 0xAD32, 0xA554, 0xAD55, 0xA554, 0x7CB5, 0xBF3E, 0xA6FE, 0xA6FE, 0xA6FE, 0xAEFE, 0xA6FE, 0x7D9A, 0xA6FE, 0x9E7D, 0xA5FA, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xC6BE, 0x957F,
  0x957F, 0x9DBF, 0xDF7F, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xC6DC, 0xAD52, 0xFE90, 0xEE51, 0x9D13, 0xB619, 0xEF7D, 0xF7BE, 0xF7BE, 0xF7BE, 0xA5B9, 0xC73E, 0xB71E, 0xA6FE, 0xAEFE, 0xAEFE, 0x9E9D, 0x85BA, 0xA6FE, 0xA6FE, 0x859A, 0xCF1D, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7F, 0xBE9E, 0x957F,
  0x957F, 0x957F, 0xDF7F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0x9D33, 0xFE91, 0xE631, 0x9D36, 0xE75D, 0xF7DE, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xDF3D, 0x8DBA, 0xDF9E, 0xC75E, 0xBF3E, 0xAEFE, 0x7D59, 0xA6BE, 0xA6FE, 0xA6FE, 0xA6DE, 0x8D59, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xAE3F, 0x957F,
  0x957F, 0x957F, 0xCEFE, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xA5D9, 0xEE51, 0xF671, 0x9D35, 0xEF7D, 0xFFDF, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xC67B, 0x8579, 0xA69C, 0x9E5C, 0x7539, 0x963C, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0x965C, 
        0xAE1A, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0x9DBF, 0x957F,
  0x957F, 0x957F, 0xB63F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xAD53, 0xFE90, 0xB552, 0xDEFC, 0xAD98, 0xAC53, 0xAC53, 0xB5D9, 0xFFFF, 0xCE9B, 0xA494, 0x9C54, 0xBE5A, 0xADF9, 0x8DDB, 0x8E1B, 0xA6DE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 
        0x8559, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xCF1E, 0x957F, 0x957F,
  0x957F, 0x957F, 0x959F, 0xD75E, 0xDF7E, 0xDF7E, 0xDF7E, 0xBE9C, 0xD5D1, 0xF691, 0xA576, 0xBE3A, 0xD452, 0xDC72, 0xE472, 0xC432, 0xC67B, 0xA454, 0xF492, 0x9C54, 0xDEDB, 0x8D79, 0xB71E, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 
        0x963C, 0xBE9C, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xAE3F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0xC6BF, 0xDF7E, 0xDF7E, 0xDF7E, 0xA5D9, 0xF671, 0xD5F1, 0xC65A, 0xAD98, 0xF492, 0xA454, 0xA433, 0xEC72, 0x6BB3, 0xE492, 0xBC32, 0xBE19, 0xF7BE, 0x8579, 0xC75E, 0xAEFE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 
        0xA6BE, 0xA5FA, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0x9D9F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x9DBF, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xA597, 0xFE90, 0xBD71, 0xDF3C, 0xB5F9, 0xE472, 0xCC52, 0xD452, 0xCC32, 0xBC12, 0xEC92, 0x9CF6, 0xEF7D, 0xFFFF, 0x8D99, 0xC75E, 0xC75E, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 
        0x9E9D, 0x9DDA, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xB65F, 0x957F, 0x957F,
  0x957F, 0x957F, 0xB67F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xA597, 0xFE90, 0xB551, 0xE75D, 0xF7BE, 0x9CB5, 0xBC12, 0xB412, 0x93B2, 0xF4B2, 0x93B2, 0x9C74, 0xACD5, 0xC65A, 0x95B9, 0xAF1E, 0xEFBF, 0xAF1E, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 
        0x85BA, 0xB67B, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xD73F, 0x957F, 0x957F,
  0x957F, 0x957F, 0xCF1E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xA5B8, 0xFE91, 0xC5B1, 0xD6FC, 0xFFFF, 0xFFDF, 0xE75D, 0xA557, 0xDC73, 0xCC93, 0xC432, 0xEC92, 0xEC92, 0xBC32, 0xADD9, 0x8E1B, 0xCF5E, 0xEFBF, 0xBF3E, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 0xA6FE, 
        0x7518, 0xC6FD, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xA5DF, 0x957F,
  0x957F, 0x959F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xAE1A, 0xE651, 0xEE51, 0xB5F9, 0xFFFF, 0xFFFF, 0xE75D, 0xB453, 0xECD3, 0x7392, 0xF492, 0xA433, 0xA433, 0xEC92, 0xAD98, 0x9DB9, 0x9E7D, 0xC75E, 0xEFBF, 0xEFBF, 0xD77E, 0xC73E, 0xA6FE, 0x7D39, 
        0x9E1A, 0xD75E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xB65F, 0x957F,
  0x957F, 0x9DDF, 0xDF7F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xD73D, 0xB571, 0xFE90, 0xA534, 0xF7DF, 0xFFFF, 0xA516, 0xECB3, 0xAC33, 0x9D37, 0xEC92, 0xC432, 0xC452, 0xDC72, 0xB5F9, 0xFFDF, 0xADFA, 0x7D59, 0x9EBD, 0xAEFE, 0xA6DE, 0x8E1C, 0x7518, 0x9DFA, 
        0xC6FD, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7F, 0xBE9E, 0x957F,
  0x957F, 0xA5DF, 0xDF7F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0x9D56, 0xFE91, 0xDDF1, 0xBE5A, 0xC67B, 0xAC33, 0xBC32, 0xADB8, 0xEF9E, 0x9C54, 0xD452, 0xCC52, 0x9474, 0xEF7D, 0xFFFF, 0xBE19, 0xD5D1, 0xB551, 0x6C76, 0x7D38, 0x95B9, 0xAE7B, 0xC6FD, 
        0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7F, 0xC6DE, 0x957F,
  0x957F, 0xA5DF, 0xDF7F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xC6DC, 0xC591, 0xFE90, 0xBD72, 0xC67B, 0xDF1D, 0xDF1C, 0xF7DE, 0xFFFF, 0xF7BE, 0xC67A, 0xC67A, 0xEF9D, 0xFFFF, 0xCEDB, 0xBD72, 0xFE90, 0xB552, 0xAE5B, 0xBEDC, 0xC6FD, 0xD75E, 0xDF7E, 
        0xDF7E, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xC6BE, 0x957F,
  0x957F, 0x9DBF, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xA5B8, 0xE631, 0xFE91, 0xBD72, 0xBE3A, 0xFFDF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xF7DF, 0xB619, 0xBD92, 0xFE90, 0xDDF1, 0x9578, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF9F, 0xA61A, 0x8579, 0xDF7E, 0xDF7E, 0xDF7F, 0xBE9E, 0x957F,
  0x957F, 0x957F, 0xD75E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7F, 0xDF7E, 0x9D77, 0xE611, 0xFE90, 0xDE11, 0xAD54, 0xB5D9, 0xCEBB, 0xD6FC, 0xCE9B, 0xADD8, 0xAD53, 0xE631, 0xFE90, 0xDDF1, 0x8D37, 0xD75E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 
        0xDF7E, 0xDF7E, 0xB65B, 0xA5FA, 0xD75E, 0xDF7E, 0xDF7E, 0xAE3F, 0x957F,
  0x957F, 0x957F, 0xC6DE, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF9E, 0xA5B9, 0xBD71, 0xFE90, 0xFE91, 0xF670, 0xDE11, 0xD5D1, 0xDE11, 0xF691, 0xFE90, 0xF690, 0xB551, 0x9578, 0xD75E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 
        0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0x9DBF, 0x957F,
  0x957F, 0x957F, 0xADDE, 0xE6BB, 0xDF3D, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9E, 0xDF9F, 0xDF9F, 0xDF7E, 0xC6DC, 0x9D56, 0xB552, 0xDE11, 0xFE90, 0xFE90, 0xF691, 0xDE11, 0xAD32, 0x9536, 0xBEBC, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xCF1E, 0x957F, 0x957F,
  0x957F, 0x957F, 0x9D7E, 0xE536, 0xDF3D, 0xDF7E, 0xDF9E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xD75E, 0xAE3B, 0x9D99, 0x9D98, 0x9599, 0xAE3B, 0xCF3E, 0xDF7E, 0xDF9E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7F, 0xAE1F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0xAE1E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xCEFE, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0xBEBE, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xD75F, 0x9DBF, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0xC6FF, 0xDF9E, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xC6BC, 0xBDF9, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xA5FF, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0xC6BF, 0xDF7F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xCEFD, 0xCC73, 0xC4D5, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 
        0xDF7E, 0xDF7E, 0xD73F, 0xA5DF, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0xAE1F, 0xD73F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xDF7E, 0xCEFF, 0xBE9F, 0xBE7B, 0xBDD9, 0xDF9F, 0xDF9F, 0xDF7E, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 0xDF9F, 
        0xDF7F, 0xBE9F, 0x9D9F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0xAE1F, 0xC6DF, 0xD75F, 0xDF7F, 0xDF7E, 0xDF7E, 0xDF7F, 0xD73F, 0xBE9F, 0xA5DF, 0x957F, 0x957F, 0x9D9F, 0xB65F, 0xCF1F, 0xDF7F, 0xDF7F, 0xDF7E, 0xDF7E, 0xDF7F, 0xCF1F, 0xB67F, 
        0x9DBF, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F,
  0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x9D9F, 0x9DBF, 0x9DBF, 0x959F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x9DBF, 0x9DBF, 0x9DBF, 0x959F, 0x957F, 0x957F, 
        0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F, 0x957F
};

GUI_CONST_STORAGE GUI_BITMAP bmhumi = {
  40, // xSize
  40, // ySize
  80, // BytesPerLine
  16, // BitsPerPixel
  (const unsigned char *)_achumi,  // Pointer to picture data
//  NULL,  // Pointer to palette
//  GUI_DRAW_BMPM565
};

/*************************** End of file ****************************/
