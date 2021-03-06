#include "t_plotgui.h"

namespace _ {

SIN createTrackbar(const std::string &trackbarname, const std::string &winname,
                   SIN *value, SIN count, TrackbarCallback onChange,
                   void *userdata) {
  // TODO
  return cv::createTrackbar(trackbarname, winname, value, count, onChange,
                            userdata);
}

void destroyAllWindows() { cv::destroyAllWindows(); }

void destroyWindow(const std::string &view) {
  Window::current().view(view).hide();
}

SIN getMouseWheelDelta(SIN flags) {
  // TODO
#if CV_MAJOR_VERSION > 2
  return cv::getMouseWheelDelta(flags);
#else
  return -1;
#endif
}

SIN getTrackbarPos(const std::string &trackbarname,
                   const std::string &winname) {
  // TODO
  return cv::getTrackbarPos(trackbarname, winname);
}

double getWindowProperty(const std::string &winname, SIN prop_id) {
  // TODO
  return cv::getWindowProperty(winname, prop_id);
}

void imshow(const std::string &view, void *img) {
  Window::current().view(view).drawImage(img);
  Window::current().view(view).finish();
  Window::current().view(view).flush();
}

void moveWindow(const std::string &view, SIN x, SIN y) {
  Window::current().view(view).offset({x, y});
}

void namedWindow(const std::string &view, SIN flags) {
  Window::current().view(view);
}

void resizeWindow(const std::string &view, SIN width, SIN height) {
  Window::current().view(view).size({width, height});
}

void resizeWindow(const std::string &view, const Size &size) {
  Window::current().view(view).size({size.width, size.height});
}

Rect selectROI(const std::string &windowName, void *img, bool showCrosshair,
               bool fromCenter) {
  // TODO
#if CV_MAJOR_VERSION > 2
  auto rect =
      cv::selectROI(windowName, (cv::InputArray)img, showCrosshair, fromCenter);
  return Rect(rect.x, rect.y, rect.width, rect.height);
#else
  return Rect(-1, -1, -1, -1);
#endif
}

Rect selectROI(void *img, bool showCrosshair, bool fromCenter) {
  // TODO
#if CV_MAJOR_VERSION > 2
  auto rect = cv::selectROI((cv::InputArray)img, showCrosshair, fromCenter);
  return Rect(rect.x, rect.y, rect.width, rect.height);
#else
  return Rect(-1, -1, -1, -1);
#endif
}

void selectROIs(const std::string &windowName, void *img,
                std::vector<Rect> &boundingBoxes, bool showCrosshair,
                bool fromCenter) {
  // TODO
#if CV_MAJOR_VERSION > 2
  std::vector<cv::Rect> boxes;
  for (auto b : boundingBoxes) {
    boxes.push_back(cv::Rect(b.x, b.y, b.width, b.height));
  }
  cv::selectROIs(windowName, (cv::InputArray)img, boxes, showCrosshair,
                 fromCenter);
#endif
}

void setMouseCallback(const std::string &view, MouseCallback onMouse,
                      void *userdata) {
  Window::current().view(view).mouse(onMouse, userdata);
}

void setTrackbarMax(const std::string &trackbarname, const std::string &winname,
                    SIN maxval) {
#if CV_MAJOR_VERSION > 2
  cv::setTrackbarMax(trackbarname, winname, maxval);
#endif
}

void setTrackbarMin(const std::string &trackbarname, const std::string &winname,
                    SIN minval) {
#if CV_MAJOR_VERSION > 2
  cv::setTrackbarMin(trackbarname, winname, minval);
#endif
}

void setTrackbarPos(const std::string &trackbarname, const std::string &winname,
                    SIN pos) {
  cv::setTrackbarPos(trackbarname, winname, pos);
}

void setWindowProperty(const std::string &winname, SIN prop_id,
                       double prop_value) {
  cv::setWindowProperty(winname, prop_id, prop_value);
}

void setWindowTitle(const std::string &view, const std::string &title) {
  Window::current().view(view).title(title);
}

SIN startWindowThread() {
  return cv::startWindowThread();
}

SIN waitKey(SIN delay) { return Util::key(delay); }

SIN waitKeyEx(SIN delay) { return Util::key(delay); }

}  // namespace _
