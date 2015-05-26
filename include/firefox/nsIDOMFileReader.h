/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/content/base/public/nsIDOMFileReader.idl
 */

#ifndef __gen_nsIDOMFileReader_h__
#define __gen_nsIDOMFileReader_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIDOMBlob; /* forward declaration */

class nsIDOMFileError; /* forward declaration */


/* starting interface:    nsIDOMFileReader */
#define NS_IDOMFILEREADER_IID_STR "fc316500-87c4-411e-ab75-dd62468f4174"

#define NS_IDOMFILEREADER_IID \
  {0xfc316500, 0x87c4, 0x411e, \
    { 0xab, 0x75, 0xdd, 0x62, 0x46, 0x8f, 0x41, 0x74 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMFileReader : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMFILEREADER_IID)

  /* [implicit_jscontext] void readAsArrayBuffer (in nsIDOMBlob filedata); */
  NS_SCRIPTABLE NS_IMETHOD ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx) = 0;

  /* void readAsBinaryString (in nsIDOMBlob filedata); */
  NS_SCRIPTABLE NS_IMETHOD ReadAsBinaryString(nsIDOMBlob *filedata) = 0;

  /* void readAsText (in nsIDOMBlob filedata, [optional] in DOMString encoding); */
  NS_SCRIPTABLE NS_IMETHOD ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding) = 0;

  /* void readAsDataURL (in nsIDOMBlob file); */
  NS_SCRIPTABLE NS_IMETHOD ReadAsDataURL(nsIDOMBlob *file) = 0;

  /* void abort (); */
  NS_SCRIPTABLE NS_IMETHOD Abort(void) = 0;

  enum { EMPTY = 0U };

  enum { LOADING = 1U };

  enum { DONE = 2U };

  /* readonly attribute unsigned short readyState; */
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) = 0;

  /* [implicit_jscontext] readonly attribute jsval result; */
  NS_SCRIPTABLE NS_IMETHOD GetResult(JSContext* cx, JS::Value *aResult) = 0;

  /* readonly attribute nsIDOMFileError error; */
  NS_SCRIPTABLE NS_IMETHOD GetError(nsIDOMFileError * *aError) = 0;

  /* attribute nsIDOMEventListener onloadstart; */
  NS_SCRIPTABLE NS_IMETHOD GetOnloadstart(nsIDOMEventListener * *aOnloadstart) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnloadstart(nsIDOMEventListener *aOnloadstart) = 0;

  /* attribute nsIDOMEventListener onprogress; */
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener *aOnprogress) = 0;

  /* attribute nsIDOMEventListener onload; */
  NS_SCRIPTABLE NS_IMETHOD GetOnload(nsIDOMEventListener * *aOnload) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnload(nsIDOMEventListener *aOnload) = 0;

  /* attribute nsIDOMEventListener onabort; */
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener * *aOnabort) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener *aOnabort) = 0;

  /* attribute nsIDOMEventListener onerror; */
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) = 0;

  /* attribute nsIDOMEventListener onloadend; */
  NS_SCRIPTABLE NS_IMETHOD GetOnloadend(nsIDOMEventListener * *aOnloadend) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnloadend(nsIDOMEventListener *aOnloadend) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMFileReader, NS_IDOMFILEREADER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMFILEREADER \
  NS_SCRIPTABLE NS_IMETHOD ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx); \
  NS_SCRIPTABLE NS_IMETHOD ReadAsBinaryString(nsIDOMBlob *filedata); \
  NS_SCRIPTABLE NS_IMETHOD ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding); \
  NS_SCRIPTABLE NS_IMETHOD ReadAsDataURL(nsIDOMBlob *file); \
  NS_SCRIPTABLE NS_IMETHOD Abort(void); \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState); \
  NS_SCRIPTABLE NS_IMETHOD GetResult(JSContext* cx, JS::Value *aResult); \
  NS_SCRIPTABLE NS_IMETHOD GetError(nsIDOMFileError * *aError); \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadstart(nsIDOMEventListener * *aOnloadstart); \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadstart(nsIDOMEventListener *aOnloadstart); \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress); \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener *aOnprogress); \
  NS_SCRIPTABLE NS_IMETHOD GetOnload(nsIDOMEventListener * *aOnload); \
  NS_SCRIPTABLE NS_IMETHOD SetOnload(nsIDOMEventListener *aOnload); \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener * *aOnabort); \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener *aOnabort); \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror); \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadend(nsIDOMEventListener * *aOnloadend); \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadend(nsIDOMEventListener *aOnloadend); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMFILEREADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx) { return _to ReadAsArrayBuffer(filedata, cx); } \
  NS_SCRIPTABLE NS_IMETHOD ReadAsBinaryString(nsIDOMBlob *filedata) { return _to ReadAsBinaryString(filedata); } \
  NS_SCRIPTABLE NS_IMETHOD ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding) { return _to ReadAsText(filedata, encoding); } \
  NS_SCRIPTABLE NS_IMETHOD ReadAsDataURL(nsIDOMBlob *file) { return _to ReadAsDataURL(file); } \
  NS_SCRIPTABLE NS_IMETHOD Abort(void) { return _to Abort(); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(JSContext* cx, JS::Value *aResult) { return _to GetResult(cx, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetError(nsIDOMFileError * *aError) { return _to GetError(aError); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadstart(nsIDOMEventListener * *aOnloadstart) { return _to GetOnloadstart(aOnloadstart); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadstart(nsIDOMEventListener *aOnloadstart) { return _to SetOnloadstart(aOnloadstart); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) { return _to GetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener *aOnprogress) { return _to SetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnload(nsIDOMEventListener * *aOnload) { return _to GetOnload(aOnload); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnload(nsIDOMEventListener *aOnload) { return _to SetOnload(aOnload); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener * *aOnabort) { return _to GetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener *aOnabort) { return _to SetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) { return _to GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return _to SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadend(nsIDOMEventListener * *aOnloadend) { return _to GetOnloadend(aOnloadend); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadend(nsIDOMEventListener *aOnloadend) { return _to SetOnloadend(aOnloadend); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMFILEREADER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsArrayBuffer(filedata, cx); } \
  NS_SCRIPTABLE NS_IMETHOD ReadAsBinaryString(nsIDOMBlob *filedata) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsBinaryString(filedata); } \
  NS_SCRIPTABLE NS_IMETHOD ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsText(filedata, encoding); } \
  NS_SCRIPTABLE NS_IMETHOD ReadAsDataURL(nsIDOMBlob *file) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReadAsDataURL(file); } \
  NS_SCRIPTABLE NS_IMETHOD Abort(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Abort(); } \
  NS_SCRIPTABLE NS_IMETHOD GetReadyState(PRUint16 *aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_SCRIPTABLE NS_IMETHOD GetResult(JSContext* cx, JS::Value *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(cx, aResult); } \
  NS_SCRIPTABLE NS_IMETHOD GetError(nsIDOMFileError * *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadstart(nsIDOMEventListener * *aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadstart(aOnloadstart); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadstart(nsIDOMEventListener *aOnloadstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadstart(aOnloadstart); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnprogress(nsIDOMEventListener * *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnprogress(nsIDOMEventListener *aOnprogress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnprogress(aOnprogress); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnload(nsIDOMEventListener * *aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnload(aOnload); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnload(nsIDOMEventListener *aOnload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnload(aOnload); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnabort(nsIDOMEventListener * *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnabort(nsIDOMEventListener *aOnabort) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnabort(aOnabort); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnerror(nsIDOMEventListener * *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnerror(nsIDOMEventListener *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(aOnerror); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnloadend(nsIDOMEventListener * *aOnloadend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnloadend(aOnloadend); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnloadend(nsIDOMEventListener *aOnloadend) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnloadend(aOnloadend); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMFileReader : public nsIDOMFileReader
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMFILEREADER

  nsDOMFileReader();

private:
  ~nsDOMFileReader();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMFileReader, nsIDOMFileReader)

nsDOMFileReader::nsDOMFileReader()
{
  /* member initializers and constructor code */
}

nsDOMFileReader::~nsDOMFileReader()
{
  /* destructor code */
}

/* [implicit_jscontext] void readAsArrayBuffer (in nsIDOMBlob filedata); */
NS_IMETHODIMP nsDOMFileReader::ReadAsArrayBuffer(nsIDOMBlob *filedata, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void readAsBinaryString (in nsIDOMBlob filedata); */
NS_IMETHODIMP nsDOMFileReader::ReadAsBinaryString(nsIDOMBlob *filedata)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void readAsText (in nsIDOMBlob filedata, [optional] in DOMString encoding); */
NS_IMETHODIMP nsDOMFileReader::ReadAsText(nsIDOMBlob *filedata, const nsAString & encoding)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void readAsDataURL (in nsIDOMBlob file); */
NS_IMETHODIMP nsDOMFileReader::ReadAsDataURL(nsIDOMBlob *file)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void abort (); */
NS_IMETHODIMP nsDOMFileReader::Abort()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned short readyState; */
NS_IMETHODIMP nsDOMFileReader::GetReadyState(PRUint16 *aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval result; */
NS_IMETHODIMP nsDOMFileReader::GetResult(JSContext* cx, JS::Value *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMFileError error; */
NS_IMETHODIMP nsDOMFileReader::GetError(nsIDOMFileError * *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onloadstart; */
NS_IMETHODIMP nsDOMFileReader::GetOnloadstart(nsIDOMEventListener * *aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnloadstart(nsIDOMEventListener *aOnloadstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onprogress; */
NS_IMETHODIMP nsDOMFileReader::GetOnprogress(nsIDOMEventListener * *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnprogress(nsIDOMEventListener *aOnprogress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onload; */
NS_IMETHODIMP nsDOMFileReader::GetOnload(nsIDOMEventListener * *aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnload(nsIDOMEventListener *aOnload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onabort; */
NS_IMETHODIMP nsDOMFileReader::GetOnabort(nsIDOMEventListener * *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnabort(nsIDOMEventListener *aOnabort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onerror; */
NS_IMETHODIMP nsDOMFileReader::GetOnerror(nsIDOMEventListener * *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnerror(nsIDOMEventListener *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onloadend; */
NS_IMETHODIMP nsDOMFileReader::GetOnloadend(nsIDOMEventListener * *aOnloadend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMFileReader::SetOnloadend(nsIDOMEventListener *aOnloadend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_FILEREADER_CID                            \
{0x06aa7c21, 0xfe05, 0x4cf2,                         \
{0xb1, 0xc4, 0x0c, 0x71, 0x26, 0xa4, 0xf7, 0x13}}
#define NS_FILEREADER_CONTRACTID \
"@mozilla.org/files/filereader;1"

#endif /* __gen_nsIDOMFileReader_h__ */
