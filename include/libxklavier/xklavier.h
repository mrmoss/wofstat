/**
 * @file xklavier.h
 */

#ifndef __XKLAVIER_H__
#define __XKLAVIER_H__

#include <stdarg.h>

#include <X11/Xlib.h>

#ifdef XKB_HEADERS_PRESENT
#include <X11/XKBlib.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

  typedef enum
  {
/**
 * Group was changed
 */
    GROUP_CHANGED,
/**
 * Indicators were changed
 */
    INDICATORS_CHANGED
  }
  XklStateChange;

/**
 * XKB state. Can be global or per-window
 */
  typedef struct
  {
/** selected group */
    int group;
/** set of active indicators */
    unsigned indicators;
  }
  XklState;

/**
 * @defgroup xklinitterm Library initialization and termination
 * @{
 */

/**
 * Initializes internal structures. Does not start actual listening though.
 * Some apps can use Xklavier for information retrieval but not for actual
 * processing.
 * @param dpy is an open display, will be tested for XKB extension
 * @return 0 if OK, otherwise last X error 
 * (special case: -1 if XKB extension is not present)
 */
  extern int XklInit( Display * dpy );

/**
 * Terminates everything...
 */
  extern int XklTerm( void );

/** @} */

/**
 * @defgroup xkbevents XKB event handling and management
 * @{
 */

/**
 * Starts listening for XKB-related events
 * @return 0
 */
  extern int XklStartListen( void );

/**
 * Stops listening for XKB-related events
 * @return 0
 */
  extern int XklStopListen( void );

/**
 * Temporary pauses listening for XKB-related events
 * @return 0
 */
  extern int XklPauseListen( void );

/**
 * Resumes listening for XKB-related events
 * @return 0
 */
  extern int XklResumeListen( void );

/**
 * Grabs some key
 * @param key is a keysym
 * @param modifiers is a bitmask of modifiers
 * @return True on success
 */
  extern Bool XklGrabKey( int key, unsigned modifiers );

/**
 * Ungrabs some key
 * @param key is a keysym
 * @param modifiers is a bitmask of modifiers
 * @return True on success
 */
  extern Bool XklUngrabKey( int key, unsigned modifiers );

/**
 * Processes X events. Should be included into the main event cycle of an
 * application. One of the most important functions. 
 * @param evt is delivered X event
 * @return 0 if the event it processed - 1 otherwise
 * @see XklStartListen
 */
  extern int XklFilterEvents( XEvent * evt );

/**
 * Allows to switch (once) to the secondary group
 */
  extern void XklAllowOneSwitchToSecondaryGroup( void );

/** @} */

/**
 * @defgroup currents Current state of the library
 * @{
 */

/**
 * @return currently focused window
 */
  extern Window XklGetCurrentWindow( void );

/**
 * @return current state of the keyboard (in XKB terms). 
 * Returned value is a statically allocated buffer, should not be freed.
 */
  extern XklState *XklGetCurrentState( void );

/** @} */

/**
 * @defgroup wininfo Per-window information
 * @{
 */

/**
 * @return the window title of some window or NULL. 
 * If not NULL, it should be freed with XFree
 */
  extern char *XklGetWindowTitle( Window w );

/** 
 * Finds the state for a given window (for its "App window").
 * @param win is a target window
 * @param state_return is a structure to store the state
 * @return True on success, otherwise False 
 * (the error message can be obtained using XklGetLastError).
 */
  extern Bool XklGetState( Window win, XklState * state_return );

/**
 * Drops the state of a given window (of its "App window").
 * @param win is a target window
 */
  extern void XklDelState( Window win );

/** 
 * Stores ths state for a given window
 * @param win is a target window
 * @param state is a new state of the window
 */
  extern void XklSaveState( Window win, XklState * state );

/**
 * Sets the "transparent" flag. It means focus switching onto 
 * this window will never change the state.
 * @param win is the window do set the flag for.
 * @param transparent - if true, the windows is transparent.
 * @see XklIsTranspatent
 */
  extern void XklSetTransparent( Window win, Bool transparent );

