/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/xul/nsIDOMXULContainerElement.idl
 */

#ifndef __gen_nsIDOMXULContainerElement_h__
#define __gen_nsIDOMXULContainerElement_h__


#ifndef __gen_nsIDOMXULElement_h__
#include "nsIDOMXULElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMXULContainerElement; /* forward declaration */


/* starting interface:    nsIDOMXULContainerItemElement */
#define NS_IDOMXULCONTAINERITEMELEMENT_IID_STR "b7fdd700-0286-42a9-888f-90b3bd782380"

#define NS_IDOMXULCONTAINERITEMELEMENT_IID \
  {0xb7fdd700, 0x0286, 0x42a9, \
    { 0x88, 0x8f, 0x90, 0xb3, 0xbd, 0x78, 0x23, 0x80 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULContainerItemElement : public nsIDOMXULElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTAINERITEMELEMENT_IID)

  /* readonly attribute nsIDOMXULContainerElement parentContainer; */
  NS_SCRIPTABLE NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULContainerItemElement, NS_IDOMXULCONTAINERITEMELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTAINERITEMELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTAINERITEMELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) { return _to GetParentContainer(aParentContainer); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTAINERITEMELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetParentContainer(nsIDOMXULContainerElement * *aParentContainer) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParentContainer(aParentContainer); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULContainerItemElement : public nsIDOMXULContainerItemElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTAINERITEMELEMENT

  nsDOMXULContainerItemElement();

private:
  ~nsDOMXULContainerItemElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULContainerItemElement, nsIDOMXULContainerItemElement)

nsDOMXULContainerItemElement::nsDOMXULContainerItemElement()
{
  /* member initializers and constructor code */
}

nsDOMXULContainerItemElement::~nsDOMXULContainerItemElement()
{
  /* destructor code */
}

/* readonly attribute nsIDOMXULContainerElement parentContainer; */
NS_IMETHODIMP nsDOMXULContainerItemElement::GetParentContainer(nsIDOMXULContainerElement * *aParentContainer)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIDOMXULContainerElement */
#define NS_IDOMXULCONTAINERELEMENT_IID_STR "dc498531-6a41-4749-a6d4-e4c42ab540d7"

#define NS_IDOMXULCONTAINERELEMENT_IID \
  {0xdc498531, 0x6a41, 0x4749, \
    { 0xa6, 0xd4, 0xe4, 0xc4, 0x2a, 0xb5, 0x40, 0xd7 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULContainerElement : public nsIDOMXULContainerItemElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCONTAINERELEMENT_IID)

  /* nsIDOMXULElement appendItem (in DOMString aLabel, in DOMString aValue); */
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM) = 0;

  /* nsIDOMXULElement insertItemAt (in long aIndex, in DOMString aLabel, in DOMString aValue); */
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM) = 0;

  /* nsIDOMXULElement removeItemAt (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM) = 0;

  /* readonly attribute unsigned long itemCount; */
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) = 0;

  /* long getIndexOfItem (in nsIDOMXULElement aItem); */
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM) = 0;

  /* nsIDOMXULElement getItemAtIndex (in long aIndex); */
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULContainerElement, NS_IDOMXULCONTAINERELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCONTAINERELEMENT \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount); \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCONTAINERELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM) { return _to AppendItem(aLabel, aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM) { return _to InsertItemAt(aIndex, aLabel, aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM) { return _to RemoveItemAt(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) { return _to GetItemCount(aItemCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM) { return _to GetIndexOfItem(aItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM) { return _to GetItemAtIndex(aIndex, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCONTAINERELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->AppendItem(aLabel, aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertItemAt(aIndex, aLabel, aValue, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveItemAt(aIndex, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemCount(PRUint32 *aItemCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemCount(aItemCount); } \
  NS_SCRIPTABLE NS_IMETHOD GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIndexOfItem(aItem, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetItemAtIndex(aIndex, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULContainerElement : public nsIDOMXULContainerElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCONTAINERELEMENT

  nsDOMXULContainerElement();

private:
  ~nsDOMXULContainerElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULContainerElement, nsIDOMXULContainerElement)

nsDOMXULContainerElement::nsDOMXULContainerElement()
{
  /* member initializers and constructor code */
}

nsDOMXULContainerElement::~nsDOMXULContainerElement()
{
  /* destructor code */
}

/* nsIDOMXULElement appendItem (in DOMString aLabel, in DOMString aValue); */
NS_IMETHODIMP nsDOMXULContainerElement::AppendItem(const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement insertItemAt (in long aIndex, in DOMString aLabel, in DOMString aValue); */
NS_IMETHODIMP nsDOMXULContainerElement::InsertItemAt(PRInt32 aIndex, const nsAString & aLabel, const nsAString & aValue, nsIDOMXULElement * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement removeItemAt (in long aIndex); */
NS_IMETHODIMP nsDOMXULContainerElement::RemoveItemAt(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long itemCount; */
NS_IMETHODIMP nsDOMXULContainerElement::GetItemCount(PRUint32 *aItemCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* long getIndexOfItem (in nsIDOMXULElement aItem); */
NS_IMETHODIMP nsDOMXULContainerElement::GetIndexOfItem(nsIDOMXULElement *aItem, PRInt32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMXULElement getItemAtIndex (in long aIndex); */
NS_IMETHODIMP nsDOMXULContainerElement::GetItemAtIndex(PRInt32 aIndex, nsIDOMXULElement * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULContainerElement_h__ */
