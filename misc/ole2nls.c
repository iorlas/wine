/*
 *	OLE2NLS library
 *
 *	Copyright 1995	Martin von Loewis
 */

/*	At the moment, these are only empty stubs.
 */

#include <string.h>
#include "windows.h"
#include "ole.h"
#include "options.h"
#include "winnls.h"
#include "stddebug.h"
#include "debug.h"

/***********************************************************************
 *           GetUserDefaultLCID       (OLE2NLS.1)
 */
DWORD GetUserDefaultLCID()
{
/* Default sorting, neutral sublanguage */
    switch(Options.language)
    {
 /* case LANG_Bu: return 0x02; */      /* Bulgarian */
 /* case LANG_Ch: return 0x04; */      /* Chinese */
    case LANG_Cz: return 0x05;         /* Czech */
    case LANG_Da: return 0x06;         /* Danish */
    case LANG_De: return 0x07;         /* German */
 /* case LANG_Gr: return 0x08; */      /* Greek */
    case LANG_En: return 0x09;         /* English */
    case LANG_Es: return 0x0a;         /* Spanish */
    case LANG_Fi: return 0x0b;         /* Finnish */
    case LANG_Fr: return 0x0c;         /* French */
 /* case LANG_Hu: return 0x0e; */      /* Hungarian */
 /* case LANG_Ic: return 0x0f; */      /* Icelandic */
    case LANG_It: return 0x10;         /* Italian */
 /* case LANG_Jp: return 0x11; */      /* Japanese */
    case LANG_Ko: return 0x12;         /* Korean */
 /* case LANG_Du: return 0x13; */      /* Dutch */
    case LANG_No: return 0x14;         /* Norwegian */
 /* case LANG_Pl: return 0x15; */      /* Polish */
 /* case LANG_Po: return 0x16; */      /* Portuguese */
 /* case LANG_Ro: return 0x18; */      /* Romanian */
 /* case LANG_Ru: return 0x19; */      /* Russian */
 /* case LANG_Cr: return 0x1a; */      /* Croatian */
 /* case LANG_Sl: return 0x1b; */      /* Slovak */
 /* case LANG_Sw: return 0x1d; */      /* Swedish */
 /* case LANG_Tu: return 0x1f; */      /* Turkish */
 /* case LANG_Sv: return 0x24; */      /* Slovenian */
    case LANG_Eo: return 0x25;         /* Esperanto (not official) */

    default:
	return 0x00;                   /* Neutral language */
    }
}

/***********************************************************************
 *         GetSystemDefaultLCID       (OLE2NLS.2)
 */
DWORD GetSystemDefaultLCID()
{
	return GetUserDefaultLCID();
}

/***********************************************************************
 *         GetUserDefaultLangID       (OLE2NLS.3)
 */
WORD GetUserDefaultLangID()
{
	return (WORD)GetUserDefaultLCID();
}

/***********************************************************************
 *         GetSystemDefaultLangID     (OLE2NLS.4)
 */
WORD GetSystemDefaultLangID()
{
	return GetUserDefaultLangID();
}

/***********************************************************************
 *         GetLocaleInfoA             (OLE2NLS.5)
 * Is the last parameter really WORD for Win16?
 */
int GetLocaleInfoA(DWORD lcid,DWORD LCType,LPSTR buf,WORD len)
{
	char *retString;
    int retLen;
    dprintf_ole(stddeb,"GetLocaleInfoA(%8lX,%8lX,%p,%4X)\n",
			lcid,LCType,buf,len);
#if 0
	/* Wine is supporting only the default locale */
	if(lcid!=GetUserDefaultLCID())
	{
		dprintf_ole(stdnimp,"GetLocaleInfoA: Unknown locale\n");
		return 0;
	}
#endif
	/* As an option, we could obtain the value from win.ini.
	   This would not match the Wine compile-time option.
	   Also, not all identifiers are available from win.ini */
	retString=0;
	retLen=0;
	/* If we are through all of this, retLen should not be zero anymore.
	   If it is, the value is not supported */
#define LOCVAL(type,value)	if(type==LCType)			\
								{retLen=strlen(value)+1;\
								 retString=value;       \
								}
#define UNSUPPORTED(type)   if(type==lcid)retString=#type;

/* I really wish I would know a better way to do this */
UNSUPPORTED(LOCALE_ILANGUAGE)
UNSUPPORTED(LOCALE_SLANGUAGE)
UNSUPPORTED(LOCALE_SENGLANGUAGE)
UNSUPPORTED(LOCALE_SABBREVLANGNAME)
UNSUPPORTED(LOCALE_SNATIVELANGNAME)
UNSUPPORTED(LOCALE_ICOUNTRY)
UNSUPPORTED(LOCALE_SCOUNTRY)
UNSUPPORTED(LOCALE_SENGCOUNTRY)
UNSUPPORTED(LOCALE_SABBREVCTRYNAME)
UNSUPPORTED(LOCALE_SNATIVECTRYNAME)
UNSUPPORTED(LOCALE_IDEFAULTLANGUAGE)
UNSUPPORTED(LOCALE_IDEFAULTCOUNTRY)
UNSUPPORTED(LOCALE_IDEFAULTCODEPAGE)
UNSUPPORTED(LOCALE_IDEFAULTANSICODEPAGE)
UNSUPPORTED(LOCALE_SLIST)
UNSUPPORTED(LOCALE_IMEASURE)
UNSUPPORTED(LOCALE_SDECIMAL)
UNSUPPORTED(LOCALE_STHOUSAND)
UNSUPPORTED(LOCALE_SGROUPING)
UNSUPPORTED(LOCALE_IDIGITS)
UNSUPPORTED(LOCALE_ILZERO)
UNSUPPORTED(LOCALE_INEGNUMBER)
UNSUPPORTED(LOCALE_SNATIVEDIGITS)
UNSUPPORTED(LOCALE_SCURRENCY)
UNSUPPORTED(LOCALE_SINTLSYMBOL)
UNSUPPORTED(LOCALE_SMONDECIMALSEP)
UNSUPPORTED(LOCALE_SMONTHOUSANDSEP)
UNSUPPORTED(LOCALE_SMONGROUPING)
UNSUPPORTED(LOCALE_ICURRDIGITS)
UNSUPPORTED(LOCALE_IINTLCURRDIGITS)
UNSUPPORTED(LOCALE_ICURRENCY)
UNSUPPORTED(LOCALE_INEGCURR)
UNSUPPORTED(LOCALE_SDATE)
UNSUPPORTED(LOCALE_STIME)
UNSUPPORTED(LOCALE_SSHORTDATE)
UNSUPPORTED(LOCALE_SLONGDATE)
UNSUPPORTED(LOCALE_STIMEFORMAT)
UNSUPPORTED(LOCALE_IDATE)
UNSUPPORTED(LOCALE_ILDATE)
UNSUPPORTED(LOCALE_ITIME)
UNSUPPORTED(LOCALE_ITIMEMARKPOSN)
UNSUPPORTED(LOCALE_ICENTURY)
UNSUPPORTED(LOCALE_ITLZERO)
UNSUPPORTED(LOCALE_IDAYLZERO)
UNSUPPORTED(LOCALE_IMONLZERO)
UNSUPPORTED(LOCALE_S1159)
UNSUPPORTED(LOCALE_S2359)
UNSUPPORTED(LOCALE_ICALENDARTYPE)
UNSUPPORTED(LOCALE_IOPTIONALCALENDAR)
UNSUPPORTED(LOCALE_IFIRSTDAYOFWEEK)
UNSUPPORTED(LOCALE_IFIRSTWEEKOFYEAR)
UNSUPPORTED(LOCALE_SDAYNAME1)
UNSUPPORTED(LOCALE_SDAYNAME2)
UNSUPPORTED(LOCALE_SDAYNAME3)
UNSUPPORTED(LOCALE_SDAYNAME4)
UNSUPPORTED(LOCALE_SDAYNAME5)
UNSUPPORTED(LOCALE_SDAYNAME6)
UNSUPPORTED(LOCALE_SDAYNAME7)
UNSUPPORTED(LOCALE_SABBREVDAYNAME1)
UNSUPPORTED(LOCALE_SABBREVDAYNAME2)
UNSUPPORTED(LOCALE_SABBREVDAYNAME3)
UNSUPPORTED(LOCALE_SABBREVDAYNAME4)
UNSUPPORTED(LOCALE_SABBREVDAYNAME5)
UNSUPPORTED(LOCALE_SABBREVDAYNAME6)
UNSUPPORTED(LOCALE_SABBREVDAYNAME7)
UNSUPPORTED(LOCALE_SMONTHNAME1)
UNSUPPORTED(LOCALE_SMONTHNAME2)
UNSUPPORTED(LOCALE_SMONTHNAME3)
UNSUPPORTED(LOCALE_SMONTHNAME4)
UNSUPPORTED(LOCALE_SMONTHNAME5)
UNSUPPORTED(LOCALE_SMONTHNAME6)
UNSUPPORTED(LOCALE_SMONTHNAME7)
UNSUPPORTED(LOCALE_SMONTHNAME8)
UNSUPPORTED(LOCALE_SMONTHNAME9)
UNSUPPORTED(LOCALE_SMONTHNAME10)
UNSUPPORTED(LOCALE_SMONTHNAME11)
UNSUPPORTED(LOCALE_SMONTHNAME12)
UNSUPPORTED(LOCALE_SMONTHNAME13)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME1)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME2)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME3)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME4)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME5)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME6)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME7)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME8)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME9)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME10)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME11)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME12)
UNSUPPORTED(LOCALE_SABBREVMONTHNAME13)
UNSUPPORTED(LOCALE_SPOSITIVESIGN)
UNSUPPORTED(LOCALE_SNEGATIVESIGN)
UNSUPPORTED(LOCALE_IPOSSIGNPOSN)
UNSUPPORTED(LOCALE_INEGSIGNPOSN)
UNSUPPORTED(LOCALE_IPOSSYMPRECEDES)
UNSUPPORTED(LOCALE_IPOSSEPBYSPACE)
UNSUPPORTED(LOCALE_INEGSYMPRECEDES)
UNSUPPORTED(LOCALE_INEGSEPBYSPACE)

