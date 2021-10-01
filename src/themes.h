/*-------------------------------------------------------------------------
 *
 * themes.h
 *	  themes initialization
 *
 * Portions Copyright (c) 2017-2021 Pavel Stehule
 *
 * IDENTIFICATION
 *	  src/themes.h
 *
 *-------------------------------------------------------------------------
 */

#ifndef PSPG_THEMES_H
#define PSPG_THEMES_H

#include <stdbool.h>

#if defined HAVE_NCURSESW_CURSES_H
#include <ncursesw/curses.h>
#elif defined HAVE_NCURSESW_H
#include <ncursesw.h>
#elif defined HAVE_NCURSES_CURSES_H
#include <ncurses/curses.h>
#elif defined HAVE_NCURSES_H
#include <ncurses.h>
#elif defined HAVE_CURSES_H
#include <curses.h>
#else
/* fallback */
#include <ncurses/ncurses.h>
#endif

typedef struct
{
	attr_t data_attr;				/* colors for data (alphanums) */
	attr_t line_attr;				/* colors for borders */
	attr_t expi_attr;				/* colors for expanded headers */
	attr_t cursor_data_attr;		/* colors for cursor on data positions */
	attr_t cursor_line_attr;		/* colors for cursor on border position */
	attr_t cursor_expi_attr;		/* colors for cursor on expanded headers */
	attr_t bookmark_data_attr;		/* colors for bookmark */
	attr_t bookmark_line_attr;		/* colors for bookmark line art */
	attr_t cursor_bookmark_attr;	/* colors for cursor on bookmark line */
	attr_t found_str_attr;			/* colors for marked string */
	attr_t pattern_data_attr;		/* colors for pattern line data */
	attr_t pattern_line_attr;		/* colors for pattern line art */
	attr_t cursor_pattern_attr;		/* colors for pattern on cursor line */
	attr_t title_attr;				/* colors for title window */
	attr_t info_attr;				/* colors for bottom info text */
	attr_t prompt_attr;				/* less prompt color */
	attr_t cursor_rownum_attr;		/* colors for cursor rownum column */
	attr_t cross_cursor_attr;		/* colors for cross horizontal and vertical cursor (data) */
	attr_t cross_cursor_line_attr;	/* colors for cross horizontal and vertical cursor (border) */
	attr_t pattern_vertical_cursor_attr;
	attr_t pattern_vertical_cursor_line_attr;
	attr_t error_attr;				/* colors for display error */
	attr_t input_attr;				/* colors for input line */
	attr_t scrollbar_arrow_attr;	/* colors for scrollbar arrows symbols */
	attr_t scrollbar_attr;			/* colors for scrollbar background */
	attr_t scrollbar_slider_attr;	/* colors for scrollbar slider */
	attr_t scrollbar_active_slider_attr; /* colors for active scrollbar slider */
	chtype scrollbar_slider_symbol;
	bool scrollbar_use_arrows;
	attr_t selection_attr;
	attr_t selection_cursor_attr;
	attr_t status_bar_attr;
} Theme;

#define		WINDOW_LUC				0
#define		WINDOW_FIX_ROWS			1
#define		WINDOW_FIX_COLS			2
#define		WINDOW_ROWS				3
#define		WINDOW_FOOTER			4
#define		WINDOW_TOP_BAR			5
#define		WINDOW_BOTTOM_BAR		6
#define		WINDOW_ROWNUM			7
#define		WINDOW_ROWNUM_LUC		8
#define		WINDOW_VSCROLLBAR		9

extern void initialize_color_pairs(int theme, bool bold_labels, bool bold_cursor);
extern void initialize_theme(int theme, int window_identifier, bool is_tabular_fmt, bool no_highlight_lines, Theme *t);

#endif
