/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/browser/components/migration/public/nsIBrowserProfileMigrator.idl
 */

#ifndef __gen_nsIBrowserProfileMigrator_h__
#define __gen_nsIBrowserProfileMigrator_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsISupportsArray; /* forward declaration */

class nsIProfileStartup; /* forward declaration */


/* starting interface:    nsIBrowserProfileMigrator */
#define NS_IBROWSERPROFILEMIGRATOR_IID_STR "f8365b4a-da55-4e47-be7a-230142360f62"

#define NS_IBROWSERPROFILEMIGRATOR_IID \
  {0xf8365b4a, 0xda55, 0x4e47, \
    { 0xbe, 0x7a, 0x23, 0x01, 0x42, 0x36, 0x0f, 0x62 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIBrowserProfileMigrator : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERPROFILEMIGRATOR_IID)

  enum { ALL = 0U };

  enum { SETTINGS = 1U };

  enum { COOKIES = 2U };

  enum { HISTORY = 4U };

  enum { FORMDATA = 8U };

  enum { PASSWORDS = 16U };

  enum { BOOKMARKS = 32U };

  enum { OTHERDATA = 64U };

  /* void migrate (in unsigned short aItems, in nsIProfileStartup aStartup, in wstring aProfile); */
  NS_SCRIPTABLE NS_IMETHOD Migrate(PRUint16 aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile) = 0;

  /* unsigned short getMigrateData (in wstring aProfile, in boolean aDoingStartup); */
  NS_SCRIPTABLE NS_IMETHOD GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, PRUint16 *_retval NS_OUTPARAM) = 0;

  /* readonly attribute boolean sourceExists; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceExists(bool *aSourceExists) = 0;

  /* readonly attribute boolean sourceHasMultipleProfiles; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceHasMultipleProfiles(bool *aSourceHasMultipleProfiles) = 0;

  /* readonly attribute nsISupportsArray sourceProfiles; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceProfiles(nsISupportsArray * *aSourceProfiles) = 0;

  /* readonly attribute AUTF8String sourceHomePageURL; */
  NS_SCRIPTABLE NS_IMETHOD GetSourceHomePageURL(nsACString & aSourceHomePageURL) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserProfileMigrator, NS_IBROWSERPROFILEMIGRATOR_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERPROFILEMIGRATOR \
  NS_SCRIPTABLE NS_IMETHOD Migrate(PRUint16 aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile); \
  NS_SCRIPTABLE NS_IMETHOD GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, PRUint16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceExists(bool *aSourceExists); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceHasMultipleProfiles(bool *aSourceHasMultipleProfiles); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceProfiles(nsISupportsArray * *aSourceProfiles); \
  NS_SCRIPTABLE NS_IMETHOD GetSourceHomePageURL(nsACString & aSourceHomePageURL); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERPROFILEMIGRATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD Migrate(PRUint16 aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile) { return _to Migrate(aItems, aStartup, aProfile); } \
  NS_SCRIPTABLE NS_IMETHOD GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, PRUint16 *_retval NS_OUTPARAM) { return _to GetMigrateData(aProfile, aDoingStartup, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceExists(bool *aSourceExists) { return _to GetSourceExists(aSourceExists); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceHasMultipleProfiles(bool *aSourceHasMultipleProfiles) { return _to GetSourceHasMultipleProfiles(aSourceHasMultipleProfiles); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceProfiles(nsISupportsArray * *aSourceProfiles) { return _to GetSourceProfiles(aSourceProfiles); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceHomePageURL(nsACString & aSourceHomePageURL) { return _to GetSourceHomePageURL(aSourceHomePageURL); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERPROFILEMIGRATOR(_to) \
  NS_SCRIPTABLE NS_IMETHOD Migrate(PRUint16 aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Migrate(aItems, aStartup, aProfile); } \
  NS_SCRIPTABLE NS_IMETHOD GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, PRUint16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMigrateData(aProfile, aDoingStartup, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceExists(bool *aSourceExists) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceExists(aSourceExists); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceHasMultipleProfiles(bool *aSourceHasMultipleProfiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceHasMultipleProfiles(aSourceHasMultipleProfiles); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceProfiles(nsISupportsArray * *aSourceProfiles) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceProfiles(aSourceProfiles); } \
  NS_SCRIPTABLE NS_IMETHOD GetSourceHomePageURL(nsACString & aSourceHomePageURL) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSourceHomePageURL(aSourceHomePageURL); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserProfileMigrator : public nsIBrowserProfileMigrator
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERPROFILEMIGRATOR

  nsBrowserProfileMigrator();

private:
  ~nsBrowserProfileMigrator();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserProfileMigrator, nsIBrowserProfileMigrator)

nsBrowserProfileMigrator::nsBrowserProfileMigrator()
{
  /* member initializers and constructor code */
}

nsBrowserProfileMigrator::~nsBrowserProfileMigrator()
{
  /* destructor code */
}

/* void migrate (in unsigned short aItems, in nsIProfileStartup aStartup, in wstring aProfile); */
NS_IMETHODIMP nsBrowserProfileMigrator::Migrate(PRUint16 aItems, nsIProfileStartup *aStartup, const PRUnichar * aProfile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned short getMigrateData (in wstring aProfile, in boolean aDoingStartup); */
NS_IMETHODIMP nsBrowserProfileMigrator::GetMigrateData(const PRUnichar * aProfile, bool aDoingStartup, PRUint16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean sourceExists; */
NS_IMETHODIMP nsBrowserProfileMigrator::GetSourceExists(bool *aSourceExists)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean sourceHasMultipleProfiles; */
NS_IMETHODIMP nsBrowserProfileMigrator::GetSourceHasMultipleProfiles(bool *aSourceHasMultipleProfiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupportsArray sourceProfiles; */
NS_IMETHODIMP nsBrowserProfileMigrator::GetSourceProfiles(nsISupportsArray * *aSourceProfiles)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String sourceHomePageURL; */
NS_IMETHODIMP nsBrowserProfileMigrator::GetSourceHomePageURL(nsACString & aSourceHomePageURL)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserProfileMigrator_h__ */
