/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/interfaces/html/nsIDOMHTMLElement.idl
 */

#ifndef __gen_nsIDOMHTMLElement_h__
#define __gen_nsIDOMHTMLElement_h__


#ifndef __gen_nsIDOMElement_h__
#include "nsIDOMElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMStringMap; /* forward declaration */

class nsIDOMHTMLMenuElement; /* forward declaration */


/* starting interface:    nsIDOMHTMLElement */
#define NS_IDOMHTMLELEMENT_IID_STR "0a21bb68-d8bd-4b2a-a3db-048a02e81c62"

#define NS_IDOMHTMLELEMENT_IID \
  {0x0a21bb68, 0xd8bd, 0x4b2a, \
    { 0xa3, 0xdb, 0x04, 0x8a, 0x02, 0xe8, 0x1c, 0x62 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMHTMLElement : public nsIDOMElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLELEMENT_IID)

  /* attribute DOMString id; */
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetId(const nsAString & aId) = 0;

  /* attribute DOMString title; */
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) = 0;

  /* attribute DOMString lang; */
  NS_SCRIPTABLE NS_IMETHOD GetLang(nsAString & aLang) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetLang(const nsAString & aLang) = 0;

  /* attribute DOMString dir; */
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) = 0;

  /* attribute DOMString className; */
  NS_SCRIPTABLE NS_IMETHOD GetClassName(nsAString & aClassName) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetClassName(const nsAString & aClassName) = 0;

  /* readonly attribute nsIDOMDOMStringMap dataset; */
  NS_SCRIPTABLE NS_IMETHOD GetDataset(nsIDOMDOMStringMap * *aDataset) = 0;

  /* attribute boolean hidden; */
  NS_SCRIPTABLE NS_IMETHOD GetHidden(bool *aHidden) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetHidden(bool aHidden) = 0;

  /* void click (); */
  NS_SCRIPTABLE NS_IMETHOD Click(void) = 0;

  /* attribute long tabIndex; */
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) = 0;

  /* void focus (); */
  NS_SCRIPTABLE NS_IMETHOD Focus(void) = 0;

  /* void blur (); */
  NS_SCRIPTABLE NS_IMETHOD Blur(void) = 0;

  /* attribute DOMString accessKey; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) = 0;

  /* readonly attribute DOMString accessKeyLabel; */
  NS_SCRIPTABLE NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) = 0;

  /* attribute boolean draggable; */
  NS_SCRIPTABLE NS_IMETHOD GetDraggable(bool *aDraggable) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetDraggable(bool aDraggable) = 0;

  /* attribute DOMString contentEditable; */
  NS_SCRIPTABLE NS_IMETHOD GetContentEditable(nsAString & aContentEditable) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) = 0;

  /* readonly attribute boolean isContentEditable; */
  NS_SCRIPTABLE NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) = 0;

  /* readonly attribute nsIDOMHTMLMenuElement contextMenu; */
  NS_SCRIPTABLE NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) = 0;

  /* attribute boolean spellcheck; */
  NS_SCRIPTABLE NS_IMETHOD GetSpellcheck(bool *aSpellcheck) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetSpellcheck(bool aSpellcheck) = 0;

  /* attribute DOMString innerHTML; */
  NS_SCRIPTABLE NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) = 0;

  /* void insertAdjacentHTML (in DOMString position, in DOMString text); */
  NS_SCRIPTABLE NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) = 0;

  /* [optional_argc] void scrollIntoView ([optional] in boolean top); */
  NS_SCRIPTABLE NS_IMETHOD ScrollIntoView(bool top, PRUint8 _argc) = 0;

  /* readonly attribute nsIDOMElement offsetParent; */
  NS_SCRIPTABLE NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) = 0;

  /* readonly attribute long offsetTop; */
  NS_SCRIPTABLE NS_IMETHOD GetOffsetTop(PRInt32 *aOffsetTop) = 0;

  /* readonly attribute long offsetLeft; */
  NS_SCRIPTABLE NS_IMETHOD GetOffsetLeft(PRInt32 *aOffsetLeft) = 0;

  /* readonly attribute long offsetWidth; */
  NS_SCRIPTABLE NS_IMETHOD GetOffsetWidth(PRInt32 *aOffsetWidth) = 0;

  /* readonly attribute long offsetHeight; */
  NS_SCRIPTABLE NS_IMETHOD GetOffsetHeight(PRInt32 *aOffsetHeight) = 0;

  /* void mozRequestFullScreen (); */
  NS_SCRIPTABLE NS_IMETHOD MozRequestFullScreen(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLElement, NS_IDOMHTMLELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLELEMENT \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId); \
  NS_SCRIPTABLE NS_IMETHOD SetId(const nsAString & aId); \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle); \
  NS_SCRIPTABLE NS_IMETHOD GetLang(nsAString & aLang); \
  NS_SCRIPTABLE NS_IMETHOD SetLang(const nsAString & aLang); \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir); \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir); \
  NS_SCRIPTABLE NS_IMETHOD GetClassName(nsAString & aClassName); \
  NS_SCRIPTABLE NS_IMETHOD SetClassName(const nsAString & aClassName); \
  NS_SCRIPTABLE NS_IMETHOD GetDataset(nsIDOMDOMStringMap * *aDataset); \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(bool *aHidden); \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(bool aHidden); \
  NS_SCRIPTABLE NS_IMETHOD Click(void); \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex); \
  NS_SCRIPTABLE NS_IMETHOD Focus(void); \
  NS_SCRIPTABLE NS_IMETHOD Blur(void); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey); \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey); \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel); \
  NS_SCRIPTABLE NS_IMETHOD GetDraggable(bool *aDraggable); \
  NS_SCRIPTABLE NS_IMETHOD SetDraggable(bool aDraggable); \
  NS_SCRIPTABLE NS_IMETHOD GetContentEditable(nsAString & aContentEditable); \
  NS_SCRIPTABLE NS_IMETHOD SetContentEditable(const nsAString & aContentEditable); \
  NS_SCRIPTABLE NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable); \
  NS_SCRIPTABLE NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu); \
  NS_SCRIPTABLE NS_IMETHOD GetSpellcheck(bool *aSpellcheck); \
  NS_SCRIPTABLE NS_IMETHOD SetSpellcheck(bool aSpellcheck); \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML); \
  NS_SCRIPTABLE NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML); \
  NS_SCRIPTABLE NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text); \
  NS_SCRIPTABLE NS_IMETHOD ScrollIntoView(bool top, PRUint8 _argc); \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent); \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetTop(PRInt32 *aOffsetTop); \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetLeft(PRInt32 *aOffsetLeft); \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetWidth(PRInt32 *aOffsetWidth); \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetHeight(PRInt32 *aOffsetHeight); \
  NS_SCRIPTABLE NS_IMETHOD MozRequestFullScreen(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return _to GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD SetId(const nsAString & aId) { return _to SetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return _to GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return _to SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetLang(nsAString & aLang) { return _to GetLang(aLang); } \
  NS_SCRIPTABLE NS_IMETHOD SetLang(const nsAString & aLang) { return _to SetLang(aLang); } \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) { return _to GetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) { return _to SetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassName(nsAString & aClassName) { return _to GetClassName(aClassName); } \
  NS_SCRIPTABLE NS_IMETHOD SetClassName(const nsAString & aClassName) { return _to SetClassName(aClassName); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataset(nsIDOMDOMStringMap * *aDataset) { return _to GetDataset(aDataset); } \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(bool *aHidden) { return _to GetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(bool aHidden) { return _to SetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD Click(void) { return _to Click(); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return _to GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return _to SetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return _to Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return _to Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return _to GetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return _to SetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) { return _to GetAccessKeyLabel(aAccessKeyLabel); } \
  NS_SCRIPTABLE NS_IMETHOD GetDraggable(bool *aDraggable) { return _to GetDraggable(aDraggable); } \
  NS_SCRIPTABLE NS_IMETHOD SetDraggable(bool aDraggable) { return _to SetDraggable(aDraggable); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentEditable(nsAString & aContentEditable) { return _to GetContentEditable(aContentEditable); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) { return _to SetContentEditable(aContentEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) { return _to GetIsContentEditable(aIsContentEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) { return _to GetContextMenu(aContextMenu); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpellcheck(bool *aSpellcheck) { return _to GetSpellcheck(aSpellcheck); } \
  NS_SCRIPTABLE NS_IMETHOD SetSpellcheck(bool aSpellcheck) { return _to SetSpellcheck(aSpellcheck); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) { return _to GetInnerHTML(aInnerHTML); } \
  NS_SCRIPTABLE NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) { return _to SetInnerHTML(aInnerHTML); } \
  NS_SCRIPTABLE NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) { return _to InsertAdjacentHTML(position, text); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollIntoView(bool top, PRUint8 _argc) { return _to ScrollIntoView(top, _argc); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) { return _to GetOffsetParent(aOffsetParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetTop(PRInt32 *aOffsetTop) { return _to GetOffsetTop(aOffsetTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetLeft(PRInt32 *aOffsetLeft) { return _to GetOffsetLeft(aOffsetLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetWidth(PRInt32 *aOffsetWidth) { return _to GetOffsetWidth(aOffsetWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetHeight(PRInt32 *aOffsetHeight) { return _to GetOffsetHeight(aOffsetHeight); } \
  NS_SCRIPTABLE NS_IMETHOD MozRequestFullScreen(void) { return _to MozRequestFullScreen(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLELEMENT(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetId(nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD SetId(const nsAString & aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetId(aId); } \
  NS_SCRIPTABLE NS_IMETHOD GetTitle(nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD SetTitle(const nsAString & aTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTitle(aTitle); } \
  NS_SCRIPTABLE NS_IMETHOD GetLang(nsAString & aLang) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLang(aLang); } \
  NS_SCRIPTABLE NS_IMETHOD SetLang(const nsAString & aLang) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLang(aLang); } \
  NS_SCRIPTABLE NS_IMETHOD GetDir(nsAString & aDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD SetDir(const nsAString & aDir) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDir(aDir); } \
  NS_SCRIPTABLE NS_IMETHOD GetClassName(nsAString & aClassName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClassName(aClassName); } \
  NS_SCRIPTABLE NS_IMETHOD SetClassName(const nsAString & aClassName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetClassName(aClassName); } \
  NS_SCRIPTABLE NS_IMETHOD GetDataset(nsIDOMDOMStringMap * *aDataset) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDataset(aDataset); } \
  NS_SCRIPTABLE NS_IMETHOD GetHidden(bool *aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD SetHidden(bool aHidden) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHidden(aHidden); } \
  NS_SCRIPTABLE NS_IMETHOD Click(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Click(); } \
  NS_SCRIPTABLE NS_IMETHOD GetTabIndex(PRInt32 *aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD SetTabIndex(PRInt32 aTabIndex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTabIndex(aTabIndex); } \
  NS_SCRIPTABLE NS_IMETHOD Focus(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Focus(); } \
  NS_SCRIPTABLE NS_IMETHOD Blur(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Blur(); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKey(nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD SetAccessKey(const nsAString & aAccessKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccessKey(aAccessKey); } \
  NS_SCRIPTABLE NS_IMETHOD GetAccessKeyLabel(nsAString & aAccessKeyLabel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAccessKeyLabel(aAccessKeyLabel); } \
  NS_SCRIPTABLE NS_IMETHOD GetDraggable(bool *aDraggable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDraggable(aDraggable); } \
  NS_SCRIPTABLE NS_IMETHOD SetDraggable(bool aDraggable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDraggable(aDraggable); } \
  NS_SCRIPTABLE NS_IMETHOD GetContentEditable(nsAString & aContentEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContentEditable(aContentEditable); } \
  NS_SCRIPTABLE NS_IMETHOD SetContentEditable(const nsAString & aContentEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetContentEditable(aContentEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetIsContentEditable(bool *aIsContentEditable) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsContentEditable(aIsContentEditable); } \
  NS_SCRIPTABLE NS_IMETHOD GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetContextMenu(aContextMenu); } \
  NS_SCRIPTABLE NS_IMETHOD GetSpellcheck(bool *aSpellcheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSpellcheck(aSpellcheck); } \
  NS_SCRIPTABLE NS_IMETHOD SetSpellcheck(bool aSpellcheck) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSpellcheck(aSpellcheck); } \
  NS_SCRIPTABLE NS_IMETHOD GetInnerHTML(nsAString & aInnerHTML) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetInnerHTML(aInnerHTML); } \
  NS_SCRIPTABLE NS_IMETHOD SetInnerHTML(const nsAString & aInnerHTML) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetInnerHTML(aInnerHTML); } \
  NS_SCRIPTABLE NS_IMETHOD InsertAdjacentHTML(const nsAString & position, const nsAString & text) { return !_to ? NS_ERROR_NULL_POINTER : _to->InsertAdjacentHTML(position, text); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollIntoView(bool top, PRUint8 _argc) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollIntoView(top, _argc); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetParent(nsIDOMElement * *aOffsetParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetParent(aOffsetParent); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetTop(PRInt32 *aOffsetTop) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetTop(aOffsetTop); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetLeft(PRInt32 *aOffsetLeft) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetLeft(aOffsetLeft); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetWidth(PRInt32 *aOffsetWidth) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetWidth(aOffsetWidth); } \
  NS_SCRIPTABLE NS_IMETHOD GetOffsetHeight(PRInt32 *aOffsetHeight) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffsetHeight(aOffsetHeight); } \
  NS_SCRIPTABLE NS_IMETHOD MozRequestFullScreen(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->MozRequestFullScreen(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLElement : public nsIDOMHTMLElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLELEMENT

  nsDOMHTMLElement();

private:
  ~nsDOMHTMLElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLElement, nsIDOMHTMLElement)

nsDOMHTMLElement::nsDOMHTMLElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLElement::~nsDOMHTMLElement()
{
  /* destructor code */
}

/* attribute DOMString id; */
NS_IMETHODIMP nsDOMHTMLElement::GetId(nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetId(const nsAString & aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString title; */
NS_IMETHODIMP nsDOMHTMLElement::GetTitle(nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetTitle(const nsAString & aTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString lang; */
NS_IMETHODIMP nsDOMHTMLElement::GetLang(nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetLang(const nsAString & aLang)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString dir; */
NS_IMETHODIMP nsDOMHTMLElement::GetDir(nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetDir(const nsAString & aDir)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString className; */
NS_IMETHODIMP nsDOMHTMLElement::GetClassName(nsAString & aClassName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetClassName(const nsAString & aClassName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMStringMap dataset; */
NS_IMETHODIMP nsDOMHTMLElement::GetDataset(nsIDOMDOMStringMap * *aDataset)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean hidden; */
NS_IMETHODIMP nsDOMHTMLElement::GetHidden(bool *aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetHidden(bool aHidden)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void click (); */
NS_IMETHODIMP nsDOMHTMLElement::Click()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute long tabIndex; */
NS_IMETHODIMP nsDOMHTMLElement::GetTabIndex(PRInt32 *aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetTabIndex(PRInt32 aTabIndex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void focus (); */
NS_IMETHODIMP nsDOMHTMLElement::Focus()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void blur (); */
NS_IMETHODIMP nsDOMHTMLElement::Blur()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString accessKey; */
NS_IMETHODIMP nsDOMHTMLElement::GetAccessKey(nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetAccessKey(const nsAString & aAccessKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString accessKeyLabel; */
NS_IMETHODIMP nsDOMHTMLElement::GetAccessKeyLabel(nsAString & aAccessKeyLabel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean draggable; */
NS_IMETHODIMP nsDOMHTMLElement::GetDraggable(bool *aDraggable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetDraggable(bool aDraggable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString contentEditable; */
NS_IMETHODIMP nsDOMHTMLElement::GetContentEditable(nsAString & aContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetContentEditable(const nsAString & aContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isContentEditable; */
NS_IMETHODIMP nsDOMHTMLElement::GetIsContentEditable(bool *aIsContentEditable)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMHTMLMenuElement contextMenu; */
NS_IMETHODIMP nsDOMHTMLElement::GetContextMenu(nsIDOMHTMLMenuElement * *aContextMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean spellcheck; */
NS_IMETHODIMP nsDOMHTMLElement::GetSpellcheck(bool *aSpellcheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetSpellcheck(bool aSpellcheck)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString innerHTML; */
NS_IMETHODIMP nsDOMHTMLElement::GetInnerHTML(nsAString & aInnerHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLElement::SetInnerHTML(const nsAString & aInnerHTML)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void insertAdjacentHTML (in DOMString position, in DOMString text); */
NS_IMETHODIMP nsDOMHTMLElement::InsertAdjacentHTML(const nsAString & position, const nsAString & text)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [optional_argc] void scrollIntoView ([optional] in boolean top); */
NS_IMETHODIMP nsDOMHTMLElement::ScrollIntoView(bool top, PRUint8 _argc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMElement offsetParent; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetParent(nsIDOMElement * *aOffsetParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetTop; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetTop(PRInt32 *aOffsetTop)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetLeft; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetLeft(PRInt32 *aOffsetLeft)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetWidth; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetWidth(PRInt32 *aOffsetWidth)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long offsetHeight; */
NS_IMETHODIMP nsDOMHTMLElement::GetOffsetHeight(PRInt32 *aOffsetHeight)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void mozRequestFullScreen (); */
NS_IMETHODIMP nsDOMHTMLElement::MozRequestFullScreen()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLElement_h__ */
