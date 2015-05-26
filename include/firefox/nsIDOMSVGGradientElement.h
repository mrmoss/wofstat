/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGGradientElement.idl
 */

#ifndef __gen_nsIDOMSVGGradientElement_h__
#define __gen_nsIDOMSVGGradientElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMSVGAnimatedEnumeration; /* forward declaration */

class nsIDOMSVGAnimatedTransformList; /* forward declaration */


/* starting interface:    nsIDOMSVGGradientElement */
#define NS_IDOMSVGGRADIENTELEMENT_IID_STR "6e7f3ee0-91c7-433e-b025-0050442b5dbb"

#define NS_IDOMSVGGRADIENTELEMENT_IID \
  {0x6e7f3ee0, 0x91c7, 0x433e, \
    { 0xb0, 0x25, 0x00, 0x50, 0x44, 0x2b, 0x5d, 0xbb }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGGradientElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGGRADIENTELEMENT_IID)

  enum { SVG_SPREADMETHOD_UNKNOWN = 0U };

  enum { SVG_SPREADMETHOD_PAD = 1U };

  enum { SVG_SPREADMETHOD_REFLECT = 2U };

  enum { SVG_SPREADMETHOD_REPEAT = 3U };

  /* readonly attribute nsIDOMSVGAnimatedEnumeration gradientUnits; */
  NS_SCRIPTABLE NS_IMETHOD GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits) = 0;

  /* readonly attribute nsIDOMSVGAnimatedTransformList gradientTransform; */
  NS_SCRIPTABLE NS_IMETHOD GetGradientTransform(nsIDOMSVGAnimatedTransformList * *aGradientTransform) = 0;

  /* readonly attribute nsIDOMSVGAnimatedEnumeration spreadMethod; */
  NS_SCRIPTABLE NS_IMETHOD GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGGradientElement, NS_IDOMSVGGRADIENTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGGRADIENTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits); \
  NS_SCRIPTABLE NS_IMETHOD GetGradientTransform(nsIDOMSVGAnimatedTransformList * *aGradientTransform); \
  NS_SCRIPTABLE NS_IMETHOD GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGGRADIENTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits) { return _to GetGradientUnits(aGradientUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetGradientTransform(nsIDOMSVGAnimatedTransformList * *aGradientTransform) { return _to GetGradientTransform(aGradientTransform); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod) { return _to GetSpreadMethod(aSpreadMethod); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGGRADIENTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGradientUnits(aGradientUnits); } \
  NS_SCRIPTABLE NS_IMETHOD GetGradientTransform(nsIDOMSVGAnimatedTransformList * *aGradientTransform) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGradientTransform(aGradientTransform); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpreadMethod(aSpreadMethod); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGGradientElement : public nsIDOMSVGGradientElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGGRADIENTELEMENT

  nsDOMSVGGradientElement();

private:
  ~nsDOMSVGGradientElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGGradientElement, nsIDOMSVGGradientElement)

nsDOMSVGGradientElement::nsDOMSVGGradientElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGGradientElement::~nsDOMSVGGradientElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration gradientUnits; */
NS_IMETHODIMP nsDOMSVGGradientElement::GetGradientUnits(nsIDOMSVGAnimatedEnumeration * *aGradientUnits)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedTransformList gradientTransform; */
NS_IMETHODIMP nsDOMSVGGradientElement::GetGradientTransform(nsIDOMSVGAnimatedTransformList * *aGradientTransform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedEnumeration spreadMethod; */
NS_IMETHODIMP nsDOMSVGGradientElement::GetSpreadMethod(nsIDOMSVGAnimatedEnumeration * *aSpreadMethod)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGLinearGradientElement */
#define NS_IDOMSVGLINEARGRADIENTELEMENT_IID_STR "b6ffa3ea-a39f-4ebb-86df-f7d3b889dff7"

#define NS_IDOMSVGLINEARGRADIENTELEMENT_IID \
  {0xb6ffa3ea, 0xa39f, 0x4ebb, \
    { 0x86, 0xdf, 0xf7, 0xd3, 0xb8, 0x89, 0xdf, 0xf7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGLinearGradientElement : public nsIDOMSVGGradientElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGLINEARGRADIENTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength x1; */
  NS_SCRIPTABLE NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y1; */
  NS_SCRIPTABLE NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength x2; */
  NS_SCRIPTABLE NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength y2; */
  NS_SCRIPTABLE NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGLinearGradientElement, NS_IDOMSVGLINEARGRADIENTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGLINEARGRADIENTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1); \
  NS_SCRIPTABLE NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1); \
  NS_SCRIPTABLE NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2); \
  NS_SCRIPTABLE NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGLINEARGRADIENTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) { return _to GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) { return _to GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) { return _to GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) { return _to GetY2(aY2); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGLINEARGRADIENTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetX1(nsIDOMSVGAnimatedLength * *aX1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX1(aX1); } \
  NS_SCRIPTABLE NS_IMETHOD GetY1(nsIDOMSVGAnimatedLength * *aY1) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY1(aY1); } \
  NS_SCRIPTABLE NS_IMETHOD GetX2(nsIDOMSVGAnimatedLength * *aX2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetX2(aX2); } \
  NS_SCRIPTABLE NS_IMETHOD GetY2(nsIDOMSVGAnimatedLength * *aY2) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetY2(aY2); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGLinearGradientElement : public nsIDOMSVGLinearGradientElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGLINEARGRADIENTELEMENT

  nsDOMSVGLinearGradientElement();

