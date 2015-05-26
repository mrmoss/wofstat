/**
 * @file xklavier_config.h
 */

#ifndef __XKLABIER_CONFIG_H__
#define __XKLABIER_CONFIG_H__

#include <libxklavier/xklavier.h>

/**
 * Maximum name length, including '\'0' character
 */
#define XKL_MAX_CI_NAME_LENGTH 32

/**
 * Maximum short description length, including '\\0' character.
 * Important: this length is in bytes, so for unicode (UTF-8 encoding in 
 * XML file) the actual maximum length can be smaller.
 */
#define XKL_MAX_CI_SHORT_DESC_LENGTH 10

/**
 * Maximum description length, including '\\0' character.
 * Important: this length is in bytes, so for unicode (UTF-8 encoding in 
 * XML file) the actual maximum length can be smaller.
 */
#define XKL_MAX_CI_DESC_LENGTH 192

#ifdef __cplusplus
extern "C"
{
#endif                          /* __cplusplus */

/**
 * The configuration item. Corresponds to XML element "configItem".
 */
  typedef struct _XklConfigItem
  {
/**
 * The configuration item name. Corresponds to XML element "name".
 */
    char name[XKL_MAX_CI_NAME_LENGTH];

/**
 * The configuration item short description. Corresponds to XML element "shortDescription".
 */
    char shortDescription[XKL_MAX_CI_DESC_LENGTH];

/**
 * The configuration item description. Corresponds to XML element "description".
 */
    char description[XKL_MAX_CI_DESC_LENGTH];
  }
  XklConfigItem, *XklConfigItemPtr;

/**
 * Basic configuration params
 */
  typedef struct _XklConfigRec
  {
/**
 * The keyboard model
 */
    char *model;
/**
 *  The number of keyboard layouts
 */
    int numLayouts;
/**
 * The array of keyboard layouts
 */
    char **layouts;
/**
 * The number of keyboard layout variants
 */
    int numVariants;
/**
 * The array of keyboard layout variants (if any)
 */
    char **variants;
/**
 * The number of keyboard layout options
 */
    int numOptions;
/**
 * The array of keyboard layout options
 */
    char **options;
  }
  XklConfigRec, *XklConfigRecPtr;
/**
 * @defgroup xklconfiginitterm XKB configuration handling initialization and termination
 * @{
 */

/**
 * Initializes XML configuration-related structures
 */
  extern void XklConfigInit( void );

/**
 * Cleans XML configuration-related structures
 */
  extern void XklConfigTerm( void );

/**
 * Loads XML configuration registry
 * @param fileName file name to load
 * @return true on success
 */
  extern Bool XklConfigLoadRegistryFromFile( const char* fileName );

/**
 * Loads XML configuration registry
 * @return true on success
 */
  extern Bool XklConfigLoadRegistry( void );

/**
 * Frees XML configuration registry
 */
  extern void XklConfigFreeRegistry( void );
/** @} */

/**
 * @defgroup enum XKB configuration elements enumeration functions
 * @{
 */

/**
 * Callback type used for enumerating keyboard models, layouts, variants, options
 * @param configItem is the item from registry
 * @param userData is anything which can be stored into the pointer
 */
  typedef void ( *ConfigItemProcessFunc ) ( const XklConfigItemPtr configItem,
                                            void *userData );

/**
 * Callback type used for enumerating keyboard option groups
 * @param configItem is the item from registry
 * @param allowMultipleSelection is a flag whether this group allows multiple selection
 * @param userData is anything which can be stored into the pointer
 */
  typedef void ( *GroupProcessFunc ) ( const XklConfigItemPtr configItem,
                                       Bool allowMultipleSelection,
                                       void *userData );
/**
 * Enumerates keyboard models from the XML configuration registry
 * @param func is a callback to call for every model
 * @param userData is anything which can be stored into the pointer
 */
  extern void XklConfigEnumModels( ConfigItemProcessFunc func,
                                   void *userData );

/**
 * Enumerates keyboard layouts from the XML configuration registry
 * @param func is a callback to call for every layout
 * @param userData is anything which can be stored into the pointer
 */
  extern void XklConfigEnumLayouts( ConfigItemProcessFunc func,
                                    void *userData );

/**
 * Enumerates keyboard layout variants from the XML configuration registry
 * @param layoutName is the layout name for which variants will be listed
 * @param func is a callback to call for every layout variant
 * @param userData is anything which can be stored into the pointer
 */
  extern void XklConfigEnumLayoutVariants( const char *layoutName,
                                           ConfigItemProcessFunc func,
                                           void *userData );

/**
 * Enumerates keyboard option groups from the XML configuration registry
 * @param func is a callback to call for every option group
 * @param userData is anything which can be stored into the pointer
 */
  extern void XklConfigEnumOptionGroups( GroupProcessFunc func,
                                         void *userData );

/**
 * Enumerates keyboard options from the XML configuration registry
 * @param optionGroupName is the option group name for which variants 
 * will be listed
 * @param func is a callback to call for every option
 * @param userData is anything which can be stored into the pointer
 */
  extern void XklConfigEnumOptions( const char *optionGroupName,
                                    ConfigItemProcessFunc func,
                                    void *userData );

/** @} */

/**
 * @defgroup lookup XKB configuration element lookup functions
 * @{
 */

/**
 * Loads a keyboard model information from the XML configuration registry.
 * @param ptr is a pointer to a XklConfigItem containing the name of the
 * keyboard model. On successfull return, the descriptions are filled.
 * @return True if appropriate element was found and loaded
 */
  extern Bool XklConfigFindModel( XklConfigItemPtr ptr );

/**
 * Loads a keyboard layout information from the XML configuration registry.
 * @param ptr is a pointer to a XklConfigItem containing the name of the
 * keyboard layout. On successfull return, the descriptions are filled.
 * @return True if appropriate element was found and loaded
 */
  extern Bool XklConfigFindLayout( XklConfigItemPtr ptr );

/**
 * Loads a keyboard layout variant information from the XML configuration 
 * registry.
 * @param layoutName is a name of the parent layout
 * @param ptr is a pointer to a XklConfigItem containing the name of the
 * keyboard layout variant. On successfull return, the descriptions are filled.
 * @return True if appropriate element was found and loaded
 */
  extern Bool XklConfigFindVariant( const char *layoutName,
                                    XklConfigItemPtr ptr );

/**
 * Loads a keyboard option group information from the XML configuration 
 * registry.
 * @param ptr is a pointer to a XklConfigItem containing the name of the
 * keyboard option group. On successfull return, the descriptions are filled.
 * @param allowMultipleSelection is a pointer to some Bool variable to fill 
 * the corresponding attribute of XML element "group".
 * @return True if appropriate element was found and loaded
 */
  extern Bool XklConfigFindOptionGroup( XklConfigItemPtr ptr,
                                        Bool * allowMultipleSelection );

/**
 * Loads a keyboard option information from the XML configuration 
 * registry.
 * @param optionGroupName is a name of the option group
 * @param ptr is a pointer to a XklConfigItem containing the name of the
 * keyboard option. On successfull return, the descriptions are filled.
 * @return True if appropriate element was found and loaded
 */
  extern Bool XklConfigFindOption( const char *optionGroupName,
                                   XklConfigItemPtr ptr );
/** @} */

/**
 * @defgroup activation XKB configuration activation
 * @{
 */

/**
 * Determines whether multiple layouts (by Ivan Pascal) are supported.
 * @return True if so.
 */
  extern Bool XklMultipleLayoutsSupported( void );
/**
 * Activates some XKB configuration
 * @param data is a valid XKB configuration
 * description. Can be NULL
 * @param userData is a data to pass to the callback
 * @return True on success
 * @see XklSetKeyAsSwitcher
 * At the moment, accepts only _ONE_ layout. Later probably I'll improve this..
 */
  extern Bool XklConfigActivate( const XklConfigRecPtr data,
                                 void *userData );

/**
 * Loads the current XKB configuration (from X server)
 * @param data is a buffer for XKB configuration
 * @return True on success
 */
  extern Bool XklConfigGetFromServer( XklConfigRecPtr data );

/**
 * Loads the current XKB configuration (from backup)
 * @param data is a buffer for XKB configuration
 * @return True on success
 * @see XklBackupNamesProp
 */
  extern Bool XklConfigGetFromBackup( XklConfigRecPtr data );

/**
 * Writes some XKB configuration into XKM file
 * @param fileName is a name of the file to create
 * @param data is a valid XKB configuration
 * description. Can be NULL
 * @param userData is a data to pass to the callback
 * @return True on success
 * At the moment, accepts only _ONE_ layout. Later probably I'll improve this..
 */
  extern Bool XklConfigWriteXKMFile( const char *fileName,
                                     const XklConfigRecPtr data,
                                     void *userData );

/** @} */

/**
 * @defgroup props Saving and restoring XKB configuration into X root window properties
 * Generalizes XkbRF_GetNamesProp and XkbRF_SetNamesProp.
 * @{
 */

/**
 * Gets the XKB configuration from any root window property
 * @param rulesAtomName is an atom name of the root window property to read
 * @param rulesFileOut is a pointer to hold the file name
 * @param configOut is a buffer to hold the result - 
 *   all records are allocated using standard malloc 
 * @return True on success
 */
  extern Bool XklGetNamesProp( Atom rulesAtomName,
                               char **rulesFileOut,
                               XklConfigRecPtr configOut );

/**
 * Saves the XKB configuration into any root window property
 * @param rulesAtomName is an atom name of the root window property to write
 * @param rulesFile is a rules file name
 * @param config is a configuration to save 
 * @return True on success
 */
  extern Bool XklSetNamesProp( Atom rulesAtomName,
                               char *rulesFile, XklConfigRecPtr config );

/**
 * Backups current XKB configuration into some property - 
 * if this property is not defined yet.
 * @return True on success
 */
  extern Bool XklBackupNamesProp(  );

/**
 * Restores XKB from the property saved by XklBackupNamesProp
 * @return True on success
 * @see XklBackupNamesProp
 */
  extern Bool XklRestoreNamesProp(  );

/** @} */

/**
 * @defgroup xklconfig XklConfigRec management utilities
 * Little utilities for managing XklConfigRec.
 * @{
 */

/**
 * Initializes the record (actually, fills it with 0-s)
 * @param data is a record to initialize
 */
  extern void XklConfigRecInit( XklConfigRecPtr data );

/**
 * Resets the record (equal to Destroy and Init)
 * @param data is a record to reset
 */
  extern void XklConfigRecReset( XklConfigRecPtr data );

/**
 * Cleans the record (frees all the non-null members)
 * @param data is a record to clean
 */
  extern void XklConfigRecDestroy( XklConfigRecPtr data );

/**
 * Compares the records
 * @param data1 is a record to compare
 * @param data2 is another record
 * @return True if records are same
 */
  extern Bool XklConfigRecEquals( XklConfigRecPtr data1, XklConfigRecPtr data2 );

/** @} */

#ifdef __cplusplus
}
#endif                          /* __cplusplus */

#endif
