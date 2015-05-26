/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/content/base/public/nsISelectionController.idl
 */

#ifndef __gen_nsISelectionController_h__
#define __gen_nsISelectionController_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsISelection_h__
#include "nsISelection.h"
#endif

#ifndef __gen_nsISelectionDisplay_h__
#include "nsISelectionDisplay.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef short SelectionType;
typedef short SelectionRegion;
class nsIDOMNode; /* forward declaration */

class nsISelection; /* forward declaration */

class nsISelectionDisplay; /* forward declaration */


/* starting interface:    nsISelectionController */
#define NS_ISELECTIONCONTROLLER_IID_STR "e0dd9365-470b-4ee8-b644-54add1c4c73f"

#define NS_ISELECTIONCONTROLLER_IID \
  {0xe0dd9365, 0x470b, 0x4ee8, \
    { 0xb6, 0x44, 0x54, 0xad, 0xd1, 0xc4, 0xc7, 0x3f }}

class NS_NO_VTABLE NS_SCRIPTABLE nsISelectionController : public nsISelectionDisplay {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISELECTIONCONTROLLER_IID)

  enum { SELECTION_NONE = 0 };

  enum { SELECTION_NORMAL = 1 };

  enum { SELECTION_SPELLCHECK = 2 };

  enum { SELECTION_IME_RAWINPUT = 4 };

  enum { SELECTION_IME_SELECTEDRAWTEXT = 8 };

  enum { SELECTION_IME_CONVERTEDTEXT = 16 };

  enum { SELECTION_IME_SELECTEDCONVERTEDTEXT = 32 };

  enum { SELECTION_ACCESSIBILITY = 64 };

  enum { SELECTION_FIND = 128 };

  enum { SELECTION_URLSECONDARY = 256 };

  enum { NUM_SELECTIONTYPES = 10 };

  enum { SELECTION_ANCHOR_REGION = 0 };

  enum { SELECTION_FOCUS_REGION = 1 };

  enum { SELECTION_WHOLE_SELECTION = 2 };

  enum { NUM_SELECTION_REGIONS = 3 };

  enum { SELECTION_OFF = 0 };

  enum { SELECTION_HIDDEN = 1 };

  enum { SELECTION_ON = 2 };

  enum { SELECTION_DISABLED = 3 };

  enum { SELECTION_ATTENTION = 4 };

  /* void setDisplaySelection (in short toggle); */
  NS_SCRIPTABLE NS_IMETHOD SetDisplaySelection(PRInt16 toggle) = 0;

  /* short getDisplaySelection (); */
  NS_SCRIPTABLE NS_IMETHOD GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM) = 0;

  /* nsISelection getSelection (in short type); */
  NS_SCRIPTABLE NS_IMETHOD GetSelection(PRInt16 type, nsISelection * *_retval NS_OUTPARAM) = 0;

  enum { SCROLL_SYNCHRONOUS = 2 };

  enum { SCROLL_FIRST_ANCESTOR_ONLY = 4 };

  /* void scrollSelectionIntoView (in short type, in short region, in short flags); */
  NS_SCRIPTABLE NS_IMETHOD ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRInt16 flags) = 0;

  /* void repaintSelection (in short type); */
  NS_SCRIPTABLE NS_IMETHOD RepaintSelection(PRInt16 type) = 0;

  /* void setCaretEnabled (in boolean enabled); */
  NS_SCRIPTABLE NS_IMETHOD SetCaretEnabled(bool enabled) = 0;

  /* void setCaretReadOnly (in boolean readOnly); */
  NS_SCRIPTABLE NS_IMETHOD SetCaretReadOnly(bool readOnly) = 0;

  /* boolean getCaretEnabled (); */
  NS_SCRIPTABLE NS_IMETHOD GetCaretEnabled(bool *_retval NS_OUTPARAM) = 0;

  /* readonly attribute boolean caretVisible; */
  NS_SCRIPTABLE NS_IMETHOD GetCaretVisible(bool *aCaretVisible) = 0;

  /* void setCaretVisibilityDuringSelection (in boolean visibility); */
  NS_SCRIPTABLE NS_IMETHOD SetCaretVisibilityDuringSelection(bool visibility) = 0;

  /* void characterMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD CharacterMove(bool forward, bool extend) = 0;

  /* [noscript] void characterExtendForDelete (); */
  NS_IMETHOD CharacterExtendForDelete(void) = 0;

  /* [noscript] void characterExtendForBackspace (); */
  NS_IMETHOD CharacterExtendForBackspace(void) = 0;

  /* void wordMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD WordMove(bool forward, bool extend) = 0;

  /* [noscript] void wordExtendForDelete (in boolean forward); */
  NS_IMETHOD WordExtendForDelete(bool forward) = 0;

  /* void lineMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD LineMove(bool forward, bool extend) = 0;

  /* void intraLineMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD IntraLineMove(bool forward, bool extend) = 0;

  /* void pageMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD PageMove(bool forward, bool extend) = 0;

  /* void completeScroll (in boolean forward); */
  NS_SCRIPTABLE NS_IMETHOD CompleteScroll(bool forward) = 0;

  /* void completeMove (in boolean forward, in boolean extend); */
  NS_SCRIPTABLE NS_IMETHOD CompleteMove(bool forward, bool extend) = 0;

  /* void scrollPage (in boolean forward); */
  NS_SCRIPTABLE NS_IMETHOD ScrollPage(bool forward) = 0;

  /* void scrollLine (in boolean forward); */
  NS_SCRIPTABLE NS_IMETHOD ScrollLine(bool forward) = 0;

  /* void scrollHorizontal (in boolean left); */
  NS_SCRIPTABLE NS_IMETHOD ScrollHorizontal(bool left) = 0;

  /* void selectAll (); */
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) = 0;

  /* boolean checkVisibility (in nsIDOMNode node, in short startOffset, in short endOffset); */
  NS_SCRIPTABLE NS_IMETHOD CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, bool *_retval NS_OUTPARAM) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISelectionController, NS_ISELECTIONCONTROLLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISELECTIONCONTROLLER \
  NS_SCRIPTABLE NS_IMETHOD SetDisplaySelection(PRInt16 toggle); \
  NS_SCRIPTABLE NS_IMETHOD GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(PRInt16 type, nsISelection * *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRInt16 flags); \
  NS_SCRIPTABLE NS_IMETHOD RepaintSelection(PRInt16 type); \
  NS_SCRIPTABLE NS_IMETHOD SetCaretEnabled(bool enabled); \
  NS_SCRIPTABLE NS_IMETHOD SetCaretReadOnly(bool readOnly); \
  NS_SCRIPTABLE NS_IMETHOD GetCaretEnabled(bool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCaretVisible(bool *aCaretVisible); \
  NS_SCRIPTABLE NS_IMETHOD SetCaretVisibilityDuringSelection(bool visibility); \
  NS_SCRIPTABLE NS_IMETHOD CharacterMove(bool forward, bool extend); \
  NS_IMETHOD CharacterExtendForDelete(void); \
  NS_IMETHOD CharacterExtendForBackspace(void); \
  NS_SCRIPTABLE NS_IMETHOD WordMove(bool forward, bool extend); \
  NS_IMETHOD WordExtendForDelete(bool forward); \
  NS_SCRIPTABLE NS_IMETHOD LineMove(bool forward, bool extend); \
  NS_SCRIPTABLE NS_IMETHOD IntraLineMove(bool forward, bool extend); \
  NS_SCRIPTABLE NS_IMETHOD PageMove(bool forward, bool extend); \
  NS_SCRIPTABLE NS_IMETHOD CompleteScroll(bool forward); \
  NS_SCRIPTABLE NS_IMETHOD CompleteMove(bool forward, bool extend); \
  NS_SCRIPTABLE NS_IMETHOD ScrollPage(bool forward); \
  NS_SCRIPTABLE NS_IMETHOD ScrollLine(bool forward); \
  NS_SCRIPTABLE NS_IMETHOD ScrollHorizontal(bool left); \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void); \
  NS_SCRIPTABLE NS_IMETHOD CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, bool *_retval NS_OUTPARAM); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISELECTIONCONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetDisplaySelection(PRInt16 toggle) { return _to SetDisplaySelection(toggle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM) { return _to GetDisplaySelection(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(PRInt16 type, nsISelection * *_retval NS_OUTPARAM) { return _to GetSelection(type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRInt16 flags) { return _to ScrollSelectionIntoView(type, region, flags); } \
  NS_SCRIPTABLE NS_IMETHOD RepaintSelection(PRInt16 type) { return _to RepaintSelection(type); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretEnabled(bool enabled) { return _to SetCaretEnabled(enabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretReadOnly(bool readOnly) { return _to SetCaretReadOnly(readOnly); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaretEnabled(bool *_retval NS_OUTPARAM) { return _to GetCaretEnabled(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaretVisible(bool *aCaretVisible) { return _to GetCaretVisible(aCaretVisible); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretVisibilityDuringSelection(bool visibility) { return _to SetCaretVisibilityDuringSelection(visibility); } \
  NS_SCRIPTABLE NS_IMETHOD CharacterMove(bool forward, bool extend) { return _to CharacterMove(forward, extend); } \
  NS_IMETHOD CharacterExtendForDelete(void) { return _to CharacterExtendForDelete(); } \
  NS_IMETHOD CharacterExtendForBackspace(void) { return _to CharacterExtendForBackspace(); } \
  NS_SCRIPTABLE NS_IMETHOD WordMove(bool forward, bool extend) { return _to WordMove(forward, extend); } \
  NS_IMETHOD WordExtendForDelete(bool forward) { return _to WordExtendForDelete(forward); } \
  NS_SCRIPTABLE NS_IMETHOD LineMove(bool forward, bool extend) { return _to LineMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD IntraLineMove(bool forward, bool extend) { return _to IntraLineMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD PageMove(bool forward, bool extend) { return _to PageMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteScroll(bool forward) { return _to CompleteScroll(forward); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteMove(bool forward, bool extend) { return _to CompleteMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollPage(bool forward) { return _to ScrollPage(forward); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollLine(bool forward) { return _to ScrollLine(forward); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollHorizontal(bool left) { return _to ScrollHorizontal(left); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return _to SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, bool *_retval NS_OUTPARAM) { return _to CheckVisibility(node, startOffset, endOffset, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISELECTIONCONTROLLER(_to) \
  NS_SCRIPTABLE NS_IMETHOD SetDisplaySelection(PRInt16 toggle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDisplaySelection(toggle); } \
  NS_SCRIPTABLE NS_IMETHOD GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDisplaySelection(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetSelection(PRInt16 type, nsISelection * *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSelection(type, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRInt16 flags) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollSelectionIntoView(type, region, flags); } \
  NS_SCRIPTABLE NS_IMETHOD RepaintSelection(PRInt16 type) { return !_to ? NS_ERROR_NULL_POINTER : _to->RepaintSelection(type); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretEnabled(bool enabled) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretEnabled(enabled); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretReadOnly(bool readOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretReadOnly(readOnly); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaretEnabled(bool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaretEnabled(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCaretVisible(bool *aCaretVisible) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCaretVisible(aCaretVisible); } \
  NS_SCRIPTABLE NS_IMETHOD SetCaretVisibilityDuringSelection(bool visibility) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCaretVisibilityDuringSelection(visibility); } \
  NS_SCRIPTABLE NS_IMETHOD CharacterMove(bool forward, bool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->CharacterMove(forward, extend); } \
  NS_IMETHOD CharacterExtendForDelete(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CharacterExtendForDelete(); } \
  NS_IMETHOD CharacterExtendForBackspace(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CharacterExtendForBackspace(); } \
  NS_SCRIPTABLE NS_IMETHOD WordMove(bool forward, bool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->WordMove(forward, extend); } \
  NS_IMETHOD WordExtendForDelete(bool forward) { return !_to ? NS_ERROR_NULL_POINTER : _to->WordExtendForDelete(forward); } \
  NS_SCRIPTABLE NS_IMETHOD LineMove(bool forward, bool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->LineMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD IntraLineMove(bool forward, bool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->IntraLineMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD PageMove(bool forward, bool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->PageMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteScroll(bool forward) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompleteScroll(forward); } \
  NS_SCRIPTABLE NS_IMETHOD CompleteMove(bool forward, bool extend) { return !_to ? NS_ERROR_NULL_POINTER : _to->CompleteMove(forward, extend); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollPage(bool forward) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollPage(forward); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollLine(bool forward) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollLine(forward); } \
  NS_SCRIPTABLE NS_IMETHOD ScrollHorizontal(bool left) { return !_to ? NS_ERROR_NULL_POINTER : _to->ScrollHorizontal(left); } \
  NS_SCRIPTABLE NS_IMETHOD SelectAll(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SelectAll(); } \
  NS_SCRIPTABLE NS_IMETHOD CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, bool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckVisibility(node, startOffset, endOffset, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSelectionController : public nsISelectionController
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISELECTIONCONTROLLER

  nsSelectionController();

private:
  ~nsSelectionController();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSelectionController, nsISelectionController)

nsSelectionController::nsSelectionController()
{
  /* member initializers and constructor code */
}

nsSelectionController::~nsSelectionController()
{
  /* destructor code */
}

/* void setDisplaySelection (in short toggle); */
NS_IMETHODIMP nsSelectionController::SetDisplaySelection(PRInt16 toggle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short getDisplaySelection (); */
NS_IMETHODIMP nsSelectionController::GetDisplaySelection(PRInt16 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISelection getSelection (in short type); */
NS_IMETHODIMP nsSelectionController::GetSelection(PRInt16 type, nsISelection * *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollSelectionIntoView (in short type, in short region, in short flags); */
NS_IMETHODIMP nsSelectionController::ScrollSelectionIntoView(PRInt16 type, PRInt16 region, PRInt16 flags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void repaintSelection (in short type); */
NS_IMETHODIMP nsSelectionController::RepaintSelection(PRInt16 type)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretEnabled (in boolean enabled); */
NS_IMETHODIMP nsSelectionController::SetCaretEnabled(bool enabled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretReadOnly (in boolean readOnly); */
NS_IMETHODIMP nsSelectionController::SetCaretReadOnly(bool readOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean getCaretEnabled (); */
NS_IMETHODIMP nsSelectionController::GetCaretEnabled(bool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean caretVisible; */
NS_IMETHODIMP nsSelectionController::GetCaretVisible(bool *aCaretVisible)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCaretVisibilityDuringSelection (in boolean visibility); */
NS_IMETHODIMP nsSelectionController::SetCaretVisibilityDuringSelection(bool visibility)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void characterMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::CharacterMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void characterExtendForDelete (); */
NS_IMETHODIMP nsSelectionController::CharacterExtendForDelete()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void characterExtendForBackspace (); */
NS_IMETHODIMP nsSelectionController::CharacterExtendForBackspace()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void wordMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::WordMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void wordExtendForDelete (in boolean forward); */
NS_IMETHODIMP nsSelectionController::WordExtendForDelete(bool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void lineMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::LineMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void intraLineMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::IntraLineMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void pageMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::PageMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completeScroll (in boolean forward); */
NS_IMETHODIMP nsSelectionController::CompleteScroll(bool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void completeMove (in boolean forward, in boolean extend); */
NS_IMETHODIMP nsSelectionController::CompleteMove(bool forward, bool extend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollPage (in boolean forward); */
NS_IMETHODIMP nsSelectionController::ScrollPage(bool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollLine (in boolean forward); */
NS_IMETHODIMP nsSelectionController::ScrollLine(bool forward)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void scrollHorizontal (in boolean left); */
NS_IMETHODIMP nsSelectionController::ScrollHorizontal(bool left)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void selectAll (); */
NS_IMETHODIMP nsSelectionController::SelectAll()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean checkVisibility (in nsIDOMNode node, in short startOffset, in short endOffset); */
NS_IMETHODIMP nsSelectionController::CheckVisibility(nsIDOMNode *node, PRInt16 startOffset, PRInt16 endOffset, bool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

   #define NS_ISELECTIONCONTROLLER_CID \
   { 0x513b9460, 0xd56a, 0x4c4e, \
   { 0xb6, 0xf9, 0x0b, 0x8a, 0xe4, 0x37, 0x2a, 0x3b }}

#endif /* __gen_nsISelectionController_h__ */
