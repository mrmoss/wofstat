/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/indexedDB/nsIIDBVersionChangeEvent.idl
 */

#ifndef __gen_nsIIDBVersionChangeEvent_h__
#define __gen_nsIIDBVersionChangeEvent_h__


#ifndef __gen_nsIDOMEvent_h__
#include "nsIDOMEvent.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIIDBVersionChangeEvent */
#define NS_IIDBVERSIONCHANGEEVENT_IID_STR "52e21085-d6cd-4886-a5eb-19b47d13abf6"

#define NS_IIDBVERSIONCHANGEEVENT_IID \
  {0x52e21085, 0xd6cd, 0x4886, \
    { 0xa5, 0xeb, 0x19, 0xb4, 0x7d, 0x13, 0xab, 0xf6 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBVersionChangeEvent : public nsIDOMEvent {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBVERSIONCHANGEEVENT_IID)

  /* readonly attribute unsigned long long oldVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetOldVersion(PRUint64 *aOldVersion) = 0;

  /* readonly attribute unsigned long long newVersion; */
  NS_SCRIPTABLE NS_IMETHOD GetNewVersion(PRUint64 *aNewVersion) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBVersionChangeEvent, NS_IIDBVERSIONCHANGEEVENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBVERSIONCHANGEEVENT \
  NS_SCRIPTABLE NS_IMETHOD GetOldVersion(PRUint64 *aOldVersion); \
  NS_SCRIPTABLE NS_IMETHOD GetNewVersion(PRUint64 *aNewVersion); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBVERSIONCHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOldVersion(PRUint64 *aOldVersion) { return _to GetOldVersion(aOldVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewVersion(PRUint64 *aNewVersion) { return _to GetNewVersion(aNewVersion); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBVERSIONCHANGEEVENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOldVersion(PRUint64 *aOldVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOldVersion(aOldVersion); } \
  NS_SCRIPTABLE NS_IMETHOD GetNewVersion(PRUint64 *aNewVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNewVersion(aNewVersion); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBVersionChangeEvent : public nsIIDBVersionChangeEvent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBVERSIONCHANGEEVENT

  nsIDBVersionChangeEvent();

private:
  ~nsIDBVersionChangeEvent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBVersionChangeEvent, nsIIDBVersionChangeEvent)

nsIDBVersionChangeEvent::nsIDBVersionChangeEvent()
{
  /* member initializers and constructor code */
}

nsIDBVersionChangeEvent::~nsIDBVersionChangeEvent()
{
  /* destructor code */
}

/* readonly attribute unsigned long long oldVersion; */
NS_IMETHODIMP nsIDBVersionChangeEvent::GetOldVersion(PRUint64 *aOldVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long newVersion; */
NS_IMETHODIMP nsIDBVersionChangeEvent::GetNewVersion(PRUint64 *aNewVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBVersionChangeEvent_h__ */
