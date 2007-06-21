/**
 * \file gsmphones.c
 *
 * Phone features database.
 */
/* (c) 2002-2005 by Marcin Wiacek and Michal Cihar */
/* Phones ID (c) partially by Walek */

#include <gammu-config.h>

#include "gsmphones.h"

#include <string.h>

/**
 * Flags needed for various phone models.
 */
OnePhoneModel allmodels[] = {
#ifdef GSM_ENABLE_NOKIA650
	{"0650" ,"THF-12","",           {0}},
#endif
#ifdef GSM_ENABLE_NOKIA6110
	{"2100" ,"NAM-2" ,"",           {F_NOWAP,F_NOCALLER,F_RING_SM,F_CAL33,F_POWER_BATT,F_PROFILES33,F_NOCALLINFO,F_NODTMF,0}},//guess
	{"3210" ,"NSE-8" ,"",           {F_NOWAP,F_NOCALLER,F_NOCALENDAR,F_NOPBKUNICODE,F_POWER_BATT,F_PROFILES51,F_NOPICTUREUNI,F_NOCALLINFO,F_NODTMF,0}},
	{"3210" ,"NSE-9" ,"",           {F_NOWAP,F_NOCALLER,F_NOCALENDAR,F_NOPBKUNICODE,F_POWER_BATT,F_PROFILES51,F_NOPICTUREUNI,F_NOCALLINFO,F_NODTMF,0}},
	{"3310" ,"NHM-5" ,"",           {F_NOWAP,F_NOCALLER,F_RING_SM,F_CAL33,F_POWER_BATT,F_PROFILES33,F_NOCALLINFO,F_NODTMF,0}},
	{"3330" ,"NHM-6" ,"",           {F_NOCALLER,F_RING_SM,F_CAL33,F_PROFILES33,F_NOPICTUREUNI,F_NOCALLINFO,F_NODTMF,0}},
	{"3390" ,"NPB-1" ,"",           {F_NOWAP,F_NOCALLER,F_RING_SM,F_CAL33,F_PROFILES33,F_NOPICTUREUNI,F_NOCALLINFO,F_NODTMF,0}},
	{"3410" ,"NHM-2" ,"",           {F_RING_SM,F_CAL33,F_PROFILES33,F_NOCALLINFO,F_NODTMF,0}},
	{"3610" ,"NAM-1" ,"",           {F_NOCALLER,F_RING_SM,F_CAL33,F_POWER_BATT,F_PROFILES33,F_NOCALLINFO,F_NODTMF,0}},//guess
	{"5510" ,"NPM-5" ,"",           {F_NOCALLER,F_PROFILES33,F_NOPICTUREUNI,0}},
	{"5110" ,"NSE-1" ,"",           {F_NOWAP,F_NOCALLER,F_NORING,F_NOPICTURE,F_NOSTARTUP,F_NOCALENDAR,F_NOPBKUNICODE,F_PROFILES51,F_MAGICBYTES,F_DISPSTATUS,0}},
	{"5110i","NSE-2" ,"",           {F_NOWAP,F_NOCALLER,F_NORING,F_NOPICTURE,F_NOSTARTUP,F_NOCALENDAR,F_NOPBKUNICODE,F_PROFILES51,F_MAGICBYTES,F_DISPSTATUS,0}},
	{"5130" ,"NSK-1" ,"",           {F_NOWAP,F_NOCALLER,F_NORING,F_NOPICTURE,F_NOSTARTUP,F_NOCALENDAR,F_NOPBKUNICODE,F_PROFILES51,F_MAGICBYTES,F_DISPSTATUS,0}},
	{"5190" ,"NSB-1" ,"",           {F_NOWAP,F_NOCALLER,F_NORING,F_NOPICTURE,F_NOSTARTUP,F_NOCALENDAR,F_NOPBKUNICODE,F_PROFILES51,F_MAGICBYTES,F_DISPSTATUS,0}},
	{"6110" ,"NSE-3" ,"",           {F_NOWAP,F_NOPICTURE,F_NOSTARTANI,F_NOPBKUNICODE,F_MAGICBYTES,F_DISPSTATUS,0}},
	{"6130" ,"NSK-3" ,"",           {F_NOWAP,F_NOPICTURE,F_NOSTARTANI,F_NOPBKUNICODE,F_MAGICBYTES,F_DISPSTATUS,0}},
	{"6150" ,"NSM-1" ,"",           {F_NOWAP,F_NOSTARTANI,F_NOPBKUNICODE,F_MAGICBYTES,F_DISPSTATUS,F_NOPICTUREUNI,0}},
	{"6190" ,"NSB-3" ,"",           {F_NOWAP,F_NOPICTURE,F_NOSTARTANI,F_NOPBKUNICODE,F_MAGICBYTES,F_DISPSTATUS,0}},
#endif
#if defined(GSM_ENABLE_NOKIA6110) || defined(GSM_ENABLE_ATGEN)
	{"5210" ,"NSM-5" ,"Nokia 5210", {F_CAL52,F_NOSTARTANI,F_NOPICTUREUNI,F_NODTMF,0}},
	{"8210" ,"NSM-3" ,"Nokia 8210", {F_NOWAP,F_NOSTARTANI,F_NOPBKUNICODE,F_NOPICTUREUNI,0}},
	{"8250" ,"NSM-3D","Nokia 8250", {F_NOWAP,F_NOSTARTANI,F_CAL82,F_NOPICTUREUNI,0}},
	{"8290" ,"NSB-7" ,"Nokia 8290", {F_NOWAP,F_NOSTARTANI,F_NOPBKUNICODE,F_NOPICTUREUNI,0}},
	{"8850" ,"NSM-2" ,"Nokia 8850", {0}},
	{"8855" ,"NSM-4" ,"Nokia 8855", {0}},
	{"8890" ,"NSB-6" ,"Nokia 8890", {0}},
#endif
#if defined(GSM_ENABLE_NOKIA7110) || defined(GSM_ENABLE_ATGEN)
	{"6210" ,"NPE-3" ,"Nokia 6210", {F_VOICETAGS,F_CAL62,0}},
	{"6250" ,"NHM-3" ,"Nokia 6250", {F_VOICETAGS,F_CAL62,0}},
	{"7110" ,"NSE-5" ,"Nokia 7110", {F_CAL62,0}},
	{"7190" ,"NSB-5" ,"Nokia 7190", {F_CAL62,0}},
#endif
#ifdef GSM_ENABLE_NOKIA6510
	{"1100" ,"RH-18" ,"",		{0}},
	{"1100a","RH-38" ,"",		{0}},
	{"1100b","RH-36" ,"",		{0}},
	{"2650", "RH-53" ,"",           {F_PBKTONEGAL,F_PBKSMSLIST,0}},//fixme
	{"3100" ,"RH-19" ,"",           {F_PBKTONEGAL,F_PBKSMSLIST,0}},//fixme
	{"3100b","RH-50" ,"",           {F_PBKTONEGAL,F_PBKSMSLIST,0}},//fixme
 	{"3105" ,"RH-48" ,"Nokia 3105",	{F_PBKTONEGAL,F_PBKSMSLIST,F_VOICETAGS,0}},//fixme
	{"3108", "RH-6",  "Nokia 3108",	{0}}, //does it have irda ?
	{"3200", "RH-30" ,"Nokia 3200",	{F_PBKTONEGAL,0}},//fixme
	{"3200a","RH-31" ,"Nokia 3200",	{F_PBKTONEGAL,0}},//fixme
 	{"3205", "RM-11" ,"Nokia 3205",	{F_CAL62,F_PBK35,F_NOGPRSPOINT,F_VOICETAGS,F_PROFILES,F_RADIO,F_PBKSMSLIST,F_PBKTONEGAL,0}},//fixme
	{"3300" ,"NEM-1" ,"Nokia 3300", {F_PBKTONEGAL,0}},//fixme
	{"3300" ,"NEM-2" ,"Nokia 3300", {F_PBKTONEGAL,0}},//fixme
	{"3510" ,"NHM-8" ,"",           {F_CAL35,F_PBK35,F_NOGPRSPOINT,F_VOICETAGS,0}},
	{"3510i","RH-9"  ,"",           {F_CAL35,F_PBK35,F_NOGPRSPOINT,F_VOICETAGS,F_PROFILES,0}},
	{"3530" ,"RH-9"  ,"",           {F_CAL35,F_PBK35,F_NOGPRSPOINT,F_VOICETAGS,0}},
	{"3589i","RH-44" ,"",		{F_VOICETAGS,0}},
	{"3590" ,"NPM-8" ,"",		{0}},//irda?
	{"3595" ,"NPM-10" ,"",		{0}},//irda?
#endif
#if defined(GSM_ENABLE_NOKIA6510) || defined(GSM_ENABLE_ATGEN)
	{"3220" ,"RH-37" ,"",           {F_PBKTONEGAL,F_TODO66,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_SYNCML,F_FILES2,F_3220_MMS,0}},
	{"3220" ,"RH-49" ,"",           {F_PBKTONEGAL,F_TODO66,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_SYNCML,F_FILES2,F_3220_MMS,0}},
	{"5100" ,"NPM-6" ,"Nokia 5100", {F_PBKTONEGAL,F_TODO66,F_RADIO,0}},
	{"5100" ,"NPM-6U","Nokia 5100", {F_PBKTONEGAL,F_TODO66,F_RADIO,0}},
	{"5100" ,"NPM-6X","Nokia 5100", {F_PBKTONEGAL,F_TODO66,F_RADIO,0}},
	{"5140" ,"NPL-4" ,"Nokia 5140", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKUSER,F_WAPMMSPROXY,F_CHAT, F_SYNCML,0}},
	{"5140" ,"NPL-5" ,"Nokia 5140", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKUSER,F_WAPMMSPROXY,F_CHAT, F_SYNCML,0}},
	{"5140i","RM-104","Nokia 5140i",{F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKUSER,F_WAPMMSPROXY,F_CHAT, F_SYNCML,0}},
	{"5300" ,"RM-146","Nokia 5300", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},
	{"6020" ,"RM-30" ,"Nokia 6020", {F_VOICETAGS, F_FILES2, F_CHAT, F_WAPMMSPROXY, F_TODO66, F_PBKTONEGAL, F_NOTES,0}},//guess
	{"6021" ,"RM-94" ,"Nokia 6021", {F_PBKTONEGAL,F_TODO66,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,F_6230iWAP,F_6230iCALLER,0}},//guess
	{"6030" ,"RM-74" ,"Nokia 6030", {F_VOICETAGS, F_FILES2, F_CHAT, F_WAPMMSPROXY, F_TODO66, F_PBKTONEGAL, F_NOTES, F_NOFILE1,0}},//guess
	{"6030b","RM-75" ,"Nokia 6030b",{F_VOICETAGS, F_FILES2, F_CHAT, F_WAPMMSPROXY, F_TODO66, F_PBKTONEGAL, F_NOTES, F_NOFILE1,0}},//guess
	{"6030" ,"RM-225","Nokia 6030", {F_VOICETAGS, F_FILES2, F_CHAT, F_WAPMMSPROXY, F_TODO66, F_PBKTONEGAL, F_NOTES, F_NOFILE1,0}},//guess
	{"6085" ,"RM-198","Nokia 6085", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},//fixme
	{"6100" ,"NPL-2" ,"Nokia 6100", {F_PBKTONEGAL,F_TODO66,0}},
	{"6101" ,"RM-76" ,"Nokia 6101", {F_PBKTONEGAL,F_TODO66,0}},
	{"6103" ,"RM-161","Nokia 6103", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_NOFILE1,0}},//fixme
	{"6111" ,"RM-82" ,"Nokia 6111", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},
	{"6125" ,"RM-178","Nokia 6125", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},//fixme
	{"6131" ,"RM-115","Nokia 6131", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},//fixme
	{"6170" ,"RM-47" ,"Nokia 6170", {F_PBKTONEGAL,F_TODO66,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"6170" ,"RM-48" ,"Nokia 6170", {F_PBKTONEGAL,F_TODO66,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"6200" ,"NPL-3" ,"Nokia 6200", {F_PBKTONEGAL,0}},
	{"6220" ,"RH-20" ,"Nokia 6220", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,0}},
	{"6230" ,"RH-12" ,"Nokia 6230", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"6230" ,"RH-28" ,"Nokia 6230", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"6230i","RM-72" ,"Nokia 6230i",{F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,F_6230iWAP,F_6230iCALLER,0}},
	{"6233" ,"RM-145","Nokia 6233", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},//fixme
	{"6234" ,"RM-123","Nokia 6234", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},//fixme
	{"6270" ,"RM-56","Nokia 6270", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},//fixme
	{"6280" ,"RM-78","Nokia 6280", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,F_6230iCALLER,0}},//fixme
	{"6300" ,"RM-217" ,"Nokia 6300", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"6310" ,"NPE-4" ,"Nokia 6310", {F_TODO63,F_CAL65,F_NOMIDI,F_NOMMS,F_VOICETAGS,0}},
	{"6310i","NPL-1" ,"Nokia 6310i",{F_TODO63,F_CAL65,F_NOMIDI,F_BLUETOOTH,F_NOMMS,F_VOICETAGS,F_PROFILES,0}},
	{"6385" ,"NHP-2AX","Nokia 6385",{F_TODO63,F_CAL65,F_NOMIDI,F_NOMMS,F_VOICETAGS,0}},
	{"6510" ,"NPM-9" ,"Nokia 6510", {F_TODO63,F_CAL65,F_NOMIDI,F_RADIO,F_NOFILESYSTEM,F_NOMMS,F_VOICETAGS,0}},
	{"6610" ,"NHL-4U","Nokia 6610", {F_PBKTONEGAL,F_TODO66,F_RADIO,0}},
	{"6610i","RM-37" ,"Nokia 6610i",{F_PBKTONEGAL,F_TODO66,F_RADIO,F_SYNCML,0}},
	{"6800" ,"NSB-9" ,"Nokia 6800", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,0}},
	{"6800" ,"NHL-6" ,"Nokia 6800", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,0}},
	{"6810" ,"RM-2"  ,"Nokia 6810", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_NOTES,F_CHAT,F_SYNCML,0}},//guess
	{"6820" ,"NHL-9" ,"Nokia 6820", {F_PBKTONEGAL,F_TODO66,F_PBKSMSLIST,F_NOTES,F_CHAT,F_SYNCML,0}},//guess
	{"6822" ,"RM-68" ,"Nokia 6822", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"7200" ,"RH-23" ,"Nokia 7200", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,0}},//guess
	{"7210" ,"NHL-4" ,"Nokia 7210", {F_PBKTONEGAL,F_TODO66,F_RADIO,0}},
	{"7250" ,"NHL-4J","Nokia 7250", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKIMG,F_SYNCML,0}},
	{"7250i","NHL-4JX","Nokia 7250i",{F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKIMG,F_SYNCML,0}},
	{"7260" ,"RM-17" ,"Nokia 7260", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"7270" ,"RM-8"  ,"Nokia 7270", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"7280" ,"RM-14" ,"Nokia 7280", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,F_6230iWAP,F_6230iCALLER,0}}, //guess
	{"7360" ,"RM-127","Nokia 7360", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_WAPMMSPROXY,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"7370" ,"RM-70" ,"Nokia 7370", {F_SERIES40_30,F_FILES2,F_TODO66,F_RADIO,F_NOTES,F_SMS_FILES,0}},//fixme
	{"7600", "NMM-3", "Nokia 7600", {F_TODO66,0}},
	{"8310" ,"NHM-7" ,"Nokia 8310", {F_CAL62,F_NOMIDI,F_RADIO,F_NOFILESYSTEM,F_NOMMS,F_VOICETAGS,0}},
	{"8390" ,"NSB-8" ,"Nokia 8390", {F_CAL62,F_NOMIDI,F_RADIO,F_NOFILESYSTEM,F_NOMMS,F_VOICETAGS,0}},
	{"8800" ,"RM-13" ,"Nokia 8800", {F_PBKTONEGAL,F_TODO66,F_RADIO,F_PBKSMSLIST,F_PBKUSER,F_NOTES,F_CHAT,F_SYNCML,F_FILES2,0}},
	{"8910" ,"NHM-4" ,"Nokia 8910", {F_CAL62,F_NOMIDI,F_NOFILESYSTEM,F_NOMMS,0}},
	{"8910i","NHM-4" ,"Nokia 8910i",{F_CAL62,F_NOMIDI,F_NOFILESYSTEM,F_NOMMS,0}},
