/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGCircleElement.idl
 */

#ifndef __gen_nsIDOMSVGCircleElement_h__
#define __gen_nsIDOMSVGCircleElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGCircleElement */
#define NS_IDOMSVGCIRCLEELEMENT_IID_STR "5d80ae99-417a-4454-96bd-3a9a2b03eee9"

#define NS_IDOMSVGCIRCLEELEMENT_IID \
  {0x5d80ae99, 0x417a, 0x4454, \
    { 0x96, 0xbd, 0x3a, 0x9a, 0x2b, 0x03, 0xee, 0xe9 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGCircleElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGCIRCLEELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength cx; */
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength cy; */
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength r; */
  NS_SCRIPTABLE NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGCircleElement, NS_IDOMSVGCIRCLEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGCIRCLEELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx); \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy); \
  NS_SCRIPTABLE NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGCIRCLEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) { return _to GetCx(aCx); } \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) { return _to GetCy(aCy); } \
  NS_SCRIPTABLE NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) { return _to GetR(aR); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGCIRCLEELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCx(aCx); } \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCy(aCy); } \
  NS_SCRIPTABLE NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetR(aR); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGCircleElement : public nsIDOMSVGCircleElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGCIRCLEELEMENT

  nsDOMSVGCircleElement();

private:
  ~nsDOMSVGCircleElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGCircleElement, nsIDOMSVGCircleElement)

nsDOMSVGCircleElement::nsDOMSVGCircleElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGCircleElement::~nsDOMSVGCircleElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength cx; */
NS_IMETHODIMP nsDOMSVGCircleElement::GetCx(nsIDOMSVGAnimatedLength * *aCx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength cy; */
NS_IMETHODIMP nsDOMSVGCircleElement::GetCy(nsIDOMSVGAnimatedLength * *aCy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength r; */
NS_IMETHODIMP nsDOMSVGCircleElement::GetR(nsIDOMSVGAnimatedLength * *aR)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGCircleElement_h__ */