/* Now, the language specific definitions. They don't have to be
   complete */
    switch(Options.language)
    {
    case LANG_De:
/* This definitions apply to Germany only. Users in Austria 
   or Switzerland might want to modify them */
LOCVAL(LOCALE_ILANGUAGE,"9")
LOCVAL(LOCALE_SLANGUAGE,"Deutsch")
LOCVAL(LOCALE_SENGLANGUAGE,"German")
LOCVAL(LOCALE_SABBREVLANGNAME,"deu")
LOCVAL(LOCALE_SNATIVELANGNAME,"Deutsch")
LOCVAL(LOCALE_ICOUNTRY,"49")
LOCVAL(LOCALE_SCOUNTRY,"Deutschland")
LOCVAL(LOCALE_SENGCOUNTRY,"Deutschland")
LOCVAL(LOCALE_SABBREVCTRYNAME,"De")
LOCVAL(LOCALE_SNATIVECTRYNAME,"Deutschland")
LOCVAL(LOCALE_IDEFAULTLANGUAGE,"9")
LOCVAL(LOCALE_IDEFAULTCOUNTRY,"49")
/* Dunno
LOCVAL(LOCALE_IDEFAULTCODEPAGE)
LOCVAL(LOCALE_IDEFAULTANSICODEPAGE)
*/
LOCVAL(LOCALE_SLIST,";")
LOCVAL(LOCALE_IMEASURE,"0")
LOCVAL(LOCALE_SDECIMAL,",")
LOCVAL(LOCALE_STHOUSAND,".")
/*
LOCVAL(LOCALE_SGROUPING)
*/
LOCVAL(LOCALE_IDIGITS,"2")
LOCVAL(LOCALE_ILZERO,"1")
/*
LOCVAL(LOCALE_INEGNUMBER)
Is this "0123456789" ??
LOCVAL(LOCALE_SNATIVEDIGITS)
*/
LOCVAL(LOCALE_SCURRENCY,"DM")
/*
LOCVAL(LOCALE_SINTLSYMBOL)
LOCVAL(LOCALE_SMONDECIMALSEP)
LOCVAL(LOCALE_SMONTHOUSANDSEP)
LOCVAL(LOCALE_SMONGROUPING)
*/
LOCVAL(LOCALE_ICURRDIGITS,"2")
/*
LOCVAL(LOCALE_IINTLCURRDIGITS)
*/
LOCVAL(LOCALE_ICURRENCY,"3")
LOCVAL(LOCALE_INEGCURR,"8")
LOCVAL(LOCALE_SDATE,".")
LOCVAL(LOCALE_STIME,":")
LOCVAL(LOCALE_SSHORTDATE,"dd.MM.yyyy")
LOCVAL(LOCALE_SLONGDATE,"ddd, d. MMMM yyyy")
/*
LOCVAL(LOCALE_STIMEFORMAT)
*/
LOCVAL(LOCALE_IDATE,"1")
/*
LOCVAL(LOCALE_ILDATE)
*/
LOCVAL(LOCALE_ITIME,"1")
/*
LOCVAL(LOCALE_ITIMEMARKPOSN)
LOCVAL(LOCALE_ICENTURY)
*/
LOCVAL(LOCALE_ITLZERO,"1")
/*
LOCVAL(LOCALE_IDAYLZERO)
LOCVAL(LOCALE_IMONLZERO)
LOCVAL(LOCALE_S1159)
LOCVAL(LOCALE_S2359)
LOCVAL(LOCALE_ICALENDARTYPE)
LOCVAL(LOCALE_IOPTIONALCALENDAR)
LOCVAL(LOCALE_IFIRSTDAYOFWEEK)
LOCVAL(LOCALE_IFIRSTWEEKOFYEAR)
*/
LOCVAL(LOCALE_SDAYNAME1,"Montag")
LOCVAL(LOCALE_SDAYNAME2,"Dienstag")
LOCVAL(LOCALE_SDAYNAME3,"Mittwoch")
LOCVAL(LOCALE_SDAYNAME4,"Donnerstag")
LOCVAL(LOCALE_SDAYNAME5,"Freitag")
LOCVAL(LOCALE_SDAYNAME6,"Sonnabend")
LOCVAL(LOCALE_SDAYNAME7,"Sonntag")
LOCVAL(LOCALE_SABBREVDAYNAME1,"Mo")
LOCVAL(LOCALE_SABBREVDAYNAME2,"Di")
LOCVAL(LOCALE_SABBREVDAYNAME3,"Mi")
LOCVAL(LOCALE_SABBREVDAYNAME4,"Do")
LOCVAL(LOCALE_SABBREVDAYNAME5,"Fr")
LOCVAL(LOCALE_SABBREVDAYNAME6,"Sa")
LOCVAL(LOCALE_SABBREVDAYNAME7,"So")
LOCVAL(LOCALE_SMONTHNAME1,"Januar")
LOCVAL(LOCALE_SMONTHNAME2,"Februar")
LOCVAL(LOCALE_SMONTHNAME3,"M�rz")
LOCVAL(LOCALE_SMONTHNAME4,"April")
LOCVAL(LOCALE_SMONTHNAME5,"Mai")
LOCVAL(LOCALE_SMONTHNAME6,"Juni")
LOCVAL(LOCALE_SMONTHNAME7,"Juli")
LOCVAL(LOCALE_SMONTHNAME8,"August")
LOCVAL(LOCALE_SMONTHNAME9,"September")
LOCVAL(LOCALE_SMONTHNAME10,"Oktober")
LOCVAL(LOCALE_SMONTHNAME11,"November")
LOCVAL(LOCALE_SMONTHNAME12,"Dezember")
LOCVAL(LOCALE_SMONTHNAME13,"")
LOCVAL(LOCALE_SABBREVMONTHNAME1,"Jan")
LOCVAL(LOCALE_SABBREVMONTHNAME2,"Feb")
LOCVAL(LOCALE_SABBREVMONTHNAME3,"M�r")
LOCVAL(LOCALE_SABBREVMONTHNAME4,"Apr")
LOCVAL(LOCALE_SABBREVMONTHNAME5,"Mai")
LOCVAL(LOCALE_SABBREVMONTHNAME6,"Jun")
LOCVAL(LOCALE_SABBREVMONTHNAME7,"Jul")
LOCVAL(LOCALE_SABBREVMONTHNAME8,"Aug")
LOCVAL(LOCALE_SABBREVMONTHNAME9,"Sep")
LOCVAL(LOCALE_SABBREVMONTHNAME10,"Okt")
LOCVAL(LOCALE_SABBREVMONTHNAME11,"Nov")
LOCVAL(LOCALE_SABBREVMONTHNAME12,"Dez")
LOCVAL(LOCALE_SABBREVMONTHNAME13,"")
/*
LOCVAL(LOCALE_SPOSITIVESIGN)
LOCVAL(LOCALE_SNEGATIVESIGN)
LOCVAL(LOCALE_IPOSSIGNPOSN)
LOCVAL(LOCALE_INEGSIGNPOSN)
LOCVAL(LOCALE_IPOSSYMPRECEDES)
LOCVAL(LOCALE_IPOSSEPBYSPACE)
LOCVAL(LOCALE_INEGSYMPRECEDES)
LOCVAL(LOCALE_INEGSEPBYSPACE)
*/
    break;  /* LANG(De) */

    case LANG_Da:
/* LOCVAL(LOCALE_ILANGUAGE,"9") */
LOCVAL(LOCALE_SLANGUAGE,"Dansk")
LOCVAL(LOCALE_SENGLANGUAGE,"Danish")
LOCVAL(LOCALE_SABBREVLANGNAME,"dan")
LOCVAL(LOCALE_SNATIVELANGNAME,"Dansk")
LOCVAL(LOCALE_ICOUNTRY,"45")
LOCVAL(LOCALE_SCOUNTRY,"Danmark")
LOCVAL(LOCALE_SENGCOUNTRY,"Denmark")
LOCVAL(LOCALE_SABBREVCTRYNAME,"Da")
LOCVAL(LOCALE_SNATIVECTRYNAME,"Danmark")
/* LOCVAL(LOCALE_IDEFAULTLANGUAGE,"9") */
LOCVAL(LOCALE_IDEFAULTCOUNTRY,"45")
/* LOCVAL(LOCALE_IDEFAULTCODEPAGE) */
/* LOCVAL(LOCALE_IDEFAULTANSICODEPAGE) */
LOCVAL(LOCALE_SLIST,";")
LOCVAL(LOCALE_IMEASURE,"0")
LOCVAL(LOCALE_SDECIMAL,",")
LOCVAL(LOCALE_STHOUSAND,".")
/* LOCVAL(LOCALE_SGROUPING) */
LOCVAL(LOCALE_IDIGITS,"2")
LOCVAL(LOCALE_ILZERO,"1")
/* LOCVAL(LOCALE_INEGNUMBER) */
/* LOCVAL(LOCALE_SNATIVEDIGITS) */
LOCVAL(LOCALE_SCURRENCY,"kr")
/* LOCVAL(LOCALE_SINTLSYMBOL) */
LOCVAL(LOCALE_SMONDECIMALSEP,",")
LOCVAL(LOCALE_SMONTHOUSANDSEP,".")
/* LOCVAL(LOCALE_SMONGROUPING) */
LOCVAL(LOCALE_ICURRDIGITS,"2")
/* LOCVAL(LOCALE_IINTLCURRDIGITS) */
LOCVAL(LOCALE_ICURRENCY,"3")
LOCVAL(LOCALE_INEGCURR,"8")
LOCVAL(LOCALE_SDATE,".")
LOCVAL(LOCALE_STIME,":")
LOCVAL(LOCALE_SSHORTDATE,"dd/MM-yyyy")
LOCVAL(LOCALE_SLONGDATE,"ddd, d. MMMM yyyy")
/* LOCVAL(LOCALE_STIMEFORMAT) */
LOCVAL(LOCALE_IDATE,"1")
/* LOCVAL(LOCALE_ILDATE) */
LOCVAL(LOCALE_ITIME,"1")
/* LOCVAL(LOCALE_ITIMEMARKPOSN) */
/* LOCVAL(LOCALE_ICENTURY) */
LOCVAL(LOCALE_ITLZERO,"1")
/* LOCVAL(LOCALE_IDAYLZERO) */
/* LOCVAL(LOCALE_IMONLZERO) */
/* LOCVAL(LOCALE_S1159) */
/* LOCVAL(LOCALE_S2359) */
/* LOCVAL(LOCALE_ICALENDARTYPE) */
/* LOCVAL(LOCALE_IOPTIONALCALENDAR) */
/* LOCVAL(LOCALE_IFIRSTDAYOFWEEK) */
/* LOCVAL(LOCALE_IFIRSTWEEKOFYEAR) */
LOCVAL(LOCALE_SDAYNAME1,"Mandag")
LOCVAL(LOCALE_SDAYNAME2,"Tirsdag")
LOCVAL(LOCALE_SDAYNAME3,"Onsdag")
LOCVAL(LOCALE_SDAYNAME4,"Torsdag")
LOCVAL(LOCALE_SDAYNAME5,"Fredag")
LOCVAL(LOCALE_SDAYNAME6,"L�rdag")
LOCVAL(LOCALE_SDAYNAME7,"S�ndag")
LOCVAL(LOCALE_SABBREVDAYNAME1,"Ma")
LOCVAL(LOCALE_SABBREVDAYNAME2,"Ti")
LOCVAL(LOCALE_SABBREVDAYNAME3,"On")
LOCVAL(LOCALE_SABBREVDAYNAME4,"To")
LOCVAL(LOCALE_SABBREVDAYNAME5,"Fr")
LOCVAL(LOCALE_SABBREVDAYNAME6,"L�")
LOCVAL(LOCALE_SABBREVDAYNAME7,"S�")
LOCVAL(LOCALE_SMONTHNAME1,"Januar")
LOCVAL(LOCALE_SMONTHNAME2,"Februar")
LOCVAL(LOCALE_SMONTHNAME3,"Marts")
LOCVAL(LOCALE_SMONTHNAME4,"April")
LOCVAL(LOCALE_SMONTHNAME5,"Maj")
LOCVAL(LOCALE_SMONTHNAME6,"Juni")
LOCVAL(LOCALE_SMONTHNAME7,"Juli")
LOCVAL(LOCALE_SMONTHNAME8,"August")
LOCVAL(LOCALE_SMONTHNAME9,"September")
LOCVAL(LOCALE_SMONTHNAME10,"Oktober")
LOCVAL(LOCALE_SMONTHNAME11,"November")
LOCVAL(LOCALE_SMONTHNAME12,"December")
LOCVAL(LOCALE_SMONTHNAME13,"")
LOCVAL(LOCALE_SABBREVMONTHNAME1,"Jan")
LOCVAL(LOCALE_SABBREVMONTHNAME2,"Feb")
LOCVAL(LOCALE_SABBREVMONTHNAME3,"Mar")
LOCVAL(LOCALE_SABBREVMONTHNAME4,"Apr")
LOCVAL(LOCALE_SABBREVMONTHNAME5,"Maj")
LOCVAL(LOCALE_SABBREVMONTHNAME6,"Jun")
LOCVAL(LOCALE_SABBREVMONTHNAME7,"Jul")
LOCVAL(LOCALE_SABBREVMONTHNAME8,"Aug")
LOCVAL(LOCALE_SABBREVMONTHNAME9,"Sep")
LOCVAL(LOCALE_SABBREVMONTHNAME10,"Okt")
LOCVAL(LOCALE_SABBREVMONTHNAME11,"Nov")
LOCVAL(LOCALE_SABBREVMONTHNAME12,"Dec")
LOCVAL(LOCALE_SABBREVMONTHNAME13,"")
/* LOCVAL(LOCALE_SPOSITIVESIGN) */
/* LOCVAL(LOCALE_SNEGATIVESIGN) */
/* LOCVAL(LOCALE_IPOSSIGNPOSN) */
/* LOCVAL(LOCALE_INEGSIGNPOSN) */
/* LOCVAL(LOCALE_IPOSSYMPRECEDES) */
/* LOCVAL(LOCALE_IPOSSEPBYSPACE) */
/* LOCVAL(LOCALE_INEGSYMPRECEDES) */
/* LOCVAL(LOCALE_INEGSEPBYSPACE) */
    break; /* LANG(Da) */

    case LANG_En:
/* This definitions apply to Germany only. Users in Austria 
   or Switzerland might want to modify them */
LOCVAL(LOCALE_ILANGUAGE,"9")
LOCVAL(LOCALE_SLANGUAGE,"English")
LOCVAL(LOCALE_SENGLANGUAGE,"English")
LOCVAL(LOCALE_SABBREVLANGNAME,"enu")
LOCVAL(LOCALE_SNATIVELANGNAME,"English")
LOCVAL(LOCALE_ICOUNTRY,"11")
LOCVAL(LOCALE_SCOUNTRY,"Deutschland")
LOCVAL(LOCALE_SENGCOUNTRY,"Deutschland")
LOCVAL(LOCALE_SABBREVCTRYNAME,"De")
LOCVAL(LOCALE_SNATIVECTRYNAME,"Deutschland")
LOCVAL(LOCALE_IDEFAULTLANGUAGE,"9")
LOCVAL(LOCALE_IDEFAULTCOUNTRY,"49")
/* Dunno
LOCVAL(LOCALE_IDEFAULTCODEPAGE)
LOCVAL(LOCALE_IDEFAULTANSICODEPAGE)
*/
LOCVAL(LOCALE_SLIST,";")
LOCVAL(LOCALE_IMEASURE,"0")
LOCVAL(LOCALE_SDECIMAL,",")
LOCVAL(LOCALE_STHOUSAND,".")
/*
LOCVAL(LOCALE_SGROUPING)
*/
LOCVAL(LOCALE_IDIGITS,"2")
LOCVAL(LOCALE_ILZERO,"1")
/*
LOCVAL(LOCALE_INEGNUMBER)
Is this "0123456789" ??
LOCVAL(LOCALE_SNATIVEDIGITS)
*/
LOCVAL(LOCALE_SCURRENCY,"DM")
/*
LOCVAL(LOCALE_SINTLSYMBOL)
LOCVAL(LOCALE_SMONDECIMALSEP)
LOCVAL(LOCALE_SMONTHOUSANDSEP)
LOCVAL(LOCALE_SMONGROUPING)
*/
LOCVAL(LOCALE_ICURRDIGITS,"2")
/*
LOCVAL(LOCALE_IINTLCURRDIGITS)
*/
LOCVAL(LOCALE_ICURRENCY,"3")
LOCVAL(LOCALE_INEGCURR,"8")
LOCVAL(LOCALE_SDATE,".")
LOCVAL(LOCALE_STIME,":")
LOCVAL(LOCALE_SSHORTDATE,"dd.MM.yyyy")
LOCVAL(LOCALE_SLONGDATE,"ddd, d. MMMM yyyy")
/*
LOCVAL(LOCALE_STIMEFORMAT)
*/
LOCVAL(LOCALE_IDATE,"1")
/*
LOCVAL(LOCALE_ILDATE)
*/
LOCVAL(LOCALE_ITIME,"1")
/*
LOCVAL(LOCALE_ITIMEMARKPOSN)
LOCVAL(LOCALE_ICENTURY)
*/
LOCVAL(LOCALE_ITLZERO,"1")
/*
LOCVAL(LOCALE_IDAYLZERO)
LOCVAL(LOCALE_IMONLZERO)
LOCVAL(LOCALE_S1159)
LOCVAL(LOCALE_S2359)
LOCVAL(LOCALE_ICALENDARTYPE)
LOCVAL(LOCALE_IOPTIONALCALENDAR)
LOCVAL(LOCALE_IFIRSTDAYOFWEEK)
LOCVAL(LOCALE_IFIRSTWEEKOFYEAR)
*/
LOCVAL(LOCALE_SDAYNAME1,"Montag")
LOCVAL(LOCALE_SDAYNAME2,"Dienstag")
LOCVAL(LOCALE_SDAYNAME3,"Mittwoch")
LOCVAL(LOCALE_SDAYNAME4,"Donnerstag")
LOCVAL(LOCALE_SDAYNAME5,"Freitag")
LOCVAL(LOCALE_SDAYNAME6,"Sonnabend")
LOCVAL(LOCALE_SDAYNAME7,"Sonntag")
LOCVAL(LOCALE_SABBREVDAYNAME1,"Mo")
LOCVAL(LOCALE_SABBREVDAYNAME2,"Di")
LOCVAL(LOCALE_SABBREVDAYNAME3,"Mi")
LOCVAL(LOCALE_SABBREVDAYNAME4,"Do")
LOCVAL(LOCALE_SABBREVDAYNAME5,"Fr")
LOCVAL(LOCALE_SABBREVDAYNAME6,"Sa")
LOCVAL(LOCALE_SABBREVDAYNAME7,"So")
LOCVAL(LOCALE_SMONTHNAME1,"Januar")
LOCVAL(LOCALE_SMONTHNAME2,"Februar")
LOCVAL(LOCALE_SMONTHNAME3,"M�rz")
LOCVAL(LOCALE_SMONTHNAME4,"April")
LOCVAL(LOCALE_SMONTHNAME5,"Mai")
LOCVAL(LOCALE_SMONTHNAME6,"Juni")
LOCVAL(LOCALE_SMONTHNAME7,"Juli")
LOCVAL(LOCALE_SMONTHNAME8,"August")
LOCVAL(LOCALE_SMONTHNAME9,"September")
LOCVAL(LOCALE_SMONTHNAME10,"Oktober")
LOCVAL(LOCALE_SMONTHNAME11,"November")
LOCVAL(LOCALE_SMONTHNAME12,"Dezember")
LOCVAL(LOCALE_SMONTHNAME13,"")
LOCVAL(LOCALE_SABBREVMONTHNAME1,"Jan")
LOCVAL(LOCALE_SABBREVMONTHNAME2,"Feb")
LOCVAL(LOCALE_SABBREVMONTHNAME3,"M�r")
LOCVAL(LOCALE_SABBREVMONTHNAME4,"Apr")
LOCVAL(LOCALE_SABBREVMONTHNAME5,"Mai")
LOCVAL(LOCALE_SABBREVMONTHNAME6,"Jun")
LOCVAL(LOCALE_SABBREVMONTHNAME7,"Jul")
LOCVAL(LOCALE_SABBREVMONTHNAME8,"Aug")
LOCVAL(LOCALE_SABBREVMONTHNAME9,"Sep")
LOCVAL(LOCALE_SABBREVMONTHNAME10,"Okt")
LOCVAL(LOCALE_SABBREVMONTHNAME11,"Nov")
LOCVAL(LOCALE_SABBREVMONTHNAME12,"Dez")
LOCVAL(LOCALE_SABBREVMONTHNAME13,"")
/*
LOCVAL(LOCALE_SPOSITIVESIGN)
LOCVAL(LOCALE_SNEGATIVESIGN)
LOCVAL(LOCALE_IPOSSIGNPOSN)
LOCVAL(LOCALE_INEGSIGNPOSN)
LOCVAL(LOCALE_IPOSSYMPRECEDES)
LOCVAL(LOCALE_IPOSSEPBYSPACE)
LOCVAL(LOCALE_INEGSYMPRECEDES)
LOCVAL(LOCALE_INEGSEPBYSPACE)
*/
    break;  /* LANG(En) */

    case LANG_Eo:
/* LOCVAL(LOCALE_ILANGUAGE,"9") ISO numerical ID for language TODO */
LOCVAL(LOCALE_SLANGUAGE,"Esperanto")
LOCVAL(LOCALE_SENGLANGUAGE,"Esperanto")
/* LOCVAL(LOCALE_SABBREVLANGNAME,"deu") */
LOCVAL(LOCALE_SNATIVELANGNAME,"Esperanto")
/* LOCVAL(LOCALE_ICOUNTRY,"49") not official in any one country */
/* LOCVAL(LOCALE_SCOUNTRY,"Deutschland") */
/* LOCVAL(LOCALE_SENGCOUNTRY,"Germany") */
/* LOCVAL(LOCALE_SABBREVCTRYNAME,"De") */
/* LOCVAL(LOCALE_SNATIVECTRYNAME,"Deutschland") */
/* LOCVAL(LOCALE_IDEFAULTLANGUAGE,"9") ISO ID of lang TODO */
/* LOCVAL(LOCALE_IDEFAULTCOUNTRY,"49") */
LOCVAL(LOCALE_IDEFAULTCODEPAGE,"3") /* is this right? TODO */
LOCVAL(LOCALE_IDEFAULTANSICODEPAGE,"3") /* is this right? TODO */
LOCVAL(LOCALE_SLIST,";")
LOCVAL(LOCALE_IMEASURE,"0")
LOCVAL(LOCALE_SDECIMAL,",")
LOCVAL(LOCALE_STHOUSAND,".")
/* LOCVAL(LOCALE_SGROUPING) */
LOCVAL(LOCALE_IDIGITS,"2")
LOCVAL(LOCALE_ILZERO,"1")
/* LOCVAL(LOCALE_INEGNUMBER) */
/* LOCVAL(LOCALE_SNATIVEDIGITS) */
LOCVAL(LOCALE_SCURRENCY,"NLG") /* accounting currency of UEA */
/* LOCVAL(LOCALE_SINTLSYMBOL) */
/* LOCVAL(LOCALE_SMONDECIMALSEP) */
/* LOCVAL(LOCALE_SMONTHOUSANDSEP) */
/* LOCVAL(LOCALE_SMONGROUPING) */
/* LOCVAL(LOCALE_ICURRDIGITS,"2") */
/* LOCVAL(LOCALE_IINTLCURRDIGITS) */
LOCVAL(LOCALE_ICURRENCY,"3")
LOCVAL(LOCALE_INEGCURR,"8")
LOCVAL(LOCALE_SDATE,".")
LOCVAL(LOCALE_STIME,":")
LOCVAL(LOCALE_SSHORTDATE,"yyyy.mm.dd")
LOCVAL(LOCALE_SLONGDATE,"ddd, d. MMMM yyyy")
/* LOCVAL(LOCALE_STIMEFORMAT) */
LOCVAL(LOCALE_IDATE,"1")
/* LOCVAL(LOCALE_ILDATE) */
LOCVAL(LOCALE_ITIME,"1")
/* LOCVAL(LOCALE_ITIMEMARKPOSN) */
/* LOCVAL(LOCALE_ICENTURY) */
LOCVAL(LOCALE_ITLZERO,"1")
/* LOCVAL(LOCALE_IDAYLZERO) */
/* LOCVAL(LOCALE_IMONLZERO) */
/* LOCVAL(LOCALE_S1159) */
/* LOCVAL(LOCALE_S2359) */
/* LOCVAL(LOCALE_ICALENDARTYPE) */
/* LOCVAL(LOCALE_IOPTIONALCALENDAR) */
/* LOCVAL(LOCALE_IFIRSTDAYOFWEEK) */
/* LOCVAL(LOCALE_IFIRSTWEEKOFYEAR) */
LOCVAL(LOCALE_SDAYNAME1,"lundo")
LOCVAL(LOCALE_SDAYNAME2,"mardo")
LOCVAL(LOCALE_SDAYNAME3,"merkredo")
LOCVAL(LOCALE_SDAYNAME4,"�a�do")
LOCVAL(LOCALE_SDAYNAME5,"vendredo")
LOCVAL(LOCALE_SDAYNAME6,"sabato")
LOCVAL(LOCALE_SDAYNAME7,"diman�o")
LOCVAL(LOCALE_SABBREVDAYNAME1,"lu")
LOCVAL(LOCALE_SABBREVDAYNAME2,"ma")
LOCVAL(LOCALE_SABBREVDAYNAME3,"me")
LOCVAL(LOCALE_SABBREVDAYNAME4,"�a")
LOCVAL(LOCALE_SABBREVDAYNAME5,"ve")
LOCVAL(LOCALE_SABBREVDAYNAME6,"sa")
LOCVAL(LOCALE_SABBREVDAYNAME7,"di")
LOCVAL(LOCALE_SMONTHNAME1,"januaro")
LOCVAL(LOCALE_SMONTHNAME2,"februaro")
LOCVAL(LOCALE_SMONTHNAME3,"marto")
LOCVAL(LOCALE_SMONTHNAME4,"aprilo")
LOCVAL(LOCALE_SMONTHNAME5,"majo")
LOCVAL(LOCALE_SMONTHNAME6,"junio")
LOCVAL(LOCALE_SMONTHNAME7,"julio")
LOCVAL(LOCALE_SMONTHNAME8,"a�gusto")
LOCVAL(LOCALE_SMONTHNAME9,"septembro")
LOCVAL(LOCALE_SMONTHNAME10,"oktobro")
LOCVAL(LOCALE_SMONTHNAME11,"novembro")
LOCVAL(LOCALE_SMONTHNAME12,"decembro")
LOCVAL(LOCALE_SMONTHNAME13,"")
LOCVAL(LOCALE_SABBREVMONTHNAME1,"jan")
LOCVAL(LOCALE_SABBREVMONTHNAME2,"feb")
LOCVAL(LOCALE_SABBREVMONTHNAME3,"mar")
LOCVAL(LOCALE_SABBREVMONTHNAME4,"apr")
LOCVAL(LOCALE_SABBREVMONTHNAME5,"maj")
LOCVAL(LOCALE_SABBREVMONTHNAME6,"jun")
LOCVAL(LOCALE_SABBREVMONTHNAME7,"jul")
LOCVAL(LOCALE_SABBREVMONTHNAME8,"a�g")
LOCVAL(LOCALE_SABBREVMONTHNAME9,"sep")
LOCVAL(LOCALE_SABBREVMONTHNAME10,"okt")
LOCVAL(LOCALE_SABBREVMONTHNAME11,"nov")
LOCVAL(LOCALE_SABBREVMONTHNAME12,"dec")
LOCVAL(LOCALE_SABBREVMONTHNAME13,"")
/* LOCVAL(LOCALE_SPOSITIVESIGN) */
/* LOCVAL(LOCALE_SNEGATIVESIGN) */
/* LOCVAL(LOCALE_IPOSSIGNPOSN) */
/* LOCVAL(LOCALE_INEGSIGNPOSN) */
/* LOCVAL(LOCALE_IPOSSYMPRECEDES) */
/* LOCVAL(LOCALE_IPOSSEPBYSPACE) */
/* LOCVAL(LOCALE_INEGSYMPRECEDES) */
/* LOCVAL(LOCALE_INEGSEPBYSPACE) */
    break;  /* LANG(Eo) */

    case LANG_Fi:
LOCVAL(LOCALE_ILANGUAGE,"11")
LOCVAL(LOCALE_SLANGUAGE,"Suomi")
LOCVAL(LOCALE_SENGLANGUAGE,"Finnish")
LOCVAL(LOCALE_SABBREVLANGNAME,"fin")
LOCVAL(LOCALE_SNATIVELANGNAME,"suomi")
LOCVAL(LOCALE_ICOUNTRY,"49")
LOCVAL(LOCALE_SCOUNTRY,"Suomi")
LOCVAL(LOCALE_SENGCOUNTRY,"Finland")
LOCVAL(LOCALE_SABBREVCTRYNAME,"Fin")
LOCVAL(LOCALE_SNATIVECTRYNAME,"Suomi")
LOCVAL(LOCALE_IDEFAULTLANGUAGE,"11")
LOCVAL(LOCALE_IDEFAULTCOUNTRY,"358")
/* 
LOCVAL(LOCALE_IDEFAULTCODEPAGE)
LOCVAL(LOCALE_IDEFAULTANSICODEPAGE)
*/
LOCVAL(LOCALE_SLIST,";")
LOCVAL(LOCALE_IMEASURE,"0")
LOCVAL(LOCALE_SDECIMAL,",")
LOCVAL(LOCALE_STHOUSAND,".")
/*
LOCVAL(LOCALE_SGROUPING)
*/
LOCVAL(LOCALE_IDIGITS,"2")
LOCVAL(LOCALE_ILZERO,"1")
/*
LOCVAL(LOCALE_INEGNUMBER)
Is this "0123456789" ??
LOCVAL(LOCALE_SNATIVEDIGITS)
*/
LOCVAL(LOCALE_SCURRENCY,"mk")
/*
LOCVAL(LOCALE_SINTLSYMBOL)
LOCVAL(LOCALE_SMONDECIMALSEP)
LOCVAL(LOCALE_SMONTHOUSANDSEP)
LOCVAL(LOCALE_SMONGROUPING)
*/
LOCVAL(LOCALE_ICURRDIGITS,"2")
/*
LOCVAL(LOCALE_IINTLCURRDIGITS)
*/
LOCVAL(LOCALE_ICURRENCY,"3")
LOCVAL(LOCALE_INEGCURR,"8")
LOCVAL(LOCALE_SDATE,".")
LOCVAL(LOCALE_STIME,":")
LOCVAL(LOCALE_SSHORTDATE,"dd.MM.yyyy")
LOCVAL(LOCALE_SLONGDATE,"ddd, d. MMMM yyyy")
/*
LOCVAL(LOCALE_STIMEFORMAT)
*/
LOCVAL(LOCALE_IDATE,"1")
/*
LOCVAL(LOCALE_ILDATE)
*/
LOCVAL(LOCALE_ITIME,"1")
/*
LOCVAL(LOCALE_ITIMEMARKPOSN)
LOCVAL(LOCALE_ICENTURY)
*/
LOCVAL(LOCALE_ITLZERO,"1")
/*
LOCVAL(LOCALE_IDAYLZERO)
LOCVAL(LOCALE_IMONLZERO)
LOCVAL(LOCALE_S1159)
LOCVAL(LOCALE_S2359)
LOCVAL(LOCALE_ICALENDARTYPE)
LOCVAL(LOCALE_IOPTIONALCALENDAR)
LOCVAL(LOCALE_IFIRSTDAYOFWEEK)
LOCVAL(LOCALE_IFIRSTWEEKOFYEAR)
*/
LOCVAL(LOCALE_SDAYNAME1,"maanantai")
LOCVAL(LOCALE_SDAYNAME2,"tiistai")
LOCVAL(LOCALE_SDAYNAME3,"keskiviikko")
LOCVAL(LOCALE_SDAYNAME4,"torstai")
LOCVAL(LOCALE_SDAYNAME5,"perjantai")
LOCVAL(LOCALE_SDAYNAME6,"lauantai")
LOCVAL(LOCALE_SDAYNAME7,"sunnuntai")
LOCVAL(LOCALE_SABBREVDAYNAME1,"Ma")
LOCVAL(LOCALE_SABBREVDAYNAME2,"Ti")
LOCVAL(LOCALE_SABBREVDAYNAME3,"Ke")
LOCVAL(LOCALE_SABBREVDAYNAME4,"To")
LOCVAL(LOCALE_SABBREVDAYNAME5,"Pe")
LOCVAL(LOCALE_SABBREVDAYNAME6,"La")
LOCVAL(LOCALE_SABBREVDAYNAME7,"Su")
LOCVAL(LOCALE_SMONTHNAME1,"tammikuu")
LOCVAL(LOCALE_SMONTHNAME2,"helmikuu")
LOCVAL(LOCALE_SMONTHNAME3,"maaliskuu")
LOCVAL(LOCALE_SMONTHNAME4,"huhtikuu")
LOCVAL(LOCALE_SMONTHNAME5,"toukokuu")
LOCVAL(LOCALE_SMONTHNAME6,"kes�kuu")
LOCVAL(LOCALE_SMONTHNAME7,"hein�kuu")
LOCVAL(LOCALE_SMONTHNAME8,"elokuu")
LOCVAL(LOCALE_SMONTHNAME9,"syyskuu")
LOCVAL(LOCALE_SMONTHNAME10,"lokakuu")
LOCVAL(LOCALE_SMONTHNAME11,"marraskuu")
LOCVAL(LOCALE_SMONTHNAME12,"joulukuu")
LOCVAL(LOCALE_SMONTHNAME13,"")
LOCVAL(LOCALE_SABBREVMONTHNAME1,"tammi")
LOCVAL(LOCALE_SABBREVMONTHNAME2,"helmi")
LOCVAL(LOCALE_SABBREVMONTHNAME3,"maalis")
LOCVAL(LOCALE_SABBREVMONTHNAME4,"huhti")
LOCVAL(LOCALE_SABBREVMONTHNAME5,"touko")
LOCVAL(LOCALE_SABBREVMONTHNAME6,"kes�")
LOCVAL(LOCALE_SABBREVMONTHNAME7,"hein�")
LOCVAL(LOCALE_SABBREVMONTHNAME8,"elo")
LOCVAL(LOCALE_SABBREVMONTHNAME9,"syys")
LOCVAL(LOCALE_SABBREVMONTHNAME10,"loka")
LOCVAL(LOCALE_SABBREVMONTHNAME11,"marras")
LOCVAL(LOCALE_SABBREVMONTHNAME12,"joulu")
LOCVAL(LOCALE_SABBREVMONTHNAME13,"")
/*
LOCVAL(LOCALE_SPOSITIVESIGN)
LOCVAL(LOCALE_SNEGATIVESIGN)
LOCVAL(LOCALE_IPOSSIGNPOSN)
LOCVAL(LOCALE_INEGSIGNPOSN)
LOCVAL(LOCALE_IPOSSYMPRECEDES)
LOCVAL(LOCALE_IPOSSEPBYSPACE)
LOCVAL(LOCALE_INEGSYMPRECEDES)
LOCVAL(LOCALE_INEGSEPBYSPACE)
*/
    break;  /* LANG(Fi) */

    case LANG_It:
LOCVAL(LOCALE_ILANGUAGE,"9")
LOCVAL(LOCALE_SLANGUAGE,"Italiano")
LOCVAL(LOCALE_SENGLANGUAGE,"Italian")
LOCVAL(LOCALE_SABBREVLANGNAME,"ita")
LOCVAL(LOCALE_SNATIVELANGNAME,"Italiano")
LOCVAL(LOCALE_ICOUNTRY,"39")
LOCVAL(LOCALE_SCOUNTRY,"Italia")
LOCVAL(LOCALE_SENGCOUNTRY,"Italy")
LOCVAL(LOCALE_SABBREVCTRYNAME,"It")
LOCVAL(LOCALE_SNATIVECTRYNAME,"Italia")
LOCVAL(LOCALE_IDEFAULTLANGUAGE,"9")
LOCVAL(LOCALE_IDEFAULTCOUNTRY,"39")
/* Dunno
LOCVAL(LOCALE_IDEFAULTCODEPAGE)
LOCVAL(LOCALE_IDEFAULTANSICODEPAGE)
*/
LOCVAL(LOCALE_SLIST,";")
LOCVAL(LOCALE_IMEASURE,"0")
LOCVAL(LOCALE_SDECIMAL,",")
LOCVAL(LOCALE_STHOUSAND,".")
/*
LOCVAL(LOCALE_SGROUPING)
*/
LOCVAL(LOCALE_IDIGITS,"2")
LOCVAL(LOCALE_ILZERO,"1")
/*
LOCVAL(LOCALE_INEGNUMBER)
Is this "0123456789" ??
LOCVAL(LOCALE_SNATIVEDIGITS)
*/
LOCVAL(LOCALE_SCURRENCY,"Lit.")
/*
LOCVAL(LOCALE_SINTLSYMBOL)
LOCVAL(LOCALE_SMONDECIMALSEP)
LOCVAL(LOCALE_SMONTHOUSANDSEP)
LOCVAL(LOCALE_SMONGROUPING)
*/
LOCVAL(LOCALE_ICURRDIGITS,"2")
/*
LOCVAL(LOCALE_IINTLCURRDIGITS)
*/
LOCVAL(LOCALE_ICURRENCY,"3")
LOCVAL(LOCALE_INEGCURR,"8")
LOCVAL(LOCALE_SDATE,".")
LOCVAL(LOCALE_STIME,":")
LOCVAL(LOCALE_SSHORTDATE,"dd.MM.yyyy")
LOCVAL(LOCALE_SLONGDATE,"ddd, d. MMMM yyyy")
/*
LOCVAL(LOCALE_STIMEFORMAT)
*/
LOCVAL(LOCALE_IDATE,"1")
/*
LOCVAL(LOCALE_ILDATE)
*/
LOCVAL(LOCALE_ITIME,"1")
/*
LOCVAL(LOCALE_ITIMEMARKPOSN)
LOCVAL(LOCALE_ICENTURY)
*/
LOCVAL(LOCALE_ITLZERO,"1")
/*
LOCVAL(LOCALE_IDAYLZERO)
LOCVAL(LOCALE_IMONLZERO)
LOCVAL(LOCALE_S1159)
LOCVAL(LOCALE_S2359)
LOCVAL(LOCALE_ICALENDARTYPE)
LOCVAL(LOCALE_IOPTIONALCALENDAR)
LOCVAL(LOCALE_IFIRSTDAYOFWEEK)
LOCVAL(LOCALE_IFIRSTWEEKOFYEAR)
*/
LOCVAL(LOCALE_SDAYNAME1,"Lunedi'")
LOCVAL(LOCALE_SDAYNAME2,"Martedi'")
LOCVAL(LOCALE_SDAYNAME3,"Mercoledi'")
LOCVAL(LOCALE_SDAYNAME4,"Giovedi'")
LOCVAL(LOCALE_SDAYNAME5,"Venerdi'")
LOCVAL(LOCALE_SDAYNAME6,"Sabato")
LOCVAL(LOCALE_SDAYNAME7,"Domenica")
LOCVAL(LOCALE_SABBREVDAYNAME1,"Lu")
LOCVAL(LOCALE_SABBREVDAYNAME2,"Ma")
LOCVAL(LOCALE_SABBREVDAYNAME3,"Me")
LOCVAL(LOCALE_SABBREVDAYNAME4,"Gi")
LOCVAL(LOCALE_SABBREVDAYNAME5,"Ve")
LOCVAL(LOCALE_SABBREVDAYNAME6,"Sa")
LOCVAL(LOCALE_SABBREVDAYNAME7,"Do")
LOCVAL(LOCALE_SMONTHNAME1,"Gennaio")
LOCVAL(LOCALE_SMONTHNAME2,"Febbraio")
LOCVAL(LOCALE_SMONTHNAME3,"Marzo")
LOCVAL(LOCALE_SMONTHNAME4,"Aprile")
LOCVAL(LOCALE_SMONTHNAME5,"Maggio")
LOCVAL(LOCALE_SMONTHNAME6,"Giugno")
LOCVAL(LOCALE_SMONTHNAME7,"Luglio")
LOCVAL(LOCALE_SMONTHNAME8,"Agosto")
LOCVAL(LOCALE_SMONTHNAME9,"Settembre")
LOCVAL(LOCALE_SMONTHNAME10,"Ottobre")
LOCVAL(LOCALE_SMONTHNAME11,"Novembre")
LOCVAL(LOCALE_SMONTHNAME12,"Dicembre")
LOCVAL(LOCALE_SMONTHNAME13,"")
LOCVAL(LOCALE_SABBREVMONTHNAME1,"Gen")
LOCVAL(LOCALE_SABBREVMONTHNAME2,"Feb")
LOCVAL(LOCALE_SABBREVMONTHNAME3,"Mar")
LOCVAL(LOCALE_SABBREVMONTHNAME4,"Apr")
LOCVAL(LOCALE_SABBREVMONTHNAME5,"Mag")
LOCVAL(LOCALE_SABBREVMONTHNAME6,"Giu")
LOCVAL(LOCALE_SABBREVMONTHNAME7,"Lug")
LOCVAL(LOCALE_SABBREVMONTHNAME8,"Ago")
LOCVAL(LOCALE_SABBREVMONTHNAME9,"Set")
LOCVAL(LOCALE_SABBREVMONTHNAME10,"Ott")
LOCVAL(LOCALE_SABBREVMONTHNAME11,"Nov")
LOCVAL(LOCALE_SABBREVMONTHNAME12,"Dic")
LOCVAL(LOCALE_SABBREVMONTHNAME13,"")
/*
LOCVAL(LOCALE_SPOSITIVESIGN)
LOCVAL(LOCALE_SNEGATIVESIGN)
LOCVAL(LOCALE_IPOSSIGNPOSN)
LOCVAL(LOCALE_INEGSIGNPOSN)
LOCVAL(LOCALE_IPOSSYMPRECEDES)
LOCVAL(LOCALE_IPOSSEPBYSPACE)
LOCVAL(LOCALE_INEGSYMPRECEDES)
LOCVAL(LOCALE_INEGSEPBYSPACE)
*/
    break;  /* LANG(It) */

    case 0x0409:
LOCVAL(LOCALE_ILANGUAGE, "0409")
LOCVAL(LOCALE_SLANGUAGE, "English (United States)")
LOCVAL(LOCALE_SENGLANGUAGE, "English")
LOCVAL(LOCALE_SABBREVLANGNAME, "ENU")
LOCVAL(LOCALE_SNATIVELANGNAME, "English")
LOCVAL(LOCALE_ICOUNTRY, "1")
LOCVAL(LOCALE_SCOUNTRY, "United States")
LOCVAL(LOCALE_SENGCOUNTRY, "United States")
LOCVAL(LOCALE_SABBREVCTRYNAME, "USA")
LOCVAL(LOCALE_SNATIVECTRYNAME, "United States")
LOCVAL(LOCALE_IDEFAULTLANGUAGE, "0409")
LOCVAL(LOCALE_IDEFAULTCOUNTRY, "1")
LOCVAL(LOCALE_IDEFAULTCODEPAGE, "437")
LOCVAL(LOCALE_IDEFAULTANSICODEPAGE, "1252")
LOCVAL(LOCALE_SLIST, ",")
LOCVAL(LOCALE_IMEASURE, "1")
LOCVAL(LOCALE_SDECIMAL, ".")
LOCVAL(LOCALE_STHOUSAND, ",")
LOCVAL(LOCALE_SGROUPING, "3;0")
LOCVAL(LOCALE_IDIGITS, "2")
LOCVAL(LOCALE_ILZERO, "1")
LOCVAL(LOCALE_INEGNUMBER, "1")
LOCVAL(LOCALE_SNATIVEDIGITS, "0123456789")
LOCVAL(LOCALE_SCURRENCY, "$")
LOCVAL(LOCALE_SINTLSYMBOL, "USD")
LOCVAL(LOCALE_SMONDECIMALSEP, ".")
LOCVAL(LOCALE_SMONTHOUSANDSEP, ",")
LOCVAL(LOCALE_SMONGROUPING, "3;0")
LOCVAL(LOCALE_ICURRDIGITS, "2")
LOCVAL(LOCALE_IINTLCURRDIGITS, "2")
LOCVAL(LOCALE_ICURRENCY, "0")
LOCVAL(LOCALE_INEGCURR, "0")
LOCVAL(LOCALE_SDATE, "/")
LOCVAL(LOCALE_STIME, ":")
LOCVAL(LOCALE_SSHORTDATE, "M/d/yy")
LOCVAL(LOCALE_SLONGDATE, "dddd, MMMM dd, yyyy")
LOCVAL(LOCALE_STIMEFORMAT, "h:mm:ss tt")
LOCVAL(LOCALE_IDATE, "0")
LOCVAL(LOCALE_ILDATE, "0")
LOCVAL(LOCALE_ITIME, "0")
LOCVAL(LOCALE_ITIMEMARKPOSN, "0")
LOCVAL(LOCALE_ICENTURY, "0")
LOCVAL(LOCALE_ITLZERO, "0")
LOCVAL(LOCALE_IDAYLZERO, "0")
LOCVAL(LOCALE_IMONLZERO, "0")
LOCVAL(LOCALE_S1159, "AM")
LOCVAL(LOCALE_S2359, "PM")
LOCVAL(LOCALE_ICALENDARTYPE, "1")
LOCVAL(LOCALE_IOPTIONALCALENDAR, "0")
LOCVAL(LOCALE_IFIRSTDAYOFWEEK, "6")
LOCVAL(LOCALE_IFIRSTWEEKOFYEAR, "0")
LOCVAL(LOCALE_SDAYNAME1, "Monday")
LOCVAL(LOCALE_SDAYNAME2, "Tuesday")
LOCVAL(LOCALE_SDAYNAME3, "Wednesday")
LOCVAL(LOCALE_SDAYNAME4, "Thursday")
LOCVAL(LOCALE_SDAYNAME5, "Friday")
LOCVAL(LOCALE_SDAYNAME6, "Saturday")
LOCVAL(LOCALE_SDAYNAME7, "Sunday")
LOCVAL(LOCALE_SABBREVDAYNAME1, "Mon")
LOCVAL(LOCALE_SABBREVDAYNAME2, "Tue")
LOCVAL(LOCALE_SABBREVDAYNAME3, "Wed")
LOCVAL(LOCALE_SABBREVDAYNAME4, "Thu")
LOCVAL(LOCALE_SABBREVDAYNAME5, "Fri")
LOCVAL(LOCALE_SABBREVDAYNAME6, "Sat")
LOCVAL(LOCALE_SABBREVDAYNAME7, "Sun")
LOCVAL(LOCALE_SMONTHNAME1, "January")
LOCVAL(LOCALE_SMONTHNAME2, "February")
LOCVAL(LOCALE_SMONTHNAME3, "March")
LOCVAL(LOCALE_SMONTHNAME4, "April")
LOCVAL(LOCALE_SMONTHNAME5, "May")
LOCVAL(LOCALE_SMONTHNAME6, "June")
LOCVAL(LOCALE_SMONTHNAME7, "July")
LOCVAL(LOCALE_SMONTHNAME8, "August")
LOCVAL(LOCALE_SMONTHNAME9, "September")
LOCVAL(LOCALE_SMONTHNAME10, "October")
LOCVAL(LOCALE_SMONTHNAME11, "November")
LOCVAL(LOCALE_SMONTHNAME12, "December")
LOCVAL(LOCALE_SMONTHNAME13, "")
LOCVAL(LOCALE_SABBREVMONTHNAME1, "Jan")
LOCVAL(LOCALE_SABBREVMONTHNAME2, "Feb")
LOCVAL(LOCALE_SABBREVMONTHNAME3, "Mar")
LOCVAL(LOCALE_SABBREVMONTHNAME4, "Apr")
LOCVAL(LOCALE_SABBREVMONTHNAME5, "May")
LOCVAL(LOCALE_SABBREVMONTHNAME6, "Jun")
LOCVAL(LOCALE_SABBREVMONTHNAME7, "Jul")
LOCVAL(LOCALE_SABBREVMONTHNAME8, "Aug")
LOCVAL(LOCALE_SABBREVMONTHNAME9, "Sep")
LOCVAL(LOCALE_SABBREVMONTHNAME10, "Oct")
LOCVAL(LOCALE_SABBREVMONTHNAME11, "Nov")
LOCVAL(LOCALE_SABBREVMONTHNAME12, "Dec")
LOCVAL(LOCALE_SABBREVMONTHNAME13, "")
LOCVAL(LOCALE_SPOSITIVESIGN, "")
LOCVAL(LOCALE_SNEGATIVESIGN, "-")
LOCVAL(LOCALE_IPOSSIGNPOSN, "3")
LOCVAL(LOCALE_INEGSIGNPOSN, "0")
LOCVAL(LOCALE_IPOSSYMPRECEDES, "1")
LOCVAL(LOCALE_IPOSSEPBYSPACE, "0")
LOCVAL(LOCALE_INEGSYMPRECEDES, "1")
LOCVAL(LOCALE_INEGSEPBYSPACE, "0")
    break; /* LANG(0x0409) (U.S. English) */

    case 0x0809:
LOCVAL(LOCALE_ILANGUAGE, "0809")
LOCVAL(LOCALE_SLANGUAGE, "English (United Kingdom)")
LOCVAL(LOCALE_SENGLANGUAGE, "English")
LOCVAL(LOCALE_SABBREVLANGNAME, "ENG")
LOCVAL(LOCALE_SNATIVELANGNAME, "English")
LOCVAL(LOCALE_ICOUNTRY, "44")
LOCVAL(LOCALE_SCOUNTRY, "United Kingdom")
LOCVAL(LOCALE_SENGCOUNTRY, "United Kingdom")
LOCVAL(LOCALE_SABBREVCTRYNAME, "GBR")
LOCVAL(LOCALE_SNATIVECTRYNAME, "United Kingdom")
LOCVAL(LOCALE_IDEFAULTLANGUAGE, "0809")
LOCVAL(LOCALE_IDEFAULTCOUNTRY, "44")
LOCVAL(LOCALE_IDEFAULTCODEPAGE, "850")
LOCVAL(LOCALE_IDEFAULTANSICODEPAGE, "1252")
LOCVAL(LOCALE_SLIST, ",")
LOCVAL(LOCALE_IMEASURE, "0")
LOCVAL(LOCALE_SDECIMAL, ".")
LOCVAL(LOCALE_STHOUSAND, ",")
LOCVAL(LOCALE_SGROUPING, "3;0")
LOCVAL(LOCALE_IDIGITS, "2")
LOCVAL(LOCALE_ILZERO, "1")
LOCVAL(LOCALE_INEGNUMBER, "1")
LOCVAL(LOCALE_SNATIVEDIGITS, "0123456789")
LOCVAL(LOCALE_SCURRENCY, "�")
LOCVAL(LOCALE_SINTLSYMBOL, "GBP")
LOCVAL(LOCALE_SMONDECIMALSEP, ".")
LOCVAL(LOCALE_SMONTHOUSANDSEP, ",")
LOCVAL(LOCALE_SMONGROUPING, "3;0")
LOCVAL(LOCALE_ICURRDIGITS, "2")
LOCVAL(LOCALE_IINTLCURRDIGITS, "2")
LOCVAL(LOCALE_ICURRENCY, "0")
LOCVAL(LOCALE_INEGCURR, "1")
LOCVAL(LOCALE_SDATE, "/")
LOCVAL(LOCALE_STIME, ":")
LOCVAL(LOCALE_SSHORTDATE, "dd/MM/yy")
LOCVAL(LOCALE_SLONGDATE, "dd MMMM yyyy")
LOCVAL(LOCALE_STIMEFORMAT, "HH:mm:ss")
LOCVAL(LOCALE_IDATE, "1")
LOCVAL(LOCALE_ILDATE, "1")
LOCVAL(LOCALE_ITIME, "1")
LOCVAL(LOCALE_ITIMEMARKPOSN, "0")
LOCVAL(LOCALE_ICENTURY, "0")
LOCVAL(LOCALE_ITLZERO, "1")
LOCVAL(LOCALE_IDAYLZERO, "1")
LOCVAL(LOCALE_IMONLZERO, "1")
LOCVAL(LOCALE_S1159, "")
LOCVAL(LOCALE_S2359, "")
LOCVAL(LOCALE_ICALENDARTYPE, "1")
LOCVAL(LOCALE_IOPTIONALCALENDAR, "0")
LOCVAL(LOCALE_IFIRSTDAYOFWEEK, "0")
LOCVAL(LOCALE_IFIRSTWEEKOFYEAR, "0")
LOCVAL(LOCALE_SDAYNAME1, "Monday")
LOCVAL(LOCALE_SDAYNAME2, "Tuesday")
LOCVAL(LOCALE_SDAYNAME3, "Wednesday")
LOCVAL(LOCALE_SDAYNAME4, "Thursday")
LOCVAL(LOCALE_SDAYNAME5, "Friday")
LOCVAL(LOCALE_SDAYNAME6, "Saturday")
LOCVAL(LOCALE_SDAYNAME7, "Sunday")
LOCVAL(LOCALE_SABBREVDAYNAME1, "Mon")
LOCVAL(LOCALE_SABBREVDAYNAME2, "Tue")
LOCVAL(LOCALE_SABBREVDAYNAME3, "Wed")
LOCVAL(LOCALE_SABBREVDAYNAME4, "Thu")
LOCVAL(LOCALE_SABBREVDAYNAME5, "Fri")
LOCVAL(LOCALE_SABBREVDAYNAME6, "Sat")
LOCVAL(LOCALE_SABBREVDAYNAME7, "Sun")
LOCVAL(LOCALE_SMONTHNAME1, "January")
LOCVAL(LOCALE_SMONTHNAME2, "February")
LOCVAL(LOCALE_SMONTHNAME3, "March")
LOCVAL(LOCALE_SMONTHNAME4, "April")
LOCVAL(LOCALE_SMONTHNAME5, "May")
LOCVAL(LOCALE_SMONTHNAME6, "June")
LOCVAL(LOCALE_SMONTHNAME7, "July")
LOCVAL(LOCALE_SMONTHNAME8, "August")
LOCVAL(LOCALE_SMONTHNAME9, "September")
LOCVAL(LOCALE_SMONTHNAME10, "October")
LOCVAL(LOCALE_SMONTHNAME11, "November")
LOCVAL(LOCALE_SMONTHNAME12, "December")
LOCVAL(LOCALE_SMONTHNAME13, "")
LOCVAL(LOCALE_SABBREVMONTHNAME1, "Jan")
LOCVAL(LOCALE_SABBREVMONTHNAME2, "Feb")
LOCVAL(LOCALE_SABBREVMONTHNAME3, "Mar")
LOCVAL(LOCALE_SABBREVMONTHNAME4, "Apr")
LOCVAL(LOCALE_SABBREVMONTHNAME5, "May")
LOCVAL(LOCALE_SABBREVMONTHNAME6, "Jun")
LOCVAL(LOCALE_SABBREVMONTHNAME7, "Jul")
LOCVAL(LOCALE_SABBREVMONTHNAME8, "Aug")
LOCVAL(LOCALE_SABBREVMONTHNAME9, "Sep")
LOCVAL(LOCALE_SABBREVMONTHNAME10, "Oct")
LOCVAL(LOCALE_SABBREVMONTHNAME11, "Nov")
LOCVAL(LOCALE_SABBREVMONTHNAME12, "Dec")
LOCVAL(LOCALE_SABBREVMONTHNAME13, "")
LOCVAL(LOCALE_SPOSITIVESIGN, "")
LOCVAL(LOCALE_SNEGATIVESIGN, "-")
LOCVAL(LOCALE_IPOSSIGNPOSN, "3")
LOCVAL(LOCALE_INEGSIGNPOSN, "3")
LOCVAL(LOCALE_IPOSSYMPRECEDES, "1")
LOCVAL(LOCALE_IPOSSEPBYSPACE, "0")
LOCVAL(LOCALE_INEGSYMPRECEDES, "1")
LOCVAL(LOCALE_INEGSEPBYSPACE, "0")
    break; /* LANG(0x0809) (U.K. English) */

/*Insert other languages here*/

    default:
	break;
    }  /* switch */

	if(!retLen)
	{
		if(!retString)fprintf(stderr,"Unkown LC type %lX\n",LCType);
		else fprintf(stderr,"'%s' not supported for your language.\n",
			retString);
		return 0;
	}

	if(retLen>len)retLen=len;
	lstrcpyn32A(buf,retString,len);
	return retLen;
}

