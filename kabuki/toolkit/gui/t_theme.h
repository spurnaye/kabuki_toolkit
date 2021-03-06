/*
    The text box widget was contributed by Christian Schueller.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/
/*
 * @file /kabuki_toolkit/gui/theme.h
 *
 * @brief Storage class for basic theme-related properties.
 */

#pragma once
#include <pch.h>


#include "c_common.h"
#include "t_opengl.h"
#include "c_entypo.h"
#include "t_object.h"

namespace _ {

/*
 * \class Theme theme.h /kabuki_toolkit/gui/theme.h
 *
 * @brief Storage class for basic theme-related properties.
 */
class SDK Theme : public Object {
public:
  Theme (NVGcontext *ctx) {
    mStandardFontSize = 16;
    mButtonFontSize = 20;
    mTextBoxFontSize = 20;
    mIconScale = 0.77f;

    mWindowCornerRadius = 2;
    mWindowHeaderHeight = 30;
    mWindowDropShadowSize = 10;
    mButtonCornerRadius = 2;
    mTabBorderWidth = 0.75f;
    mTabInnerMargin = 5;
    mTabMinButtonWidth = 20;
    mTabMaxButtonWidth = 160;
    mTabControlWidth = 20;
    mTabButtonHorizontalPadding = 10;
    mTabButtonVerticalPadding = 2;

    mDropShadow = Color (0, 128);
    mTransparent = Color (0, 0);
    mBorderDark = Color (29, 255);
    mBorderLight = Color (92, 255);
    mBorderMedium = Color (35, 255);
    mTextColor = Color (255, 160);
    mDisabledTextColor = Color (255, 80);
    mTextColorShadow = Color (0, 160);
    mIconColor = mTextColor;

    mButtonGradientTopFocused = Color (64, 255);
    mButtonGradientBotFocused = Color (48, 255);
    mButtonGradientTopUnfocused = Color (74, 255);
    mButtonGradientBotUnfocused = Color (58, 255);
    mButtonGradientTopPushed = Color (41, 255);
    mButtonGradientBotPushed = Color (29, 255);

    /* Window-related */
    mWindowFillUnfocused = Color (43, 230);
    mWindowFillFocused = Color (45, 230);
    mWindowTitleUnfocused = Color (220, 160);
    mWindowTitleFocused = Color (255, 190);

    mWindowHeaderGradientTop = mButtonGradientTopUnfocused;
    mWindowHeaderGradientBot = mButtonGradientBotUnfocused;
    mWindowHeaderSepTop = mBorderLight;
    mWindowHeaderSepBot = mBorderDark;

    mWindowPopup = Color (50, 255);
    mWindowPopupTransparent = Color (50, 0);

    mCheckBoxIcon = ENTYPO_ICON_CHECK;
    mMessageInformationIcon = ENTYPO_ICON_INFO_WITH_CIRCLE;
    mMessageQuestionIcon = ENTYPO_ICON_HELP_WITH_CIRCLE;
    mMessageWarningIcon = ENTYPO_ICON_WARNING;
    mMessageAltButtonIcon = ENTYPO_ICON_CIRCLE_WITH_CROSS;
    mMessagePrimaryButtonIcon = ENTYPO_ICON_CHECK;
    mPopupChevronRightIcon = ENTYPO_ICON_CHEVRON_RIGHT;
    mPopupChevronLeftIcon = ENTYPO_ICON_CHEVRON_LEFT;
    mTabHeaderLeftIcon = ENTYPO_ICON_ARROW_BOLD_LEFT;
    mTabHeaderRightIcon = ENTYPO_ICON_ARROW_BOLD_RIGHT;
    mTextBoxUpIcon = ENTYPO_ICON_CHEVRON_UP;
    mTextBoxDownIcon = ENTYPO_ICON_CHEVRON_DOWN;

    mFontNormal = nvgCreateFontMem (ctx, "sans", roboto_regular_ttf,
      roboto_regular_ttf_size, 0);
    mFontBold = nvgCreateFontMem (ctx, "sans-bold", roboto_bold_ttf,
      roboto_bold_ttf_size, 0);
    mFontIcons = nvgCreateFontMem (ctx, "icons", entypo_ttf,
      entypo_ttf_size, 0);
    if (mFontNormal == -1 || mFontBold == -1 || mFontIcons == -1)
      throw std::runtime_error ("Could not load fonts!");
  }

