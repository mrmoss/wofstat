/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/browser/components/sessionstore/nsISessionStartup.idl
 */

#ifndef __gen_nsISessionStartup_h__
#define __gen_nsISessionStartup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsISessionStartup */
#define NS_ISESSIONSTARTUP_IID_STR "170c6857-7f71-46ce-bc9b-185723b1c3a8"

#define NS_ISESSIONSTARTUP_IID \
  {0x170c6857, 0x7f71, 0x46ce, \
    { 0xbc, 0x9b, 0x18, 0x57, 0x23, 0xb1, 0xc3, 0xa8 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISessionStartup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISESSIONSTARTUP_IID)

  /* readonly attribute jsval state; */
  NS_SCRIPTABLE NS_IMETHOD GetState(JS::Value *aState) = 0;

  /* boolean doRestore (); */
  NS_SCRIPTABLE NS_IMETHOD DoRestore(bool *_retval NS_OUTPARAM) = 0;

  enum { NO_SESSION = 0U };

  enum { RECOVER_SESSION = 1U };

  enum { RESUME_SESSION = 2U };

  enum { DEFER_SESSION = 3U };

  /* readonly attribute unsigned long sessionType; */
  NS_SCRIPTABLE NS_IMETHOD GetSessionType(PRUint32 *aSessionType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISessionStartup, NS_ISESSIONSTARTUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISESSIONSTARTUP \
  NS_SCRIPTABLE NS_IMETHOD GetState(JS::Value *aState); \
  NS_SCRIPTABLE NS_IMETHOD DoRestore(bool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSessionType(PRUint32 *aSessionType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISESSIONSTARTUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetState(JS::Value *aState) { return _to GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD DoRestore(bool *_retval NS_OUTPARAM) { return _to DoRestore(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSessionType(PRUint32 *aSessionType) { return _to GetSessionType(aSessionType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISESSIONSTARTUP(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetState(JS::Value *aState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetState(aState); } \
  NS_SCRIPTABLE NS_IMETHOD DoRestore(bool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->DoRestore(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSessionType(PRUint32 *aSessionType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSessionType(aSessionType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSessionStartup : public nsISessionStartup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISESSIONSTARTUP

  nsSessionStartup();

private:
  ~nsSessionStartup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSessionStartup, nsISessionStartup)

nsSessionStartup::nsSessionStartup()
{
  /* member initializers and constructor code */
}

nsSessionStartup::~nsSessionStartup()
{
  /* destructor code */
}

/* readonly attribute jsval state; */
NS_IMETHODIMP nsSessionStartup::GetState(JS::Value *aState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean doRestore (); */
NS_IMETHODIMP nsSessionStartup::DoRestore(bool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long sessionType; */
NS_IMETHODIMP nsSessionStartup::GetSessionType(PRUint32 *aSessionType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISessionStartup_h__ */
