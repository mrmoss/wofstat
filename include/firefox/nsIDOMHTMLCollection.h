/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLCollection.idl
 */

#ifndef __gen_nsIDOMHTMLCollection_h__
#define __gen_nsIDOMHTMLCollection_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIContent; /* forward declaration */


/* starting interface:    nsIDOMHTMLCollection */
#define NS_IDOMHTMLCOLLECTION_IID_STR "b7ccd7b3-86aa-4322-a50c-b972643bb662"

#define NS_IDOMHTMLCOLLECTION_IID \
  {0xb7ccd7b3, 0x86aa, 0x4322, \
    { 0xa5, 0x0c, 0xb9, 0x72, 0x64, 0x3b, 0xb6, 0x62 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLCollection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLCOLLECTION_IID)

  /* readonly attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;

  /* [forward(getNodeAt),getter] nsIDOMNode item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* [forward(getNamedItem),getter] nsIDOMNode namedItem (in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* [noscript,nostdcall,notxpcom] nsIContent getNodeAt (in unsigned long index); */
  virtual nsIContent * GetNodeAt(PRUint32 index) = 0;

  /* [noscript,nostdcall,notxpcom] nsISupports getNamedItem (in DOMString name, out nsWrapperCachePtr cache); */
  virtual nsISupports * GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLCollection, NS_IDOMHTMLCOLLECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLCOLLECTION \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM); \
  virtual nsIContent * GetNodeAt(PRUint32 index); \
  virtual nsISupports * GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLCOLLECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM) { return _to NamedItem(name, _retval); } \
  virtual nsIContent * GetNodeAt(PRUint32 index) { return _to GetNodeAt(index); } \
  virtual nsISupports * GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM) { return _to GetNamedItem(name, cache); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLCOLLECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(name, _retval); } \
  virtual nsIContent * GetNodeAt(PRUint32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNodeAt(index); } \
  virtual nsISupports * GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamedItem(name, cache); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLCollection : public nsIDOMHTMLCollection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLCOLLECTION

  nsDOMHTMLCollection();

private:
  ~nsDOMHTMLCollection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLCollection, nsIDOMHTMLCollection)

nsDOMHTMLCollection::nsDOMHTMLCollection()
{
  /* member initializers and constructor code */
}

nsDOMHTMLCollection::~nsDOMHTMLCollection()
{
  /* destructor code */
}

/* readonly attribute unsigned long length; */
NS_IMETHODIMP nsDOMHTMLCollection::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [forward(getNodeAt),getter] nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLCollection::Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [forward(getNamedItem),getter] nsIDOMNode namedItem (in DOMString name); */
NS_IMETHODIMP nsDOMHTMLCollection::NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsIContent getNodeAt (in unsigned long index); */
nsIContent * nsDOMHTMLCollection::GetNodeAt(PRUint32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsISupports getNamedItem (in DOMString name, out nsWrapperCachePtr cache); */
nsISupports * nsDOMHTMLCollection::GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLCollection_h__ */