  /* Fonts */
  // The standard font face (default: `"sans"` from `resources/roboto_regular.ttf`).
  int mFontNormal;
  // The bold font face (default: `"sans-bold"` from `resources/roboto_regular.ttf`).
  int mFontBold;
  // The icon font face (default: `"icons"` from `resources/entypo.ttf`).
  int mFontIcons;
  /*
   * The amount of scaling that is applied to each icon to fit the size of
   * NanoGUI widgets.  The default value is `0.77f`, setting to e.g. higher
   * than `1.0f` is generally discouraged.
   */
  float mIconScale;

  /* Spacing-related parameters */
  // The font size for all widgets other than buttons and textboxes (default: ` 16`).
  int mStandardFontSize;
  // The font size for buttons (default: `20`).
  int mButtonFontSize;
  // The font size for text boxes (default: `20`).
  int mTextBoxFontSize;
  // Rounding radius for Window widget corners (default: `2`).
  int mWindowCornerRadius;
  // Default size of Window widget titles (default: `30`).
  int mWindowHeaderHeight;
  // Size of drop shadow rendered behind the Window widgets (default: `10`).
  int mWindowDropShadowSize;
  // Rounding radius for Button (and derived types) widgets (default: `2`).
  int mButtonCornerRadius;
  // The border width for TabHeader widgets (default: `0.75f`).
  float mTabBorderWidth;
  // The inner margin on a TabHeader widget (default: `5`).
  int mTabInnerMargin;
  // The minimum size for buttons on a TabHeader widget (default: `20`).
  int mTabMinButtonWidth;
  // The maximum size for buttons on a TabHeader widget (default: `160`).
  int mTabMaxButtonWidth;
  // Used to help specify what lies "in bound" for a TabHeader widget (default: `20`).
  int mTabControlWidth;
  // The amount of horizontal padding for a TabHeader widget (default: `10`).
  int mTabButtonHorizontalPadding;
  // The amount of vertical padding for a TabHeader widget (default: `2`).
  int mTabButtonVerticalPadding;

  /* Generic colors */
  /*
   * The color of the drop shadow drawn behind widgets
   * (default: intensity=`0`, alpha=`128`; see @ref _::Color::Color(int,int)).
   */
  Color mDropShadow;
  /*
   * The transparency color
   * (default: intensity=`0`, alpha=`0`; see @ref _::Color::Color(int,int)).
   */
  Color mTransparent;
  /*
   * The dark border color
   * (default: intensity=`29`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mBorderDark;
  /*
   * The light border color
   * (default: intensity=`92`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mBorderLight;
  /*
   * The medium border color
   * (default: intensity=`35`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mBorderMedium;
  /*
   * The text color
   * (default: intensity=`255`, alpha=`160`; see @ref _::Color::Color(int,int)).
   */
  Color mTextColor;
  /*
   * The disable dtext color
   * (default: intensity=`255`, alpha=`80`; see @ref _::Color::Color(int,int)).
   */
  Color mDisabledTextColor;
  /*
   * The text shadow color
   * (default: intensity=`0`, alpha=`160`; see @ref _::Color::Color(int,int)).
   */
  Color mTextColorShadow;
  // The icon color (default: @ref _::Theme::mTextColor).
  Color mIconColor;

  /* Button colors */
  /*
   * The top gradient color for buttons in focus
   * (default: intensity=`64`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mButtonGradientTopFocused;
  /*
   * The bottom gradient color for buttons in focus
   * (default: intensity=`48`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mButtonGradientBotFocused;
  /*
   * The top gradient color for buttons not in focus
   * (default: intensity=`74`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mButtonGradientTopUnfocused;
  /*
   * The bottom gradient color for buttons not in focus
   * (default: intensity=`58`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mButtonGradientBotUnfocused;
  /*
   * The top gradient color for buttons currently pushed
   * (default: intensity=`41`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mButtonGradientTopPushed;
  /*
   * The bottom gradient color for buttons currently pushed
   * (default: intensity=`29`, alpha=`255`; see @ref _::Color::Color(int,int)).
   */
  Color mButtonGradientBotPushed;

