/*
 * Copyright © 2001, 2002, Sun Microsystems, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of Sun Microsystems, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * This software is provided "AS IS," without a warranty of any kind.
 *
 * ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES,
 * INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED.
 * SUN AND ITS LICENSORS SHALL NOT BE LIABLE FOR ANY DAMAGES OR
 * LIABILITIES  SUFFERED BY LICENSEE AS A RESULT OF  OR RELATING TO USE,
 * MODIFICATION OR DISTRIBUTION OF THE SOFTWARE OR ITS DERIVATIVES.
 * IN NO EVENT WILL SUN OR ITS LICENSORS BE LIABLE FOR ANY LOST REVENUE,
 * PROFIT OR DATA, OR FOR DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL,
 * INCIDENTAL OR PUNITIVE DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE
 * THEORY OF LIABILITY, ARISING OUT OF THE USE OF OR INABILITY TO USE
 * SOFTWARE, EVEN IF SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 *
 */

/* @(#)XSTstr.h	1.83        04/07/27 SMI */

#include <X11/Xmd.h>

#ifndef CARD64
#define CARD64	double
#endif

#define	 X_STQueryVersion			0
#define	 X_STCapable				1
#define	 X_STEnable				2
#define	 X_STDisable				3
#define	 X_STInfo				4
#if 0
#define	 X_STWindowFast				125
#endif

#define	 X_STTypeEnvNewCopy			5
#define	 X_STTypeEnvDispose			6
#define	 X_STTypeEnvSetFontFallbackPolicy	7
#define  X_STTypeEnvGetFontFallbackPolicy	8
#define	 X_STTypeEnvSetFontFallbacks		9
#define	 X_STTypeEnvGetFontFallbacks		10
#define  X_STTypeEnvFindAllScalers		16
#define  X_STTypeEnvFindScaler			17
#define  X_STTypeEnvFindFontFamily		18
#define  X_STTypeEnvGetFontFolders		19
#define  X_STTypeEnvSetFontFolders		20
#define  X_STTypeEnvFindAllLayoutEngines	23
#define  X_STTypeEnvFindLayoutEngine		24

#define	 X_STTypeEnvFindFontsByName		11
#define	 X_STTypeEnvCreateFont			12
#define  X_STTypeEnvFindFontBySignature         13
#define	 X_STTypeEnvFindCreateFontFromURI	14
#define	 X_STTypeEnvDestroyFont			15
#define  X_STTypeEnvGetLocations		21
#define  X_STTypeEnvSetLocations		22
#define  X_STTypeEnvDownloadFont		129

#define  X_STScalerGetInfo			25
#define	 X_STScalerControl			26

#define  X_STLayoutEngineGetInfo		27
#define  X_STLayoutEngineControl                28

#define	 X_STFontGetInfo			31
#define  X_STFontGetFontFamily		        34
#define  X_STFontGetTypefaceName	        35
#define  X_STFontGetData	        	36

#define	 X_STFontGetNameTags			29
#define	 X_STFontGetNameString			30
#define	 X_STFontGetBaselines			32
#define	 X_STFontGetFeatures			33
#define  X_STFontGetSignature                   37

#define  X_STFontFamilyGetName		        38
#define  X_STFontFamilyGetFonts	        	39

#define	 X_STGCSetColors			40
#define	 X_STGCGetColors			41
#define	 X_STGCSetAlphaRange			42
#define  X_STGCGetAlphaRange			43
#define	 X_STGCSetOutputFormat			44
#define	 X_STGCGetOutputFormat			45
#define	 X_STGCGetMatrix			46
#define	 X_STGCSetMatrix			47
#define	 X_STGCConcatMatrix			48
#define	 X_STGCTranslate			49
#define	 X_STGCScale				50
#define	 X_STGCRotate				51
#define	 X_STGCShear				52
#define  X_STGCSetRegion                        53

#define	 X_STStyleNewCopy			54
#define	 X_STStyleDispose			55
#define	 X_STStyleCompare			56
#define	 X_STStyleIsEmpty			57
#define	 X_STStyleRemoveAttributes		58
#define	 X_STStyleSetFont			59
#define	 X_STStyleGetFont			60
#define  X_STStyleSetScaler			61
#define	 X_STStyleGetScaler			62
#define	 X_STStyleSetEffects			63
#define	 X_STStyleGetEffects			64
#define	 X_STStyleResetAttributes		65
#define	 X_STStyleCopyAttributes		66
#define	 X_STStyleOverwriteAttributes		67
#define	 X_STStyleUnderwriteAttributes		68
#define	 X_STStyleCalculateBaselines		69
#define	 X_STStyleGetDesignMetrics		70
#define  X_STStyleGetOptions                    71
#define  X_STStyleSetOptions                    72

#define  X_STStyleSetLayoutEngine		73
#define	 X_STStyleGetLayoutEngine		74

#define	 X_STTextNew				75
#define	 X_STTextNewCopy			76
#define	 X_STTextDispose			77
#define	 X_STTextClear				78
#define	 X_STTextSetMetrics			79
#define	 X_STTextGetMetrics			80
#define	 X_STTextSetControls			81
#define	 X_STTextGetControls			82
#define	 X_STTextSetFontFallbacks		83
#define	 X_STTextGetFontFallbacks		84
#define	 X_STTextCopyAttributes			85
#define	 X_STTextResetAttributes		86
#define	 X_STTextRemoveAttributes	        87
#define	 X_STTextSetText			88
#define	 X_STTextGetText			89
#define	 X_STTextUpdate				90
#define	 X_STTextSetStyle			91
#define	 X_STTextGetStyle			92
#define	 X_STTextGetCommonStyle			93
#define	 X_STTextFindMissingChars		94
#define	 X_STTextOverwriteStyle			95
#define	 X_STTextUnderwriteStyle		96
#define	 X_STTextAugmentStyle			97
#define  X_STTextGetStyledGlyphs                98

#define	 X_STLineNew				99
#define	 X_STLineNewForWidth			100
#define	 X_STLineDispose			101
#define	 X_STLineGrow				102
#define	 X_STLineShrink				103
#define	 X_STLineGetOffset			104
#define	 X_STLineSetMetrics			105
#define	 X_STLineGetMetrics			106
#define	 X_STLineMeasureText			107
#define	 X_STLineMeasureTextImage		108
#define	 X_STLineGetGlyphBounds			109
#define	 X_STLineHitTest			110
#define	 X_STLinePositionToCaret		111
#define	 X_STLineMoveCaret			112
#define	 X_STLineRender				113
#define	 X_STLineAddHighlight			114
#define	 X_STLineRemoveHighlight		115
#define	 X_STLineGetDesignMetrics		116
#define  X_STLineGetHighlights			117
#define  X_STLineGetStyledGlyphs                118

#define  X_STGlyphVectorNew			119
#define  X_STGlyphVectorNewCopy			120
#define  X_STGlyphVectorDispose			121
#define  X_STGlyphVectorSetGlyphs		122
#define  X_STGlyphVectorGetGlyphs		123
#define  X_STGlyphVectorReplaceGlyphs		124
#define  X_STGlyphVectorAdjustPositions		125
#define  X_STGlyphVectorMeasure			126
#define  X_STGlyphVectorGetBounds		127
#define  X_STGlyphVectorRender			128

#define  X_STSetSysCtlFlag			130

#define STNumberRequests                       131


#define STMajorVersion	1
#define STMinorVersion	4

/*#define STExtensionName	"STExtension" */
#define STExtensionName	"ST"

/** @defgroup General Basic functions
 * @{
 */

/**
 * ST Query Version request
 *
 * The X_STQueryVersion request returns version information about the XST extension.
 * 
 * The protocol version numbers returned indicate the version of the XST extension of the
 * target X server. The version numbers can be compared to constants defined in the XST.h
 * header file. Each version is a superset of the previous versions.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STQueryVersion                 */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD16	majorVersion B16;   /**< Major Version number: check for this num       */
    CARD16	minorVersion B16;   /**< Minor Version number: check for this num       */
} xSTQueryVersionReq;
#define sz_xSTQueryVersionReq 8

/**
 * ST Query Version reply
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD16	majorVersion B16;   /**< Major Version of software                      */
    CARD16	minorVersion B16;   /**< Minor Version of software                      */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTQueryVersionReply;
#define sz_xSTQueryVersionReply 32

/**
 * ST Capable request
 *
 * The X_STCapable request returns a Boolean flag which indicates whether the target 
 * XServer is capable of performing XST functions.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STCapable                      */
    CARD16	length B16;         /**< Request Length in Bytes                        */
} xSTCapableReq;
#define sz_xSTCapableReq 4

/**
 * ST Capable reply
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    BOOL	capable;            /**< Flag for ST Capable                            */
    CARD8	pad1;               /**< Not used                                       */
    CARD16	pad2 B16;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
    CARD32	pad6 B32;           /**< Not used                                       */
    CARD32	pad7 B32;           /**< Not used                                       */
} xSTCapableReply;
#define sz_xSTCapableReply 32

/**
 * ST Enabled request
 *
 * The X_STEnable request is used to turn XST capabilities in the server ON.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STEnable                       */
    CARD16	length B16;         /**< Request Length in Bytes                        */
} xSTEnableReq;
#define sz_xSTEnableReq 4

/**
 * ST Disabled request
 *
 * The X_STDisable request is used to turn XST capabilities in the server OFF.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STDisable                      */
    CARD16	length B16;         /**< Request Length in Bytes                        */
} xSTDisableReq;
#define sz_xSTDisableReq 4

/**
 * ST Info request
 *
 * The X_STInfo request is used to get information on the state of ST within the XServer.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STInfo                         */
    CARD16	length B16;         /**< Request Length in Bytes                        */
} xSTInfoReq;
#define sz_xSTInfoReq 4

/**
 * ST Info reply
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    BOOL        state;              /**< ST enabled or disabled                         */
    CARD8	pad1;               /**< Not used                                       */
    CARD16	pad2 B16;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
    CARD32	pad6 B32;           /**< Not used                                       */
    CARD32	pad7 B32;           /**< Not used                                       */
} xSTInfoReply;
#define sz_xSTInfoReply 32

#if 0
/**
 * ST Window Fast request
 *
 * The X_STWindowFast request is used to determine if the XServer has direct access to the
 * data within the drawable. Some drawables may be stored on video card memory and may not
 * be accessable without a copy first. If a copy is required, then a False is returned.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue  may be returned if the Drawable to use is not valid.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STWindowFast                   */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	drawable B32;       /**< Drawable XID to check                          */
} xSTWindowFastReq;
#define sz_xSTWindowFastReq 8

/**
 * ST Window Fast reply
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    BOOL        fast;		    /**< Drawable fast or not                           */
    CARD8	pad1;               /**< Not used                                       */
    CARD16	pad2 B16;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
    CARD32	pad6 B32;           /**< Not used                                       */
    CARD32	pad7 B32;           /**< Not used                                       */
} xSTWindowFastReply;
#define sz_xSTWindowFastReply 32
#endif

/**
 * @}
 */

/** @defgroup XSTTypeEnv_Protocol XSTTypeEnv Protocol messages
 * @{
 */

/**
 * ST TypeEnv New/New Copy request
 *
 * The X_STTypeEnvNewCopy request is used to create a new STTypeEnv and associated 
 * XSTTypeEnv XID value. The protocol request and reply used are the same to perform both
 * an XSTTypeEnvNew and XSTTypeEnvNewCopy. The difference between the two functions is 
 * that the OldEnv field is set to 0 when creating a new XSTTypeEnv. 
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadAlloc may be returned if unable to allocate the resource.
 * BadValue may be returned if the XSTTypeEnv to copy is not valid.
 * BadImplementation may be returned if the STTypeEnv to copy is NULL. 
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvNewCopy               */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	OldEnv B32;         /**< Old XSTTypeEnv XID to copy. 0 if no copy       */
    CARD32	NewEnv B32;         /**< New XSTTypeEnv XID to create.                  */
} xSTTypeEnvNewCopyReq;
#define sz_xSTTypeEnvNewCopyReq 12

/**
 * ST TypeEnv Dispose request
 *
 * The X_STTypeEnvDispose request is used to remove and free the resources used by the 
 * STTypeEnv as well as remove the XID value from the XServer. The protocol Env represents
 * the XSTTypeEnv XID of the STTypeEnv structure to dispose. The XServer calls 
 * STTypeEnvDispose. There is no response to the XSTTypeEnvDispose command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to dispose is not valid.
 * BadImplementation may be returned if the STTypeEnv to dispose is NULL. 
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvDispose               */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to dispose                      */
} xSTTypeEnvDisposeReq;
#define sz_xSTTypeEnvDisposeReq 8

/**
 * ST TypeEnv Set Font Fallback Policy request
 *
 * The X_STTypeEnvSetFontFallbackPolicy request is used to set the fallback policy to be 
 * used for all  characters not present in their STStyle specified font within each STText
 * object associated with the STTypeEnv object the operation is performed upon. The 
 * protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv 
 * structure. Policy represents the font fallback policy to use. It is a  member of the 
 * XSTFontFallbackPolicy group. The XServer calls STTypeEnvSetFontFallbackPolicy to set 
 * the appropriate policy for the STTypeEnv. There is no response to this command.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to set is not valid.
 * BadImplementation may be returned if the STTypeEnv to set is NULL. 
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvSetFontFallbackPolicy */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to set                          */
    CARD32	Policy B32;         /**< Font Fallback policy to use                    */
} xSTTypeEnvSetFontFallbackPolicyReq;
#define sz_xSTTypeEnvSetFontFallbackPolicyReq 12

/**
 * ST TypeEnv Get Font Fallback Policy request
 *
 * The X_STTypeEnvGetFontFallbackPolicy request is used to request the fallback policy to
 * be used for all characters not present in their STStyle specified font. The protocol 
 * Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv structure. 
 * The XServer calls STTypeEnvGetFontFallbackPolicy to get the appropriate response to 
 * return to the X client. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvGetFontFallbackPolicy */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
} xSTTypeEnvGetFontFallbackPolicyReq;
#define sz_xSTTypeEnvGetFontFallbackPolicyReq 8

/**
 * ST TypeEnv Get Font Fallback Policy reply
 *
 * The protocol response Policy is set and returned to the Xclient application. The policy
 * value returned is a member of the XSTFontFallbackPolicy group.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Policy B32;         /**< Policy value. See XSTFontFallbackPolicy        */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvGetFontFallbackPolicyReply;
#define sz_xSTTypeEnvGetFontFallbackPolicyReply 32

/**
 * ST TypeEnv Set Font Fallbacks request
 *
 * The X_STTypeEnvSetFontFallbacks request is used to set the font fallback list to be 
 * used for all characters not present in their STStyle specified font within each STText
 * object associated with the STTypeEnv object the operation is performed upon. This may 
 * be overridden if the STText object has its own font fallback list. ( See 
 * XSTTextSetFontFallbacks for information on the local font fallbacks.)
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol count represents the number of XSTFont IDs appended onto the 
 * end of the protocol request. Each XSTFont ID is a CARD32. The XServer calls 
 * STTypeEnvSetFontFallbacks and sends the list of STFont IDs. There is no response given
 * to this command.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvSetFontFallbacks      */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to set                          */
    CARD32	count B32;          /**< Number of Fallback Fonts in list               */
} xSTTypeEnvSetFontFallbacksReq;
#define sz_xSTTypeEnvSetFontFallbacksReq 12

/**
 * ST TypeEnv Get Font Fallbacks request
 *
 * The X_STTypeEnvGetFontFallbacks request is used to get the font fallback list to be 
 * used for all characters not present in their STStyle specified font within each STText
 * object associated with the STTypeEnv object the operation is performed upon. This may 
 * be overridden if the STText object has its own font fallback list. (See 
 * XSTTextGetFontFallbacks for information on the local font fallbacks.)
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The XServer calls STTypeEnvGetFontFallbacks and receives a list of STFont 
 * IDs. Count represents the number of STFont IDs received by the XServer.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the fallbacks cannot be obtained.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvGetFontFallbacks      */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
} xSTTypeEnvGetFontFallbacksReq;
#define sz_xSTTypeEnvGetFontFallbacksReq 8

/**
 * ST TypeEnv Get Font Fallbacks reply
 * 
 * The response is returned along with a number, equal to count, of additional CARD32s. 
 * Each additional CARD32 contains an XSTFont ID.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of XSTFont IDs in list                  */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvGetFontFallbacksReply;
#define sz_xSTTypeEnvGetFontFallbacksReply 32

/**
 * ST TypeEnv Find All Scalers request
 *
 * The X_STTypeEnvFindAllScalers request is used to find all of the available STScaler 
 * IDs and return them to the X client application.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The XServer calls STTypeEnvFindAllScalers which returns a list of STScaler 
 * IDs. 
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the return scaler IDs cannot be allocated.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvFindAllScalers        */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
} xSTTypeEnvFindAllScalersReq;
#define sz_xSTTypeEnvFindAllScalersReq 8

/**
 * ST TypeEnv Find All Scalers reply
 *
 * The protocol response Count is set to the number of STScaler IDs returned by STSF. The
 * XSTScaler ID CARD32s are appended to the end of the response message and returned to 
 * the X client.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of XSTScaler IDs in list                */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvFindAllScalersReply;
#define sz_xSTTypeEnvFindAllScalersReply 32

/**
 * ST TypeEnv Find Scaler request
 *
 * The X_STTypeEnvFindScaler request attempts to find a particular scaler available to 
 * STSF by sending a scaler tag value. If the scaler is found by STSF, then the STScaler 
 * ID value will be returned.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol ScalerTag is used to help identify the specific scaler the X 
 * client application is interested in finding. The XServer calls STTypeEnvFindScaler and
 * passes the ScalerTag. The function returns the STScaler ID if it was found. 
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvFindScaler            */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	ScalerTag B32;      /**< Unique Scaler ID value                         */
} xSTTypeEnvFindScalerReq;
#define sz_xSTTypeEnvFindScalerReq 12

/**
 * ST TypeEnv Find Scaler reply
 *
 * The protocol response Scaler is set to the XSTScaler ID value.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Scaler B32;         /**< XSTScaler ID returned                          */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvFindScalerReply;
#define sz_xSTTypeEnvFindScalerReply 32

