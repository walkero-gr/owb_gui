/*
**	Includes and definitions header
**	Automatically generated by Emperor
*/

#define ALL_REACTION_CLASSES
#define ALL_REACTION_MACROS

#define CATCOMP_NUMBERS
#define CATCOMP_STRINGS

#define TapeDeckObject   IIntuition->NewObject(NULL, "tapedeck.gadget"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos/dos.h>
#include <math.h>
#include <proto/asl.h>
#include <proto/dos.h>
#include <proto/exec.h>
#include <proto/gadtools.h>
#include <proto/graphics.h>
#include <proto/icon.h>
#include <proto/intuition.h>
#include <proto/locale.h>
#include <proto/utility.h>
#include <proto/wb.h>
#include <proto/colorwheel.h>
#include <proto/datebrowser.h>      
#include <libraries/picasso96.h>
#include <proto/dos.h>
#include <libraries/resource.h>
#include <proto/texteditor.h>
#include <gadgets/colorwheel.h>
#include <gadgets/datebrowser.h>
#include <gadgets/gradientslider.h>
#include <gadgets/tapedeck.h>
#include <gadgets/texteditor.h>
#include <proto/texteditor.h>
#include <reaction/reaction.h>
#include <intuition/icclass.h>
#include <intuition/imageclass.h>
#include <intuition/gadgetclass.h>
#include <workbench/startup.h>

#include "globals.h"

#define VERSION "0"
#define REVISION "7"

#define PROGNAME "OWB_gui"
#define DEVELOPER "George Sokianos"
#define DATE "15-Mar-2008"

#define Menu_Project1 65504
#define Menu_Information1 63488
#define Menu_prefs 63520
#define Menu_Quit1 63584
#define Menutitle1 65505
#define Menuitem1 63489
#define Menuitem2 63521
#define Menuitem3 63553
#define Menuitem4 63585
#define Menuitem5 63617
#define Menuitem6 63649

#define CFG_FILE "PROGDIR:prog.cfg"
#define BKM_FILE "PROGDIR:bookmarks.txt"
