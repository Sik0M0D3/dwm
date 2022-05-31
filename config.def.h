/* See LICENSE file for copyright and license details. */
/* Appearance */
static const unsigned int snap            = 8;      /* snap pixel */
static const unsigned int gappx[]         = { 10 }; /* windows gaps size, can be custom per tag */
static const unsigned int borderpx        = 1;      /* border pixel of windows */
static const unsigned int colorfultitle   = 1;      /* 0 = use SchemeTitle and SchemeTitleFloat */
static const unsigned int systraypinning  = 1;      /* 0 = pin to selected : pin to monitor X */
static const unsigned int systrayspacing  = 3;      /* systray spacing between icons */
static const int systraypinningfailfirst  = 1;      /* 0 = on last monitor : 1 = on first */
static const int startwithgaps[]          = { 1 };  /* 0 = off : 1 = on, can be custom per tag */
static const int viewonrulestag           = 1;      /* 1 = auto switch view to spawned clients */
static const int focusonwheel             = 0;      /* 0 = on Left click : 1 = on Wheel click */
static const int colorfultag              = 1;      /* 0 = use SchemeSel for selected used tag */
static const int showsystray              = 1;      /* 0 = systray off : 1 = systray on */
static const int horizpadbar              = 20;     /* horizontal padding of the status text */
static const int vertpadbar               = 10;     /* vertical padding of the status text */
static const int sidepad                  = 10;     /* bar side padding */
static const int vertpad                  = 10;     /* bar vertical padding */
static const int user_bh                  = 32;     /* 0 = auto/off : 1 = use X as bar height */
static const int showbar                  = 1;      /* 0 = bar Off : 1 = bar On */
static const int topbar                   = 1;      /* 0 = bottom bar : 1 = top bar */
static const char *fonts[]                = {       /* fonts is self-explanatory */
  "Material Design Icons:size=20:antialias=true:autohint=true",
  "JetBrains Mono:style=Regular:size=15:antialias=true:autohint=true",
  /*"Fantasque Sans Mono:size=17:antialias=true:autohint=true",*/
};
static const Bool viewontag = True; /*  <-  follow client to tag on tag switch */

#include "themes/catppuccin.h"  /* <- the colors are defined in the themes headers */
static const char white[] = "#ffffff";
static const char *colors[][3]  = {
  /*                      Fg      Bg      Border  */
  [SchemeNorm]        = { gray2,  black,  black   },
  [SchemeSel]         = { blue,   black,  white   },
  [SchemeTag]         = { gray2,  black,  },  /*  <-  this is like SchemeNorm but for tags */
  [SchemeTag1]        = { red,    black,  red     },
  [SchemeTag2]        = { orange, black,  orange  },
  [SchemeTag3]        = { blue,   black,  blue    },
  [SchemeTag4]        = { green,  black,  green   },
  [SchemeTag5]        = { pink,   black,  pink    },
  [SchemeTag6]        = { yellow, black,  yellow  },
  [SchemeLayout]      = { green,  black   },  /*  <-  Layout symbol colors */
  [SchemeTitle]       = { blue,   black   },  /*  <-  this and the one line below are */
  [SchemeTitleFloat]  = { gray1,  black   },  /*  only used if colorfultitle is off   */
};
static const int tagschemes[] = {
  SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5, SchemeTag6
};

/* Tagging */
static const int ulineall               = 0;  /* 1 = underline all tags : 0 = only selected */
static const unsigned int ulinepad      = 16; /* underlines' horizontal padding from the edges */
static const unsigned int ulinestroke   = 1;  /* height of the tags' underline */
static const unsigned int ulinevoffset  = 1;  /* distance between the bottom and the underline */
static const char *tags[] = { "󰆍", "󰊯", "󰓓", "󰊖", "󰙯", "󰒓", };  /* Tags declaration <- this also
                                                                 defines the total amount of tags
                                                                 there are so be careful. */
