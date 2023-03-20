#pragma once

enum { ColFg, ColBg, ColBorder }; /* Clr scheme index */
enum { SchemeNorm, SchemeSel, SchemeOut, SchemeLast, SchemeUrg }; /* color schemes */

static const char *colors[][4]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { "#000000",  "#d3d7cf",  "#888888" },
	[SchemeSel]  = { "#fefeff",  "#3232ae",  "#32327a"  },
	[SchemeOut]  = { "#000000",  "#9ebfbf" , "#323232" },
	[SchemeUrg]  = { "#000000",  "#9ebfbf" , "#FF3232" },
};