/**
 * ST TypeEnv Find All Layout Engines request
 *
 * The X_STTypeEnvFindAllLayoutEngines request attempts to get all of the Layout engines
 * available to STSF. XSTScaler IDs will be returned.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The XServer calls STTypeEnvFindAllLayoutEngines and passes the Env. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the return layout engine IDs cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvFindAllLayoutEngines  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
} xSTTypeEnvFindAllLayoutEnginesReq;
#define sz_xSTTypeEnvFindAllLayoutEnginesReq 8

/**
 * ST TypeEnv Find All Layout Engines reply
 *
 * The protocol response count is set to the number of STLayoutEngine IDs returned by 
 * STSF. The XSTLayoutEngine ID CARD32s are appended to the end of the response message 
 * and returned to the X client.
 */ 
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of Layout Engine IDs returned           */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvFindAllLayoutEnginesReply;
#define sz_xSTTypeEnvFindAllLayoutEnginesReply 32

/**
 * ST TypeEnv Find Layout Engine
 *
 * The X_STTypeEnvFindAllLayoutEngines request attempts to get a specific Layout engine
 * available to STSF. XSTScaler ID will be returned.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol LETag specifies the unique identifier for the Layout Engine. 
 * The XServer calls STTypeEnvFindLayoutEngine and passes the Env and the LETag.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvFindLayoutEngine      */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	LETag B32;          /**< Layout Engine Tag uniquely identifying engine  */
} xSTTypeEnvFindLayoutEngineReq;
#define sz_xSTTypeEnvFindLayoutEngineReq 12

/**
 * ST TypeEnv Find Layout Engine reply
 *
 * The protocol response LayoutEngine is set to the XSTLayoutEngine ID returned by 
 * STSF. 
 */ 
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      LayoutEngine B32;   /**< Layout Engine ID returned                      */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvFindLayoutEngineReply;
#define sz_xSTTypeEnvFindLayoutEngineReply 32

/**
 * ST TypeEnv Find Font Family(s) request
 *
 * The STTypeEnvFindFontFamily request attempts to find a particular font family, or all 
 * font families, available to STSF by sending a name string and a Language value. If the
 * Name is found by STSF, then the FontFamily ID value will be returned.
 *
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Max specifies whether this is searching for a single font 
 * family (1), or all font families (0). 
 *
 * The remaining protocol items vary depending on whether the call comes as a request for
 * one font matching the parameters, or all fonts. For finding a single font:
 * The protocol LanguageID is used to identify the language and region that the string is
 * to match. The protocol NameLength indicates the length of the string appended onto the
 * end of the request. The XServer calls STTypeEnvFindFontFamily and passes the 
 * STTypeEnv, the Language ID, the string and it's length. The function returns the 
 * FontFamily ID if it was found. 
 * For finding all fonts:
 * The protocol LanguageID is 0. It is not used. The protocol NameLength is 0. It is not 
 * used. The XServer calls STTypeEnvFindAllFontFamiles and passes the STTypeEnv. The 
 * function returns a list of all FontFamily IDs.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvFindFontFamily        */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	LanguageID B32;     /**< Language ID associated with single font to find*/
    CARD32	Max B32;            /**< Maximum number of fonts to return              */
    CARD32	NameLength B32;     /**< Number of bytes in font family name to find    */
} xSTTypeEnvFindFontFamilyReq;
#define sz_xSTTypeEnvFindFontFamilyReq 20

/**
 * ST TypeEnv Find Font Family(s) reply
 *
 * The protocol response count is set to one (1) if the FontFamily was found. The protocol
 * response LanguageID is set to the language and region that the name matches. The 
 * FontFamily ID is appended onto the end of the response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of FontFamily IDs returned              */
    CARD32      LanguageID B32;     /**< Language ID associated with single font family */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
} xSTTypeEnvFindFontFamilyReply;
#define sz_xSTTypeEnvFindFontFamilyReply 32

/**
 * ST TypeEnv Get Font Folders request
 *
 * The X_STTypeEnvGetFontFolders request returns a list of user specified directories that
 * are searched for additional fonts.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The XServer calls STTypeEnvGetFontFolders and passes the STTypeEnv. The 
 * function returns an array of directory strings along with the number of directories.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvGetFontFolders        */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
} xSTTypeEnvGetFontFoldersReq;
#define sz_xSTTypeEnvGetFontFoldersReq 8

/**
 * ST TypeEnv Get Font Folders reply
 *
 * The protocol response count is the number of returned directory strings. The directory
 * strings are appended onto the end of the response message.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of Font Folders returned                */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvGetFontFoldersReply;
#define sz_xSTTypeEnvGetFontFoldersReply 32

/**
 * ST TypeEnv Set Font Folders request
 *
 * The X_STTypeEnvSetFontFolders request sets the list of directories that are to be  
 * searched for extra fonts.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol FontFoldersCount indicates the number of directory strings 
 * appended onto the end of the request. The XServer calls STTypeEnvSetFontFolders and 
 * passes the STTypeEnv along with the array of directory strings and the number of  
 * strings. There is no response to this command.
 *
 * BadLength may be returned if the protocol message is not of the proper length. 
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvSetFontFolders        */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32      FontFoldersCount B32; /**< Number of Font Folder strings appended       */
} xSTTypeEnvSetFontFoldersReq;
#define sz_xSTTypeEnvSetFontFoldersReq 12


/**
 * @}
 */


/**
 * ST TypeEnv Find Fonts By Name request
 *
 * The X_STTypeEnvFindFontsByName request is used for all four of the find font commands.
 * The protocol values are changed for each of the commands to indicate to the XServer 
 * which STSF command is to be called. For the XSTTypeEnvFindFontByName command, STSF is 
 * instructed to find a particular font matching the name appended to the end of the 
 * protocol request. For the XSTTypeEnvFindAllFonts command, STSF is instructed to find
 * all available fonts. For the XSTTypeEnvFindFontByPlatformName, STSF is instructed to 
 * find a particular font matching the tag value information. For the 
 * XSTTypeEnvFindFontsByPlatformName, STSF is instructed to return all fonts matching the
 * platform information.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol NameLength is set to the number of bytes used to specify the 
 * name of the font to find. This is the number of bytes appended onto the end of the 
 * protocol message in UTF-16 format. 
 * For the XSTTypeEnvFindFontByName command, the following protocol values are used:
 * 	NameID     is 0. It is not used.
 *      PlatformID is 0. It is not used. 
 *      EncodingID is 0. It is not used. 
 *      LanguageID is 0. It is not used.
 *      Max        is 1. We only want one XSTFont ID in the response.
 *   The XServer calls STTypeEnvFindFont and receives an STFont ID.
 * For the XSTTypeEnvFindAllFontByName command, the following protocol values are used:
 * 	NameID     is 0. It is not used.
 *      PlatformID is 0. It is not used. 
 *      EncodingID is 0. It is not used. 
 *      LanguageID is 0. It is not used.
 *      Max        is 0. We want all XSTFont IDs in the response.
 *   The XServer calls STTypeEnvFindAllFonts and receives an STFont ID.
 * For the XSTTypeEnvFindFontByPlatformName command, the following protocol values are 
 * used:
 * 	NameID     is the field number to compare to the name string.
 *      PlatformID is the type of platform the font is designed for.
 *      EncodingID is the encoding type of the field.
 *      LanguageID is the language type of the field.
 *      Max        is 1. We only want one XSTFont ID in the response.
 *   The XServer calls STTypeEnvFindFontByPlatform and receives an STFont ID.
 * For the XSTTypeEnvFindAllFontsByPlatformName command, the following protocol values are
 * used:
 * 	NameID     is the field number to compare to the name string.
 *      PlatformID is the type of platform the font is designed for.
 *      EncodingID is the encoding type of the field.
 *      LanguageID is the language type of the field.
 *      Max        is 0. We want all XSTFont IDs in the response.
 *   The XServer calls STTypeEnvFindAllFontByPlatform and receives an STFont ID.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the return font IDs cannot be allocated.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvFindFontsByName       */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD16	NameID B16;         /**< ID Tag to search. IE: Font name, license, etc. */
    INT16	PlatformID B16;     /**< Platform. IE:                                  */
    INT16	EncodingID B16;     /**< Encoding. IE:                                  */
    INT16	LanguageID B16;     /**< Language. IE:                                  */
    CARD32	Max B32;            /**< Maximum number of Font IDs to return           */
    CARD32	NameLength B32;     /**< Number of bytes in string                      */
} xSTTypeEnvFindFontsByNameReq;
#define sz_xSTTypeEnvFindFontsByNameReq 24

/**
 * ST TypeEnv Find Fonts By Name reply
 *
 * The protocol response count is set to one if a font was found, or zero if no font 
 * matches. The XSTFont ID CARD32 is appended to the end of the response message and 
 * returned to the X client.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of XSTFont IDs in list                  */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvFindFontsByNameReply;
#define sz_xSTTypeEnvFindFontsByNameReply 32

typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvCreateFont            */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	DataLength B32;     /**< Length of data appended to request in bytes    */
    CARD32	TotalLength B32;
    CARD32	Offset B32;
} xSTTypeEnvDownloadFontReq;
#define sz_xSTTypeEnvDownloadFontReq 20

/**
 * ST TypeEnv Create Font request
 *
 * The X_STTypeEnvCreateFont request is used to create a local font for the X client 
 * application to use. This font is local to just the STTypeEnv and is not available to 
 * any other application connected to the STSF server. The font(s) to be created is a  
 * string of binary data that is sent to XST client library and forwarded through the 
 * protocol.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol DataLength represents the amount of binary data in bytes 
 * appended onto the protocol request. This binary data contains the font(s) to be  
 * created. The XServer calls STTypeEnvCreateFont to create the font(s) from the binary 
 * data. This function returns a list of one or more STFont IDs.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the return font IDs cannot be allocated.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvCreateFont            */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	DataLength B32;     /**< Length of data appended to request in bytes    */
} xSTTypeEnvCreateFontReq;
#define sz_xSTTypeEnvCreateFontReq 12

/**
 * ST TypeEnv Create Font reply
 *
 * The protocol response Count is set the the number of STFont IDs returned by STSF. The 
 * XSTFont ID CARD32s are appended to the end of the response message and returned to the 
 * X client.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of XSTFont IDs in list                  */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvCreateFontReply;
#define sz_xSTTypeEnvCreateFontReply 32

#if 0
typedef struct {				/* Use xSTTypeEnvCreateFontReq */
    CARD8	reqType;
    CARD8	stReqType;
    CARD16	length B16;
    CARD32	Env B32;
    CARD32	DataLength B32;
} xSTTypeEnvCreateFontFromStreamReq;
#define sz_xSTTypeEnvCreateFontFromStreamReq 12
#endif

/**
 * ST TypeEnv Find or Create Font From URI request
 *
 * The X_STTypeEnvCreateFontFromURI request is used to create a local font for the X 
 * client application to use. This font is local to just the STTypeEnv and is not 
 * available to any other application connected to the STSF server. The font(s) to be 
 * created is a stored 
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol DataLength represents the amount of binary data in bytes 
 * appended onto the protocol request. This binary data contains the font(s) to be  
 * created. The XServer calls STTypeEnvCreateFont to create the font(s) from the binary 
 * data. This function returns a list of one or more STFont IDs.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the return font IDs cannot be allocated.
 */
typedef struct {				/* Use xSTTypeEnvCreateFontReq */
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvFindCreateFontFromURI */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	URICount B32;       /**< Number of bytes in URI string                  */
    CARD32      find B32;           /**< Find the Font, or Create the font              */
} xSTTypeEnvFindCreateFontFromURIReq;
#define sz_xSTTypeEnvFindCreateFontFromURIReq 16

/**
 * ST TypeEnv Destroy Font request
 *
 * The X_STTypeEnvDestroyFont request is used to remove a created font from the STTypeEnv
 * structure. The font will be removed and their resources freed. Note that fonts not 
 * created with the STTypeEnvCreateFont command cannot be destroyed.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font represents the XSTFont ID. The XServer calls 
 * STTypeEnvDestroyFont and passes the STFont ID. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8	reqType;            /**< Request Type: always STRCode                   */
    CARD8	stReqType;          /**< ST Request:   X_STTypeEnvDestroyFont           */
    CARD16	length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< XSTFont ID to destroy                          */
} xSTTypeEnvDestroyFontReq;
#define sz_xSTTypeEnvDestroyFontReq 12

/**
 * ST TypeEnv Get Locations request
 *
 * The X_STTypeEnvGetLocations request returns a mask indicating which directory locations
 * are being used when searching for fonts.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The XServer calls STTypeEnvGetLocations and passes the STTypeEnv. The 
 * function returns a mask indicating which directory locations are being used. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvGetLocations          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
} xSTTypeEnvGetLocationsReq;
#define sz_xSTTypeEnvGetLocationsReq 8

/**
 * ST TypeEnv Get Locations reply
 * 
 * The protocol response mask is set to the returned mask.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      mask B32;           /**< Mask of font locations used by STSF server     */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTypeEnvGetLocationsReply;
#define sz_xSTTypeEnvGetLocationsReply 32

/**
 * ST TypeEnv Set Locations request
 *
 * The STTypeEnvSetLocations request allows the user to specify which directory locations
 * are to be used when searching for fonts.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol mask indicates which directory locations to use for getting 
 * fonts. The XServer calls STTypeEnvSetLocations and passes the STTypeEnv along with the
 * mask. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvSetLocations          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32      Locations B32;      /**< Location mask to tell STSF where to find fonts */
} xSTTypeEnvSetLocationsReq;
#define sz_xSTTypeEnvSetLocationsReq 12

/**
 * ST TypeEnv Find Font By Signature request
 * 
 * The STTypeEnvFindFontBySignature request allows the user to specify a md5 encrypted
 * signature and receive the font id associated with it.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTypeEnvSetLocations          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32      count B32;          /**< number of bytes in the signature               */
} xSTTypeEnvFindFontBySignatureReq;
#define sz_xSTTypeEnvFindFontBySignatureReq 8

/**
 * ST TypeEnv Find Font By Signature reply
 *
 * The protocol response Font is set to the returned Font ID.
 */
typedef struct {
    BYTE        type;               /**< Reply Type: always X_Reply                     */
    CARD8       pad0;               /**< Not used                                       */
    CARD16      sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32      length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Font B32;           /**< Font ID associated with the signature          */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
    CARD32      pad5 B32;           /**< Not used                                       */
} xSTTypeEnvFindFontBySignatureReply;
#define sz_xSTTypeEnvFindFontBySignatureReply 32


 





/** @defgroup XSTScaler_Protocol XSTScaler Protocol messages
 * @{
 */


/**
 * ST Scaler Control request
 *
 * The X_STScalerControl request is used to send the scaler associated with a TypeEnv
 * object a string of data and get a response.
 * The protocol Env is the XID value referring to the STTypeEnv object to use. The 
 * protocol Scaler is the XID value referring to the STScaler type to use. The
 * protocol count indicates the number of bytes appended onto the end of the request to
 * send to the scaler. The XServer calls STScalerControl and passes the STStyle
 * object along with the data and its length. The function returns a string of data and
 * its length.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response could not be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STScalerControl                */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Scaler B32;         /**< XSTScaler XID to use                           */
    CARD32	count B32;          /**< Number of bytes of data to send to the scaler  */
} xSTScalerControlReq;
#define sz_xSTScalerControlReq 16

/**
 * ST Scaler Control reply
 *
 * The protocol response count is the number of bytes returned. The data is appended onto
 * the end of the response message.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of bytes of data returned from scaler   */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTScalerControlReply;
#define sz_xSTScalerControlReply 32

/**
 * ST Scaler Get Info request
 *
 * The X_STScalerGetInfo request is used to get detailed information about a specific 
 * scaler.
 * The protocol Env is an XSTTypeEnv XID value referring to the STTypeEnv structure. The 
 * protocol Scaler is an XSTScaler representing the STScaler value. The XServer calls 
 * STScalerGetInfo and passes the STTypeEnv object and the STScaler value. The function 
 * returns the name strings, version numbers and capability flags.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STScalerGetInfo                */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Scaler B32;         /**< XSTScaler ID to use to get info                */
    CARD32      mask B32;           /**< Indicates the fields to return                 */
} xSTScalerGetInfoReq;
#define sz_xSTScalerGetInfoReq 16

/**
 * ST Scaler Get Info reply
 *
 * The protocol response Tag represents the ???. The protocol response Version indicates 
 * the version number of the scaler. The top 16 bits are the major number, while the  
 * bottom 16 bits are the minor number. The protocol response SFlags  is a mask 
 * representing the abilities of the scaler to perform hinting, embedded bitmaps, etc. The
 * protocol response FFlags is a mask representing the font formats that the scaler can 
 * use. The protocol response ShortNameLen indicates the length of the standard name of 
 * the scaler. The protocol response LongNameLen indicates the length of the full name of
 * the scaler. The protocol response NoticeLen indicates the length of the notice string.
 * Each of the strings is appended onto the end of the response message. The ShortName is
 * first, followed by the LongName, followed by the Notice. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Tag B32;            /**< ???                                            */
    CARD32      Version B32;        /**< Major Number/Minor Number of version           */
    CARD32      SFlags B32;         /**< Mask of scaler abilities. IE: hinting          */
    CARD32      FFlags B32;         /**< Mask of font types supported by scaler         */
    CARD32      ShortNameLen B32;   /**< Number of bytes in Short Name                  */
    CARD32      LongNameLen B32;    /**< Number of bytes in Long Name                   */
    CARD32      NoticeLen B32;      /**< Number of bytes in Notice                      */
} xSTScalerGetInfoReply;
#define sz_xSTScalerGetInfoReply 36


/**
 * @}
 */





/** @defgroup XSTLayoutEngine_Protocol XSTLayoutEngine Protocol messages
 * @{
 */


/**
 * ST LayoutEngine Get Info request
 *
 * The X_STLayoutEngineGetInfo request is used to get detailed information about a 
 * specific layout engine.
 * The protocol Env is an XSTTypeEnv XID value referring to the STTypeEnv structure. The
 * protocol LayoutEngine is an XSTLayoutEngine XID representing the STLayoutEngine value.
 * The XServer calls STLayoutEngineGetInfo and passes the STTypeEnv object and the 
 * STLayoutEngine value. The function returns the name strings, version numbers and 
 * capability flags.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */ 
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLayoutEngineGetInfo          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	LayoutEngine B32;   /**< XSTLayoutEngine XID to use to get info         */
    CARD32      mask B32;           /**< Identify which fields to return                */
} xSTLayoutEngineGetInfoReq;
#define sz_xSTLayoutEngineGetInfoReq 16

