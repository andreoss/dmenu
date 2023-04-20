#pragma once

/*
 * Clr scheme index
 */
enum { ColFg, ColBg, ColBorder };
/*
 * color schemes
 */
enum { SchemeNorm, SchemeSel, SchemeOut, SchemeLast, SchemeUrg };

static const char *colors[][4] = {
    /*
     * fg bg border
     */
    [SchemeNorm] = {"#000000", "#d3d7cf", "#888888"},
    [SchemeSel] = {"#fefeff", "#3232ae", "#32327a"},
    [SchemeOut] = {"#000000", "#9ebfbf", "#323232"},
    [SchemeUrg] = {"#000000", "#9ebfbf", "#FF3232"},
};
