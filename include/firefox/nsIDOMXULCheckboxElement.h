/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/xul/nsIDOMXULCheckboxElement.idl
 */

#ifndef __gen_nsIDOMXULCheckboxElement_h__
#define __gen_nsIDOMXULCheckboxElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

#ifndef __gen_nsIDOMXULLabeledControlEl_h__
#include "nsIDOMXULLabeledControlEl.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMXULCheckboxElement */
#define NS_IDOMXULCHECKBOXELEMENT_IID_STR "064aa0c2-3442-489c-a4f5-a42b626dcc53"

#define NS_IDOMXULCHECKBOXELEMENT_IID \
  {0x064aa0c2, 0x3442, 0x489c, \
    { 0xa4, 0xf5, 0xa4, 0x2b, 0x62, 0x6d, 0xcc, 0x53 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMXULCheckboxElement : public nsIDOMXULLabeledControlElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMXULCHECKBOXELEMENT_IID)

  enum { CHECKSTATE_UNCHECKED = 0 };

  enum { CHECKSTATE_CHECKED = 1 };

  enum { CHECKSTATE_MIXED = 2 };

  /* attribute boolean checked; */
  NS_SCRIPTABLE NS_IMETHOD GetChecked(bool *aChecked) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetChecked(bool aChecked) = 0;

  /* attribute long checkState; */
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) = 0;

  /* attribute boolean autoCheck; */
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(bool *aAutoCheck) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(bool aAutoCheck) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMXULCheckboxElement, NS_IDOMXULCHECKBOXELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMXULCHECKBOXELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(bool *aChecked); \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(bool aChecked); \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState); \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState); \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(bool *aAutoCheck); \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(bool aAutoCheck); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMXULCHECKBOXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(bool *aChecked) { return _to GetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(bool aChecked) { return _to SetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) { return _to GetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) { return _to SetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(bool *aAutoCheck) { return _to GetAutoCheck(aAutoCheck); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(bool aAutoCheck) { return _to SetAutoCheck(aAutoCheck); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMXULCHECKBOXELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetChecked(bool *aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD SetChecked(bool aChecked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChecked(aChecked); } \
  NS_SCRIPTABLE NS_IMETHOD GetCheckState(PRInt32 *aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD SetCheckState(PRInt32 aCheckState) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCheckState(aCheckState); } \
  NS_SCRIPTABLE NS_IMETHOD GetAutoCheck(bool *aAutoCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAutoCheck(aAutoCheck); } \
  NS_SCRIPTABLE NS_IMETHOD SetAutoCheck(bool aAutoCheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAutoCheck(aAutoCheck); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMXULCheckboxElement : public nsIDOMXULCheckboxElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMXULCHECKBOXELEMENT

  nsDOMXULCheckboxElement();

private:
  ~nsDOMXULCheckboxElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMXULCheckboxElement, nsIDOMXULCheckboxElement)

nsDOMXULCheckboxElement::nsDOMXULCheckboxElement()
{
  /* member initializers and constructor code */
}

nsDOMXULCheckboxElement::~nsDOMXULCheckboxElement()
{
  /* destructor code */
}

/* attribute boolean checked; */
NS_IMETHODIMP nsDOMXULCheckboxElement::GetChecked(bool *aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetChecked(bool aChecked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long checkState; */
NS_IMETHODIMP nsDOMXULCheckboxElement::GetCheckState(PRInt32 *aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetCheckState(PRInt32 aCheckState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean autoCheck; */
NS_IMETHODIMP nsDOMXULCheckboxElement::GetAutoCheck(bool *aAutoCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMXULCheckboxElement::SetAutoCheck(bool aAutoCheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMXULCheckboxElement_h__ */