/**
 * ST LayoutEngine Get Info reply
 *
 * The protocol response Tag represents the ???. The protocol response Version indicates 
 * the version number of the scaler. The top 16 bits are the major number, while the  
 * bottom 16 bits are the minor number. The protocol response LEFlags is a mask 
 * representing the abilities of the scaler. The protocol response ShortNameLen indicates
 * the length of the standard name of the scaler. The protocol response LongNameLen 
 * indicates the length of the full name of the scaler. The protocol response NoticeLen 
 * indicates the length of the notice string. Each of the strings is appended onto the end
 * of the response message. The ShortName is first, followed by the LongName, followed by
 * the Notice.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Tag B32;            /**< ???                                            */
    CARD32      Version B32;        /**< Major Number/Minor Number of version           */
    CARD32      LEFlags B32;        /**< Mask of layout engine abilities.               */
    CARD32      ShortNameLen B32;   /**< Number of bytes in Short Name                  */
    CARD32      LongNameLen B32;    /**< Number of bytes in Long Name                   */
    CARD32      NoticeLen B32;      /**< Number of bytes in Notice                      */
} xSTLayoutEngineGetInfoReply;
#define sz_xSTLayoutEngineGetInfoReply 32


/**
 * ST LayoutEngine Control request
 *
 * The X_STLayoutEngineControl request is used to send the scaler associated with a TypeEnv
 * object a string of data and get a response.
 * The protocol Env is the XID value referring to the STTypeEnv object to use. The 
 * protocol LayoutEngine is the XID value referring to the STLayoutEngine type to use. The
 * protocol count indicates the number of bytes appended onto the end of the request to
 * send to the scaler. The XServer calls STLayoutEngineControl and passes the STStyle
 * object along with the data and its length. The function returns a string of data and
 * its length.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response could not be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLayoutEngineControl          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	LayoutEngine B32;   /**< XSTLayoutEngine XID to use                     */
    CARD32	count B32;          /**< Number of bytes of data to send to the layout E*/
} xSTLayoutEngineControlReq;
#define sz_xSTLayoutEngineControlReq 16

/**
 * ST LayoutEngine Control reply
 *
 * The protocol response count is the number of bytes returned. The data is appended onto
 * the end of the response message.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of bytes of data returned from scaler   */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTLayoutEngineControlReply;
#define sz_xSTLayoutEngineControlReply 32


/**
 * @}
 */





/** @defgroup XSTFont_Protocol XSTFont Protocol messages
 * @{
 */


/**
 * ST Font Get Extra Info request
 *
 * The X_STFontGetInfo request attempts to retrieve several items of extra information
 * from a specified font in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain 
 * the extra information. The XServer calls STFontGetInfo and passes the STTypeEnv 
 * structure and the Font. The function returns the full font name, its length, the  
 * postscript name, and its length, along with the font type, flags indicating  
 * capabilities, an array of Sbits and the number of elements in the array, and the font's
 * metrics. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetInfo                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< Font ID to use in getting the info             */
    CARD32      mask B32;           /**< mask of which fields to get                    */
} xSTFontGetInfoReq;
#define sz_xSTFontGetInfoReq 16

/**
 * ST Font Get Extra Info reply
 *
 * The protocol response FontType is set to the font type. The protocol response Flags is
 * set to the flags value representing the font's capabilities. The protocol responses 
 * hAscent, hDescent, hLeading, vAscent, vDescent, vLeading, ItalicAngle, xMin, yMin, 
 * xMax, yMax, widthClass, and weightClass are all set to the values stored in the font 
 * metrics. The protocol response SbitCount is set to the number of Sbit elements in the 
 * Sbit array. The protocol response fNameCount is set to the number of characters in the
 * full font name. The protocol response pNameCount is set to the number of characters in
 * the Postscript name. The array of Sbits is appended to the end of the response, 
 * followed by the full font name string, followed by the postscript name string.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	FontType B32;       /**< Font Format: TrueType, Type1, etc.             */
    CARD32	Flags B32;          /**< Mask of font capabilities: IE embedded bitmaps */
    CARD64	hAscent;            /**< Metric value returned from the font            */
    CARD64	hDescent;           /**< Metric value returned from the font            */
    CARD64	hLeading;           /**< Metric value returned from the font            */
    CARD64	vAscent;            /**< Metric value returned from the font            */
    CARD64	vDescent;           /**< Metric value returned from the font            */
    CARD64	vLeading;           /**< Metric value returned from the font            */
    CARD64	italicAngle;        /**< Metric value returned from the font            */
    CARD64	xMin;               /**< Metric value returned from the font            */
    CARD64	yMin;               /**< Metric value returned from the font            */
    CARD64	xMax;               /**< Metric value returned from the font            */
    CARD64	yMax;               /**< Metric value returned from the font            */
    CARD32	SbitCount B32;      /**< Number of embedded bitmaps available in font   */
    CARD32	widthClass B32;     /**< Width of the font: IE Condensed, Expanded      */
    CARD32	weightClass B32;    /**< Weight of the font: IE Thin, Bold, etc         */
    CARD32	fNameCount B32;     /**< Number of bytes in the Font name               */
    CARD32	pNameCount B32;     /**< Number of bytes in the Postscript font name    */
    CARD32	uNameCount B32;     /**< Number of bytes in the URI name                */
} xSTFontGetInfoReply;
#define sz_xSTFontGetInfoReply 128

/**
 * ST Font Get Family request
 * 
 * The X_STFontGetFontFamily request attempts to retrieve the FontFamily ID value for a 
 * specified font in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain 
 * the FontFamily ID. The XServer calls STFontGetFontFamily and passes the STTypeEnv 
 * structure and the Font. The function returns the FontFamily ID.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetFontFamily            */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< Font ID to use in getting the info             */
} xSTFontGetFontFamilyReq;
#define sz_xSTFontGetFontFamilyReq 12

/**
 * ST Font Get Family reply
 *
 * The protocol response FontFamily is filled in with the FontFamily ID.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	FontFamily B32;     /**< XSTFontFamily ID                               */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTFontGetFontFamilyReply;
#define sz_xSTFontGetFontFamilyReply 32

/**
 * ST Font Get Typeface Name request
 *
 * The X_STFontGetTypefaceName request attempts to retrieve the available features for a 
 * specified font in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain 
 * the typeface name string. The protocol LanguageID is the language and region for which
 * to obtain the name. The XServer calls STFontGetTypefaceName and passes the STTypeEnv 
 * structure, the Font and the LanguageID. The function returns a string along with it's 
 * length in characters and the language that the typeface was returned using. The XServer
 * calls STIntCountUTF16Bytes to get the number of bytes that the string occupies.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetTypefaceName          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< Font ID to use in getting the info             */
    CARD32	LanguageID B32;     /**< Language type requested for string             */
    CARD32      mask B32;           /**< mask of which fields to get from font          */
} xSTFontGetTypefaceNameReq;
#define sz_xSTFontGetTypefaceNameReq 20

/**
 * ST Font Get Typeface Name reply
 *
 * The protocol response count is filled in with the number of characters in the string. 
 * The protocol response bytes is filled in with the number of bytes used by the string. 
 * The protocol response LanguageID is filled in with the LanguageID that most nearly 
 * matches the requested LanguageID. The protocol response weight tells the weight of the
 * font from light to heavy. The protocol response width tells the width of the font from
 * narrow to expanded. The protocol response style tells the style of the font from 
 * Regular to Italic. The Typeface name string is appended onto the end of the protocol 
 * response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of characters in the returned string    */
    CARD32	bytes B32;          /**< Number of bytes in the returned string         */
    CARD32	weight B32;         /**< Weight of font: IE: Compressed, Expanded       */
    CARD32	width B32;          /**< Width of font: IE: Thin, Bold, etc.            */
    CARD32	style B32;          /**< Style of font: IE: Regular, Italic             */
    CARD32	LanguageID B32;     /**< Language of returned string                    */
} xSTFontGetTypefaceNameReply;
#define sz_xSTFontGetTypefaceNameReply 32

/**
 * ST Font Get Data request
 *
 * The X_STFontGetData request attempts to retrieve a table of data from the specified 
 * font in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain 
 * the typeface name string. The protocol LanguageID is the language and region for which
 * to obtain the name. The XServer calls STFontGetTypefaceName and passes the STTypeEnv 
 * structure, the Font and the LanguageID. The function returns a string along with it's 
 * length in characters and the language that the typeface was returned using. The XServer
 * calls STIntCountUTF16Bytes to get the number of bytes that the string occupies.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetTypefaceName          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< Font ID to use in getting the info             */
    CARD32	Table B32;          /**< ID value for table to retrieve                 */
} xSTFontGetDataReq;
#define sz_xSTFontGetDataReq 16

/**
 * ST Font Get Typeface Name reply
 *
 * The protocol response count is filled in with the number of characters in the string. 
 * The protocol response bytes is filled in with the number of bytes used by the string. 
 * The protocol response LanguageID is filled in with the LanguageID that most nearly 
 * matches the requested LanguageID. The protocol response weight tells the weight of the
 * font from light to heavy. The protocol response width tells the width of the font from
 * narrow to expanded. The protocol response style tells the style of the font from 
 * Regular to Italic. The Typeface name string is appended onto the end of the protocol 
 * response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of characters in the returned string    */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTFontGetDataReply;
#define sz_xSTFontGetDataReply 32

/**
 * ST FontFamily Get Name request
 *
 * The X_STFontFamilyGetName request attempts to retrieve the Font Family name for a 
 * specified font family in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol FontFamily is the specific font family from which the user 
 * wants to obtain the font family name string. The protocol LanguageID is the language 
 * and region for which to obtain the name. The XServer calls STFontFamilyGetName and 
 * passes the STTypeEnv structure, the FontFamily ID and the LanguageID. The function 
 * returns a string along with it's length in characters and the language that the name 
 * was returned using. The XServer calls STIntCountUTF16Bytes to get the number of bytes 
 * that the string occupies.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontFamilyGetName            */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	FontFamily B32;     /**< Font ID to use in getting the info             */
    CARD32	LanguageID B32;     /**< Language type requested for string             */
} xSTFontFamilyGetNameReq;
#define sz_xSTFontFamilyGetNameReq 16

/**
 * ST FontFamily Get Name reply
 *
 * The protocol response count is filled in with the number of characters in the string. 
 * The protocol response bytes is filled in with the number of bytes used by the string. 
 * The font family name string is appended onto the end of the protocol response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of characters in the returned string    */
    CARD32	bytes B32;          /**< Number of bytes in the returned string         */
    CARD32	LanguageID B32;     /**< Language of returned string                    */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
} xSTFontFamilyGetNameReply;
#define sz_xSTFontFamilyGetNameReply 32

/**
 * ST FontFamily Get Fonts request
 *
 * The X_STFontFamilyGetFonts request attempts to retrieve the Font IDs for a specified 
 * font family in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol FontFamily is the specific font family from which the user 
 * wants to obtain the list of font IDs. The XServer calls STFontFamilyGetFonts and passes
 * the STTypeEnv structure, and the FontFamily ID. The function returns a list of font IDs
 * along with the number of fonts in the list.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontFamilyGetFonts           */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	FontFamily B32;     /**< Font ID to use in getting the info             */
} xSTFontFamilyGetFontsReq;
#define sz_xSTFontFamilyGetFontsReq 12

/**
 * ST FontFamily Get Fonts reply
 *
 *
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of XSTFont IDs returned                 */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTFontFamilyGetFontsReply;
#define sz_xSTFontFamilyGetFontsReply 32


/**
 * @}
 */


/**
 * ST Font Get Name Tags request
 *
 * The X_STFontGetNameTags request attempts to retrieve all of the NameTags available in a
 * particular font in a particular STTypeEnv. A NameTag is comprised of a PlatformID, 
 * EncodingID, LanguageID, and NameID.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain 
 * NameTags. The XServer calls STFontGetNameTags and passes both the STTypeEnv structure 
 * and Font. The function returns a list of NameTags and the number of tags found in the 
 * font.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the NameTags cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetNameTags              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< Font ID to use in getting the tags             */
} xSTFontGetNameTagsReq;
#define sz_xSTFontGetNameTagsReq 12

/**
 * ST Font Get Name Tags reply
 *
 * The protocol response count is set to the number of tags. The rest of the tags are 
 * appended onto the end of the response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of Font Folders returned                */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTFontGetNameTagsReply;
#define sz_xSTFontGetNameTagsReply 32

/**
 * ST Font Get Name String request
 *
 * The X_STFontGetNameString request attempts to retrieve a particular string from a 
 * specified font in a particular STTypeEnv. The string should be uniquely represented by
 * a NameTag whose values are included in the request.
 *
 * This protocol message is used for two seperate calls. It handles the 
 * XSTFontGetNameString and XSTFontGetUnicodeNameString functions.
 *
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain a
 * name string. 
 * For the XSTFontGetNameString function, the protocol PlatformID, EncodingID, LanguageID,
 * and NameID are values that represent a unique NameTag. The protocol Format is set to 0.
 * The XServer calls STFontGetNameString and passes the STTypeEnv structure, Font, and the
 * NameTag structure built of the four NameTag values. The function returns a string along
 * with its length.
 * For the XSTFontGetUnicodeNameString function, the protocol PlatformID, EncodingID,
 * LanguageID, and NameID are values that represent a unique NameTag. The protocol Format
 * is set to 1. The XServer calls STFontGetUnicodeName and passes the STTypeEnv structure,
 * Font and the NameTag structure built of the four NameTag values. The function returns a
 * string along with its length. The XServer also calls STIntCountUTF16Bytes to get the
 * number of bytes used in the string.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for the string cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetNameString            */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< Font ID to use in getting the tags             */
    CARD16	PlatformID B16;     /**< Platform ID tag                                */
    CARD16	EncodingID B16;     /**< Encoding ID tag                                */
    CARD32	LanguageID B16;     /**< Language ID tag                                */
    CARD16	NameID B16;         /**< Name ID tag                                    */
    CARD16	Format B32;         /**< Platform ID tag                                */
} xSTFontGetNameStringReq;
#define sz_xSTFontGetNameStringReq 24

/**
 * ST Font Get Name String reply
 *
 * The protocol response count is set to the number of bytes in the non UTF8 string. The
 * protocol bytes is set to the number of bytes returned by STIntCountUTF16Bytes. The 
 * string is appended onto the end of the response. The protocol response LanguageID is 
 * the language of the returned string.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of characters in the non UTF8 string    */
    CARD32	bytes B32;          /**< Number of bytes in the UTF8 string             */
    CARD32	LanguageID B32;     /**< Language of the string                         */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
} xSTFontGetNameStringReply;
#define sz_xSTFontGetNameStringReply 32


/**
 * ST Font Get Baselines request
 *
 * The X_STFontGetBaselines request attempts to retrieve baseline information from a 
 * specified font in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain  
 * the baseline information. The XServer calls STFontGetBaselines and passes the STTypeEnv
 * structure and the Font. The function returns the baseline values available for the  
 * font. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetBaselines             */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< Font ID to use in getting the info             */
} xSTFontGetBaselinesReq;
#define sz_xSTFontGetBaselinesReq 12

/**
 * ST Font Get Baselines reply
 *
 * The function returns the baseline values available for the font. The protocol response
 * count is the number of baselines returned at the end of the protocol response. The 
 * protocol mask is the mask of which baselines are returned.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of baselines returned at end of reply   */
    CARD32      mask B32;           /**< Identify which baselines are present           */ 
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
} xSTFontGetBaselinesReply;
#define sz_xSTFontGetBaselinesReply 32


/**
 * ST Font Get Features request
 *
 * The X_STFontGetFeatures request attempts to retrieve the available features for a 
 * specified font in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain 
 * the features information. The XServer calls STFontGetFeatures and passes the STTypeEnv
 * structure and the Font. The function returns a list of features available for the font.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetFeatures              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	Font B32;           /**< Font ID to use in getting the info             */
} xSTFontGetFeaturesReq;
#define sz_xSTFontGetFeaturesReq 12

/**
 * ST Font Get Features reply
 *
 * The protocol response count is filled in with the number of features available for the
 * font. The list of features is appended onto the end of the response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of Font Folders returned                */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTFontGetFeaturesReply;
#define sz_xSTFontGetFeaturesReply 32

/**
 * ST Font Get Signature request
 *
 * The X_STFontGetSignature request attempts to retrieve the md5 encrypted signature of the
 * specified font in a particular STTypeEnv.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Font is the specific font from which the user wants to obtain
 * the features information. The XServer calls STFontGetSignature and passes the STTypeEnv
 * structure and the Font. The function returns a string containing the signature
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STFontGetSignature             */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32      Font B32;           /**< Font ID to use in getting the info             */
} xSTFontGetSignatureReq;
#define sz_xSTFontGetSignatureReq 12

/**
 * ST Font Get Signature reply
 *
 * The protocol response count is filled in with the number of bytes used by the signature.
 * The signature is appended onto the end of the response.
 */
typedef struct {
    BYTE        type;               /**< Reply Type: always X_Reply                     */
    CARD8       pad0;               /**< Not used                                       */
    CARD16      sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32      length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of bytes in the signature               */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
    CARD32      pad5 B32;           /**< Not used                                       */
} xSTFontGetSignatureReply;
#define sz_xSTFontGetSignatureReply 32





/** @defgroup XSTGC_Protocol XSTGC Protocol messages
 * @{
 */


/**
 * ST GC Set Colors request
 *
 * The X_STGCSetColors request is used to set colors for the text, highlight, underline, 
 * and strikethrough.
 * The protocol gc is the XID value referring to the gc structure to modify. The protocol 
 * mask indicates which of the color values to set. The protocol count is the number of
 * color values appended to the end of the request. The XServer calls STGraphicsSetColors 
 * and passes the STGraphics object obtained from the GC along with the colors and the 
 * mask. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the GC to use is not valid.
 * BadImplementation may be returned if the STGraphics to use is NULL.
 * BadAlloc may be returned if an STGraphics cannot be allocated to associate with the GC.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGCSetColors                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      gc B32;             /**< Graphics Context.                              */
    CARD32	mask B32;           /**< Mask indicating which colors to set            */
    CARD32      count B32;          /**< Number of colors appended to end of request    */
} xSTGCSetColorsReq;
#define sz_xSTGCSetColorsReq 16

/**
 * ST GC Get Colors request
 *
 * The X_STGCGetColors request is used to get colors for the text, highlight, underline, 
 * and strikethrough.
 * The protocol gc is the XID value referring to the gc structure to check. The XServer 
 * calls STGraphicsGetColors and passes the STGraphics object obtained from the GC. The 
 * function returns those colors that have been set along with a mask indicating which 
 * colors those are.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the GC to use is not valid.
 * BadImplementation may be returned if the STGraphics to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGCGetColors                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      gc B32;             /**< Graphics Context.                              */
} xSTGCGetColorsReq;
#define sz_xSTGCGetColorsReq 8

