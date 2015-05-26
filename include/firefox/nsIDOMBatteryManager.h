/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /jds/packages/BUILD/SUNWfirefox-10.0.2/firefox/dom/battery/nsIDOMBatteryManager.idl
 */

#ifndef __gen_nsIDOMBatteryManager_h__
#define __gen_nsIDOMBatteryManager_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */


/* starting interface:    nsIDOMBatteryManager */
#define NS_IDOMBATTERYMANAGER_IID_STR "6ac8bdb2-f005-469b-a55e-398e23ef3c95"

#define NS_IDOMBATTERYMANAGER_IID \
  {0x6ac8bdb2, 0xf005, 0x469b, \
    { 0xa5, 0x5e, 0x39, 0x8e, 0x23, 0xef, 0x3c, 0x95 }}

class NS_NO_VTABLE NS_SCRIPTABLE nsIDOMBatteryManager : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMBATTERYMANAGER_IID)

  /* readonly attribute float level; */
  NS_SCRIPTABLE NS_IMETHOD GetLevel(float *aLevel) = 0;

  /* readonly attribute boolean charging; */
  NS_SCRIPTABLE NS_IMETHOD GetCharging(bool *aCharging) = 0;

  /* attribute nsIDOMEventListener onlevelchange; */
  NS_SCRIPTABLE NS_IMETHOD GetOnlevelchange(nsIDOMEventListener * *aOnlevelchange) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnlevelchange(nsIDOMEventListener *aOnlevelchange) = 0;

  /* attribute nsIDOMEventListener onchargingchange; */
  NS_SCRIPTABLE NS_IMETHOD GetOnchargingchange(nsIDOMEventListener * *aOnchargingchange) = 0;
  NS_SCRIPTABLE NS_IMETHOD SetOnchargingchange(nsIDOMEventListener *aOnchargingchange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMBatteryManager, NS_IDOMBATTERYMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMBATTERYMANAGER \
  NS_SCRIPTABLE NS_IMETHOD GetLevel(float *aLevel); \
  NS_SCRIPTABLE NS_IMETHOD GetCharging(bool *aCharging); \
  NS_SCRIPTABLE NS_IMETHOD GetOnlevelchange(nsIDOMEventListener * *aOnlevelchange); \
  NS_SCRIPTABLE NS_IMETHOD SetOnlevelchange(nsIDOMEventListener *aOnlevelchange); \
  NS_SCRIPTABLE NS_IMETHOD GetOnchargingchange(nsIDOMEventListener * *aOnchargingchange); \
  NS_SCRIPTABLE NS_IMETHOD SetOnchargingchange(nsIDOMEventListener *aOnchargingchange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMBATTERYMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLevel(float *aLevel) { return _to GetLevel(aLevel); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharging(bool *aCharging) { return _to GetCharging(aCharging); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnlevelchange(nsIDOMEventListener * *aOnlevelchange) { return _to GetOnlevelchange(aOnlevelchange); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnlevelchange(nsIDOMEventListener *aOnlevelchange) { return _to SetOnlevelchange(aOnlevelchange); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnchargingchange(nsIDOMEventListener * *aOnchargingchange) { return _to GetOnchargingchange(aOnchargingchange); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnchargingchange(nsIDOMEventListener *aOnchargingchange) { return _to SetOnchargingchange(aOnchargingchange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMBATTERYMANAGER(_to) \
  NS_SCRIPTABLE NS_IMETHOD GetLevel(float *aLevel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLevel(aLevel); } \
  NS_SCRIPTABLE NS_IMETHOD GetCharging(bool *aCharging) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCharging(aCharging); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnlevelchange(nsIDOMEventListener * *aOnlevelchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnlevelchange(aOnlevelchange); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnlevelchange(nsIDOMEventListener *aOnlevelchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnlevelchange(aOnlevelchange); } \
  NS_SCRIPTABLE NS_IMETHOD GetOnchargingchange(nsIDOMEventListener * *aOnchargingchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnchargingchange(aOnchargingchange); } \
  NS_SCRIPTABLE NS_IMETHOD SetOnchargingchange(nsIDOMEventListener *aOnchargingchange) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnchargingchange(aOnchargingchange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMBatteryManager : public nsIDOMBatteryManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMBATTERYMANAGER

  nsDOMBatteryManager();

private:
  ~nsDOMBatteryManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMBatteryManager, nsIDOMBatteryManager)

nsDOMBatteryManager::nsDOMBatteryManager()
{
  /* member initializers and constructor code */
}

nsDOMBatteryManager::~nsDOMBatteryManager()
{
  /* destructor code */
}

/* readonly attribute float level; */
NS_IMETHODIMP nsDOMBatteryManager::GetLevel(float *aLevel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean charging; */
NS_IMETHODIMP nsDOMBatteryManager::GetCharging(bool *aCharging)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onlevelchange; */
NS_IMETHODIMP nsDOMBatteryManager::GetOnlevelchange(nsIDOMEventListener * *aOnlevelchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMBatteryManager::SetOnlevelchange(nsIDOMEventListener *aOnlevelchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIDOMEventListener onchargingchange; */
NS_IMETHODIMP nsDOMBatteryManager::GetOnchargingchange(nsIDOMEventListener * *aOnchargingchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMBatteryManager::SetOnchargingchange(nsIDOMEventListener *aOnchargingchange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMBatteryManager_h__ */