#endif
#ifdef GSM_ENABLE_NOKIA3320
	{"3320" ,"NPC-1" ,"Nokia 3320", {F_CAL62,F_DAYMONTH,0}},//fixme
#endif
#if defined(GSM_ENABLE_NOKIA3650) || defined(GSM_ENABLE_ATGEN)
	{"3650" ,"NHL-8" ,"Nokia 3650", {0}},
	{"NGAGE","NEM-4" ,"",           {F_RADIO,0}},
#endif
#ifdef GSM_ENABLE_NOKIA9210
	{"9210" ,"RAE-3" ,"",           {0}},
	{"9210i","RAE-5" ,"",           {0}},
#endif
#ifdef GSM_ENABLE_ATGEN
	{"7650" ,"NHL-2" ,"Nokia 7650", {0}},
	{"at"   ,	  "at",		  "",				   {0}},
	/* Siemens */
	{"M20"  ,	  "M20",	  "",				   {F_M20SMS,F_SLOWWRITE,0}},
	{"MC35" ,	  "MC35",	  "",				   {0}},
	{"TC35" ,	  "TC35",	  "",				   {0}},
	{"S25",		  "S25",  	  "SIEMENS S25",		   {0}},
	{"C35i" ,	  "C35i",	  "",				   {0}},
	{"S35i" ,	  "S35i",	  "",				   {0}},
	{"M35i" ,	  "M35i",	  "",				   {0}},
	{"S40" ,	  "Siemens S40",  "",			   	   {0}},
	{"C45" ,	  "C45",	  "",				   {0}},
	{"S45" ,	  "S45",	  "",				   {0}},
	{"S45i" ,	  "S45i",	  "",				   {0}},
	{"ME45" ,	  "ME45", 	  "SIEMENS ME45",		   {0}},
	{"SL45" ,	  "SL45",	  "",				   {0}},
	{"SL45i" ,	  "SL45i",	  "",				   {0}},
	{"M50" ,	  "M50",	  "",				   {0}},
	{"S45"	,	  "6618" ,	  "",				   {0}},
	{"ME45" ,	  "3618" ,	  "",				   {0}},
	{"S55" ,	  "S55" ,	  "",				   {0}},
	{"S65" ,	  "S65" , "SIEMENS S65",				   {0}},
	/* Samsung */
	{"S100" ,	  "SGH-S100" ,    "",				   {0}},
	{"S200" ,	  "SGH-S200" ,    "",				   {0}},
	{"S300" ,	  "SGH-S300" ,    "",				   {0}},
	{"S500" ,	  "SGH-S500" ,    "",				   {0}},
	{"V200" ,	  "SGH-V200" ,    "",				   {0}},
	{"T100" ,	  "SGH-T100" ,    "",				   {0}},
	{"E700" ,	  "SGH-E700" ,    "",				   {0}},
	{"X461",	  "SGH-X461" ,    "",				   {0}},

	/* Ericsson/Sony Ericsson */
	{"T28s",	"1101101-BVT28s","",				   {F_OBEX, 0}},
	{"R320s" ,	"1101201-BV R320s","",				   {F_OBEX, 0}},
	{"R380s",	"7100101-BVR380s" ,"",				   {F_OBEX, 0}},
	{"R520m",	"1130101-BVR520m" ,"",				   {F_OBEX, 0}},
	{"T39m",	"1130102-BVT39m" ,"",				   {F_OBEX, 0}},
	{"T65",		"1101901-BVT65" , "",				   {F_OBEX, 0}},
	{"T68",		"1130201-BVT68" , "",				   {F_OBEX, 0}},
	{"T68i",	"1130202-BVT68" , "",				   {F_OBEX, 0}},
	{"R600",	"102001-BVR600" , "",				   {F_OBEX, 0}},
	{"T200",	"1130501-BVT200" ,"",				   {F_OBEX, 0}},
	{"T300",	"1130601-BVT300" ,"T300",			   {F_OBEX, 0}},
	{"T310",	"1130602-BVT310" ,"",			   	   {F_OBEX, 0}},
	{"P800",	"7130501-BVP800" ,"",				   {F_OBEX, 0}},

	/* Ericsson/Sony Ericsson till 2003, not verified */
	{"T106",	"1022101-BV" ,"",				   {F_OBEX, 0}},
	{"SH888",	"1100801-BV" ,"",				   {F_OBEX, 0}},
	{"R250s PRO",	"1100802-BV" ,"",				   {F_OBEX, 0}},
	{"A1018s",	"1100901-BV" ,"",				   {F_OBEX, 0}},
	{"A1018sc",	"1100901-CN" ,"",				   {F_OBEX, 0}},
	{"A1028s",	"1100902-BV" ,"",				   {F_OBEX, 0}},
	{"A1028sc",	"1100902-CN" ,"",				   {F_OBEX, 0}},
	{"T18s",	"1101001-BV" ,"",				   {F_OBEX, 0}},
	{"T18sc",	"1101001-CN" ,"",				   {F_OBEX, 0}},
	{"T10s",	"1101002-BV" ,"",				   {F_OBEX, 0}},
	{"T10sc",	"1101002-CN" ,"",				   {F_OBEX, 0}},
	{"T28s",	"1101101-BC" ,"",				   {F_OBEX, 0}},
	{"T28sc",	"1101101-CN" ,"",				   {F_OBEX, 0}},
	{"R310s",	"1101102-BC" ,"",				   {F_OBEX, 0}},
	{"R310sc",	"1101102-CN" ,"",				   {F_OBEX, 0}},
	{"R320s",	"1101201-BV" ,"",				   {F_OBEX, 0}},
	{"R320sc",	"1101201-CN" ,"",				   {F_OBEX, 0}},
	{"T20e",	"1101401-BV" ,"",				   {F_OBEX, 0}},
	{"T20ec",	"1101401-CN" ,"",				   {F_OBEX, 0}},
	{"A2618s",	"1101501-BV" ,"",				   {F_OBEX, 0}},
	{"A2618sc",	"1101501-CN" ,"",				   {F_OBEX, 0}},
	{"A2628s",	"1101502-BV" ,"",				   {F_OBEX, 0}},
	{"A2628sc",	"1101502-CN" ,"",				   {F_OBEX, 0}},
	{"T29s",	"1101601-BV" ,"",				   {F_OBEX, 0}},
	{"T29sc",	"1101601-CN" ,"",				   {F_OBEX, 0}},
	{"A3618s",	"1101801-BV" ,"",				   {F_OBEX, 0}},
	{"A3618sc",	"1101801-CN" ,"",				   {F_OBEX, 0}},
	{"T65",		"1101901-BV" ,"",				   {F_OBEX, 0}},
	{"T65",		"1101901-CN" ,"",				   {F_OBEX, 0}},
	{"R600",	"1102001-BV" ,"",				   {F_OBEX, 0}},
	{"R602",	"1102001-CN" ,"",				   {F_OBEX, 0}},
	{"T100",	"1102101-BV" ,"",				   {F_OBEX, 0}},
	{"T102",	"1102101-BV" ,"",				   {F_OBEX, 0}},
	{"T105",	"1102101-BV" ,"",				   {F_OBEX, 0}},
	{"T100",	"1102101-CN" ,"",				   {F_OBEX, 0}},
	{"T102",	"1102101-CN" ,"",				   {F_OBEX, 0}},
	{"T105",	"1102101-CN" ,"",				   {F_OBEX, 0}},
	{"R520m",	"1130101-BV" ,"",				   {F_OBEX, 0}},
	{"R520mc",	"1130101-CN" ,"",				   {F_OBEX, 0}},
	{"T39m",	"1130102-BV" ,"",				   {F_OBEX, 0}},
	{"T39mc",	"1130102-CN" ,"",				   {F_OBEX, 0}},
	{"T68",		"1130201-BV" ,"",				   {F_OBEX, 0}},
	{"T68",		"1130201-CN" ,"",				   {F_OBEX, 0}},
	{"T68i",	"1130202-BV" ,"",				   {F_OBEX, 0}},
	{"T68ie",	"1130202-CN" ,"",				   {F_OBEX, 0}},
	{"T66",		"1130401-BV" ,"",				   {F_OBEX, 0}},
	{"T66",		"1130401-CN" ,"",				   {F_OBEX, 0}},
	{"T600",	"1130402-BV" ,"",				   {F_OBEX, 0}},
	{"T602",	"1130402-CN" ,"",				   {F_OBEX, 0}},
	{"T200",	"1130501-BV" ,"",				   {F_OBEX, 0}},
	{"T202",	"1130501-CN" ,"",				   {F_OBEX, 0}},
	{"T300",	"1130601-BV" ,"",				   {F_OBEX, 0}},
	{"T302",	"1130601-CN" ,"",				   {F_OBEX, 0}},
	{"T310",	"1130602-BV" ,"",				   {F_OBEX, 0}},
	{"T312",	"1130602-CN" ,"",				   {F_OBEX, 0}},
	{"T28 WORLD",	"1141101-BV" ,"",				   {F_OBEX, 0}},
	{"R190",	"1150101-BV" ,"",				   {F_OBEX, 0}},
	{"R290",	"1180101-BV" ,"",				   {F_OBEX, 0}},
	{"T106",	"1222101-BV" ,"",				   {F_OBEX, 0}},
	{"T608",	"1250101-BV" ,"",				   {F_OBEX, 0}},
	{"T306",	"1260101-BV" ,"",				   {F_OBEX, 0}},
	{"T316",	"1260102-BV" ,"",				   {F_OBEX, 0}},
	{"T106 850",	"1272101-BV" ,"",				   {F_OBEX, 0}},
	{"GM12",	"6050102-BV" ,"",				   {F_OBEX, 0}},
	{"GM22",	"6100201-BV" ,"",				   {F_OBEX, 0}},
	{"GM25",	"6100202-BV" ,"",				   {F_OBEX, 0}},
	{"GM47",	"6100501-BV" ,"",				   {F_OBEX, 0}},
	{"GM27",	"6100502-BV" ,"",				   {F_OBEX, 0}},
	{"GM29",	"6100503-BV" ,"",				   {F_OBEX, 0}},
	{"GM41",	"6100504-BV" ,"",				   {F_OBEX, 0}},
	{"GR47",	"6100511-BV" ,"",				   {F_OBEX, 0}},
	{"GT47",	"6100512-BV" ,"",				   {F_OBEX, 0}},
	{"GC75",	"6130201-BV" ,"",				   {F_OBEX, 0}},
	{"GC25",	"6150101-BV" ,"",				   {F_OBEX, 0}},
	{"GM48",	"6220501-BV" ,"",				   {F_OBEX, 0}},
	{"GM28",	"6220502-BV" ,"",				   {F_OBEX, 0}},
	{"GR48",	"6220511-BV" ,"",				   {F_OBEX, 0}},
	{"GT48",	"6220512-BV" ,"",				   {F_OBEX, 0}},
	{"R380s",	"7100101-BV" ,"",				   {F_OBEX, 0}},
	{"R380sc",	"7100101-CN" ,"",				   {F_OBEX, 0}},
	{"P800",	"7130501-BV" ,"",				   {F_OBEX, 0}},
	{"P802",	"7130501-CN" ,"",				   {F_OBEX, 0}},
	{"R380s world",	"7140101-BV" ,"",				   {F_OBEX, 0}},

