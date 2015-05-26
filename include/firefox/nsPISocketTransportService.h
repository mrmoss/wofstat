/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/netwerk/base/public/nsPISocketTransportService.idl
 */

#ifndef __gen_nsPISocketTransportService_h__
#define __gen_nsPISocketTransportService_h__


#ifndef __gen_nsISocketTransportService_h__
#include "nsISocketTransportService.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsPISocketTransportService */
#define NS_PISOCKETTRANSPORTSERVICE_IID_STR "83123036-81c0-47cb-8d9c-bd85d29a1b3f"

#define NS_PISOCKETTRANSPORTSERVICE_IID \
  {0x83123036, 0x81c0, 0x47cb, \
    { 0x8d, 0x9c, 0xbd, 0x85, 0xd2, 0x9a, 0x1b, 0x3f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsPISocketTransportService : public nsISocketTransportService {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PISOCKETTRANSPORTSERVICE_IID)

  /* void init (); */
  NS_SCRIPTABLE NS_IMETHOD Init(void) = 0;

  /* void shutdown (); */
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) = 0;

  /* attribute boolean autodialEnabled; */
  NS_SCRIPTABLE NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled) = 0;

  /* readonly attribute long sendBufferSize; */
  NS_SCRIPTABLE NS_IMETHOD GetSendBufferSize(PRInt32 *aSendBufferSize) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPISocketTransportService, NS_PISOCKETTRANSPORTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPISOCKETTRANSPORTSERVICE \
  NS_SCRIPTABLE NS_IMETHOD Init(void); \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled); \
  NS_SCRIPTABLE NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled); \
  NS_SCRIPTABLE NS_IMETHOD GetSendBufferSize(PRInt32 *aSendBufferSize); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPISOCKETTRANSPORTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return _to Init(); } \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return _to Shutdown(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled) { return _to GetAutodialEnabled(aAutodialEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled) { return _to SetAutodialEnabled(aAutodialEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetSendBufferSize(PRInt32 *aSendBufferSize) { return _to GetSendBufferSize(aSendBufferSize); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPISOCKETTRANSPORTSERVICE(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(); } \
  NS_SCRIPTABLE NS_IMETHOD Shutdown(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Shutdown(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutodialEnabled(bool *aAutodialEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutodialEnabled(aAutodialEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutodialEnabled(bool aAutodialEnabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutodialEnabled(aAutodialEnabled); } \
  NS_SCRIPTABLE NS_IMETHOD GetSendBufferSize(PRInt32 *aSendBufferSize) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSendBufferSize(aSendBufferSize); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPISocketTransportService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPISOCKETTRANSPORTSERVICE

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPISocketTransportService)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void init (); */
NS_IMETHODIMP _MYCLASS_::Init()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void shutdown (); */
NS_IMETHODIMP _MYCLASS_::Shutdown()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autodialEnabled; */
NS_IMETHODIMP _MYCLASS_::GetAutodialEnabled(bool *aAutodialEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP _MYCLASS_::SetAutodialEnabled(bool aAutodialEnabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long sendBufferSize; */
NS_IMETHODIMP _MYCLASS_::GetSendBufferSize(PRInt32 *aSendBufferSize)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPISocketTransportService_h__ */
