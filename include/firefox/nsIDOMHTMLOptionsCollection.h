/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLOptionsCollection.idl
 */

#ifndef __gen_nsIDOMHTMLOptionsCollection_h__
#define __gen_nsIDOMHTMLOptionsCollection_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

#ifndef __gen_nsIDOMHTMLCollection_h__
#include "nsIDOMHTMLCollection.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMHTMLOptionElement; /* forward declaration */

class nsIDOMHTMLSelectElement; /* forward declaration */


/* starting interface:    nsIDOMHTMLOptionsCollection */
#define NS_IDOMHTMLOPTIONSCOLLECTION_IID_STR "429b041b-06df-486c-9a3a-a1d901cc76a2"

#define NS_IDOMHTMLOPTIONSCOLLECTION_IID \
  {0x429b041b, 0x06df, 0x486c, \
    { 0x9a, 0x3a, 0xa1, 0xd9, 0x01, 0xcc, 0x76, 0xa2 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLOptionsCollection : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLOPTIONSCOLLECTION_IID)

  /* attribute unsigned long length; */
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLength(PRUint32 aLength) = 0;

  /* nsIDOMNode item (in unsigned long index); */
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* [forward(getNamedItem),getter] nsIDOMNode namedItem (in DOMString name); */
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM) = 0;

  /* [noscript,nostdcall,notxpcom] nsISupports getNamedItem (in DOMString name, out nsWrapperCachePtr cache); */
  virtual nsISupports * GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM) = 0;

  /* attribute long selectedIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) = 0;

  /* [noscript,setter] void setOption (in unsigned long index, in nsIDOMHTMLOptionElement option); */
  NS_IMETHOD SetOption(PRUint32 index, nsIDOMHTMLOptionElement *option) = 0;

  /* [noscript] readonly attribute nsIDOMHTMLSelectElement select; */
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) = 0;

  /* void add (in nsIDOMHTMLOptionElement option, [optional] in nsIVariant before); */
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMHTMLOptionElement *option, nsIVariant *before) = 0;

  /* void remove (in long index); */
  NS_SCRIPTABLE NS_IMETHOD Remove(PRInt32 index) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLOptionsCollection, NS_IDOMHTMLOPTIONSCOLLECTION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLOPTIONSCOLLECTION \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength); \
  NS_SCRIPTABLE NS_IMETHOD SetLength(PRUint32 aLength); \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM); \
  virtual nsISupports * GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex); \
  NS_IMETHOD SetOption(PRUint32 index, nsIDOMHTMLOptionElement *option); \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect); \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMHTMLOptionElement *option, nsIVariant *before); \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRInt32 index); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLOPTIONSCOLLECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return _to GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetLength(PRUint32 aLength) { return _to SetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) { return _to Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM) { return _to NamedItem(name, _retval); } \
  virtual nsISupports * GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM) { return _to GetNamedItem(name, cache); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) { return _to GetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) { return _to SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetOption(PRUint32 index, nsIDOMHTMLOptionElement *option) { return _to SetOption(index, option); } \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) { return _to GetSelect(aSelect); } \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMHTMLOptionElement *option, nsIVariant *before) { return _to Add(option, before); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRInt32 index) { return _to Remove(index); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLOPTIONSCOLLECTION(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLength(PRUint32 *aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD SetLength(PRUint32 aLength) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLength(aLength); } \
  NS_SCRIPTABLE NS_IMETHOD Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->Item(index, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->NamedItem(name, _retval); } \
  virtual nsISupports * GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNamedItem(name, cache); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelectedIndex(PRInt32 *aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelectedIndex(aSelectedIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetSelectedIndex(PRInt32 aSelectedIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSelectedIndex(aSelectedIndex); } \
  NS_IMETHOD SetOption(PRUint32 index, nsIDOMHTMLOptionElement *option) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOption(index, option); } \
  NS_IMETHOD GetSelect(nsIDOMHTMLSelectElement * *aSelect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelect(aSelect); } \
  NS_SCRIPTABLE NS_IMETHOD Add(nsIDOMHTMLOptionElement *option, nsIVariant *before) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(option, before); } \
  NS_SCRIPTABLE NS_IMETHOD Remove(PRInt32 index) { return !_to ? NS_ERROR_NULL_POINTER : _to->Remove(index); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLOptionsCollection : public nsIDOMHTMLOptionsCollection
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLOPTIONSCOLLECTION

  nsDOMHTMLOptionsCollection();

private:
  ~nsDOMHTMLOptionsCollection();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLOptionsCollection, nsIDOMHTMLOptionsCollection)

nsDOMHTMLOptionsCollection::nsDOMHTMLOptionsCollection()
{
  /* member initializers and constructor code */
}

nsDOMHTMLOptionsCollection::~nsDOMHTMLOptionsCollection()
{
  /* destructor code */
}

/* attribute unsigned long length; */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::GetLength(PRUint32 *aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOptionsCollection::SetLength(PRUint32 aLength)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMNode item (in unsigned long index); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::Item(PRUint32 index, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [forward(getNamedItem),getter] nsIDOMNode namedItem (in DOMString name); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::NamedItem(const nsAString & name, nsIDOMNode * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,nostdcall,notxpcom] nsISupports getNamedItem (in DOMString name, out nsWrapperCachePtr cache); */
nsISupports * nsDOMHTMLOptionsCollection::GetNamedItem(const nsAString & name, nsWrapperCache **cache NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long selectedIndex; */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::GetSelectedIndex(PRInt32 *aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLOptionsCollection::SetSelectedIndex(PRInt32 aSelectedIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,setter] void setOption (in unsigned long index, in nsIDOMHTMLOptionElement option); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::SetOption(PRUint32 index, nsIDOMHTMLOptionElement *option)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute nsIDOMHTMLSelectElement select; */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::GetSelect(nsIDOMHTMLSelectElement * *aSelect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void add (in nsIDOMHTMLOptionElement option, [optional] in nsIVariant before); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::Add(nsIDOMHTMLOptionElement *option, nsIVariant *before)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void remove (in long index); */
NS_IMETHODIMP nsDOMHTMLOptionsCollection::Remove(PRInt32 index)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLOptionsCollection_h__ */
