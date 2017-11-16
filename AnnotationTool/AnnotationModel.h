#pragma once
#pragma unmanaged

#include <string>
#include <vector>
#include <map>

class AnnotationModel
{
public:
    AnnotationModel();
    ~AnnotationModel();

    struct Object {
        Object(std::string name, bool fixed_as = false, int w_as = 1, int h_as = 1)
            : m_name(name), m_fixed_aspect_ratio(fixed_as), m_width_aspect(w_as), m_height_aspect(h_as) { }

        std::string m_name;
        bool m_fixed_aspect_ratio;
        int m_width_aspect;
        int m_height_aspect;
    };

    struct Annotation {
        int m_object_id; // ID in objects vector
        int x, y;
        int width, height;
    };

private:
    std::string m_project_name;
    std::string m_description;
    std::vector<Object> m_objects;
    std::vector<std::string> m_folders; // absolute path here
    std::multimap<std::string, Annotation> m_image_annotations; // maps absolute image path to annotations
};