/**
 * ST GC Get Colors reply
 * 
 * The protocol response mask indicates which of the color values have been set. The
 * protocol response count is the number of color values appended to the end of the 
 * reply.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      mask B32;           /**< Mask indicating which colors have been set     */
    CARD32      count B32;          /**< Number of color values appended to end of rep  */
    CARD32      pad1 B32;	    /**< Not Used                                       */
    CARD32      pad2 B32;	    /**< Not Used                                       */
    CARD32      pad3 B32;	    /**< Not Used                                       */
    CARD32      pad4 B32;	    /**< Not Used                                       */
} xSTGCGetColorsReply;
#define sz_xSTGCGetColorsReply 32

/**
 * ST GC Set Output Format request
 *
 * The X_STGCSetOutputFormat request is used to set the output to go to a raster or vector
 * device, and to set the mode to tailor the output to be B&W, Grayscale or LCD optimized.
 * The protocol gc is the XID value referring to the gc structure to modify. The protocol
 * Mode indicates which output device is being used (B&W, Grayscale, LCD, etc.). The 
 * protocol Type indicates whether the format is Raster or Vector. The XServer calls 
 * STGraphicsSetDevice and passes the STGraphics object obtained from the GC along with 
 * the STDevice created based on the Type value. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the GC to use is not valid or the Type value is not Raster
 *  or Vector.
 * BadImplementation may be returned if the STGraphics to use is NULL.
 * BadAlloc may be returned if the STGraphics cannot be allocated to associate with the GC
 *  or the STDevice cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGCSetOutputFormat            */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      gc B32;             /**< Graphics Context.                              */
    CARD32      Mode B32;           /**< Format of the output. IE: B&W, LCD, Grayscale  */
    CARD32	Type B32;           /**< Output Type. IE: Raster or Vector device       */
} xSTGCSetOutputFormatReq;
#define sz_xSTGCSetOutputFormatReq 16

/**
 * ST GC Get Output Format request
 *
 * The X_STGCGetOutputFormat request is used to get the output device, either a raster or
 * vector device, and to get the mode the output is tailored to.
 * The protocol gc is the XID value referring to the gc structure to modify. The XServer 
 * calls STGraphicsGetDevice and passes the STGraphics object obtained from the GC.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the GC to use is not valid.
 * BadImplementation may be returned if the STGraphics to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGCGetOutputFormat            */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      gc B32;             /**< Graphics Context.                              */
    CARD32      mask B32;           /**< Identify which fields to return                */
} xSTGCGetOutputFormatReq;
#define sz_xSTGCGetOutputFormatReq 12

/**
 * ST GC Get Output Format reply
 *
 * The protocol response Mode indicates which output device is being used (B&W, Grayscale,
 * LCD, etc.). The protocol response Type indicates whether the format is Raster or 
 * Vector.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Mode B32;           /**< Format of the output. IE: B&W, LCD, Grayscale  */
    CARD32      Type B32;           /**< Output Type. IE: Raster or Vector device       */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
} xSTGCGetOutputFormatReply;
#define sz_xSTGCGetOutputFormatReply 32

/**
 * ST GC Set Alpha Range request
 *
 * The X_STGCSetAlphaRange request is used to set alpha ranges for the text, highlight, 
 * underline, and strikethrough.
 * The protocol gc is the XID value referring to the gc structure to modify. The protocol
 * mask indicates which of the alpha range pairs are appended to the end of the request.
 * The protocol count contains the number of alpha range pairs appended to the end of
 * the request. Alpha entries are two doubles representing the min and max values of the
 * alpha range for that item. The range is between 0.0 and 1.0 where min must be less
 * than max.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the GC to use is not valid or if the *min is greater than 
 *  the *max value.
 * BadAlloc may be returned if the STGraphics associated with the GC cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGCSetAlphaRange              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      gc B32;             /**< Graphics Context.                              */
    CARD32      mask B32;           /**< Mask indicating which Alpha values are set     */
    CARD32      count B32;          /**< Count of number of alpha pairs appended        */
} xSTGCSetAlphaRangeReq;
#define sz_xSTGCSetAlphaRangeReq 16

/**
 * ST GC Get Alpha Range request
 *
 * The X_STGCGetAlphaRange request is used to get alpha ranges for the text, highlight, 
 * underline, and strikethrough.
 * The protocol gc is the XID value referring to the gc structure to check.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the GC to use is not valid.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGCGetAlphaRange              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      gc B32;             /**< Graphics Context.                              */
} xSTGCGetAlphaRangeReq;
#define sz_xSTGCGetAlphaRangeReq 8

/**
 * ST GC Get Alpha Range reply
 *
 * The protocol response mask indicates which of the alpha pairs are returned.
 * The protocol response count contains the number of alpha pairs that are appended
 * to the end of the reply. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      mask B32;           /**< Mask indicating which Alpha values are set     */
    CARD32      count B32;          /**< Number of alpha pairs returned in reply        */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
} xSTGCGetAlphaRangeReply;
#define sz_xSTGCGetAlphaRangeReply 32

/**
 * ST GC Get Matrix request
 * 
 * The X_STGCGetMatrix request is used to get the transformation matrix.
 * The protocol gc is the XID value referring to the gc structure to use. The XServer 
 * calls STDeviceGetMatrix and passes the STDevice object obtained from the GC. The 
 * function returns the transformation matrix.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the GC to use is not valid.
 * BadImplementation may be returned if the STDevice to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGCGetMatrix                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      gc B32;             /**< Graphics Context.                              */
} xSTGCGetMatrixReq;
#define sz_xSTGCGetMatrixReq 8

/**
 * ST GC Get Matrix reply
 *
 * The protocol response xx is a double representing the xx portion of the matrix. The 
 * protocol response xy is a double representing the xy portion of the matrix. The 
 * protocol response yx is a double representing the yx portion of the matrix. The 
 * protocol response yy is a double representing the yy portion of the matrix. The 
 * protocol response tx is a double representing the tx portion of the matrix. The 
 * protocol response ty is a double representing the ty portion of the matrix. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64      xx;                 /**< xx portion of matrix                           */
    CARD64      xy;                 /**< xy portion of matrix  [xx][xy]                 */
    CARD64      yx;                 /**< yx portion of matrix  [yx][yy]                 */
    CARD64      yy;                 /**< yy portion of matrix  [tx][ty]                 */
    CARD64      tx;                 /**< tx portion of matrix                           */
    CARD64      ty;                 /**< ty portion of matrix                           */
} xSTGCGetMatrixReply;
#define sz_xSTGCGetMatrixReply 56

/**
 * ST GC Set Matrix request
 * 
 * The X_STGCSetMatrix request is used to set the transformation matrix held in the GC and
 * the STDevice object.
 * The protocol gc is the XID value referring to the gc structure to modify. The protocol
 * xx is a double representing the xx portion of the matrix. The protocol xy is a double 
 * representing the xy portion of the matrix. The protocol yx is a double representing the
 * yx portion of the matrix. The protocol yy is a double representing the yy portion of 
 * the matrix. The protocol tx is a double representing the tx portion of the matrix. The
 * protocol ty is a double representing the ty portion of the matrix. The XServer calls 
 * STDeviceSetMatrix and passes the STDevice object obtained from the GC along with the 
 * matrix information. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the GC to use is not valid.
 * BadImplementation may be returned if the STDevice to use is NULL.
 * BadAlloc may be returned if the STGraphics cannot be allocated to associate with the GC
 *  or the STDevice cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGCSetMatrix                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      gc B32;             /**< Graphics Context.                              */
    CARD64      xx;                 /**< xx portion of matrix                           */
    CARD64      xy;                 /**< xy portion of matrix  [xx][xy]                 */
    CARD64      yx;                 /**< yx portion of matrix  [yx][yy]                 */
    CARD64      yy;                 /**< yy portion of matrix  [tx][ty]                 */
    CARD64      tx;                 /**< tx portion of matrix                           */
    CARD64      ty;                 /**< ty portion of matrix                           */
} xSTGCSetMatrixReq;
#define sz_xSTGCSetMatrixReq 56

typedef struct {
    CARD8       reqType;
    CARD8       stReqType;
    CARD16      length B16;
    CARD32      gc B32;
    CARD64      xx;
    CARD64      xy;
    CARD64      yx;
    CARD64      yy;
    CARD64      tx;
    CARD64      ty;
} xSTGCConcatMatrixReq;
#define sz_xSTGCConcatMatrixReq 56

typedef struct {
    CARD8       reqType;
    CARD8       stReqType;
    CARD16      length B16;
    CARD32      gc B32;
    CARD64      tx;
    CARD64      ty;
} xSTGCTranslateReq;
#define sz_xSTGCTranslateReq 24

typedef struct {
    CARD8       reqType;
    CARD8       stReqType;
    CARD16      length B16;
    CARD32      gc B32;
    CARD64      sx;
    CARD64      sy;
} xSTGCScaleReq;
#define sz_xSTGCScaleReq 24

typedef struct {
    CARD8       reqType;
    CARD8       stReqType;
    CARD16      length B16;
    CARD32      gc B32;
    CARD64      theta;
} xSTGCRotateReq;
#define sz_xSTGCRotateReq 16

typedef struct {
    CARD8       reqType;
    CARD8       stReqType;
    CARD16      length B16;
    CARD32      gc B32;
    CARD64      shx;
    CARD64      shy;
} xSTGCShearReq;
#define sz_xSTGCShearReq 24

typedef struct {
    CARD8       reqType;
    CARD8       stReqType;
    CARD16      length B16;
    CARD32      gc B32;
    CARD32      numRects B32;
    CARD32      extX1 B32;
    CARD32      extX2 B32;
    CARD32      extY1 B32;
    CARD32      extY2 B32;
} xSTGCSetRegionReq;
#define sz_xSTGCSetRegionReq 28


/**
 * @}
 */





/** @defgroup XSTStyle_Protocol XSTStyle Protocol messages
 * @{
 */



/**
 * ST Style New Copy request
 * 
 * The X_STStyleNewCopy request is used to create a new STStyle object. This command is 
 * used for creating an empty STStyle, a default STStyle or to copy an existing STStyle.
 * The protocol Env is the XID value referring to the STTypeEnv object to associate the 
 * new STStyle object with. The protocol OldStyle is the XID value referring to the 
 * STStyle object to copy. This value is zero (0) if the command is performing a NewEmpty
 * or NewDefault operation. The protocol NewStyle is the XID value the client is 
 * requesting for the new XSTStyle. The protocol Type is not used for performing a copy 
 * operation. It indicates which NewEmpty or NewDefault operation to perform. The XServer
 * calls STStyleNewCopy on a copy request, passing the STTypeEnv object, and the STStyle 
 * object referred to by OldStyle XID. For the NewEmpty request, the XServer calls 
 * STStyleNewEmpty and passes the STTypeEnv object. For the NewDefault request the XServer
 * calls STStyleNewDefault and passes the STTypeEnv object. The functions each return an 
 * STStyle object.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv or XSTStyle (OldStyle) to use is not valid.
 * BadImplementation may be returned if the STTypeEnv or STStyle to use is NULL.
 * BadAlloc may be returned if the new STStyle object cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleNewCopy                 */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32	OldStyle B32;       /**< XSTStyle XID to copy. 0 if not copying         */
    CARD32	NewStyle B32;       /**< New XSTStyle XID to associate with STStyle     */
    CARD32	Type B32;           /**< Command Type to perform. NewStyle, NewCopy, etc*/
} xSTStyleNewCopyReq;
#define sz_xSTStyleNewCopyReq 20

/**
 * ST Style Dispose request
 * 
 * The X_STStyleDispose request is used to free an existing STStyle object and its 
 * associated XID value.
 * The protocol Style is the XID value referring to the STLine object to dispose. The 
 * XServer calls STStyleDispose and passes the STStyle object. There is no response to 
 * this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleDispose                 */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
} xSTStyleDisposeReq;
#define sz_xSTStyleDisposeReq 8

/**
 * ST Style Compare request
 *
 * The X_STStyleCompare request is used to compare two STStyle objects. It tells whether 
 * they are equal, subset, superset, or unequal.
 * The protocol Style1 is the XID value referring to the first STStyle object to compare.
 * The protocol Style2 is the XID value referring to the second STStyle object to compare.
 * The protocol mask is a bitmask indicating which fields to compare. The XServer calls 
 * STStyleCompare and passes the two STStyle objects. The function returns a value 
 * indicating how equal the styles are. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if either XSTStyle to use is not valid.
 * BadImplementation may be returned if either STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleCompare                 */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style1 B32;         /**< XSTStyle XID to compare                        */
    CARD32	Style2 B32;         /**< XSTStyle XID to compare                        */
    CARD32	mask B32;           /**< Mask identifying fields to compare             */
} xSTStyleCompareReq;
#define sz_xSTStyleCompareReq 16

/**
 * ST Style Compare reply
 *
 * The protocol response compare is the returned value indicating the equality of the 
 * STStyle objects.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      compare B32;        /**< Result of comparison                           */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTStyleCompareReply;
#define sz_xSTStyleCompareReply 32

/**
 * ST Style Is Empty request
 *
 * The X_STStyleIsEmpty request is used to check if an STStyle object is empty. 
 * The protocol Style is the XID value referring to the STStyle object to check. The 
 * XServer calls STStyleIsEmpty and passes the STStyle object. The function returns a 
 * value indicating whether the STStyle is empty.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleIsEmpty                 */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
} xSTStyleIsEmptyReq;
#define sz_xSTStyleIsEmptyReq 8

/**
 * ST Style Is Empty reply
 *
 * The protocol response isempty is the returned value.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      isempty B32;        /**< Result of test                                 */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTStyleIsEmptyReply;
#define sz_xSTStyleIsEmptyReply 32

/**
 * ST Style Remove Attributes request
 *
 * The X_STStyleRemoveAttributes request is used to clear the attribute fields of an 
 * STStyle object. The protocol Style is the XID value referring to the STStyle object to 
 * clear. The protocol mask is a bitmask indicating which fields to clear. The XServer 
 * calls STStyleIsClear and passes the STStyle object. There is no response to this 
 * command.

 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleRemoveAttributes        */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32	mask B32;           /**< Mask indicating the fields to clear            */
} xSTStyleRemoveAttributesReq;
#define sz_xSTStyleRemoveAttributesReq 12

/**
 * ST Style Set Font request
 *
 * The X_STStyleSetFont request is used to set the font, size, various flags, or features
 * of an STStyle object. 
 * The protocol Style is the XID value referring to the STStyle object to modify. The 
 * protocol Size is a double representing the size of the font to use. The protocol Font 
 * is the STFont value. The protocol LanguageID is the language associated with this 
 * style. The protocol BaselineFlag indicates which baseline to use. The protocol count 
 * indicates the number of Features appended onto the end of the request message to set in
 * the font. The protocol mask tells which values to set within the STStyle object. The 
 * XServer calls STStyleSetFont and passes the STStyle object, the STFont, its Size, Flags
 * and Features along with the mask. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleSetFont                 */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD64	Size;               /**< Point Size of Font for length of style         */
    CARD32	Font B32;           /**< XSTFont ID for length of style                 */
    CARD32	LanguageID B32;     /**< Language used for length of style              */
    CARD32	BaselineFlag B32;   /**< Baseline to use for length of style            */
    CARD32	mask B32;           /**< Mask indicating the fields to clear            */
} xSTStyleSetFontReq;
#define sz_xSTStyleSetFontReq 32

/**
 * ST Style Get Font request
 *
 * The X_STStyleGetFont request is used to get the font, size, various flags, and features
 * of an STStyle object. 
 * The protocol Style is the XID value referring to the STStyle object to check. The 
 * XServer calls STStyleGetFont and passes the STStyle object. The command returns the 
 * Font, its Size, language used during the style, the baseline being used, and any 
 * features set for the style. It also returns a mask that shows which of these values was
 * set in the STStyle object.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleGetFont                 */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32      mask B32;           /**< mask indicating fileds to return               */
} xSTStyleGetFontReq;
#define sz_xSTStyleGetFontReq 12

/**
 * ST Style Get Font reply
 *
 * The protocol response Size is a double representing the size of the font. The protocol
 * response Font is the STFont value. The protocol response LanguageID represents the 
 * language in use. The protocol response BaselineFlag indicates which baseline is used. 
 * The protocol count indicates the number of Features appended onto the end of the 
 * response message. The protocol mask tells which values are set within the STStyle 
 * object. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64      Size;               /**< Point size of the font                         */
    CARD32      Font B32;           /**< XST Font ID of the style                       */
    CARD32      LanguageID B32;     /**< Language used within style                     */
    CARD32      BaselineFlag B32;   /**< Baseline set within style                      */
    CARD32	mask B32;           /**< Mask indicating the fields that have been set  */
} xSTStyleGetFontReply;
#define sz_xSTStyleGetFontReply 32

/**
 * ST Style Set Scaler request
 *
 * The X_STStyleSetScaler request is used to set the scaler to use, the hinting method to
 * use, and whether to use embedded bitmaps or not, for an STStyle object.
 * The protocol Style is the XID value referring to the STStyle object to modify. The
 * protocol Scaler is the STScaler value to set. The protocol Hints is a flag indicating
 * the type of hinting the scaler is to user. The protocol Sbits indicates if the scaler
 * is to use embedded bitmaps. The protocol mask indicates which of the values to set in
 * the STStyle object. The XServer calls STStyleSetScaler and passes the STStyle object,
 * the scaler, the hints and Sbits flags, and the mask. There is no response to this
 * command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleSetScaler               */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32      Scaler B32;         /**< XSTScaler ID to use                            */
    CARD32      Hints B32;          /**< Hinting mode to use. IE: Apply Hints, Autohint */
    CARD32      Sbits B32;          /**< Flag to use embedded bitmaps                   */
    CARD32	mask B32;           /**< Mask indicating the fields to set              */
} xSTStyleSetScalerReq;
#define sz_xSTStyleSetScalerReq 24

/**
 * ST Style Get Scaler request
 *
 * The X_STStyleGetScaler request is used to get the scaler in use, the hinting method in
 * use, and whether embedded bitmaps are used, in an STStyle object. 
 * The protocol Style is the XID value referring to the STStyle object to check. The
 * XServer calls STStyleGetScaler and passes the STStyle object. The function returns
 * which scaler is being used, which hinting method is used, whether embedded bitmaps are
 * enabled, and a mask indicating which of these fields was previously set.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleGetScaler               */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32      mask B32;           /**< Indicates which fields to return               */
} xSTStyleGetScalerReq;
#define sz_xSTStyleGetScalerReq 12

