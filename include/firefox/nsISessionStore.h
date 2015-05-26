/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/browser/components/sessionstore/nsISessionStore.idl
 */

#ifndef __gen_nsISessionStore_h__
#define __gen_nsISessionStore_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsIDOMNode; /* forward declaration */


/* starting interface:    nsISessionStore */
#define NS_ISESSIONSTORE_IID_STR "59bfaf00-e3d8-4728-b4f0-cc0b9dfb4806"

#define NS_ISESSIONSTORE_IID \
  {0x59bfaf00, 0xe3d8, 0x4728, \
    { 0xb4, 0xf0, 0xcc, 0x0b, 0x9d, 0xfb, 0x48, 0x06 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISessionStore : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISESSIONSTORE_IID)

  /* void init (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) = 0;

  /* attribute boolean canRestoreLastSession; */
  NS_SCRIPTABLE NS_IMETHOD GetCanRestoreLastSession(bool *aCanRestoreLastSession) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCanRestoreLastSession(bool aCanRestoreLastSession) = 0;

  /* void restoreLastSession (); */
  NS_SCRIPTABLE NS_IMETHOD RestoreLastSession(void) = 0;

  /* AString getBrowserState (); */
  NS_SCRIPTABLE NS_IMETHOD GetBrowserState(nsAString & _retval NS_OUTPARAM) = 0;

  /* void setBrowserState (in AString aState); */
  NS_SCRIPTABLE NS_IMETHOD SetBrowserState(const nsAString & aState) = 0;

  /* AString getWindowState (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM) = 0;

  /* void setWindowState (in nsIDOMWindow aWindow, in AString aState, in boolean aOverwrite); */
  NS_SCRIPTABLE NS_IMETHOD SetWindowState(nsIDOMWindow *aWindow, const nsAString & aState, bool aOverwrite) = 0;

  /* AString getTabState (in nsIDOMNode aTab); */
  NS_SCRIPTABLE NS_IMETHOD GetTabState(nsIDOMNode *aTab, nsAString & _retval NS_OUTPARAM) = 0;

  /* void setTabState (in nsIDOMNode aTab, in AString aState); */
  NS_SCRIPTABLE NS_IMETHOD SetTabState(nsIDOMNode *aTab, const nsAString & aState) = 0;

  /* nsIDOMNode duplicateTab (in nsIDOMWindow aWindow, in nsIDOMNode aTab, [optional] in long aDelta); */
  NS_SCRIPTABLE NS_IMETHOD DuplicateTab(nsIDOMWindow *aWindow, nsIDOMNode *aTab, PRInt32 aDelta, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* unsigned long getClosedTabCount (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD GetClosedTabCount(nsIDOMWindow *aWindow, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* AString getClosedTabData (in nsIDOMWindow aWindow); */
  NS_SCRIPTABLE NS_IMETHOD GetClosedTabData(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM) = 0;

  /* nsIDOMNode undoCloseTab (in nsIDOMWindow aWindow, in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD UndoCloseTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode forgetClosedTab (in nsIDOMWindow aWindow, in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD ForgetClosedTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* unsigned long getClosedWindowCount (); */
  NS_SCRIPTABLE NS_IMETHOD GetClosedWindowCount(PRUint32 *_retval NS_OUTPARAM) = 0;

  /* AString getClosedWindowData (); */
  NS_SCRIPTABLE NS_IMETHOD GetClosedWindowData(nsAString & _retval NS_OUTPARAM) = 0;

  /* nsIDOMWindow undoCloseWindow (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD UndoCloseWindow(PRUint32 aIndex, nsIDOMWindow * *_retval NS_OUTPARAM) = 0;

  /* nsIDOMNode forgetClosedWindow (in unsigned long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD ForgetClosedWindow(PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* AString getWindowValue (in nsIDOMWindow aWindow, in AString aKey); */
  NS_SCRIPTABLE NS_IMETHOD GetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, nsAString & _retval NS_OUTPARAM) = 0;

  /* void setWindowValue (in nsIDOMWindow aWindow, in AString aKey, in AString aStringValue); */
  NS_SCRIPTABLE NS_IMETHOD SetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, const nsAString & aStringValue) = 0;

  /* void deleteWindowValue (in nsIDOMWindow aWindow, in AString aKey); */
  NS_SCRIPTABLE NS_IMETHOD DeleteWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey) = 0;

  /* AString getTabValue (in nsIDOMNode aTab, in AString aKey); */
  NS_SCRIPTABLE NS_IMETHOD GetTabValue(nsIDOMNode *aTab, const nsAString & aKey, nsAString & _retval NS_OUTPARAM) = 0;

  /* void setTabValue (in nsIDOMNode aTab, in AString aKey, in AString aStringValue); */
  NS_SCRIPTABLE NS_IMETHOD SetTabValue(nsIDOMNode *aTab, const nsAString & aKey, const nsAString & aStringValue) = 0;

  /* void deleteTabValue (in nsIDOMNode aTab, in AString aKey); */
  NS_SCRIPTABLE NS_IMETHOD DeleteTabValue(nsIDOMNode *aTab, const nsAString & aKey) = 0;

  /* void persistTabAttribute (in AString aName); */
  NS_SCRIPTABLE NS_IMETHOD PersistTabAttribute(const nsAString & aName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISessionStore, NS_ISESSIONSTORE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISESSIONSTORE \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow); \
  NS_SCRIPTABLE NS_IMETHOD GetCanRestoreLastSession(bool *aCanRestoreLastSession); \
  NS_SCRIPTABLE NS_IMETHOD SetCanRestoreLastSession(bool aCanRestoreLastSession); \
  NS_SCRIPTABLE NS_IMETHOD RestoreLastSession(void); \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserState(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserState(const nsAString & aState); \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetWindowState(nsIDOMWindow *aWindow, const nsAString & aState, bool aOverwrite); \
  NS_SCRIPTABLE NS_IMETHOD GetTabState(nsIDOMNode *aTab, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetTabState(nsIDOMNode *aTab, const nsAString & aState); \
  NS_SCRIPTABLE NS_IMETHOD DuplicateTab(nsIDOMWindow *aWindow, nsIDOMNode *aTab, PRInt32 aDelta, nsIDOMNode * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetClosedTabCount(nsIDOMWindow *aWindow, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetClosedTabData(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UndoCloseTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ForgetClosedTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetClosedWindowCount(PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetClosedWindowData(nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD UndoCloseWindow(PRUint32 aIndex, nsIDOMWindow * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ForgetClosedWindow(PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, const nsAString & aStringValue); \
  NS_SCRIPTABLE NS_IMETHOD DeleteWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey); \
  NS_SCRIPTABLE NS_IMETHOD GetTabValue(nsIDOMNode *aTab, const nsAString & aKey, nsAString & _retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD SetTabValue(nsIDOMNode *aTab, const nsAString & aKey, const nsAString & aStringValue); \
  NS_SCRIPTABLE NS_IMETHOD DeleteTabValue(nsIDOMNode *aTab, const nsAString & aKey); \
  NS_SCRIPTABLE NS_IMETHOD PersistTabAttribute(const nsAString & aName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISESSIONSTORE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) { return _to Init(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanRestoreLastSession(bool *aCanRestoreLastSession) { return _to GetCanRestoreLastSession(aCanRestoreLastSession); } \
  NS_SCRIPTABLE NS_IMETHOD SetCanRestoreLastSession(bool aCanRestoreLastSession) { return _to SetCanRestoreLastSession(aCanRestoreLastSession); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreLastSession(void) { return _to RestoreLastSession(); } \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserState(nsAString & _retval NS_OUTPARAM) { return _to GetBrowserState(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserState(const nsAString & aState) { return _to SetBrowserState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM) { return _to GetWindowState(aWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetWindowState(nsIDOMWindow *aWindow, const nsAString & aState, bool aOverwrite) { return _to SetWindowState(aWindow, aState, aOverwrite); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabState(nsIDOMNode *aTab, nsAString & _retval NS_OUTPARAM) { return _to GetTabState(aTab, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabState(nsIDOMNode *aTab, const nsAString & aState) { return _to SetTabState(aTab, aState); } \
  NS_SCRIPTABLE NS_IMETHOD DuplicateTab(nsIDOMWindow *aWindow, nsIDOMNode *aTab, PRInt32 aDelta, nsIDOMNode * *_retval NS_OUTPARAM) { return _to DuplicateTab(aWindow, aTab, aDelta, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosedTabCount(nsIDOMWindow *aWindow, PRUint32 *_retval NS_OUTPARAM) { return _to GetClosedTabCount(aWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosedTabData(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM) { return _to GetClosedTabData(aWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UndoCloseTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) { return _to UndoCloseTab(aWindow, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ForgetClosedTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) { return _to ForgetClosedTab(aWindow, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosedWindowCount(PRUint32 *_retval NS_OUTPARAM) { return _to GetClosedWindowCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosedWindowData(nsAString & _retval NS_OUTPARAM) { return _to GetClosedWindowData(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD UndoCloseWindow(PRUint32 aIndex, nsIDOMWindow * *_retval NS_OUTPARAM) { return _to UndoCloseWindow(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ForgetClosedWindow(PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) { return _to ForgetClosedWindow(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, nsAString & _retval NS_OUTPARAM) { return _to GetWindowValue(aWindow, aKey, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, const nsAString & aStringValue) { return _to SetWindowValue(aWindow, aKey, aStringValue); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey) { return _to DeleteWindowValue(aWindow, aKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabValue(nsIDOMNode *aTab, const nsAString & aKey, nsAString & _retval NS_OUTPARAM) { return _to GetTabValue(aTab, aKey, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabValue(nsIDOMNode *aTab, const nsAString & aKey, const nsAString & aStringValue) { return _to SetTabValue(aTab, aKey, aStringValue); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTabValue(nsIDOMNode *aTab, const nsAString & aKey) { return _to DeleteTabValue(aTab, aKey); } \
  NS_SCRIPTABLE NS_IMETHOD PersistTabAttribute(const nsAString & aName) { return _to PersistTabAttribute(aName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISESSIONSTORE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIDOMWindow *aWindow) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aWindow); } \
  NS_SCRIPTABLE NS_IMETHOD GetCanRestoreLastSession(bool *aCanRestoreLastSession) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanRestoreLastSession(aCanRestoreLastSession); } \
  NS_SCRIPTABLE NS_IMETHOD SetCanRestoreLastSession(bool aCanRestoreLastSession) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCanRestoreLastSession(aCanRestoreLastSession); } \
  NS_SCRIPTABLE NS_IMETHOD RestoreLastSession(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->RestoreLastSession(); } \
  NS_SCRIPTABLE NS_IMETHOD GetBrowserState(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBrowserState(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetBrowserState(const nsAString & aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBrowserState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindowState(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowState(aWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetWindowState(nsIDOMWindow *aWindow, const nsAString & aState, bool aOverwrite) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindowState(aWindow, aState, aOverwrite); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabState(nsIDOMNode *aTab, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabState(aTab, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabState(nsIDOMNode *aTab, const nsAString & aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabState(aTab, aState); } \
  NS_SCRIPTABLE NS_IMETHOD DuplicateTab(nsIDOMWindow *aWindow, nsIDOMNode *aTab, PRInt32 aDelta, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DuplicateTab(aWindow, aTab, aDelta, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosedTabCount(nsIDOMWindow *aWindow, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosedTabCount(aWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosedTabData(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosedTabData(aWindow, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD UndoCloseTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UndoCloseTab(aWindow, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ForgetClosedTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForgetClosedTab(aWindow, aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosedWindowCount(PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosedWindowCount(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetClosedWindowData(nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClosedWindowData(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD UndoCloseWindow(PRUint32 aIndex, nsIDOMWindow * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->UndoCloseWindow(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ForgetClosedWindow(PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForgetClosedWindow(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWindowValue(aWindow, aKey, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, const nsAString & aStringValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetWindowValue(aWindow, aKey, aStringValue); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteWindowValue(aWindow, aKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabValue(nsIDOMNode *aTab, const nsAString & aKey, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabValue(aTab, aKey, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabValue(nsIDOMNode *aTab, const nsAString & aKey, const nsAString & aStringValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabValue(aTab, aKey, aStringValue); } \
  NS_SCRIPTABLE NS_IMETHOD DeleteTabValue(nsIDOMNode *aTab, const nsAString & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->DeleteTabValue(aTab, aKey); } \
  NS_SCRIPTABLE NS_IMETHOD PersistTabAttribute(const nsAString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->PersistTabAttribute(aName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSessionStore : public nsISessionStore
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISESSIONSTORE

  nsSessionStore();

private:
  ~nsSessionStore();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSessionStore, nsISessionStore)

nsSessionStore::nsSessionStore()
{
  /* member initializers and constructor code */
}

nsSessionStore::~nsSessionStore()
{
  /* destructor code */
}

/* void init (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsSessionStore::Init(nsIDOMWindow *aWindow)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean canRestoreLastSession; */
NS_IMETHODIMP nsSessionStore::GetCanRestoreLastSession(bool *aCanRestoreLastSession)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsSessionStore::SetCanRestoreLastSession(bool aCanRestoreLastSession)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void restoreLastSession (); */
NS_IMETHODIMP nsSessionStore::RestoreLastSession()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getBrowserState (); */
NS_IMETHODIMP nsSessionStore::GetBrowserState(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setBrowserState (in AString aState); */
NS_IMETHODIMP nsSessionStore::SetBrowserState(const nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getWindowState (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsSessionStore::GetWindowState(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWindowState (in nsIDOMWindow aWindow, in AString aState, in boolean aOverwrite); */
NS_IMETHODIMP nsSessionStore::SetWindowState(nsIDOMWindow *aWindow, const nsAString & aState, bool aOverwrite)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTabState (in nsIDOMNode aTab); */
NS_IMETHODIMP nsSessionStore::GetTabState(nsIDOMNode *aTab, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTabState (in nsIDOMNode aTab, in AString aState); */
NS_IMETHODIMP nsSessionStore::SetTabState(nsIDOMNode *aTab, const nsAString & aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode duplicateTab (in nsIDOMWindow aWindow, in nsIDOMNode aTab, [optional] in long aDelta); */
NS_IMETHODIMP nsSessionStore::DuplicateTab(nsIDOMWindow *aWindow, nsIDOMNode *aTab, PRInt32 aDelta, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getClosedTabCount (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsSessionStore::GetClosedTabCount(nsIDOMWindow *aWindow, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getClosedTabData (in nsIDOMWindow aWindow); */
NS_IMETHODIMP nsSessionStore::GetClosedTabData(nsIDOMWindow *aWindow, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode undoCloseTab (in nsIDOMWindow aWindow, in unsigned long aIndex); */
NS_IMETHODIMP nsSessionStore::UndoCloseTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode forgetClosedTab (in nsIDOMWindow aWindow, in unsigned long aIndex); */
NS_IMETHODIMP nsSessionStore::ForgetClosedTab(nsIDOMWindow *aWindow, PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getClosedWindowCount (); */
NS_IMETHODIMP nsSessionStore::GetClosedWindowCount(PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getClosedWindowData (); */
NS_IMETHODIMP nsSessionStore::GetClosedWindowData(nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMWindow undoCloseWindow (in unsigned long aIndex); */
NS_IMETHODIMP nsSessionStore::UndoCloseWindow(PRUint32 aIndex, nsIDOMWindow * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode forgetClosedWindow (in unsigned long aIndex); */
NS_IMETHODIMP nsSessionStore::ForgetClosedWindow(PRUint32 aIndex, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getWindowValue (in nsIDOMWindow aWindow, in AString aKey); */
NS_IMETHODIMP nsSessionStore::GetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setWindowValue (in nsIDOMWindow aWindow, in AString aKey, in AString aStringValue); */
NS_IMETHODIMP nsSessionStore::SetWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey, const nsAString & aStringValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteWindowValue (in nsIDOMWindow aWindow, in AString aKey); */
NS_IMETHODIMP nsSessionStore::DeleteWindowValue(nsIDOMWindow *aWindow, const nsAString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getTabValue (in nsIDOMNode aTab, in AString aKey); */
NS_IMETHODIMP nsSessionStore::GetTabValue(nsIDOMNode *aTab, const nsAString & aKey, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setTabValue (in nsIDOMNode aTab, in AString aKey, in AString aStringValue); */
NS_IMETHODIMP nsSessionStore::SetTabValue(nsIDOMNode *aTab, const nsAString & aKey, const nsAString & aStringValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void deleteTabValue (in nsIDOMNode aTab, in AString aKey); */
NS_IMETHODIMP nsSessionStore::DeleteTabValue(nsIDOMNode *aTab, const nsAString & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void persistTabAttribute (in AString aName); */
NS_IMETHODIMP nsSessionStore::PersistTabAttribute(const nsAString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISessionStore_h__ */
