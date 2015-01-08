/*Own project inclussion*/
#include "InternalSettings.hpp"

// Global static pointer used to ensure a single instance of the class.
InternalSettings* InternalSettings::m_pInstance = NULL;


const string InternalSettings::ConfigurationFileName = "../Configuration.xml";
const string InternalSettings::DefaultAppName = "Territorial Administrator";
const string InternalSettings::PathnFileName = "./Data/Path.xml";

/* Project Error Settings */
bool InternalSettings::ProjectError = false;

/* Settup type */
TAR_tenSetupType InternalSettings::SettupType = TAR_enNoSettup;

/* Error type */
TAR_tenErrorType InternalSettings::ErrorType = TAR_enNoError;

vector<IS_tstLanguagesConfig> InternalSettings::Languages(MaxNumberOfLanguages);

/* Number of avalable languages */
unsigned int InternalSettings::NumberOfAvailableLanguages = 0;

/** This function is called to create an instance of the class.
Calling the constructor publicly is not allowed. The constructor
is private and is only called by this Instance function.
*/
InternalSettings* InternalSettings::Instance()
{
	if (!m_pInstance)   // Only allow one instance of class to be generated.
	{
		m_pInstance = new InternalSettings;
	}
	return m_pInstance;
}


/** Create Default XML file */
const string  InternalSettings::IS_sGetConfigurationFileName()
{
	return ConfigurationFileName;
}

/** Set project error */
void InternalSettings::IS_vSetProjectError(bool boProjectError)
{
	ProjectError = boProjectError;
}

/** Reset project error */
void InternalSettings::IS_vResetProjectError()
{
	ProjectError = false;
}

/** Set initial settings value */
void InternalSettings::IS_vSetInitialSettingValue(void)
{
	ProjectError = false;
	SettupType = TAR_enNoSettup;
	ErrorType = TAR_enNoError;
	for (int cnt = 0; cnt < MaxNumberOfLanguages; cnt++)
	{
		Languages[cnt].Language = L"";
		Languages[cnt].Path = "";
	}
	NumberOfAvailableLanguages = 0;
}

/** Get settup type */
TAR_tenSetupType InternalSettings::IS_vGetSetupType(void)
{
	return SettupType;
}

/** Set settup type */
void InternalSettings::IS_vSetSetupType(TAR_tenSetupType enSetupType)
{
	SettupType = enSetupType;
}

/** Get Default App Name
*/
const string  InternalSettings::IS_sGetDefaultAppName(void)
{
	return DefaultAppName;
}

const string InternalSettings::IS_sGetPathsName(void)
{
	return PathnFileName;
}

void InternalSettings::IS_vSetLanguageConfiguration(unsigned int LanguageIndex, wstring Language, string Path)
{
	if (LanguageIndex < MaxNumberOfLanguages)
	{
		Languages[LanguageIndex].Language = Language;
		Languages[LanguageIndex].Path = Path;
	}
}

/* Get Language Name */
const wstring InternalSettings::IS_sGetLanguageName(unsigned int LanguageIndex)
{
	wstring result = L"";
	if (LanguageIndex < NumberOfAvailableLanguages)
	{
		result = Languages[LanguageIndex].Language;
	}
	return result;
}

/* Get Language texts Path */
const string InternalSettings::IS_sGetLanguagePath(unsigned int LanguageIndex)
{
	string result = "";
	if (LanguageIndex < NumberOfAvailableLanguages)
	{
		result = Languages[LanguageIndex].Path;
	}
	return result;
}

/* Set Number of available languages */
void InternalSettings::IS_vSetNumberOfAvailableLanguages(unsigned int LanguageNumber)
{
	if (LanguageNumber < MaxNumberOfLanguages)
	{
		NumberOfAvailableLanguages = LanguageNumber;
	}
	else
	{
		NumberOfAvailableLanguages = MaxNumberOfLanguages;
	}
}