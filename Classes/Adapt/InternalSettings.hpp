#ifndef __INTERNAL_SETTINGS_H__
#define __INTERNAL_SETTINGS_H__
/*Standard inclussion*/
#include <string>

/* Project inclusions */
#include "CustomDataTypes.h"

using namespace std;
/** The scope of the object is to hold project configuration
* during runtime
*/

class InternalSettings
{
public:
	/* public initialisator of he class */
	static InternalSettings* Instance();

	/** Get configuration File name
	*/
	const string IS_sGetConfigurationFileName(void);

	/** Set project error */
	void IS_vSetProjectError(bool boProjectError);

	/** Reset project error */
	void IS_vResetProjectError(void);

	/** Set initial settings value */
	void IS_vSetInitialSettingValue(void);

	/** Set Setup type */
	void IS_vSetSetupType(TAR_tenSetupType enSetupType);

	/** Get Setup type */
	TAR_tenSetupType IS_vGetSetupType(void);

	/** Get Default App Name
	*/
	const string IS_sGetDefaultAppName(void);

private:
	InternalSettings(){};  // Private so that it can  not be called
	InternalSettings(InternalSettings const&){};             // copy constructor is private
	InternalSettings& operator=(InternalSettings const&){};  // assignment operator is private
	static InternalSettings* m_pInstance;

	/* Settup type */
	static TAR_tenSetupType SettupType;

	/* Default application name */
	static const string DefaultAppName;

	/* Project Error Settings */
	static bool ProjectError;

	/* Error type */
	static TAR_tenErrorType ErrorType;

	/* Configration file name */
	static const string ConfigurationFileName;

	/* Link to path file */
	static const string PathnFileName;
};

#endif // __INTERNAL_SETTINGS_H__
