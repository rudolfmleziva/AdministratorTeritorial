#ifndef __CUSTOM_DATA_TYPES_H__
#define __CUSTOM_DATA_TYPES_H__


/** The scope of the object is to define neccessary Data types 
*/

#define NumberOfSettupSteps 3

/** The enum defines Setup types */
enum TAR_enSetupType
{
	TAR_enNoSettup     = 0,
	TAR_enCleanSetup   = 1,
	TAR_emNoLangConfig = 2
};

typedef enum TAR_enSetupType TAR_tenSetupType;

/** The enum defines Error types */
enum TAR_enErrorType
{
	TAR_enNoError                = 0,
	TAR_enSettingCannotBeCreated = 1,
	TAR_emLangFileNotFound       = 2
};

typedef enum TAR_enErrorType TAR_tenErrorType;

#endif // __CUSTOM_DATA_TYPES_H__
