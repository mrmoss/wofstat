/*
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef	_BSM_AUDIT_UEVENTS_H
#define	_BSM_AUDIT_UEVENTS_H

#pragma ident	"@(#)audit_uevents.h	1.12	06/09/10 SMI"

/*
 * User level audit event numbers.
 *
 *     0		Reserved as an invalid event number.
 *     1 - 2047		Reserved for the Solaris Kernel events.
 *  2048 - 32767	Reserved for the Solaris TCB programs.
 * 32768 - 65535	Available for third party TCB applications.
 *
 */

#ifdef	__cplusplus
extern "C" {
#endif

#define	AUE_at_create			6144
#define	AUE_at_delete			6145
#define	AUE_at_perm			6146
#define	AUE_cron_invoke			6147
#define	AUE_crontab_create		6148
#define	AUE_crontab_delete		6149
#define	AUE_crontab_perm		6150
#define	AUE_inetd_connect		6151
#define	AUE_login			6152
#define	AUE_logout			6153
#define	AUE_telnet			6154
#define	AUE_rlogin			6155
#define	AUE_mountd_mount		6156
#define	AUE_mountd_umount		6157
#define	AUE_rshd			6158
#define	AUE_su				6159
#define	AUE_halt_solaris		6160
#define	AUE_reboot_solaris		6161
#define	AUE_rexecd			6162
#define	AUE_passwd			6163
#define	AUE_rexd			6164
#define	AUE_ftpd			6165
#define	AUE_init_solaris		6166
#define	AUE_uadmin_solaris		6167
#define	AUE_shutdown_solaris		6168
#define	AUE_poweroff_solaris		6169
#define	AUE_crontab_mod			6170
#define	AUE_ftpd_logout			6171
#define	AUE_ssh				6172
#define	AUE_role_login			6173
#define	AUE_prof_cmd			6180
#define	AUE_filesystem_add		6181
#define	AUE_filesystem_delete		6182
#define	AUE_filesystem_modify		6183
#define	AUE_network_add			6184
#define	AUE_network_delete		6185
#define	AUE_network_modify		6186
#define	AUE_printer_add			6187
#define	AUE_printer_delete		6188
#define	AUE_printer_modify		6189
#define	AUE_scheduledjob_add		6190
#define	AUE_scheduledjob_delete		6191
#define	AUE_scheduledjob_modify		6192
#define	AUE_serialport_add		6193
#define	AUE_serialport_delete		6194
#define	AUE_serialport_modify		6195
#define	AUE_usermgr_add			6196
#define	AUE_usermgr_delete		6197
#define	AUE_usermgr_modify		6198
#define	AUE_uauth			6199
#define	AUE_allocate_succ		6200
#define	AUE_allocate_fail		6201
#define	AUE_deallocate_succ		6202
#define	AUE_deallocate_fail		6203
#define	AUE_listdevice_succ		6205
#define	AUE_listdevice_fail		6206
#define	AUE_create_user			6207
#define	AUE_modify_user			6208
#define	AUE_delete_user			6209
#define	AUE_disable_user		6210
#define	AUE_enable_user			6211
#define	AUE_newgrp_login		6212
#define	AUE_admin_authenticate		6213
#define	AUE_kadmind_auth		6214
#define	AUE_kadmind_unauth		6215
#define	AUE_krb5kdc_as_req		6216
#define	AUE_krb5kdc_tgs_req		6217
#define	AUE_krb5kdc_tgs_req_2ndtktmm	6218
#define	AUE_krb5kdc_tgs_req_alt_tgt	6219
#define	AUE_smserverd			6220
#define	AUE_screenlock			6221
#define	AUE_screenunlock		6222
#define	AUE_zone_state			6223
#define	AUE_inetd_copylimit		6224
#define	AUE_inetd_failrate		6225
#define	AUE_inetd_ratelimit		6226
#define	AUE_zlogin			6227
#define	AUE_hotplug_state		6500
#define	AUE_hotplug_set			6501
#define	AUE_hotplug_install		6502
#define	AUE_hotplug_uninstall		6503
#define	AUE_hotplug_create_port		6504
#define	AUE_hotplug_remove_port		6505
#define	AUE_hotplug_set_ceiling		6506
#define	AUE_hotplug_clear_ceiling	6507
#define	AUE_sl_change			9035
#define	AUE_file_relabel		9036
#define	AUE_file_copy			9037
#define	AUE_file_move			9038
#define	AUE_sel_mgr_xfer		9039
#define	AUE_print_request		9040
#define	AUE_print_request_ps		9041
#define	AUE_print_request_unlabeled	9042
#define	AUE_print_request_nobanner	9043
#define	AUE_ClientConnect		9101
#define	AUE_ClientDisconnect		9102
#define	AUE_ChangeProperty		9120
#define	AUE_DeleteProperty		9121
#define	AUE_GrabServer			9137
#define	AUE_UngrabServer		9138
#define	AUE_SetFontPath			9146
#define	AUE_InstallColormap		9173
#define	AUE_UninstallColormap		9174
#define	AUE_SetScreenSaver		9193
#define	AUE_ChangeHosts			9194
#define	AUE_SetAccessControl		9195
#define	AUE_SetCloseDownMode		9196
#define	AUE_KillClient			9197
#define	AUE_XExtensions			9202
#define	AUE_CreateWindow		9103
#define	AUE_ChangeWindowAttributes	9104
#define	AUE_GetWindowAttributes		9105
#define	AUE_DestroyWindow		9106
#define	AUE_DestroySubwindows		9107
#define	AUE_ChangeSaveSet		9108
#define	AUE_ReparentWindow		9109
#define	AUE_MapWindow			9110
#define	AUE_MapSubwindows		9111
#define	AUE_UnmapWindow			9112
#define	AUE_UnmapSubwindows		9113
#define	AUE_ConfigureWindow		9114
#define	AUE_CirculateWindow		9115
#define	AUE_GetGeometry			9116
#define	AUE_QueryTree			9117
#define	AUE_InternAtom			9118
#define	AUE_GetAtomName			9119
#define	AUE_GetProperty			9122
#define	AUE_ListProperties		9123
#define	AUE_SetSelectionOwner		9124
#define	AUE_GetSelectionOwner		9125
#define	AUE_ConvertSelection		9126
#define	AUE_SendEvent			9127
#define	AUE_GrabPointer			9128
#define	AUE_UngrabPointer		9129
#define	AUE_GrabButton			9130
#define	AUE_UngrabButton		9131
#define	AUE_ChangeActivePointerGrab	9132
#define	AUE_GrabKeyboard		9133
#define	AUE_UngrabKeyboard		9134
#define	AUE_GrabKey			9135
#define	AUE_UngrabKey			9136
#define	AUE_QueryPointer		9139
#define	AUE_GetMotionEvents		9140
#define	AUE_TranslateCoords		9141
#define	AUE_WarpPointer			9142
#define	AUE_SetInputFocus		9143
#define	AUE_GetInputFocus		9144
#define	AUE_QueryKeymap			9145
#define	AUE_FreePixmap			9147
#define	AUE_ChangeGC			9148
#define	AUE_CopyGC			9149
#define	AUE_SetDashes			9150
#define	AUE_SetClipRectangles		9151
#define	AUE_FreeGC			9152
#define	AUE_ClearArea			9153
#define	AUE_CopyArea			9154
#define	AUE_CopyPlane			9155
#define	AUE_PolyPoint			9156
#define	AUE_PolyLine			9157
#define	AUE_PolySegment			9158
#define	AUE_PolyRectangle		9159
#define	AUE_PolyArc			9160
#define	AUE_FillPolygon			9161
#define	AUE_PolyFillRectangle		9162
#define	AUE_PolyFillArc			9163
#define	AUE_PutImage			9164
#define	AUE_GetImage			9165
#define	AUE_PolyText8			9166
#define	AUE_PolyText16			9167
#define	AUE_ImageText8			9168
#define	AUE_ImageText16			9169
#define	AUE_CreateColormap		9170
#define	AUE_FreeColormap		9171
#define	AUE_CopyColormapAndFree		9172
#define	AUE_ListInstalledColormaps	9175
#define	AUE_AllocColor			9176
#define	AUE_AllocNamedColor		9177
#define	AUE_AllocColorCells		9178
#define	AUE_AllocColorPlanes		9179
#define	AUE_FreeColors			9180
#define	AUE_StoreColors			9181
#define	AUE_StoreNamedColor		9182
#define	AUE_QueryColors			9183
#define	AUE_LookupColor			9184
#define	AUE_CreateCursor		9185
#define	AUE_CreateGlyphCursor		9186
#define	AUE_FreeCursor			9187
#define	AUE_RecolorCursor		9188
#define	AUE_ChangeKeyboardMapping	9189
#define	AUE_ChangeKeyboardControl	9190
#define	AUE_Bell			9191
#define	AUE_ChangePointerControl	9192
#define	AUE_RotateProperties		9198
#define	AUE_ForceScreenSaver		9199
#define	AUE_SetPointerMapping		9200
#define	AUE_SetModifierMapping		9201

#ifdef	__cplusplus
}
#endif

#endif	/* _BSM_AUDIT_UEVENTS_H */
