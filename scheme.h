#pragma once

enum { ColFg, ColBg, ColBorder }; /* Clr scheme index */
enum { SchemeNorm, SchemeSel, SchemeOut, SchemeLast }; /* color schemes */

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#bbbbbb",  "#000000",  "#bbbbbb" },
	[SchemeSel]  = { "#fefefe",  "#993232",  "#533232"  },
	[SchemeOut]  = { "#000000",  "#9ebfbf" , "#323232" },
};
