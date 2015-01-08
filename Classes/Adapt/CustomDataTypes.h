#ifndef __CUSTOM_DATA_TYPES_H__
#define __CUSTOM_DATA_TYPES_H__


/** The scope of the object is to define neccessary Data types 
*/

#define NumberOfSettupSteps 5

#define MaxNumberOfLanguages 32

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

enum TAR_enResources
{
	TAR_nenBeginOfInactiveSetupSteps = 0,
	TAR_nenInactiveSetupStep1        = TAR_nenBeginOfInactiveSetupSteps,
	TAR_nenInactiveSetupStep2        = 1,
	TAR_nenInactiveSetupStep3        = 2,
	TAR_nenInactiveSetupStep4        = 3,
	TAR_nenInactiveSetupStep5        = 4,
	TAR_nenSetupNextButton           = 5,
	TAR_nenSetupPreviousButton       = 6,
	TAR_nenNumberOfResources         = 7
};

typedef enum TAR_enResources TAR_tenResources;

enum TAR_enTexts
{
	TAR_nenAppName                  = 0,
	TAR_nenExecutionError           = 1,
	TAR_nenConfigurationCreateError = 2,
	TAR_nenSetupWelcome             = 3,
	TAR_nenLanguageSelect           = 4,
	TAR_nenPersonalData             = 5,
	TAR_nenName                     = 6,
	TAR_nenSurname                  = 7,
	TAR_nenBirthDate                = 8,
	TAR_nenResponsabilities         = 9,
	TAR_nenEmail                    = 10,
	TAR_nenPhoneNumber              = 11,
	TAR_nenNumberOfTexts            = 12
};
typedef enum TAR_enTexts TAR_tenTexts;

#endif // __CUSTOM_DATA_TYPES_H__