/**
 * Returns "transparent" flag. 
 * @param win is the window to get the transparent flag from.
 * @see XklSetTranspatent
 */
  extern Bool XklIsTransparent( Window win );

/**
 * Checks whether 2 windows have the same App Window
 * @param win1 is first window
 * @param win2 is second window
 * @return True is windows are in the same application
 */
  extern Bool XklIsSameApp( Window win1, Window win2 );

/** @} */

/**
 * @defgroup xkbinfo Various XKB configuration info
 * @{
 */

/**
 * @return the total number of groups in the current XKB configuration 
 * (keyboard)
 */
  extern unsigned XklGetNumGroups( void );

/**
 * @return the array of group names for the current XKB configuration 
 * (keyboard).
 * This array is static, should not be freed
 */
  extern const char **XklGetGroupNames( void );

/**
 * @return the array of indicator names for the current XKB configuration 
 * (keyboard).
 * This array is static, should not be freed
 */
  extern const char **XklGetIndicatorNames( void );

/** @} */

/**
 * @defgroup xkbgroup XKB group calculation and change
 * @{
 */

/**
 * Calculates next group id. Does not change the state of anything.
 * @return next group id
 */
  extern int XklGetNextGroup( void );

/**
 * Calculates prev group id. Does not change the state of anything.
 * @return prev group id
 */
  extern int XklGetPrevGroup( void );

/**
 * @return saved group id of the current client. 
 * Does not change the state of anything.
 */
  extern int XklGetRestoreGroup( void );

/**
 * Locks the group. Can be used after XklGetXXXGroup functions
 * @param group is a group number for locking
 * @see XklGetNextGroup
 * @see XklGetPrevGroup
 * @see XklGetRestoreGroup
 */
  extern void XklLockGroup( int group );

/** @} */

/**
 * @defgroup callbacks Application callbacks support
 * @{
 */

/**
 * Used for notifying application of the XKB configuration change.
 * @param userData is anything which can be stored into the pointer
 * @see XklRegisterConfigCallback
 */
  typedef void ( *XklConfigCallback ) ( void *userData );

/**
 * Registers user callback. Only one callback can be registered at a time
 * @param fun is the function to call
 * @param userData is the data to pass
 * @see XklConfigCallback
 */
  extern int XklRegisterConfigCallback( XklConfigCallback fun,
                                        void *userData );

/**
 * Used for notifying application of new window creation (actually, 
 * registration).
 * @param win is a new window
 * @param parent is a new window's parent
 * @param userData is anything which can be stored into the pointer
 * @return the initial group id for the window (-1 to use the default value)
 * @see XklRegisterConfigCallback
 * @see XklSetDefaultGroup
 * @see XklGetDefaultGroup
 */
  typedef int ( *XklWinCallback ) ( Window win, Window parent,
                                    void *userData );

/**
 * Registers user callback. Only one callback can be registered at a time
 * @param fun is the function to call
 * @param userData is the data to pass
 * @see XklWindowCallback
 */
  extern int XklRegisterWindowCallback( XklWinCallback fun, void *userData );

/**
 * Used for notifying application of the window state change.
 * @param changeType is a mask of changes
 * @param group is a new group
 * @param restore is indicator of whether this state is restored from
 * saved state of set as new.
 * @param userData is anything which can be stored into the pointer
 * @see XklRegisterConfigCallback
 */
  typedef void ( *XklStateCallback ) ( XklStateChange changeType, int group,
                                       Bool restore, void *userData );

/**
 * Registers user callback. Only one callback can be registered at a time
 * @param fun is the function to call
 * @param userData is the data to pass
 * @see XklStateCallback
 */
  extern int XklRegisterStateCallback( XklStateCallback fun, void *userData );

/** @} */

/**
 * @defgroup settings Settings for event processing
 * @{
 */