static const Rule rules[] = {   /*  <-  This are the Tag Rules
    Run command xprop(1): {
      WM_CLASS  =   Instance, Class
      WM_NAME   =   Title
    }
    Use (Class, Instance, Title) to help dwm identify a specific client = (X program's window).
    Use (Mask) to spawn programs on a specific Tag (Left_num = On/Off)<<(Right_num = Tag(0 to 5)).
    Use (Float) to spawn programs on Floating window mode by default (1=On/0=Off).
    Use (Monitor) to spawn programs on a specific(fixed) Monitor, -1 = Selected Monitor.

      Class                 Instance              Title               Mask    Float   Monitor */
    { NULL,                 NULL,                 "Alacritty",        0<<0,   0,      -1      },
    { NULL,                 NULL,                 "bash",             0<<0,   1,      -1      },
    { "Sxiv",               "sxiv",               NULL,               0<<0,   1,      -1      },
    { NULL,                 NULL,                 "nvim",             1<<0,   0,      -1      },
    { "librewolf",          "Navigator",          "LibreWolf",        1<<1,   0,      -1      },
    { "Chromium",           "chromium",           NULL,               1<<1,   0,      -1      },
    { "Zenity",             "zenity",             "Steam setup",      1<<2,   1,      -1      },
    { "Steam",              "Steam",              NULL,               1<<2,   1,      -1      },
    { "discord",            "discord",            NULL,               1<<4,   0,      -1      },
    { "qpwgraph",           "qpwgraph",           NULL,               1<<5,   0,      -1      },
    { NULL,                 NULL,                 "pulsemixer",       1<<5,   0,      -1      },
    { NULL,                 NULL,                 "htop",             1<<5,   0,      -1      },
    { NULL,                 NULL,                 "btop",             1<<5,   0,      -1      },
    { NULL,                 NULL,                 "bmon",             1<<5,   0,      -1      },
};

/*  Layout(s) and their Settings  */
static const float mfact        = 0.50; /*  factor of master area size [0.05..0.95]   */
static const int nmaster        = 1;    /*  number of clients in master area          */
static const int resizehints    = 0;    /*  1 = respect size hints in tiled resizals  */
static const int lockfullscreen = 0;    /*  1 = force focus on the fullscreen window  */
static const Layout layouts[] = {
  /*  Symbol    Function  */
  {   "󱇙",      tile      },  /*  the First Layout is the Default one */
/*{   "󱗼",      tile      },
  {   "󰙀",      tile      },*/
  {   "󰮐",      NULL      },  /*  Function == Null ? Floating Layout   */
  {   "󰄶",      monocle   },
  {   NULL,     NULL      },  /*  (Symbol && Function) == Null -> it's end of the array  */
};

/* Key Definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* Helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) {.v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Helper for launching gtk application */
#define GTKCMD(cmd) {.v = (const char*[]){ "/usr/bin/gtk-launch", cmd, NULL } }

/* Commands */
static char dmenumon[2] = "0" ; /* dmenu arg,   ↓ (monitor) */
static const char *dmenucmd[] = { "dmenu_run",  "-m", dmenumon,
  /*Fg              Bg    */
  "-nf",  red,    "-nb",  black,
  "-sf",  black,  "-sb",  red,
  /* The 3 args below this line require dmenu to be patched with xyz patch, this is to spawn */
  "-x", "600",  "-y", "300",  "-z", "720",  /* dmenu in the middle of a 1920x1080 screen */
  NULL
};

/* Programs you can spawn by wheel clicking on a tag's icon */
static const Arg tagexec[]  = {
  SHCMD("st -e bash"),
  SHCMD("chromium --incognito"),
  SHCMD("steam"),
  GTKCMD("lutris"),
  SHCMD("com.discordapp.Discord"),
  SHCMD("st -e btop")
};

