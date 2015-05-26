/* $XConsortium: Shell.h,v 1.32 94/04/17 20:14:49 kaleb Exp $ */

/***********************************************************

Copyright (c) 1987, 1988, 1994  X Consortium

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
X CONSORTIUM BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of the X Consortium shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from the X Consortium.


Copyright 1987, 1988 by Digital Equipment Corporation, Maynard, Massachusetts.

                        All Rights Reserved

Permission to use, copy, modify, and distribute this software and its 
documentation for any purpose and without fee is hereby granted, 
provided that the above copyright notice appear in all copies and that
both that copyright notice and this permission notice appear in 
supporting documentation, and that the name of Digital not be
used in advertising or publicity pertaining to distribution of the
software without specific, written prior permission.  

DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
SOFTWARE.

******************************************************************/

#ifndef _XtShell_h
#define _XtShell_h

#include <X11/SM/SMlib.h>

/***********************************************************************
 *
 * Shell Widget
 *
 ***********************************************************************/
/*
 * Shell-specific resources names, classes, and a representation type.
 */

/* The string definitions are automatically generated. */
/* Do not edit. */

#ifdef XTSTRINGDEFINES
#define XtNiconName "iconName"
#define XtCIconName "IconName"
#define XtNiconPixmap "iconPixmap"
#define XtCIconPixmap "IconPixmap"
#define XtNiconWindow "iconWindow"
#define XtCIconWindow "IconWindow"
#define XtNiconMask "iconMask"
#define XtCIconMask "IconMask"
#define XtNwindowGroup "windowGroup"
#define XtCWindowGroup "WindowGroup"
#define XtNvisual "visual"
#define XtCVisual "Visual"
#define XtNtitleEncoding "titleEncoding"
#define XtCTitleEncoding "TitleEncoding"
#define XtNsaveUnder "saveUnder"
#define XtCSaveUnder "SaveUnder"
#define XtNtransient "transient"
#define XtCTransient "Transient"
#define XtNoverrideRedirect "overrideRedirect"
#define XtCOverrideRedirect "OverrideRedirect"
#define XtNtransientFor "transientFor"
#define XtCTransientFor "TransientFor"
#define XtNiconNameEncoding "iconNameEncoding"
#define XtCIconNameEncoding "IconNameEncoding"
#define XtNallowShellResize "allowShellResize"
#define XtCAllowShellResize "AllowShellResize"
#define XtNcreatePopupChildProc "createPopupChildProc"
#define XtCCreatePopupChildProc "CreatePopupChildProc"
#define XtNtitle "title"
#define XtCTitle "Title"
#define XtRAtom "Atom"
#define XtNargc "argc"
#define XtCArgc "Argc"
#define XtNargv "argv"
#define XtCArgv "Argv"
#define XtNiconX "iconX"
#define XtCIconX "IconX"
#define XtNiconY "iconY"
#define XtCIconY "IconY"
#define XtNinput "input"
#define XtCInput "Input"
#define XtNiconic "iconic"
#define XtCIconic "Iconic"
#define XtNinitialState "initialState"
#define XtCInitialState "InitialState"
#define XtNgeometry "geometry"
#define XtCGeometry "Geometry"
#define XtNbaseWidth "baseWidth"
#define XtCBaseWidth "BaseWidth"
#define XtNbaseHeight "baseHeight"
#define XtCBaseHeight "BaseHeight"
#define XtNwinGravity "winGravity"
#define XtCWinGravity "WinGravity"
#define XtNminWidth "minWidth"
#define XtCMinWidth "MinWidth"
#define XtNminHeight "minHeight"
#define XtCMinHeight "MinHeight"
#define XtNmaxWidth "maxWidth"
#define XtCMaxWidth "MaxWidth"
#define XtNmaxHeight "maxHeight"
#define XtCMaxHeight "MaxHeight"
#define XtNwidthInc "widthInc"
#define XtCWidthInc "WidthInc"
#define XtNheightInc "heightInc"
#define XtCHeightInc "HeightInc"
#define XtNminAspectY "minAspectY"
#define XtCMinAspectY "MinAspectY"
#define XtNmaxAspectY "maxAspectY"
#define XtCMaxAspectY "MaxAspectY"
#define XtNminAspectX "minAspectX"
#define XtCMinAspectX "MinAspectX"
#define XtNmaxAspectX "maxAspectX"
#define XtCMaxAspectX "MaxAspectX"
#define XtNwmTimeout "wmTimeout"
#define XtCWmTimeout "WmTimeout"
#define XtNwaitForWm "waitforwm"
#define XtCWaitForWm "Waitforwm"
#define XtNwaitforwm "waitforwm"
#define XtCWaitforwm "Waitforwm"
#define XtNclientLeader "clientLeader"
#define XtCClientLeader "ClientLeader"
#define XtNwindowRole "windowRole"
#define XtCWindowRole "WindowRole"
#define XtNurgency "urgency"
#define XtCUrgency "Urgency"
#define XtNcancelCallback "cancelCallback"
#define XtNcloneCommand "cloneCommand"
#define XtCCloneCommand "CloneCommand"
#define XtNconnection "connection"
#define XtCConnection "Connection"
#define XtNcurrentDirectory "currentDirectory"
#define XtCCurrentDirectory "CurrentDirectory"
#define XtNdieCallback "dieCallback"
#define XtNdiscardCommand "discardCommand"
#define XtCDiscardCommand "DiscardCommand"
#define XtNenvironment "environment"
#define XtCEnvironment "Environment"
#define XtNinteractCallback "interactCallback"
#define XtNjoinSession "joinSession"
#define XtCJoinSession "JoinSession"
#define XtNprogramPath "programPath"
#define XtCProgramPath "ProgramPath"
#define XtNresignCommand "resignCommand"
#define XtCResignCommand "ResignCommand"
#define XtNrestartCommand "restartCommand"
#define XtCRestartCommand "RestartCommand"
#define XtNrestartStyle "restartStyle"
#define XtCRestartStyle "RestartStyle"
#define XtNsaveCallback "saveCallback"
#define XtNsaveCompleteCallback "saveCompleteCallback"
#define XtNsessionID "sessionID"
#define XtCSessionID "SessionID"
#define XtNshutdownCommand "shutdownCommand"
#define XtCShutdownCommand "ShutdownCommand"
#define XtNerrorCallback "errorCallback"
#else
#if __STDC__
#define _XtConst_ const
#else
#define _XtConst_ /**/
#endif
extern _XtConst_ char XtShellStrings[];
extern _XtConst_ char XtR6ShellStrings[];
#ifndef XtNiconName
#define XtNiconName ((char*)&XtShellStrings[0])
#endif
#ifndef XtCIconName
#define XtCIconName ((char*)&XtShellStrings[9])
#endif
#ifndef XtNiconPixmap
#define XtNiconPixmap ((char*)&XtShellStrings[18])
#endif
#ifndef XtCIconPixmap
#define XtCIconPixmap ((char*)&XtShellStrings[29])
#endif
#ifndef XtNiconWindow
#define XtNiconWindow ((char*)&XtShellStrings[40])
#endif
#ifndef XtCIconWindow
#define XtCIconWindow ((char*)&XtShellStrings[51])
#endif
#ifndef XtNiconMask
#define XtNiconMask ((char*)&XtShellStrings[62])
#endif
#ifndef XtCIconMask
#define XtCIconMask ((char*)&XtShellStrings[71])
#endif
#ifndef XtNwindowGroup
#define XtNwindowGroup ((char*)&XtShellStrings[80])
#endif
#ifndef XtCWindowGroup
#define XtCWindowGroup ((char*)&XtShellStrings[92])
#endif
#ifndef XtNvisual
#define XtNvisual ((char*)&XtShellStrings[104])
#endif
#ifndef XtCVisual
#define XtCVisual ((char*)&XtShellStrings[111])
#endif
#ifndef XtNtitleEncoding
#define XtNtitleEncoding ((char*)&XtShellStrings[118])
#endif
#ifndef XtCTitleEncoding
#define XtCTitleEncoding ((char*)&XtShellStrings[132])
#endif
#ifndef XtNsaveUnder
#define XtNsaveUnder ((char*)&XtShellStrings[146])
#endif
#ifndef XtCSaveUnder
#define XtCSaveUnder ((char*)&XtShellStrings[156])
#endif
#ifndef XtNtransient
#define XtNtransient ((char*)&XtShellStrings[166])
#endif
#ifndef XtCTransient
#define XtCTransient ((char*)&XtShellStrings[176])
#endif
#ifndef XtNoverrideRedirect
#define XtNoverrideRedirect ((char*)&XtShellStrings[186])
#endif
#ifndef XtCOverrideRedirect
#define XtCOverrideRedirect ((char*)&XtShellStrings[203])
#endif
#ifndef XtNtransientFor
#define XtNtransientFor ((char*)&XtShellStrings[220])
#endif
#ifndef XtCTransientFor
#define XtCTransientFor ((char*)&XtShellStrings[233])
#endif
#ifndef XtNiconNameEncoding
#define XtNiconNameEncoding ((char*)&XtShellStrings[246])
#endif
#ifndef XtCIconNameEncoding
#define XtCIconNameEncoding ((char*)&XtShellStrings[263])
#endif
#ifndef XtNallowShellResize
#define XtNallowShellResize ((char*)&XtShellStrings[280])
#endif
#ifndef XtCAllowShellResize
#define XtCAllowShellResize ((char*)&XtShellStrings[297])
#endif
#ifndef XtNcreatePopupChildProc
#define XtNcreatePopupChildProc ((char*)&XtShellStrings[314])
#endif
#ifndef XtCCreatePopupChildProc
#define XtCCreatePopupChildProc ((char*)&XtShellStrings[335])
#endif
#ifndef XtNtitle
#define XtNtitle ((char*)&XtShellStrings[356])
#endif
#ifndef XtCTitle
#define XtCTitle ((char*)&XtShellStrings[362])
#endif
#ifndef XtRAtom
#define XtRAtom ((char*)&XtShellStrings[368])
#endif
#ifndef XtNargc
#define XtNargc ((char*)&XtShellStrings[373])
#endif
#ifndef XtCArgc
#define XtCArgc ((char*)&XtShellStrings[378])
#endif
#ifndef XtNargv
#define XtNargv ((char*)&XtShellStrings[383])
#endif
#ifndef XtCArgv
#define XtCArgv ((char*)&XtShellStrings[388])
#endif
#ifndef XtNiconX
#define XtNiconX ((char*)&XtShellStrings[393])
#endif
#ifndef XtCIconX
#define XtCIconX ((char*)&XtShellStrings[399])
#endif
#ifndef XtNiconY
#define XtNiconY ((char*)&XtShellStrings[405])
#endif
#ifndef XtCIconY
#define XtCIconY ((char*)&XtShellStrings[411])
#endif
#ifndef XtNinput
#define XtNinput ((char*)&XtShellStrings[417])
#endif
#ifndef XtCInput
#define XtCInput ((char*)&XtShellStrings[423])
#endif
#ifndef XtNiconic
#define XtNiconic ((char*)&XtShellStrings[429])
#endif
#ifndef XtCIconic
#define XtCIconic ((char*)&XtShellStrings[436])
#endif
#ifndef XtNinitialState
#define XtNinitialState ((char*)&XtShellStrings[443])
#endif
#ifndef XtCInitialState
#define XtCInitialState ((char*)&XtShellStrings[456])
#endif
#ifndef XtNgeometry
#define XtNgeometry ((char*)&XtShellStrings[469])
#endif
#ifndef XtCGeometry
#define XtCGeometry ((char*)&XtShellStrings[478])
#endif
#ifndef XtNbaseWidth
#define XtNbaseWidth ((char*)&XtShellStrings[487])
#endif
#ifndef XtCBaseWidth
#define XtCBaseWidth ((char*)&XtShellStrings[497])
#endif
#ifndef XtNbaseHeight
#define XtNbaseHeight ((char*)&XtShellStrings[507])
#endif
#ifndef XtCBaseHeight
#define XtCBaseHeight ((char*)&XtShellStrings[518])
#endif
#ifndef XtNwinGravity
#define XtNwinGravity ((char*)&XtShellStrings[529])
#endif
#ifndef XtCWinGravity
#define XtCWinGravity ((char*)&XtShellStrings[540])
#endif
#ifndef XtNminWidth
#define XtNminWidth ((char*)&XtShellStrings[551])
#endif
#ifndef XtCMinWidth
#define XtCMinWidth ((char*)&XtShellStrings[560])
#endif
#ifndef XtNminHeight
#define XtNminHeight ((char*)&XtShellStrings[569])
#endif
#ifndef XtCMinHeight
#define XtCMinHeight ((char*)&XtShellStrings[579])
#endif
#ifndef XtNmaxWidth
#define XtNmaxWidth ((char*)&XtShellStrings[589])
#endif
#ifndef XtCMaxWidth
#define XtCMaxWidth ((char*)&XtShellStrings[598])
#endif
#ifndef XtNmaxHeight
#define XtNmaxHeight ((char*)&XtShellStrings[607])
#endif
#ifndef XtCMaxHeight
#define XtCMaxHeight ((char*)&XtShellStrings[617])
#endif
#ifndef XtNwidthInc
#define XtNwidthInc ((char*)&XtShellStrings[627])
#endif
#ifndef XtCWidthInc
#define XtCWidthInc ((char*)&XtShellStrings[636])
#endif
#ifndef XtNheightInc
#define XtNheightInc ((char*)&XtShellStrings[645])
#endif
#ifndef XtCHeightInc
#define XtCHeightInc ((char*)&XtShellStrings[655])
#endif
#ifndef XtNminAspectY
#define XtNminAspectY ((char*)&XtShellStrings[665])
#endif
#ifndef XtCMinAspectY
#define XtCMinAspectY ((char*)&XtShellStrings[676])
#endif
#ifndef XtNmaxAspectY
#define XtNmaxAspectY ((char*)&XtShellStrings[687])
#endif
#ifndef XtCMaxAspectY
#define XtCMaxAspectY ((char*)&XtShellStrings[698])
#endif
#ifndef XtNminAspectX
#define XtNminAspectX ((char*)&XtShellStrings[709])
#endif
#ifndef XtCMinAspectX
#define XtCMinAspectX ((char*)&XtShellStrings[720])
#endif
#ifndef XtNmaxAspectX
#define XtNmaxAspectX ((char*)&XtShellStrings[731])
#endif
#ifndef XtCMaxAspectX
#define XtCMaxAspectX ((char*)&XtShellStrings[742])
#endif
#ifndef XtNwmTimeout
#define XtNwmTimeout ((char*)&XtShellStrings[753])
#endif
#ifndef XtCWmTimeout
#define XtCWmTimeout ((char*)&XtShellStrings[763])
#endif
#ifndef XtNwaitForWm
#define XtNwaitForWm ((char*)&XtShellStrings[773])
#endif
#ifndef XtCWaitForWm
#define XtCWaitForWm ((char*)&XtShellStrings[783])
#endif