/**
 * Sets the configuration parameter: group per application
 * @param isGlobal is a new parameter value
 */
  extern void XklSetGroupPerApp( Bool isGlobal );

/**
 *  @return the value of the parameter: group per application
 */
  extern Bool XklIsGroupPerApp( void );

/**
 * Sets the configuration parameter: perform indicators handling
 * @param whetherHandle is a new parameter value
 */
  extern void XklSetIndicatorsHandling( Bool whetherHandle );

/**
 * @return the value of the parameter: perform indicator handling
 */
  extern Bool XklGetIndicatorsHandling( void );

/**
 * Sets the secondary groups (one bit per group). 
 * Secondary groups require explicit "allowance" for switching
 * @param mask is a new group mask
 * @see XklAllowOneSwitchToSecondaryGroup
 */
  extern void XklSetSecondaryGroupsMask( int mask );

/**
 * @return the secondary group mask
 */
  extern int XklGetSecondaryGroupsMask( void );

/**
 * Configures the default group set on window creation.
 * If -1, no default group is used
 * @param group the default group
 */
  extern void XklSetDefaultGroup( int group );

/**
 * Returns the default group set on window creation
 * If -1, no default group is used
 * @return the default group
 */
  extern int XklGetDefaultGroup( void );

/** @} */

/**
 * @defgroup debugerr Debugging, error processing 
 * @{
 */

/**
 * @return the text message (statically allocated) of the last error
 */
  extern const char *XklGetLastError( void );

/**
 * Output (optionally) some debug info
 * @param file is the name of the source file. 
 * Preprocessor symbol__FILE__ should be used here
 * @param function is a name of the function
 * Preprocessor symbol__func__ should be used here
 * @param level is a level of the message
 * @param format is a format (like in printf)
 * @see XklDebug
 */
  extern void _XklDebug( const char file[], const char function[], int level,
                         const char format[], ... );

/**
 * Custom log output method for _XklDebug. This appender is NOT called if the
 * level of the message is greater than currently set debug level.
 *
 * @param file is the name of the source file. 
 * Preprocessor symbol__FILE__ should be used here
 * @param function is a name of the function
 * Preprocessor symbol__func__ should be used here
 * @param level is a level of the message
 * @param format is a format (like in printf)
 * @param args is the list of parameters
 * @see _XklDebug
 * @see XklSetDebugLevel
 */
  typedef void ( *XklLogAppender ) ( const char file[], const char function[],
                                     int level, const char format[],
                                     va_list args );

/**
 * Default log output method. Sends everything to stdout.
 *
 * @param file is the name of the source file. 
 * Preprocessor symbol__FILE__ should be used here
 * @param function is a name of the function
 * Preprocessor symbol__func__ should be used here
 * @param level is a level of the message
 * @param format is a format (like in printf)
 * @param args is the list of parameters
 */
  extern void XklDefaultLogAppender( const char file[], const char function[],
                                     int level, const char format[],
                                     va_list args );

/**
 * Installs the custom log appender.function
 * @param fun is the new log appender
 */
  extern void XklSetLogAppender( XklLogAppender fun );

/**
 * Sets maximum debug level. 
 * Message of the level more than the one set here - will be ignored
 * @param level is a new debug level
 */
  extern void XklSetDebugLevel( int level );

/**
 * Output (optionally) some debug info
 * @param level is a level of the message
 * @param format is a format (like in printf)
 * @see _XklDebug
 */
#ifdef G_HAVE_ISO_VARARGS
#define XklDebug( level, ... ) \
  _XklDebug( __FILE__, __func__, level, __VA_ARGS__ )
#elif defined(G_HAVE_GNUC_VARARGS)
#define XklDebug( level, format, args... ) \
   _XklDebug( __FILE__, __func__, level, format, ## args )
#else
#define XklDebug( level, ... ) \
  _XklDebug( __FILE__, __func__, level, __VA_ARGS__ )
#endif

/** @} */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */

#endif