/**
 * ST Style Get Scaler reply
 *
 * The protocol response Scaler is the STScaler value currently set. The protocol response
 * Hints is a flag indicating the type of hinting the scaler is using. The protocol 
 * response Sbits indicates if the scaler is using embedded bitmaps. The protocol response * mask indicates which of the values are set in the STStyle object. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Scaler B32;         /**< XSTScaler ID to use                            */
    CARD32      Hints B32;          /**< Hinting mode to use. IE: Apply Hints, Autohint */
    CARD32      Sbits B32;          /**< Flag to use embedded bitmaps                   */
    CARD32	mask B32;           /**< Mask indicating the fields that have been set  */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
} xSTStyleGetScalerReply;
#define sz_xSTStyleGetScalerReply 32

/**
 * ST Style Set Effects request
 *
 * The X_STStyleSetEffects request is used to set the style effects such as Ligature and 
 * Kerning use, and to set the effects for Strikethrough and Underline for an STStyle 
 * object.
 * The protocol Style is the XID value referring to the STStyle object to modify. The 
 * protocol StyleEffects represents a mask of style effects to use such as Ligature and 
 * Kerning settings. The protocol STEffects is a mask indicating the type of strikethrough
 * to use. The protocol ULEffects is a mask that indicates the type of underline to use.
 * The protocol mask indicates which of the values to set in the STStyle object. The
 * XServer calls STStyleSetEffects and passes the STStyle object, the StyleEffects, the
 * STEffects and ULEffects flags, and the mask. There is no response to this command.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleSetEffects              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32      StyleEffects B32;   /**< Mask of style effects. IE: Ligature, Kerning   */
    CARD32      STEffects B32;      /**< Mask of strikethrough effects. IE: double      */
    CARD32      ULEffects B32;      /**< Mask of underline effects. IE: dash, thick     */
    CARD32	mask B32;           /**< Mask indicating which fields to set            */
} xSTStyleSetEffectsReq;
#define sz_xSTStyleSetEffectsReq 24

/**
 * ST Style Get Effects request
 *
 * The X_STStyleGetEffects request is used to get the style effects such as Ligature and 
 * Kerning use, and to get the effects for Strikethrough and Underline for an STStyle 
 * object. 
 * The protocol Style is the XID value referring to the STStyle object to check. The
 * XServer calls STStyleGetEffects and passes the STStyle object. The function returns the
 * StyleEffects, the STEffects and ULEffects flags, and the mask indicating which of
 * these effects have been set. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleGetEffects              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32      mask B32;           /**< Indiates which fields to return                */
} xSTStyleGetEffectsReq;
#define sz_xSTStyleGetEffectsReq 12

/**
 * ST Style Get Effects reply
 *
 * The protocol response StyleEffects represents a mask of style effects in use such as
 * Ligature and Kerning settings. The protocol response STEffects is a mask indicating the
 * type of strikethrough in use. The protocol response ULEffects is a mask that indicates
 * the type of underline in use. The protocol response mask indicates which of the values
 * were set in the STStyle object.  
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      StyleEffects B32;   /**< Mask of style effects. IE: Ligature, Kerning   */
    CARD32      STEffects B32;      /**< Mask of strikethrough effects. IE: double      */
    CARD32      ULEffects B32;      /**< Mask of underline effects. IE: dash, thick     */
    CARD32	mask B32;           /**< Mask indicating which fields to set            */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
} xSTStyleGetEffectsReply;
#define sz_xSTStyleGetEffectsReply 32

/**
 * ST Style Reset Attributes request
 *
 * The X_STStyleResetAttributes request is used to reset specific attributes for an
 * STStyle object. 
 * The protocol Style is the XID value referring to the STStyle object to modify. The
 * protocol mask indicates which of the values to reset in the STStyle object. The XServer
 * calls STStyleResetAttributes and passes the STStyle object and the mask. There is no
 * response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleResetAttributes         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32	mask B32;           /**< Mask indicating fields to reset                */
} xSTStyleResetAttributesReq;
#define sz_xSTStyleResetAttributesReq 12

/**
 * ST Style Copy Attributes request
 *
 * The X_STStyleCopyAttributes request is used to copy specific attributes from an STStyle
 * object to another. 
 * The protocol ToStyle is the XID value referring to the STStyle object to modify. The 
 * protocol FromStyle is the XID value referring to the STStyle object to copy. The 
 * protocol mask indicates which of the values to copy from the STStyle object to the 
 * other. The XServer calls STStyleCopyAttributes and passes the two STStyle objects and 
 * the mask. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleCopyAttributes          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	ToStyle B32;        /**< XSTStyle XID to copy to                        */
    CARD32	FromStyle B32;      /**< XSTStyle XID to copy from                      */
    CARD32	mask B32;           /**< Mask indicating fields to copy                 */
} xSTStyleCopyAttributesReq;
#define sz_xSTStyleCopyAttributesReq 16

/**
 * ST Style Overwrite Attributes request
 *
 * The X_STStyleOverwriteAttributes request is used to copy specific attributes from an
 * STStyle object to another. 
 * The protocol ToStyle is the XID value referring to the STStyle object to modify. The
 * protocol FromStyle is the XID value referring to the STStyle object to copy. The
 * protocol mask indicates which of the values to copy from the STStyle object to the
 * other. The XServer calls STStyleOverwriteAttributes and passes the two STStyle objects
 * and the mask. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleOverwriteAttributes     */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	ToStyle B32;        /**< XSTStyle XID to overwrite to                   */
    CARD32	FromStyle B32;      /**< XSTStyle XID to overwrite from                 */
    CARD32	mask B32;           /**< Mask indicating fields to overwrite            */
} xSTStyleOverwriteAttributesReq;
#define sz_xSTStyleOverwriteAttributesReq 16

/**
 * ST Style Underwrite Attributes request
 *
 * The X_STStyleUnderwriteAttributes request is used to copy specific attributes from an 
 * STStyle object to another. 
 * The protocol ToStyle is the XID value referring to the STStyle object to modify. The
 * protocol FromStyle is the XID value referring to the STStyle object to copy. The
 * protocol mask indicates which of the values to copy from the STStyle object to the
 * other. The XServer calls STStyleUnerwriteAttributes and passes the two STStyle objects
 * and the mask. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleUnderwriteAttributes    */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	ToStyle B32;        /**< XSTStyle XID to underwrite to                  */
    CARD32	FromStyle B32;      /**< XSTStyle XID to underwrite from                */
    CARD32	mask B32;           /**< Mask indicating fields to underwrite           */
} xSTStyleUnderwriteAttributesReq;
#define sz_xSTStyleUnderwriteAttributesReq 16

/**
 * ST Style Get Baselines request
 *
 * The X_STStyleCalculateBaselines request attempts to retrieve baseline information from a 
 * specified STStyle.
 * 
 * The protocol Style is an XID referring to the specific STStyle from which the user 
 * wants to obtain  the baseline information. The XServer calls STStyleCalculateBaselines and 
 * passes the STStyle structure and BaselineFlag information. The function returns the 
 * baseline values available for the font associated with the style. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleCalculateBaselines      */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32	BaselineFlag B32;   /**< Flag indicating which font baseline to use     */
} xSTStyleCalculateBaselinesReq;
#define sz_xSTStyleCalculateBaselinesReq 12

/**
 * ST Style Get Baselines reply
 *
 * The protocol response count is the number of baselines returned at the end of the 
 * protocol response. The protocol mask is the mask of which baselines are returned.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of baselines returned at end of reply   */
    CARD32      mask B32;           /**< Indicates which baselines are returned         */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
} xSTStyleCalculateBaselinesReply;
#define sz_xSTStyleCalculateBaselinesReply 32

/**
 * ST Style Get Design Metrics request
 *
 * The X_STStyleGetDesignMetrics request attempts to retrieve metric information about the
 * font associated with a specified STStyle.
 *
 * The protocol Style is an XID referring to the specific STStyle from which the user
 * wants to obtain  the metrics information. The XServer calls STStyleGetDesignMetrics and
 * passes the STStyle structure. The function returns the metrics values in design units
 * associated with the font in the STStyle.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleGetDesignMetrics        */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
} xSTStyleGetDesignMetricsReq;
#define sz_xSTStyleGetDesignMetricsReq 8

/**
 * ST Style Get Design Metrics reply
 *
 * The protocol response Ascent refers to the ascent of the text in design units. The 
 * protocol response Descent refers to the descent of the text in design units. The 
 * protocol response Leading refers to the leading between lines in design units.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64	Ascent;             /**< Maximum ascent of line in design units         */
    CARD64	Descent;            /**< Maximum descent of line in design units        */
    CARD64	Leading;            /**< Maximum leading of line in design units        */
} xSTStyleGetDesignMetricsReply;
#define sz_xSTStyleGetDesignMetricsReply 32

/**
 * ST Style Get Options request
 *
 * The X_STStyleGetOptions request is used to retrieve special kerning values from an 
 * STStyle object.
 * The protocol Style is the XID value referring to the STStyle object to access. The 
 * XServer calls STStyleGetOptions and passes the STStyle object. The function returns 
 * several values along with a mask indicating the values that have been previously set. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleGetOptions              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32      mask B32;           /**< Indicates which fields to return               */
} xSTStyleGetOptionsReq;
#define sz_xSTStyleGetOptionsReq 12

/**
 * ST Style Get Options reply
 *
 * The protocol response ImposeWidth is the width imposed on the style. The protocol
 * response BeforeWSS is the amount to shift before the stream. The protocol response
 * AfterWSS is the amount to shift after the stream. The protocol response CrossSS is the
 * cross stream shift. The protocol response Tracking is the amount of space between the
 * characters. The protocol response HangingIF is the hanging inhibit factor. The protocol
 * response KerningIF is the kerning inhibit factor. The protocol response 
 * DecompositionIF is the decomposition inhibit factor. The protocol response mask 
 * indicates which of the values to were previously modified.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	ImposeWidth B32;    /**< Width imposed on the Style                     */
    CARD32	BeforeWSS B32;      /**< Amount to shift before the stream              */
    CARD32	AfterWSS B32;       /**< Amount to shift after the stream               */
    CARD32	CrossSS B32;        /**< Cross stream shift                             */
    CARD32	Tracking B32;       /**< Space between characters                       */
    CARD32	HangingIF B32;      /**< Hanging inhibit factor                         */
    CARD32	KerningIF B32;      /**< Kerning inhibit factor                         */
    CARD32	DecompositionIF B32; /**< Decomposition inhibit factor                  */
    CARD32	mask B32;           /**< Mask indicating which fields have been set     */
} xSTStyleGetOptionsReply;
#define sz_xSTStyleGetOptionsReply 44

/**
 * ST Style Set Options request
 *
 * The X_STStyleSetOptions request is used to set special kerning values for an STStyle 
 * object. 
 * The protocol Style is the XID value referring to the STStyle object to access. The
 * protocol  ImposeWidth is the width imposed on the style. The protocol BeforeWSS is the
 * amount to shift before the stream. The protocol AfterWSS is the amount to shift after
 * the stream. The protocol CrossSS is the cross stream shift. The protocol Tracking is
 * the amount of space between the characters. The protocol HangingIF is the hanging
 * inhibit factor. The protocol KerningIF is the kerning inhibit factor. The protocol
 * DecompositionIF is the decomposition inhibit factor. The protocol mask indicates which
 * of the values to were previously modified. The XServer calls STStyleSetOptions and
 * passes the STStyle object and the options. There is no response to this command. 
 *  
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleSetOptions              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32	ImposeWidth B32;    /**< Width imposed on the Style                     */
    CARD32	BeforeWSS B32;      /**< Amount to shift before the stream              */
    CARD32	AfterWSS B32;       /**< Amount to shift after the stream               */
    CARD32	CrossSS B32;        /**< Cross stream shift                             */
    CARD32	Tracking B32;       /**< Space between characters                       */
    CARD32	HangingIF B32;      /**< Hanging inhibit factor                         */
    CARD32	KerningIF B32;      /**< Kerning inhibit factor                         */
    CARD32	DecompositionIF B32; /**< Decomposition inhibit factor                  */
    CARD32	mask B32;           /**< Mask indicating which fields to set            */
} xSTStyleSetOptionsReq;
#define sz_xSTStyleSetOptionsReq 44


/**
 * @}
 */


/**
 * ST Style Set LayoutEngine request
 *
 * The X_STStyleSetLayoutEngine request is used to set the layout engine to use.
 * The protocol Style is the XID value referring to the STStyle object to set. The 
 * protocol LayoutEngine is the XID value referring to the STLayoutEngine object to 
 * associate with the STStyle. The protocol mask is the mask bits indicating which 
 * fields to set.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */ 
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleSetLayoutEngine         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
    CARD32      LayoutEngine B32;   /**< XSTLayoutEngine XID to use                     */
    CARD32	mask B32;           /**< Mask indicating which fields to set            */
} xSTStyleSetLayoutEngineReq;
#define sz_xSTStyleSetLayoutEngineReq 16

/**
 * ST Style Get LayoutEngine request
 *
 * The X_STStyleGetLayoutEngine request is used to get the layout engine in use.
 * The protocol Style is the XID value referring to the STStyle object to use.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle to use is not valid.
 * BadImplementation may be returned if the STStyle to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STStyleGetLayoutEngine         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Style B32;          /**< XSTStyle XID to use                            */
} xSTStyleGetLayoutEngineReq;
#define sz_xSTStyleGetLayoutEngineReq 8

/**
 * ST Style Get LayoutEngine reply
 *
 * The protocol LayoutEngine is the XID value referring to the STLayoutEngine object 
 * associated with the STStyle. The protocol mask is the mask bits indicating which
 * fields have been set.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      LayoutEngine B32;   /**< XSTLayoutEngine XID associated with Style      */
    CARD32	mask B32;           /**< Mask indicating the fields that have been set  */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
} xSTStyleGetLayoutEngineReply;
#define sz_xSTStyleGetLayoutEngineReply 32









/** @defgroup XSTText_Protocol XSTText Protocol messages
 * @{
 */


/**
 * ST Text New Copy request
 *
 * The X_STTextNewCopy request is used to create a new STText object and the XSTText XID 
 * value associated with it by copying an existing STText object.
 * The protocol OldText is the XID value referring to the existing STText object. The 
 * protocol NewText is the XID value requested for the STText structure. The XServer calls
 * STTextNewCopy and passes the STTypeEnv structure and the STText value referred to by
 * OldText. The function returns an STText object.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the Text object cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextNewCopy                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	OldText B32;        /**< XSTText XID referring to STText to copy        */
    CARD32	NewText B32;        /**< XSTText XID referring to new STText            */
} xSTTextNewCopyReq;
#define sz_xSTTextNewCopyReq 12

/**
 * ST Text New/New Empty request
 *
 * The X_STTextNew request is used to create a new STText object and the XSTText XID value
 * associated with it.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol Text is the XID value requested for the STText structure. The
 * protocol count contains the number of characters in the text string. For 
 * XSTTextNewEmpty, count is set to 0. The text string is appended onto the end of the 
 * request message in UTF-16 format. The XServer calls STTextNew and passes the STTypeEnv
 * structure, the text string, and the number of characters in the string. The function 
 * returns an STText object.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if the Text object cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextNew                      */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32      Text B32;           /**< XSTText XID referring to new STText            */
    CARD32      count B32;          /**< Number of utf16 characters in the string       */
} xSTTextNewReq;
#define sz_xSTTextNewReq 16

/**
 * ST Text Dispose request
 *
 * The X_STTextDispose request is used to free up memory used by an STText object and free
 * the resource ID used by the XSTText ID.
 * The protocol Text is the XID value referring to the STText object to dispose. The 
 * XServer calls STTextDispose and passes the STText value referred to by Text. There is 
 * no response to the XSTTextDispose command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextDispose                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to dispose     */
} xSTTextDisposeReq;
#define sz_xSTTextDisposeReq 8

/**
 * ST Text Clear request
 *
 * The X_STTextClear request is used to clear the attribute values of the STText object
 * referred to by the XSTText XID.
 * The protocol Text is the XID value referring to the STText object to clear. The XServer
 * calls STTextClear and passes the STText value referred to by Text. There is no response
 * to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextClear                    */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to clear       */
} xSTTextClearReq;
#define sz_xSTTextClearReq 8

/**
 * ST Text Set Metrics request
 *
 * The X_STTextSetMetrics request is used to set the metric attribute values of the STText
 * object referred to by the XSTText XID.
 * The protocol Text is the XID value referring to the STText object to set. The protocol
 * TextWidth is a double that represents the width of the text in points. The protocol
 * Ascent is a double that represents the maximum Ascent of any character in the text
 * string. The protocol Descent is a double that represents the maximum Descent of any
 * character in the text string. The protocol Leading is a double that represents the
 * leading between text regions. The protocol count is the number of baselines appened
 * to the end of the request. The protocol mask identifies which baselines are appended
 * to the end of the request. The XServer calls STTextSetMetrics and passes
 * the STText value referred to by Text, and the metric information. There is no response
 * to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextSetMetrics               */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to set         */
    CARD64	TextWidth;          /**< Width of text in points                        */
    CARD64	Ascent;             /**< Maximum Ascent of any character in text        */
    CARD64	Descent;            /**< Maximum Descent of any character in text       */
    CARD64	Leading;            /**< Leading between line                           */
    CARD32      count B32;          /**< Number of baselines appended to request        */
    CARD32      mask B32;           /**< Indicates which baselines are appended         */
    CARD32      TextMask B32;       /**< Indicates which of the metrics to set          */
    CARD32      pad B32;
} xSTTextSetMetricsReq;
#define sz_xSTTextSetMetricsReq 56

/**
 * ST Text Get Metrics request
 *
 * The X_STTextGetMetrics request is used to get the metric attribute values of the STText
 * object referred to by the XSTText XID. This metric information is imposed information
 * set by the XSTTextSetMetrics command.
 * The protocol Text is the XID value referring to the STText object to check. The XServer
 * calls STTextSetMetrics and passes the STText value referred to by Text. The command
 * returns the metric information stored in the STText.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextGetMetrics               */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
    CARD32      mask B32;           /**< Indicates which fields to return               */
} xSTTextGetMetricsReq;
#define sz_xSTTextGetMetricsReq 12