  /* Window colors */
  /*
   * The fill color for a Window that is not in focus
   * (default: intensity=`43`, alpha=`230`; see @ref _::Color::Color(int,int)).
   */
  Color mWindowFillUnfocused;
  /*
   * The fill color for a Window that is in focus
   * (default: intensity=`45`, alpha=`230`; see @ref _::Color::Color(int,int)).
   */
  Color mWindowFillFocused;
  /*
   * The title color for a Window that is not in focus
   * (default: intensity=`220`, alpha=`160`; see @ref _::Color::Color(int,int)).
   */
  Color mWindowTitleUnfocused;
  /*
   * The title color for a Window that is in focus
   * (default: intensity=`255`, alpha=`190`; see @ref _::Color::Color(int,int)).
   */
  Color mWindowTitleFocused;

  /*
   * The top gradient color for Window headings
   * (default: @ref _::Theme::mButtonGradientTopUnfocused).
   */
  Color mWindowHeaderGradientTop;
  /*
   * The bottom gradient color for Window headings
   * (default: @ref _::Theme::mButtonGradientBotUnfocused).
   */
  Color mWindowHeaderGradientBot;
  // The Window header top separation color (default: @ref _::Theme::mBorderLight).
  Color mWindowHeaderSepTop;
  // The Window header bottom separation color (default: @ref _::Theme::mBorderDark).
  Color mWindowHeaderSepBot;

  /*
   * The popup window color
   * (default: intensity=`50`, alpha=`255`; see @ref _::Color::Color(int,int))).
   */
  Color mWindowPopup;
  /*
   * The transparent popup window color
   * (default: intensity=`50`, alpha=`0`; see @ref _::Color::Color(int,int))).
   */
  Color mWindowPopupTransparent;

  // Icon to use for CheckBox widgets (default: `ENTYPO_ICON_CHECK`).
  int mCheckBoxIcon;
  // Icon to use for informational MessageDialog widgets (default: `ENTYPO_ICON_INFO_WITH_CIRCLE`).
  int mMessageInformationIcon;
  // Icon to use for interrogative MessageDialog widgets (default: `ENTYPO_ICON_HELP_WITH_CIRCLE`).
  int mMessageQuestionIcon;
  // Icon to use for warning MessageDialog widgets (default: `ENTYPO_ICON_WARNING`).
  int mMessageWarningIcon;
  // Icon to use on MessageDialog alt button (default: `ENTYPO_ICON_CIRCLE_WITH_CROSS`).
  int mMessageAltButtonIcon;
  // Icon to use on MessageDialog primary button (default: `ENTYPO_ICON_CHECK`).
  int mMessagePrimaryButtonIcon;
  // Icon to use for PopupButton widgets opening to the right (default: `ENTYPO_ICON_CHEVRON_RIGHT`).
  int mPopupChevronRightIcon;
  // Icon to use for PopupButton widgets opening to the left (default: `ENTYPO_ICON_CHEVRON_LEFT`).
  int mPopupChevronLeftIcon;
  // Icon to indicate hidden tabs to the left on a TabHeader (default: `ENTYPO_ICON_ARROW_BOLD_LEFT`).
  int mTabHeaderLeftIcon;
  // Icon to indicate hidden tabs to the right on a TabHeader (default: `ENTYPO_ICON_ARROW_BOLD_RIGHT`).
  int mTabHeaderRightIcon;
  // Icon to use when a TextBox has an up toggle (e.g. IntBox) (default: `ENTYPO_ICON_CHEVRON_UP`).
  int mTextBoxUpIcon;
  // Icon to use when a TextBox has a down toggle (e.g. IntBox) (default: `ENTYPO_ICON_CHEVRON_DOWN`).
  int mTextBoxDownIcon;

protected:
  // Default destructor does nothing; allows for inheritance.
  virtual ~Theme () { };

public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

} //< namespace _
