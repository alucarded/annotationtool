#include "AnnotationModel.h"

#include "opencv2/core/core.hpp"

AnnotationModel::AnnotationModel()
{
}

AnnotationModel::~AnnotationModel()
{
}

void AnnotationModel::GetAnnotationsForImage(const std::string & path, std::vector<Annotation>& annotations)
{
    auto pit = m_image_annotations.equal_range(path);
    auto it = pit.first;
    while (it != pit.second) {
        annotations.push_back(it->second);
        it++;
    }
}

void AnnotationModel::SetProjectDetails(const std::string& name, const std::string& desc, int mode)
{
    m_project_name = name;
    m_description = desc;
    m_mode = static_cast<Mode>(mode); // TODO: choose mode per object?
}

void AnnotationModel::SetCurrentObject(const std::string & name)
{
    m_current_object = name;
}

void AnnotationModel::SetImage(const std::string & name)
{
    m_current_image_path = name;
}

void AnnotationModel::AddObject(const std::string& name, double aspect_ratio)
{
    m_objects.insert(std::pair<std::string, Object>(name, Object(name, std::string() /* TODO: add it */, aspect_ratio)));
}

void AnnotationModel::AddAnnotation(int x, int y, int w, int h)
{
    Annotation annotation(m_current_object, x, y, w, h);
    m_image_annotations.insert(std::pair<std::string, Annotation>(m_current_image_path, annotation));
}

void AnnotationModel::SaveAnnotations(const std::string & path)
{
    using namespace cv;
    // TODO: verify valid extension ?
    unsigned buckets_count = m_image_annotations.bucket_count();
    FileStorage fs(path, FileStorage::WRITE);
    fs << "images" << "[";
    for (unsigned i = 0; i < buckets_count; ++i) {
        //std::cout << "bucket #" << i << " contains:";
        auto local_it = m_image_annotations.begin(i);
        if (m_image_annotations.end(i) == local_it) {
            break;
        }
        std::string path = local_it->first;
        fs << "{:" <<"path" << path;
        fs << "annotations" << "[";
        for (; local_it != m_image_annotations.end(i); ++local_it) {
            //std::cout << " " << local_it->first << ":" << local_it->second;
            const Annotation& an = local_it->second;
            fs << "{:" <<"object_type" << an.m_object_name;
            fs << "X" << an.m_x;
            fs << "Y" << an.m_y;
            fs << "width" << an.m_width;
            fs << "height" << an.m_height;
            fs << "}";
        }
        fs << "]";
        fs << "}";
        //std::cout << std::endl;
    }
    fs << "]";
    fs.release();
}
