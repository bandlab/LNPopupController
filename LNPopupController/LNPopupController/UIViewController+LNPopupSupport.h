//
//  UIViewController+LNPopupSupport.h
//  LNPopupController
//
//  Created by Leo Natan on 7/24/15.
//  Copyright © 2015 Leo Natan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <LNPopupController/LNPopupContentView.h>
#import <LNPopupController/LNPopupBar.h>
#import <LNPopupController/LNPopupItem.h>

NS_ASSUME_NONNULL_BEGIN

@class LNPopupController;

/**
 * Available interaction styles with the popup bar and popup content view.
 */
typedef NS_ENUM(NSUInteger, LNPopupInteractionStyle) {
	/**
	 * Use the most appropriate interaction style for the current operating system version; uses snap style for iOS 10 and above, otherwise drag.
	 */
	LNPopupInteractionStyleDefault,
	
	/**
	 * Drag interaction style
	 */
	LNPopupInteractionStyleDrag,
	/**
	 * Snap interaction style
	 */
	LNPopupInteractionStyleSnap,
	/**
	 * No interaction
	 */
	LNPopupInteractionStyleNone = 0xFFFF
};

/**
 *  The state of the popup presentation.
 */
typedef NS_ENUM(NSUInteger, LNPopupPresentationState){
	/**
	 *  The popup bar is hidden and no presentation is taking place.
	 */
	LNPopupPresentationStateHidden,
	/**
	 *  The popup bar is presented and is closed and no presentation is taking place.
	 */
	LNPopupPresentationStateClosed,
	/**
	 *  The popup is transition and presentation is taking place.
	 */
	LNPopupPresentationStateTransitioning,
	/**
	 *  The popup is open and the content controller's view is displayed.
	 */
	LNPopupPresentationStateOpen,
};

/**
 *  Popup presentation support for UIViewController subclasses.
 */
@interface UIViewController (LNPopupContent)

/**
 *  The popup item used to represent the view controller in a popup presentation. (read-only)
 *
 *  This is a unique instance of LNPopupItem created to represent the view controller when it presented in a popup. The first time the property is accessed, the LNPopupItem object is created. Therefore, you should not access this property if you are not using popup presentation to display the view controller. To ensure the popup item is configured, you can either override this property and add code to create the bar button items when first accessed or create the items in your view controller's initialization code.
 *  The default behavior is to create a popup item that displays the view controller's title.
 */
@property (nonatomic, retain, readonly) LNPopupItem* popupItem;

/**
 *  Return the view to which the popup interaction gesture recognizer will be added to.
 *
 *  The default implementation returns the controller's view. @see UIViewController.popupContentView
 *
 *  @return The view to which the popup interaction gesture recognizer will be added to.
 */
@property (nonatomic, strong, readonly) __kindof UIView* viewForPopupInteractionGestureRecognizer;

@end

@interface UIViewController (LNPopupPresentation)

/**
 *  Presents an interactive popup bar in the receiver's view hierarchy. The popup bar is attached to the receiver's docking view. @see -[UIViewController bottomDockingViewForPopupBar]
 *
 *  You may call this method multiple times with different controllers, triggering replacement to the popup content view and update to the popup bar, if popup is open or bar presented, respectively.
 *
 *  The provided controller is retained by the system and will be released once a different controller is presented or when the popup bar is dismissed.
 *
 *  @param controller      The controller for popup presentation.
 *  @param animated        Pass YES to animate the presentation; otherwise, pass NO.
 *  @param completion      The block to execute after the presentation finishes. This block has no return value and takes no parameters. You may specify nil for this parameter.
 */
- (void)presentPopupBarWithContentViewController:(UIViewController*)controller animated:(BOOL)animated completion:(nullable void(^)(void))completion;

/**
 *  Presents an interactive popup bar in the receiver's view hierarchy and optionally opens the popup in the same animation. The popup bar is attached to the receiver's docking view. @see -[UIViewController bottomDockingViewForPopupBar]
 *
 *  You may call this method multiple times with different controllers, triggering replacement to the popup content view and update to the popup bar, if popup is open or bar presented, respectively.
 *
 *  The provided controller is retained by the system and will be released once a different controller is presented or when the popup bar is dismissed.
 *
 *  @param controller      The controller for popup presentation.
 *  @param openPopup	   Pass YES to open the popup in the same animation
 *  @param animated        Pass YES to animate the presentation; otherwise, pass NO.
 *  @param completion      The block to execute after the presentation finishes. This block has no return value and takes no parameters. You may specify nil for this parameter.
 */
