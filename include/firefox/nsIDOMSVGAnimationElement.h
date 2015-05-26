/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGAnimationElement.idl
 */

#ifndef __gen_nsIDOMSVGAnimationElement_h__
#define __gen_nsIDOMSVGAnimationElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimationElement */
#define NS_IDOMSVGANIMATIONELEMENT_IID_STR "91183127-a2a5-43ee-a9ce-737a4d25e65e"

#define NS_IDOMSVGANIMATIONELEMENT_IID \
  {0x91183127, 0xa2a5, 0x43ee, \
    { 0xa9, 0xce, 0x73, 0x7a, 0x4d, 0x25, 0xe6, 0x5e }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimationElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATIONELEMENT_IID)

  /* readonly attribute nsIDOMSVGElement targetElement; */
  NS_SCRIPTABLE NS_IMETHOD GetTargetElement(nsIDOMSVGElement * *aTargetElement) = 0;

  /* float getStartTime (); */
  NS_SCRIPTABLE NS_IMETHOD GetStartTime(float *_retval NS_OUTPARAM) = 0;

  /* float getCurrentTime (); */
  NS_SCRIPTABLE NS_IMETHOD GetCurrentTime(float *_retval NS_OUTPARAM) = 0;

  /* float getSimpleDuration (); */
  NS_SCRIPTABLE NS_IMETHOD GetSimpleDuration(float *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimationElement, NS_IDOMSVGANIMATIONELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATIONELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetTargetElement(nsIDOMSVGElement * *aTargetElement); \
  NS_SCRIPTABLE NS_IMETHOD GetStartTime(float *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentTime(float *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSimpleDuration(float *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATIONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTargetElement(nsIDOMSVGElement * *aTargetElement) { return _to GetTargetElement(aTargetElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartTime(float *_retval NS_OUTPARAM) { return _to GetStartTime(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentTime(float *_retval NS_OUTPARAM) { return _to GetCurrentTime(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSimpleDuration(float *_retval NS_OUTPARAM) { return _to GetSimpleDuration(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATIONELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetTargetElement(nsIDOMSVGElement * *aTargetElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTargetElement(aTargetElement); } \
  NS_SCRIPTABLE NS_IMETHOD GetStartTime(float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartTime(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCurrentTime(float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentTime(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSimpleDuration(float *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSimpleDuration(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimationElement : public nsIDOMSVGAnimationElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATIONELEMENT

  nsDOMSVGAnimationElement();

private:
  ~nsDOMSVGAnimationElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimationElement, nsIDOMSVGAnimationElement)

nsDOMSVGAnimationElement::nsDOMSVGAnimationElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimationElement::~nsDOMSVGAnimationElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGElement targetElement; */
NS_IMETHODIMP nsDOMSVGAnimationElement::GetTargetElement(nsIDOMSVGElement * *aTargetElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getStartTime (); */
NS_IMETHODIMP nsDOMSVGAnimationElement::GetStartTime(float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getCurrentTime (); */
NS_IMETHODIMP nsDOMSVGAnimationElement::GetCurrentTime(float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* float getSimpleDuration (); */
NS_IMETHODIMP nsDOMSVGAnimationElement::GetSimpleDuration(float *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimationElement_h__ */
