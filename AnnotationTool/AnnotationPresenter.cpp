#include "AnnotationPresenter.h"
#include "Utilities.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

AnnotationPresenter::AnnotationPresenter(IAnnotationView^ view, AnnotationModel * model) : m_view(view), m_model(model)
{
    view->ObjectNodeSelected += gcnew ObjectSet(this, &AnnotationPresenter::OnObjectNodeSelected);
    view->ImageNodeSelected += gcnew ImageSet(this, &AnnotationPresenter::OnImageNodeSelected);
    view->AnnotationDrawn += gcnew AnnotationAdded(this, &AnnotationPresenter::OnAnnotationDrawn);
}


AnnotationPresenter::~AnnotationPresenter()
{
    delete m_model;
}

void AnnotationPresenter::OnObjectNodeSelected(System::String^ obj_name, double % aspect_ratio)
{
    std::string name;
    double ar;
    MarshalString(obj_name, name);
    m_model->SetCurrentObject(name);
    m_model->GetAspectRatio(name, ar);
    aspect_ratio = ar;
}

void AnnotationPresenter::OnImageNodeSelected(System::String^ image_path)
{
    std::string std_path = MarshalString(image_path);
    System::Drawing::Image^ sys_img;
#ifdef OPENCV_IMAGE_LOAD
    // TODO: opencv part should perhaps be moved somewhere else
    using namespace cv;
    Mat img = imread(std_path, IMREAD_COLOR);
    Mat display;
    convertScaleAbs(img, display);
    sys_img = safe_cast<System::Drawing::Image^>(Mat2Bitmap(display));
    display.addref(); // increase reference count to prevent premature image data disposal
#else
    sys_img = System::Drawing::Image::FromFile(image_path);
#endif
    m_view->DisplayImage(sys_img);
    m_model->SetImage(std_path);
}

void AnnotationPresenter::OnAnnotationDrawn(int x, int y, int w, int h)
{
    m_model->AddAnnotation(x, y, w, h);
}