/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/svg/nsIDOMSVGAnimateTransformElement.idl
 */

#ifndef __gen_nsIDOMSVGAnimateTransformElement_h__
#define __gen_nsIDOMSVGAnimateTransformElement_h__


#ifndef __gen_nsIDOMSVGAnimationElement_h__
#include "nsIDOMSVGAnimationElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMSVGAnimateTransformElement */
#define NS_IDOMSVGANIMATETRANSFORMELEMENT_IID_STR "0967287a-97a0-4926-936c-1749f1e67a68"

#define NS_IDOMSVGANIMATETRANSFORMELEMENT_IID \
  {0x0967287a, 0x97a0, 0x4926, \
    { 0x93, 0x6c, 0x17, 0x49, 0xf1, 0xe6, 0x7a, 0x68 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMSVGAnimateTransformElement : public nsIDOMSVGAnimationElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMSVGANIMATETRANSFORMELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMSVGAnimateTransformElement, NS_IDOMSVGANIMATETRANSFORMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMSVGANIMATETRANSFORMELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMSVGANIMATETRANSFORMELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMSVGANIMATETRANSFORMELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMSVGAnimateTransformElement : public nsIDOMSVGAnimateTransformElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMSVGANIMATETRANSFORMELEMENT

  nsDOMSVGAnimateTransformElement();

private:
  ~nsDOMSVGAnimateTransformElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMSVGAnimateTransformElement, nsIDOMSVGAnimateTransformElement)

nsDOMSVGAnimateTransformElement::nsDOMSVGAnimateTransformElement()
{
  /* member initializers and constructor code */
}

nsDOMSVGAnimateTransformElement::~nsDOMSVGAnimateTransformElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSVGAnimateTransformElement_h__ */