/* Sony-Ericsson since 2003, partly not verified  */
	{"T230",	"AAA-1001012-BV" ,"",				   {F_OBEX, 0}},
	{"T228",	"AAA-1001012-CN" ,"",				   {F_OBEX, 0}},
	{"T290i",	"AAA-1001013-BV" ,"",				   {F_OBEX, 0}},
	{"T290c",	"AAA-1001013-CN" ,"",				   {F_OBEX, 0}},
	{"J300i/J300c",	"AAA-1001021-BV" ,"",				   {F_OBEX, 0}},
	{"Z300i/Z300c",	"AAA-1001031-BV" ,"",				   {F_OBEX, 0}},
	{"J230i/J230c",	"AAA-1002011-BV" ,"",				   {F_OBEX, 0}},
	{"J220i/J220c",	"AAA-1002012-BV" ,"",				   {F_OBEX, 0}},
	{"J100i/J100c",	"AAA-1002021-BV" ,"",				   {F_OBEX, 0}},
	{"T250i/T250c",	"AAA-1002031-BV" ,"",				   {F_OBEX, 0}},
	{"J120i/J120c",	"AAA-1002041-BV" ,"",				   {F_OBEX, 0}},
	{"J110i/J110c",	"AAA-1002042-BV" ,"",				   {F_OBEX, 0}},
	{"K200i/K220c",	"AAA-1002051-BV" ,"",				   {F_OBEX, 0}},
	{"K220i/K220c",	"AAA-1002052-BV" ,"",				   {F_OBEX, 0}},
	{"T226",	"AAA-1041011-BV" ,"",				   {F_OBEX, 0}},
	{"T226s/T237m",	"AAA-1041012-BV" ,"",				   {F_OBEX, 0}},
	{"J300a",	"AAA-1041021-BV" ,"",				   {F_OBEX, 0}},
	{"Z300a",	"AAA-1041031-BV" ,"",				   {F_OBEX, 0}},
	{"J230a",	"AAA-1042011-BV" ,"",				   {F_OBEX, 0}},
	{"J220a",	"AAA-1042012-BV" ,"",				   {F_OBEX, 0}},
	{"J100a",	"AAA-1042021-BV" ,"",				   {F_OBEX, 0}},
	{"T250a",	"AAA-1042031-BV" ,"",				   {F_OBEX, 0}},
	{"J110a",	"AAA-1042041-BV" ,"",				   {F_OBEX, 0}},
	{"K200a",	"AAA-1042051-BV" ,"",				   {F_OBEX, 0}},
	{"T292a",	"AAA-1061011-BV" ,"",				   {F_OBEX, 0}},
	{"T610",	"AAB-1021011-BV" ,"",				   {F_OBEX, 0}},
	{"T618",	"AAB-1021011-CN" ,"",				   {F_OBEX, 0}},
	{"T630",	"AAB-1021012-BV" ,"",				   {F_OBEX, 0}},
	{"T628",	"AAB-1021012-CN" ,"",				   {F_OBEX, 0}},
	{"Z200",	"AAB-1021021-BV" ,"",				   {F_OBEX, 0}},
	{"Z208",	"AAB-1021021-CN" ,"",				   {F_OBEX, 0}},
	{"Z600",	"AAB-1021031-BV" ,"",				   {F_OBEX, 0}},
	{"Z608",	"AAB-1021031-CN" ,"",				   {F_OBEX, 0}},
	{"K700i",	"AAB-1021041-BV" ,"",				   {F_OBEX, 0}},
	{"K700c",	"AAB-1021041-CN" ,"",				   {F_OBEX, 0}},
	{"F500i",	"AAB-1021042-BV" ,"",				   {F_OBEX, 0}},
	{"K506c",	"AAB-1021042-CN" ,"",				   {F_OBEX, 0}},
	{"K500i",	"AAB-1021043-BV" ,"",				   {F_OBEX, 0}},
	{"K500c",	"AAB-1021043-CN" ,"",				   {F_OBEX, 0}},
	{"K508i",	"AAB-1021044-BV" ,"",				   {F_OBEX, 0}},
	{"K508c",	"AAB-1021044-CN" ,"",				   {F_OBEX, 0}},
	{"S700i",	"AAB-1021051-BV" ,"",				   {F_OBEX, 0}},
	{"S700c",	"AAB-1021051-CN" ,"",				   {F_OBEX, 0}},
	{"J200i",	"AAB-1021061-BV" ,"",				   {F_OBEX, 0}},
	{"J200c",	"AAB-1021061-CN" ,"",				   {F_OBEX, 0}},
	{"J210i",	"AAB-1021062-BV" ,"",				   {F_OBEX, 0}},
	{"J210c",	"AAB-1021062-CN" ,"",				   {F_OBEX, 0}},
	{"K300i/K300c",	"AAB-1021071-BV" ,"",				   {F_OBEX, 0}},
	{"K750i/K750c",	"AAB-1022011-BV" ,"",				   {F_OBEX, 0}},
	{"D750i/K758c",	"AAB-1022012-BV" ,"",				   {F_OBEX, 0}},
	{"W800i/W800c",	"AAB-1022013-BV" ,"",				   {F_OBEX, 0}},
	{"W700i/W700c",	"AAB-1022014-BV" ,"",				   {F_OBEX, 0}},
	{"Z550i/Z550c",	"AAB-1022015-BV" ,"",				   {F_OBEX, 0}},
	{"Z558i/Z558c",	"AAB-1022016-BV" ,"",				   {F_OBEX, 0}},
	{"W550i/W550c",	"AAB-1022021-BV" ,"",				   {F_OBEX, 0}},
	{"Z530i/Z530c",	"AAB-1022031-BV" ,"",				   {F_OBEX, 0}},
	{"K510i/K510c",	"AAB-1022041-BV" ,"",				   {F_OBEX, 0}},
	{"K310i/K310c",	"AAB-1022042-BV" ,"",				   {F_OBEX, 0}},
	{"K320i/K320c",	"AAB-1022043-BV" ,"",				   {F_OBEX, 0}},
	{"W200i/W200c",	"AAB-1022044-BV" ,"",				   {F_OBEX, 0}},
	{"Z310i/Z310c",	"AAB-1022051-BV" ,"",				   {F_OBEX, 0}},
	{"W830i/W830c",	"AAB-1022061-BV" ,"",				   {F_OBEX, 0}},
	{"W888c",	"AAB-1022071-BV" ,"",				   {F_OBEX, 0}},
	{"K818c",	"AAB-1022081-BV" ,"",				   {F_OBEX, 0}},
	{"T616",	"AAB-1031011-BV" ,"",				   {F_OBEX, 0}},
	{"T637",	"AAB-1031012-BV" ,"",				   {F_OBEX, 0}},
	{"K300a",	"AAB-1031021-BV" ,"",				   {F_OBEX, 0}},
	{"K510a",	"AAB-1032011-BV" ,"",				   {F_OBEX, 0}},
	{"K310a",	"AAB-1032012-BV" ,"",				   {F_OBEX, 0}},
	{"W200a",	"AAB-1032013-BV" ,"",				   {F_OBEX, 0}},
	{"Z310a",	"AAB-1032021-BV" ,"",				   {F_OBEX, 0}},
	{"Z520i/Z520c",	"AAC-1052011-BV" ,"",				   {F_OBEX, 0}},
	{"Z520a",	"AAC-1052012-BV" ,"",				   {F_OBEX, 0}},
	{"Z525i",	"AAC-1052013-BV" ,"",				   {F_OBEX, 0}},
	{"Z525a",	"AAC-1052014-BV" ,"",				   {F_OBEX, 0}},
	{"K550i/K550c",	"AAC-1052021-BV" ,"",				   {F_OBEX, 0}},
	{"W610i/W610c",	"AAC-1052022-BV" ,"",				   {F_OBEX, 0}},
	{"K550im",	"AAC-1052023-BV" ,"",				   {F_OBEX, 0}},
	{"Z550a",	"AAC-1052031-BV" ,"",				   {F_OBEX, 0}},
	{"S500i/S500c",	"AAC-1052041-BV" ,"",				   {F_OBEX, 0}},
	{"W580i/W580c",	"AAC-1052042-BV" ,"",				   {F_OBEX, 0}},
	{"Z1010",	"AAD-3011011-BV" ,"",				   {F_OBEX, 0}},
	{"V800/V802SE/Z800i",	"AAD-3021011-BV" ,"",				   {F_OBEX, 0}},
	{"K600i",	"AAD-3021021-BV" ,"",				   {F_OBEX, 0}},
	{"V600i",	"AAD-3021022-BV" ,"",				   {F_OBEX, 0}},
	{"K608i",	"AAD-3021023-BV" ,"",				   {F_OBEX, 0}},
	{"W900i",	"AAD-3022011-BV" ,"",				   {F_OBEX, 0}},
	{"W850i",	"AAD-3022021-BV" ,"",				   {F_OBEX, 0}},
	{"K800i",	"AAD-3022031-BV" ,"",				   {F_OBEX, 0}},
	{"K610i",	"AAD-3022041-BV" ,"",				   {F_OBEX, 0}},
	{"K618i/V630i",	"AAD-3022042-BV" ,"",				   {F_OBEX, 0}},
	{"K610im",	"AAD-3022043-BV" ,"",				   {F_OBEX, 0}},
	{"Z610i",	"AAD-3022044-BV" ,"",				   {F_OBEX, 0}},
	{"W880i",	"AAD-3022051-BV" ,"",				   {F_OBEX, 0}},
	{"K810i",	"AAD-3022061-BV" ,"",				   {F_OBEX, 0}},
	{"K530i",	"AAD-3022091-BV" ,"",				   {F_OBEX, 0}},
	{"K790i/K790c",	"AAF-1022011-BV" ,"",				   {F_OBEX, 0}},
	{"Z500a",	"AAF-1031011-BV" ,"",				   {F_OBEX, 0}},
	{"S710a",	"AAF-1031021-BV" ,"",				   {F_OBEX, 0}},
	{"K790a",	"AAF-1032011-BV" ,"",				   {F_OBEX, 0}},
	{"W712a",	"AAF-1042011-BV" ,"",				   {F_OBEX, 0}},
	{"Z712a",	"AAF-1042012-BV" ,"",				   {F_OBEX, 0}},
	{"W600a/W600c/W600i",	"AAF-1052021-BV" ,"",				   {F_OBEX, 0}},
	{"W300i/W300c",	"AAF-1052031-BV" ,"",				   {F_OBEX, 0}},
	{"W710i/W710c",	"AAF-1052041-BV" ,"",				   {F_OBEX, 0}},
	{"W810i/W810c",	"AAF-1052051-BV" ,"",				   {F_OBEX, 0}},
	{"Z502a",	"AAF-1061011-BV" ,"",				   {F_OBEX, 0}},
	{"GR64",	"BAC-1051012-BV" ,"",				   {F_OBEX, 0}},
	{"GS64",	"BAC-1051022-BV" ,"",				   {F_OBEX, 0}},
	{"GA64",	"BAC-1051023-BV" ,"",				   {F_OBEX, 0}},
	{"CM52",	"BAE-4001011-BV" ,"",				   {F_OBEX, 0}},
	{"CM52",	"BAE-4001012-BV" ,"",				   {F_OBEX, 0}},
	{"GC82",	"FAA-1041011-BV" ,"",				   {F_OBEX, 0}},
	{"P900",	"FAB-1021011-BV" ,"",				   {F_OBEX, 0}},
	{"P908",	"FAB-1021011-CN" ,"",				   {F_OBEX, 0}},
	{"P910i",	"FAB-1021012-BV" ,"",				   {F_OBEX, 0}},
	{"P910c",	"FAB-1021012-CN" ,"",				   {F_OBEX, 0}},
	{"M608c",	"FAB-1022011-BV" ,"",				   {F_OBEX, 0}},
	{"W958c",	"FAB-1022012-BV" ,"",				   {F_OBEX, 0}},
	{"P1c",		"FAB-1022013-BV" ,"",				   {F_OBEX, 0}},
	{"P910a",	"FAB-1031012-BV" ,"",				   {F_OBEX, 0}},
	{"P990i",	"FAD-3022011-BV" ,"",				   {F_OBEX, 0}},
	{"M600i",	"FAD-3022012-BV" ,"",				   {F_OBEX, 0}},
	{"W950i",	"FAD-3022013-BV" ,"",				   {F_OBEX, 0}},
	{"P1i",		"FAD-3022015-BV" ,"",				   {F_OBEX, 0}},
	{"GC99",	"FAD-3031012-BV" ,"",				   {F_OBEX, 0}},
	{"GC79",	"FAE-1021011-BV" ,"",				   {F_OBEX, F_SMS_LOCATION_0, 0}},
	{"GC85",	"FAF-1021011-BV" ,"",				   {F_OBEX, 0}},
	{"GC83",	"FAF-1031011-BV" ,"",				   {F_OBEX, 0}},
	{"VDC",		"FAF-1031021-BV" ,"",				   {F_OBEX, 0}},
	{"GC89",	"FAF-1051011-BV" ,"",				   {F_OBEX, 0}},
	{"GC86",	"FAF-1051012-BV" ,"",				   {F_OBEX, 0}},


	/* Some cards identify a bit different */
	{"GC79",	"FAE-1021011-BVGC79" ,"",			   {F_OBEX, F_SMS_LOCATION_0, 0}},

	/* IrDA identifications for Sony-Ericsson */
	/* At least my K750i reports itself as "Sony Ericss", so detect it for IrDA */
	{"Generic SE",	"Generic SE", "Sony Ericss",			   {F_OBEX, 0}},
	{"K300 series",	"K300 series", "K300 series",			   {F_OBEX, 0}},
	{"K700 series",	"K700 series", "K700 series",			   {F_OBEX, 0}},

	/* Mitsubishi */
	{"M341i",	"M7", "MT170",					   {F_OBEX, F_IRMC_LEVEL_2, 0}},

	/* Motorola */
	{"V3",		"V3 Razr", "",					   {F_OBEX, F_IRMC_LEVEL_2, F_MODE22, 0}},
	{"L6",		"L6", "",					   {F_OBEX, F_IRMC_LEVEL_2, F_MODE22, 0}},

	/* Other */
	{"iPAQ" ,	  "iPAQ"  ,	  "" ,				   {0}},
	{"A2D"  ,	  "A2D"  ,	  "" ,				   {0}},
	{"9210" ,	  "RAE-3",	  "Nokia Communicator GSM900/1800",{0}},

	/* Sagem */
	{"myV-65",	"myV-65 GPRS",	  "",				   {F_SMSME900,0}},

	/* LG */
	{"KG800", "KG800", "", {F_NO_UCS2, 0}},