#include "movestack.c"
#include "shiftview.c"
static Key keys[] = {
  /*  Mask                            Key         Function            Argument          */
  { MODKEY,                           XK_p,       spawn,              { .v = dmenucmd } },
  { MODKEY,                           XK_Return,  spawn,              SHCMD("alacritty") },
  { MODKEY|ShiftMask,                 XK_Return,  spawn,              SHCMD("st -e bash") },
  { MODKEY|ControlMask,               XK_Return,  zoom,               { 0 } },
  { MODKEY|ControlMask,               XK_f,       togglefullscreen,   { 0 } },
  { MODKEY,                           XK_f,       togglefloating,     { 0 } },
  { MODKEY,                           XK_b,       togglebar,          { 0 } },
  { MODKEY,                           XK_b,       spawn,              SHCMD("notify-bar") },
  { MODKEY,                           XK_q,       killclient,         { 0 } },
  /*              Use arrow Keys to move, manage and resize clients               */
  { MODKEY,                           XK_Up,      focusstack,         { .i = -1 } },
  { MODKEY,                           XK_Down,    focusstack,         { .i = +1 } },
  { MODKEY,                           XK_Left,    focusstack,         { .i = -1 } },
  { MODKEY,                           XK_Right,   focusstack,         { .i = +1 } },
  { MODKEY|ShiftMask,                 XK_Up,      incnmaster,         { .i = +1 } },
  { MODKEY|ShiftMask,                 XK_Down,    incnmaster,         { .i = -1 } },
  { MODKEY|ShiftMask,                 XK_Left,    setmfact,           { .f = -0.05 } },
  { MODKEY|ShiftMask,                 XK_Right,   setmfact,           { .f = +0.05 } },
  { MODKEY|ControlMask,               XK_Up,      movestack,          { .i = -1 } },
  { MODKEY|ControlMask,               XK_Down,    movestack,          { .i = +1 } },
  { MODKEY|ControlMask,               XK_Left,    movestack,          { .i = -1 } },
  { MODKEY|ControlMask,               XK_Right,   movestack,          { .i = +1 } },
  /*            Or Use wasd Keys to move, manage and resize clients               */
  { MODKEY,                           XK_w,       focusstack,         { .i = -1 } },
  { MODKEY,                           XK_s,       focusstack,         { .i = +1 } },
  { MODKEY,                           XK_a,       focusstack,         { .i = -1 } },
  { MODKEY,                           XK_d,       focusstack,         { .i = +1 } },
  { MODKEY|ShiftMask,                 XK_w,       incnmaster,         { .i = +1 } },
  { MODKEY|ShiftMask,                 XK_s,       incnmaster,         { .i = -1 } },
  { MODKEY|ShiftMask,                 XK_a,       setmfact,           { .f = -0.05 } },
  { MODKEY|ShiftMask,                 XK_d,       setmfact,           { .f = +0.05 } },
  { MODKEY|ControlMask,               XK_w,       movestack,          { .i = -1 } },
  { MODKEY|ControlMask,               XK_s,       movestack,          { .i = +1 } },
  { MODKEY|ControlMask,               XK_a,       movestack,          { .i = -1 } },
  { MODKEY|ControlMask,               XK_d,       movestack,          { .i = +1 } },
  /*                Tags, Gaps, Layouts and Monitor Settings                */
  { Mod1Mask,                         XK_Tab,     view,               { 0 } },
  { Mod1Mask|ShiftMask,               XK_Tab,     view,               { .ui = ~ 0 } },
  { MODKEY|ControlMask,               XK_Tab,     tag,                { .ui = ~ 0 } },
  { MODKEY|ShiftMask,                 XK_Tab,     shiftview,          { .i = -1 } },
  { MODKEY,                           XK_Tab,     shiftview,          { .i = +1 } },
  { MODKEY,                           XK_minus,   setgaps,            { .i = -10 } },
  { MODKEY,                           XK_plus,    setgaps,            { .i = +10 } },
  { MODKEY,                           XK_0,       setgaps,            { .i = GAP_TOGGLE } },
  { MODKEY|ShiftMask,                 XK_0,       setgaps,            { .i = GAP_RESET } },
  { MODKEY|ControlMask,               XK_space,   cyclelayout,        { .i = -1 } },
  { MODKEY,                           XK_space,   cyclelayout,        { .i = +1 } },
  { MODKEY,                           XK_F1,      setlayout,          { .v = &layouts[0] } },
  { MODKEY,                           XK_F2,      setlayout,          { .v = &layouts[1] } },
  { MODKEY,                           XK_F3,      setlayout,          { .v = &layouts[2] } },
  { MODKEY,                           XK_comma,   focusmon,           { .i = -1 } },
  { MODKEY,                           XK_period,  focusmon,           { .i = +1 } },
  { MODKEY|ShiftMask,                 XK_comma,   tagmon,             { .i = -1 } },
  { MODKEY|ShiftMask,                 XK_period,  tagmon,             { .i = +1 } },
  /*                                  Tag Spawns                                  */
  { ShiftMask,                        XK_F1,      spawn,              tagexec [0] },
  { ShiftMask,                        XK_F2,      spawn,              tagexec [1] },
  { ShiftMask,                        XK_F3,      spawn,              tagexec [2] },
  { ShiftMask,                        XK_F4,      spawn,              tagexec [3] },
  { ShiftMask,                        XK_F5,      spawn,              tagexec [4] },
  { ShiftMask,                        XK_F6,      spawn,              tagexec [5] },
  /*                                  Tag Keys                          */
  TAGKEYS(                            XK_1,                           0 )
  TAGKEYS(                            XK_2,                           1 )
  TAGKEYS(                            XK_3,                           2 )
  TAGKEYS(                            XK_4,                           3 )
  TAGKEYS(                            XK_5,                           4 )
  TAGKEYS(                            XK_6,                           5 )
  /*                                  Quiting                               */
  { MODKEY|ShiftMask,                 XK_r,       quit,               { 0 } },
  { MODKEY|ShiftMask,                 XK_r,       spawn,              SHCMD("a-start") },
  { MODKEY|ShiftMask,                 XK_q,       spawn,              SHCMD("kill $(pidof dwm)") },
  { MODKEY|ControlMask|ShiftMask,     XK_r,       spawn,              SHCMD("reboot") },
  { MODKEY|ControlMask|ShiftMask,     XK_q,       spawn,              SHCMD("poweroff") },
};