/**
 * ST Text Get Metrics reply
 *
 * The protocol response TextWidth is a double that represents the width of the text in
 * points. The protocol response Ascent is a double that represents the maximum Ascent of
 * any character in the text string. The protocol response Descent is a double that
 * represents the maximum Descent of any character in the text string. The protocol
 * response Leading is a double that represents the leading between text regions. The
 * protocol response count is the number of baselines returned at the end of the 
 * protocol response. The protocol mask is the mask of which baselines are returned.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64	TextWidth;          /**< Width of text in points                        */
    CARD64	Ascent;             /**< Maximum Ascent of any character in text        */
    CARD64	Descent;            /**< Maximum Descent of any character in text       */
    CARD64	Leading;            /**< Leading between line                           */
    CARD32	count B32;          /**< Number of baselines appended to end of reply   */
    CARD32	mask B32;           /**< Indicates which baseline values are returned   */
    CARD32      TextMask B32;       /**< Indicates which of the metrics are set         */
    CARD32      pad B32;            /**< Not used                                       */
} xSTTextGetMetricsReply;
#define sz_xSTTextGetMetricsReply 56

/**
 * ST Text Set Controls request
 * 
 * The X_STTextSetControls request is used to set the attribute values of the STText
 * object referred to by the XSTText XID. These attributes pertain to direction of the
 * text, it's justification, the language present in the text and Font Fallback overrides.
 * The protocol Text is the XID value referring to the STText object to modify. The
 * protocol Direction represents the direction of text layout. The protocol Justification
 * represents the justification used on the text. The protocol FlushFactor represents the
 * degree to which the text is Flush with the margins. The protocol Language represents
 * the language ID value referring to the input method to use for this text region. The
 * protocol Policy represents the font fallback policy override for the text region. The
 * protocol mask tells ST which of the controls to set. The XServer calls
 * STTextSetControls and passes the STText value referred to by Text, the controls, and
 * the mask. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextSetControls              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
    CARD32      Direction B32;      /**< Direction of text flow                         */
    CARD32      Justification B32;  /**< Justification of the text                      */
    CARD32      FlushFactor B32;    /**< Degree to which text is flush with the margins */
    CARD32      Language B32;       /**< Language of the text                           */
    CARD32      Policy B32;         /**< Font Fallback Policy                           */
    CARD32	mask B32;           /**< Mask identifying which fields to set           */
} xSTTextSetControlsReq;
#define sz_xSTTextSetControlsReq 32

/**
 * ST Text Get Controls request
 *
 * The X_STTextGetControls request is used to get the attribute values of the STText 
 * object referred to by the XSTText XID. These attributes pertain to direction of the 
 * text, it's justification, the language present in the text and Font Fallback overrides.
 * The protocol Text is the XID value referring to the STText object to modify. The 
 * XServer calls STTextGetControls and passes the STText value referred to by Text. The 
 * command returns the controls along with a mask indicating which of the controls have 
 * been set for this STText object.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */ 
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextGetControls              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
    CARD32      mask B32;           /**< Indicates which fields to return               */
} xSTTextGetControlsReq;
#define sz_xSTTextGetControlsReq 12

/**
 * ST Text Get Controls reply
 *
 * The protocol response Direction represents the direction of text layout. The protocol
 * response Justification represents the justification used on the text. The protocol
 * response FlushFactor represents the degree to which the text is Flush with the margins.
 * The protocol response Language represents the language ID value referring to the input
 * method to use for this text region. The protocol response Policy represents the font
 * fallback policy override for the text region. The protocol response mask
 * indicates which of these controls was previously set. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Direction B32;      /**< Direction of text flow                         */
    CARD32      Justification B32;  /**< Justification of the text                      */
    CARD32      FlushFactor B32;    /**< Degree to which text is flush with the margins */
    CARD32      Language B32;       /**< Language of the text                           */
    CARD32      Policy B32;         /**< Font Fallback Policy                           */
    CARD32	mask B32;           /**< Mask identifying which fields have been set    */
} xSTTextGetControlsReply;
#define sz_xSTTextGetControlsReply 32

/**
 * ST Text Set Font Fallbacks request
 *
 * The X_STTextSetFontFallbacks request is used to set the override the STTypeEnv Font 
 * fallback  values for the STText object referred to by the XSTText XID. 
 * The protocol Text is the XID value referring to the STText object to modify. The
 * protocol count represents the number of font fallback Font IDs are appended onto the
 * end of the request. The XServer calls STTextSetControls and passes the STText value
 * referred to by Text, the Font Fallback Font IDs, and the number of Font IDs. There is
 * no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextSetFontFallbacks         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
    CARD32      count B32;          /**< Number of XSTFont IDs in fallback list         */
} xSTTextSetFontFallbacksReq;
#define sz_xSTTextSetFontFallbacksReq 12

/**
 * ST Text Get Font Fallbacks request
 *
 * The X_STTextGetFontFallbacks request is used to get the override the STTypeEnv Font
 * fallback  values for the STText object referred to by the XSTText XID. 
 * The protocol Text is the XID value referring to the STText object to modify. The
 * XServer calls STTextGetControls and passes the STText value referred to by Text. The
 * command returns a list of Font Fallback Font IDs, and the number of Font IDs.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextGetFontFallbacks         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
} xSTTextGetFontFallbacksReq;
#define sz_xSTTextGetFontFallbacksReq 8

/**
 * ST Text Get Font Fallbacks reply
 * 
 * The protocol response count represents the number of font fallback Font IDs. These Font
 * IDs are appended onto the end of the response. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of XSTFont IDs in fallback list         */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
    CARD32      pad5 B32;           /**< Not used                                       */
} xSTTextGetFontFallbacksReply;
#define sz_xSTTextGetFontFallbacksReply 32

/**
 * ST Text Copy Attributes request
 * 
 * The X_STTextCopyAttributes request is used to copy the metrics, controls, and fallbacks
 * from one STText object to another. Both STText objects are referred to by the XSTText
 * XIDs. 
 * The protocol FromText is the XID value referring to the STText object to copy. The 
 * protocol ToText is the XID value referring to the STText object to modify. The protocol
 * mask dictates the portions of the FromText object to copy over to the ToText object.
 * The XServer calls STTextCopyAttributes and passes the two STText objects, and the mask.
 * There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextCopyAttributes           */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      FromText B32;       /**< XSTText XID referring to STText to copy from   */
    CARD32	ToText B32;         /**< XSTText XID referring to STText to copy to     */
    CARD32	mask B32;           /**< Mask identifying fields to copy                */
} xSTTextCopyAttributesReq;
#define sz_xSTTextCopyAttributesReq 16

/**
 * ST Text Clear Attibutes request
 *
 * The X_STTextRemoveAttributes request is used to reset the metrics, controls, and 
 * fallbacks of an STText object referred to by the XSTText XID. 
 * The protocol Text is the XID value referring to the STText object to reset. The 
 * protocol mask dictates the portions of the Text object to reset. The XServer calls 
 * STTextRemoveAttributes and passes the STText object referred to by Text, and the mask. 
 * There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextRemoveAttributes          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
    CARD32	mask B32;           /**< Mask identifying fields to reset               */
} xSTTextRemoveAttributesReq;
#define sz_xSTTextRemoveAttributesReq 12

/**
 * ST Text Reset Attibutes request
 *
 * The X_STTextResetAttributes request is used to reset the metrics, controls, and 
 * fallbacks of an STText object referred to by the XSTText XID. 
 * The protocol Text is the XID value referring to the STText object to reset. The 
 * protocol mask dictates the portions of the Text object to reset. The XServer calls 
 * STTextResetAttributes and passes the STText object referred to by Text, and the mask. 
 * There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextResetAttributes          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
    CARD32	mask B32;           /**< Mask identifying fields to reset               */
} xSTTextResetAttributesReq;
#define sz_xSTTextResetAttributesReq 12

/**
 * ST Text Set Text request
 *
 * The X_STTextSetText request is used to set the text string of an STText object referred
 * to by the XSTText XID. The STText object only contains a pointer to the text.
 * The protocol Text is the XID value referring to the STText object to modify. The 
 * protocol CharCount represents the number of characters attached onto the end of the 
 * request message. The XServer calls STTextGetText and frees the old text string. The 
 * XServer then calls STTextSetText and passes the STText object referred to by Text, the
 * string of characters, and the number of character in the string. There is no response 
 * to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextSetText                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
    CARD32	CharCount B32;      /**< Number of UTF16 characters to set in text      */
} xSTTextSetTextReq;
#define sz_xSTTextSetTextReq 12

/**
 * ST Text Get Text request
 *
 * The X_STTextGetText request is used to get the text string of an STText object referred
 * to by the XSTText XID.
 * The protocol Text is the XID value referring to the STText object to query. The XServer
 * calls STTextSetText and passes the STText object referred to by Text. The command
 * returns a pointer to the text string, and the number of characters in the string. The
 * XServer calls STIntCountUTF16Bytes to get the number of bytes used by the string.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextGetText                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
} xSTTextGetTextReq;
#define sz_xSTTextGetTextReq 8

typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	CharCount B32;      /**< Number of UTF16 character in text              */
    CARD32	bytes B32;          /**< Number of bytes used by string                 */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
} xSTTextGetTextReply;
#define sz_xSTTextGetTextReply 32

/**
 * ST Text Update request
 *
 * The X_STTextUpdate request is used to change the text string of an STText object
 * referred to by the XSTText XID.
 * The protocol Text is the XID value referring to the STText object to modify. The
 * protocol Change indicates the type of change to perform, Insert, Remove, Exchange. The
 * protocol TextOffset marks the beginning character of the text to change. The protocol
 * TextLength indicates the amount of text to change. The XServer calls STTextUpdate and
 * passes the STText object referred to by Text, the offset and length, and the string
 * that is modified. There is no response to this command. On some occasions, if the
 * reallocation of space for the string does not result in a string at the same memory
 * position, then the X-server call STTextSetText instead.

 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid or the TextOffset is
 *  greater than the current length of the text, or TextLength is greater than the current
 *  length of the text and a Remove or Exchange request is performed.
 * BadImplementation may be returned if the STText to use is NULL.
 * BadAlloc may be returned if space for the additional text cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextUpdate                   */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to STText to use         */
    CARD32	Change B32;         /**< Type of change being performed. IE: delete     */
    CARD32	TextOffset B32;     /**< Starting character of change                   */
    CARD32	TextLength B32;     /**< Number of characters associated with change    */
} xSTTextUpdateReq;
#define sz_xSTTextUpdateReq 20

/**
 * ST Text Augment Style request
 *
 * The X_STTextAugmentStyle request is used to add fields set in the supplied style to
 * any styles present in the region of characters.
 * The protocol Text is the XID value referring to the STText object to modify. The 
 * protocol Style is the supplied XSTStyle XID referring to an STStyle object. The 
 * protocol FirstChar is the first character whose STStyle is to be augmented. The 
 * protocol CharCount is the number of characters whose STStyle objects are to be 
 * augmented.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid or the FirstChar is
 *  greater than the current length of the text, or CharCount is greater than the current
 *  length of the text.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextAugmentStyle             */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32	Style B32;          /**< XSTStyle XID referring to the STStyle to use   */
    CARD32	FirstChar B32;      /**< Starting character of change                   */
    CARD32	CharCount B32;      /**< Number of characters associated with change    */
} xSTTextAugmentStyleReq;
#define sz_xSTTextAugmentStyleReq 20

/**
 * ST Text Overwrite Style request
 *
 * The X_STTextOverwriteStyle request is used to change fields in the covered STStyle
 * objects that are set in the supplied STStyle object.
 * The protocol Text is the XID value referring to the STText object to modify. The 
 * protocol Style is the supplied XSTStyle XID referring to an STStyle object. The 
 * protocol FirstChar is the first character whose STStyle is to be changed. The protocol
 * CharCount is the number of characters whose STStyle objects are to be changed.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid or the FirstChar is
 *  greater than the current length of the text, or CharCount is greater than the current
 *  length of the text.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextOverwriteStyle           */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32	Style B32;          /**< XSTStyle XID referring to the STStyle to use   */
    CARD32	FirstChar B32;      /**< Starting character of change                   */
    CARD32	CharCount B32;      /**< Number of characters associated with change    */
} xSTTextOverwriteStyleReq;
#define sz_xSTTextOverwriteStyleReq 20

/**
 * ST Text Underwrite Style request
 *
 * The X_STTextUnderwriteStyle request is used to change fields in the covered STStyle
 * objects that are not set in the supplied STStyle object.
 * The protocol Text is the XID value referring to the STText object to modify. The 
 * protocol Style is the supplied XSTStyle XID referring to an STStyle object. The 
 * protocol FirstChar is the first character whose STStyle is to be changed. The protocol
 * CharCount is the number of characters whose STStyle objects are to be changed.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid or the FirstChar is
 *  greater than the current length of the text, or CharCount is greater than the current
 *  length of the text.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextUnderwriteStyle          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32	Style B32;          /**< XSTStyle XID referring to the STStyle to use   */
    CARD32	FirstChar B32;      /**< Starting character of change                   */
    CARD32	CharCount B32;      /**< Number of characters associated with change    */
} xSTTextUnderwriteStyleReq;
#define sz_xSTTextUnderwriteStyleReq 20

/**
 * ST Text Set Style request
 *
 * The X_STTextSetStyle request is used to associate an STStyle, referred to by the 
 * XSTStyle XID, with a section of STText, referred to by the XSTText XID.
 * The protocol Text is the XID value referring to the STText object to modify. The 
 * protocol Style is the XID value referring to the STStyle object to use. The protocol 
 * FirstChar marks the first character of the STText object that the STStyle object 
 * applies to. The protocol CharCount indicates the number of characters of the STText 
 * object that the STStyle object applies to. The XServer calls STTextSetStyle and passes
 * the STText object referred to by Text, the STStyle object referred to by Style, the 
 * offset and length. There is no response to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTStyle or XSTText to use is not valid.
 * BadImplementation may be returned if the STStyle or STText to use is
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextSetStyle                 */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32	Style B32;          /**< XSTStyle XID referring to the STStyle to use   */
    CARD32	FirstChar B32;      /**< Starting character of change                   */
    CARD32	CharCount B32;      /**< Number of characters associated with change    */
} xSTTextSetStyleReq;
#define sz_xSTTextSetStyleReq 20

/**
 * ST Text Get Style request
 *
 * The X_STTextGetStyle request is used to get an XSTStyle XID, referring to the STStyle
 * object, that applies to a specific location of text in the STText object, referred to
 * by the XSTText XID.
 * The protocol Text is the XID value referring to the STText object to check. The 
 * protocol Position indicates the character location in the text string to check. The 
 * XServer calls STTextGetStyle and passes the STText object referred to by Text, and the
 * Position to check. The function returns an STStyle value that includes the Position
 * within it's coverage of the STText object along with it's start and length. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextGetStyle                 */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32	Position B32;       /**< Character position within text to get STStyle  */
} xSTTextGetStyleReq;
#define sz_xSTTextGetStyleReq 12

/**
 * ST Text Get Style reply
 *
 * The protocol response Style is the XSTStyle XID that refers to the STStyle object 
 * returned. The protocol response FirstChar marks the first character of the STText 
 * object that the STStyle object applies to. The protocol response CharCount indicates 
 * the number of characters of the STText object that the STStyle object applies to. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	Style B32;          /**< XSTStyle XID referring to STStyle found        */
    CARD32	FirstChar B32;      /**< First character in STText where STStyle starts */
    CARD32	CharCount B32;      /**< Number of characters in STText STStyle covers  */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
} xSTTextGetStyleReply;
#define sz_xSTTextGetStyleReply 32

/**
 * ST Text Get Common Style request
 *
 * The X_STTextGetCommonStyle request is used to get an XSTStyle XID, referring to a new
 * STStyle object, that represents the Style common to a section of text in the STText
 * object, referred to by the XSTText XID. This new style may include information from
 * several styles, or a single style.
 * The protocol Text is the XID value referring to the STText object to check. The
 * protocol Position indicates the first character location in the text string to check.
 * The protocol CharCount indicates the number of characters in the text string to check.
 * The XServer calls STTextGetCommonStyle and passes the STText object referred to by
 * Text,  the Position to begin the check and CharCount for the number of characters to
 * check. The function returns an STStyle value that contains all of the elements of the
 * styles found that are the same. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 * BadAlloc may be returned if space for the new STStyle cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextGetCommonStyle           */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32	Position B32;       /**< Character position within text to get STStyle  */
    CARD32	CharCount B32;      /**< Number of characters in text to create STStyle */
} xSTTextGetCommonStyleReq;
#define sz_xSTTextGetCommonStyleReq 16

/**
 * ST Text Get Common Style reply
 *
 * The protocol response Style is the XSTStyle XID that refers to the new STStyle object 
 * returned. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	Style B32;          /**< XSTStyle XID referring to STStyle found        */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTextGetCommonStyleReply;
#define sz_xSTTextGetCommonStyleReply 32

/**
 * ST Text Find Missing Chars request
 *
 * The X_STTextFindMissingChars request is used to find which character positions within
 * an STText object do not have coverage by the font contained in the STStyle that is
 * associated with it, or by one of the Font Fallbacks in the STText or STTypeEnv objects.
 * The command returns a collection of offset, length pairs indicating the characters that
 * cannot be displayed.
 * The protocol Text is the XID value referring to the STText object to check. The XServer
 * calls STTextFindMissingChars and passes the STText object referred to by Text. The
 * function returns a list of offset, length pairs and the number of pairs.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextFindMissingChars         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
} xSTTextFindMissingCharsReq;
#define sz_xSTTextFindMissingCharsReq 8

/**
 * ST Text Find Missing Chars reply
 *
 * The protocol response count is the number of pairs returned. The pairs are appended 
 * onto the end of the response message. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      count B32;          /**< Number of offset, length pairs returned        */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
    CARD32      pad5 B32;           /**< Not used                                       */
} xSTTextFindMissingCharsReply;
#define sz_xSTTextFindMissingCharsReply 32


/**
 * ST Text Get Styled Glyphs request
 *
 * The X_STTextGetStyledGlyphs request is used to get an array of styled glyphs from
 * the line object referred to by the XSTText XID. 
 * The protocol Text is the XID value referring to the STText object to use. The protocol
 * Position is the first character to begin retrieving glyph information from. The
 * protocol CharCount is the number of characters to retrieve glyph information for.
 * The XServer calls STTextGetStyledGlyphs and passes the STText object referred to by
 * Text. The function returns the metric information about the line that was set by the 
 * font.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STTextGetStyledGlyphs         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32      Position B32;       /**< Char Position within Text to get glyphs from   */
    CARD32      CharCount B32;      /**< Number of characters to get glyphs for         */
} xSTTextGetStyledGlyphsReq;
#define sz_xSTTextGetStyledGlyphsReq 16

/**
 * ST Text Get Design Metrics reply
 *
 * The protocol response GlyphCount indicates the number of the styled glyphs appended
 * to the end of the response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	GlyphCount B32;     /**< Number of styled glyphs in return message      */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTTextGetStyledGlyphsReply;
