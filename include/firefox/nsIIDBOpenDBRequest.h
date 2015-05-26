/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/indexedDB/nsIIDBOpenDBRequest.idl
 */

#ifndef __gen_nsIIDBOpenDBRequest_h__
#define __gen_nsIIDBOpenDBRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */


/* starting interface:    nsIIDBOpenDBRequest */
#define NS_IIDBOPENDBREQUEST_IID_STR "91010fbe-1dfb-435d-852e-288d2804c0a7"

#define NS_IIDBOPENDBREQUEST_IID \
  {0x91010fbe, 0x1dfb, 0x435d, \
    { 0x85, 0x2e, 0x28, 0x8d, 0x28, 0x04, 0xc0, 0xa7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIIDBOpenDBRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBOPENDBREQUEST_IID)

  /* attribute nsIDOMEventListener onblocked; */
  NS_SCRIPTABLE NS_IMETHOD GetOnblocked(nsIDOMEventListener * *aOnblocked) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnblocked(nsIDOMEventListener *aOnblocked) = 0;

  /* attribute nsIDOMEventListener onupgradeneeded; */
  NS_SCRIPTABLE NS_IMETHOD GetOnupgradeneeded(nsIDOMEventListener * *aOnupgradeneeded) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnupgradeneeded(nsIDOMEventListener *aOnupgradeneeded) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBOpenDBRequest, NS_IIDBOPENDBREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBOPENDBREQUEST \
  NS_SCRIPTABLE NS_IMETHOD GetOnblocked(nsIDOMEventListener * *aOnblocked); \
  NS_SCRIPTABLE NS_IMETHOD SetOnblocked(nsIDOMEventListener *aOnblocked); \
  NS_SCRIPTABLE NS_IMETHOD GetOnupgradeneeded(nsIDOMEventListener * *aOnupgradeneeded); \
  NS_SCRIPTABLE NS_IMETHOD SetOnupgradeneeded(nsIDOMEventListener *aOnupgradeneeded); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBOPENDBREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnblocked(nsIDOMEventListener * *aOnblocked) { return _to GetOnblocked(aOnblocked); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnblocked(nsIDOMEventListener *aOnblocked) { return _to SetOnblocked(aOnblocked); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnupgradeneeded(nsIDOMEventListener * *aOnupgradeneeded) { return _to GetOnupgradeneeded(aOnupgradeneeded); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnupgradeneeded(nsIDOMEventListener *aOnupgradeneeded) { return _to SetOnupgradeneeded(aOnupgradeneeded); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBOPENDBREQUEST(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOnblocked(nsIDOMEventListener * *aOnblocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnblocked(aOnblocked); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnblocked(nsIDOMEventListener *aOnblocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnblocked(aOnblocked); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnupgradeneeded(nsIDOMEventListener * *aOnupgradeneeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnupgradeneeded(aOnupgradeneeded); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnupgradeneeded(nsIDOMEventListener *aOnupgradeneeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnupgradeneeded(aOnupgradeneeded); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBOpenDBRequest : public nsIIDBOpenDBRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBOPENDBREQUEST

  nsIDBOpenDBRequest();

private:
  ~nsIDBOpenDBRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBOpenDBRequest, nsIIDBOpenDBRequest)

nsIDBOpenDBRequest::nsIDBOpenDBRequest()
{
  /* member initializers and constructor code */
}

nsIDBOpenDBRequest::~nsIDBOpenDBRequest()
{
  /* destructor code */
}

/* attribute nsIDOMEventListener onblocked; */
NS_IMETHODIMP nsIDBOpenDBRequest::GetOnblocked(nsIDOMEventListener * *aOnblocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBOpenDBRequest::SetOnblocked(nsIDOMEventListener *aOnblocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onupgradeneeded; */
NS_IMETHODIMP nsIDBOpenDBRequest::GetOnupgradeneeded(nsIDOMEventListener * *aOnupgradeneeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBOpenDBRequest::SetOnupgradeneeded(nsIDOMEventListener *aOnupgradeneeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBOpenDBRequest_h__ */
