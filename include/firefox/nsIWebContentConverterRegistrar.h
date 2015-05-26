/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/browser/components/feeds/public/nsIWebContentConverterRegistrar.idl
 */

#ifndef __gen_nsIWebContentConverterRegistrar_h__
#define __gen_nsIWebContentConverterRegistrar_h__


#ifndef __gen_nsIMIMEInfo_h__
#include "nsIMIMEInfo.h"
#endif

#ifndef __gen_nsIWebContentHandlerRegistrar_h__
#include "nsIWebContentHandlerRegistrar.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIRequest; /* forward declaration */


/* starting interface:    nsIWebContentHandlerInfo */
#define NS_IWEBCONTENTHANDLERINFO_IID_STR "eb361098-5158-4b21-8f98-50b445f1f0b2"

#define NS_IWEBCONTENTHANDLERINFO_IID \
  {0xeb361098, 0x5158, 0x4b21, \
    { 0x8f, 0x98, 0x50, 0xb4, 0x45, 0xf1, 0xf0, 0xb2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebContentHandlerInfo : public nsIHandlerApp {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBCONTENTHANDLERINFO_IID)

  /* readonly attribute AString contentType; */
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) = 0;

  /* readonly attribute AString uri; */
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsAString & aUri) = 0;

  /* AString getHandlerURI (in AString uri); */
  NS_SCRIPTABLE NS_IMETHOD GetHandlerURI(const nsAString & uri, nsAString & _retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebContentHandlerInfo, NS_IWEBCONTENTHANDLERINFO_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBCONTENTHANDLERINFO \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType); \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsAString & aUri); \
  NS_SCRIPTABLE NS_IMETHOD GetHandlerURI(const nsAString & uri, nsAString & _retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBCONTENTHANDLERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) { return _to GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsAString & aUri) { return _to GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetHandlerURI(const nsAString & uri, nsAString & _retval NS_OUTPARAM) { return _to GetHandlerURI(uri, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBCONTENTHANDLERINFO(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetContentType(nsAString & aContentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentType(aContentType); } \
  NS_SCRIPTABLE NS_IMETHOD GetUri(nsAString & aUri) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUri(aUri); } \
  NS_SCRIPTABLE NS_IMETHOD GetHandlerURI(const nsAString & uri, nsAString & _retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHandlerURI(uri, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebContentHandlerInfo : public nsIWebContentHandlerInfo
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBCONTENTHANDLERINFO

  nsWebContentHandlerInfo();

private:
  ~nsWebContentHandlerInfo();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebContentHandlerInfo, nsIWebContentHandlerInfo)

nsWebContentHandlerInfo::nsWebContentHandlerInfo()
{
  /* member initializers and constructor code */
}

nsWebContentHandlerInfo::~nsWebContentHandlerInfo()
{
  /* destructor code */
}

/* readonly attribute AString contentType; */
NS_IMETHODIMP nsWebContentHandlerInfo::GetContentType(nsAString & aContentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString uri; */
NS_IMETHODIMP nsWebContentHandlerInfo::GetUri(nsAString & aUri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* AString getHandlerURI (in AString uri); */
NS_IMETHODIMP nsWebContentHandlerInfo::GetHandlerURI(const nsAString & uri, nsAString & _retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIWebContentConverterService */
#define NS_IWEBCONTENTCONVERTERSERVICE_IID_STR "de7cc06e-e778-45cb-b7db-7a114e1e75b1"

#define NS_IWEBCONTENTCONVERTERSERVICE_IID \
  {0xde7cc06e, 0xe778, 0x45cb, \
    { 0xb7, 0xdb, 0x7a, 0x11, 0x4e, 0x1e, 0x75, 0xb1 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIWebContentConverterService : public nsIWebContentHandlerRegistrar {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBCONTENTCONVERTERSERVICE_IID)

  /* void setAutoHandler (in AString contentType, in nsIWebContentHandlerInfo handler); */
  NS_SCRIPTABLE NS_IMETHOD SetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo *handler) = 0;

  /* nsIWebContentHandlerInfo getAutoHandler (in AString contentType); */
  NS_SCRIPTABLE NS_IMETHOD GetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM) = 0;

  /* nsIWebContentHandlerInfo getWebContentHandlerByURI (in AString contentType, in AString uri); */
  NS_SCRIPTABLE NS_IMETHOD GetWebContentHandlerByURI(const nsAString & contentType, const nsAString & uri, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM) = 0;

  /* void loadPreferredHandler (in nsIRequest request); */
  NS_SCRIPTABLE NS_IMETHOD LoadPreferredHandler(nsIRequest *request) = 0;

  /* void removeProtocolHandler (in AString protocol, in AString uri); */
  NS_SCRIPTABLE NS_IMETHOD RemoveProtocolHandler(const nsAString & protocol, const nsAString & uri) = 0;

  /* void removeContentHandler (in AString contentType, in AString uri); */
  NS_SCRIPTABLE NS_IMETHOD RemoveContentHandler(const nsAString & contentType, const nsAString & uri) = 0;

  /* void getContentHandlers (in AString contentType, [optional] out unsigned long count, [array, size_is (count), retval] out nsIWebContentHandlerInfo handlers); */
  NS_SCRIPTABLE NS_IMETHOD GetContentHandlers(const nsAString & contentType, PRUint32 *count NS_OUTPARAM, nsIWebContentHandlerInfo * **handlers NS_OUTPARAM) = 0;

  /* void resetHandlersForType (in AString contentType); */
  NS_SCRIPTABLE NS_IMETHOD ResetHandlersForType(const nsAString & contentType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebContentConverterService, NS_IWEBCONTENTCONVERTERSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBCONTENTCONVERTERSERVICE \
  NS_SCRIPTABLE NS_IMETHOD SetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo *handler); \
  NS_SCRIPTABLE NS_IMETHOD GetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetWebContentHandlerByURI(const nsAString & contentType, const nsAString & uri, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD LoadPreferredHandler(nsIRequest *request); \
  NS_SCRIPTABLE NS_IMETHOD RemoveProtocolHandler(const nsAString & protocol, const nsAString & uri); \
  NS_SCRIPTABLE NS_IMETHOD RemoveContentHandler(const nsAString & contentType, const nsAString & uri); \
  NS_SCRIPTABLE NS_IMETHOD GetContentHandlers(const nsAString & contentType, PRUint32 *count NS_OUTPARAM, nsIWebContentHandlerInfo * **handlers NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ResetHandlersForType(const nsAString & contentType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBCONTENTCONVERTERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo *handler) { return _to SetAutoHandler(contentType, handler); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM) { return _to GetAutoHandler(contentType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetWebContentHandlerByURI(const nsAString & contentType, const nsAString & uri, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM) { return _to GetWebContentHandlerByURI(contentType, uri, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadPreferredHandler(nsIRequest *request) { return _to LoadPreferredHandler(request); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveProtocolHandler(const nsAString & protocol, const nsAString & uri) { return _to RemoveProtocolHandler(protocol, uri); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveContentHandler(const nsAString & contentType, const nsAString & uri) { return _to RemoveContentHandler(contentType, uri); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentHandlers(const nsAString & contentType, PRUint32 *count NS_OUTPARAM, nsIWebContentHandlerInfo * **handlers NS_OUTPARAM) { return _to GetContentHandlers(contentType, count, handlers); } \
  NS_SCRIPTABLE NS_IMETHOD ResetHandlersForType(const nsAString & contentType) { return _to ResetHandlersForType(contentType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBCONTENTCONVERTERSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo *handler) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoHandler(contentType, handler); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoHandler(contentType, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetWebContentHandlerByURI(const nsAString & contentType, const nsAString & uri, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWebContentHandlerByURI(contentType, uri, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD LoadPreferredHandler(nsIRequest *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->LoadPreferredHandler(request); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveProtocolHandler(const nsAString & protocol, const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveProtocolHandler(protocol, uri); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveContentHandler(const nsAString & contentType, const nsAString & uri) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveContentHandler(contentType, uri); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentHandlers(const nsAString & contentType, PRUint32 *count NS_OUTPARAM, nsIWebContentHandlerInfo * **handlers NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentHandlers(contentType, count, handlers); } \
  NS_SCRIPTABLE NS_IMETHOD ResetHandlersForType(const nsAString & contentType) { return !_to ? NS_ERROR_NULL_POINTER : _to->ResetHandlersForType(contentType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebContentConverterService : public nsIWebContentConverterService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBCONTENTCONVERTERSERVICE

  nsWebContentConverterService();

private:
  ~nsWebContentConverterService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebContentConverterService, nsIWebContentConverterService)

nsWebContentConverterService::nsWebContentConverterService()
{
  /* member initializers and constructor code */
}

nsWebContentConverterService::~nsWebContentConverterService()
{
  /* destructor code */
}

/* void setAutoHandler (in AString contentType, in nsIWebContentHandlerInfo handler); */
NS_IMETHODIMP nsWebContentConverterService::SetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo *handler)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebContentHandlerInfo getAutoHandler (in AString contentType); */
NS_IMETHODIMP nsWebContentConverterService::GetAutoHandler(const nsAString & contentType, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWebContentHandlerInfo getWebContentHandlerByURI (in AString contentType, in AString uri); */
NS_IMETHODIMP nsWebContentConverterService::GetWebContentHandlerByURI(const nsAString & contentType, const nsAString & uri, nsIWebContentHandlerInfo * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void loadPreferredHandler (in nsIRequest request); */
NS_IMETHODIMP nsWebContentConverterService::LoadPreferredHandler(nsIRequest *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeProtocolHandler (in AString protocol, in AString uri); */
NS_IMETHODIMP nsWebContentConverterService::RemoveProtocolHandler(const nsAString & protocol, const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeContentHandler (in AString contentType, in AString uri); */
NS_IMETHODIMP nsWebContentConverterService::RemoveContentHandler(const nsAString & contentType, const nsAString & uri)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getContentHandlers (in AString contentType, [optional] out unsigned long count, [array, size_is (count), retval] out nsIWebContentHandlerInfo handlers); */
NS_IMETHODIMP nsWebContentConverterService::GetContentHandlers(const nsAString & contentType, PRUint32 *count NS_OUTPARAM, nsIWebContentHandlerInfo * **handlers NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void resetHandlersForType (in AString contentType); */
NS_IMETHODIMP nsWebContentConverterService::ResetHandlersForType(const nsAString & contentType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebContentConverterRegistrar_h__ */