#define sz_xSTTextGetStyledGlyphsReply 32


/**
 * @}
 */





/** @defgroup XSTLine_Protocol XSTLine Protocol messages
 * @{
 */


/**
 * ST Line New For Width request
 *
 * The X_STLineNewForWidth request is used to create a new STLine object and return an
 * XSTLine XID value to the client along with the length of the new STLine. The new STLine
 * object is to use the most characters that will fit in Width points.
 * The protocol Text is the XID value referring to the STText object for which to create
 * the line. The protocol Line is the XID value the client is requesting. The protocol
 * Width is the width in points of the new Line. The protocol Position is the first
 * character position of the new STLine object. The XServer calls STLineNewForWidth and
 * passes the STText object referred to by Text, the Position and the Width values. The
 * function returns an STLine object along with the number of characters that were able to
 * fit into the STLine.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 * BadAlloc may be returned if the new STLine object cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineNewForWidth              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the new STLine        */
    CARD64	Width;              /**< Width of STLine in points                      */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32      Position B32;       /**< Position of the first character within STText  */
} xSTLineNewForWidthReq;
#define sz_xSTLineNewForWidthReq 24

/**
 * ST Line New request
 *
 * The X_STLineNew request is used to create a new STLine object and return an XSTLine XID
 * value to the client along with the length of the new STLine.
 * The protocol Text is the XID value referring to the STText object for which to create
 * the line. The protocol Line is the XID value the client is requesting. The protocol
 * Position is the first character position of the new STLine object. The protocol
 * CharCount is the number of characters requested to be in the line. The XServer calls
 * STLineNew and passes the STText object referred to by Text, the Position and the
 * CharCount values. The function returns an STLine object along with the number of
 * characters that were able to fit into the STLine. In general, the number of characters
 * added to the line will equal the number of characters requested, unless there are not
 * enough characters in the STText to satisfy the request.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTText to use is not valid.
 * BadImplementation may be returned if the STText to use is NULL.
 * BadAlloc may be returned if the new STLine object cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineNew                      */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the new STLine        */
    CARD32      Text B32;           /**< XSTText XID referring to the STText to use     */
    CARD32      Position B32;       /**< Position of the first character within STText  */
    CARD32      CharCount B32;      /**< Number of characters contained in STLine       */
} xSTLineNewReq;
#define sz_xSTLineNewReq 20

/**
 * ST Line New/New For Width reply
 *
 * The protocol response Line is the XSTLine XID associated with the new STLine object.
 * The protocol response CharCount is the number of characters placed in the STLine.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Line B32;           /**< XSTLine XID associated with new STLine object  */
    CARD32      CharCount B32;      /**< Number of characters placed in STLine object   */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
} xSTLineNewReply;
#define sz_xSTLineNewReply 32

/**
 * ST Line Dispose request
 *
 * The X_STLineDispose request is used to free an existing STLine object and its XSTLine
 * XID.
 * The protocol Line is the XID value referring to the STLine object to dispose of. The
 * XServer calls STLineDispose and passes the STLine object referred to by Line. The
 * function has no response.

 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineDispose                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to new STLine to use     */
} xSTLineDisposeReq;
#define sz_xSTLineDisposeReq 8

/**
 * ST Line Grow request
 *
 * The X_STLineGrow request is used to increase the number of characters in an existing
 * STLine object referred to by an XSTLine XID.
 * The protocol Line is the XID value referring to the STLine object to grow. The protocol
 * Position indicates the beginning or ending of the line of text. The protocol CharCount
 * is the number of characters to add to the STLine. The XServer calls STLineGrow and
 * passes the STLine object referred to by Line, the Position and CharCount. The function
 * has no response.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineGrow                     */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32      Position B32;       /**< Flag to indicate Left or Right side of STLine  */
    CARD32      CharCount B32;      /**< Number of characters to add to STLine          */
} xSTLineGrowReq;
#define sz_xSTLineGrowReq 16

/**
 * ST Line Shrink request
 *
 * The X_STLineShrink request is used to decrease the number of characters in an existing
 * STLine object referred to by an XSTLine XID.
 * The protocol Line is the XID value referring to the STLine object to shrink. The
 * protocol Position indicates the beginning or ending of the line of text. The protocol
 * CharCount is the number of characters to remove from the STLine. The XServer calls
 * STLineShrink and passes the STLine object referred to by Line, the Position and
 * CharCount. The function has no response.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineShrink                   */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32      Position B32;       /**< Flag to indicate Left or Right side of STLine  */
    CARD32      CharCount B32;      /**< Number of characters to remove from STLine     */
} xSTLineShrinkReq;
#define sz_xSTLineShrinkReq 16

/**
 * ST Line Get Offset request
 *
 * The X_STLineGetOffset request is used to find which characters are in an existing 
 * STLine object referred to by an XSTLine XID.
 * The protocol Line is the XID value referring to the STLine object to check. The XServer
 * calls STLineGetOffset and passes the STLine object referred to by Line. The function
 * returns the position of the first character in the line, and the number of characters
 * in the line. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineGetOffset                */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
} xSTLineGetOffsetReq;
#define sz_xSTLineGetOffsetReq 8

/**
 * ST Line Get Offset reply
 *
 * The protocol response Position is set to the first character in the line. The protocol
 * response CharCount is the number of characters in the STLine. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32      Position B32;       /**< First character location within STText         */
    CARD32      CharCount B32;      /**< Number of characters in STLine                 */
    CARD32      pad1 B32;           /**< Not used                                       */
    CARD32      pad2 B32;           /**< Not used                                       */
    CARD32      pad3 B32;           /**< Not used                                       */
    CARD32      pad4 B32;           /**< Not used                                       */
} xSTLineGetOffsetReply;
#define sz_xSTLineGetOffsetReply 32

/**
 * ST Line Set Metrics request
 *
 * The X_STLineSetMetrics request is used to set the metrics for STLine object referred to
 * by the XSTLine XID. These metrics will override the metrics imposed by the STText
 * object.
 * The protocol Line is the XID value referring to the STLine object to modify. The
 * protocol LineWidth is a double that indicates the width of the line in points. The
 * protocol Ascent is a double that indicates the maximum ascent of any character in the
 * line. The protocol Descent is a double that indicates the maximum descent of any
 * character in the line. The protocol Leading is a double that indicates the leading
 * value to be used after this line. The protocol count is the number of baselines
 * appended to the end of the request. The protocol base indicates which baselines
 * are appended to the end. The XServer calls STLineSetMetrics and passes the
 * STLine object referred to by Line, along with the metric values. There is no response
 * to this command.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineSetMetrics               */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD64      LineWidth;          /**< Maximum width of STLine in points              */
    CARD64	Ascent;             /**< Maximum Ascent of any character in text        */
    CARD64	Descent;            /**< Maximum Descent of any character in text       */
    CARD64	Leading;            /**< Leading between line                           */
    CARD32      count B32;          /**< Number of baselines appended to end of request */
    CARD32      mask B32;           /**< Identifies which baselines are appened         */
    CARD32      TextMask B32;       /**< Indicates which of the metrics are set         */
    CARD32      pad B32;
} xSTLineSetMetricsReq;
#define sz_xSTLineSetMetricsReq 56

/**
 * ST Line Get Metrics request
 *
 * The X_STLineGetMetrics request is used to get the metrics for STLine object referred to
 * by the XSTLine XID. These metrics need to have been set with the XSTLineSetMetrics  
 * command previously.
 * The protocol Line is the XID value referring to the STLine object to use. The XServer 
 * calls STLineGetMetrics and passes the STLine object referred to by Line. The function  
 * returns the metric information about the line that was set previously.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineGetMetrics               */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32      mask B32;           /**< Identifies which fields to return              */
} xSTLineGetMetricsReq;
#define sz_xSTLineGetMetricsReq 12

/**
 * ST Line Get Metrics reply
 *
 * The protocol response LineWidth is a double that indicates the width of the line in
 * points. The protocol response Ascent is a double that indicates the maximum ascent of
 * any character in the line. The protocol response Descent is a double that indicates the
 * maximum descent of any character in the line. The protocol response Leading is a double
 * that indicates the leading value to be used after this line. The protocol response
 * count is the number of baselines returned at the end of the protocol response. The 
 * protocol mask is the mask of which baselines are returned.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64      LineWidth;          /**< Maximum width of STLine in points              */
    CARD64	Ascent;             /**< Maximum Ascent of any character in text        */
    CARD64	Descent;            /**< Maximum Descent of any character in text       */
    CARD64	Leading;            /**< Leading between line                           */
    CARD32	count B32;          /**< Number of baselines attached to end of reply   */
    CARD32	mask B32;           /**< Identifies which baseline values are attached  */
    CARD32      TextMask B32;       /**< Indicates which of the metrics are set         */
    CARD32      pad B32;
} xSTLineGetMetricsReply;
#define sz_xSTLineGetMetricsReply 56

/**
 * ST Line Measure Text request
 *
 * The X_STLineMeasureText request is used to get a bounding rectangle around an STLine
 * object referred to by the XSTLine XID.
 * The protocol Line is the XID value referring to the STLine object to use. The XServer
 * calls STLineMeasureText and passes the STLine object referred to by Line. The function
 * returns a rectangular bounding box around the text. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineMeasureText              */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
} xSTLineMeasureTextReq;
#define sz_xSTLineMeasureTextReq 8

/**
 * ST Line Measure Text reply
 *
 * The protocol response ax is a double that is the upper left X value. The protocol
 * response ay is a double that is the upper left Y value. The protocol response bx is a
 * double that is the lower right X value. The protocol response by is a double that is
 * the lower right Y value. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64      ax;                 /**< Upper left X value                             */
    CARD64      ay;                 /**< Upper left Y value                             */
    CARD64      bx;                 /**< Lower right X value                            */
    CARD64      by;                 /**< Lower right Y value                            */
} xSTLineMeasureTextReply;
#define sz_xSTLineMeasureTextReply 40

/**
 * ST Line Measure Text Image request
 *
 * The X_STLineMeasureTextImage request is used to get a bounding rectangle around an
 * STLine object referred to by the XSTLine XID. This command differs from
 * X_STLineMeasureText because it uses the imposed justification, flush factor and other
 * values that affect the output positioning.
 * The protocol Line is the XID value referring to the STLine object to use. The XServer
 * calls STLineMeasureTextImage and passes the STLine object referred to by Line. The
 * function returns a rectangular bounding box around the text. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineMeasureTextImage         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
} xSTLineMeasureTextImageReq;
#define sz_xSTLineMeasureTextImageReq 8

/**
 * ST Line Measure Text Image reply
 * 
 * The protocol response ax is a double that is the upper left X value. The protocol
 * response ay is a double that is the upper left Y value. The protocol response bx is a
 * double that is the lower right X value. The protocol response by is a double that is
 * the lower right Y value. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64      ax;                 /**< Upper left X value                             */
    CARD64      ay;                 /**< Upper left Y value                             */
    CARD64      bx;                 /**< Lower right X value                            */
    CARD64      by;                 /**< Lower right Y value                            */
} xSTLineMeasureTextImageReply;
#define sz_xSTLineMeasureTextImageReply 40

/**
 * ST Line Get Glyph Bounds request
 *
 * The X_STLineGetGlyphBounds request is used to get a bounding rectangle around an STLine
 * object referred to by the XSTLine XID.
 * The protocol Line is the XID value referring to the STLine object to use. The protocol
 * gc is the GC containing the transformation matrix to use. The protocol MaxBoundsCount
 * indicates the maximum number of bounding boxes to return. The protocol BoundsType
 * indicates the type of bounding boxes to obtain. The XServer calls STLineGetGlyphBounds
 * and passes the STLine object referred to by Line, the STGraphics held in the GC, the
 * MaxBoundsCount, and the BoundsType. The function returns a list of trapezoidal bounding
 * boxes around the text and the number of trapezoids returned.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine or GC to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 * BadAlloc may be returned if the response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineGetGlyphBounds           */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32      gc B32;             /**< Graphics Context                               */
    CARD32      MaxBoundsCount B32; /**< Maximum number of bounds to return             */
    CARD32      Bounds B32;         /**< Type of bounding box to obtain. IE: caret      */
} xSTLineGetGlyphBoundsReq;
#define sz_xSTLineGetGlyphBoundsReq 20

/**
 * ST Line Get Glyph Bounds reply
 *
 * The protocol response BoundsCount is the number of trapezoids that will be returned. 
 * The trapezoids are appended onto the end of the response message.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	BoundsCount B32;    /**< Number of bounding trapezoids returned         */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTLineGetGlyphBoundsReply;
#define sz_xSTLineGetGlyphBoundsReply 32

/**
 * ST Line Hit Test request
 *
 * The X_STLineHitTest request is used to get a character position within an STLine object
 * referred to by the XSTLine XID based on an X, Y coordinate.
 * The protocol Line is the XID value referring to the STLine object to use. The protocol
 * X is the X value that is within the scope of the line. The protocol Y is the Y value
 * that is within the scope of the line. The XServer calls STLineHitTest and passes the
 * STLine object referred to by Line, and the X and Y values. The function returns the
 * primary offset, secondary offset, and the IsLeading flag. The protocol response POffset
 * is the primary character offset into the text. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineHitTest                  */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD64	X;                  /**< X Position                                     */
    CARD64	Y;                  /**< Y Position                                     */
} xSTLineHitTestReq;
#define sz_xSTLineHitTestReq 24

/**
 * ST Line Hit Test reply
 * 
 * The protocol response POffset is the primary character offset into the text. The
 * protocol response IsLeading indicates which offset to use depending on the bidi status
 * of the line. The protocol response SOffset is the secondary character offset into the
 * text and is used for bidi text.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	POffset B32;        /**< Primary Offset into STText                     */
    CARD32	IsLeading B32;      /**< Flag Indicates the type of Caret produced      */
    CARD32	SOffset B32;        /**< Secondary offset int STText                    */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
} xSTLineHitTestReply;
#define sz_xSTLineHitTestReply 32

/**
 * ST Line Position To Caret request
 *
 * The X_STLinePositionToCaret request is used to get a caret based on a character
 * position within an STLine object referred to by the XSTLine XID.
 * The protocol Line is the XID value referring to the STLine object to use. The protocol
 * Position is the character that the cursor is position at within the line. The protocol
 * IsLeading is the type of caret to produce. The XServer calls STLinePositionToCaret and
 * passes the STLine object referred to by Line, and the Position and IsLeading values.
 * The function returns the two Strong Caret points, and the two Weak Caret points.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLinePositionToCaret          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32	Position B32;       /**< Position within text to get Caret              */
    CARD32	IsLeading B32;      /**< Type of Caret to return                        */
} xSTLinePositionToCaretReq;
#define sz_xSTLinePositionToCaretReq 16

/**
 * ST Line Position to Caret reply
 *
 * The protocol response SCax and SCay are one of the points of the Strong Caret. The
 * protocol response SCbx and SCby are the second point of the Strong Caret. The protocol
 * response WCax and WCay are the first point of the Weak Caret. The protocol response
 * WCbx and WCby are the second point of the Weak Caret. The protocol response SplitCenter
 * indicates that the caret splits the center of a compound glyph.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64	SCax;               /**< Strong Caret upper X value                     */
    CARD64	SCay;               /**< Strong Caret upper Y value                     */
    CARD64	SCbx;               /**< Strong Caret lower X value                     */
    CARD64	SCby;               /**< Strong Caret lower Y value                     */
    CARD64	WCax;               /**< Weak Caret upper X value                       */
    CARD64	WCay;               /**< Weak Caret upper Y value                       */
    CARD64	WCbx;               /**< Weak Caret lower X value                       */
    CARD64	WCby;               /**< Weak Caret lower Y value                       */
    CARD32	SplitCenter B32;    /**< Split Caret                                    */
    CARD32      pad1 B32;           /**< Not used                                       */
} xSTLinePositionToCaretReply;
#define sz_xSTLinePositionToCaretReply 80

/**
 * ST Line Move Caret request
 *
 * The X_STLineMoveCaret request is used to move the caret around an STLine object
 * referred to by the XSTLine XID.
 * The protocol Line is the XID value referring to the STLine object to use. The protocol
 * Offset is the character that the cursor is position at within the line. The protocol
 * Direction is the direction to move the caret within the line. The protocol Movement is
 * the distance to move the caret. The XServer calls STLineMoveCaret and passes the STLine
 * object referred to by Line, the Offset, the Direction and Movement values. The function
 * returns the new position within the Line. 
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineMoveCaret                */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32	Offset B32;         /**< Current cursor position within STLine          */
    CARD32	Direction B32;      /**< Direction to move cursor                       */
    CARD32	Movement B32;       /**< Amount to move cursor. IE: clustor, character  */
} xSTLineMoveCaretReq;
#define sz_xSTLineMoveCaretReq 20

/**
 * ST Line Move Caret reply
 * 
 * The protocol response Offset stores the new position of the caret.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	Offset B32;         /**< New position of the caret                      */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTLineMoveCaretReply;
#define sz_xSTLineMoveCaretReply 32

/**
 * ST Line Render request
 *
 * The X_STLineRender request is used to render an STLine object referred to by the
 * XSTLine XID. STLineRender requires data values to be set, including callbacks for
 * Rendering, Highlighting, Underlining, and Strikethrough. 
 * The protocol Line is the XID value referring to the STLine object to use. The protocol
 * gc is GC containing the transformation matrix and STGraphics objects to use. The
 * protocol drawable is the destination window or pixmap to draw on. The XServer calls
 * STLineRender and passes the STLine object referred to by Line, and the STGraphics
 * object found in the GC. The function has no response.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine, GC, or Drawable to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 * BadAlloc may be returned if space for STLineRender data structures cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineRender                   */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	gc     B32;         /**< Graphics Context                               */
    CARD32	drawable B32;       /**< Window or Pixmap to draw on                    */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
} xSTLineRenderReq;
#define sz_xSTLineRenderReq 16

/**
 * ST Line Add Highlight request
 *
 * The X_STLineAddHighlight request is used to select a portion of an STLine object
 * referred to by the XSTLine XID.
 * The protocol Line is the XID value referring to the STLine object to use. The protocol
 * Position is the character position to start highlight within the line. The protocol
 * CharCount is the number of characters to highlight from the starting point within the
 * line. The XServer calls STLineAddHighlight and passes the STLine object referred to by
 * Line, and the Position and CharCount values. The function has no response.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineAddHighlight             */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32      Position B32;       /**< First Character to begin highlighting          */
    CARD32      CharCount B32;      /**< Number of characters to highlight              */
} xSTLineAddHighlightReq;
#define sz_xSTLineAddHighlightReq 16