#ifndef XtNwaitforwm
#define XtNwaitforwm ((char*)&XtR6ShellStrings[0])
#endif
#ifndef XtCWaitforwm
#define XtCWaitforwm ((char*)&XtR6ShellStrings[10])
#endif
#ifndef XtNclientLeader
#define XtNclientLeader ((char*)&XtR6ShellStrings[20])
#endif
#ifndef XtCClientLeader
#define XtCClientLeader ((char*)&XtR6ShellStrings[33])
#endif
#ifndef XtNwindowRole
#define XtNwindowRole ((char*)&XtR6ShellStrings[46])
#endif
#ifndef XtCWindowRole
#define XtCWindowRole ((char*)&XtR6ShellStrings[57])
#endif
#ifndef XtNurgency
#define XtNurgency ((char*)&XtR6ShellStrings[68])
#endif
#ifndef XtCUrgency
#define XtCUrgency ((char*)&XtR6ShellStrings[76])
#endif
#ifndef XtNcancelCallback
#define XtNcancelCallback ((char*)&XtR6ShellStrings[84])
#endif
#ifndef XtNcloneCommand
#define XtNcloneCommand ((char*)&XtR6ShellStrings[99])
#endif
#ifndef XtCCloneCommand
#define XtCCloneCommand ((char*)&XtR6ShellStrings[112])
#endif
#ifndef XtNconnection
#define XtNconnection ((char*)&XtR6ShellStrings[125])
#endif
#ifndef XtCConnection
#define XtCConnection ((char*)&XtR6ShellStrings[136])
#endif
#ifndef XtNcurrentDirectory
#define XtNcurrentDirectory ((char*)&XtR6ShellStrings[147])
#endif
#ifndef XtCCurrentDirectory
#define XtCCurrentDirectory ((char*)&XtR6ShellStrings[164])
#endif
#ifndef XtNdieCallback
#define XtNdieCallback ((char*)&XtR6ShellStrings[181])
#endif
#ifndef XtNdiscardCommand
#define XtNdiscardCommand ((char*)&XtR6ShellStrings[193])
#endif
#ifndef XtCDiscardCommand
#define XtCDiscardCommand ((char*)&XtR6ShellStrings[208])
#endif
#ifndef XtNenvironment
#define XtNenvironment ((char*)&XtR6ShellStrings[223])
#endif
#ifndef XtCEnvironment
#define XtCEnvironment ((char*)&XtR6ShellStrings[235])
#endif
#ifndef XtNinteractCallback
#define XtNinteractCallback ((char*)&XtR6ShellStrings[247])
#endif
#ifndef XtNjoinSession
#define XtNjoinSession ((char*)&XtR6ShellStrings[264])
#endif
#ifndef XtCJoinSession
#define XtCJoinSession ((char*)&XtR6ShellStrings[276])
#endif
#ifndef XtNprogramPath
#define XtNprogramPath ((char*)&XtR6ShellStrings[288])
#endif
#ifndef XtCProgramPath
#define XtCProgramPath ((char*)&XtR6ShellStrings[300])
#endif
#ifndef XtNresignCommand
#define XtNresignCommand ((char*)&XtR6ShellStrings[312])
#endif
#ifndef XtCResignCommand
#define XtCResignCommand ((char*)&XtR6ShellStrings[326])
#endif
#ifndef XtNrestartCommand
#define XtNrestartCommand ((char*)&XtR6ShellStrings[340])
#endif
#ifndef XtCRestartCommand
#define XtCRestartCommand ((char*)&XtR6ShellStrings[355])
#endif
#ifndef XtNrestartStyle
#define XtNrestartStyle ((char*)&XtR6ShellStrings[370])
#endif
#ifndef XtCRestartStyle
#define XtCRestartStyle ((char*)&XtR6ShellStrings[383])
#endif
#ifndef XtNsaveCallback
#define XtNsaveCallback ((char*)&XtR6ShellStrings[396])
#endif
#ifndef XtNsaveCompleteCallback
#define XtNsaveCompleteCallback ((char*)&XtR6ShellStrings[409])
#endif
#ifndef XtNsessionID
#define XtNsessionID ((char*)&XtR6ShellStrings[430])
#endif
#ifndef XtCSessionID
#define XtCSessionID ((char*)&XtR6ShellStrings[440])
#endif
#ifndef XtNshutdownCommand
#define XtNshutdownCommand ((char*)&XtR6ShellStrings[450])
#endif
#ifndef XtCShutdownCommand
#define XtCShutdownCommand ((char*)&XtR6ShellStrings[466])
#endif
#ifndef XtNerrorCallback
#define XtNerrorCallback ((char*)&XtR6ShellStrings[482])
#endif
#undef _XtConst_
#endif

/* Class record constants */

typedef struct _ShellClassRec *ShellWidgetClass;
typedef struct _OverrideShellClassRec *OverrideShellWidgetClass;
typedef struct _WMShellClassRec *WMShellWidgetClass;
typedef struct _TransientShellClassRec *TransientShellWidgetClass;
typedef struct _TopLevelShellClassRec *TopLevelShellWidgetClass;
typedef struct _ApplicationShellClassRec *ApplicationShellWidgetClass;
typedef struct _SessionShellClassRec *SessionShellWidgetClass;

#ifndef SHELL 
externalref WidgetClass shellWidgetClass;
externalref WidgetClass overrideShellWidgetClass;
externalref WidgetClass wmShellWidgetClass;
externalref WidgetClass transientShellWidgetClass;
externalref WidgetClass topLevelShellWidgetClass;
externalref WidgetClass applicationShellWidgetClass;
externalref WidgetClass sessionShellWidgetClass;
#endif

#endif /* _XtShell_h */
/* DON'T ADD STUFF AFTER THIS #endif */
