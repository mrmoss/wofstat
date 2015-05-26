/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/xpfe/appshell/public/nsIAppShellService.idl
 */

#ifndef __gen_nsIAppShellService_h__
#define __gen_nsIAppShellService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXULWindow; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIDOMWindow; /* forward declaration */

class nsIAppShell; /* forward declaration */

struct JSContext;

/* starting interface:    nsIAppShellService */
#define NS_IAPPSHELLSERVICE_IID_STR "ebcd34e2-2e43-45c0-aac8-e6f1c692b371"

#define NS_IAPPSHELLSERVICE_IID \
  {0xebcd34e2, 0x2e43, 0x45c0, \
    { 0xaa, 0xc8, 0xe6, 0xf1, 0xc6, 0x92, 0xb3, 0x71 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIAppShellService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPSHELLSERVICE_IID)

  enum { SIZE_TO_CONTENT = -1 };

  /* nsIXULWindow createTopLevelWindow (in nsIXULWindow aParent, in nsIURI aUrl, in PRUint32 aChromeMask, in long aInitialWidth, in long aInitialHeight); */
  NS_SCRIPTABLE NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIXULWindow * *_retval NS_OUTPARAM) = 0;

  /* [noscript] void createHiddenWindow (); */
  NS_IMETHOD CreateHiddenWindow(void) = 0;

  /* void destroyHiddenWindow (); */
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) = 0;

  /* readonly attribute nsIXULWindow hiddenWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) = 0;

  /* readonly attribute nsIDOMWindow hiddenDOMWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow) = 0;

  /* [noscript] void getHiddenWindowAndJSContext (out nsIDOMWindow aHiddenDOMWindow, out JSContext aJSContext); */
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow NS_OUTPARAM, JSContext **aJSContext NS_OUTPARAM) = 0;

  /* readonly attribute boolean applicationProvidedHiddenWindow; */
  NS_SCRIPTABLE NS_IMETHOD GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow) = 0;

  /* void registerTopLevelWindow (in nsIXULWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) = 0;

  /* void unregisterTopLevelWindow (in nsIXULWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppShellService, NS_IAPPSHELLSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPSHELLSERVICE \
  NS_SCRIPTABLE NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIXULWindow * *_retval NS_OUTPARAM); \
  NS_IMETHOD CreateHiddenWindow(void); \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void); \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow); \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow NS_OUTPARAM, JSContext **aJSContext NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow); \
  NS_SCRIPTABLE NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPSHELLSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIXULWindow * *_retval NS_OUTPARAM) { return _to CreateTopLevelWindow(aParent, aUrl, aChromeMask, aInitialWidth, aInitialHeight, _retval); } \
  NS_IMETHOD CreateHiddenWindow(void) { return _to CreateHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) { return _to DestroyHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) { return _to GetHiddenWindow(aHiddenWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow) { return _to GetHiddenDOMWindow(aHiddenDOMWindow); } \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow NS_OUTPARAM, JSContext **aJSContext NS_OUTPARAM) { return _to GetHiddenWindowAndJSContext(aHiddenDOMWindow, aJSContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow) { return _to GetApplicationProvidedHiddenWindow(aApplicationProvidedHiddenWindow); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) { return _to RegisterTopLevelWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) { return _to UnregisterTopLevelWindow(aWindow); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPSHELLSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIXULWindow * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateTopLevelWindow(aParent, aUrl, aChromeMask, aInitialWidth, aInitialHeight, _retval); } \
  NS_IMETHOD CreateHiddenWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD DestroyHiddenWindow(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->DestroyHiddenWindow(); } \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenWindow(nsIXULWindow * *aHiddenWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenWindow(aHiddenWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenDOMWindow(aHiddenDOMWindow); } \
  NS_IMETHOD GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow NS_OUTPARAM, JSContext **aJSContext NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHiddenWindowAndJSContext(aHiddenDOMWindow, aJSContext); } \
  NS_SCRIPTABLE NS_IMETHOD GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetApplicationProvidedHiddenWindow(aApplicationProvidedHiddenWindow); } \
  NS_SCRIPTABLE NS_IMETHOD RegisterTopLevelWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->RegisterTopLevelWindow(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD UnregisterTopLevelWindow(nsIXULWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->UnregisterTopLevelWindow(aWindow); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppShellService : public nsIAppShellService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPSHELLSERVICE

  nsAppShellService();

private:
  ~nsAppShellService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppShellService, nsIAppShellService)

nsAppShellService::nsAppShellService()
{
  /* member initializers and constructor code */
}

nsAppShellService::~nsAppShellService()
{
  /* destructor code */
}

/* nsIXULWindow createTopLevelWindow (in nsIXULWindow aParent, in nsIURI aUrl, in PRUint32 aChromeMask, in long aInitialWidth, in long aInitialHeight); */
NS_IMETHODIMP nsAppShellService::CreateTopLevelWindow(nsIXULWindow *aParent, nsIURI *aUrl, PRUint32 aChromeMask, PRInt32 aInitialWidth, PRInt32 aInitialHeight, nsIXULWindow * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void createHiddenWindow (); */
NS_IMETHODIMP nsAppShellService::CreateHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void destroyHiddenWindow (); */
NS_IMETHODIMP nsAppShellService::DestroyHiddenWindow()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXULWindow hiddenWindow; */
NS_IMETHODIMP nsAppShellService::GetHiddenWindow(nsIXULWindow * *aHiddenWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMWindow hiddenDOMWindow; */
NS_IMETHODIMP nsAppShellService::GetHiddenDOMWindow(nsIDOMWindow * *aHiddenDOMWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getHiddenWindowAndJSContext (out nsIDOMWindow aHiddenDOMWindow, out JSContext aJSContext); */
NS_IMETHODIMP nsAppShellService::GetHiddenWindowAndJSContext(nsIDOMWindow * *aHiddenDOMWindow NS_OUTPARAM, JSContext **aJSContext NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean applicationProvidedHiddenWindow; */
NS_IMETHODIMP nsAppShellService::GetApplicationProvidedHiddenWindow(bool *aApplicationProvidedHiddenWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void registerTopLevelWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsAppShellService::RegisterTopLevelWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void unregisterTopLevelWindow (in nsIXULWindow aWindow); */
NS_IMETHODIMP nsAppShellService::UnregisterTopLevelWindow(nsIXULWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppShellService_h__ */
