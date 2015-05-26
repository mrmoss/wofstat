/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGStopElement.idl
 */

#ifndef __gen_nsIDOMSVGStopElement_h__
#define __gen_nsIDOMSVGStopElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedNumber; /* forward declaration */


/* starting interface:    nsIDOMSVGStopElement */
#define NS_IDOMSVGSTOPELEMENT_IID_STR "b59416e8-62e4-4416-b3e1-b73a1cf0d88a"

#define NS_IDOMSVGSTOPELEMENT_IID \
  {0xb59416e8, 0x62e4, 0x4416, \
    { 0xb3, 0xe1, 0xb7, 0x3a, 0x1c, 0xf0, 0xd8, 0x8a }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGStopElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSTOPELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedNumber offset; */
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGStopElement, NS_IDOMSVGSTOPELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSTOPELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSTOPELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) { return _to GetOffset(aOffset); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSTOPELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetOffset(nsIDOMSVGAnimatedNumber * *aOffset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffset(aOffset); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGStopElement : public nsIDOMSVGStopElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSTOPELEMENT

  nsDOMSVGStopElement();

private:
  ~nsDOMSVGStopElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGStopElement, nsIDOMSVGStopElement)

nsDOMSVGStopElement::nsDOMSVGStopElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGStopElement::~nsDOMSVGStopElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedNumber offset; */
NS_IMETHODIMP nsDOMSVGStopElement::GetOffset(nsIDOMSVGAnimatedNumber * *aOffset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGStopElement_h__ */
