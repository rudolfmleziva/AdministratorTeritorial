#ifndef __INTERNAL_SETTINGS_H__
#define __INTERNAL_SETTINGS_H__
/*Standard inclussion*/
#include <stdbool.h>

#include "CustomDataTypes.h"

/** The scope of the object is to hold project configuration
* during runtime
*/

/** Get configuration File name
*/
const char * IS_pchGetConfigurationFileName(void);

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
const char * IS_pchGetDefaultAppName(void);

#endif // __INTERNAL_SETTINGS_H__
