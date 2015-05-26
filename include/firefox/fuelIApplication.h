/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/browser/fuel/public/fuelIApplication.idl
 */

#ifndef __gen_fuelIApplication_h__
#define __gen_fuelIApplication_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_extIApplication_h__
#include "extIApplication.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMHTMLDocument; /* forward declaration */

class fuelIBookmarkFolder; /* forward declaration */

class fuelIBrowserTab; /* forward declaration */


/* starting interface:    fuelIAnnotations */
#define FUELIANNOTATIONS_IID_STR "335c9292-91a1-4ca0-ad0b-07d5f63ed6cd"

#define FUELIANNOTATIONS_IID \
  {0x335c9292, 0x91a1, 0x4ca0, \
    { 0xad, 0x0b, 0x07, 0xd5, 0xf6, 0x3e, 0xd6, 0xcd }}

class NS_NO_VTABLE NS_SCRIPTABLE fuelIAnnotations : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(FUELIANNOTATIONS_IID)

  /* readonly attribute nsIVariant names; */
  NS_SCRIPTABLE NS_IMETHOD GetNames(nsIVariant * *aNames) = 0;

  /* boolean has (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, bool *_retval NS_OUTPARAM) = 0;

  /* nsIVariant get (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsIVariant * *_retval NS_OUTPARAM) = 0;

  /* void set (in AString aName, in nsIVariant aValue, in PRInt32 aExpiration); */
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue, PRInt32 aExpiration) = 0;

  /* void remove (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(fuelIAnnotations, FUELIANNOTATIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_FUELIANNOTATIONS \
  NS_SCRIPTABLE NS_IMETHOD GetNames(nsIVariant * *aNames); \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, bool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsIVariant * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue, PRInt32 aExpiration); \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_FUELIANNOTATIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNames(nsIVariant * *aNames) { return _to GetNames(aNames); } \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, bool *_retval NS_OUTPARAM) { return _to Has(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsIVariant * *_retval NS_OUTPARAM) { return _to Get(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue, PRInt32 aExpiration) { return _to Set(aName, aValue, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsAString & aName) { return _to Remove(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_FUELIANNOTATIONS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetNames(nsIVariant * *aNames) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNames(aNames); } \
  NS_SCRIPTABLE NS_IMETHOD Has(const nsAString & aName, bool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Has(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Get(const nsAString & aName, nsIVariant * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Get(aName, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Set(const nsAString & aName, nsIVariant *aValue, PRInt32 aExpiration) { return !_to ? NS_ERROR_NULL_POINTER : _to->Set(aName, aValue, aExpiration); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public fuelIAnnotations
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_FUELIANNOTATIONS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, fuelIAnnotations)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute nsIVariant names; */
NS_IMETHODIMP _MYCLASS_::GetNames(nsIVariant * *aNames)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean has (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Has(const nsAString & aName, bool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIVariant get (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Get(const nsAString & aName, nsIVariant * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void set (in AString aName, in nsIVariant aValue, in PRInt32 aExpiration); */
NS_IMETHODIMP _MYCLASS_::Set(const nsAString & aName, nsIVariant *aValue, PRInt32 aExpiration)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in AString aName); */
NS_IMETHODIMP _MYCLASS_::Remove(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    fuelIBookmark */
#define FUELIBOOKMARK_IID_STR "808585b6-7568-4b26-8c62-545221bf2b8c"

#define FUELIBOOKMARK_IID \
  {0x808585b6, 0x7568, 0x4b26, \
    { 0x8c, 0x62, 0x54, 0x52, 0x21, 0xbf, 0x2b, 0x8c }}

class NS_NO_VTABLE NS_SCRIPTABLE fuelIBookmark : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(FUELIBOOKMARK_IID)

  /* readonly attribute long long id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(PRInt64 *aId) = 0;

  /* attribute AString title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) = 0;

  /* attribute AString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) = 0;

  /* attribute AString keyword; */
  NS_SCRIPTABLE NS_IMETHOD GetKeyword(nsAString & aKeyword) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetKeyword(const nsAString & aKeyword) = 0;

  /* readonly attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /* attribute fuelIBookmarkFolder parent; */
  NS_SCRIPTABLE NS_IMETHOD GetParent(fuelIBookmarkFolder * *aParent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetParent(fuelIBookmarkFolder *aParent) = 0;

  /* readonly attribute fuelIAnnotations annotations; */
  NS_SCRIPTABLE NS_IMETHOD GetAnnotations(fuelIAnnotations * *aAnnotations) = 0;

  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /* void remove (); */
  NS_SCRIPTABLE NS_IMETHOD Remove(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(fuelIBookmark, FUELIBOOKMARK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_FUELIBOOKMARK \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRInt64 *aId); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetKeyword(nsAString & aKeyword); \
  NS_SCRIPTABLE NS_IMETHOD SetKeyword(const nsAString & aKeyword); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetParent(fuelIBookmarkFolder * *aParent); \
  NS_SCRIPTABLE NS_IMETHOD SetParent(fuelIBookmarkFolder *aParent); \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotations(fuelIAnnotations * *aAnnotations); \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_SCRIPTABLE NS_IMETHOD Remove(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_FUELIBOOKMARK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRInt64 *aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) { return _to SetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) { return _to SetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyword(nsAString & aKeyword) { return _to GetKeyword(aKeyword); } \
  NS_SCRIPTABLE NS_IMETHOD SetKeyword(const nsAString & aKeyword) { return _to SetKeyword(aKeyword); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(fuelIBookmarkFolder * *aParent) { return _to GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD SetParent(fuelIBookmarkFolder *aParent) { return _to SetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotations(fuelIAnnotations * *aAnnotations) { return _to GetAnnotations(aAnnotations); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(void) { return _to Remove(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_FUELIBOOKMARK(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRInt64 *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD SetUri(nsIURI *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetKeyword(nsAString & aKeyword) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKeyword(aKeyword); } \
  NS_SCRIPTABLE NS_IMETHOD SetKeyword(const nsAString & aKeyword) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKeyword(aKeyword); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(fuelIBookmarkFolder * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD SetParent(fuelIBookmarkFolder *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotations(fuelIAnnotations * *aAnnotations) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotations(aAnnotations); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public fuelIBookmark
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_FUELIBOOKMARK

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, fuelIBookmark)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute long long id; */
NS_IMETHODIMP _MYCLASS_::GetId(PRInt64 *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString title; */
NS_IMETHODIMP _MYCLASS_::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIURI uri; */
NS_IMETHODIMP _MYCLASS_::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetUri(nsIURI *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString description; */
NS_IMETHODIMP _MYCLASS_::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetDescription(const nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString keyword; */
NS_IMETHODIMP _MYCLASS_::GetKeyword(nsAString & aKeyword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetKeyword(const nsAString & aKeyword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString type; */
NS_IMETHODIMP _MYCLASS_::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute fuelIBookmarkFolder parent; */
NS_IMETHODIMP _MYCLASS_::GetParent(fuelIBookmarkFolder * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetParent(fuelIBookmarkFolder *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute fuelIAnnotations annotations; */
NS_IMETHODIMP _MYCLASS_::GetAnnotations(fuelIAnnotations * *aAnnotations)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (); */
NS_IMETHODIMP _MYCLASS_::Remove()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    fuelIBookmarkFolder */
#define FUELIBOOKMARKFOLDER_IID_STR "9f42fe20-52de-4a55-8632-a459c7716aa0"

#define FUELIBOOKMARKFOLDER_IID \
  {0x9f42fe20, 0x52de, 0x4a55, \
    { 0x86, 0x32, 0xa4, 0x59, 0xc7, 0x71, 0x6a, 0xa0 }}

class NS_NO_VTABLE NS_SCRIPTABLE fuelIBookmarkFolder : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(FUELIBOOKMARKFOLDER_IID)

  /* readonly attribute long long id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(PRInt64 *aId) = 0;

  /* attribute AString title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* attribute AString description; */
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) = 0;

  /* readonly attribute AString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;

  /* attribute fuelIBookmarkFolder parent; */
  NS_SCRIPTABLE NS_IMETHOD GetParent(fuelIBookmarkFolder * *aParent) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetParent(fuelIBookmarkFolder *aParent) = 0;

  /* readonly attribute fuelIAnnotations annotations; */
  NS_SCRIPTABLE NS_IMETHOD GetAnnotations(fuelIAnnotations * *aAnnotations) = 0;

  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /* readonly attribute nsIVariant children; */
  NS_SCRIPTABLE NS_IMETHOD GetChildren(nsIVariant * *aChildren) = 0;

  /* fuelIBookmark addBookmark (in AString aTitle, in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD AddBookmark(const nsAString & aTitle, nsIURI *aURI, fuelIBookmark * *_retval NS_OUTPARAM) = 0;

  /* fuelIBookmark addSeparator (); */
  NS_SCRIPTABLE NS_IMETHOD AddSeparator(fuelIBookmark * *_retval NS_OUTPARAM) = 0;

  /* fuelIBookmarkFolder addFolder (in AString aTitle); */
  NS_SCRIPTABLE NS_IMETHOD AddFolder(const nsAString & aTitle, fuelIBookmarkFolder * *_retval NS_OUTPARAM) = 0;

  /* void remove (); */
  NS_SCRIPTABLE NS_IMETHOD Remove(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(fuelIBookmarkFolder, FUELIBOOKMARKFOLDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_FUELIBOOKMARKFOLDER \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRInt64 *aId); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription); \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD GetParent(fuelIBookmarkFolder * *aParent); \
  NS_SCRIPTABLE NS_IMETHOD SetParent(fuelIBookmarkFolder *aParent); \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotations(fuelIAnnotations * *aAnnotations); \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_SCRIPTABLE NS_IMETHOD GetChildren(nsIVariant * *aChildren); \
  NS_SCRIPTABLE NS_IMETHOD AddBookmark(const nsAString & aTitle, nsIURI *aURI, fuelIBookmark * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddSeparator(fuelIBookmark * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD AddFolder(const nsAString & aTitle, fuelIBookmarkFolder * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD Remove(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_FUELIBOOKMARKFOLDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRInt64 *aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return _to GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) { return _to SetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(fuelIBookmarkFolder * *aParent) { return _to GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD SetParent(fuelIBookmarkFolder *aParent) { return _to SetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotations(fuelIAnnotations * *aAnnotations) { return _to GetAnnotations(aAnnotations); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildren(nsIVariant * *aChildren) { return _to GetChildren(aChildren); } \
  NS_SCRIPTABLE NS_IMETHOD AddBookmark(const nsAString & aTitle, nsIURI *aURI, fuelIBookmark * *_retval NS_OUTPARAM) { return _to AddBookmark(aTitle, aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddSeparator(fuelIBookmark * *_retval NS_OUTPARAM) { return _to AddSeparator(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddFolder(const nsAString & aTitle, fuelIBookmarkFolder * *_retval NS_OUTPARAM) { return _to AddFolder(aTitle, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(void) { return _to Remove(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_FUELIBOOKMARKFOLDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(PRInt64 *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDescription(nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD SetDescription(const nsAString & aDescription) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDescription(aDescription); } \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD GetParent(fuelIBookmarkFolder * *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD SetParent(fuelIBookmarkFolder *aParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetParent(aParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetAnnotations(fuelIAnnotations * *aAnnotations) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnnotations(aAnnotations); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD GetChildren(nsIVariant * *aChildren) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildren(aChildren); } \
  NS_SCRIPTABLE NS_IMETHOD AddBookmark(const nsAString & aTitle, nsIURI *aURI, fuelIBookmark * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddBookmark(aTitle, aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddSeparator(fuelIBookmark * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSeparator(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD AddFolder(const nsAString & aTitle, fuelIBookmarkFolder * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddFolder(aTitle, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public fuelIBookmarkFolder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_FUELIBOOKMARKFOLDER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, fuelIBookmarkFolder)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute long long id; */
NS_IMETHODIMP _MYCLASS_::GetId(PRInt64 *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString title; */
NS_IMETHODIMP _MYCLASS_::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString description; */
NS_IMETHODIMP _MYCLASS_::GetDescription(nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetDescription(const nsAString & aDescription)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString type; */
NS_IMETHODIMP _MYCLASS_::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute fuelIBookmarkFolder parent; */
NS_IMETHODIMP _MYCLASS_::GetParent(fuelIBookmarkFolder * *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetParent(fuelIBookmarkFolder *aParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute fuelIAnnotations annotations; */
NS_IMETHODIMP _MYCLASS_::GetAnnotations(fuelIAnnotations * *aAnnotations)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant children; */
NS_IMETHODIMP _MYCLASS_::GetChildren(nsIVariant * *aChildren)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* fuelIBookmark addBookmark (in AString aTitle, in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::AddBookmark(const nsAString & aTitle, nsIURI *aURI, fuelIBookmark * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* fuelIBookmark addSeparator (); */
NS_IMETHODIMP _MYCLASS_::AddSeparator(fuelIBookmark * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* fuelIBookmarkFolder addFolder (in AString aTitle); */
NS_IMETHODIMP _MYCLASS_::AddFolder(const nsAString & aTitle, fuelIBookmarkFolder * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (); */
NS_IMETHODIMP _MYCLASS_::Remove()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    fuelIBookmarkRoots */
#define FUELIBOOKMARKROOTS_IID_STR "c9a80870-eb3c-11dc-95ff-0800200c9a66"

#define FUELIBOOKMARKROOTS_IID \
  {0xc9a80870, 0xeb3c, 0x11dc, \
    { 0x95, 0xff, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE fuelIBookmarkRoots : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(FUELIBOOKMARKROOTS_IID)

  /* readonly attribute fuelIBookmarkFolder menu; */
  NS_SCRIPTABLE NS_IMETHOD GetMenu(fuelIBookmarkFolder * *aMenu) = 0;

  /* readonly attribute fuelIBookmarkFolder toolbar; */
  NS_SCRIPTABLE NS_IMETHOD GetToolbar(fuelIBookmarkFolder * *aToolbar) = 0;

  /* readonly attribute fuelIBookmarkFolder tags; */
  NS_SCRIPTABLE NS_IMETHOD GetTags(fuelIBookmarkFolder * *aTags) = 0;

  /* readonly attribute fuelIBookmarkFolder unfiled; */
  NS_SCRIPTABLE NS_IMETHOD GetUnfiled(fuelIBookmarkFolder * *aUnfiled) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(fuelIBookmarkRoots, FUELIBOOKMARKROOTS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_FUELIBOOKMARKROOTS \
  NS_SCRIPTABLE NS_IMETHOD GetMenu(fuelIBookmarkFolder * *aMenu); \
  NS_SCRIPTABLE NS_IMETHOD GetToolbar(fuelIBookmarkFolder * *aToolbar); \
  NS_SCRIPTABLE NS_IMETHOD GetTags(fuelIBookmarkFolder * *aTags); \
  NS_SCRIPTABLE NS_IMETHOD GetUnfiled(fuelIBookmarkFolder * *aUnfiled); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_FUELIBOOKMARKROOTS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMenu(fuelIBookmarkFolder * *aMenu) { return _to GetMenu(aMenu); } \
  NS_SCRIPTABLE NS_IMETHOD GetToolbar(fuelIBookmarkFolder * *aToolbar) { return _to GetToolbar(aToolbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetTags(fuelIBookmarkFolder * *aTags) { return _to GetTags(aTags); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnfiled(fuelIBookmarkFolder * *aUnfiled) { return _to GetUnfiled(aUnfiled); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_FUELIBOOKMARKROOTS(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetMenu(fuelIBookmarkFolder * *aMenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMenu(aMenu); } \
  NS_SCRIPTABLE NS_IMETHOD GetToolbar(fuelIBookmarkFolder * *aToolbar) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetToolbar(aToolbar); } \
  NS_SCRIPTABLE NS_IMETHOD GetTags(fuelIBookmarkFolder * *aTags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTags(aTags); } \
  NS_SCRIPTABLE NS_IMETHOD GetUnfiled(fuelIBookmarkFolder * *aUnfiled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnfiled(aUnfiled); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public fuelIBookmarkRoots
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_FUELIBOOKMARKROOTS

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, fuelIBookmarkRoots)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute fuelIBookmarkFolder menu; */
NS_IMETHODIMP _MYCLASS_::GetMenu(fuelIBookmarkFolder * *aMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute fuelIBookmarkFolder toolbar; */
NS_IMETHODIMP _MYCLASS_::GetToolbar(fuelIBookmarkFolder * *aToolbar)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute fuelIBookmarkFolder tags; */
NS_IMETHODIMP _MYCLASS_::GetTags(fuelIBookmarkFolder * *aTags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute fuelIBookmarkFolder unfiled; */
NS_IMETHODIMP _MYCLASS_::GetUnfiled(fuelIBookmarkFolder * *aUnfiled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    fuelIWindow */
#define FUELIWINDOW_IID_STR "207edb28-eb5e-424e-a862-b0e97c8de866"

#define FUELIWINDOW_IID \
  {0x207edb28, 0xeb5e, 0x424e, \
    { 0xa8, 0x62, 0xb0, 0xe9, 0x7c, 0x8d, 0xe8, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE fuelIWindow : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(FUELIWINDOW_IID)

  /* readonly attribute nsIVariant tabs; */
  NS_SCRIPTABLE NS_IMETHOD GetTabs(nsIVariant * *aTabs) = 0;

  /* readonly attribute fuelIBrowserTab activeTab; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveTab(fuelIBrowserTab * *aActiveTab) = 0;

  /* fuelIBrowserTab open (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD Open(nsIURI *aURI, fuelIBrowserTab * *_retval NS_OUTPARAM) = 0;

  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(fuelIWindow, FUELIWINDOW_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_FUELIWINDOW \
  NS_SCRIPTABLE NS_IMETHOD GetTabs(nsIVariant * *aTabs); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveTab(fuelIBrowserTab * *aActiveTab); \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIURI *aURI, fuelIBrowserTab * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_FUELIWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTabs(nsIVariant * *aTabs) { return _to GetTabs(aTabs); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveTab(fuelIBrowserTab * *aActiveTab) { return _to GetActiveTab(aActiveTab); } \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIURI *aURI, fuelIBrowserTab * *_retval NS_OUTPARAM) { return _to Open(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_FUELIWINDOW(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTabs(nsIVariant * *aTabs) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabs(aTabs); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveTab(fuelIBrowserTab * *aActiveTab) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveTab(aActiveTab); } \
  NS_SCRIPTABLE NS_IMETHOD Open(nsIURI *aURI, fuelIBrowserTab * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(aURI, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public fuelIWindow
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_FUELIWINDOW

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, fuelIWindow)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute nsIVariant tabs; */
NS_IMETHODIMP _MYCLASS_::GetTabs(nsIVariant * *aTabs)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute fuelIBrowserTab activeTab; */
NS_IMETHODIMP _MYCLASS_::GetActiveTab(fuelIBrowserTab * *aActiveTab)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* fuelIBrowserTab open (in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::Open(nsIURI *aURI, fuelIBrowserTab * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    fuelIBrowserTab */
#define FUELIBROWSERTAB_IID_STR "3073ceff-777c-41ce-9ace-ab37268147c1"

#define FUELIBROWSERTAB_IID \
  {0x3073ceff, 0x777c, 0x41ce, \
    { 0x9a, 0xce, 0xab, 0x37, 0x26, 0x81, 0x47, 0xc1 }}

class NS_NO_VTABLE NS_SCRIPTABLE fuelIBrowserTab : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(FUELIBROWSERTAB_IID)

  /* readonly attribute nsIURI uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) = 0;

  /* readonly attribute PRInt32 index; */
  NS_SCRIPTABLE NS_IMETHOD GetIndex(PRInt32 *aIndex) = 0;

  /* readonly attribute fuelIWindow window; */
  NS_SCRIPTABLE NS_IMETHOD GetWindow(fuelIWindow * *aWindow) = 0;

  /* readonly attribute nsIDOMHTMLDocument document; */
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMHTMLDocument * *aDocument) = 0;

  /* readonly attribute extIEvents events; */
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) = 0;

  /* void load (in nsIURI aURI); */
  NS_SCRIPTABLE NS_IMETHOD Load(nsIURI *aURI) = 0;

  /* void focus (); */
  NS_SCRIPTABLE NS_IMETHOD Focus(void) = 0;

  /* void close (); */
  NS_SCRIPTABLE NS_IMETHOD Close(void) = 0;

  /* void moveBefore (in fuelIBrowserTab aBefore); */
  NS_SCRIPTABLE NS_IMETHOD MoveBefore(fuelIBrowserTab *aBefore) = 0;

  /* void moveToEnd (); */
  NS_SCRIPTABLE NS_IMETHOD MoveToEnd(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(fuelIBrowserTab, FUELIBROWSERTAB_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_FUELIBROWSERTAB \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri); \
  NS_SCRIPTABLE NS_IMETHOD GetIndex(PRInt32 *aIndex); \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(fuelIWindow * *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMHTMLDocument * *aDocument); \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents); \
  NS_SCRIPTABLE NS_IMETHOD Load(nsIURI *aURI); \
  NS_SCRIPTABLE NS_IMETHOD Focus(void); \
  NS_SCRIPTABLE NS_IMETHOD Close(void); \
  NS_SCRIPTABLE NS_IMETHOD MoveBefore(fuelIBrowserTab *aBefore); \
  NS_SCRIPTABLE NS_IMETHOD MoveToEnd(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_FUELIBROWSERTAB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndex(PRInt32 *aIndex) { return _to GetIndex(aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(fuelIWindow * *aWindow) { return _to GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMHTMLDocument * *aDocument) { return _to GetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return _to GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Load(nsIURI *aURI) { return _to Load(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return _to Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return _to Close(); } \
  NS_SCRIPTABLE NS_IMETHOD MoveBefore(fuelIBrowserTab *aBefore) { return _to MoveBefore(aBefore); } \
  NS_SCRIPTABLE NS_IMETHOD MoveToEnd(void) { return _to MoveToEnd(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_FUELIBROWSERTAB(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsIURI * *aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndex(PRInt32 *aIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndex(aIndex); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindow(fuelIWindow * *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetDocument(nsIDOMHTMLDocument * *aDocument) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocument(aDocument); } \
  NS_SCRIPTABLE NS_IMETHOD GetEvents(extIEvents * *aEvents) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEvents(aEvents); } \
  NS_SCRIPTABLE NS_IMETHOD Load(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Load(aURI); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_SCRIPTABLE NS_IMETHOD MoveBefore(fuelIBrowserTab *aBefore) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveBefore(aBefore); } \
  NS_SCRIPTABLE NS_IMETHOD MoveToEnd(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MoveToEnd(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public fuelIBrowserTab
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_FUELIBROWSERTAB

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, fuelIBrowserTab)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute nsIURI uri; */
NS_IMETHODIMP _MYCLASS_::GetUri(nsIURI * *aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute PRInt32 index; */
NS_IMETHODIMP _MYCLASS_::GetIndex(PRInt32 *aIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute fuelIWindow window; */
NS_IMETHODIMP _MYCLASS_::GetWindow(fuelIWindow * *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLDocument document; */
NS_IMETHODIMP _MYCLASS_::GetDocument(nsIDOMHTMLDocument * *aDocument)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute extIEvents events; */
NS_IMETHODIMP _MYCLASS_::GetEvents(extIEvents * *aEvents)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void load (in nsIURI aURI); */
NS_IMETHODIMP _MYCLASS_::Load(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP _MYCLASS_::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP _MYCLASS_::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveBefore (in fuelIBrowserTab aBefore); */
NS_IMETHODIMP _MYCLASS_::MoveBefore(fuelIBrowserTab *aBefore)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void moveToEnd (); */
NS_IMETHODIMP _MYCLASS_::MoveToEnd()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    fuelIApplication */
#define FUELIAPPLICATION_IID_STR "fe74cf80-aa2d-11db-abbd-0800200c9a66"

#define FUELIAPPLICATION_IID \
  {0xfe74cf80, 0xaa2d, 0x11db, \
    { 0xab, 0xbd, 0x08, 0x00, 0x20, 0x0c, 0x9a, 0x66 }}

class NS_NO_VTABLE NS_SCRIPTABLE fuelIApplication : public extIApplication {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(FUELIAPPLICATION_IID)

  /* readonly attribute fuelIBookmarkRoots bookmarks; */
  NS_SCRIPTABLE NS_IMETHOD GetBookmarks(fuelIBookmarkRoots * *aBookmarks) = 0;

  /* readonly attribute nsIVariant windows; */
  NS_SCRIPTABLE NS_IMETHOD GetWindows(nsIVariant * *aWindows) = 0;

  /* readonly attribute fuelIWindow activeWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetActiveWindow(fuelIWindow * *aActiveWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(fuelIApplication, FUELIAPPLICATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_FUELIAPPLICATION \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarks(fuelIBookmarkRoots * *aBookmarks); \
  NS_SCRIPTABLE NS_IMETHOD GetWindows(nsIVariant * *aWindows); \
  NS_SCRIPTABLE NS_IMETHOD GetActiveWindow(fuelIWindow * *aActiveWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_FUELIAPPLICATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarks(fuelIBookmarkRoots * *aBookmarks) { return _to GetBookmarks(aBookmarks); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindows(nsIVariant * *aWindows) { return _to GetWindows(aWindows); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveWindow(fuelIWindow * *aActiveWindow) { return _to GetActiveWindow(aActiveWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_FUELIAPPLICATION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetBookmarks(fuelIBookmarkRoots * *aBookmarks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBookmarks(aBookmarks); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindows(nsIVariant * *aWindows) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindows(aWindows); } \
  NS_SCRIPTABLE NS_IMETHOD GetActiveWindow(fuelIWindow * *aActiveWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetActiveWindow(aActiveWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public fuelIApplication
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_FUELIAPPLICATION

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, fuelIApplication)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* readonly attribute fuelIBookmarkRoots bookmarks; */
NS_IMETHODIMP _MYCLASS_::GetBookmarks(fuelIBookmarkRoots * *aBookmarks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIVariant windows; */
NS_IMETHODIMP _MYCLASS_::GetWindows(nsIVariant * *aWindows)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute fuelIWindow activeWindow; */
NS_IMETHODIMP _MYCLASS_::GetActiveWindow(fuelIWindow * *aActiveWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_fuelIApplication_h__ */
