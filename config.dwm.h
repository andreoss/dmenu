#pragma once
#define VERSION "121"
#include "scheme.h"
#include "dwm.h"
#include "config.def.h"

/*
 * alt-tab configuration 
 */
static const unsigned int mod_key_tab = 0x40;	/* if this key is hold the 
						 * alt-tab functionality
						 * stays acitve. This key
						 * must be the same as key 
						 * that is used to active
						 * functin
						 * switch_windows_start ` */
static const unsigned int mod_key_cycle = 0x17;	/* if this key is hit the
						 * alt-tab program moves
						 * one position forward in 
						 * clients stack. This key 
						 * must be the same as key 
						 * that is used to active
						 * functin
						 * switch_windows_start */
static const unsigned int menu_position_y = 1;	/* tab position on Y axis, 
						 * 0 = bottom, 1 = center, 
						 * 2 = top */
static const unsigned int menu_position_x = 1;	/* tab position on X axis, 
						 * 0 = left, 1 = center, 2 
						 * = right */
static const unsigned int menu_max_width = 600;	/* tab menu width */
static const unsigned int menu_max_height = 200;	/* tab menu height 
							 */
static const int user_bh = 0;	/* 0 means that dwm will calculate bar
				 * height, >= 1 means dwm will user_bh as
				 * bar height */

static const unsigned int borderpx = 3;	/* border pixel of windows */
static const unsigned int snap = 32;	/* snap pixel */
static const int showbar = 1;	/* 0 means no bar */

static const int swallowfloating = 1;	/* 1 means swallow floating
					 * windows by default */
/*
 * tagging 
 */
static const char *tags[] = {
    "Ⅰ",
    "Ⅱ",
    "Ⅲ",
    "Ⅳ",
    "Ⅴ",
    "Ⅵ",
    "Ⅶ",
    "Ⅷ",
    "Ⅸ"
};

static const Rule rules[] = {
    /*
     * class instance title tags mask isfloating isterminal noswallow
     * monitor 
     */
    {"Firefox", NULL, NULL, 1 << 8, 0, 0, -1, -1},
    {"st", NULL, NULL, 0, 0, 1, 0, -1},
};

/*
 * layout(s) 
 */
static const float mfact = 0.55;	/* factor of master area size
					 * [0.05..0.95] */
static const int nmaster = 1;	/* number of clients in master area */
static const int resizehints = 1;	/* 1 means respect size hints in
					 * tiled resizals */
static const int lockfullscreen = 1;	/* 1 will force focus on the
					 * fullscreen window */

static const Layout layouts[] = {
    /*
     * symbol arrange function 
     */
    {" Ŧ ", tile},		/* first entry is default */
    {" ƒ ", NULL},		/* no layout function means floating
				 * behavior */
    {" Ɱ ", monocle},
};

/*
 * key definitions 
 */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/*
 * helper for spawning shell commands in the pre dwm-5.0 fashion 
 */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/*
 * commands 
 */
static const char *termcmd[] = { "st", NULL };
static const char *dmenucmd[] = { "dmenu_run", NULL };

static const Key keys[] = {
    /*
     * modifier key function argument 
     */
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_slash, spawn, {.v = dmenucmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_q, view, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {Mod1Mask, XK_Tab, switch_windows_start, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY | ShiftMask, XK_f, togglealwaysontop, {0}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
	TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6)
	TAGKEYS(XK_8, 7)
    TAGKEYS(XK_9, 8) {MODKEY | ShiftMask, XK_q, quit, {0}},
};

/*
 * button definitions 
 */
/*
 * click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin 
 */
static const Button buttons[] = {
    /*
     * click event mask button function argument 
     */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