#endif
#if defined(GSM_ENABLE_ATGEN) || defined(GSM_ENABLE_ALCATEL)
	/* Alcatel */
	{"BE5", 	  "ONE TOUCH 500","",				   {F_ALCATEL,F_SMSONLYSENT,F_BROKENCPBS,0}},
	{"BH4",		  "ONE TOUCH 535","ALCATEL OT535",		   {F_ALCATEL,F_SMSONLYSENT,0}},
	{"BF5", 	  "ONE TOUCH 715","ALCATEL OT715",		   {F_ALCATEL,F_SMSONLYSENT,F_BROKENCPBS,0}},
	{"OT - C55x",	  "OT - C55x","ALCATEL OT55x",			   {F_ALCATEL,0}},
#endif
	{"unknown",	  ""      ,"",           {0}}
};

OnePhoneModel *GetModelData(char *model, char *number, char *irdamodel)
{
	int i = 0;

	while (strcmp(allmodels[i].number,"") != 0) {
		if (model !=NULL) {
			if (strcmp (model, allmodels[i].model) == 0) {
				return (&allmodels[i]);
			}
		}
		if (number !=NULL) {
			if (strcmp (number, allmodels[i].number) == 0) {
				return (&allmodels[i]);
			}
		}
		if (irdamodel !=NULL) {
			if (strcmp (irdamodel, allmodels[i].irdamodel) == 0) {
				return (&allmodels[i]);
			}
		}
		i++;
	}
	return (&allmodels[i]);
}

bool GSM_IsPhoneFeatureAvailable(OnePhoneModel *model, Feature feature)
{
	int	i	= 0;

	while (model->features[i] != 0) {
		if (model->features[i] == feature) {
			return true;
		}
		i++;
	}
	return false;
}

/* How should editor hadle tabs in this file? Add editor commands here.
 * vim: noexpandtab sw=8 ts=8 sts=8:
 */
