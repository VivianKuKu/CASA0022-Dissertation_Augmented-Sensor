#pragma once

#import <UIKit/UIKit.h>
#import "PluginBase/UnityViewControllerListener.h"

#if PLATFORM_IOS
    #define UNITY_VIEW_CONTROLLER_BASE_CLASS UIViewController
#elif PLATFORM_TVOS
    #import <GameController/GCController.h>
    #define UNITY_VIEW_CONTROLLER_BASE_CLASS GCEventViewController
#endif

@interface UnityViewControllerBase : UNITY_VIEW_CONTROLLER_BASE_CLASS
{
    id<UnityViewControllerNotifications> _notificationDelegate;

#if UNITY_SUPPORT_ROTATION
    @private ScreenOrientation _currentOrientation;
#endif
}
- (void)viewWillLayoutSubviews;
- (void)viewDidLayoutSubviews;
- (void)viewDidDisappear:(BOOL)animated;
- (void)viewWillDisappear:(BOOL)animated;
- (void)viewDidAppear:(BOOL)animated;
- (void)viewWillAppear:(BOOL)animated;

@property (nonatomic, retain) id<UnityViewControllerNotifications> notificationDelegate;

@end

#if PLATFORM_IOS
#include "UnityViewControllerBase+iOS.h"
#elif PLATFORM_TVOS
#include "UnityViewControllerBase+tvOS.h"
#endif

// this should be used to create view controller that plays nicely with unity and account for player settings
UnityViewControllerBase* AllocUnityViewController(void);

UnityViewControllerBase* AllocUnityDefaultViewController(void);
#if UNITY_SUPPORT_ROTATION
UnityViewControllerBase* AllocUnitySingleOrientationViewController(UIInterfaceOrientation orient);
#endif
