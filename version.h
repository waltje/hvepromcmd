#ifndef VERSION_H
# define VERSION_H


/* Application name. */
#define APP_NAME	"HvEpromCmd"
#define APP_TITLE	"HV EPROM Programmer Client"
#define APP_PRODUCT	"HVEPROM Project"
#define APP_COMPANY	"Matthew Millman <inaxeon@hotmail.com>"
#define APP_COPYRIGHT	"Copyright 2019-2023 Matthew Millman"
#define APP_LICENSE	"Released under the GNU Public License."


/* Version info. */
#define APP_VER_MAJOR	2
#define APP_VER_MINOR	0
#define APP_VER_REV	0
#define APP_VER_PATCH	0


/* Standard C preprocessor macros. */
#define STR_STRING(x)	#x
#define STR(x)		STR_STRING(x)
#define STR_RC(a,e)	a ## , ## e


/* These are used in the application. */
#define APP_VER_NUM	APP_VER_MAJOR.APP_VER_MINOR.APP_VER_REV
#if defined(APP_VER_PATCH) && APP_VER_PATCH > 0
# define APP_VER_NUM_4	APP_VER_MAJOR.APP_VER_MINOR.APP_VER_REV.APP_VER_PATCH
# define APP_VERSION	STR(APP_VER_NUM_4)
#else
# define APP_VER_NUM_4	APP_VER_MAJOR.APP_VER_MINOR.APP_VER_REV.0
# define APP_VERSION	STR(APP_VER_NUM)
#endif
#define APP_VERSION_4	STR(APP_VER_NUM_4)


#endif	/*VERSION_H*/