private:
  ~nsDOMSVGLinearGradientElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGLinearGradientElement, nsIDOMSVGLinearGradientElement)

nsDOMSVGLinearGradientElement::nsDOMSVGLinearGradientElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGLinearGradientElement::~nsDOMSVGLinearGradientElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength x1; */
NS_IMETHODIMP nsDOMSVGLinearGradientElement::GetX1(nsIDOMSVGAnimatedLength * *aX1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y1; */
NS_IMETHODIMP nsDOMSVGLinearGradientElement::GetY1(nsIDOMSVGAnimatedLength * *aY1)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength x2; */
NS_IMETHODIMP nsDOMSVGLinearGradientElement::GetX2(nsIDOMSVGAnimatedLength * *aX2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength y2; */
NS_IMETHODIMP nsDOMSVGLinearGradientElement::GetY2(nsIDOMSVGAnimatedLength * *aY2)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

class nsIDOMSVGAnimatedLength; /* forward declaration */


/* starting interface:    nsIDOMSVGRadialGradientElement */
#define NS_IDOMSVGRADIALGRADIENTELEMENT_IID_STR "67041054-7013-4c56-84db-448edb98936d"

#define NS_IDOMSVGRADIALGRADIENTELEMENT_IID \
  {0x67041054, 0x7013, 0x4c56, \
    { 0x84, 0xdb, 0x44, 0x8e, 0xdb, 0x98, 0x93, 0x6d }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGRadialGradientElement : public nsIDOMSVGGradientElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGRADIALGRADIENTELEMENT_IID)

  /* readonly attribute nsIDOMSVGAnimatedLength cx; */
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength cy; */
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength r; */
  NS_SCRIPTABLE NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength fx; */
  NS_SCRIPTABLE NS_IMETHOD GetFx(nsIDOMSVGAnimatedLength * *aFx) = 0;

  /* readonly attribute nsIDOMSVGAnimatedLength fy; */
  NS_SCRIPTABLE NS_IMETHOD GetFy(nsIDOMSVGAnimatedLength * *aFy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGRadialGradientElement, NS_IDOMSVGRADIALGRADIENTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGRADIALGRADIENTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx); \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy); \
  NS_SCRIPTABLE NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR); \
  NS_SCRIPTABLE NS_IMETHOD GetFx(nsIDOMSVGAnimatedLength * *aFx); \
  NS_SCRIPTABLE NS_IMETHOD GetFy(nsIDOMSVGAnimatedLength * *aFy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGRADIALGRADIENTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) { return _to GetCx(aCx); } \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) { return _to GetCy(aCy); } \
  NS_SCRIPTABLE NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) { return _to GetR(aR); } \
  NS_SCRIPTABLE NS_IMETHOD GetFx(nsIDOMSVGAnimatedLength * *aFx) { return _to GetFx(aFx); } \
  NS_SCRIPTABLE NS_IMETHOD GetFy(nsIDOMSVGAnimatedLength * *aFy) { return _to GetFy(aFy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGRADIALGRADIENTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCx(nsIDOMSVGAnimatedLength * *aCx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCx(aCx); } \
  NS_SCRIPTABLE NS_IMETHOD GetCy(nsIDOMSVGAnimatedLength * *aCy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCy(aCy); } \
  NS_SCRIPTABLE NS_IMETHOD GetR(nsIDOMSVGAnimatedLength * *aR) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetR(aR); } \
  NS_SCRIPTABLE NS_IMETHOD GetFx(nsIDOMSVGAnimatedLength * *aFx) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFx(aFx); } \
  NS_SCRIPTABLE NS_IMETHOD GetFy(nsIDOMSVGAnimatedLength * *aFy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFy(aFy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGRadialGradientElement : public nsIDOMSVGRadialGradientElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGRADIALGRADIENTELEMENT

  nsDOMSVGRadialGradientElement();

private:
  ~nsDOMSVGRadialGradientElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGRadialGradientElement, nsIDOMSVGRadialGradientElement)

nsDOMSVGRadialGradientElement::nsDOMSVGRadialGradientElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGRadialGradientElement::~nsDOMSVGRadialGradientElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMSVGAnimatedLength cx; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetCx(nsIDOMSVGAnimatedLength * *aCx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength cy; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetCy(nsIDOMSVGAnimatedLength * *aCy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength r; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetR(nsIDOMSVGAnimatedLength * *aR)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength fx; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetFx(nsIDOMSVGAnimatedLength * *aFx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMSVGAnimatedLength fy; */
NS_IMETHODIMP nsDOMSVGRadialGradientElement::GetFy(nsIDOMSVGAnimatedLength * *aFy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGGradientElement_h__ */