/***********************************************************************
 *         GetLocaleInfo32W             (KERNEL32.230)
 * Is the last parameter really WORD for Win16?
 */
INT32 GetLocaleInfo32W(LCID lcid,LCTYPE LCType,LPWSTR wbuf,INT32 len)
{
	int i;
	LPSTR abuf = (LPSTR) wbuf;
	INT32 n = GetLocaleInfoA(lcid, LCType, abuf, len);
	for (i = n; i > 0; --i) {
		wbuf[i] = abuf[i];
	}
	return n;
}

/***********************************************************************
 *           CompareString16       (OLE2NLS.8)
 */
UINT16 CompareString16(DWORD lcid,DWORD fdwStyle,
	LPCSTR s1,DWORD l1,LPCSTR s2,DWORD l2)
{
	return (UINT16)CompareString32A(lcid,fdwStyle,s1,l1,s2,l2);
}

/***********************************************************************
 *           CompareString32A   (KERNEL32.29)
 * This implementation ignores the locale
 * FIXME
 */
UINT32 CompareString32A(DWORD lcid, DWORD fdwStyle, 
	LPCSTR s1, DWORD l1, LPCSTR s2,DWORD l2)
{
	int len,ret;
	if(fdwStyle & NORM_IGNORENONSPACE)
	{
		fprintf(stdnimp, "CompareStringA: IGNORENONSPACE not supprted\n");
	}
	if(fdwStyle & NORM_IGNORESYMBOLS)
		fprintf(stdnimp, "CompareStringA: IGNORESYMBOLS not supported\n");
	/* Is strcmp defaulting to string sort or to word sort?? */
	/* FIXME: Handle NORM_STRINGSORT */
	l1 = (l1==-1)?strlen(s1):l1;
	l2 = (l2==-1)?strlen(s2):l2;
	len = l1<l2 ? l1:l2;
	ret = (fdwStyle & NORM_IGNORECASE) ?
		lstrncmpi32A(s1,s2,len)	: lstrncmp32A(s1,s2,len);
	/* not equal, return 1 or 3 */
	if(ret!=0)return ret+2;
	/* same len, return 2 */
	if(l1==l2)return 2;
	/* the longer one is lexically greater */
	return (l1<l2)? 1 : 3;
}

