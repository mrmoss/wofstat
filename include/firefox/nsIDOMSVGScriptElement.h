/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGScriptElement.idl
 */

#ifndef __gen_nsIDOMSVGScriptElement_h__
#define __gen_nsIDOMSVGScriptElement_h__


#ifndef __gen_nsIDOMSVGElement_h__
#include "nsIDOMSVGElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGScriptElement */
#define NS_IDOMSVGSCRIPTELEMENT_IID_STR "e73416d1-e9db-4a8f-b6f4-b2ddbe4aa90c"

#define NS_IDOMSVGSCRIPTELEMENT_IID \
  {0xe73416d1, 0xe9db, 0x4a8f, \
    { 0xb6, 0xf4, 0xb2, 0xdd, 0xbe, 0x4a, 0xa9, 0x0c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGScriptElement : public nsIDOMSVGElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGSCRIPTELEMENT_IID)

  /* attribute DOMString type; */
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGScriptElement, NS_IDOMSVGSCRIPTELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGSCRIPTELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType); \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGSCRIPTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGSCRIPTELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_SCRIPTABLE NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGScriptElement : public nsIDOMSVGScriptElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGSCRIPTELEMENT

  nsDOMSVGScriptElement();

private:
  ~nsDOMSVGScriptElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGScriptElement, nsIDOMSVGScriptElement)

nsDOMSVGScriptElement::nsDOMSVGScriptElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGScriptElement::~nsDOMSVGScriptElement()
{
  /* destructor code */
}

/* attribute DOMString type; */
NS_IMETHODIMP nsDOMSVGScriptElement::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMSVGScriptElement::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGScriptElement_h__ */