- (void)presentPopupBarWithContentViewController:(UIViewController*)controller openPopup:(BOOL)openPopup animated:(BOOL)animated completion:(nullable void(^)(void))completion;

/**
 *  Opens the popup, displaying the content view controller's view.
 *
 *  @param animated        Pass YES to animate; otherwise, pass NO.
 *  @param completion      The block to execute after the popup is opened. This block has no return value and takes no parameters. You may specify nil for this parameter.
 */
- (void)openPopupAnimated:(BOOL)animated completion:(nullable void(^)(void))completion;

/**
 *  Closes the popup, hiding the content view controller's view.
 *
 *  @param animated        Pass YES to animate; otherwise, pass NO.
 *  @param completion      The block to execute after the popup is closed. This block has no return value and takes no parameters. You may specify nil for this parameter.
 */
- (void)closePopupAnimated:(BOOL)animated completion:(nullable void(^)(void))completion;

/**
 *  Dismisses the popup presentation, closing the popup if open and dismissing the popup bar.
 *
 *  @param animated        Pass YES to animate; otherwise, pass NO.
 *  @param completion      The block to execute after the dismissal. This block has no return value and takes no parameters. You may specify nil for this parameter.
 */
- (void)dismissPopupBarAnimated:(BOOL)animated completion:(nullable void(^)(void))completion;

/**
 *  The popup bar interaction style.
 */
@property (nonatomic, assign) LNPopupInteractionStyle popupInteractionStyle;

/**
 *  The popup bar managed by the system. (read-only)
 */
@property (nonatomic, strong, readonly) LNPopupBar* popupBar;
@property (nonatomic, strong, readonly, nullable) LNPopupBar* popupBarIfLoaded;

/**
 *  Call this method to update the popup bar appearance (style, tint color, etc.) according to its docking view. You should call this after updating the docking view.
 *  If the popup bar's inheritsVisualStyleFromDockingView property is set to NO, this method has no effect. @see LNPopupBar.inheritsVisualStyleFromDockingView
 */
- (void)updatePopupBarAppearance;

/**
 *  The popup content container view. (read-only)
 */
@property (nonatomic, strong, readonly) LNPopupContentView* popupContentView;

/**
 *  The state of the popup presentation. (read-only)
 */
@property (nonatomic, readonly) LNPopupPresentationState popupPresentationState;

- (nullable LNPopupController *)_ln_popupController_nocreate;

/**
 *  The content view controller of the receiver. If there is no popover presentation, the property will be nil. (read-only)
 */
@property (nullable, nonatomic, strong, readonly) __kindof UIViewController* popupContentViewController;

/**
 *  The popup presentation container view controller of the receiver. If the receiver is not part of a popover presentation, the property will be nil. (read-only)
 */
@property (nullable, nonatomic, weak, readonly) __kindof UIViewController* popupPresentationContainerViewController;

@end

/**
 *  Popup presentation containment support in custom container view controller subclasses.
 */
@interface UIViewController (LNPopupCustomContainer)

/**
 *  Return a view to dock the popup bar to, or nil to use the system-provided view.
 *
 *  A default implementation is provided for UIViewController, UINavigationController and UITabBarController.
 *  The default implmentation for UIViewController returns an invisible UIView docked to the bottom, for UINavigationController returns the toolbar and for UITabBarController returns the tab bar.
 */
@property (nullable, nonatomic, strong, readonly) __kindof UIView* bottomDockingViewForPopupBar;

/**
 *  Return the default frame for the docking view, when the popup is in hidden or closed state. If bottomDockingViewForPopupBar returns nil, this method is not called, and the default system-provided frame is used.
 *
 *  A default implementation is provided for UIViewController, UINavigationController and UITabBarController.
 */
@property (nonatomic, readonly) CGRect defaultFrameForBottomDockingView;

- (void)updatePopupFrames;

@end

@interface UIViewController (Deprecations)

@property (nullable, nonatomic, strong, readonly) __kindof UIView* bottomDockingViewForPopup NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