/***********************************************************************
 *           CompareString32W       (KERNEL32.30)
 * This implementation ignores the locale
 * FIXME
 */
UINT32 CompareString32W(DWORD lcid, DWORD fdwStyle, 
	LPCWSTR s1, DWORD l1, LPCWSTR s2,DWORD l2)
{
	int len,ret;
	if(fdwStyle & NORM_IGNORENONSPACE)
		fprintf(stdnimp,"CompareStringW:IGNORENONSPACE not supprted\n");
	if(fdwStyle & NORM_IGNORESYMBOLS)
		fprintf(stdnimp,"CompareStringW:IGNORESYMBOLS not supported\n");

	/* Is strcmp defaulting to string sort or to word sort?? */
	/* FIXME: Handle NORM_STRINGSORT */
	l1 = (l1==-1)?lstrlen32W(s1):l1;
	l2 = (l2==-1)?lstrlen32W(s2):l2;
	len = l1<l2 ? l1:l2;
	ret = (fdwStyle & NORM_IGNORECASE) ?
		lstrncmpi32W(s1,s2,len)	: lstrncmp32W(s1,s2,len);
	/* not equal, return 1 or 3 */
	if(ret!=0) return ret+2;
	/* same len, return 2 */
	if(l1==l2) return 2;
	/* the longer one is lexically greater */
	return (l1<l2)? 1 : 3;
}

/***********************************************************************
 *           SetLocalInfoA       (KERNEL32.499)
 */
BOOL SetLocaleInfoA(DWORD lcid, DWORD lctype, LPCSTR data) {
	fprintf(stdnimp,"SetLocaleInfoA(%ld,%ld,%s)\n",lcid,lctype,data);
	return TRUE;
}