/* Mouse and Bar Buttons Definitions */
static Button buttons[] = {   /*  <-  This are the bar buttons and the mouse button functions.
    Click can be = ClkLtSymbol, ClkWinTitle, ClkStatusText, ClkClientWin, ClkTagBar, or ClkRootWin.
    Click           Mask              Button      Function            Argument  */
  { ClkLtSymbol,    0,                Button1,    cyclelayout,        { .i = +1 } },
  { ClkLtSymbol,    0,                Button3,    cyclelayout,        { .i = -1 } },
  { ClkWinTitle,    0,                Button2,    togglebar,          { 0 } },
  { ClkWinTitle,    0,                Button2,    spawn,              SHCMD("notify-bar") },
  { ClkWinTitle,    0,                Button3,    zoom,               { 0 } },
  { ClkStatusText,  0,                Button1,    sigdwmblocks,       { .i = 1 } },
  { ClkStatusText,  0,                Button2,    sigdwmblocks,       { .i = 2 } },
  { ClkStatusText,  0,                Button3,    sigdwmblocks,       { .i = 3 } },
  { ClkStatusText,  0,                Button4,    sigdwmblocks,       { .i = 4 } },
  { ClkStatusText,  0,                Button5,    sigdwmblocks,       { .i = 5 } },
  { ClkStatusText,  ShiftMask,        Button1,    sigdwmblocks,       { .i = 6 } },
  { ClkStatusText,  ShiftMask,        Button2,    sigdwmblocks,       { .i = 7 } },
  { ClkStatusText,  ShiftMask,        Button3,    sigdwmblocks,       { .i = 8 } },
  { ClkClientWin,   MODKEY,           Button1,    movemouse,          { 0 } },
  { ClkClientWin,   MODKEY,           Button2,    togglefloating,     { 0 } },
  { ClkClientWin,   MODKEY,           Button3,    resizemouse,        { 0 } },
  { ClkTagBar,      MODKEY,           Button1,    tag,                { 0 } },
  { ClkTagBar,      MODKEY,           Button3,    toggletag,          { 0 } },
  { ClkTagBar,      0,                Button1,    view,               { 0 } },
  { ClkTagBar,      0,                Button2,    spawntag,           { 0 } },
  { ClkTagBar,      0,                Button3,    toggleview,         { 0 } },
};
