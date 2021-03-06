/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

//
//  Vrml 97 library
//  Copyright (C) 1998 Chris Morley
//  See the file COPYING for license details.
//

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

unsigned char *mpgread(FILE *fp, int *w, int *h, int *nc,
                       int *nf, unsigned char ***);

#ifdef __cplusplus
}
#endif