/**
 * ST Line Get Highlights request
 *
 * The X_STLineGetHighlight request is used to get the portions of an STLine object,
 * referred to by the XSTLine XID, that are highlighted.
 * The protocol Line is the XID value referring to the STLine object to use. The XServer
 * calls STLineGetHighlight and passes the STLine object referred to by Line. The function
 * returns a list of Position, CharCount values that is appended onto the end of the
 * response.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineGetHighlight             */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
} xSTLineGetHighlightsReq;
#define sz_xSTLineGetHighlightsReq 8

/**
 * ST Line Get Highlights reply
 *
 * The protocol response count is the number of highlighted regions in the STLine.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of highlighted regions returned         */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTLineGetHighlightsReply;
#define sz_xSTLineGetHighlightsReply 32

/**
 * ST Line Remove Highlight request
 *
 * The X_STLineRemoveHighlight request is used to de-select a portion of an STLine object
 * referred to by the XSTLine XID that was selected previously.
 * The protocol Line is the XID value referring to the STLine object to use. The protocol
 * Position is the character position to start removing highlight from within the line.
 * The protocol CharCount is the number of characters to remove highlighting from the
 * starting point within the line. The XServer calls STLineRemoveHighlight and passes the
 * STLine object referred to by Line, and the Position and CharCount values. The function
 * has no response.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineRemoveHighlight          */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32      Position B32;       /**< First position to begin removing highlight     */
    CARD32      CharCount B32;      /**< Number of characters to remove highlight       */
} xSTLineRemoveHighlightReq;
#define sz_xSTLineRemoveHighlightReq 16

/**
 * ST Line Get Design Metrics request
 *
 * The X_STLineGetDesignMetrics request is used to get the design metrics for STLine
 * object referred to by the XSTLine XID. Design metrics differ from regular metrics in
 * that they are imposed by the font rather than the client application.
 * The protocol Line is the XID value referring to the STLine object to use. The XServer
 * calls STLineGetDesignMetrics and passes the STLine object referred to by Line. The
 * function returns the metric information about the line that was set by the font.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineGetDesignMetrics         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
} xSTLineGetDesignMetricsReq;
#define sz_xSTLineGetDesignMetricsReq 8

/**
 * ST Line Get Design Metrics reply
 *
 * The protocol response LineWidth is a double that indicates the width of the line in
 * points. The protocol response Ascent is a double that indicates the maximum ascent of
 * any character in the line. The protocol response Descent is a double that indicates the
 * maximum descent of any character in the line. The protocol response Leading is a double
 * that indicates the leading value to be used after this line. 
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64	Ascent;             /**< Maximum ascent of line in design units         */
    CARD64	Descent;            /**< Maximum descent of line in design units        */
    CARD64	Leading;            /**< Maximum leading of line in design units        */
    CARD64	LineWidth;          /**< Maximum width of line in design units          */
} xSTLineGetDesignMetricsReply;
#define sz_xSTLineGetDesignMetricsReply 40


/**
 * ST Line Get Styled Glyphs request
 *
 * The X_STLineGetStyledGlyphs request is used to get an array of styled glyphs from
 * the line object referred to by the XSTLine XID. 
 * The protocol Line is the XID value referring to the STLine object to use. The protocol
 * Position is the first character to begin retrieving glyph information from. The
 * protocol CharCount is the number of characters to retrieve glyph information for.
 * The XServer calls STLineGetStyledGlyphs and passes the STLine object referred to by
 * Line. The function returns the metric information about the line that was set by the 
 * font.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTLine to use is not valid.
 * BadImplementation may be returned if the STLine to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STLineGetStyledGlyphs         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32      Line B32;           /**< XSTLine XID referring to the STLine to use     */
    CARD32      Position B32;       /**< Char Position within Line to get glyphs from   */
    CARD32      CharCount B32;      /**< Number of characters to get glyphs for         */
} xSTLineGetStyledGlyphsReq;
#define sz_xSTLineGetStyledGlyphsReq 16

/**
 * ST Line Get Design Metrics reply
 *
 * The protocol response GlyphCount indicates the number of the styled glyphs appended
 * to the end of the response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	GlyphCount B32;     /**< Number of styled glyphs in return message      */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTLineGetStyledGlyphsReply;
#define sz_xSTLineGetStyledGlyphsReply 32

/**
 * @}
 */





/** @defgroup XSTGlyphVector_Protocol XSTGlyphVector Protocol messages
 * @{
 */


/**
 * ST GlyphVector New request
 *
 * The X_STGlyphVectorNew request is used to create a new STGlyphVector containing any
 * glyphs appended to the request. A GlyphVector is similar to an STLine except that there
 * is no layout that occurs on the GlyphVector. The client is responsible for poisitioning
 * all glyphs.
 * The protocol Env represents the XSTTypeEnv XID used by the XServer to get the STTypeEnv
 * structure. The protocol count indicates the number of GlyphVector items appended onto
 * the end of the request. The protocol GlyphVector is the XID that will be used to refer
 * to the STGlyphVector object. The XServer calls STGlyphVectorNew and passes the 
 * STTypeEnv object, and the list of GlyphVectors. It returns a pointer to the new 
 * STGlyphVector object. This command has no response.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for STGlyphVector data structures cannot be 
 *  allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorNew               */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	Env B32;            /**< XSTTypeEnv XID to use                          */
    CARD32      count B32;          /**< Number of glyph vectors to put in object       */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID for new STGlyphVector       */
} xSTGlyphVectorNewReq;
#define sz_xSTGlyphVectorNewReq 16

/**
 * ST GlyphVector New Copy request
 *
 * The X_STGlyphVectorNewCopy request is used to copy one STGlyphVector object to another
 * new STGlyphVector object.
 * The protocol OldVector represents the XSTGlyphVector XID used by the XServer to get the
 * STGlyphVector object. The protocol NewVector represents the XSTGlyphVector XID of the
 * new STGlyphVector to be created by STSF. The XServer calls STGlyphVectorNewCopy and
 * passes the existing STGlyphVector object. It returns a pointer the new STGlyphVector
 * object. This command has no response.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTTypeEnv to use is not valid.
 * BadImplementation may be returned if the STTypeEnv to use is NULL.
 * BadAlloc may be returned if space for STGlyphVector data structures cannot be 
 *  allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorNewCopy           */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	OldVector B32;      /**< XSTGlyphVector XID of structure to copy        */
    CARD32	NewVector B32;      /**< XSTGlyphVector XID of new STGlyphVector        */
} xSTGlyphVectorNewCopyReq;
#define sz_xSTGlyphVectorNewCopyReq 12

/**
 * ST GlyphVector Dispose request
 *
 * The X_STGlyphVectorDispose request is used to remove and free the resources used by the
 * STGlyphVector as well as remove the XID value from the XServer. 
 * The protocol GlyphVector represents the XSTGlyphVector XID of the STGlyphVector object
 * to dispose. The XServer calls STGlyphVectorDispose. There is no response to the 
 * XSTGlyphVectorDispose command.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTGlyphVector to use is not valid.
 * BadImplementation may be returned if the STGlyphVector to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorDispose           */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID of STGlyphVector to use     */
} xSTGlyphVectorDisposeReq;
#define sz_xSTGlyphVectorDisposeReq 8

/**
 * ST GlyphVector Set Glyphs request
 *
 * The X_STGlyphVectorSetGlyphs request is used to associate a supplied set to 
 * GlyphVectors with the STGlyphVector object.
 * The protocol GlyphVector represents the XSTGlyphVector XID of the STGlyphVector object 
 * to use. The protocol GlyphCount indicates the number of GlyphVectors appended onto the
 * end of the request. The XServer calls STGlyphVectorSetGlyphs and passes the 
 * STGlyphVector and the list of GlyphVectors. There is no response to the 
 * XSTGlyphVectorSetGlyphs command.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTGlyphVector to use is not valid.
 * BadImplementation may be returned if the STGlyphVector to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorSetGlyphs         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID of STGlyphVector to use     */
    CARD32	GlyphCount B32;     /**< Number of GlyphVectors appended after request  */
} xSTGlyphVectorSetGlyphsReq;
#define sz_xSTGlyphVectorSetGlyphsReq 12

/**
 * ST GlyphVector Get Glyphs request
 *
 * The X_STGlyphVectorGetGlyphs request is used to return the list of GlyphVectors
 * associated with the specified STGlyphVector.
 * The protocol GlyphVector represents the XSTGlyphVector XID of the STGlyphVector object 
 * to use. The protocol position indicates the position of the first GlyphVector to 
 * return. The protocol GlyphCount indicates the number of GlyphVectors to return. The
 * XServer calls STGlyphVectorGetGlyphs and passes the STGlyphVector, the position and
 * the number of GlyphVectors to retrieve. The function returns a list of GlyphVectors.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTGlyphVector to use is not valid.
 * BadImplementation may be returned if the STGlyphVector to use is NULL.
 * BadAlloc may be returned if space for the protocol response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorGetGlyphs         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID of STGlyphVector to use     */
    CARD32	position B32;       /**< Position of first GlyphVector to return        */
    CARD32	GlyphCount B32;     /**< Number of GlyphVectors to return               */
} xSTGlyphVectorGetGlyphsReq;
#define sz_xSTGlyphVectorGetGlyphsReq 16

/**
 * ST GlyphVector Get Glyphs reply
 *
 * The protocol response count indicates the number of GlyphVectors appended onto the end
 * of the response.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of GlyphVectors returned                */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTGlyphVectorGetGlyphsReply;
#define sz_xSTGlyphVectorGetGlyphsReply 32

/**
 * ST GlyphVector Replace Glyphs request
 *
 * The X_STGlyphVectorReplaceGlyphs request is used to replace a subset of the 
 * GlyphVectors in an STGlyphVector object.
 * The protocol GlyphVector represents the XSTGlyphVector XID of the STGlyphVector object
 * to use. The protocol position indicates the position of the first GlyphVector to
 * replace. The protocol GlyphCount indicates the number of GlyphVectors to replace. The
 * protocol count indicates the number of GlyphVectors appended to the request that will
 * replace the selected area. The XServer calls STGlyphVectorReplaceGlyphs and passes the
 * STGlyphVector, the position, the number of GlyphVectors to replace, and the list of
 * GlyphVectors to put in their place. There is no response to this command.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTGlyphVector to use is not valid.
 * BadImplementation may be returned if the STGlyphVector to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorReplaceGlyphs     */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID of STGlyphVector to use     */
    CARD32	position B32;       /**< Position of first GlyphVector to replace       */
    CARD32	GlyphCount B32;     /**< Number of GlyphVectors to replace              */
    CARD32	count B32;          /**< Number of GlyphVectors to insert               */
} xSTGlyphVectorReplaceGlyphsReq;
#define sz_xSTGlyphVectorReplaceGlyphsReq 20

/**
 * ST GlyphVector Adjust Positions request
 *
 * The X_STGlyphVectorAdjustPositions request is used to shift the position of a portion
 * of the GlyphVectors by a specified X, Y amount.
 * The protocol GlyphVector represents the XSTGlyphVector XID of the STGlyphVector object
 * to use. The protocol position indicates the position of the first GlyphVector to shift.
 * The protocol GlyphCount indicates the number of GlyphVectors to shift. The protocol x
 * indicates the amount to shift the selected GlyphVectors by along the X axis. The 
 * protocol y indicates the amount to shift the selected GlyphVectors by along the Y axis.
 * The XServer calls STGlyphVectorAdjustPositions and passes the STGlyphVector, the 
 * position, the number of GlyphVectors to shift, and the X and Y values. There is no 
 * response to this command.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTGlyphVector to use is not valid.
 * BadImplementation may be returned if the STGlyphVector to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorAdjustPositions   */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID of STGlyphVector to use     */
    CARD32	position B32;       /**< Position of first GlyphVector to shift         */
    CARD32	GlyphCount B32;     /**< Number of GlyphVectors to shift                */
    CARD64	x;                  /**< Amount of shift GlyphVectors along the X axis  */
    CARD64	y;                  /**< Amount of shift GlyphVectors along the Y axis  */
} xSTGlyphVectorAdjustPositionsReq;
#define sz_xSTGlyphVectorAdjustPositionsReq 32

/**
 * ST GlyphVector Measure request
 *
 * The X_STGlyphVectorMeasure request is used to determine the bounding box around the
 * selected GlyphVectors.
 * The protocol GlyphVector represents the XSTGlyphVector XID of the STGlyphVector object
 * to use. The protocol position indicates the position of the first GlyphVector to use.
 * The protocol GlyphCount indicates the number of GlyphVectors to use. The XServer calls
 * STGlyphVectorMeasure and passes the STGlyphVector object, the position and the number
 * of GlyphVectors to include. It returns an STRectangle indicating the upper left and
 * lower right corners of the bounding rectangle.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTGlyphVector to use is not valid.
 * BadImplementation may be returned if the STGlyphVector to use is NULL.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorMeasure           */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID of STGlyphVector to use     */
    CARD32	position B32;       /**< Position of first GlyphVector to use           */
    CARD32	GlyphCount B32;     /**< Number of GlyphVectors to use                  */
} xSTGlyphVectorMeasureReq;
#define sz_xSTGlyphVectorMeasureReq 16

/**
 * ST GlyphVector Measure reply
 *
 * The protocol response ax represents the upper left X value of the bounding rectangle.
 * The protocol response ay represents the upper left Y value of the bounding rectangle.
 * The protocol response bx represents the lower right X value of the bounding rectangle.
 * The protocol response by represents the lower right Y value of the bounding rectangle.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD64	ax;                 /**< Upper left X value                             */
    CARD64	ay;                 /**< Upper left Y value                             */
    CARD64	bx;                 /**< Lower right X value                            */
    CARD64	by;                 /**< Lower right Y value                            */
} xSTGlyphVectorMeasureReply;
#define sz_xSTGlyphVectorMeasureReply 40

/**
 * ST GlyphVector Get Bounds request
 *
 * The X_STGlyphVectorGetBounds request is used to get the transformed trapezoidal 
 * bounding areas around the selected GlyphVectors.
 * The protocol GlyphVector represents the XSTGlyphVector XID of the STGlyphVector object
 * to use. The protocol position indicates the position of the first GlyphVector to use.
 * The protocol GlyphCount indicates the number of GlyphVectors to use. The protocol
 * MaxBounds indicates the maximum number of bounding areas to return. The protocol
 * BoundsType indicates the type of bounding areas to use. The XServer calls
 * STGlyphVectorGetBounds and passes the STGlyphVector object, the position and the number
 * of GlyphVectors to include, and the bounds max and type to use. It returns a list of
 * STTrapezoids.
 *
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTGlyphVector to use is not valid.
 * BadImplementation may be returned if the STGlyphVector to use is NULL.
 * BadAlloc may be returned if space for the protocol response cannot be allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorGetBounds         */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID of STGlyphVector to use     */
    CARD32	gc B32;             /**< Graphics Contect containing transformation     */
    CARD32	position B32;       /**< Position of first GlyphVector to use           */
    CARD32	GlyphCount B32;     /**< Number of GlyphVectors to use                  */
    CARD32	MaxBounds B32;      /**< Maximum number of bounding boxes to return     */
    CARD32	BoundsType B32;     /**< Type of bounding box to obtain. IE: caret      */
} xSTGlyphVectorGetBoundsReq;
#define sz_xSTGlyphVectorGetBoundsReq 28

/**
 * ST GlyphVector Get Bounds reply
 *
 * The procotol response count indicates the number of bounding boxes returned.
 */
typedef struct {
    BYTE	type;		    /**< Reply Type: always X_Reply                     */
    CARD8	pad0;               /**< Not used                                       */
    CARD16	sequenceNumber B16; /**< Sequence Number to associate to request        */
    CARD32	length B32;         /**< Length of Reply beyond normal in Bytes         */
    CARD32	count B32;          /**< Number of bounding boxes included in reply     */
    CARD32	pad1 B32;           /**< Not used                                       */
    CARD32	pad2 B32;           /**< Not used                                       */
    CARD32	pad3 B32;           /**< Not used                                       */
    CARD32	pad4 B32;           /**< Not used                                       */
    CARD32	pad5 B32;           /**< Not used                                       */
} xSTGlyphVectorGetBoundsReply;
#define sz_xSTGlyphVectorGetBoundsReply 32

/**
 * ST GlyphVector Render request
 *
 * The X_STGlyphVectorRender request is used to render an STGlyphVector object referred to
 * by the XSTGlyphVector XID. STGlyphVectorRender requires data values to be set, 
 * including the callback for Rendering.
 * The protocol GlyphVector is the XID value referring to the STGlyphVector object to use.
 * The protocol gc is GC containing the transformation matrix and STGraphics objects to 
 * use. The protocol drawable is the destination window or pixmap to draw on. The protocol
 * position indicates the position of the first GlyphVector to use. The protocol 
 * GlyphCount indicates the number of GlyphVectors to use. The XServer calls
 * STGlyphVectorRender and passes the STGlyphVector object referred to by GlyphVector, and
 * the STGraphics object found in the GC. The function has no response.
 * 
 * BadLength may be returned if the protocol message is not of the proper length.
 * BadValue may be returned if the XSTGlyphVector, GC, or Drawable to use is not valid.
 * BadImplementation may be returned if the STGlyphVector to use is NULL.
 * BadAlloc may be returned if space for STGlyphVectorRender data structures cannot be
 *  allocated.
 */
typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorRender            */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	GlyphVector B32;    /**< XSTGlyphVector XID of STGlyphVector to use     */
    CARD32	drawable B32;       /**< Window or Pixmap to draw on                    */
    CARD32	gc     B32;         /**< Graphics Context                               */
    CARD32	position B32;       /**< Position of first GlyphVector to render        */
    CARD32	GlyphCount B32;     /**< Number of GlyphVectors to render               */
} xSTGlyphVectorRenderReq;
#define sz_xSTGlyphVectorRenderReq 24

typedef struct {
    CARD8       reqType;            /**< Request Type: always STRCode                   */
    CARD8       stReqType;          /**< ST Request:   X_STGlyphVectorRender            */
    CARD16      length B16;         /**< Request Length in Bytes                        */
    CARD32	flag B32;           /**< SysCtl flag ID                                 */
    CARD32	value B32;          /**< Value to set SysCtl to                         */
} xSTSetSysCtlFlagReq;
#define sz_xSTSetSysCtlFlagReq 12
/**
 * @}
 */
