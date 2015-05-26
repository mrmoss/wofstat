/******************************************************************************
 *
 * Description
 *  mpapi-sun.h - general header file for Sun extension to the Multipath
 *  Management API Version 1.0 client
 *
 * License:
 *  The contents of this file are subject to the SNIA Public License
 *  Version 1.1 (the "License"); you may not use this file except in
 *  compliance with the License. You may obtain a copy of the License at
 *
 *  http://mp-mgmt-api.sourceforge.net
 *
 *  Software distributed under the License is distributed on an "AS IS"
 *  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 *  the License for the specific language governing rights and limitations
 *  under the License.
 *
 *****************************************************************************/
#pragma ident	"@(#)mpapi-sun.h	1.1	07/01/23 SMI"

#include <sys/scsi/impl/uscsi.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef MPAPI_SUN_H
#define MPAPI_SUN_H

/**
 ******************************************************************************
 *
 * The APIs for path management.
 *
 * - Sun_MP_SendScsiCmd
 *
 ******************************************************************************
 */


MP_STATUS Sun_MP_SendScsiCmd(
   MP_OID		pathOid,
   struct uscsi_cmd	*cmd
);


#endif

#ifdef __cplusplus
};
#endif

