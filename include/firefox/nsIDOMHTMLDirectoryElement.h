/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLDirectoryElement.idl
 */

#ifndef __gen_nsIDOMHTMLDirectoryElement_h__
#define __gen_nsIDOMHTMLDirectoryElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLDirectoryElement */
#define NS_IDOMHTMLDIRECTORYELEMENT_IID_STR "1e04cd43-edc0-4658-bd77-d67661af6c9c"

#define NS_IDOMHTMLDIRECTORYELEMENT_IID \
  {0x1e04cd43, 0xedc0, 0x4658, \
    { 0xbd, 0x77, 0xd6, 0x76, 0x61, 0xaf, 0x6c, 0x9c }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLDirectoryElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLDIRECTORYELEMENT_IID)

  /* attribute boolean compact; */
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLDirectoryElement, NS_IDOMHTMLDIRECTORYELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLDIRECTORYELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact); \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLDIRECTORYELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) { return _to GetCompact(aCompact); } \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) { return _to SetCompact(aCompact); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLDIRECTORYELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetCompact(bool *aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCompact(aCompact); } \
  NS_SCRIPTABLE NS_IMETHOD SetCompact(bool aCompact) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCompact(aCompact); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLDirectoryElement : public nsIDOMHTMLDirectoryElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLDIRECTORYELEMENT

  nsDOMHTMLDirectoryElement();

private:
  ~nsDOMHTMLDirectoryElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLDirectoryElement, nsIDOMHTMLDirectoryElement)

nsDOMHTMLDirectoryElement::nsDOMHTMLDirectoryElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLDirectoryElement::~nsDOMHTMLDirectoryElement()
{
  /* destructor code */
}

/* attribute boolean compact; */
NS_IMETHODIMP nsDOMHTMLDirectoryElement::GetCompact(bool *aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLDirectoryElement::SetCompact(bool aCompact)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLDirectoryElement_h__ */
