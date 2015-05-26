/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLAudioElement.idl
 */

#ifndef __gen_nsIDOMHTMLAudioElement_h__
#define __gen_nsIDOMHTMLAudioElement_h__


#ifndef __gen_nsIDOMHTMLMediaElement_h__
#include "nsIDOMHTMLMediaElement.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "jsapi.h"

/* starting interface:    nsIDOMHTMLAudioElement */
#define NS_IDOMHTMLAUDIOELEMENT_IID_STR "f4115c13-bc51-4c3b-a5c0-9106af9f7368"

#define NS_IDOMHTMLAUDIOELEMENT_IID \
  {0xf4115c13, 0xbc51, 0x4c3b, \
    { 0xa5, 0xc0, 0x91, 0x06, 0xaf, 0x9f, 0x73, 0x68 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLAudioElement : public nsIDOMHTMLMediaElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLAUDIOELEMENT_IID)

  /* void mozSetup (in PRUint32 channels, in PRUint32 rate); */
  NS_SCRIPTABLE NS_IMETHOD MozSetup(PRUint32 channels, PRUint32 rate) = 0;

  /* [implicit_jscontext] unsigned long mozWriteAudio (in jsval data); */
  NS_SCRIPTABLE NS_IMETHOD MozWriteAudio(const JS::Value & data, JSContext* cx, PRUint32 *_retval NS_OUTPARAM) = 0;

  /* unsigned long long mozCurrentSampleOffset (); */
  NS_SCRIPTABLE NS_IMETHOD MozCurrentSampleOffset(PRUint64 *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLAudioElement, NS_IDOMHTMLAUDIOELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLAUDIOELEMENT \
  NS_SCRIPTABLE NS_IMETHOD MozSetup(PRUint32 channels, PRUint32 rate); \
  NS_SCRIPTABLE NS_IMETHOD MozWriteAudio(const JS::Value & data, JSContext* cx, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD MozCurrentSampleOffset(PRUint64 *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLAUDIOELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD MozSetup(PRUint32 channels, PRUint32 rate) { return _to MozSetup(channels, rate); } \
  NS_SCRIPTABLE NS_IMETHOD MozWriteAudio(const JS::Value & data, JSContext* cx, PRUint32 *_retval NS_OUTPARAM) { return _to MozWriteAudio(data, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozCurrentSampleOffset(PRUint64 *_retval NS_OUTPARAM) { return _to MozCurrentSampleOffset(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLAUDIOELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD MozSetup(PRUint32 channels, PRUint32 rate) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozSetup(channels, rate); } \
  NS_SCRIPTABLE NS_IMETHOD MozWriteAudio(const JS::Value & data, JSContext* cx, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozWriteAudio(data, cx, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD MozCurrentSampleOffset(PRUint64 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozCurrentSampleOffset(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLAudioElement : public nsIDOMHTMLAudioElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLAUDIOELEMENT

  nsDOMHTMLAudioElement();

private:
  ~nsDOMHTMLAudioElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLAudioElement, nsIDOMHTMLAudioElement)

nsDOMHTMLAudioElement::nsDOMHTMLAudioElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLAudioElement::~nsDOMHTMLAudioElement()
{
  /* destructor code */
}

/* void mozSetup (in PRUint32 channels, in PRUint32 rate); */
NS_IMETHODIMP nsDOMHTMLAudioElement::MozSetup(PRUint32 channels, PRUint32 rate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] unsigned long mozWriteAudio (in jsval data); */
NS_IMETHODIMP nsDOMHTMLAudioElement::MozWriteAudio(const JS::Value & data, JSContext* cx, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long long mozCurrentSampleOffset (); */
NS_IMETHODIMP nsDOMHTMLAudioElement::MozCurrentSampleOffset(PRUint64 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLAudioElement_h__ */
