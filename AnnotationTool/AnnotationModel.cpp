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

void AnnotationModel::GetAspectRatio(const std::string& object_name, double & aspect_ratio)
{
    auto it = m_objects.find(object_name);
    if (it == m_objects.end()) {
        // TODO: should not happen, throw exception or show error popup
        aspect_ratio = 0.0;
        return;
    }
    aspect_ratio = it->second.m_aspect_ratio;

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

void AnnotationModel::AddObject(const std::string& name, const std::string& desc, double aspect_ratio)
{
    m_objects.insert(std::pair<std::string, Object>(name, Object(name, desc, aspect_ratio)));
}

void AnnotationModel::AddObject(const AnnotationModel::Object& obj)
{
    m_objects.insert(std::pair<std::string, Object>(obj.m_name, obj));
}

bool AnnotationModel::AddFolder(const std::string& path, bool is_recursive)
{
    auto it = m_folders.insert(std::pair<std::string, bool>(path, is_recursive));
    return it.second;
}

void AnnotationModel::AddAnnotation(int x, int y, int w, int h)
{
    AddAnnotation(m_current_image_path, m_current_object, x, y, w, h);
}

void AnnotationModel::AddAnnotation(const std::string& img_path, const std::string& obj_name, int x, int y, int w, int h)
{
    Annotation annotation(obj_name, x, y, w, h);
    AddAnnotation(img_path, annotation);
}

void AnnotationModel::AddAnnotation(const std::string& img_path, const Annotation& annotation)
{
    m_image_annotations.insert(std::pair<std::string, Annotation>(img_path, annotation));
}

void AnnotationModel::SaveProject(const std::string & path)
{
    // TODO: verify valid extension ?
    cv::FileStorage fs(path, cv::FileStorage::WRITE);
    fs << "project" << m_project_name;
    fs << "description" << m_description;
    fs << "objects" << "[";
    for (auto it = m_objects.begin(); it != m_objects.end(); ++it) {
        fs << "{:" << "name" << it->first;
        fs << "description" << it->second.m_desc;
        // TODO: store aspect ratio as two values in case of object editing ?
        fs << "aspectRatio" << it->second.m_aspect_ratio;
        fs << "}";
    }
    fs << "]";
    fs << "folders" << "[";
    for (auto it = m_folders.begin(); it != m_folders.end(); ++it) {
        fs << "{:" << "path" << it->first;
        fs << "recursive" << it->second;
        fs << "}";
    }
    fs << "]";
    fs << "images" << "[";
    unsigned buckets_count = m_image_annotations.bucket_count();
    for (unsigned i = 0; i < buckets_count; ++i) {
        //std::cout << "bucket #" << i << " contains:";
        auto local_it = m_image_annotations.begin(i);
        if (m_image_annotations.end(i) == local_it) {
            continue;
        }
        const std::string& path = local_it->first;
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

void AnnotationModel::LoadProject(const std::string & path)
{
    // TODO: reset model - perhaps as an option, use code below to also import annotations etc.

    // TODO: send updates to UI after loading

    cv::FileStorage fs(path, cv::FileStorage::READ);
    fs["project"] >> m_project_name;
    fs["description"] >> m_description;
    cv::FileNode objects = fs["objects"];
    cv::FileNodeIterator it = objects.begin(), it_end = objects.end();
    for (; it != it_end; ++it) {
        Object obj;
        (*it)["name"] >> obj.m_name;
        (*it)["description"] >> obj.m_desc;
        (*it)["aspectRatio"] >> obj.m_aspect_ratio;
        AddObject(obj);
    }
    cv::FileNode folders = fs["folders"];
    it = folders.begin(), it_end = folders.end();
    for (; it != it_end; ++it) {
        std::string path;
        bool recur;
        (*it)["path"] >> path;
        (*it)["recursive"] >> recur;
        AddFolder(path, recur);
    }
    cv::FileNode images = fs["images"];
    it = images.begin(), it_end = images.end();
    for (; it != it_end; ++it) {
        std::string path;
        (*it)["path"] >> path;

        cv::FileNode annotations = (*it)["annotations"];
        cv::FileNodeIterator local_it = annotations.begin(), local_it_end = annotations.end();
        for (; local_it != local_it_end; ++local_it) {
            Annotation an;
            (*local_it)["object_type"] >> an.m_object_name;
            (*local_it)["X"] >> an.m_x;
            (*local_it)["Y"] >> an.m_y;
            (*local_it)["width"] >> an.m_width;
            (*local_it)["height"] >> an.m_height;
            AddAnnotation(path, an);
        }
    }
    fs.release();
}

void AnnotationModel::Reset()
{
    // TODO:
}
