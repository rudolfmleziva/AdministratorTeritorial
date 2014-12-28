/*Own project inclussion*/
#include "InternalSettings.h"



static const char SettingsFileName[] = {'S','e','t','t','i','n','g','s','.','x','m','l','\0'};
static const char DefaultAppName[] = { 'T', 'e','r','r','i','t','o','r','i','a','l',' ',
                                       'A','d','m','i','n','i','s','t','r','a','t','o','r','\0'};
static const char ConfigurationFileName[] = { 'C', 'o', 'n', 'f', 'i', 'g', 'u', 'r', 'a', 't', 'i', 'o','n', '.', 'x', 'm', 'l', '\0' };

/* Project Error Settings */
static bool ProjectError = false;

/* Settup type */
static TAR_tenSetupType SettupType = TAR_enNoSettup;

/* Error type */
static TAR_tenErrorType ErrorType = TAR_enNoError;

/** Create Default XML file */
const char *  IS_pchGetConfigurationFileName()
{
	return &SettingsFileName[0];
}

/** Set project error */
void IS_vSetProjectError(bool boProjectError)
{
	ProjectError = boProjectError;
}

/** Reset project error */
void IS_vResetProjectError()
{
	ProjectError = false;
}

/** Set initial settings value */
void IS_vSetInitialSettingValue(void)
{
	ProjectError = false;
	SettupType = TAR_enNoSettup;
	ErrorType = TAR_enNoError;
}

/** Get settup type */
TAR_tenSetupType IS_vGetSetupType(void)
{
	return SettupType;
}

/** Set settup type */
void IS_vSetSetupType(TAR_tenSetupType enSetupType)
{
	SettupType = enSetupType;
}

/** Get Default App Name
*/
const char * IS_pchGetDefaultAppName(void)
{
	return &DefaultAppName[0];
}

