/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/browser/components/nsIBrowserGlue.idl
 */

#ifndef __gen_nsIBrowserGlue_h__
#define __gen_nsIBrowserGlue_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */


/* starting interface:    nsIBrowserGlue */
#define NS_IBROWSERGLUE_IID_STR "781df699-17dc-4237-b3d7-876ddb7085e3"

#define NS_IBROWSERGLUE_IID \
  {0x781df699, 0x17dc, 0x4237, \
    { 0xb3, 0xd7, 0x87, 0x6d, 0xdb, 0x70, 0x85, 0xe3 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIBrowserGlue : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBROWSERGLUE_IID)

  /* void sanitize (in nsIDOMWindow aParentWindow); */
  NS_SCRIPTABLE NS_IMETHOD Sanitize(nsIDOMWindow *aParentWindow) = 0;

  /* void ensurePlacesDefaultQueriesInitialized (); */
  NS_SCRIPTABLE NS_IMETHOD EnsurePlacesDefaultQueriesInitialized(void) = 0;

  /* nsIDOMWindow getMostRecentBrowserWindow (); */
  NS_SCRIPTABLE NS_IMETHOD GetMostRecentBrowserWindow(nsIDOMWindow * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIBrowserGlue, NS_IBROWSERGLUE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBROWSERGLUE \
  NS_SCRIPTABLE NS_IMETHOD Sanitize(nsIDOMWindow *aParentWindow); \
  NS_SCRIPTABLE NS_IMETHOD EnsurePlacesDefaultQueriesInitialized(void); \
  NS_SCRIPTABLE NS_IMETHOD GetMostRecentBrowserWindow(nsIDOMWindow * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBROWSERGLUE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Sanitize(nsIDOMWindow *aParentWindow) { return _to Sanitize(aParentWindow); } \
  NS_SCRIPTABLE NS_IMETHOD EnsurePlacesDefaultQueriesInitialized(void) { return _to EnsurePlacesDefaultQueriesInitialized(); } \
  NS_SCRIPTABLE NS_IMETHOD GetMostRecentBrowserWindow(nsIDOMWindow * *_retval NS_OUTPARAM) { return _to GetMostRecentBrowserWindow(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBROWSERGLUE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Sanitize(nsIDOMWindow *aParentWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->Sanitize(aParentWindow); } \
  NS_SCRIPTABLE NS_IMETHOD EnsurePlacesDefaultQueriesInitialized(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnsurePlacesDefaultQueriesInitialized(); } \
  NS_SCRIPTABLE NS_IMETHOD GetMostRecentBrowserWindow(nsIDOMWindow * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMostRecentBrowserWindow(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsBrowserGlue : public nsIBrowserGlue
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBROWSERGLUE

  nsBrowserGlue();

private:
  ~nsBrowserGlue();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsBrowserGlue, nsIBrowserGlue)

nsBrowserGlue::nsBrowserGlue()
{
  /* member initializers and constructor code */
}

nsBrowserGlue::~nsBrowserGlue()
{
  /* destructor code */
}

/* void sanitize (in nsIDOMWindow aParentWindow); */
NS_IMETHODIMP nsBrowserGlue::Sanitize(nsIDOMWindow *aParentWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void ensurePlacesDefaultQueriesInitialized (); */
NS_IMETHODIMP nsBrowserGlue::EnsurePlacesDefaultQueriesInitialized()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow getMostRecentBrowserWindow (); */
NS_IMETHODIMP nsBrowserGlue::GetMostRecentBrowserWindow(nsIDOMWindow * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIBrowserGlue_h__ */
